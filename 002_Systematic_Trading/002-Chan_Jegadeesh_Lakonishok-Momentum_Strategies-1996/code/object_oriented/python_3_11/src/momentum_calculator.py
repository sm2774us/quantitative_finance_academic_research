from typing import List, Dict, TypedDict
from dataclasses import dataclass
import csv
import math
from collections import defaultdict

class EpsRecord(TypedDict):
    company_id: str
    quarter: str
    eps: float

@dataclass
class EpsData:
    company_id: str
    quarter: str
    eps: float

    @staticmethod
    def from_dict(record: EpsRecord) -> 'EpsData':
        return EpsData(record['company_id'], record['quarter'], float(record['eps']))

class MomentumCalculator:
    def __init__(self, lookback: int = 4):
        self.lookback = lookback

    def compute_signal(self, eps_data: List[EpsData]) -> List[tuple[str, float]]:
        # Group by company
        company_eps: Dict[str, List[EpsData]] = defaultdict(list)
        for record in eps_data:
            company_eps[record.company_id].append(record)

        results = []
        for company_id, records in company_eps.items():
            # Sort by quarter (assuming Q1_YYYY format)
            records.sort(key=lambda x: self._parse_quarter(x.quarter))
            if len(records) < self.lookback + 1:
                continue

            # Compute momentum for the latest quarter
            latest_eps = records[-1].eps
            past_eps = records[-1 - self.lookback].eps
            eps_values = [r.eps for r in records[-5:]]  # Last 5 quarters for stddev
            stddev = self._stddev(eps_values)
            if stddev == 0:
                continue
            momentum = (latest_eps - past_eps) / stddev
            results.append((company_id, momentum))

        return results

    def _parse_quarter(self, quarter: str) -> tuple[int, int]:
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

    def _stddev(self, values: List[float]) -> float:
        if not values:
            return 0.0
        mean = sum(values) / len(values)
        variance = sum((x - mean) ** 2 for x in values) / len(values)
        return math.sqrt(variance)

def load_eps_data(file_path: str) -> List[EpsData]:
    with open(file_path, 'r') as f:
        reader = csv.DictReader(f)
        return [EpsData.from_dict(row) for row in reader]

if __name__ == "__main__":
    calculator = MomentumCalculator()
    eps_data = load_eps_data("eps_data.csv")
    signals = calculator.compute_signal(eps_data)
    for company_id, signal in signals:
        print(f"{company_id}: {signal:.4f}")
