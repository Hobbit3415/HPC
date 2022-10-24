#include <iostream>
#include <vector>
#include <eigen3/Eigen/Dense>

typedef Eigen::Matrix<float, 3, 3> matriz3x3f;
typedef Eigen::Matrix<float, 2, 2> matriz2x2f;
typedef Eigen::Matrix<float, 2, 3> matriz2x3f;
typedef Eigen::Matrix<float, 3, 2> matriz3x2f;

/**
 * @brief Metodo que recibe cuatro numeros de coma flotante
 * y retorna una matriz Eigen 2x2
 * @return Una matriz Eigen 2x2
 */
Eigen::Matrix2d inicializar_2d(double a, double b, double c, double d){
    Eigen::Matrix2d matriz;
    matriz<< a,b,c,d;
    return matriz;
}

void punto_a(){
    std::cout << "A: X = 3A-4B"<< std::endl;
    // Se crean dos matrices 2x2
    Eigen::Matrix2d a = inicializar_2d(4, -2, 1, -7);
    Eigen::Matrix2d b = inicializar_2d(-1, 2, 6, -5);

    Eigen::Matrix2d x;

    x = 3*a - 4*b;

    // Se imprimen las matrices
    std::cout << "\nMatriz a:\n" << a << std::endl;
    std::cout << "\nMatriz b:\n" << b << std::endl;

    std::cout << "\nX =\n" << x << std::endl;
}

void punto_b(){
    std::cout << "B: X = (3BA - 4A)/2"<< std::endl;
    // Se crean dos matrices 2x2
    Eigen::Matrix2d a = inicializar_2d(0, -1, 2, 1);
    Eigen::Matrix2d b = inicializar_2d(1, 2, 3, 4);

    Eigen::Matrix2d x;

    x = (3*b*a - 4*a)/2;

    // Se imprimen las matrices
    std::cout << "\nMatriz a:\n" << a << std::endl;
    std::cout << "\nMatriz b:\n" << b << std::endl;

    std::cout << "\nX =\n" << x << std::endl;
}

void punto_c(){
    std::cout << "C: X = C/(AB^t)"<< std::endl;
    // Se crean dos matrices 2x2
    Eigen::Matrix2d a = inicializar_2d(-3, -2, 3, 3);
    Eigen::Matrix2d b = inicializar_2d(5, 9, 3, 4);
    Eigen::Matrix2d c = inicializar_2d(1, 1, 0, 0);

    Eigen::Matrix2d x;

    x = c*(a*b.transpose()).inverse();

    // Se imprimen las matrices
    std::cout << "\nMatriz a:\n" << a << std::endl;
    std::cout << "\nMatriz b:\n" << b << std::endl;
    std::cout << "\nMatriz c:\n" << c << std::endl;

    std::cout << "\nX =\n" << x << std::endl;
}

void punto_d(){
    std::cout << "D: X = B/A"<< std::endl;
    // Se crean dos matrices 2x2
    Eigen::Matrix2d a = inicializar_2d(2, 1,  -4, -3);
    Eigen::Matrix2d b = inicializar_2d(2, 2, 6, 4);

    Eigen::Matrix2d x;

    x = b * a.inverse();

    // Se imprimen las matrices
    std::cout << "\nMatriz a:\n" << a << std::endl;
    std::cout << "\nMatriz b:\n" << b << std::endl;

    std::cout << "\nX =\n" << x << std::endl;
}

void punto_f(){
    std::cout << "F: X = A+3B"<< std::endl;
    // Se crean dos matrices 2x2
    matriz3x3f a;
    matriz3x3f b;
    a <<    1, 5, -1,\
            -1, 2, 2,\
            0, -3, 3;

    b <<    -1, -4, 3,\
            1, -2, -2,\
            -3, 3, -5;


    matriz3x3f x;

    x = a + 3*b;

    // Se imprimen las matrices
    std::cout << "\nMatriz a:\n" << a << std::endl;
    std::cout << "\nMatriz b:\n" << b << std::endl;

    std::cout << "\nX =\n" << x << std::endl;
}

void punto_g(){
    std::cout << "G: X = B/A"<< std::endl;
    // Se crean dos matrices 2x2
    matriz3x3f a;
    matriz3x3f b;
    a <<    2, 7, 3,\
            3, 9, 4,\
            1, 5, 3;

    b <<    1, 0, 2,\
            0, 1, 0,\
            0, 0, 1;

    matriz3x3f x;

    x = b * a.inverse();

    // Se imprimen las matrices
    std::cout << "\nMatriz a:\n" << a << std::endl;
    std::cout << "\nMatriz b:\n" << b << std::endl;

    std::cout << "\nX =\n" << x << std::endl;
}

void punto_h(){
    std::cout << "H: X = B/A"<< std::endl;
    // Se crean dos matrices 2x2
    matriz3x3f a;
    matriz3x3f b;
    a <<    1, 1, 1,\
            6, 5, 4,\
            13, 10, 8;

    b <<    0, 1, 2,\
            1, 0, 2,\
            1, 2, 0;

    matriz3x3f x;

    x = b * a.inverse();

    // Se imprimen las matrices
    std::cout << "\nMatriz a:\n" << a << std::endl;
    std::cout << "\nMatriz b:\n" << b << std::endl;

    std::cout << "\nX =\n" << x << std::endl;
}

void punto_i(){
    std::cout << "I: X = A^t*A-2A"<< std::endl;
    // Se crean dos matrices 2x2
    matriz2x2f a;
    a <<    3, -1,\
            0, 2;

    matriz2x2f x;

    x = a.transpose() * a - (2*a);

    // Se imprimen las matrices
    std::cout << "\nMatriz a:\n" << a << std::endl;

    std::cout << "\nX =\n" << x << std::endl;
}

void punto_j(){
    std::cout << "J: X = A^3"<< std::endl;
    // Se crean dos matrices 2x2
    matriz2x2f a;
    a <<   4, 2,\
            -1, 0;

    matriz2x2f x;

    x = a*a*a;

    // Se imprimen las matrices
    std::cout << "\nMatriz a:\n" << a << std::endl;

    std::cout << "\nX =\n" << x << std::endl;
}

void punto_k(){
    std::cout << "K: X = C/(A^t * B)"<< std::endl;
    // Se crean dos matrices 2x2
    matriz2x2f a;
    matriz2x2f b;
    matriz2x2f c;

    a <<   2, 4,\
            3, 2;

    b <<   1, 0,\
           2, 1;

    c <<   7, 5,\
           6, 1;

    matriz2x2f x;

    x = c * (((a.transpose())*b).inverse());

    // Se imprimen las matrices
    std::cout << "\nMatriz a:\n" << a << std::endl;
    std::cout << "\nMatriz b:\n" << b << std::endl;
    std::cout << "\nMatriz c:\n" << c << std::endl;

    std::cout << "\nX =\n" << x << std::endl;
}

void punto_l(){
    std::cout << "L: X = AA^t - 2AB"<< std::endl;
        // Se crean dos matrices 2x2
        matriz2x3f a;
        matriz3x2f b;
        a <<    1, 0, -2,\
                2, -1, 3;

        b <<    2, -3,\
                -2, 0,\
                -1, -2;

        matriz3x3f x;

        x = a*a.transpose();

        // Se imprimen las matrices
        std::cout << "\nMatriz a:\n" << a << std::endl;
        std::cout << "\nMatriz b:\n" << b << std::endl;

        std::cout << "\nX =\n" << x << std::endl;
}

int main()
{
    punto_l();
    return 0;
}
