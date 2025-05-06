import momentum;
import <iostream>;
import <random>;

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
    MomentumStrategy strategy(returns, 12, 0.1, 0.1);
    auto result = strategy.compute_portfolio(50);
    if (result)
    {
        auto [weights, portfolio_return] = *result;
        std::cout << "Portfolio Weights: " << weights.transpose() << std::endl;
        std::cout << "Portfolio Return: " << portfolio_return << std::endl;
    }
    else
    {
        std::cerr << "Error: " << result.error() << std::endl;
    }
    return 0;
}
