#pragma once
#include <Eigen/Dense>
#include <tuple>

namespace fama_french_fp
{
    std::tuple<double, double, double, double> fit_fama_french(
        const Eigen::VectorXd &stock_returns, const Eigen::MatrixXd &factors);
}
