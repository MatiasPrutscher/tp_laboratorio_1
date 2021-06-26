#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "input.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	FILE* f;
	if(path != NULL && pArrayListEmployee != NULL)
	{
		f = fopen(path, "r");
		if(f == NULL)
		{
			printf("No se pudo abrir el archivo\n");
		}
		else
		{
			if(parser_EmployeeFromText(f, pArrayListEmployee))
			{
				printf("Se realizo la carga del archivo\n");
			}
			else
			{
				printf("No se realizo la carga del archivo\n");
			}
		}
		fclose(f);
	}
    return todoOk;
}

/** \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
		if(path != NULL && pArrayListEmployee != NULL)
		{
			FILE* f = fopen(path, "rb");
			if(f == NULL)
			{
				printf("No se pudo abrir el archivo\n");
			}
			else
			{
				if(parser_EmployeeFromBinary(f, pArrayListEmployee))
				{
					printf("Se realizo la carga del archivo\n");
				}
				else
				{
					printf("No se realizo la carga del archivo\n");
				}
			}
			fclose(f);
		}
	    return todoOk;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* id, char* path)
{
	int todoOk = 0;
	Employee* aux = employee_new();

	if(pArrayListEmployee != NULL)
	{
		if(newEmpleado(aux, id, path, pArrayListEmployee))
		{
			(*id)++;
			todoOk = 1;
		}
		else
		{
			employee_delete(aux);
		}
	}
    return todoOk;
}


/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	int tam = 0;
	Employee* aux = NULL;
	if(pArrayListEmployee != NULL)
	{
		printf(" ___________________________________________________________________________\n");
		printf("|  Id   |\t nombre \t\t| Horas Trabajadas  |    sueldo\t    |\n");
		printf("|_______|_______________________________|___________________|_______________|\n");
		tam = ll_len(pArrayListEmployee);
		for(int i = 0; i < tam ; i++)
		{
			aux = (Employee*) ll_get(pArrayListEmployee, i);
			if(aux != NULL)
			{
				mostrarEmpleado(aux);
				todoOk = 1;
			}
		}
		printf("|_______|_______________________________|___________________|_______________|\n");
	}
    return todoOk;
}

int controller_searchEmployee(LinkedList* pArrayListEmployee, int id, int* index)
{
	int todoOk = 0;
	int auxId = 0;
	int tam = 0;
	Employee* aux = NULL;
	if(pArrayListEmployee != NULL)
	{
		tam = ll_len(pArrayListEmployee);
		for(int i = 0; i < tam; i++)
		{
			aux = ll_get(pArrayListEmployee, i);
			employee_getId(aux, &auxId);
			if(auxId==id)
			{
				*index = i;
				todoOk = 1;
				break;
			}
		}

	}
	return todoOk;
}





/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee, int nextid)
{
	int todoOk = 0;
	int idx;
	int index = 0;
	if(pArrayListEmployee != NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		utn_getInt("Ingrese el id a eliminar (-1 para cancelar): ", "Error, reingrese", -1, nextid, 5, &idx);
		if(idx != -1)
		{
			controller_searchEmployee(pArrayListEmployee, idx, &index);
			if(ll_remove(pArrayListEmployee, index))
			{
				printf("Baja realizada con exito\n");
				todoOk = 1;
			}
		}

	}
	return todoOk;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee, int nextid)
{
	{
		int todoOk = 0;
		int idx;
		int index = 0;
		int opcion = 0;
		char nombre[128];
		int horasTrabajadas;
		int sueldo;
		Employee* aux = NULL;

		if(pArrayListEmployee != NULL)
		{
			controller_ListEmployee(pArrayListEmployee);
			utn_getInt("Ingrese el id a modificar (-1 para cancelar): ", "Error, reingrese", -1, nextid, 5, &idx);
			controller_searchEmployee(pArrayListEmployee, idx, &index);
			aux = (Employee*) ll_get(pArrayListEmployee, index);

			printf("1-Modificar nombre: \n");
			printf("2-Modificar horas trabajadas: \n");
			printf("3-Modificar sueldo: \n");
			printf("4-cancelar: \n");
			utn_getInt("Ingrese una opcion: ", "Error, reingrese", -1, 4, 5, &opcion);
			switch(opcion)
			{
				case 1:
					utn_getString("Ingrese nombre: ", "Error, reingrese", 128, 5, nombre);
					employee_setNombre(aux, nombre);
					break;
				case 2:
					utn_getInt("Ingrese horas trabajadas: ", "Error, reingrese", 0, 500, 5, &horasTrabajadas);
					employee_setHorasTrabajadas(aux, horasTrabajadas);
					break;
				case 3:
					utn_getInt("Ingrese sueldo: ", "Error, reingrese", 0, 50000, 5, &sueldo);
					employee_setSueldo(aux, sueldo);
					break;
			}

		}
		return todoOk;
	}

}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	int opcion = 0;
	if(pArrayListEmployee != NULL)
	{
		printf("criterios de ordenamiento: \n");
		printf("1- Nombre, alfabetico creciente:\n");
		printf("2- Nombre, alfabetico decreciente:\n");
		printf("3- Id creciente:\n");
		printf("4- Id decreciente:\n");
		printf("5- Horas trabajadas creciente:\n");
		printf("6- Horas trabajadas decreciente:\n");
		printf("7- Sueldo creciente:\n");
		printf("8- Sueldo decreciente:\n");
		printf("9- cancelar\n");
		utn_getInt("Ingrese una opcion: ", "Error, reingrese", 1, 9, 5, &opcion);
		switch(opcion)
		{
			case 1:
				ll_sort(pArrayListEmployee, employee_CmpNombre, 1);
				todoOk = 1;
				break;
			case 2:
				ll_sort(pArrayListEmployee, employee_CmpNombre, 0);
				todoOk = 1;
				break;
			case 3:
				ll_sort(pArrayListEmployee, employee_CmpId, 1);
				todoOk = 1;
				break;
			case 4:
				ll_sort(pArrayListEmployee, employee_CmpId, 0);
				todoOk = 1;
				break;
			case 5:
				ll_sort(pArrayListEmployee, employee_CmpHorasTrabajadas, 1);
				todoOk = 1;
				break;
			case 6:
				ll_sort(pArrayListEmployee, employee_CmpHorasTrabajadas, 0);
				todoOk = 1;
				break;
			case 7:
				ll_sort(pArrayListEmployee, employee_CmpSueldo, 1);
				todoOk = 1;
				break;
			case 8:
				ll_sort(pArrayListEmployee, employee_CmpSueldo, 0);
				todoOk = 1;
				break;
		}
	}

	return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	int tam = 0;
	int id = 0;
	char nombre[128];
	int horasTrabajadas = 0;
	int sueldo = 0;

	Employee* aux = NULL;
	FILE* f = NULL;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		f = fopen(path, "w");
		if(f == NULL)
		{
			printf("No se pudo abrir el archivo\n");
		}
		else
		{
			tam = ll_len(pArrayListEmployee);
			fprintf(f,"id,nombre,horasTrabajadas,sueldo\n");
			for(int i = 0; i < tam; i++)
			{
				aux = (Employee*)ll_get(pArrayListEmployee, i);
				if(aux != NULL)
				{
					if((employee_getHorasTrabajadas(aux, &horasTrabajadas) &&
					   employee_getId(aux, &id) &&
					   employee_getNombre(aux, nombre) &&
					   employee_getSueldo(aux, &sueldo)))
					{
						fprintf(f,"%d, %s, %d, %d\n", id, nombre, horasTrabajadas, sueldo);
						todoOk = 1;

					}
				}
			}
			if(todoOk == 1)
			{
				printf("Guardado con exito\n");
			}
		}
		fclose(f);
	}
	return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	int tam = 0;
	Employee* aux = NULL;
	FILE* f = NULL;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		f = fopen(path, "wb");
		if(f == NULL)
		{
			printf("No se pudo abrir el archivo\n");
		}
		else
		{
			tam = ll_len(pArrayListEmployee);
			for(int i = 0; i < tam; i++)
			{
				aux = (Employee*)ll_get(pArrayListEmployee, i);
				if(aux != NULL)
				{
					fwrite(aux, sizeof(Employee), 1, f);
					todoOk = 1;
				}
			}
			if(todoOk == 1)
			{
				printf("Guardado con exito\n");
			}
		}
	}
	return todoOk;
}

int controller_saveAsTextId(char* path , int id)
{
	int todoOk = 0;

	FILE* f = NULL;

	if(path != NULL && id > 0)
	{
		f = fopen(path, "w");
		if(f == NULL)
		{
			printf("No se pudo abrir el archivo\n");
		}
		else
		{
			fprintf(f,"%d\n", id);
			todoOk = 1;
		}
		if(todoOk == 1)
		{
			printf("Id guardado con exito\n");
		}
		fclose(f);
	}
	return todoOk;
}

