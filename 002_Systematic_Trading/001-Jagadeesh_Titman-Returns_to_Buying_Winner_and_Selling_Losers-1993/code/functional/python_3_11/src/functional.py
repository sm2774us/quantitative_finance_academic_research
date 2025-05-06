from typing import Tuple, List
import numpy as np

def get_winners(returns: np.ndarray, t: int, lookback: int, top_decile: float) -> List[int]:
    """Get indices of top decile assets based on past returns."""
    past_returns = np.sum(returns[t - lookback:t, :], axis=0)
    sorted_indices = np.argsort(past_returns)[::-1]
    n_winners = int(returns.shape[1] * top_decile)
    return sorted_indices[:n_winners].tolist()

def get_losers(returns: np.ndarray, t: int, lookback: int, bottom_decile: float) -> List[int]:
    """Get indices of bottom decile assets based on past returns."""
    past_returns = np.sum(returns[t - lookback:t, :], axis=0)
    sorted_indices = np.argsort(past_returns)
    n_losers = int(returns.shape[1] * bottom_decile)
    return sorted_indices[:n_losers].tolist()

def compute_portfolio(
    returns: np.ndarray, lookback: int, top_decile: float, bottom_decile: float, t: int
) -> Tuple[np.ndarray, float]:
    """Compute portfolio weights and return at time t."""
    winners = get_winners(returns, t, lookback, top_decile)
    losers = get_losers(returns, t, lookback, bottom_decile)
    weights = np.zeros(returns.shape[1])
    winner_return = 0.0
    loser_return = 0.0
    for i in winners:
        weights[i] = 1.0 / len(winners)
        winner_return += returns[t, i]
    for i in losers:
        weights[i] = -1.0 / len(losers)
        loser_return += returns[t, i]
    portfolio_return = (winner_return / len(winners)) - (loser_return / len(losers))
    return weights, portfolio_return

def main() -> None:
    np.random.seed(42)
    returns = np.random.normal(0, 0.05, (100, 50))
    weights, portfolio_return = compute_portfolio(returns, lookback=12, top_decile=0.1, bottom_decile=0.1, t=50)
    print(f"Portfolio Weights: {weights}")
    print(f"Portfolio Return: {portfolio_return}")

if __name__ == "__main__":
    main()
