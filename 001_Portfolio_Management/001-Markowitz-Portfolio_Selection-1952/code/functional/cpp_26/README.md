# Markowitz (1952) - Portfolio Selection - __`C++26` Functional-Programming Code__

## File Structure
```
├── src/
│   ├── main.cpp
│   ├── markowitz_fp.cpp
│   ├── markowitz_fp.hpp
│
├── CMakeLists.txt
├── README.md
```

## Explanation
- __FP:__ Avoids state, using pure functions within a namespace. Data is passed explicitly, and lambdas handle optimization callbacks.
- __Latest Features:__ __`C++26`__ uses modern [__`Eigen`__](https://github.com/PX4/eigen) integration and leverages [__`NLopt`’s__](https://github.com/stevengj/nlopt) __SLSQP solver__.

## Complexity
- __Time Complexity:__ __`O(n^3)`__ for matrix operations (e.g., covariance matrix multiplication) and solver iterations, where __`n`__ is the number of assets. __`SLSQP`’s__ exact complexity depends on convergence but is typically polynomial.
- __Space Complexity:__ __`O(n^2)`__ for storing the covariance matrix and __`O(n)`__ for weights and returns.

## Build and Run Instructions
- Install Dependencies:
  - Install __`Eigen`__ on __(`Ubuntu`) or equivalent__  or build from source :
  ```bash
  sudo apt-get install libeigen3-dev
  ```
  - Install __`NLopt`__ on __(`Ubuntu`) or equivalent__  or build from source :
  ```bash
  sudo apt-get install libnlopt-dev
  ```
- Build:
```bash
mkdir build && cd build
cmake ..
make
```
- Run:
```bash
./markowitz
```
- Expected Output:
```
Optimal Weights: 0.166667 0.666667 0.166667
Portfolio Risk: 0.057735
```
