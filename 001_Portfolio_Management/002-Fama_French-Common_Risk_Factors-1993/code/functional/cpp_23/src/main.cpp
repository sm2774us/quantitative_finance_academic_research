#include "fama_french_fp.hpp" // Uncomment for FP
#include <iostream>
#include <random>

int main()
{
    std::mt19937 rng(42);
    std::normal_distribution<double> dist(0.0, 0.02);
    Eigen::VectorXd stock_returns(100);
    Eigen::MatrixXd factors(100, 3);
    for (int i = 0; i < 100; ++i)
    {
        stock_returns(i) = dist(rng);
        factors(i, 0) = dist(rng) * 0.5;  // Mkt-RF
        factors(i, 1) = dist(rng) * 0.25; // SMB
        factors(i, 2) = dist(rng) * 0.2;  // HML
    }
    FamaFrenchModel model(stock_returns, factors);
    model.fit();
    auto [alpha, beta_mkt, beta_smb, beta_hml] = fama_french_fp::fit_fama_french(stock_returns, factors);
    std::cout << "Alpha: " << alpha << "\nBeta_Mkt: " << beta_mkt << "\nBeta_SMB: " << beta_smb << "\nBeta_HML: " << beta_hml << std::endl;
    return 0;
}
