import numpy as np
from momentum.strategy import MomentumStrategy

def main() -> None:
    np.random.seed(42)
    returns = np.random.normal(0, 0.05, (100, 50))  # 100 days, 50 assets
    strategy = MomentumStrategy(returns, lookback=12, top_decile=0.1, bottom_decile=0.1)
    weights, portfolio_return = strategy.compute_portfolio(t=50)
    print(f"Portfolio Weights: {weights}")
    print(f"Portfolio Return: {portfolio_return}")

if __name__ == "__main__":
    main()
