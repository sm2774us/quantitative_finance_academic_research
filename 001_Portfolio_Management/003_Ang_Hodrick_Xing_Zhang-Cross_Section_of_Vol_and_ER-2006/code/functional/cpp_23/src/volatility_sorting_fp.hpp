#pragma once
#include <Eigen/Dense>
#include <vector>

namespace volatility_sorting_fp
{
    std::vector<std::vector<int>> sort_assets(const Eigen::MatrixXd &returns, int n_portfolios);
}
