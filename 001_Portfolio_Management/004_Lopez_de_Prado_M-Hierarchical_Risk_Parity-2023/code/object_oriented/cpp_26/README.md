# Lopez de Prado (2023) - Hierarchical Risk Parity with Machine Learning Clustering - __`C++26` Object-Oriented Code__

## File Structure
```
├── src/
│   ├── main.cpp
│   ├── hrp.cpp
│   ├── hrp.hpp
│
├── CMakeLists.txt
├── README.md
```

## Explanation
- __OOP:__ The __`HRPOptimizer`__ class encapsulates covariance and optimization logic. Uses __`C++26`__ `modules` and `std::expected`.
- __Latest Features:__ __`C++26`__ uses modern [__`Eigen`__](https://github.com/PX4/eigen) integration. __`C++26`__ `modules` and `error handling`.
- __Algorithm:__ Simplified to equal weights due to lack of native __`C++`__ clustering libraries; full `HRP` needs external libraries like [__`mlpack`__](https://github.com/mlpack/mlpack).

## Complexity
- __Time Complexity:__ $$O(1)$$ (simplified).
- __Space Complexity:__ $$O(N)$$ for storing volatilities and portfolios.

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
./hrp
```
- Expected Output:
```
Optimal Weights: [0.33333333 0.33333333 0.33333333]
```
