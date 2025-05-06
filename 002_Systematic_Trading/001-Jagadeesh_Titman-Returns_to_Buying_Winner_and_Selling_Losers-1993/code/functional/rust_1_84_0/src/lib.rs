use nalgebra::DMatrix;
use std::error::Error;

pub fn get_winners(returns: &DMatrix<f64>, t: usize, lookback: usize, top_decile: f64) -> Result<Vec<usize>, Box<dyn Error>> {
    let n_assets = returns.ncols();
    let mut past_returns: Vec<(f64, usize)> = (0..n_assets)
        .map(|i| {
            let ret = returns.slice((t - lookback, i), (lookback, 1)).sum();
            (ret, i)
        })
        .collect();
    past_returns.sort_by(|a, b| b.0.partial_cmp(&a.0).unwrap());
    let n_winners = (n_assets as f64 * top_decile) as usize;
    Ok(past_returns.into_iter().take(n_winners).map(|(_, i)| i).collect())
}

pub fn get_losers(returns: &DMatrix<f64>, t: usize, lookback: usize, bottom_decile: f64) -> Result<Vec<usize>, Box<dyn Error>> {
    let n_assets = returns.ncols();
    let mut past_returns: Vec<(f64, usize)> = (0..n_assets)
        .map(|i| {
            let ret = returns.slice((t - lookback, i), (lookback, 1)).sum();
            (ret, i)
        })
        .collect();
    past_returns.sort_by(|a, b| a.0.partial_cmp(&b.0).unwrap());
    let n_losers = (n_assets as f64 * bottom_decile) as usize;
    Ok(past_returns.into_iter().take(n_losers).map(|(_, i)| i).collect())
}

pub fn compute_portfolio(
    returns: DMatrix<f64>,
    lookback: usize,
    top_decile: f64,
    bottom_decile: f64,
    t: usize,
) -> Result<(DMatrix<f64>, f64), Box<dyn Error>> {
    let winners = get_winners(&returns, t, lookback, top_decile)?;
    let losers = get_losers(&returns, t, lookback, bottom_decile)?;
    let n_assets = returns.ncols();
    let mut weights = DMatrix::zeros(1, n_assets);
    let mut winner_return = 0.0;
    let mut loser_return = 0.0;
    for i in winners {
        weights[(0, i)] = 1.0 / winners.len() as f64;
        winner_return += returns[(t, i)];
    }
    for i in losers {
        weights[(0, i)] = -1.0 / losers.len() as f64;
        loser_return += returns[(t, i)];
    }
    let portfolio_return = (winner_return / winners.len() as f64) - (loser_return / losers.len() as f64);
    Ok((weights, portfolio_return))
}
