#pragma once
#include <Eigen/Dense>
#include <utiity>

class MarkowitzOptimizer
{
public:
    MarkowitzOptimizer(const Eigen::VectorXd &returns, const Eigen::MatrixXd &cov_matrix);
    std::pair<Eigen::VectorXd, double> optimize(double target_return) const;

private:
    Eigen::VectorXd returns_;
    Eigen::MatrixXd cov_matrix_;
    int n_assets_;

    double objective(const Eigen::VectorXd &weights) const;
    bool constraint_return(const Eigen::VectorXd &weights, double target_return) const;
    bool constraint_sum(const Eigen::VectorXd &weights) const;
};
