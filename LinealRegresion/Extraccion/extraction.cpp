#include "extraction.h"
#include <stdlib.h>
#include <vector>
//#include <boost/algorithm/algorithm.hpp>
#include <boost/algorithm/string.hpp>
#include <cmath>

/**
 * Para capturar el fichero de entrada "csv"
 * Se considera crear una funcion que trate un vector
 * de vectores del tipo string. Es decir, cada linea
 * representa un vector de strings, y la matriz completa
 * (fichero csv) representa un vector
 * @brief Extraction::LeerCsv
 */
std::vector<std::vector<std::string>> Extraction::LeerCsv()
{
    /**
    * La idea es almacenar el fichero en un puntero
    * del tipo ifstream (https://cpluplus.com/reference/),
    * es decir, se crea un buffer de la cadena del fichero csv.
    * La variable dataset, ha de armarse cuando se haga el
    * constructor de la clase, para ser recibida por argumentos
    * de entrada de la función
    * */
    std::ifstream archivo(dataset);

}
