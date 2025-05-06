# Jegadeesh & Titman (1993) - Returns to Buying Winners and Selling Losers - __`C++23` Object-Oriented Code__

## File Structure
```
├── src/
│   ├── main.cpp
│   ├── momentum.cpp
│   ├── momentum.hpp
│
├── CMakeLists.txt
├── README.md
```

## Explanation
- __OOP:__ The __`MomentumStrategy`__ class manages the returns matrix and parameters, with methods to compute winners, losers, and portfolio returns. __`C++23`__ uses __modern random number generation__ and __`Eigen` for matrix operations__.
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
