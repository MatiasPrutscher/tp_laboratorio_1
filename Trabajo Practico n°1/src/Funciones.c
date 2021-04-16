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

int menu()
{
	setbuf(stdout, NULL);
	int opcion;
	printf("Alumno: Prutscher Matias \tcurso: 1ro A\n");
	printf("------------------------------------------------------------------------------\n");
	printf(" ####    ##   #       ####  #    # #        ##   #####   ####  #####    ##   \n");
	printf("#    #  #  #  #      #    # #    # #       #  #  #    # #    # #    #  #  #  \n");
	printf("#      #    # #      #      #    # #      #    # #    # #    # #    # #    # \n");
	printf("#      ###### #      #      #    # #      ###### #    # #    # #####  ###### \n");
	printf("#    # #    # #      #    # #    # #      #    # #    # #    # #   #  #    # \n");
	printf(" ####  #    # ######  ####   ####  ###### #    # #####   ####  #    # #    # \n");
	printf("------------------------------------------------------------------------------\n\n");
	printf("1. Ingresar 1er operando (A=x)\n");
	printf("2. Ingresar 2do operando (B=y)\n");;
	printf("3. Calcular todas las operaciones\n");
	printf("\ta) Calcular la suma (A+B)\n");
	printf("\tb) Calcular la resta (A-B)\n");
	printf("\tc) Calcular la division (A/B)\n");
	printf("\td) Calcular la multiplicacion (A*B)\n");
	printf("\te) Calcular el factorial (A!)\n");
	printf("4. Informar resultados\n");
	printf("\ta) 'El resultado de A+B es: r'\n");
	printf("\tb) 'El resultado de A-B es: r'\n");
	printf("\tc) 'El resultado de A/B es: r' o 'No es posible dividir por cero'\n");
	printf("\td) 'El resultado de A*B es: r'\n");
	printf("\te) 'El factorial de A es: r1 y El factorial de B es: r2'\n");
	printf("5. Salir\n");
	printf("ingrese una opcion: ");
	fflush(stdin);
	scanf("%d", &opcion);

	return opcion;

}


float tomaDeDatos(void)
{
	float numero;
	setbuf(stdout, NULL);

	printf("Ingrese el numero a operar: ");
	while(!scanf("%f", &numero))
	{
		system("color 40");//Al haber un error cambia el color de la consola a rojo
		printf("\n\aError, ingrese el numero a operar: ");
		fflush(stdin);

	}
	system("color 0F");//retorna la consola a negro
	return numero;
}


char pedidoDeSalida(void)
{
	char respuesta;

	setbuf(stdout, NULL);
	printf("Realmente desea salir del programa? S/N\n");
	fflush(stdin);
	scanf("%c", &respuesta);
	respuesta = toupper(respuesta);
	while(respuesta != 'S' && respuesta != 'N')
	{
		system("color 40");//Al haber un error cambia el color de la consola a rojo
		printf("\aError, respuestas validas unicamente: S/N\n");//\a emite una señal sonora avisando al usuario que ocurrio un error
		fflush(stdin);
		scanf("%c", &respuesta);
		respuesta = toupper(respuesta);
		system("color 0F");//retorna la consola a negro
	}
	return respuesta;
}


int realizacionDeOperaciones(float x, float y, float* resultadoSuma, float* resultadoResta, float* resultadoDivision, float* resultadoMultiplicacion, unsigned long long int* resultadoFactorialX, unsigned long long int* resultadoFactorialY)
{
	int todoOk = 0;

	*resultadoSuma = suma(x, y);
	*resultadoResta = resta(x, y);
	*resultadoMultiplicacion = multiplicacion(x,y);
	*resultadoFactorialX = factorial(x);
	*resultadoFactorialY = factorial(y);
	if(y!=0)
	{
		*resultadoDivision = division(x,y);
		todoOk=1;
	}

	return todoOk;
}


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
