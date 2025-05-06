#include "volatility_sorting_fp.hpp" // Uncomment for FP version
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
    VolatilitySorter sorter(returns, 5);
    auto portfolios = volatility_sorting_fp::sort_assets(returns, 5);
    for (int i = 0; i < portfolios.size(); ++i)
    {
        std::cout << "Portfolio " << i << ": ";
        for (int asset : portfolios[i])
        {
            std::cout << asset << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
