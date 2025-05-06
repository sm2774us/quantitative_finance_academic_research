use volatility_sorting::sort_assets;
use nalgebra::DMatrix;
use rand::Rng;
use rand_distr::{Normal, Distribution};

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let mut rng = rand::thread_rng();
    let normal = Normal::new(0.0, 0.05)?;
    let returns = DMatrix::from_fn(100, 50, |_, _| normal.sample(&mut rng));
    let portfolios = sort_assets(returns, 5)?;
    for (i, portfolio) in portfolios.iter().enumerate() {
        println!("Portfolio {}: {:?}", i, portfolio);
    }
    Ok(())
}
