from typing import List, Tuple
import numpy as np
from scipy.optimize import minimize

class MarkowitzOptimizer:
    def __init__(self, returns: np.ndarray, cov_matrix: np.ndarray):
        """Initialize with asset returns and covariance matrix."""
        self.returns = returns  # Shape: (n_assets,)
        self.cov_matrix = cov_matrix  # Shape: (n_assets, n_assets)
        self.n_assets = len(returns)

    def objective(self, weights: np.ndarray) -> float:
        """Objective function: portfolio variance."""
        return np.sqrt(np.dot(weights.T, np.dot(self.cov_matrix, weights)))

    def constraint_return(self, weights: np.ndarray, target_return: float) -> float:
        """Constraint: portfolio return equals target return."""
        return np.sum(self.returns * weights) - target_return

    def constraint_sum(self, weights: np.ndarray) -> float:
        """Constraint: weights sum to 1."""
        return np.sum(weights) - 1.0

    def optimize(self, target_return: float) -> Tuple[np.ndarray, float]:
        """Optimize portfolio for given target return."""
        initial_weights = np.ones(self.n_assets) / self.n_assets
        constraints = (
            {"type": "eq", "fun": self.constraint_sum},
            {"type": "eq", "fun": lambda w: self.constraint_return(w, target_return)},
        )
        bounds = [(0, 1) for _ in range(self.n_assets)]
        result = minimize(
            self.objective,
            initial_weights,
            method="SLSQP",
            bounds=bounds,
            constraints=constraints,
        )
        return result.x, result.fun