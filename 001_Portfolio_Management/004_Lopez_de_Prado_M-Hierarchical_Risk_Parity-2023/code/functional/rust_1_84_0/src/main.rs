use hrp::hrp_optimize;
use nalgebra::DMatrix;

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let cov_matrix = DMatrix::from_row_slice(3, 3, &[
        0.005, -0.002, 0.001,
        -0.002, 0.004, -0.001,
        0.001, -0.001, 0.006,
    ]);
    let weights = hrp_optimize(cov_matrix)?;
    println!("Optimal Weights: {:?}", weights);
    Ok(())
}
