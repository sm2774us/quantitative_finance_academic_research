import numpy as np
import pandas as pd
from fama_french.model import FamaFrenchModel

def main() -> None:
    # Generate synthetic data
    np.random.seed(42)
    dates = pd.date_range('2020-01-01', periods=100)
    stock_returns = pd.Series(np.random.normal(0.001, 0.02, 100), index=dates)
    factors = pd.DataFrame({
        'Mkt-RF': np.random.normal(0.001, 0.01, 100),
        'SMB': np.random.normal(0.0005, 0.005, 100),
        'HML': np.random.normal(0.0003, 0.004, 100)
    }, index=dates)
    # Fit and analyze
    model = FamaFrenchModel(stock_returns, factors)
    model.fit()
    alpha, beta_mkt, beta_smb, beta_hml = model.get_coefficients()
    print(f"Alpha: {alpha:.4f}, Beta_Mkt: {beta_mkt:.4f}, Beta_SMB: {beta_smb:.4f}, Beta_HML: {beta_hml:.4f}")
    print(model.summary())

if __name__ == "__main__":
    main()
