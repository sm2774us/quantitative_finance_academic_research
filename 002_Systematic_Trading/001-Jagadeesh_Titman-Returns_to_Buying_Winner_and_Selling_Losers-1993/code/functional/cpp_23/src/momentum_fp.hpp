#pragma once
#include <Eigen/Dense>
#include <vector>

namespace momentum_fp
{
    std::pair<Eigen::VectorXd, double> compute_portfolio(
        const Eigen::MatrixXd &returns,
        int lookback,
        double top_decile,
        double bottom_decile,
        int t);
}
