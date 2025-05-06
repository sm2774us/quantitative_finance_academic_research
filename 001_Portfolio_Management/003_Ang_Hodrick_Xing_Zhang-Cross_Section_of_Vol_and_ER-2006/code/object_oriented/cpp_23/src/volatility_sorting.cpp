#include "volatility_sorting.hpp"
#include <algorithm>

VolatilitySorter::VolatilitySorter(const Eigen::MatrixXd &returns, int n_portfolios)
    : returns_(returns), n_portfolios_(n_portfolios) {}

double VolatilitySorter::compute_volatility(int asset) const
{
    Eigen::VectorXd asset_returns = returns_.col(asset);
    double mean = asset_returns.mean();
    double variance = (asset_returns.array() - mean).square().mean();
    return std::sqrt(variance);
}

std::vector<std::vector<int>> VolatilitySorter::sort_assets() const
{
    std::vector<std::pair<double, int>> volatilities;
    for (int i = 0; i < returns_.cols(); ++i)
    {
        volatilities.emplace_back(compute_volatility(i), i);
    }
    std::sort(volatilities.begin(), volatilities.end());
    std::vector<std::vector<int>> portfolios(n_portfolios_);
    int portfolio_size = returns_.cols() / n_portfolios_;
    for (int i = 0; i < returns_.cols(); ++i)
    {
        int portfolio_idx = i / portfolio_size;
        if (portfolio_idx < n_portfolios_)
        {
            portfolios[portfolio_idx].push_back(volatilities[i].second);
        }
    }
    return portfolios;
}
