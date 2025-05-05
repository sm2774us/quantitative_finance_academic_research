# Fama & French (1993) - Common Risk Factors in Stock and Bond Returns - __`Python 3.11` Object-Oriented Code__

## File Structure
```
├── src/
│   ├── markowitz/
│   │   ├── __init__.py
│   │   ├── model.py
│   ├── main.py
│
├── pyproject.toml
├── README.md
```

## Explanation
- __OOP:__ The __`FamaFrenchModel`__ class encapsulates the regression process, maintaining state via the fitted model.
- __Features:__ Uses __`Python 3.11`’s__ enhanced `type hints` and __`Poetry`__ for `dependency management`.
- __Algorithm:__ __`Ordinary Least Squares` (`OLS`) regression estimates the coefficients__.

## Complexity
- __Time Complexity:__ $$O(Tk^{2})$$, where __$$T$$ is the number of time periods__ and __$$k=3$$ (number of factors)__, due to `OLS` computation.
- __Space Complexity:__ $$O(Tk)$$ for storing returns and factors.

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
Alpha: <value>, Beta_Mkt: <value>, Beta_SMB: <value>, Beta_HML: <value>
<Detailed regression summary>
```
