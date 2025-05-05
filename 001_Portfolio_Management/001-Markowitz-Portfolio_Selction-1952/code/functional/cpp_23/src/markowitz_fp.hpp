#pragma once
#include <Eigen/Dense>
#include <functional>
#include <vector>

namespace markowitz_fp
{
    std::pair<Eigen::VectorXd, double> optimize(
        const Eigen::VectorXd &returns,
        const Eigen::MatrixXd &cov_matrix,
        double target_return);
}
