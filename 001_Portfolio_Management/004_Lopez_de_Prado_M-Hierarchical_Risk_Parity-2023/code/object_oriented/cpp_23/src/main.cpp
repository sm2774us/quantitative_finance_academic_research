#include "hrp.hpp"
#include <iostream>

int main()
{
    Eigen::MatrixXd cov_matrix(3, 3);
    cov_matrix << 0.005, -0.002, 0.001,
        -0.002, 0.004, -0.001,
        0.001, -0.001, 0.006;
    HRPOptimizer optimizer(cov_matrix);
    Eigen::VectorXd weights = optimizer.optimize();
    std::cout << "Optimal Weights: " << weights.transpose() << std::endl;
    return 0;
}
