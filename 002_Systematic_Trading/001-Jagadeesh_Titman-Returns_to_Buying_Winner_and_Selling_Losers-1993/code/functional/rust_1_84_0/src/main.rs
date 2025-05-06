use momentum::compute_portfolio;
use nalgebra::DMatrix;
use rand::Rng;
use rand_distr::{Normal, Distribution};

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let mut rng = rand::thread_rng();
    let normal = Normal::new(0.0, 0.05)?;
    let returns = DMatrix::from_fn(100, 50, |_, _| normal.sample(&mut rng));
    let (weights, portfolio_return) = compute_portfolio(returns, 12, 0.1, 0.1, 50)?;
    println!("Portfolio Weights: {:?}", weights);
    println!("Portfolio Return: {}", portfolio_return);
    Ok(())
}
