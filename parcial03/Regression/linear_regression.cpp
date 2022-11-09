#include "linear_regression.h"
#include <eigen3/Eigen/Dense>
#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>

/* Primera funcion:
 * Funcion de coste para la regresion lineal
 * basada en la funcion de minimos cuadrados ordinarios
 */
float LinearRegression::OLS_cost(Eigen::MatrixXd X, Eigen::MatrixXd y, Eigen::MatrixXd theta){
    Eigen::MatrixXd diferencia = pow((X*theta -y).array(), 2);
    return (diferencia.sum()/(2*X.rows()));
}

/**
 * Funcion de gradiente descendiente:
 * En función de un ratio de aprendizaje se avanza hasta encontrar el
 * punto minimo que representa el valor optimo para la funcion
 */
std::tuple<Eigen::VectorXd, std::vector<float>> LinearRegression::GradientDescent(Eigen::MatrixXd X,
                                                                                  Eigen::MatrixXd y,
                                                                                  Eigen::VectorXd theta,
                                                                                  float alpha,
                                                                                  int num_iter){
    Eigen::MatrixXd temporal = theta;
    int parametros = theta.rows();
    std::vector<float> costo;
    // En costo ingresaremos los valores de la funcion de costo
    costo.push_back(OLS_cost(X, y, theta));
    /**
     * Se itera segun el numero de iteraciones y el ratio de aprendizaje
     * para encontrar los valores optimos
     * */
    for (int i = 0; i < num_iter; ++i) {
        Eigen::MatrixXd error = X*theta-y;
        for (int j = 0; j < parametros; ++j) {
            Eigen::MatrixXd X_i = X.col(j);
            Eigen::MatrixXd termino = error.cwiseProduct(X_i);
            temporal(j, 0) = theta(j, 0) - (alpha/X.rows())*termino.sum();
        }
        theta = temporal;
        costo.push_back(OLS_cost(X, y, theta));
    }
    return std::make_tuple(theta, costo);
}

/*
 * Como metrica de evaluacion se tiene el R2, que representa
 * una medida de que tan bueno es nuestro modelo
*/
float LinearRegression::RSquared(Eigen::MatrixXd y, Eigen::MatrixXd y_hat){
    auto numerador = pow((y-y_hat).array(), 2).sum();
    auto denominador = pow(y.array()-y.mean(),2).sum();

    return 1-numerador/denominador;
}











