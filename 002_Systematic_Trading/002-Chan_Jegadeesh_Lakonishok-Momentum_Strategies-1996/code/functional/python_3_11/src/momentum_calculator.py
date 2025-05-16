from typing import List, Tuple, Dict
from functools import reduce
import csv
import math
from collections import defaultdict

def parse_quarter(quarter: str) -> Tuple[int, int]:
    match quarter.split('_'):
        case ['Q1', year]:
            return (int(year), 1)
        case ['Q2', year]:
            return (int(year), 2)
        case ['Q3', year]:
            return (int(year), 3)
        case ['Q4', year]:
            return (int(year), 4)
        case _:
            raise ValueError(f"Invalid quarter format: {quarter}")

def stddev(values: List[float]) -> float:
    if not values:
        return 0.0
    mean = sum(values) / len(values)
    variance = sum((x - mean) ** 2 for x in values) / len(values)
    return math.sqrt(variance)

def compute_momentum_signal(
    eps_data: List[Dict[str, str]], lookback: int = 4
) -> List[Tuple[str, float]]:
    # Group by company
    company_eps: Dict[str, List[Dict[str, str]]] = defaultdict(list)
    for record in eps_data:
        company_eps[record['company_id']].append(record)

    def process_company(
        company_id: str, records: List[Dict[str, str]]
    ) -> Tuple[str, float] | None:
        # Sort by quarter
        sorted_records = sorted(records, key=lambda x: parse_quarter(x['quarter']))
        if len(sorted_records) < lookback + 1:
            return None

        # Compute momentum
        latest_eps = float(sorted_records[-1]['eps'])
        past_eps = float(sorted_records[-1 - lookback]['eps'])
        eps_values = [float(r['eps']) for r in sorted_records[-5:]]
        sigma = stddev(eps_values)
        if sigma == 0:
            return None
        return (company_id, (latest_eps - past_eps) / sigma)

    # Map and filter valid results
    results = [
        result
        for result in map(
            lambda x: process_company(x[0], x[1]), company_eps.items()
        )
        if result is not None
    ]

    return results

def load_eps_data(file_path: str) -> List[Dict[str, str]]:
    with open(file_path, 'r') as f:
        return list(csv.DictReader(f))

if __name__ == "__main__":
    eps_data = load_eps_data("eps_data.csv")
    signals = compute_momentum_signal(eps_data)
    for company_id, signal in signals:
        print(f"{company_id}: {signal:.4f}")
