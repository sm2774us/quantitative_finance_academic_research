module fama_french;
import <stdexcept>;
import <iostream>;

FamaFrenchModel::FamaFrenchModel(const Eigen::VectorXd &stock_returns, const Eigen::MatrixXd &factors)
    : stock_returns_(stock_returns), factors_(factors), coefficients_(4)
{
    if (stock_returns.size() != factors.rows() || factors.cols() != 3)
    {
        throw std::invalid_argument("Dimension mismatch");
    }
}

std::expected<void, std::string> FamaFrenchModel::fit()
{
    try
    {
        Eigen::MatrixXd X(factors_.rows(), 4);
        X.col(0).setOnes();
        X.block(0, 1, factors_.rows(), 3) = factors_;
        Eigen::MatrixXd XtX = X.transpose() * X;
        Eigen::MatrixXd XtX_inv = XtX.inverse();
        coefficients_ = XtX_inv * X.transpose() * stock_returns_;
        return {};
    }
    catch (const std::exception &e)
    {
        return std::unexpected(e.what());
    }
}

std::expected<std::tuple<double, double, double, double>, std::string> FamaFrenchModel::get_coefficients() const
{
    if (coefficients_.size() == 0)
    {
        return std::unexpected("Model not fitted");
    }
    return std::tuple{coefficients_(0), coefficients_(1), coefficients_(2), coefficients_(3)};
}

void FamaFrenchModel::print_summary() const
{
    std::cout << "Alpha: " << coefficients_(0) << "\nBeta_Mkt: " << coefficients_(1)
              << "\nBeta_SMB: " << coefficients_(2) << "\nBeta_HML: " << coefficients_(3) << std::endl;
}
