import hrp;
import <iostream>;

int main()
{
    Eigen::MatrixXd cov_matrix(3, 3);
    cov_matrix << 0.005, -0.002, 0.001,
        -0.002, 0.004, -0.001,
        0.001, -0.001, 0.006;
    HRPOptimizer optimizer(cov_matrix);
    if (auto weights = optimizer.optimize(); weights)
    {
        std::cout << "Optimal Weights: " << weights->transpose() << std::endl;
    }
    else
    {
        std::cerr << "Error: " << weights.error() << std::endl;
    }
    return 0;
}
