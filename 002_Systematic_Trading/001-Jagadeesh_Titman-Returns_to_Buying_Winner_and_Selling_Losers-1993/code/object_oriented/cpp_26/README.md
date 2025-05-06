# Jegadeesh & Titman (1993) - Returns to Buying Winners and Selling Losers - __`C++26` Object-Oriented Code__

## File Structure
```
├── module/
│   ├── momentum.ixx
│
├── src/
│   ├── main.cpp
│   ├── momentum.cpp
│
├── CMakeLists.txt
├── README.md
```

## Explanation
- __OOP:__ The __`MomentumStrategy`__ class manages the returns matrix and parameters, with methods to compute winners, losers, and portfolio returns. __`C++26`__ uses __modern random number generation__, uses __`modules`__ and __`std::expected` for error handling, improving modularity and robustness__. Uses __`Eigen` for matrix operations__.
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
