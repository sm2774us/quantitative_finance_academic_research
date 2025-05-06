import numpy as np
from volatility_sorting.sorter import VolatilitySorter

def main() -> None:
    np.random.seed(42)
    returns = np.random.normal(0, 0.05, (100, 50))
    sorter = VolatilitySorter(returns, 5)
    portfolios = sorter.sort_assets()
    for i, portfolio in enumerate(portfolios):
        print(f"Portfolio {i}: {portfolio}")

if __name__ == "__main__":
    main()
