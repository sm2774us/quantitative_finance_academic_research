# Harvey, Liu, & Zhu (2016) - …and the Cross-Section of Expected Returns
[__Citation: Harvey, C. R., Liu, Y., & Zhu, H. (2016). …and the Cross-Section of Expected Returns. Review of Financial Studies, 29(1), 5–68.__](../paper/Harvey_Liu_Zhu-and_the_Cross_Section_of_Expected_Returns-2016.PDF)

## Summary:
This paper addresses the “factor zoo” by cataloging hundreds of cross-sectional return predictors and advocating for rigorous statistical testing to avoid data mining. It’s critical for systematic traders to distinguish robust factors from spurious ones.

## Key Takeaways:
- Many reported anomalies fail multiple-testing adjustments (e.g., Bonferroni correction).
- Robust factors include momentum, value, and low volatility.
- Hedge funds use this framework to validate trading signals.

## MathJax Example:

T-statistic adjustment for multiple testing:

$$
p_{\text{adjusted}} = 1 - (1 - p)^{\text{# tests}}
$$

Factors with $p_{\text{adjusted}} < 0.05$ are considered significant.

## Hedge Fund Relevance:
Citadel’s quant teams apply these statistical rigor principles to filter signals, ensuring only high-confidence factors drive trading strategies.
