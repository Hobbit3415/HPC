#ifndef EXTRACTION_DATA_H
#define EXTRACTION_DATA_H

#include <iostream>
#include <eigen3/Eigen/Dense>
#include <list>
#include <vector>
#include <fstream>

/* Clase Extracción de Datos:
 *  - Leer un fichero csv
 *  - Entrar con argumentos a la clase:
 *          - Lugar del dataset(csv)
 *          - Separador
 *          - Si tiene cabezera o no
 * -Pasar a un vector de vectores del tipo string
 * -Pasar el vector de vector string s Eigen
 * -Promedio
 * -Desviación
 * -Normalización
 * -Métricas*/

class ExtractionData
{
    /*Argumentos de entrada a la clase*/
    std::string dataset; //Ruta del dataset
    std::string delimitador; //Separador  entre datos
    bool header;//Cabecera o no


public:
    //Se crea el constructor con los argumentos de entreda
    //Vector de vectores del tipo string
    ExtractionData(std::string data,
                   std::string separador,
                   bool cabecera):
        dataset(data), delimitador(separador), header(cabecera){}

    //Prototipo de métodos/funciones
    std::vector<std::vector<std::string>> LeerCSV();
    Eigen::MatrixXd CSVtoEigen(std::vector<std::vector<std::string>> dataSet, int filas, int columnas);
    auto Promedio(Eigen::MatrixXd datos) -> decltype(datos.colwise().mean());
    auto DevStand(Eigen::MatrixXd datos) -> decltype(((datos.array().square().colwise().sum())/ (datos.rows()-1)).sqrt());
    Eigen::MatrixXd Norm(Eigen::MatrixXd datos);
    std::tuple<Eigen::MatrixXd,Eigen::MatrixXd,Eigen::MatrixXd,Eigen::MatrixXd> TrainTestSplit(Eigen::MatrixXd datos, float size_train);

    void EigenToFile(Eigen::MatrixXd matriz, std::string file_name);
    void VectorToFile(std::vector<float> vector, std::string file_name);

};

#endif // EXTRACTION_DATA_H
