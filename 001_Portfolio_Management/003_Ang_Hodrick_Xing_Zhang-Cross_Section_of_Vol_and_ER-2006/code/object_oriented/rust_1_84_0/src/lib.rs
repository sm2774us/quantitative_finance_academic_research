use nalgebra::DMatrix;
use std::error::Error;

pub struct VolatilitySorter {
    returns: DMatrix<f64>,
    n_portfolios: usize,
}

impl VolatilitySorter {
    pub fn new(returns: DMatrix<f64>, n_portfolios: usize) -> Result<Self, Box<dyn Error>> {
        Ok(Self { returns, n_portfolios })
    }

    fn compute_volatility(&self, asset: usize) -> f64 {
        let asset_returns = self.returns.column(asset);
        let mean = asset_returns.mean();
        let variance = asset_returns.iter().map(|x| (x - mean).powi(2)).sum::<f64>() / asset_returns.len() as f64;
        variance.sqrt()
    }

    pub fn sort_assets(&self) -> Result<Vec<Vec<usize>>, Box<dyn Error>> {
        let mut volatilities: Vec<(f64, usize)> = (0..self.returns.ncols())
            .map(|i| (self.compute_volatility(i), i))
            .collect();
        volatilities.sort_by(|a, b| a.0.partial_cmp(&b.0).unwrap());
        let portfolio_size = self.returns.ncols() / self.n_portfolios;
        let mut portfolios = Vec::new();
        for i in 0..self.n_portfolios {
            let start = i * portfolio_size;
            let end = if i < self.n_portfolios - 1 { start + portfolio_size } else { self.returns.ncols() };
            portfolios.push(volatilities[start..end].iter().map(|&(_, idx)| idx).collect());
        }
        Ok(portfolios)
    }
}
