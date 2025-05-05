from typing import Tuple
import numpy as np
import pandas as pd
import statsmodels.api as sm

def fit_fama_french(stock_returns: pd.Series, factors: pd.DataFrame) -> sm.regression.linear_model.RegressionResults:
    """Fit the three-factor model functionally."""
    X = sm.add_constant(factors)
    return sm.OLS(stock_returns, X).fit()

def get_coefficients(model: sm.regression.linear_model.RegressionResults) -> Tuple[float, float, float, float]:
    """Extract alpha and factor loadings from the fitted model."""
    params = model.params
    return params['const'], params['Mkt-RF'], params['SMB'], params['HML']

def main() -> None:
    np.random.seed(42)
    dates = pd.date_range('2020-01-01', periods=100)
    stock_returns = pd.Series(np.random.normal(0.001, 0.02, 100), index=dates)
    factors = pd.DataFrame({
        'Mkt-RF': np.random.normal(0.001, 0.01, 100),
        'SMB': np.random.normal(0.0005, 0.005, 100),
        'HML': np.random.normal(0.0003, 0.004, 100)
    }, index=dates)
    model = fit_fama_french(stock_returns, factors)
    alpha, beta_mkt, beta_smb, beta_hml = get_coefficients(model)
    print(f"Alpha: {alpha:.4f}, Beta_Mkt: {beta_mkt:.4f}, Beta_SMB: {beta_smb:.4f}, Beta_HML: {beta_hml:.4f}")
    print(model.summary())

if __name__ == "__main__":
    main()
