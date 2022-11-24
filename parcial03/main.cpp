/*
 * Fecha: 21 noviembre de 2022
 * Autor: Emmanuel Mora Mosquera
 * Materia: HPC
 * Tópico: Parcial 03
 * Requerimientos:
 * - Realizar un análiss de datos sobre el dataset seleccionado
 * - Modelar el dataset mediante una regresión lineal en C++
 * - Modelar el dataset mediante una regresión lineal en Python
 * - Comparar los dos modelos creados
 */

#include "Extraction/extraction_data.h"
#include "Regression/linear_regression.h"
#include <eigen3/Eigen/Dense>
#include <boost/algorithm/string.hpp>
#include <list>
#include <vector>
#include <fstream>
#include <iostream>

int main(int argc, char* argv[])
{

    //Se crea un objeto del tipo ClassExtraction
    ExtractionData Obj_extraccion(argv[1],argv[2],argv[3]);
    std::cout<<"########################"<<std::endl;
    std::cout<<"Fichero entrada: "<< argv[1] << std::endl;

    //Se crea un vector de vectores del tipo string para cargar objeto ExData
    std::vector<std::vector<std::string>> lec_datos = Obj_extraccion.LeerCSV();

    int filas = lec_datos.size();
    int columnas = lec_datos[0].size();

//    std::cout<< lec_datos <<std::endl;

    std::cout<<"Num_filas: "<<filas <<std::endl;
    std::cout<<"Num_columnas: "<<columnas <<std::endl;
    std::cout<<"########################"<<std::endl;

    Eigen::MatrixXd matData = Obj_extraccion.CSVtoEigen(lec_datos, filas, columnas);

//    std::cout<<"-mat data: "<< std::endl;
//    std::cout<< matData << std::endl;
//    std::cout<<"Suma por columnas "<<std::endl;
//    std::cout<<Obj_extraccion.Sumatoria(matData)<<std::endl;

    std::cout<<"Promedios por columnas "<<std::endl;
    std::cout<<Obj_extraccion.Promedio(matData)<<std::endl;
    std::cout<<"########################"<<std::endl;
    std::cout<<"Desviaciones STD por columnas"<<std::endl;
    std::cout<<Obj_extraccion.DevStand(matData)<<std::endl;

    std::cout<<"Primera fila: "<<std::endl;
    std::cout<< matData(0) <<std::endl;

    Eigen::MatrixXd normData = Obj_extraccion.Norm(matData);

    /* Train test split */
    Eigen::MatrixXd X_train, y_train, X_test, y_test;
    std::tuple<Eigen::MatrixXd,
               Eigen::MatrixXd,
               Eigen::MatrixXd,
               Eigen::MatrixXd> tupla_datos = Obj_extraccion.TrainTestSplit(normData, 0.8);
    std::tie(X_train, y_train, X_test, y_test) = tupla_datos;
    /* Inspeccion visual de division conjunto de datos */
    std::cout<<"Train: "<<std::endl;
    std::cout<< X_train.cols() <<std::endl;
    std::cout<< X_train.rows() <<std::endl;
    std::cout<< y_train.cols() <<std::endl;
    std::cout<< y_train.rows() <<std::endl;
    std::cout<< "Test: " <<std::endl;
    std::cout<< X_test.cols() <<std::endl;
    std::cout<< X_test.rows() <<std::endl;
    std::cout<< y_test.cols() <<std::endl;
    std::cout<< y_test.rows() <<std::endl;
    std::cout<< "###########################" <<std::endl;


    LinearRegression modelo_lr;
    Eigen::MatrixXd vector_train = Eigen::VectorXd::Ones(X_train.rows());
    Eigen::MatrixXd vector_test = Eigen::VectorXd::Ones(X_test.rows());

    /* Train: Se redimensiona la columna adicional */
    X_train.conservativeResize(X_train.rows(), X_train.cols()+1);
    /* Train: se agrega a la nueva columna el vector de ceros */
    X_train.col(X_train.cols()-1) = vector_train;
    /* Test: Se redimensiona la columna adicional */
    X_test.conservativeResize(X_test.rows(), X_test.cols()+1);
    /* Test: se agrega a la nueva columna el vector de ceros */
    X_test.col(X_test.cols()-1) = vector_test;

    /* Parametros */
    Eigen::VectorXd thetas = Eigen::VectorXd::Zero(X_train.cols());
    float learning_rate = 0.01;
    int num_iter = 1000;
    Eigen::VectorXd thetas_salida;
    std::vector<float> costo;

    /* Optimizacion de parametros */
    std::tuple<Eigen::VectorXd, std::vector<float>> gradiente = modelo_lr.GradientDescent(X_train,
                                                                                          y_train,
                                                                                          thetas,
                                                                                          learning_rate,
                                                                                          num_iter);
    std::tie(thetas_salida, costo) = gradiente;

//    /*Exportar costo a file*/
//    Obj_extraccion.VectorToFile(costo, "/home/hobbit/Documents/HPC/LinearRegression/costo.txt");

    /*
     * Calculo de promedio/desviacion para y_hat
     * Adicional, se denormalizan los datos para calcular la
     * metrica R2_score
    */
    auto prom_data = Obj_extraccion.Promedio(matData);
    auto prom_independientes = prom_data(0, 13);

    auto escalado = matData.rowwise()-matData.colwise().mean();
    auto desv_data = Obj_extraccion.DevStand(escalado);
    auto desv_independientes = desv_data(0, 13);

//    /**
//     * Calculo de valores estimados (predicciones( y_hat
//     * Se denormaliza y
//     * y = mX+b
//     */
    Eigen::MatrixXd y_train_hat = (X_train*thetas_salida * desv_independientes).array()+prom_independientes;
    Eigen::MatrixXd y_train_real = matData.col(0).topRows(15067);

    Eigen::MatrixXd y_test_hat = (X_test*thetas_salida * desv_independientes).array()+prom_independientes;
    Eigen::MatrixXd y_test_real = matData.col(0).bottomRows(3767);

    float r2_score_train = modelo_lr.RSquared(y_train_real, y_train_hat);

    float r2_score_test = modelo_lr.RSquared(y_test_real, y_test_hat);

    std::cout<< "######################" <<std::endl;
    std::cout<< "Metrica R2 Conjunto entrenamiento: "<< r2_score_train <<std::endl;

    std::cout<< "######################" <<std::endl;
    std::cout<< "Metrica R2 Conjunto pruebas: "<< r2_score_test <<std::endl;

    return EXIT_SUCCESS;
}
