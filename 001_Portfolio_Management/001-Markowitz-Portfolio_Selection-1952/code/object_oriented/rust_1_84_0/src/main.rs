use markowitz::MarkowitzOptimizer;
use nalgebra::{DVector, DMatrix};

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let returns = DVector::from_vec(vec![0.1, 0.12, 0.15]);
    let cov_matrix = DMatrix::from_row_slice(3, 3, &[
        0.005, -0.002, 0.001,
        -0.002, 0.004, -0.001,
        0.001, -0.001, 0.006,
    ]);
    let optimizer = MarkowitzOptimizer::new(returns, cov_matrix)?;
    let target_return = 0.13;
    let (weights, risk) = optimizer.optimize(target_return)?;
    println!("Optimal Weights: {:?}", weights);
    println!("Portfolio Risk: {}", risk);
    Ok(())
}
