/*
 * Menu.h
 *
 *  Created on: 17 abr. 2021
 *      Author: Maty
 */

#ifndef MENU_H_
#define MENU_H_

/** \brief Muestra las opciones del menu y retorna la respuesta del mismo
 *
 * \return int retorna la opcion elegida
 *
 */
int menu(void);


/** \brief toma los datos de tipo float y lo devuelve
 *
 * \return float retorna el numero ingresado
 *
 */
float tomaDeDatos(void);


/** \brief valida la opcion de salida del programa
 *
 * \return char devuelve unicamente 'S' para salir o 'N' para continuar con el programa
 *
 */
char pedidoDeSalida(void);


/** \brief Realiza las operaciones y devuelve 1 si se realizaron o 0 si no se realizo la division
 *
 * \param x primer numero a operar
 * \param y segundo numero a operar
 * \param resultadoSuma float* recibe el puntero del resultado de la suma para realizarla y devolver el mismo
 * \param resultadoSuma float* recibe el puntero del resultado de la resta para realizarla y devolver el mismo
 * \param resultadoSuma float* recibe el puntero del resultado de la division para realizarla y devolver el mismo
 * \param resultadoSuma float* recibe el puntero del resultado de la multiplicacion para realizarla y devolver el mismo
 * \param banderaDecimalX int* recibe el puntero a la bandera de si es decimal para el numero A
 * \param banderaDecimalY int* recibe el puntero a la bandera de si es decimal para el numero B
 * \param resultadoFactorialX unsigned long long int* recibe el puntero del resultado del factorial para realizarlo y devolver el mismo
 * \param resultadoFactorialY unsigned long long int* recibe el puntero del resultado del factorial para realizarlo y devolver el mismo
 * \return int retorna 1 si se realizaron todas las operacion, 0 si no se realizo la division
 *
 */
int realizacionDeOperaciones(float x, float y, float* resultadoSuma, float* resultadoResta, float* resultadoDivision, float* resultadoMultiplicacion, int* banderaDecimalX, int* banderaDecimalY, unsigned long long int* resultadoFactorialX, unsigned long long int* resultadoFactorialY);

/** \brief Pide los datos para mostrarlos a traves de printf
 *
 * \param x primer numero a operar
 * \param y segundo numero a operar
 * \param resultadoSuma float* recibe el resultado de la suma para mostrarlo
 * \param resultadoResta float* recibe el resultado de la resta para mostrarlo
 * \param resultadoDivision float* recibe el resultado de la division para mostrarlo
 * \param resultadoMultiplicacion float* recibe el resultado de la multiplicacion para mostrarlo
 * \param banderaDecimalX int* recibe el puntero a la bandera de si es decimal para el numero A
 * \param banderaDecimalY int* recibe el puntero a la bandera de si es decimal para el numero B
 * \param resultadoFactorialX unsigned long long int* recibe el resultado del factorial para mostrarlo
 * \param banderaDivision int muestra si se pudo realizar la division o no
 * \param resultadoFactorialY unsigned long long int* recibe el resultado del factorial para mostrarlo
 * \return void
 *
 */
void muestraDeResultados(float x, float y, float resultadoSuma, float resultadoResta, float resultadoDivision, float resultadoMultiplicacion, int banderaDecimalX, int banderaDecimalY, unsigned long long int resultadoFactorialX, unsigned long long int resultadoFactorialY, int banderaDivision);



#endif /* MENU_H_ */
