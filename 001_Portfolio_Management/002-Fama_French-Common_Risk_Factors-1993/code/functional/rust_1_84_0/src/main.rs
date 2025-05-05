use fama_french::fit_fama_french;
use nalgebra::{DMatrix, DVector};
use rand::Rng;
use rand_distr::{Normal, Distribution};

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let mut rng = rand::thread_rng();
    let normal = Normal::new(0.0, 0.02)?;
    let stock_returns = DVector::from_fn(100, |_, _| normal.sample(&mut rng));
    let factors = DMatrix::from_fn(100, 3, |_, j| {
        let scale = match j { 0 => 0.5, 1 => 0.25, _ => 0.2 };
        normal.sample(&mut rng) * scale
    });
    let (alpha, beta_mkt, beta_smb, beta_hml) = fit_fama_french(stock_returns, factors)?;
    println!("Alpha: {}\nBeta_Mkt: {}\nBeta_SMB: {}\nBeta_HML: {}", alpha, beta_mkt, beta_smb, beta_hml);
    Ok(())
}
