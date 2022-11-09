#ifndef LINEARREGRESSION_H
#define LINEARREGRESSION_H

#include <eigen3/Eigen/Dense>
#include <iostream>
#include <vector>
#include <cmath>

class LinearRegression
{

public:

    float OLS_cost(Eigen::MatrixXd X, Eigen::MatrixXd y, Eigen::MatrixXd theta);

    std::tuple<Eigen::VectorXd, std::vector<float>> GradientDescent(Eigen::MatrixXd X,
                                                                    Eigen::MatrixXd y,
                                                                    Eigen::VectorXd theta,
                                                                    float alpha,
                                                                    int num_iter);
    float RSquared(Eigen::MatrixXd y, Eigen::MatrixXd y_hat);
};


#endif // LINEARREGRESSION_H
