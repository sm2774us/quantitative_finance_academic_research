#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <ranges>
#include <sstream>
#include <string>
#include <vector>
#include <flat_map>
#include <format>

struct EpsData
{
    std::string company_id;
    std::string quarter;
    double eps;

    static EpsData from_csv_line(const std::string &line)
    {
        std::stringstream ss(line);
        std::string company_id, quarter, eps_str;
        std::getline(ss, company_id, ',');
        std::getline(ss, quarter, ',');
        std::getline(ss, eps_str, ',');
        return {company_id, quarter, std::stod(eps_str)};
    }
};

class MomentumCalculator
{
public:
    explicit MomentumCalculator(int lookback = 4) : lookback_(lookback) {}

    auto compute_signal(const std::vector<EpsData> &eps_data) const
    {
        // Group by company using ranges
        std::flat_map<std::string, std::vector<EpsData>> company_eps;
        for (const auto &record : eps_data)
        {
            company_eps[record.company_id].push_back(record);
        }

        std::vector<std::pair<std::string, double>> results;
        for (auto &[company_id, records] : company_eps)
        {
            auto sorted_records = records | std::ranges::to<std::vector>();
            std::ranges::sort(sorted_records, {}, &EpsData::quarter);
            if (sorted_records.size() < static_cast<size_t>(lookback_ + 1))
            {
                continue;
            }

            const double latest_eps = sorted_records.back().eps;
            const double past_eps = sorted_records[sorted_records.size() - 1 - lookback_].eps;
            auto eps_values = sorted_records | std::views::take_last(5) | std::views::transform(&EpsData::eps) | std::ranges::to<std::vector>();
            const double sigma = stddev(eps_values);
            if (sigma == 0.0)
            {
                continue;
            }
            results.emplace_back(company_id, (latest_eps - past_eps) / sigma);
        }
        return results;
    }

private:
    int lookback_;

    static double stddev(const std::vector<double> &values)
    {
        if (values.empty())
            return 0.0;
        const double mean = std::ranges::sum(values) / values.size();
        const double variance = std::ranges::fold_left(
                                    values | std::views::transform([&](double x)
                                                                   { return (x - mean) * (x - mean); }),
                                    0.0,
                                    std::plus{}) /
                                values.size();
        return std::sqrt(variance);
    }
};

std::vector<EpsData> load_eps_data(const std::string &file_path)
{
    std::ifstream file(file_path);
    std::vector<EpsData> data;
    std::string line;
    std::getline(file, line); // Skip header
    while (std::getline(file, line))
    {
        data.push_back(EpsData::from_csv_line(line));
    }
    return data;
}

int main()
{
    MomentumCalculator calc;
    auto eps_data = load_eps_data("eps_data.csv");
    auto signals = calc.compute_signal(eps_data);
    for (const auto &[company_id, signal] : signals)
    {
        std::cout << std::format("{}: {:.4f}\n", company_id, signal);
    }
    return 0;
}
