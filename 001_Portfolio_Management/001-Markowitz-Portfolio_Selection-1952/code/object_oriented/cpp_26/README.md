# Markowitz (1952) - Portfolio Selection - __`C++26` Object-Oriented Code__

## File Structure
```
├── module/
│   ├── markowitz.ixx
│
├── src/
│   ├── main.cpp
│   ├── markowitz.cpp
│
├── CMakeLists.txt
├── README.md
```

## Explanation
- __OOP:__ Uses __`modules`__ for better encapsulation and __`std::expected`__ for error handling, reflecting __`C++26`’s focus on robust error management__.
- __Latest Features:__ __`C++26`__ uses __`modules`__, __`std::expected`__, and, modern [__`Eigen`__](https://github.com/PX4/eigen) integration and leverages [__`NLopt`’s__](https://github.com/stevengj/nlopt) __SLSQP solver__.

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
