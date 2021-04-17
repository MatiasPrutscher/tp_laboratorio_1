/*
 * Menu.c
 *
 *  Created on: 17 abr. 2021
 *      Author: Maty
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Menu.h"
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


int realizacionDeOperaciones(float x, float y, float* resultadoSuma, float* resultadoResta, float* resultadoDivision, float* resultadoMultiplicacion, int* banderaDecimalX, int* banderaDecimalY, unsigned long long int* resultadoFactorialX, unsigned long long int* resultadoFactorialY)
{
	int todoOk = 0;
	int auxX;
	int auxY;

	auxX = (int)x;
	auxY = (int)y;

	*resultadoSuma = suma(x, y);
	*resultadoResta = resta(x, y);
	*resultadoMultiplicacion = multiplicacion(x,y);
	if(x >= 0 && x - auxX == 0)
	{
		*resultadoFactorialX = factorial((int)x);
		*banderaDecimalX = 1;
	}

	if(y >= 0 && y - auxY == 0)
	{
		*resultadoFactorialY = factorial((int)y);
		*banderaDecimalY = 1;
	}

	if(y!=0)
	{
		*resultadoDivision = division(x,y);
		todoOk=1;
	}

	return todoOk;
}


void muestraDeResultados(float x, float y, float resultadoSuma, float resultadoResta, float resultadoDivision, float resultadoMultiplicacion, int banderaDecimalX, int banderaDecimalY, unsigned long long int resultadoFactorialX, unsigned long long int resultadoFactorialY, int banderaDivision)
{

	printf("\ta) El resultado de %.2f+%.2f es: %.2f\n", x, y, resultadoSuma);
	printf("\tb) El resultado de %.2f-%.2f es: %.2f\n", x, y, resultadoResta);
	if(banderaDivision == 0)//Si la bandera es 0 no se realizo la cuenta ya que el segundo termino es 0
	{
		printf("\tc) No es posible dividir por cero\n");

	}//Fin if(banderaDivisionPorCero == 0)
	else
	{
		printf("\tc) El resultado de %.2f/%.2f es: %.2f\n",x, y, resultadoDivision);

	}//Fin else if(banderaDivisionPorCero == 0)
	printf("\td) El resultado de %.2f*%.2f es: %.2f\n", x, y, resultadoMultiplicacion);
	if(banderaDecimalX != 1)
	{
		printf("\tNo se puede sacar el factorial de %.2f\n", x);
	}
	else
	{
		printf("\te) El factorial de %d es: %I64u\n", (int)x, resultadoFactorialX);
	}
	if(banderaDecimalY != 1)
	{
		printf("\te) No se puede sacar el factorial de %.2f\n", y);
	}
	else
	{
		printf("\te) El factorial de %d es: %I64u\n\n", (int)y, resultadoFactorialY);
	}
	//printf("\te) El factorial de %d es: %I64u y El factorial de %d es: %I64u\n\n", (int)x, resultadoFactorialX, (int)y, resultadoFactorialY);

}

