# Chan, Jegadeesh, & Lakonishok (1996) - Momentum Strategies - __`C++23` Object-Oriented Code__

## File Structure
```
├── src/
│   ├── momentum_calculator.cpp
│
├── pyproject.toml
├── README.md
```

## OOP Implementation
Uses classes for __`EpsData`__ and __`MomentumCalculator`__.

## Solution Overview

### Problem Interpretation
The momentum strategy involves calculating the earnings momentum signal for a set of companies based on their earnings per share (EPS) data. The signal is computed as the difference between the current EPS ($E_t$) and the EPS from four quarters ago ($E_{t-4}$), normalized by the standard deviation of EPS over a defined period. The implementation will:
- Read EPS data (assumed to be in a CSV file with columns: `company_id`, `quarter`, `eps`).
- Compute the earnings momentum signal for each company.
- Support both OOP and FP paradigms.
- Leverage language-specific features for __`C++23`__.

### Assumptions
- Input CSV format: `company_id,quarter,eps` (e.g., `AAPL,Q1_2023,1.52`).
- Quarters are sequential and identified by strings (e.g., `Q1_2023`).
- At least 5 quarters of data are available to compute $E_t - E_{t-4}$ and $\sigma_E$.
- Output: A list of `company_id` and their momentum signals.

### General Approach
- **OOP**: Define classes/structs for data (e.g., `Company`, `EpsData`) and a processor (e.g., `MomentumCalculator`) to encapsulate logic.
- **FP**: Use immutable data, pure functions, and functional constructs (e.g., map, fold) to compute signals.
- **Data Processing**:
  1. Parse CSV into a data structure.
  2. Group EPS data by company.
  3. For each company, compute $E_t - E_{t-4}$ and $\sigma_E$.
  4. Calculate and return the momentum signal.

### Complexity Analysis (General)
- **Time Complexity**: $O(N \log N)$, where $N$ is the number of EPS records. This accounts for sorting/grouping by company and quarter. Standard deviation calculation is $O(M)$ per company, where $M$ is the number of quarters (typically small, e.g., 5–20).
- **Space Complexity**: $O(N)$ for storing EPS data and $O(K)$ for output, where $K$ is the number of companies.

---

## C++23 Implementation

### Language Features Used
- **Ranges** for functional-style data processing.
- **Format Library** for string formatting.
- **Flat Map** (from `std::flat_map`) for efficient company grouping.
- **Structured Bindings** for cleaner tuple handling.

## Complexity Analysis (General)
- **Time Complexity**: $O(N \log N)$, where $N$ is the number of EPS records. This accounts for sorting/grouping by company and quarter. Standard deviation calculation is $O(M)$ per company, where $M$ is the number of quarters (typically small, e.g., 5–20).
- **Space Complexity**: $O(N)$ for storing EPS data and $O(K)$ for output, where $K$ is the number of companies.

## Build and Run Instructions
1. **Install Dependencies**:
   ```bash
   sudo apt update
   sudo apt install build-essential cmake g++-13
   ```
2. **Create `CMakeLists.txt`**:
   ```cmake
   cmake_minimum_required(VERSION 3.22)
   project(MomentumCpp23)
   
   # Set the C++ standard to C++23
   set(CMAKE_CXX_STANDARD 23)
   set(CMAKE_CXX_COMPILER g++-13)
   set(CMAKE_CXX_STANDARD_REQUIRED ON)
   
   # Add the executable and the source files
   add_executable(momentum src/momentum_calculator.cpp)
   ```
3. **Add Code and Data**:
   - Save `momentum_calculator.cpp`.
   - Use the same `eps_data.csv` as in Python.
4. **Build**:
   ```bash
   mkdir build && cd build
   cmake ..
   make
   ```
4. **Run**:
   ```bash
   ./momentum_calculator
   ```
   **Expected Output**:
   ```
   AAPL: 0.4472
   MSFT: 0.3162
   ```

### Complexity Analysis (C++23)
- **Time**: $O(N \log N)$ for sorting and grouping.
- **Space**: $O(N)$ for data storage, $O(K)$ for output.

