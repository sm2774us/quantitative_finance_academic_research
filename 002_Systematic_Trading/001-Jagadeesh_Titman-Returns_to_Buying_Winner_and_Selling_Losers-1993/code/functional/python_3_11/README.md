# Jegadeesh & Titman (1993) - Returns to Buying Winners and Selling Losers - __`Python 3.11` Functional-Programming Code__

## File Structure
```
├── src/
│   ├── functional.py
│
├── pyproject.toml
├── README.md
```

## Explanation
- __FP:__ Pure functions, avoiding state. Each function handles a specific task (winners, losers, portfolio computation).
- __Latest Features:__ __`Python 3.11` type hinting (e.g., `np.ndarray`)__ and __`Poetry` for dependency management__.
- __Algorithm:__Ranks assets by past returns, selects top/bottom deciles, and computes long-short portfolio returns.

## Complexity
- __Time Complexity:__ $$O(TNlogN)$$ for sorting $N$ assets over $T$ periods (lookback).
- __Space Complexity:__ $$O(TN)$$ for the returns matrix, $$O(N)$$ for weights.

## Build and Run Instructions
- Setup Poetry:
```bash
poetry install
```
- Run:
```bash
poetry run python src/functional.py
```
- Expected Output:
```
Portfolio Weights: [0.2 0.  0.  ... -0.2 0. ]
Portfolio Return: <value>
```
