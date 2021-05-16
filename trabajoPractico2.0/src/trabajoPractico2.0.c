/*
 ============================================================================
 Name        : trabajoPractico2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description :
 Enunciado
Una empresa requiere un sistema para administrar su n�mina de empleados. Se sabe que
dicha n�mina bajo ninguna circunstancia superara los 1000 empleados.
Datos:
El sistema deber� tener el siguiente men� de opciones:
1. ALTAS: Se debe permitir ingresar un empleado calculando autom�ticamente el n�mero
de Id. El resto de los campos se le pedir� al usuario.
2. MODIFICAR: Se ingresar� el N�mero de Id, permitiendo modificar: o Nombre o Apellido
o Salario o Sector
3. BAJA: Se ingresar� el N�mero de Id y se eliminar� el empleado del sistema.
4. INFORMAR:
1. Listado de los empleados ordenados alfab�ticamente por Apellido y Sector.
2. Total y promedio de los salarios, y cu�ntos empleados superan el salario promedio.
NOTA: Se deber� realizar el men� de opciones y las validaciones a trav�s de funciones.
Tener en cuenta que no se podr� ingresar a los casos 2, 3 y 4; sin antes haber realizado la
carga de alg�n empleado.
Para la realizaci�n de este programa, se utilizar� una biblioteca llamada �ArrayEmployees� que
facilitar� el manejo de la lista de empleados y su modificaci�n. En la secci�n siguiente se
detallan las funciones que esta biblioteca debe tener.
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "ArrayEmployees.h"

#define TAM 1000

int main(void) {
	int flagAdd = 1;
	char exit;
	Employee employees[TAM];
	Employee auxEmp;
	int id = 1;
	int idS;
	int index;
	int order;

	initEmployees(employees, TAM);
	exit = 'N';

	setbuf(stdout, NULL);
	do
	{
		switch(menu())
		{
			 case 1:
				createEmployee(&auxEmp, &id);
				if(!(addEmployee(employees, TAM, auxEmp.id, auxEmp.name, auxEmp.lastName, auxEmp.salary, auxEmp.sector)))
				{
					printf("Successful registration!!\n");
				}
				else
				{
					printf("There was a problem registering the employee\n");
				}
				flagAdd = 1;
				break;

			case 2:
				if(flagAdd == 0)
				{
					printf("To look for a employee you must first have employees");
				}
				else
				{
					utn_getInt("Enter the id of the employee: ", "Error, enter a number from 1 to 1000 ", 1, 1000, 5, &idS);
					index = findEmployeeById(employees, TAM, idS);
					if(index == -1)
					{
						printf("There is no employee with that id number\n");
					}
					else
					{
						printEmployee(employees[index]);
					}
				}
				break;

			case 3:
				if(flagAdd == 0)
				{
					printf("To delete a employee you must first have employees");
				}
				else
				{
					printf("\n3- Delete employee: ");
					utn_getInt("Enter the id of the employee: ", "Error, enter a number from 1 to 1000 ", 1, 1000, 5, &idS);
					removeEmployee(employees, TAM, idS);
				}
				break;

			case 4:
				if(flagAdd == 0)
				{
					printf("There is no employee to show");
				}
				else
				{
					switch(subMenu())
					{
						case 1:
							utn_getInt("Enter 1 if you want an increasing or 0 for decreasing order: ", "Error, enter 1 or 0 ", 0, 1, 5, &order);
							sortEmployees(employees, TAM, order);
							if(printEmployees(employees, TAM) == -1)
							{
								printf("\nError, there is no employee\n");
							}
							break;
						case 2:
							CalculateSalary(employees, TAM);
							break;
					}
				}
				break;

			case 5:
				utn_getString("exit confirm? Y/N ","Error, re-enter an option. Y for 'yes' or N for 'NO' : ", 4, 3, &exit);
				exit = toupper(exit);
				confirmExit(&exit);
				break;
			default:
				printf("Error, re-enter a valid option\n");
				break;
		}
		system("pause");
		system("cls");
	}while(exit == 'N');

	return EXIT_SUCCESS;
}
