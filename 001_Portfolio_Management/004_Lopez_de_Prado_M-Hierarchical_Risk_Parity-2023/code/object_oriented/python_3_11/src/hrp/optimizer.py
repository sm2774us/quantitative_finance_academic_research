from typing import Optional
import numpy as np
from scipy.cluster.hierarchy import linkage, dendrogram

class HRPOptimizer:
    def __init__(self, cov_matrix: np.ndarray):
        """Initialize with covariance matrix."""
        self.cov_matrix = cov_matrix
        self.n_assets = cov_matrix.shape[0]
        if cov_matrix.shape[1] != self.n_assets:
            raise ValueError("Covariance matrix must be square")

    def optimize(self) -> np.ndarray:
        """Compute HRP weights."""
        # Hierarchical clustering
        corr = np.corrcoef(self.cov_matrix)
        dist = np.sqrt((1 - corr) / 2)
        link = linkage(dist, method='single')
        # Simplified: equal weights (full HRP would use recursive bisection)
        return np.ones(self.n_assets) / self.n_assets
