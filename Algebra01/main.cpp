/*
 *
 *
 *
 *
 */

#include <iostream>
#include <vector>
#include <eigen3/Eigen/Dense>

/** Se crean tos de datos personalizados **/
/* Tipo de dato matriz 3x3 flotante */
typedef Eigen::Matrix<float, 3, 3> miMatriz3x3f;

/* Tipo de dato vector 3 flotante */
typedef Eigen::Matrix<float, 3, 1> miVector3f;

/* Tipo de dato matriuz NxN flotante */
typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> miMatrizd;

int main()
{
    // Se declaran las variables de los tpos anteriores
    miMatriz3x3f mA;
    // Aqui puedo instanciar muchos objetos de "miVector3x3f"
    miVector3f vB;
    miMatrizd mDyn(10, 15);

    std::cout << "** Se inicializan las variables anteriores **" << std::endl;
    //mA en ceros
    std::cout<<"mA Ceros"<<std::endl;
    mA = miMatriz3x3f::Zero();
    std::cout << mA << std::endl;

    //mA en Identidad
    std::cout<<"\nmA Identidad"<<std::endl;
    mA = miMatriz3x3f::Identity();
    std::cout << mA << std::endl;

    //mA en Identidad
    std::cout<<"\nvB Random"<<std::endl;
    vB = miVector3f::Random();
    std::cout << vB << std::endl;

    // Se inicializa manualmente mA
    mA << 1,2,3,4,5,6,7,8,9;
    // Se cambia el valor indice (1,1) de mA por 10
    mA(1, 1) = 10;
    std::cout << "\nmA (1,1) = 10 \nMatriz dinamica renombrada\n" <<mA << std::endl;

    std::cout<<"\n** Funcion Map **"<<std::endl;
    // Se crea una data int
    int datosInt[] = {1,2,3,4};

    // Se mapea en un vector filas de enteros (4x1)
    Eigen::Map<Eigen::RowVectorXi> v_map(datosInt, 4);
    std::cout << "\nVector Map" << v_map << std::endl;

    // Se mapea en una matriz una data dada en un vector flotante
    std::vector<float> vdatos = {1,2,3,5,4,3,1,3,4};
    std::cout << vdatos.data() << std::endl;

    // Se mapea en un vector filas de enteros (4x1)
    Eigen::Map<miMatriz3x3f> M_map(vdatos.data());
    std::cout << "\nMatriz Map\n" << M_map << std::endl;

    // Aritmetica
    std::cout << "\n** Aritmetica **\n" << std::endl;
    // Se crean dos matrices 2x2
    Eigen::Matrix2d a;
    a << 1,2,3,4;
    Eigen::Matrix2d b;
    b << 0,1,1,0;
    Eigen::Matrix2d resultado;

    // Se imprimen las matrices
    std::cout << "\nMatriz a:\n" << a << std::endl;
    std::cout << "\nMatriz b:\n" << b << std::endl;

    // Operaciones Element Wise
    std::cout << "\n** Operaciones element wise **"<< std::endl;
    resultado = a.array() + b.array();
    std::cout << "Matriz element wise a+b:\n" << resultado << std::endl;

    resultado = a.array() - b.array();
    std::cout << "Matriz element wise a-b:\n" << resultado << std::endl;

    resultado = a.array() * b.array();
    std::cout << "Matriz element wise a*b:\n" << resultado << std::endl;

    resultado = a.array() / b.array();
    std::cout << "Matriz element wise a/b:\n" << resultado << std::endl;

    // Se requiere que la matriz b sea multiplicada por el escalar 4
    resultado = b.array() *4;
    std::cout << "Matriz element wise b*4:\n" << resultado << std::endl;

    std::cout << "\nMatriz transpuesta"<< std::endl;
    std::cout << "mA^T:\n" << std::endl;
    std::cout << mA.transpose() << std::endl;

    // Se sobrescribe sobre matriz A la transpuesta
    std::cout << "\nMatriz transpuesta (sobrescrita)"<< std::endl;
    mA.transposeInPlace();
    std::cout << mA << std::endl;

    std::cout << "\n** Acceso parcial a las estructuras **"<< std::endl;
    Eigen::MatrixXf matriz_dinamica = Eigen::MatrixXf::Random(4, 4);
    std::cout << "Matriz 4x4 aleatoria\n"<< matriz_dinamica <<std::endl;

    std::cout << "\n** Acceso parcial a las estructuras **"<< std::endl;
    matriz_dinamica = Eigen::MatrixXf::Random(6, 6);
    std::cout << "Matriz 6x6 aleatoria\n"<< matriz_dinamica <<std::endl;

    /* Se requiere extraer o copiar el bloque central de la matriz anterior */
    Eigen::MatrixXf m_bloque;
    m_bloque = matriz_dinamica.block(3,2,3,4);
    std::cout << "Matriz bloque\n"<< m_bloque <<std::endl;

    // Se requiere que el bloque 2x2 inicial de la matriz aleatoria sea cero
    matriz_dinamica.block(0, 0, 2, 2) *= 0;
    std::cout << "\nMatriz bloque\n"<< matriz_dinamica <<std::endl;

    // Se require multiplicar una columna por -4
    matriz_dinamica.row(3).array() += -4;
    std::cout << "\nMatriz bloque\n"<< matriz_dinamica <<std::endl;

    // Se requiere que a la columna 4 se le sume 5
    matriz_dinamica.row(4).array() += -5;
    std::cout << "\nMatriz bloque\n"<< matriz_dinamica <<std::endl;

    // Se requiere que la ultima columna sea dividida entre cero
    matriz_dinamica.col(5).array() /= 0;
    std::cout << "\nUltima columna dividida por cero\n"<< matriz_dinamica <<std::endl;

    /* BROADCASTING (Transmision) */
    /* Se crea una matriz aleatoria de 2x4 */
    Eigen::MatrixXf mat_transmi = Eigen::MatrixXf::Random(2, 4);
    std::cout << "\nMatriz aleatoria 2x4\n" << mat_transmi << std::endl;

    /* Se crea un vector por columnas de 2 */
    Eigen::Vector2f vec_transmi;
    vec_transmi << 100, 100;
    std::cout << "\n\nVector \n" << vec_transmi << std::endl;

    /* Se transmite por columna a cada elemento */
    mat_transmi.colwise() += vec_transmi;
    std::cout << "\nMatriz suma por columnas Broadcasting V \n" << mat_transmi << std::endl;


    /** Operaciones de reduccion **/
    /* Sobre matrices vectores */
    // Se crea una matriz doble  3x3
    Eigen::Matrix3d m_reduction;
    m_reduction << 3,4,5,6,7,8,3,2,1;
    std::cout << "\nOperaciones de reduccion\n" << m_reduction << std::endl;

    // Reduccion sum()
    /* Suma cada elemento de la matriz o el vector */
    std::cout << "\nReduccion suma: " << m_reduction.sum() << std::endl;

    /* Producto de cada elemento de la matriz o el vector */
    std::cout << "\nReduccion producto: " << m_reduction.prod() << std::endl;

    /* Promedia cada elemento de la matriz o el vector */
    std::cout << "\nReduccion promedio: " << m_reduction.mean() << std::endl;

    /* Suma cada elemento de la matriz o el vector */
    std::cout << "\nReduccion minCoeff: " << m_reduction.minCoeff() << std::endl;

    /* Suma cada elemento de la matriz o el vector */
    std::cout << "\nReduccion maxCoeff: " << m_reduction.maxCoeff() << std::endl;

    /* Suma cada elemento de la matriz o el vector */
    std::cout << "\nReduccion trace: " << m_reduction.trace() << std::endl;


    return 0;
}
