#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menu.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/

int main()
{
    int option = 0;
    int nextId = 1001;
    int auxId = 1000;
    int flagArchivo = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();
    setbuf(stdout, NULL);

    validacionId(&auxId, "id.csv");

    do{
    	option = menu();
		switch(option)
		{
			case 1:
				if(auxId == 1000)
				{
					if(!flagArchivo)
					{
						if(controller_loadFromText("data.csv",listaEmpleados))
						{
							flagArchivo = 1;
						}
					}
					else
					{
						printf("Ya se realizo la carga del archivo anteriormente");
					}
				}
				else
				{
					if(!flagArchivo)
					{
						if(controller_loadFromText("data2.csv",listaEmpleados))
						{
							flagArchivo = 1;
						}
					}
					else
					{
						printf("Ya se realizo la carga del archivo anteriormente");
					}
				}
				break;
			case 2:
				if(auxId == 1000)
				{
					if(!flagArchivo)
					{
						if(controller_loadFromBinary("data.bin",listaEmpleados))
						{
							flagArchivo = 1;
						}
					}
					else
					{
						printf("Ya se realizo la carga del archivo anteriormente");
					}
				}
				else
				{
					if(!flagArchivo)
					{
						if(controller_loadFromBinary("data2.bin",listaEmpleados))
						{
							flagArchivo = 1;
						}
					}
					else
					{
						printf("Ya se realizo la carga del archivo anteriormente");
					}
				}
				break;
			case 3:
				controller_addEmployee(listaEmpleados, &nextId, "id.csv");
				break;
			case 4:
				if(ll_isEmpty(listaEmpleados))
				{
					printf("No se puede editar sin cargar los empleados anteriormente");
				}
				else
				{
					controller_editEmployee(listaEmpleados);
				}
				break;
			case 5:
				if(ll_isEmpty(listaEmpleados))
				{
					printf("No se puede remover sin cargar los empleados anteriormente");
				}
				else
				{
					controller_removeEmployee(listaEmpleados, nextId);
				}
				break;
			case 6:
				if(ll_isEmpty(listaEmpleados))
				{
					printf("No se puede listar sin cargar los empleados anteriormente");
				}
				else
				{
					controller_ListEmployee(listaEmpleados);
				}
				break;
			case 7:
				if(ll_isEmpty(listaEmpleados))
				{
					printf("No se puede grabar sin cargar los archivos anteriormente");
				}
				else
				{
					controller_sortEmployee(listaEmpleados);
				}
				break;
			case 8:
				if(ll_isEmpty(listaEmpleados))
				{
					printf("No se puede grabar sin cargar los archivos anteriormente");
				}
				else
				{
					controller_saveAsText("data2.csv" , listaEmpleados);
					controller_saveAsTextId("id.csv" , nextId);
				}
				break;
			case 9:
				if(ll_isEmpty(listaEmpleados))
				{
					printf("No se puede grabar sin cargar los archivos anteriormente");
				}
				else
				{
					controller_saveAsBinary("data2.bin" , listaEmpleados);
					controller_saveAsTextId("id.csv" , nextId);//guarda el id
				}
				break;
		}
		printf("\n\n");
    }while(option != 10);
    free(listaEmpleados);
    return 0;
}
