use nalgebra::{DMatrix, DVector};
use std::error::Error;

pub fn fit_fama_french(stock_returns: DVector<f64>, factors: DMatrix<f64>) -> Result<(f64, f64, f64, f64), Box<dyn Error>> {
    if stock_returns.len() != factors.nrows() || factors.ncols() != 3 {
        return Err("Dimension mismatch".into());
    }
    let mut X = DMatrix::zeros(factors.nrows(), 4);
    X.column_mut(0).fill(1.0);
    for i in 0..3 {
        X.column_mut(i + 1).copy_from(&factors.column(i));
    }
    let xtx = X.transpose() * &X;
    let xtx_inv = xtx.try_inverse().ok_or("Matrix not invertible")?;
    let xty = X.transpose() * &stock_returns;
    let coefficients = xtx_inv * xty;
    Ok((coefficients[0], coefficients[1], coefficients[2], coefficients[3]))
}
