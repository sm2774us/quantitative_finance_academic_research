#include "momentum_fp.hpp"
#include <iostream>
#include <random>

int main()
{
    std::mt19937 rng(42);
    std::normal_distribution<double> dist(0.0, 0.05);
    Eigen::MatrixXd returns(100, 50);
    for (int i = 0; i < returns.rows(); ++i)
    {
        for (int j = 0; j < returns.cols(); ++j)
        {
            returns(i, j) = dist(rng);
        }
    }
    auto [weights, portfolio_return] = momentum_fp::compute_portfolio(returns, 12, 0.1, 0.1, 50);
    std::cout << "Portfolio Weights: " << weights.transpose() << std::endl;
    std::cout << "Portfolio Return: " << portfolio_return << std::endl;
    return 0;
}
