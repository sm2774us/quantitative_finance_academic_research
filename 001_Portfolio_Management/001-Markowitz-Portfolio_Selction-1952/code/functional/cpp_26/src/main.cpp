#include "markowitz_fp.hpp"
#include <iostream>

int main()
{
    Eigen::VectorXd returns(3);
    returns << 0.1, 0.12, 0.15;
    Eigen::MatrixXd cov_matrix(3, 3);
    cov_matrix << 0.005, -0.002, 0.001,
        -0.002, 0.004, -0.001,
        0.001, -0.001, 0.006;
    auto [weights, risk] = markowitz_fp::optimize(returns, cov_matrix, 0.13);
    std::cout << "Optimal Weights: " << weights.transpose() << std::endl;
    std::cout << "Portfolio Risk: " << risk << std::endl;
    return 0;
}
