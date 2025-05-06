export module volatility_sorting;
import <Eigen/Dense>;
import <vector>;
import <expected>;

export class VolatilitySorter
{
public:
    VolatilitySorter(const Eigen::MatrixXd &returns, int n_portfolios);
    std::expected<std::vector<std::vector<int>>, std::string> sort_assets() const;

private:
    Eigen::MatrixXd returns_;
    int n_portfolios_;
    double compute_volatility(int asset) const;
};
