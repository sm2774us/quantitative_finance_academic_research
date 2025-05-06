from typing import List
import numpy as np

class VolatilitySorter:
    def __init__(self, returns: np.ndarray, n_portfolios: int):
        """Initialize with returns matrix and number of portfolios."""
        self.returns = returns  # Shape: (n_periods, n_assets)
        self.n_portfolios = n_portfolios
        self.n_assets = returns.shape[1]

    def compute_volatility(self, asset: int) -> float:
        """Compute volatility for an asset."""
        asset_returns = self.returns[:, asset]
        return np.std(asset_returns, ddof=1)

    def sort_assets(self) -> List[List[int]]:
        """Sort assets into portfolios by volatility."""
        volatilities = [(self.compute_volatility(i), i) for i in range(self.n_assets)]
        volatilities.sort()  # Sort by volatility ascending
        portfolio_size = self.n_assets // self.n_portfolios
        portfolios = []
        for i in range(self.n_portfolios):
            start = i * portfolio_size
            end = start + portfolio_size if i < self.n_portfolios - 1 else self.n_assets
            portfolios.append([idx for _, idx in volatilities[start:end]])
        return portfolios
