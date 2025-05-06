use volatility_sorting::VolatilitySorter;
use nalgebra::DMatrix;
use rand::Rng;
use rand_distr::{Normal, Distribution};

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let mut rng = rand::thread_rng();
    let normal = Normal::new(0.0, 0.05)?;
    let returns = DMatrix::from_fn(100, 50, |_, _| normal.sample(&mut rng));
    let sorter = VolatilitySorter::new(returns.clone(), 5)?;
    let portfolios = sorter.sort_assets()?;
    for (i, portfolio) in portfolios.iter().enumerate() {
        println!("Portfolio {}: {:?}", i, portfolio);
    }
    Ok(())
}
