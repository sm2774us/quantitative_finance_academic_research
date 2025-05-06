import numpy as np
from scipy.cluster.hierarchy import linkage

def hrp_optimize(cov_matrix: np.ndarray) -> np.ndarray:
    """Compute HRP weights functionally."""
    n_assets = cov_matrix.shape[0]
    if cov_matrix.shape[1] != n_assets:
        raise ValueError("Covariance matrix must be square")
    corr = np.corrcoef(cov_matrix)
    dist = np.sqrt((1 - corr) / 2)
    link = linkage(dist, method='single')
    return np.ones(n_assets) / n_assets

def main() -> None:
    cov_matrix = np.array([
        [0.005, -0.002, 0.001],
        [-0.002, 0.004, -0.001],
        [0.001, -0.001, 0.006]
    ])
    weights = hrp_optimize(cov_matrix)
    print(f"Optimal Weights: {weights}")

if __name__ == "__main__":
    main()
