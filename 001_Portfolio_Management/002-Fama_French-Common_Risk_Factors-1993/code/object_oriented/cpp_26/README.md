# Fama & French (1993) - Common Risk Factors in Stock and Bond Returns - __`C++26` Object-Oriented Code__

## File Structure
```
├── module/
│   ├── fama_french.ixx
│
├── src/
│   ├── main.cpp
│   ├── fama_french.cpp
│
├── CMakeLists.txt
├── README.md
```

## Explanation
- __OOP:__ Uses __`modules`__ for better encapsulation and __`std::expected`__ for error handling, reflecting __`C++26`’s focus on robust error management__.
- __Latest Features:__ __`C++26`__ uses __`modules`__, __`std::expected`__, and, modern [__`Eigen`__](https://github.com/PX4/eigen) integration.
- __Algorithm:__ Manual __Ordinary Least Squares (`OLS`) implementation__ for simplicity (real-world would use __Generalized Least Squares (`GLS`)__ or similar).

## Complexity
## Explanation
- __OOP:__ Uses __`modules`__ for better encapsulation and __`std::expected`__ for error handling, reflecting __`C++26`’s focus on robust error management__.
- __Latest Features:__ __`C++26`__ uses __`modules`__, __`std::expected`__, and, modern [__`Eigen`__](https://github.com/PX4/eigen) integration.
- __Algorithm:__ Manual __Ordinary Least Squares (`OLS`) implementation__ for simplicity (real-world would use __Generalized Least Squares (`GLS`)__ or similar).

## Complexity
- __Time Complexity:__ $$O(Tk^{2})$$, where __$$T=100$$ is the number of time periods__ and __$$k=4$$ (number of factors including intercept)__.
- __Space Complexity:__ $$O(Tk)$$ for storing returns and factors.

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
./fama_french
```
- Expected Output:
```
Alpha: <value>
Beta_Mkt: <value>
Beta_SMB: <value>
Beta_HML: <value>
```
