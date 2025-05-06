# Jegadeesh & Titman (1993) - Returns to Buying Winners and Selling Losers - __`C++26` Functional-Programming Code__

## File Structure
```
├── src/
│   ├── main.cpp
│   ├── momentum_fp.cpp
│   ├── momentum_fp.hpp
│
├── CMakeLists.txt
├── README.md
```

## Explanation
- __FP:__ Pure functions in a namespace, avoiding state. Each function computes a specific part of the strategy (winners, losers, portfolio).
- __Algorithm:__ Ranks assets by past returns, selects top/bottom deciles, and computes long-short portfolio returns.

## Complexity
- __Time Complexity:__ $$O(TNlogN)$$ for sorting $N$ assets over $T$ periods (lookback period).
- __Space Complexity:__ $$O(TN)$$ for the returns matrix, $$O(N)$$ for weights and temporary storage.

## Build and Run Instructions
- Install Dependencies:
  - Install __`Eigen`__ on __(`Ubuntu`) or equivalent__  or build from source :
  ```bash
  sudo apt-get install libeigen3-dev
  ```
- Build:
```bash
mkdir build && cd build
cmake ..
make
```
- Run:
```bash
./momentum
```
- Expected Output:
```
Portfolio Weights: [0.2, 0, 0, ..., -0.2, 0]
Portfolio Return: <value>
```
