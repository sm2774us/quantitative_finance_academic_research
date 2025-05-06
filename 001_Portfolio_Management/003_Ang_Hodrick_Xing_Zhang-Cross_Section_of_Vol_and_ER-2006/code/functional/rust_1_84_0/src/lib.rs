use nalgebra::DMatrix;
use std::error::Error;

pub fn compute_volatility(returns: &DMatrix<f64>, asset: usize) -> f64 {
    let asset_returns = returns.column(asset);
    let mean = asset_returns.mean();
    let variance = asset_returns.iter().map(|x| (x - mean).powi(2)).sum::<f64>() / asset_returns.len() as f64;
    variance.sqrt()
}

pub fn sort_assets(returns: DMatrix<f64>, n_portfolios: usize) -> Result<Vec<Vec<usize>>, Box<dyn Error>> {
    let mut volatilities: Vec<(f64, usize)> = (0..returns.ncols())
        .map(|i| (compute_volatility(&returns, i), i))
        .collect();
    volatilities.sort_by(|a, b| a.0.partial_cmp(&b.0).unwrap());
    let portfolio_size = returns.ncols() / n_portfolios;
    let mut portfolios = Vec::new();
    for i in 0..n_portfolios {
        let start = i * portfolio_size;
        let end = if i < n_portfolios - 1 { start + portfolio_size } else { returns.ncols() };
        portfolios.push(volatilities[start..end].iter().map(|&(_, idx)| idx).collect());
    }
    Ok(portfolios)
}
