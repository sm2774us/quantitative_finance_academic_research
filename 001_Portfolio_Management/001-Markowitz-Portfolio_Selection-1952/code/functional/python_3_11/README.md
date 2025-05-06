# Markowitz (1952) - Portfolio Selection - __`Python 3.11` Functional-Programming Code__

## File Structure
```
├── src/
│   ├── functional.py
│
├── pyproject.toml
├── README.md
```

## Explanation
- __FP:__ The functional version avoids state, using pure functions and passing all data explicitly. It achieves the same result but is more modular for composition.
- __Latest Features:__ __`Python 3.11`__ `type hints` (e.g., __`np.ndarray`__) and __`Poetry`__ for `dependency management`.
- __Algorithm:__ Uses [__`SciPy`’s__](https://github.com/scipy/scipy) minimize with the __`SLSQP` solver__ to handle `the quadratic optimization problem with linear constraints`.

## Complexity
- __Time Complexity:__ __`O(n^3)`__ for matrix operations (e.g., covariance matrix multiplication) and solver iterations, where __`n`__ is the number of assets. __`SLSQP`’s__ exact complexity depends on convergence but is typically polynomial.
- __Space Complexity:__ __`O(n^2)`__ for storing the covariance matrix and __`O(n)`__ for weights and returns.

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
Optimal Weights: [0.16666667 0.66666667 0.16666667]
Portfolio Risk: 0.05773502691896258
```
