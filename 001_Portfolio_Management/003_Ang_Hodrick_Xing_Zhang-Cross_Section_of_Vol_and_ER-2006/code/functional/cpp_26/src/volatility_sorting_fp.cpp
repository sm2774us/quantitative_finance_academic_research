#include "volatility_sorting_fp.hpp"
#include <algorithm>

namespace volatility_sorting_fp
{
    double compute_volatility(const Eigen::MatrixXd &returns, int asset)
    {
        Eigen::VectorXd asset_returns = returns.col(asset);
        double mean = asset_returns.mean();
        double variance = (asset_returns.array() - mean).square().mean();
        return std::sqrt(variance);
    }

    std::vector<std::vector<int>> sort_assets(const Eigen::MatrixXd &returns, int n_portfolios)
    {
        std::vector<std::pair<double, int>> volatilities;
        for (int i = 0; i < returns.cols(); ++i)
        {
            volatilities.emplace_back(compute_volatility(returns, i), i);
        }
        std::sort(volatilities.begin(), volatilities.end());
        std::vector<std::vector<int>> portfolios(n_portfolios);
        int portfolio_size = returns.cols() / n_portfolios;
        for (int i = 0; i < returns.cols(); ++i)
        {
            int portfolio_idx = i / portfolio_size;
            if (portfolio_idx < n_portfolios)
            {
                portfolios[portfolio_idx].push_back(volatilities[i].second);
            }
        }
        return portfolios;
    }
}
