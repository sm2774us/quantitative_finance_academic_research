# Lopez de Prado (2023) - Hierarchical Risk Parity with Machine Learning Clustering - __`Python 3.11` Functional-Programming Code__

## File Structure
```
├── src/
│   ├── functional.py
│
├── pyproject.toml
├── README.md
```

## Explanation
- __FP:__ The __`hrp_optimize`__ function performs the same task statelessly.
- __Latest Features:__ __`Python 3.11`__ __type hints__ and __`SciPy`__ for clustering.
- __Algorithm:__ Simplified __Hierarchical Risk Parity (`HRP`)__ using hierarchical clustering; returns equal weights for demonstration (full HRP requires recursive risk allocation).

## Complexity
- __Time Complexity:__ $$O(N^{2})$$ for hierarchical clustering.
- __Space Complexity:__ $$O(N^{2})$$.

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
Optimal Weights: [0.33333333 0.33333333 0.33333333]
```
