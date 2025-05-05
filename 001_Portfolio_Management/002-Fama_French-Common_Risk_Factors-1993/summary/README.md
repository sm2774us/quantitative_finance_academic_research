# Fama & French (1993) - Common Risk Factors in Stock and Bond Returns
[__Citation: Fama, E. F., & French, K. R. (1993). Common Risk Factors in the Returns on Stocks and Bonds. Journal of Financial Economics, 33(1), 3–56.__](../paper/Fama_French_Common_Risk_Factors_1993.pdf)

## Summary:
Fama and French extended the CAPM by introducing a three-factor model, incorporating size (SMB) and value (HML) factors alongside market risk to explain stock returns. This model is widely used in hedge funds for alpha generation and risk attribution in equity long/short strategies.

## Key Takeaways:
- The model is:

$$
R_i - R_f = \beta_i (R_m - R_f) + s_i SMB + h_i HML + \epsilon_i
$$

- SMB captures small-cap outperformance; HML captures value stock outperformance.
- Hedge funds like Point72 use factor models to isolate alpha and hedge systematic risks.

## MathJax Example:
$$
R_i - R_f = \alpha_i + \beta_i (R_m - R_f) + s_i SMB + h_i HML + \epsilon_i
$$

where,
- $R_i$ is the asset return,
- $R_f$ is the risk-free rate, and,
- $\alpha_i$ is the idiosyncratic return (alpha).

## Hedge Fund Relevance:
Essential for systematic equity strategies. Researchers at Millennium might use enhanced factor models (e.g., with momentum or quality factors) to design trading signals.
