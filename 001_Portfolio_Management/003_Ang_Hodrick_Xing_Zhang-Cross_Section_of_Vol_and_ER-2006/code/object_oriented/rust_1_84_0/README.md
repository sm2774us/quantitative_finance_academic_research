# Ang, Hodrick, Xing, & Zhang (2006) - The Cross-Section of Volatility and Expected Returns - __`Rust 1.84.0` Object-Oriented Code__

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
- __OOP:__ The __`VolatilitySorter`__ `struct` with methods for volatility and sorting.
- __Latest Features:__ __`Rust 1.84.0`’s__ error handling and [__`nalgebra`__](https://github.com/dimforge/nalgebra) for matrix operations.
- __Algorithm:__ Computes total volatility (as a proxy for idiosyncratic) and sorts assets into portfolios.

## Complexity
- __Time Complexity:__ $$O(NlogN)$$ for sorting $$N$$ assets.
- __Space Complexity:__ $$O(N)$$ for storing volatilities and portfolios.

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
Portfolio 0: [<asset indices>]
Portfolio 1: [<asset indices>]
...
```
