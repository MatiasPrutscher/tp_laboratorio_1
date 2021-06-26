#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Employee.h"
#include "input.h"

Employee* employee_new()
{
	Employee* newEmployee = (Employee*) malloc(sizeof(Employee));
	if(newEmployee != NULL)
	{
		employee_setHorasTrabajadas(newEmployee, 0);
		employee_setId(newEmployee, 0);
		employee_setNombre(newEmployee, " ");
		employee_setSueldo(newEmployee, 0);
	}
	return newEmployee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* newEmployee = NULL;
	if(idStr != NULL && nombreStr!= NULL && horasTrabajadasStr != NULL && sueldoStr!= NULL)
	{
		newEmployee = employee_new();
		if(newEmployee != NULL)
		{
			if(!(employee_setHorasTrabajadas(newEmployee, atoi(horasTrabajadasStr)) &&
			   employee_setId(newEmployee, atoi(idStr)) &&
			   employee_setNombre(newEmployee, nombreStr) &&
			   employee_setSueldo(newEmployee, atoi(sueldoStr))))
			{
				employee_delete(newEmployee);
			}
		}
	}
	return newEmployee;
}

void employee_delete(Employee* this)
{
	free(this);
	this = NULL;
}

int employee_setId(Employee* this,int id)
{
	int todoOk = 0;

	if(this != NULL)
	{
		this->id = id;
		todoOk = 1;
	}
	return todoOk;
}

int employee_getId(Employee* this,int* id)
{
	int todoOk = 0;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		todoOk = 1;
	}
	return todoOk;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int todoOk = 0;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		todoOk = 1;
	}
	return todoOk;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int todoOk = 0;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		todoOk = 1;
	}
	return todoOk;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int todoOk = 0;

	if(this != NULL)
	{
		this->horasTrabajadas = horasTrabajadas;
		todoOk = 1;
	}
	return todoOk;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int todoOk = 0;

	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		todoOk = 1;
	}
	return todoOk;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int todoOk = 0;

	if(this != NULL)
	{
		this->sueldo = sueldo;
		todoOk = 1;
	}
	return todoOk;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int todoOk = 0;

	if(this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;
		todoOk = 1;
	}
	return todoOk;
}

int mostrarEmpleado(Employee* this)
{
    int todoOk = 0;
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;

    if(this != NULL
       && employee_getId(this, &id)
       && employee_getNombre(this, nombre)
       && employee_getHorasTrabajadas(this, &horasTrabajadas)
       && employee_getSueldo(this, &sueldo))
    {
        printf("|  %d\t|\t %-15s\t| \t%d\t    |     %d\t    |\n", id, nombre, horasTrabajadas, sueldo);
        todoOk = 1;
    }
    return todoOk;
}

int newEmpleado(Employee* this, int* id, char* path, LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	char nombre[128];
	int horasTrabajadas = 0;
	int sueldo = 0;
	this = employee_new();

	if(this != NULL && id != NULL && path != NULL)
	{

		validacionId(id, path);
		printf("Id: %d\n", *id);
		utn_getString("Ingrese el nombre: ","Error, reingrese: ", 128, 5, nombre);
		utn_getInt("Ingrese la cantidad de horas trabajadas: ", "Error, reingrese: ", 0, 400, 5, &horasTrabajadas);
		utn_getInt("Ingrese el sueldo: ", "Error, reingrese: ", 1000, 50000, 5, &sueldo);
		if(employee_setId(this, *id)
		   && employee_setNombre(this, nombre)
		   && employee_setHorasTrabajadas(this, horasTrabajadas)
		   && employee_setSueldo(this, sueldo))
		{
			todoOk = 1;
			ll_add(pArrayListEmployee, this);
		}
		else
		{
			employee_delete(this);
		}
	}
	return todoOk;
}

int validacionId(int* id, char* path)
{
	int todoOk = 0;
	FILE* f;
	int auxId = 0;
	if(id != NULL && path != NULL)
	{
		f = fopen(path, "r");
		if(f != NULL)
		{
			if(fscanf(f, "%d",  &auxId) == 1)
			{
				if(auxId > *id)
				{
					*id = auxId;
					todoOk = 1;
				}
			}
		}
	}
	return todoOk;
}

int employee_CmpNombre(void* a, void* b)
{
	int retorno = 0;
	Employee* emp1;
	Employee* emp2;
	if(a != NULL && b != NULL)
	{
		emp1 = (Employee*) a;
		emp2 = (Employee*) b;

		retorno = strcmp(emp1->nombre, emp2->nombre);
	}
	return retorno;
}

int employee_CmpSueldo(void* a, void* b)
{
	int retorno = 0;
	Employee* emp1;
	Employee* emp2;
	if(a != NULL && b != NULL)
	{
		emp1 = (Employee*) a;
		emp2 = (Employee*) b;

		if(emp1->sueldo > emp2->sueldo)
		{
			retorno = 1;
		}
		else
		{
			if(emp1->sueldo < emp2->sueldo)
			{
				retorno = -1;
			}
		}
	}
	return retorno;
}

int employee_CmpHorasTrabajadas(void* a, void* b)
{
	int retorno = 0;
	Employee* emp1;
	Employee* emp2;
	if(a != NULL && b != NULL)
	{
		emp1 = (Employee*) a;
		emp2 = (Employee*) b;

		if(emp1->horasTrabajadas > emp2->horasTrabajadas)
		{
			retorno = 1;
		}
		else
		{
			if(emp1->horasTrabajadas < emp2->horasTrabajadas)
			{
				retorno = -1;
			}
		}
	}
	return retorno;
}

int employee_CmpId(void* a, void* b)
{
	int retorno = 0;
	Employee* emp1;
	Employee* emp2;
	if(a != NULL && b != NULL)
	{
		emp1 = (Employee*) a;
		emp2 = (Employee*) b;

		if(emp1->id > emp2->id)
		{
			retorno = 1;
		}
		else
		{
			if(emp1->id < emp2->id)
			{
				retorno = -1;
			}
		}
	}
	return retorno;
}

