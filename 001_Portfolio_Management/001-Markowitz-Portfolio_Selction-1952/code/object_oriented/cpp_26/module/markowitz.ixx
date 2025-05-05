export module markowitz;
import <Eigen/Dense>;
import <expected>;

export class MarkowitzOptimizer
{
public:
    MarkowitzOptimizer(const Eigen::VectorXd &returns, const Eigen::MatrixXd &cov_matrix);
    std::expected<std::pair<Eigen::VectorXd, double>, std::string> optimize(double target_return) const;

private:
    Eigen::VectorXd returns_;
    Eigen::MatrixXd cov_matrix_;
    int n_assets_;

    double objective(const Eigen::VectorXd &weights) const;
    bool constraint_return(const Eigen::VectorXd &weights, double target_return) const;
    bool constraint_sum(const Eigen::VectorXd &weights) const;
};
