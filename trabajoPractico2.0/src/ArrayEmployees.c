/*
 * ArrayEmployees.c
 *
 *  Created on: 15 may. 2021
 *      Author: Maty
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "ArrayEmployees.h"


int menu()
{
    int option;
    printf("*Alumno: Prutscher Matias Nicolas*\n");
    printf("*Division: 1°A*\n\n");
    printf("******* Trabajo practico n°2 *******\n\n");
    printf("1- Enter employee: ");
    printf("\n2- Find employee: ");
    printf("\n3- Delete employee: ");
    printf("\n4- Reports: ");
    printf("\n5- Exit: \n");
    scanf("%d", &option);

    return option;
}

int subMenu()
{
	int option;
	printf("1- Alphabetical sorting: ");
	printf("\n2- Total and average wages: ");
	scanf("%d", &option);

	return option;
}

int initEmployees(Employee* list, int len)
{
	int isOk = -1;
	for(int i = 0; i< len; i++)
	{
		list[i].isEmpty = 1;
		isOk = 0;
	}
	return isOk;
}

int createEmployee(Employee* list, int* pId)
{
	int isOk = 0;
	if(pId != NULL)
	{
		utn_getString("Enter the name of the employee: ", "Error, re-enter the name: ", 51, 5, list->name);
		utn_getString("Enter the last name of the employee: ", "Error, re-enter the last name: ", 51, 5, list->lastName);
		utn_getFloat("Enter the salary: ","Error, re-enter the salary: ", 1000, 50000, 5, &list->salary);
		utn_getInt("Enter the sector: ","Error, re-enter the sector: ", 1, 10, 5, &list->sector);
		list->isEmpty = 0;
		list->id = *pId;
		(*pId)++;
		isOk = 1;
	}
	return isOk;
}

int confirmExit(char* option)
{
	int isOk = 0;

	while(*option != 'Y' && *option != 'N')
		{
			printf("Error, re-enter an option. Y for 'yes' or N for 'NO' : ");
			fflush(stdin);
			*option = getchar();
		}
	isOk = 1;

	return isOk;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	int isOk = -1;
	int i;

	if(list != NULL && len > 0 && id >=0 && name != NULL && lastName != NULL && salary > 0 && sector >=0)
	{
		i = lookForEmpty(list, len);
		if(i != -1)
		{
			list[i].id = id;
			strcpy(list[i].name, name);
			strcpy(list[i].lastName, lastName);
			list[i].salary = salary;
			list[i].sector = sector;
			list[i].isEmpty = 0;
			isOk = 0;
		}
	}
	return isOk;
}

int lookForEmpty(Employee list[], int len)
{
    int indice = -1;

    for(int i = 0; i < len; i++)
    {
        if(list[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void printEmployee(Employee list)
{
	printf("|      %d\t|\t %-10s |\t %-10s\t|   %.2f   |%d\t |\n",
			list.id,
			list.lastName,
			list.name,
			list.salary,
			list.sector);
}

int printEmployees(Employee list[], int length)
{
	int isOk = -1;
	int i;
	printf(" _____________________________________________________________________________\n");
	printf("|\t\t|\t\t    |\t\t|\t\t|\t      |\n");
	printf("|     ID:\t| Last Name:        |\t Name:\t|      Salary:\t|   Sector    |\n");
	printf("|_______________|___________________|___________|_______________|_____________|\n");

	for(i = 0; i < length; i++)
	{
		if(!list[i].isEmpty)
		{
			printEmployee(list[i]);
			printf("|_______________|___________________|___________|________|______________________|___________________|____________|\n");
			isOk = 0;
		}
	}
	return isOk;
}

int removeEmployee(Employee* list, int len, int id)
{
	int isOk = -1;
	int index;
	char confirm;

	index = findEmployeeById(list, len, id);
	printf("%d", index);
	if(index != -1)
	{
		printf("The employee to be terminated is:\n");
		printEmployee(list[index]);
		//utn_getString("Remove confirm? Y/N ","Error, re-enter an option. Y for 'yes' or N for 'NO' : ", 2, 3, &confirm); //no funciona, por que? no hay porque. Funciona bien en el resto del codigo
		printf("Remove confirm? Y/N ");
		scanf("%c", &confirm);
		confirm = toupper(confirm);
		confirmExit(&confirm);
		if(confirm == 'Y')
		{
			list[index].isEmpty = 1;
			isOk = 0;
			printf("\nEmployee was successfully eliminated\n\n");
		}
		else
		{
			printf("\nEmployee removal was canceled\n\n");
		}

	}
	else
	{
		printf("There is no employee with that id number\n\n");
	}
	return isOk;
}

int findEmployeeById(Employee* list, int len,int id)
{
	int index = -1;

	if(list != NULL && len > 0 && id > -1)
	{
		for(int i = 0; i < len; i++)
		{
			if(!list[i].isEmpty && list[i].id == id)
			{
				index = i;
				break;
			}
		}
	}
	return index;
}

int sortEmployees(Employee* list, int len, int order)
{
	int isOk = -1;
	Employee employeeAux;

	for(int i = 0; i < len-1; i++)
	{
		for(int j = i+1; j < len ; j++)
		{
			if(order == 1)
			{
				if((list[i].sector > list[j].sector) ||
							   (list[i].sector == list[j].sector &&
								strcmp(list[i].lastName, list[j].lastName) > 0) ||
								((list[i].sector == list[j].sector) &&
								strcmp(list[i].lastName, list[j].lastName) == 0  &&
								strcmp(list[i].name, list[j].name) > 0))
					{
						employeeAux = list[i];
						list[i] = list[j];
						list[j] = employeeAux;
						isOk = 1;
					}
			}
			else
			{
				if((list[i].sector < list[j].sector) ||
							   (list[i].sector == list[j].sector &&
								strcmp(list[i].lastName, list[j].lastName) < 0) ||
								((list[i].sector == list[j].sector) &&
								strcmp(list[i].lastName, list[j].lastName) == 0  &&
								strcmp(list[i].name, list[j].name) < 0))
					{
						employeeAux = list[i];
						list[i] = list[j];
						list[j] = employeeAux;
						isOk = 1;
					}
			}

		}
	}
	return isOk;
}

int CalculateSalary(Employee* list, int len)
{
    int i;
    int isOk = -1;
    float average;
    float accumulator = 0;
    int count = 0;

    if(list != NULL && len > 0)
    {
        for(i = 0; i < len; i++)
        {
            if(list[i].isEmpty != 1)
            {
            	accumulator+=list[i].salary;
                count++;
                isOk = 0;
            }
        }

        average = accumulator / count;

        printf(" >TOTAL salaries: %.2f\n",accumulator);
        printf(" >AVERAGE of salaries: %.2f\n",average);

        showEmployeesExceedAv(list,len,average);

    }

    return isOk;
}

int showEmployeesExceedAv(Employee* list, int len, float average)
{
    int i;
    int isOk=-1;

    if(list != NULL && len > 0 && average > 0)
    {
        printf("         >EMPLOYEES OVER THE AVERAGE SALARY<  \n");
        for(i = 0; i < len; i++)
        {
            if((list[i].isEmpty!= 1) && (list[i].salary > average))
            {
            	printEmployee(list[i]);
                isOk = 0;
            }
        }
    }

    return isOk;
}
