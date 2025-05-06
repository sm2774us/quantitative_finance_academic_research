use nalgebra::DMatrix;
use std::error::Error;

pub struct MomentumStrategy {
    returns: DMatrix<f64>,
    lookback: usize,
    top_decile: f64,
    bottom_decile: f64,
    n_assets: usize,
}

impl MomentumStrategy {
    pub fn new(returns: DMatrix<f64>, lookback: usize, top_decile: f64, bottom_decile: f64) -> Result<Self, Box<dyn Error>> {
        let n_assets = returns.ncols();
        Ok(Self { returns, lookback, top_decile, bottom_decile, n_assets })
    }

    fn get_winners(&self, t: usize) -> Result<Vec<usize>, Box<dyn Error>> {
        let mut past_returns: Vec<(f64, usize)> = (0..self.n_assets)
            .map(|i| {
                let ret = self.returns.slice((t - self.lookback, i), (self.lookback, 1)).sum();
                (ret, i)
            })
            .collect();
        past_returns.sort_by(|a, b| b.0.partial_cmp(&a.0).unwrap());
        let n_winners = (self.n_assets as f64 * self.top_decile) as usize;
        Ok(past_returns.into_iter().take(n_winners).map(|(_, i)| i).collect())
    }

    fn get_losers(&self, t: usize) -> Result<Vec<usize>, Box<dyn Error>> {
        let mut past_returns: Vec<(f64, usize)> = (0..self.n_assets)
            .map(|i| {
                let ret = self.returns.slice((t - self.lookback, i), (self.lookback, 1)).sum();
                (ret, i)
            })
            .collect();
        past_returns.sort_by(|a, b| a.0.partial_cmp(&b.0).unwrap());
        let n_losers = (self.n_assets as f64 * self.bottom_decile) as usize;
        Ok(past_returns.into_iter().take(n_losers).map(|(_, i)| i).collect())
    }

    pub fn compute_portfolio(&self, t: usize) -> Result<(DMatrix<f64>, f64), Box<dyn Error>> {
        let winners = self.get_winners(t)?;
        let losers = self.get_losers(t)?;
        let mut weights = DMatrix::zeros(1, self.n_assets);
        let mut winner_return = 0.0;
        let mut loser_return = 0.0;
        for i in winners {
            weights[(0, i)] = 1.0 / winners.len() as f64;
            winner_return += self.returns[(t, i)];
        }
        for i in losers {
            weights[(0, i)] = -1.0 / losers.len() as f64;
            loser_return += self.returns[(t, i)];
        }
        let portfolio_return = (winner_return / winners.len() as f64) - (loser_return / losers.len() as f64);
        Ok((weights, portfolio_return))
    }
}
