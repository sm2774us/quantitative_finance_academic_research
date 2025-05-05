import markowitz;
import <iostream>;

int main()
{
    Eigen::VectorXd returns(3);
    returns << 0.1, 0.12, 0.15;
    Eigen::MatrixXd cov_matrix(3, 3);
    cov_matrix << 0.005, -0.002, 0.001,
        -0.002, 0.004, -0.001,
        0.001, -0.001, 0.006;
    MarkowitzOptimizer optimizer(returns, cov_matrix);
    auto result = optimizer.optimize(0.13);
    if (result)
    {
        auto [weights, risk] = *result;
        std::cout << "Optimal Weights: " << weights.transpose() << std::endl;
        std::cout << "Portfolio Risk: " << risk << std::endl;
    }
    else
    {
        std::cerr << "Optimization failed: " << result.error() << std::endl;
    }
    return 0;
}
