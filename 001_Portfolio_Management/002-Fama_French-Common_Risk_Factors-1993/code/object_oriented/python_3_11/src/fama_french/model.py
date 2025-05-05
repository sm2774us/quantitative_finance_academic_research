from typing import Tuple
import numpy as np
import pandas as pd
import statsmodels.api as sm

class FamaFrenchModel:
    def __init__(self, stock_returns: pd.Series, factors: pd.DataFrame):
        """Initialize with stock returns and factor data (Mkt-RF, SMB, HML)."""
        self.stock_returns = stock_returns
        self.factors = factors
        self.model = None

    def fit(self) -> None:
        """Fit the three-factor model using OLS regression."""
        X = sm.add_constant(self.factors)
        self.model = sm.OLS(self.stock_returns, X).fit()

    def get_coefficients(self) -> Tuple[float, float, float, float]:
        """Return alpha and factor loadings (Mkt-RF, SMB, HML)."""
        if self.model is None:
            raise ValueError("Model not fitted yet. Call fit() first.")
        params = self.model.params
        return params['const'], params['Mkt-RF'], params['SMB'], params['HML']

    def summary(self) -> str:
        """Return a textual summary of the regression."""
        if self.model is None:
            raise ValueError("Model not fitted yet. Call fit() first.")
        return self.model.summary().as_text()
