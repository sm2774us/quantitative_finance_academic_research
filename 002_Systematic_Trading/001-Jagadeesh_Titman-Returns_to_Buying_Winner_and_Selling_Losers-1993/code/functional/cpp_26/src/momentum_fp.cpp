#include "momentum_fp.hpp"
#include <algorithm>
#include <numeric>

namespace momentum_fp
{
    std::vector<int> get_winners(const Eigen::MatrixXd &returns, int lookback, int t, double top_decile)
    {
        std::vector<std::pair<double, int>> past_returns;
        for (int i = 0; i < returns.cols(); ++i)
        {
            double ret = 0.0;
            for (int j = t - lookback; j < t; ++j)
            {
                ret += returns(j, i);
            }
            past_returns.emplace_back(ret, i);
        }
        std::sort(past_returns.rbegin(), past_returns.rend());
        int n_winners = static_cast<int>(returns.cols() * top_decile);
        std::vector<int> winners;
        for (int i = 0; i < n_winners; ++i)
        {
            winners.push_back(past_returns[i].second);
        }
        return winners;
    }

    std::vector<int> get_losers(const Eigen::MatrixXd &returns, int lookback, int t, double bottom_decile)
    {
        std::vector<std::pair<double, int>> past_returns;
        for (int i = 0; i < returns.cols(); ++i)
        {
            double ret = 0.0;
            for (int j = t - lookback; j < t; ++j)
            {
                ret += returns(j, i);
            }
            past_returns.emplace_back(ret, i);
        }
        std::sort(past_returns.begin(), past_returns.end());
        int n_losers = static_cast<int>(returns.cols() * bottom_decile);
        std::vector<int> losers;
        for (int i = 0; i < n_losers; ++i)
        {
            losers.push_back(past_returns[i].second);
        }
        return losers;
    }

    std::pair<Eigen::VectorXd, double> compute_portfolio(
        const Eigen::MatrixXd &returns,
        int lookback,
        double top_decile,
        double bottom_decile,
        int t)
    {
        auto winners = get_winners(returns, lookback, t, top_decile);
        auto losers = get_losers(returns, lookback, t, bottom_decile);
        Eigen::VectorXd weights = Eigen::VectorXd::Zero(returns.cols());
        double winner_return = 0.0, loser_return = 0.0;
        for (int i : winners)
        {
            weights(i) = 1.0 / winners.size();
            winner_return += returns(t, i);
        }
        for (int i : losers)
        {
            weights(i) = -1.0 / losers.size();
            loser_return += returns(t, i);
        }
        double portfolio_return = (winner_return / winners.size()) - (loser_return / losers.size());
        return {weights, portfolio_return};
    }
}
