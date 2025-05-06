module hrp;
import <stdexcept>;

HRPOptimizer::HRPOptimizer(const Eigen::MatrixXd &cov_matrix)
    : cov_matrix_(cov_matrix), n_assets_(cov_matrix.rows())
{
    if (cov_matrix.cols() != n_assets_)
    {
        throw std::invalid_argument("Covariance matrix must be square");
    }
}

std::expected<Eigen::VectorXd, std::string> HRPOptimizer::optimize() const
{
    try
    {
        Eigen::VectorXd weights = Eigen::VectorXd::Ones(n_assets_) / n_assets_;
        return weights;
    }
    catch (const std::exception &e)
    {
        return std::unexpected(e.what());
    }
}
