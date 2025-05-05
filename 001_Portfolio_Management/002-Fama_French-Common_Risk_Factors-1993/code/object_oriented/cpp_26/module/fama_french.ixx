export module fama_french;
import <Eigen/Dense>;
import <vector>;
import <expected>;
import <tuple>;

export class FamaFrenchModel
{
public:
    FamaFrenchModel(const Eigen::VectorXd &stock_returns, const Eigen::MatrixXd &factors);
    std::expected<void, std::string> fit();
    std::expected<std::tuple<double, double, double, double>, std::string> get_coefficients() const;
    void print_summary() const;

private:
    Eigen::VectorXd stock_returns_;
    Eigen::MatrixXd factors_;
    Eigen::VectorXd coefficients_;
};
