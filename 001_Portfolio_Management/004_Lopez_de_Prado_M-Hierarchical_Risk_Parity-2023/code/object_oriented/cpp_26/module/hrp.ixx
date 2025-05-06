export module hrp;
import <Eigen/Dense>;
import <expected>;

export class HRPOptimizer
{
public:
    HRPOptimizer(const Eigen::MatrixXd &cov_matrix);
    std::expected<Eigen::VectorXd, std::string> optimize() const;

private:
    Eigen::MatrixXd cov_matrix_;
    int n_assets_;
};
