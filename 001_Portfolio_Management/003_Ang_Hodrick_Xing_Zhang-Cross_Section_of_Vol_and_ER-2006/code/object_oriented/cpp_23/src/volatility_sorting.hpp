#pragma once
#include <Eigen/Dense>
#include <vector>

class VolatilitySorter
{
public:
    VolatilitySorter(const Eigen::MatrixXd &returns, int n_portfolios);
    std::vector<std::vector<int>> sort_assets() const;

private:
    Eigen::MatrixXd returns_;
    int n_portfolios_;

    double compute_volatility(int asset) const; // Total volatility as proxy
};
