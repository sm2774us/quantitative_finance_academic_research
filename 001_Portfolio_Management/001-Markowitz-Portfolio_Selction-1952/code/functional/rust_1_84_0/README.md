# Markowitz (1952) - Portfolio Selection - __`Rust 1.84.0` Object-Oriented Code__

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
- __FP:__ Pure functions with no state, passing all data explicitly. Closures handle optimization callbacks.
- __Latest Features:__ __`Rust 1.84.0`’s__ improved pattern matching and [__`nalgebra`__](https://github.com/dimforge/nalgebra) for linear algebra. Error handling uses __`Box`__ for flexibility.

## Complexity
- __Time Complexity:__ __`O(n^3)`__ for matrix operations (e.g., covariance matrix multiplication) and solver iterations, where __`n`__ is the number of assets. __`SLSQP`’s__ exact complexity depends on convergence but is typically polynomial.
- __Space Complexity:__ __`O(n^2)`__ for storing the covariance matrix and __`O(n)`__ for weights and returns.

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
Optimal Weights: [0.16666666666666666, 0.6666666666666666, 0.16666666666666666]
Portfolio Risk: 0.05773502691896258
```
