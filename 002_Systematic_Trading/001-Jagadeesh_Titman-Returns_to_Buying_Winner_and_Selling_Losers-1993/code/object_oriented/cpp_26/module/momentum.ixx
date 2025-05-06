export module momentum;
import <Eigen/Dense>;
import <vector>;
import <expected>;

export class MomentumStrategy
{
public:
    MomentumStrategy(const Eigen::MatrixXd &returns, int lookback, double top_decile, double bottom_decile);
    std::expected<std::pair<Eigen::VectorXd, double>, std::string> compute_portfolio(int t) const;

private:
    Eigen::MatrixXd returns_;
    int lookback_;
    double top_decile_;
    double bottom_decile_;

    std::vector<int> get_winners(int t) const;
    std::vector<int> get_losers(int t) const;
};
