# Jegadeesh & Titman (1993) - Returns to Buying Winners and Selling Losers
[__Citation: Jegadeesh, N., & Titman, S. (1993). Returns to Buying Winners and Selling Losers: Implications for Stock Market Efficiency. The Journal of Finance, 48(1), 65–91.__](../paper/Jegadeesh_Titman-Returns_to_Buying_Winners_and_Selling_Losers-1993.pdf)

## Summary:
This paper introduced the momentum anomaly, showing that stocks with strong past performance (winners) outperform those with poor performance (losers) over 3–12 months. It’s a cornerstone of systematic trading strategies in hedge funds.

## Key Takeaways:
- Momentum portfolios are formed by longing top-decile performers and shorting bottom-decile performers.
- Returns are robust across markets but decay after 12 months.
- Behavioral explanations include underreaction and overreaction to news.

## MathJax Example:
Momentum signal for stock $i$:

$$
M_i = \frac{P_t - P_{t-12}}{P_{t-12}}
$$

Portfolio return:

$$
R_p = \frac{1}{N_w} \sum_{i \in \text{winners}} R_i - \frac{1}{N_l} \sum_{i \in \text{losers}} R_i
$$

## Hedge Fund Relevance:
Momentum is a core signal in Citadel’s and Millennium’s systematic equity strategies. Researchers combine it with other factors (e.g., value, quality) to enhance alpha.
