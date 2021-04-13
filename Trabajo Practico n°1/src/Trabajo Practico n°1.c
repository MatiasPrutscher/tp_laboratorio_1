/*
 ============================================================================

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

int main(void) {

	//Declaracion de variables
	float primerOperando;
	float segundoOperando;
	float resultadoSuma;
	float resultadoResta;
	float resultadoDivision;
	float resultadoMultiplicacion;

	unsigned long long int resultadoFactorialA;
	unsigned long long int resultadoFactorialB;

	char confirmacionDeSalida;

	//Declaracion de banderas
	int banderaPrimerOperando;
	int banderaSegundoOperando;
	int banderaCalcularOperaciones;
	int banderaDivisionPorCero;
	int banderaError;

	//inicializacion de variables
	banderaPrimerOperando = 0;
	banderaSegundoOperando = 0;
	banderaCalcularOperaciones = 0;
	banderaDivisionPorCero = 0;
	banderaError = 0;
	confirmacionDeSalida = 'N';

	while(confirmacionDeSalida != 'S')
	{

		switch(menu())
		{

			case 1:
				primerOperando = tomaDeDatos();
				banderaPrimerOperando = 1; //Se ingreso el dato y cambia el estado de la bandera
				break;//Fin case 1

			case 2:
				if(banderaPrimerOperando == 0)//no permite ingresar el segundo numero sin antes haber ingresado el primer numero
				{
					system("color 40");//Al haber un error cambia el color de la consola a rojo
					printf("\n\aError, no se puede ingresar el segundo numero sin haber ingresado el primero\n\n");//\a emite una señal sonora avisando al usuario que ocurrio un error
					banderaError = 1;
				}//Fin if(banderaPrimerOperando == 0)
				else
				{

					segundoOperando = tomaDeDatos();
					banderaSegundoOperando = 1;//Se ingreso el dato y cambia el estado de la bandera

				}//Fin else if(banderaPrimerOperando == 0)
				break;//Fin case 2

			case 3:
				if(banderaPrimerOperando == 0)//no permite realizar las operaciones sin antes haber ingresado el primer numero e informa de dicho problema
				{

					system("color 40");//Al haber un error cambia el color de la consola a rojo
					printf("\n\aError, no se puede realizar las operaciones sin haber ingresado el primer numero a operar\n\n");//\a emite una señal sonora avisando al usuario que ocurrio un error
					banderaError = 1;

				}//Fin if(banderaPrimerOperando == 0)
				else
				{
					if(banderaSegundoOperando == 0)//no permite realizar las operaciones sin antes haber ingresado el segundo numero e informa de dicho problema
					{

						system("color 40");//Al haber un error cambia el color de la consola a rojo
						printf("\n\aError, no se puede realizar las operaciones sin haber ingresado el segundo numero a operar\n\n");//\a emite una señal sonora avisando al usuario que ocurrio un error
						banderaError = 1;

					}//Fin if(banderaSegundoOperando == 0)
					else
					{
						resultadoSuma = suma(primerOperando, segundoOperando);
						resultadoResta = resta(primerOperando, segundoOperando);
						if(segundoOperando != 0)
						{
							resultadoDivision = division(primerOperando, segundoOperando);
							banderaDivisionPorCero = 1;
						}
						resultadoMultiplicacion = multiplicacion(primerOperando, segundoOperando);
						resultadoFactorialA = factorial((int)primerOperando);
						resultadoFactorialB = factorial((int)segundoOperando);

						printf("\nSe realizaron todas las operaciones\n\n");
						banderaCalcularOperaciones = 1;//Se realizan los calculos y cambia el estado de la bandera

					}////Fin else if(banderaSegundoOperando == 0)
				}//Fin else if(banderaPrimerOperando == 0)
				break;//Fin case 3

			case 4:
				if(banderaPrimerOperando == 0)//No permite la muestra de datos sin antes haber ingresado el primer numero e informa dicho problema
				{

					system("color 40");//Al haber un error cambia el color de la consola a rojo
					printf("\n\aError, no se puede mostrar los resultados sin haber ingresado el primer numero a operar\n\n");//\a emite una señal sonora avisando al usuario que ocurrio un error
					banderaError = 1;

				}//Fin if(banderaPrimerOperando == 0)
				else
				{
					if(banderaSegundoOperando == 0)//No permite la muestra de datos sin antes haber ingresado el segundo numero e informa dicho problema
					{

						system("color 40");//Al haber un error cambia el color de la consola a rojo
						printf("\n\aError, no se puede mostrar los resultados sin haber ingresado el segundo numero a operar\n\n");//\a emite una señal sonora avisando al usuario que ocurrio un error
						banderaError = 1;

					}//Fin if(banderaSegundoOperando == 0)
					else
					{
						if(banderaCalcularOperaciones == 0)//No permite la muestra de datos sin haber realizado las operaciones e informa dicho problema
						{

							system("color 40");//Al haber un error cambia el color de la consola a rojo
							printf("\n\aError, no se puede mostrar los resultados sin haber realizado las operaciones previamente\n\n");//\a emite una señal sonora avisando al usuario que ocurrio un error
							banderaError = 1;

						}//Fin if(banderaCalcularOperaciones == 0)
						else
						{

							printf("\ta) El resultado de %.2f+%.2f es: %.2f\n", primerOperando, segundoOperando, resultadoSuma);
							printf("\tb) El resultado de %.2f-%.2f es: %.2f\n", primerOperando, segundoOperando, resultadoResta);
							if(banderaDivisionPorCero == 0)//Si la bandera es 0 no se realizo la cuenta ya que el segundo termino es 0
							{

								printf("\tc) No es posible dividir por cero\n");

							}//Fin if(banderaDivisionPorCero == 0)
							else
							{

								printf("\tc) El resultado de %.2f/%.2f es: %.2f\n",primerOperando, segundoOperando, resultadoDivision);

							}//Fin else if(banderaDivisionPorCero == 0)
							printf("\td) El resultado de %.2f*%.2f es: %.2f\n", primerOperando, segundoOperando, resultadoMultiplicacion);
							printf("\te) El factorial de %d es: %I64u y El factorial de %d es: %I64u\n\n", (int)primerOperando, resultadoFactorialA, (int)segundoOperando, resultadoFactorialB);
							banderaPrimerOperando = 0; 		// vuelta a 0 de las banderas iniciales
							banderaSegundoOperando = 0;	 	// vuelta a 0 de las banderas iniciales
							banderaCalcularOperaciones = 0; // vuelta a 0 de las banderas iniciales

						}//Fin else if(banderaCalcularOperaciones == 0)
					}////Fin else if(banderaSegundoOperando == 0)
				}////Fin else if(banderaPrimerOperando == 0)
				break;//Fin case 4

			case 5:
				confirmacionDeSalida = pedidoDeSalida();
				break;//Fin case 5

			default:
				system("color 40");//Al haber un error cambia el color de la consola a rojo
				printf("\n\aError, ingrese una opcion valida\n\n");//\a emite una señal sonora avisando al usuario que ocurrio un error
				banderaError = 1;
				break;//Fin default

		}//Fin switch(menu())
		system("pause");
		system("cls");//Limpia la consola

		if(banderaError == 1)//retorna la consola a negro en el caso de que hay habido un error
		{

			system("color 0F");

		}//Fin if(banderaError == 1)
	}//Fin while(confirmacionDeSalida != 'S')

	return EXIT_SUCCESS;

}//Fin int main(void)
