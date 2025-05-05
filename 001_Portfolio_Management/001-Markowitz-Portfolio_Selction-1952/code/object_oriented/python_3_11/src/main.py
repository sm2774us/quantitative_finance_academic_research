import numpy as np
from markowitz.optimizer import MarkowitzOptimizer

def main() -> None:
    # Synthetic data
    np.random.seed(42)
    returns = np.array([0.1, 0.12, 0.15])  # Expected returns
    cov_matrix = np.array([[0.005, -0.002, 0.001],
                           [-0.002, 0.004, -0.001],
                           [0.001, -0.001, 0.006]])  # Covariance matrix
    optimizer = MarkowitzOptimizer(returns, cov_matrix)
    target_return = 0.13
    weights, risk = optimizer.optimize(target_return)
    print(f"Optimal Weights: {weights}")
    print(f"Portfolio Risk: {risk}")

if __name__ == "__main__":
    main()