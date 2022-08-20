/**********************************
* Fecha : 27/07/2022
* Autor: Emmanuel Mora
* Materia: HPC
* Tema: Introduccion Lenguaje de programacion C++
* TemaAplicacion Calculo del BMI
* *********************************/

#include <iostream>
#include <math.h>

/* Funcion de bienvenida */
void bienvenida(){
	std::string nombre;
	std::cout << "**********************************" << std::endl;
	std::cout << "** Programa para el Calculo BMI **" << std::endl;
	std::cout << "**********************************" << std::endl;
	/* Se requiere el nombre de la persona */
	std::cout << "Ingrese su nombre: ";
	std::cin >> nombre;
	std::cout << "\n**********************************" << std::endl;
	std::cout << "Welcome "<<nombre<< std::endl;
}

/* Funcion para el calculo del BMI */
float calculoBMI(){
	float altura, masa, bmi;
	/* Se requiere la altura en cm */
	std::cout << "Ingrese su altura en cm's: ";
	std::cin >> altura;
	/* Se requiere la masa en kg */
	std::cout << "Ingrese su masa corporal en kg: ";
	std::cin >> masa;
	/* Se calcula el BMI */
	bmi = masa/pow(altura/100, 2);
	return bmi;
}

int main(){
	float bmi;
	bienvenida();
	bmi = calculoBMI();
	std::cout << "Su IMC es de: " << bmi << std::endl;

	/* Clasificacion */
	if (bmi <= 18.4)
		std::cout << "Usted tiene bajo peso" << std::endl;
	else if (bmi <= 29.9)
		std::cout << "Usted tiene peso normal" << std::endl;
	else if (bmi <= 34.9)
		std::cout << "Usted tiene obesidad clase I" << std::endl;
	else if (bmi <= 39.9)
		std::cout << "Usted tiene obesidad clase II" << std::endl;
	else
		std::cout << "Usted tiene obesidad clase III" << std::endl;

	return 0;
}
