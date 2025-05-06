#include "hrp_fp.hpp"
#include <stdexcept>

namespace hrp_fp
{
    Eigen::VectorXd optimize(const Eigen::MatrixXd &cov_matrix)
    {
        int n_assets = cov_matrix.rows();
        if (cov_matrix.cols() != n_assets)
        {
            throw std::invalid_argument("Covariance matrix must be square");
        }
        return Eigen::VectorXd::Ones(n_assets) / n_assets;
    }
}
