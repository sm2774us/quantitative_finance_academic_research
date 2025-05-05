#pragma once
#include <Eigen/Dense>
#include <vector>

class FamaFrenchModel
{
public:
    FamaFrenchModel(const Eigen::VectorXd &stock_returns, const Eigen::MatrixXd &factors);
    void fit();
    std::tuple<double, double, double, double> get_coefficients() const;
    void print_summary() const;

private:
    Eigen::VectorXd stock_returns_;
    Eigen::MatrixXd factors_;      // Columns: Mkt-RF, SMB, HML
    Eigen::VectorXd coefficients_; // [alpha, beta_mkt, beta_smb, beta_hml]
};
