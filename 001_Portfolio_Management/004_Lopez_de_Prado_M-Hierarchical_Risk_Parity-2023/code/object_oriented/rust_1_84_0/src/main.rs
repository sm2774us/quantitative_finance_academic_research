use hrp::HRPOptimizer;
// use hrp::hrp_optimize; // Uncomment for FP version
use nalgebra::DMatrix;

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let cov_matrix = DMatrix::from_row_slice(3, 3, &[
        0.005, -0.002, 0.001,
        -0.002, 0.004, -0.001,
        0.001, -0.001, 0.006,
    ]);
    let optimizer = HRPOptimizer::new(cov_matrix.clone())?;
    let weights = optimizer.optimize()?;
    // For FP: let weights = hrp_optimize(cov_matrix)?;
    println!("Optimal Weights: {:?}", weights);
    Ok(())
}
