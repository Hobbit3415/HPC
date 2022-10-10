/*
 * Fecha: 21 sept 2022
 * Autor: Emmanuel Mora Mosquera
 * Materia: HPC
 * Tópico: Implementación de la Regresión Lineal como
 * modelo en C++
 * Requerimientos:
 * - Construir una clase Extraction, que permita
 * manipular, extraer y cargar los datos.
 * - Construir una clase LinearRegression, que permita
 * los calculos de la función de costo, gradiente descendiente
 * entre otras. */


#include "Extraction/extraction_data.h"
#include <eigen3/Eigen/Dense>
#include <boost/algorithm/string.hpp>
#include <list>
#include <vector>
#include <fstream>
#include <iostream>

int main(int argc, char* argv[])
{

    //Se crea un objeto del tipo ClassExtraction
    ExtractionData ExData(argv[1],argv[2],argv[3]);

    //Se crea un vector de vectores del tipo string para cargar objeto ExData
    std::vector<std::vector<std::string>> dataframe = ExData.LeerCSV();

    //Cantidad de filas y columnas
    int filas    = dataframe.size();
    int columnas = dataframe[0].size();

    //Se crea una matriz Eigen, para ingresar los valores a esa matriz
    Eigen::MatrixXd matData = ExData.CSVtoEigen(dataframe, filas, columnas);


    /*Se normaliza la matriz de los datos */
    Eigen::MatrixXd matNorm = ExData.Norm(matData);


    /*Se divide en datos de entrenamiento y datos de prueba*/
    Eigen::MatrixXd X_train, y_train, X_test, y_test;


    std::tuple<Eigen::MatrixXd,Eigen::MatrixXd,Eigen::MatrixXd,Eigen::MatrixXd> div_datos = ExData.TrainTestSplit(matNorm, 0.8);
    /*Se descomprime la tupla en 4 conjuntos */

    std::tie(X_train,y_train,X_test,y_test) = div_datos;

    std::cout<<"Matriz de entrenamiento, número " << X_train.rows() << " de Filas"<<std::endl;
    std::cout<<"Matriz de prueba, número " << X_test.rows() << " de Filas"<<std::endl;
    std::cout<<"Matriz total, número " << matNorm.rows() << " de Filas"<<std::endl;

    return EXIT_SUCCESS;
}
