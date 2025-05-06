#pragma once
#include <Eigen/Dense>
#include <vector>

class HRPOptimizer
{
public:
    HRPOptimizer(const Eigen::MatrixXd &cov_matrix);
    Eigen::VectorXd optimize() const;

private:
    Eigen::MatrixXd cov_matrix_;
    int n_assets_;
};
