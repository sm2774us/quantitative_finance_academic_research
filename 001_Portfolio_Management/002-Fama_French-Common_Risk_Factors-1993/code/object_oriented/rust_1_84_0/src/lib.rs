use nalgebra::{DMatrix, DVector};
use std::error::Error;

pub struct FamaFrenchModel {
    stock_returns: DVector<f64>,
    factors: DMatrix<f64>,
    coefficients: Option<DVector<f64>>,
}

impl FamaFrenchModel {
    pub fn new(stock_returns: DVector<f64>, factors: DMatrix<f64>) -> Result<Self, Box<dyn Error>> {
        if stock_returns.len() != factors.nrows() || factors.ncols() != 3 {
            return Err("Dimension mismatch".into());
        }
        Ok(Self { stock_returns, factors, coefficients: None })
    }

    pub fn fit(&mut self) -> Result<(), Box<dyn Error>> {
        let mut X = DMatrix::zeros(self.factors.nrows(), 4);
        X.column_mut(0).fill(1.0);
        for i in 0..3 {
            X.column_mut(i + 1).copy_from(&self.factors.column(i));
        }
        let xtx = X.transpose() * &X;
        let xtx_inv = xtx.try_inverse().ok_or("Matrix not invertible")?;
        let xty = X.transpose() * &self.stock_returns;
        self.coefficients = Some(xtx_inv * xty);
        Ok(())
    }

    pub fn get_coefficients(&self) -> Result<(f64, f64, f64, f64), Box<dyn Error>> {
        let coeffs = self.coefficients.as_ref().ok_or("Model not fitted")?;
        Ok((coeffs[0], coeffs[1], coeffs[2], coeffs[3]))
    }
}
