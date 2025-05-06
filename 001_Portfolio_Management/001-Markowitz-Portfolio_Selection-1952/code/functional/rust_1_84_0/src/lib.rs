use nalgebra::{DVector, DMatrix};
use nlopt::{Algorithm, Nlopt, Target};
use std::error::Error;

pub fn markowitz_optimize(
    returns: DVector<f64>,
    cov_matrix: DMatrix<f64>,
    target_return: f64,
) -> Result<(DVector<f64>, f64), Box<dyn Error>> {
    let n_assets = returns.len();
    if cov_matrix.nrows() != n_assets || cov_matrix.ncols() != n_assets {
        return Err("Covariance matrix dimensions mismatch".into());
    }

    let objective = |weights: &[f64], _: Option<&mut [f64]>| {
        let w = DVector::from_row_slice(weights);
        (w.transpose() * &cov_matrix * w).sqrt()
    };

    let constraint_return = |weights: &[f64], _: Option<&mut [f64]>| {
        let w = DVector::from_row_slice(weights);
        w.dot(&returns) - target_return
    };

    let constraint_sum = |weights: &[f64], _: Option<&mut [f64]>| {
        weights.iter().sum::<f64>() - 1.0
    };

    let mut opt = Nlopt::new(
        Algorithm::Slsqp,
        n_assets,
        objective,
        Target::Minimize,
        None,
    )?;
    let mut weights = vec![1.0 / n_assets as f64; n_assets];
    opt.add_equality_constraint(constraint_return, 1e-6)?;
    opt.add_equality_constraint(constraint_sum, 1e-6)?;
    let lb = vec![0.0; n_assets];
    let ub = vec![1.0; n_assets];
    opt.set_lower_bounds(&lb)?;
    opt.set_upper_bounds(&ub)?;
    let (minf, weights) = opt.optimize(&mut weights)?;
    Ok((DVector::from_row_slice(&weights), minf))
}
