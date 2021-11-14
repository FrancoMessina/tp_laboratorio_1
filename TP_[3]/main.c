#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "input.h"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
 *****************************************************/



int main()
{
	setbuf(stdout,NULL);
	int option = 0;

	LinkedList* listaEmpleados = ll_newLinkedList();
	do{
		option =  menuOpcion();
		switch(option)
		{
		case 1:
			controller_loadFromText("data.csv",listaEmpleados);
			break;
		case 2:
			controller_loadFromBinary("data.bin",listaEmpleados);
			break;
		case 3:
			controller_addEmployee(listaEmpleados);
			printf("Empleado agregado con exito! \n");
			break;
		case 4:
			controller_editEmployee(listaEmpleados);
			printf("Edicion con exito! \n");
			break;
		case 5:
			controller_removeEmployee(listaEmpleados);
			printf("Operacion con exito! \n");

			break;
		case 6:
			controller_ListEmployee(listaEmpleados);
			printf("Listado de empelados con exitos! \n");

			break;
		case 7:
			controller_sortEmployee(listaEmpleados);
			printf("Ordenado con exitos! \n");
			break;
		case 8:
			controller_saveAsText("data.csv", listaEmpleados);
			printf("Datos cargados en Texto correctamente! \n");

			break;
		case 9:
			controller_saveAsBinary("data.bin", listaEmpleados);
			printf("Datos cargados en bin correctamente! \n");
			break;
		case 10:
			printf("Gracias por usar el programa!! \n");
			break;
		default:
			printf("Opcion invalida \n");
			break;
		}
		system("pause");
	}while(option != 10);
	ll_deleteLinkedList(listaEmpleados);
	return 0;
}

