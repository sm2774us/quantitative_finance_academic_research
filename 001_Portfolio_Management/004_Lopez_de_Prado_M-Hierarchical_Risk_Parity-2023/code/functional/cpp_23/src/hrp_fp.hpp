#pragma once
#include <Eigen/Dense>

namespace hrp_fp
{
    Eigen::VectorXd optimize(const Eigen::MatrixXd &cov_matrix);
}
