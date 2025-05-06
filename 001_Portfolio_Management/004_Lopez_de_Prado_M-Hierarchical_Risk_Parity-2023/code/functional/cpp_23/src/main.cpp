#include "hrp_fp.hpp" // Uncomment for FP
#include <iostream>

int main()
{
    Eigen::MatrixXd cov_matrix(3, 3);
    cov_matrix << 0.005, -0.002, 0.001,
        -0.002, 0.004, -0.001,
        0.001, -0.001, 0.006;
    Eigen::VectorXd weights = hrp_fp::optimize(cov_matrix);
    std::cout << "Optimal Weights: " << weights.transpose() << std::endl;
    return 0;
}
