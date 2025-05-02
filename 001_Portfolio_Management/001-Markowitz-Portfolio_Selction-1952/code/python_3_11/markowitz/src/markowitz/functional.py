from typing import Callable, Tuple
import numpy as np
from scipy.optimize import minimize

def markowitz_optimize(
    returns: np.ndarray, cov_matrix: np.ndarray, target_return: float
) -> Tuple[np.ndarray, float]:
    """Functional implementation of Markowitz optimization."""
    n_assets = len(returns)

    def objective(weights: np.ndarray) -> float:
        return np.sqrt(np.dot(weights.T, np.dot(cov_matrix, weights)))

    def constraint_return(weights: np.ndarray) -> float:
        return np.sum(returns * weights) - target_return

    def constraint_sum(weights: np.ndarray) -> float:
        return np.sum(weights) - 1.0

    initial_weights = np.ones(n_assets) / n_assets
    constraints = (
        {"type": "eq", "fun": constraint_sum},
        {"type": "eq", "fun": constraint_return},
    )
    bounds = [(0, 1) for _ in range(n_assets)]
    result = minimize(
        objective,
        initial_weights,
        method="SLSQP",
        bounds=bounds,
        constraints=constraints,
    )
    return result.x, result.fun

def main() -> None:
    np.random.seed(42)
    returns = np.array([0.1, 0.12, 0.15])
    cov_matrix = np.array([[0.005, -0.002, 0.001],
                           [-0.002, 0.004, -0.001],
                           [0.001, -0.001, 0.006]])
    target_return = 0.13
    weights, risk = markowitz_optimize(returns, cov_matrix, target_return)
    print(f"Optimal Weights: {weights}")
    print(f"Portfolio Risk: {risk}")

if __name__ == "__main__":
    main()