use nalgebra::{DVector, DMatrix};
use nlopt::{Algorithm, Nlopt, Target};
use std::error::Error;

pub struct MarkowitzOptimizer {
    returns: DVector<f64>,
    cov_matrix: DMatrix<f64>,
    n_assets: usize,
}

impl MarkowitzOptimizer {
    pub fn new(returns: DVector<f64>, cov_matrix: DMatrix<f64>) -> Result<Self, Box<dyn Error>> {
        let n_assets = returns.len();
        if cov_matrix.nrows() != n_assets || cov_matrix.ncols() != n_assets {
            return Err("Covariance matrix dimensions mismatch".into());
        }
        Ok(Self { returns, cov_matrix, n_assets })
    }

    fn objective(&self, weights: &[f64]) -> f64 {
        let w = DVector::from_row_slice(weights);
        (w.transpose() * &self.cov_matrix * w).sqrt()
    }

    fn constraint_return(&self, weights: &[f64], target_return: f64) -> f64 {
        let w = DVector::from_row_slice(weights);
        w.dot(&self.returns) - target_return
    }

    fn constraint_sum(&self, weights: &[f64]) -> f64 {
        weights.iter().sum::<f64>() - 1.0
    }

    pub fn optimize(&self, target_return: f64) -> Result<(DVector<f64>, f64), Box<dyn Error>> {
        let mut opt = Nlopt::new(
            Algorithm::Slsqp,
            self.n_assets,
            self.objective,
            Target::Minimize,
            None,
        )?;
        let mut weights = vec![1.0 / self.n_assets as f64; self.n_assets];
        opt.add_equality_constraint(
            |w, _| self.constraint_return(w, target_return),
            1e-6,
        )?;
        opt.add_equality_constraint(
            |w, _| self.constraint_sum(w),
            1e-6,
        )?;
        let lb = vec![0.0; self.n_assets];
        let ub = vec![1.0; self.n_assets];
        opt.set_lower_bounds(&lb)?;
        opt.set_upper_bounds(&ub)?;
        let (minf, weights) = opt.optimize(&mut weights)?;
        Ok((DVector::from_row_slice(&weights), minf))
    }
}
