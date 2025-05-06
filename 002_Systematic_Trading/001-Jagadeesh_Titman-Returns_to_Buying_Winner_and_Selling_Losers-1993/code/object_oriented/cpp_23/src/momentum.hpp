#pragma once
#include <Eigen/Dense>
#include <vector>

class MomentumStrategy
{
public:
    MomentumStrategy(const Eigen::MatrixXd &returns, int lookback, double top_decile, double bottom_decile);
    std::pair<Eigen::VectorXd, double> compute_portfolio(int t) const;

private:
    Eigen::MatrixXd returns_;
    int lookback_;
    double top_decile_;
    double bottom_decile_;

    std::vector<int> get_winners(int t) const;
    std::vector<int> get_losers(int t) const;
};
