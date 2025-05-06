use fama_french::FamaFrenchModel;
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
    let mut model = FamaFrenchModel::new(stock_returns.clone(), factors.clone())?;
    model.fit()?;
    let (alpha, beta_mkt, beta_smb, beta_hml) = model.get_coefficients()?;
    println!("Alpha: {}\nBeta_Mkt: {}\nBeta_SMB: {}\nBeta_HML: {}", alpha, beta_mkt, beta_smb, beta_hml);
    Ok(())
}
