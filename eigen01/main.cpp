#include <iostream>
// Dense es una biblioteca para trabajar con matrices
#include <eigen3/Eigen/Dense>

int main()
{
    /*Se hace uso de la biblioteca Eigen Dense*/
    /*Se requiere declarar una matriz double 2x2 */
    Eigen::Matrix2d matriz2d;
    /*Se llena la matriz con cualquier núero */
    matriz2d << 2,3,4,0;
    std::cout <<" Se presenta la matriz"<< std::endl;
    std::cout<<matriz2d<< std::endl;
    std::cout << "EL bicho dice siuuuuuuuuuuu" << std::endl;
    std::cout <<" "<<std::endl;
    return 0;
}
