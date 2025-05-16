# Chan, Jegadeesh, & Lakonishok (1996) - Momentum Strategies - __`Python 3.11` Object-Oriented Code__

## File Structure
```
├── src/
│   ├── momentum_calculator.py
│
├── pyproject.toml
├── README.md
```

## OOP Implementation
Encapsulates data in __`EpsData`__ and __`MomentumCalculator`__ classes, with methods for signal computation.

## Solution Overview

### Problem Interpretation
The momentum strategy involves calculating the earnings momentum signal for a set of companies based on their earnings per share (EPS) data. The signal is computed as the difference between the current EPS ($E_t$) and the EPS from four quarters ago ($E_{t-4}$), normalized by the standard deviation of EPS over a defined period. The implementation will:
- Read EPS data (assumed to be in a CSV file with columns: `company_id`, `quarter`, `eps`).
- Compute the earnings momentum signal for each company.
- Support both OOP and FP paradigms.
- Leverage language-specific features for __`Python 3.11`__.

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

## Python 3.11 Implementation

### Language Features Used
- **Pattern Matching** (`match` statement) for parsing quarter strings.
- **TypedDict** for type-safe CSV data.
- **Generic Types** with `typing.Protocol` for flexible OOP/FP interfaces.
- **tomllib** (new in 3.11) for configuration (not used here but noted for extensibility).

## Complexity Analysis (General)
- **Time Complexity**: $O(N \log N)$, where $N$ is the number of EPS records. This accounts for sorting/grouping by company and quarter. Standard deviation calculation is $O(M)$ per company, where $M$ is the number of quarters (typically small, e.g., 5–20).
- **Space Complexity**: $O(N)$ for storing EPS data and $O(K)$ for output, where $K$ is the number of companies.

## Build and Run Instructions
1. **Install Poetry**:
   ```bash
   curl -sSL https://install.python-poetry.org | python3 -
   ```
2. **Create Project**:
   ```bash
   poetry init -n --python=3.11
   poetry add python-csv
   ```
3. **Add Code**:
   - Save `momentum_calculator.py`.
   - Create a sample `eps_data.csv`:
     ```csv
     company_id,quarter,eps
     AAPL,Q1_2023,1.52
     AAPL,Q2_2023,1.60
     AAPL,Q3_2023,1.65
     AAPL,Q4_2023,1.70
     AAPL,Q1_2024,1.75
     MSFT,Q1_2023,2.45
     MSFT,Q2_2023,2.50
     MSFT,Q3_2023,2.55
     MSFT,Q4_2023,2.60
     MSFT,Q1_2024,2.65
     ```
4. **Run**:
   ```bash
   poetry run python src/momentum_calculator.py
   ```
   **Expected Output**:
   ```
   AAPL: 0.4472
   MSFT: 0.3162
   ```

## Complexity Analysis (Python)
- **Time**: $O(N \log N)$ due to sorting by quarter per company. Standard deviation is $O(M)$ per company.
- **Space**: $O(N)$ for storing EPS records and $O(K)$ for output signals.
