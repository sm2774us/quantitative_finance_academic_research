# Ang, Hodrick, Xing, & Zhang (2006) - The Cross-Section of Volatility and Expected Returns - __`Python 3.11` Object-Oriented Code__

## File Structure
```
├── src/
│   ├── volatility_sorting/
│   │   ├── __init__.py
│   │   ├── sorter.py
│   ├── main.py
│
├── pyproject.toml
├── README.md
```

## Explanation
- __OOP:__ The __`VolatilitySorter`__ class encapsulates returns and sorting logic.
- __Latest Features:__ __`Python 3.11`__ __type hints__ and __`Poetry`__.
- __Algorithm:__ Computes volatility per asset and sorts into portfolios.

## Complexity
- __Time Complexity:__ $$O(NlogN)$$ for sorting $$N$$ assets.
- __Space Complexity:__ $$O(N)$$ for storing volatilities and portfolios.

## Build and Run Instructions
- Setup Poetry:
```bash
poetry install
```
- Run:
```bash
poetry run python src/main.py
```
- Expected Output:
```
Portfolio 0: [<asset indices>]
Portfolio 1: [<asset indices>]
...
```
