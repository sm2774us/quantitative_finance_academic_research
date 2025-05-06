use nalgebra::{DMatrix, DVector};
use kdtree::KdTree;
use std::error::Error;

pub fn hrp_optimize(cov_matrix: DMatrix<f64>) -> Result<DVector<f64>, Box<dyn Error>> {
    let n_assets = cov_matrix.nrows();
    if cov_matrix.ncols() != n_assets {
        return Err("Covariance matrix must be square".into());
    }
    let mut kdtree = KdTree::new(n_assets);
    for i in 0..n_assets {
        let point = cov_matrix.row(i).as_slice().to_vec();
        kdtree.add(point, i)?;
    }
    let _clusters = kdtree.nearest(&cov_matrix.row(0).as_slice().to_vec(), 2, &|a, b| {
        a.iter().zip(b).map(|(x, y)| (x - y).powi(2)).sum()
    })?;
    Ok(DVector::from_element(n_assets, 1.0 / n_assets as f64))
}
