use momentum::MomentumStrategy;
use nalgebra::DMatrix;
use rand::Rng;
use rand_distr::{Normal, Distribution};

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let mut rng = rand::thread_rng();
    let normal = Normal::new(0.0, 0.05)?;
    let returns = DMatrix::from_fn(100, 50, |_, _| normal.sample(&mut rng));
    let strategy = MomentumStrategy::new(returns, 12, 0.1, 0.1)?;
    let (weights, portfolio_return) = strategy.compute_portfolio(50)?;
    println!("Portfolio Weights: {:?}", weights);
    println!("Portfolio Return: {}", portfolio_return);
    Ok(())
}
