# Chan, Jegadeesh, & Lakonishok (1996) - Momentum Strategies - __`Python 3.11` Functional-Programming Code__

## File Structure
```
├── src/
│   ├── momentum_calculator.py
│
├── pyproject.toml
├── README.md
```

## FP Implementation
Uses pure functions, immutable data, and functional constructs like __`map`__ and __`reduce`__.

## Explanation
- **OOP**: Define classes/structs for data (e.g., `Company`, `EpsData`) and a processor (e.g., `MomentumCalculator`) to encapsulate logic.
- **Data Processing**:
  1. Parse CSV into a data structure.
  2. Group EPS data by company.
  3. For each company, compute $E_t - E_{t-4}$ and $\sigma_E$.
  4. Calculate and return the momentum signal.

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
