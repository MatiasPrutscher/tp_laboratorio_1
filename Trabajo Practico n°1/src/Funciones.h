/*
 * Funciones.h
 *
 * Prutscher Matias Nicolas
 *
 * 1°A
 *
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

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
 * \param resultadoFactorialX unsigned long long int* recibe el puntero del resultado del factorial para realizarlo y devolver el mismo
 * \param resultadoFactorialY unsigned long long int* recibe el puntero del resultado del factorial para realizarlo y devolver el mismo
 * \return int retorna 1 si se realizaron todas las operacion, 0 si no se realizo la division
 *
 */
int realizacionDeOperaciones(float x, float y, float* resultadoSuma, float* resultadoResta, float* resultadoDivision, float* resultadoMultiplicacion, unsigned long long int* resultadoFactorialX, unsigned long long int* resultadoFactorialY);

/** \brief Pide los datos para mostrarlos a traves de printf
 *
 * \param x primer numero a operar
 * \param y segundo numero a operar
 * \param resultadoSuma float* recibe el resultado de la suma para mostrarlo
 * \param resultadoSuma float* recibe el resultado de la resta para mostrarlo
 * \param resultadoSuma float* recibe el resultado de la division para mostrarlo
 * \param resultadoSuma float* recibe el resultado de la multiplicacion para mostrarlo
 * \param resultadoFactorialX unsigned long long int* recibe el resultado del factorial para mostrarlo
 * \param banderaDivision int muestra si se pudo realizar la division o no
 * \param resultadoFactorialY unsigned long long int* recibe el resultado del factorial para mostrarlo
 * \return void
 *
 */
void muestraDeResultados(float x, float y, float resultadoSuma, float resultadoResta, float resultadoDivision, float resultadoMultiplicacion, unsigned long long int resultadoFactorialX, unsigned long long int resultadoFactorialY, int banderaDivision);



/** \brief recibe dos numeros, los suma y devuelve la suma de los mismos
 *
 * \param x float primer numero a sumar
 * \param y float segundo numero a sumar
 * \return float devuelve el resultado de la suma
 *
 */
float suma(float x, float y);


/** \brief recibe dos numeros, los suma y devuelve la resta de los mismos
 *
 * \param x float primer numero a restar
 * \param y float segundo numero a restar
 * \return float devuelve el resultado de la resta
 *
 */
float resta(float x, float y);


/** \brief recibe dos numeros, los divide y devuelve la division de los mismos
 *
 * \param x float primer numero a dividir
 * \param y float segundo numero a dividir
 * \return float devuelve el resultado de la division
 *
 */
float division(float x, float y);


/** \brief recibe dos numeros, los multiplica y devuelve la multiplicacion de los mismos
 *
 * \param x float primer numero a multiplicar
 * \param y float segundo numero a multiplicar
 * \return float devuelve el resultado de la multiplicacion
 *
 */
float multiplicacion(float x, float y);


/** \brief recibe un numero, realiza la factorizacion de manera recursiva y devuelve el resultado
 *
 * \param x float numero a factorizar
 * \return double devuelve el resultado de la factorizacion
 *
 */
unsigned long long int factorial (int x);


#endif /* FUNCIONES_H_ */
