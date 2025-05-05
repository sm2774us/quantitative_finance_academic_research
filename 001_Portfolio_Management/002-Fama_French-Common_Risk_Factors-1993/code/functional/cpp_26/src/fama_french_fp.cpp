#include "fama_french_fp.hpp"

namespace fama_french_fp
{
    std::tuple<double, double, double, double> fit_fama_french(
        const Eigen::VectorXd &stock_returns, const Eigen::MatrixXd &factors)
    {
        if (stock_returns.size() != factors.rows() || factors.cols() != 3)
        {
            throw std::invalid_argument("Dimension mismatch");
        }
        Eigen::MatrixXd X(factors.rows(), 4);
        X.col(0).setOnes();
        X.block(0, 1, factors.rows(), 3) = factors;
        Eigen::MatrixXd XtX = X.transpose() * X;
        Eigen::MatrixXd XtX_inv = XtX.inverse();
        Eigen::VectorXd coefficients = XtX_inv * X.transpose() * stock_returns;
        return {coefficients(0), coefficients(1), coefficients(2), coefficients(3)};
    }
}
