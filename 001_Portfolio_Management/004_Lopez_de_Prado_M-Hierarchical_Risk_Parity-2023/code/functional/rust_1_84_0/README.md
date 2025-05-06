# Lopez de Prado (2023) - Hierarchical Risk Parity with Machine Learning Clustering - __`Rust 1.84.0` Functional-Programming Code__

## File Structure
```
├── src/
│   ├── lib.rs
│   ├── main.rs
│
├── Cargo.toml
├── README.md
```

## Explanation
- __OOP:__ The __`hrp_optimize`__ `function` performs the same task without state.
- __Latest Features:__ __`Rust 1.84.0`’s__ error handling and and [__`nalgebra`__](https://github.com/dimforge/nalgebra) for matrix operations.
- __Algorithm:__ Simplified with __`k-d` tree clustering__; full __`HRP`__ uses `hierarchical clustering` (e.g., `dendrogram-based`).

## Complexity
- __Time Complexity:__ $$O(NlogN)$$ for `k-d tree` construction and querying.
- __Space Complexity:__ $$O(N^{2})$$ for the covariance matrix.

## Build and Run Instructions
- Build:
```bash
cargo build --release
```
- Run:
```bash
cargo run --release
```
- Expected Output:
```
Optimal Weights: [0.333333, 0.333333, 0.333333]
```
