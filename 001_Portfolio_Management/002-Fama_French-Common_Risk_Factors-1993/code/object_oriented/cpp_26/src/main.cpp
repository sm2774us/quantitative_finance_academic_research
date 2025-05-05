import fama_french;
// import fama_french_fp; // Uncomment for FP
import <iostream>;
import <random>;

int main()
{
    std::mt19937 rng(42);
    std::normal_distribution<double> dist(0.0, 0.02);
    Eigen::VectorXd stock_returns(100);
    Eigen::MatrixXd factors(100, 3);
    for (int i = 0; i < 100; ++i)
    {
        stock_returns(i) = dist(rng);
        factors(i, 0) = dist(rng) * 0.5;
        factors(i, 1) = dist(rng) * 0.25;
        factors(i, 2) = dist(rng) * 0.2;
    }
    FamaFrenchModel model(stock_returns, factors);
    if (auto result = model.fit(); !result)
    {
        std::cerr << "Fit failed: " << result.error() << std::endl;
        return 1;
    }
    if (auto coeffs = model.get_coefficients(); coeffs)
    {
        auto [alpha, beta_mkt, beta_smb, beta_hml] = *coeffs;
        model.print_summary();
    }
    // For FP: auto [alpha, beta_mkt, beta_smb, beta_hml] = fama_french_fp::fit_fama_french(stock_returns, factors);
    return 0;
}
