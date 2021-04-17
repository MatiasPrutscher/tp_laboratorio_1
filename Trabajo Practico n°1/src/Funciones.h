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
