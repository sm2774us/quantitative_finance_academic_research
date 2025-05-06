#include "momentum.hpp"
#include <iostream>
#include <random>

int main()
{
    std::mt19937 rng(42);
    std::normal_distribution<double> dist(0.0, 0.05);
    Eigen::MatrixXd returns(100, 50); // 100 days, 50 assets
    for (int i = 0; i < returns.rows(); ++i)
    {
        for (int j = 0; j < returns.cols(); ++j)
        {
            returns(i, j) = dist(rng);
        }
    }
    MomentumStrategy strategy(returns, 12, 0.1, 0.1);
    auto [weights, portfolio_return] = strategy.compute_portfolio(50);
    std::cout << "Portfolio Weights: " << weights.transpose() << std::endl;
    std::cout << "Portfolio Return: " << portfolio_return << std::endl;
    return 0;
}
