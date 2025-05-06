from typing import Tuple, List
import numpy as np

class MomentumStrategy:
    def __init__(self, returns: np.ndarray, lookback: int, top_decile: float, bottom_decile: float):
        """Initialize with returns matrix, lookback period, and decile thresholds."""
        self.returns = returns  # Shape: (n_periods, n_assets)
        self.lookback = lookback
        self.top_decile = top_decile
        self.bottom_decile = bottom_decile
        self.n_assets = returns.shape[1]

    def get_winners(self, t: int) -> List[int]:
        """Get indices of top decile assets based on past returns."""
        past_returns = np.sum(self.returns[t - self.lookback:t, :], axis=0)
        sorted_indices = np.argsort(past_returns)[::-1]
        n_winners = int(self.n_assets * self.top_decile)
        return sorted_indices[:n_winners].tolist()

    def get_losers(self, t: int) -> List[int]:
        """Get indices of bottom decile assets based on past returns."""
        past_returns = np.sum(self.returns[t - self.lookback:t, :], axis=0)
        sorted_indices = np.argsort(past_returns)
        n_losers = int(self.n_assets * self.bottom_decile)
        return sorted_indices[:n_losers].tolist()

    def compute_portfolio(self, t: int) -> Tuple[np.ndarray, float]:
        """Compute portfolio weights and return at time t."""
        winners = self.get_winners(t)
        losers = self.get_losers(t)
        weights = np.zeros(self.n_assets)
        winner_return = 0.0
        loser_return = 0.0
        for i in winners:
            weights[i] = 1.0 / len(winners)
            winner_return += self.returns[t, i]
        for i in losers:
            weights[i] = -1.0 / len(losers)
            loser_return += self.returns[t, i]
        portfolio_return = (winner_return / len(winners)) - (loser_return / len(losers))
        return weights, portfolio_return
