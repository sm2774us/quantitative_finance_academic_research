#include "markowitz.hpp"
#include <nlopt.hpp>
#include <vector>
#include <cmath>
#include <stdexcept>

MarkowitzOptimizer::MarkowitzOptimizer(const Eigen::VectorXd &returns, const Eigen::MatrixXd &cov_matrix)
    : returns_(returns), cov_matrix_(cov_matrix), n_assets_(returns.size())
{
    if (cov_matrix.rows() != n_assets_ || cov_matrix.cols() != n_assets_)
    {
        throw std::invalid_argument("Covariance matrix dimensions mismatch");
    }
}

double MarkowitzOptimizer::objective(const Eigen::VectorXd &weights) const
{
    return std::sqrt(weights.transpose() * cov_matrix_ * weights);
}

bool MarkowitzOptimizer::constraint_return(const Eigen::VectorXd &weights, double target_return) const
{
    return std::abs(weights.dot(returns_) - target_return) < 1e-6;
}

bool MarkowitzOptimizer::constraint_sum(const Eigen::VectorXd &weights) const
{
    return std::abs(weights.sum() - 1.0) < 1e-6;
}

std::pair<Eigen::VectorXd, double> MarkowitzOptimizer::optimize(double target_return) const
{
    nlopt::opt opt(nlopt::LD_SLSQP, n_assets_);
    std::vector<double> weights(n_assets_, 1.0 / n_assets_);
    opt.set_min_objective(
        [](const std::vector<double> &w, std::vector<double> &, void *data)
        {
            auto *self = static_cast<const MarkowitzOptimizer *>(data);
            Eigen::Map<const Eigen::VectorXd> weights(w.data(), w.size());
            return self->objective(weights);
        },
        const_cast<MarkowitzOptimizer *>(this));
    opt.add_equality_constraint(
        [](const std::vector<double> &w, std::vector<double> &, void *data)
        {
            auto *params = static_cast<std::pair<const MarkowitzOptimizer *, double> *>(data);
            Eigen::Map<const Eigen::VectorXd> weights(w.data(), w.size());
            return params->first->constraint_return(weights, params->second) ? 0.0 : 1.0;
        },
        new std::pair<const MarkowitzOptimizer *, double>(this, target_return),
        1e-6);
    opt.add_equality_constraint(
        [](const std::vector<double> &w, std::vector<double> &, void *data)
        {
            auto *self = static_cast<const MarkowitzOptimizer *>(data);
            Eigen::Map<const Eigen::VectorXd> weights(w.data(), w.size());
            return self->constraint_sum(weights) ? 0.0 : 1.0;
        },
        const_cast<MarkowitzOptimizer *>(this),
        1e-6);
    std::vector<double> lb(n_assets_, 0.0), ub(n_assets_, 1.0);
    opt.set_lower_bounds(lb);
    opt.set_upper_bounds(ub);
    double minf;
    opt.optimize(weights, minf);
    Eigen::VectorXd result = Eigen::Map<Eigen::VectorXd>(weights.data(), n_assets_);
    return {result, minf};
}
