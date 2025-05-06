#include "momentum.hpp"
#include <algorithm>
#include <numeric>

MomentumStrategy::MomentumStrategy(const Eigen::MatrixXd &returns, int lookback, double top_decile, double bottom_decile)
    : returns_(returns), lookback_(lookback), top_decile_(top_decile), bottom_decile_(bottom_decile) {}

std::vector<int> MomentumStrategy::get_winners(int t) const
{
    std::vector<std::pair<double, int>> past_returns;
    for (int i = 0; i < returns_.cols(); ++i)
    {
        double ret = 0.0;
        for (int j = t - lookback_; j < t; ++j)
        {
            ret += returns_(j, i);
        }
        past_returns.emplace_back(ret, i);
    }
    std::sort(past_returns.rbegin(), past_returns.rend());
    int n_winners = static_cast<int>(returns_.cols() * top_decile_);
    std::vector<int> winners;
    for (int i = 0; i < n_winners; ++i)
    {
        winners.push_back(past_returns[i].second);
    }
    return winners;
}

std::vector<int> MomentumStrategy::get_losers(int t) const
{
    std::vector<std::pair<double, int>> past_returns;
    for (int i = 0; i < returns_.cols(); ++i)
    {
        double ret = 0.0;
        for (int j = t - lookback_; j < t; ++j)
        {
            ret += returns_(j, i);
        }
        past_returns.emplace_back(ret, i);
    }
    std::sort(past_returns.begin(), past_returns.end());
    int n_losers = static_cast<int>(returns_.cols() * bottom_decile_);
    std::vector<int> losers;
    for (int i = 0; i < n_losers; ++i)
    {
        losers.push_back(past_returns[i].second);
    }
    return losers;
}

std::pair<Eigen::VectorXd, double> MomentumStrategy::compute_portfolio(int t) const
{
    auto winners = get_winners(t);
    auto losers = get_losers(t);
    Eigen::VectorXd weights = Eigen::VectorXd::Zero(returns_.cols());
    double winner_return = 0.0, loser_return = 0.0;
    for (int i : winners)
    {
        weights(i) = 1.0 / winners.size();
        winner_return += returns_(t, i);
    }
    for (int i : losers)
    {
        weights(i) = -1.0 / losers.size();
        loser_return += returns_(t, i);
    }
    double portfolio_return = (winner_return / winners.size()) - (loser_return / losers.size());
    return {weights, portfolio_return};
}
