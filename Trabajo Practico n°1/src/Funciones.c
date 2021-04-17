/*
 * Funciones.c
 *
 * Prutscher Matias Nicolas
 *
 * 1°A
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Funciones.h"

float suma(float x, float y)
{
	return x + y;
}


float resta(float x, float y)
{
	return x - y;
}


float division(float x, float y)
{
	return x / y;
}


float multiplicacion(float x, float y)
{
	return x * y;
}


unsigned long long int factorial (int x)
{
	double resultado;

	if( x == 0 || x == 1 )
	{
		resultado = 1;
	}
	else
	{
		resultado = x * factorial(x-1);
	}
	return resultado;
}
