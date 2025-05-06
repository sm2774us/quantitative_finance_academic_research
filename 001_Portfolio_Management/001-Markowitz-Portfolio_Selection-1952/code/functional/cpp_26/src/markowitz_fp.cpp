#include "markowitz_fp.hpp"
#include <nlopt.hpp>
#include <cmath>
#include <stdexcept>

namespace markowitz_fp
{
    double objective(const Eigen::VectorXd &weights, const Eigen::MatrixXd &cov_matrix)
    {
        return std::sqrt(weights.transpose() * cov_matrix * weights);
    }

    double constraint_return(const Eigen::VectorXd &weights, const Eigen::VectorXd &returns, double target_return)
    {
        return weights.dot(returns) - target_return;
    }

    double constraint_sum(const Eigen::VectorXd &weights)
    {
        return weights.sum() - 1.0;
    }

    std::pair<Eigen::VectorXd, double> optimize(
        const Eigen::VectorXd &returns,
        const Eigen::MatrixXd &cov_matrix,
        double target_return)
    {
        int n_assets = returns.size();
        if (cov_matrix.rows() != n_assets || cov_matrix.cols() != n_assets)
        {
            throw std::invalid_argument("Covariance matrix dimensions mismatch");
        }
        nlopt::opt opt(nlopt::LD_SLSQP, n_assets);
        std::vector<double> weights(n_assets, 1.0 / n_assets);
        opt.set_min_objective(
            [](const std::vector<double> &w, std::vector<double> &, void *data)
            {
                auto *params = static_cast<std::pair<const Eigen::MatrixXd *, const Eigen::VectorXd *> *>(data);
                Eigen::Map<const Eigen::VectorXd> weights(w.data(), w.size());
                return objective(weights, *params->first);
            },
            new std::pair<const Eigen::MatrixXd *, const Eigen::VectorXd *>(&cov_matrix, &returns));
        opt.add_equality_constraint(
            [](const std::vector<double> &w, std::vector<double> &, void *data)
            {
                auto *params = static_cast<std::pair<const Eigen::VectorXd *, double> *>(data);
                Eigen::Map<const Eigen::VectorXd> weights(w.data(), w.size());
                return constraint_return(weights, *params->first, params->second);
            },
            new std::pair<const Eigen::VectorXd *, double>(&returns, target_return),
            1e-6);
        opt.add_equality_constraint(
            [](const std::vector<double> &w, std::vector<double> &, void *data)
            {
                Eigen::Map<const Eigen::VectorXd> weights(w.data(), w.size());
                return constraint_sum(weights);
            },
            nullptr,
            1e-6);
        std::vector<double> lb(n_assets, 0.0), ub(n_assets, 1.0);
        opt.set_lower_bounds(lb);
        opt.set_upper_bounds(ub);
        double minf;
        opt.optimize(weights, minf);
        Eigen::VectorXd result = Eigen::Map<Eigen::VectorXd>(weights.data(), n_assets);
        return {result, minf};
    }
}
