# Ang, Hodrick, Xing, & Zhang (2006) - The Cross-Section of Volatility and Expected Returns - __`Python 3.11` Functional-Programming Code__

## File Structure
```
├── src/
│   ├── functional.py
│
├── pyproject.toml
├── README.md
```

## Explanation
- __FP:__ Pure functions compute volatility and sort assets.
- __Latest Features:__ __`Python 3.11`__ __type hints__ and __`Poetry`__.
- __Algorithm:__ Computes volatility per asset and sorts into portfolios.

## Complexity
- __Time Complexity:__ $$O(NlogN)$$.
- __Space Complexity:__ $$O(N)$$.

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
Portfolio 0: [<asset indices>]
Portfolio 1: [<asset indices>]
...
```
