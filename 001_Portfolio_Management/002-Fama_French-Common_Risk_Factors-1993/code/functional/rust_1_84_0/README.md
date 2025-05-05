# Fama & French (1993) - Common Risk Factors in Stock and Bond Returns - __`Rust 1.84.0` Functional-Programming Code__

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
- __OOP:__ The __`fit_fama_french`__ `function` computes coefficients statelessly.
- __Latest Features:__ __`Rust 1.84.0`’s__ error handling and and [__`nalgebra`__](https://github.com/dimforge/nalgebra) for matrix operations.
- __Algorithm:__ Manual __Ordinary Least Squares (`OLS`) implementation__ for simplicity (real-world would use __Generalized Least Squares (`GLS`)__ or similar).

## Complexity
- __Time Complexity:__ $$O(Tk^{2})$$, where __$$T=100$$ is the number of time periods__ and __$$k=4$$ (number of factors including intercept)__.
- __Space Complexity:__ $$O(Tk)$$ for storing returns and factors.

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
Alpha: <value>
Beta_Mkt: <value>
Beta_SMB: <value>
Beta_HML: <value>
```
