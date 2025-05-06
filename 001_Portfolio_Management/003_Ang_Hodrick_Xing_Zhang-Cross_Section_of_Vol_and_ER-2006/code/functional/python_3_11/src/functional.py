from typing import List
import numpy as np

def compute_volatility(returns: np.ndarray, asset: int) -> float:
    """Compute volatility for an asset."""
    return np.std(returns[:, asset], ddof=1)

def sort_assets(returns: np.ndarray, n_portfolios: int) -> List[List[int]]:
    """Sort assets into portfolios by volatility."""
    n_assets = returns.shape[1]
    volatilities = [(compute_volatility(returns, i), i) for i in range(n_assets)]
    volatilities.sort()
    portfolio_size = n_assets // n_portfolios
    portfolios = []
    for i in range(n_portfolios):
        start = i * portfolio_size
        end = start + portfolio_size if i < n_portfolios - 1 else n_assets
        portfolios.append([idx for _, idx in volatilities[start:end]])
    return portfolios

def main() -> None:
    np.random.seed(42)
    returns = np.random.normal(0, 0.05, (100, 50))
    portfolios = sort_assets(returns, 5)
    for i, portfolio in enumerate(portfolios):
        print(f"Portfolio {i}: {portfolio}")

if __name__ == "__main__":
    main()
