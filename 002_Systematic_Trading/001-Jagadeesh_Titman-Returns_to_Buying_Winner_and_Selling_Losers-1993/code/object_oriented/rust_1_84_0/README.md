# Jegadeesh & Titman (1993) - Returns to Buying Winners and Selling Losers - __`Rust 1.84.0` Object-Oriented Code__

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
- __OOP:__ The __`MomentumStrategy`__ `struct` ncapsulates state, with methods to compute winners, losers, and portfolio returns. Uses __`Rust 1.84.0`’s__ error handling and [__`nalgebra`__](https://github.com/dimforge/nalgebra) for matrix operations.
- __Latest Features:__ __`Rust 1.84.0`’s__ pattern matching and __`rand_distr` for random data generation__.
- __Algorithm:__ Ranks assets by past returns, selects top/bottom deciles, and computes long-short portfolio returns.

## Complexity
- __Time Complexity:__ $$O(TNlogN)$$ for sorting $N$ assets over $T$ periods (lookback period).
- __Space Complexity:__ $$O(TN)$$ for the returns matrix, $$O(N)$$ for weights and temporary storage.

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
Portfolio Weights: [[0.2, 0.0, ..., -0.2, 0.0]]
Portfolio Return: <value>
```
