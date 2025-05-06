import numpy as np
from hrp.optimizer import HRPOptimizer

def main() -> None:
    cov_matrix = np.array([
        [0.005, -0.002, 0.001],
        [-0.002, 0.004, -0.001],
        [0.001, -0.001, 0.006]
    ])
    optimizer = HRPOptimizer(cov_matrix)
    weights = optimizer.optimize()
    print(f"Optimal Weights: {weights}")

if __name__ == "__main__":
    main()
