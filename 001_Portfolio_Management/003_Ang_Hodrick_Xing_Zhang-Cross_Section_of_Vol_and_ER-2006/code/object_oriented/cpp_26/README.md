# Ang, Hodrick, Xing, & Zhang (2006) - The Cross-Section of Volatility and Expected Returns - __`C++26` Object-Oriented Code__

## File Structure
```
├── module/
│   ├── volatility_sorting.ixx
│
├── src/
│   ├── main.cpp
│   ├── volatility_sorting.cpp
│
├── CMakeLists.txt
├── README.md
```

## Explanation
- __OOP:__ __`VolatilitySorter`__ manages the returns matrix and sorting logic. Uses __`modules`__ for better encapsulation and __`std::expected`__ for error handling, reflecting __`C++26`’s focus on robust error management__.
- __Latest Features:__ __`C++26`__ uses __`modules`__, __`std::expected`__, __`C++26`'s__ modern random generation (same as __`C++23`__), and [__`Eigen`__](https://github.com/PX4/eigen) for efficient matrix operations.
- __Algorithm:__ Computes total volatility (as a proxy for idiosyncratic) and sorts assets into portfolios.

## Complexity
- __Time Complexity:__ $$O(NlogN)$$ for sorting $$N$$ assets.
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
./volatility_sorting
```
- Expected Output:
```
Portfolio 0: [<asset indices>]
Portfolio 1: [<asset indices>]
...
```
