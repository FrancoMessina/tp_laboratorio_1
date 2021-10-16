#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "input.h"
#include "Menu.h"
#define TAM 10
#define ASCENDENTE 1
#define DESCENDENTE 0
int main(void) {
	setbuf(stdout, NULL);
	Employee lista[TAM];
	int nextId = 1000;
	char name [51];
	char lastName[51];
	float salary;
	int sector;
	char seguir = 's';
	int pedirId;
	int opcionInformar;
	int contEmpleados = 0;
	int pedirOrden;

	if(initEmployees(lista,TAM) == -1)
	{
		printf("Error \n");
	}
	do
	{
		switch(pedirOpcion())
		{
		case 1:

			printf("Alta Empleado \n");
			if(buscarLibre(lista,TAM) == -1)
			{
				printf("no se pudo realizar el alta\n");
			}
			else
			{
				cargarEmployee(&nextId, name,lastName,&salary,&sector);
				addEmployees(lista,TAM, nextId, name, lastName, salary, sector);
				printf("Alta exitosa! \n");
				contEmpleados++;
			}
			break;
		case 2:
			if(contEmpleados == 0)
			{
				printf("Tenes que cargar un empleado como minimo \n");
			}
			else
			{
				if(!modificarEmployee(lista,TAM))
				{
					printf("No se pudo modificar\n");
				}
				else
				{
					printf("Modifcacion exitosa\n");
				}
			}
			break;
		case 3:
			if(contEmpleados == 0)
			{
				printf("Tenes que cargar un empleado como minimo \n");
			}
			else
			{
				pedirId = ingresarEntero("Ingresa el ID : ");
				if(removeEmployee(lista,pedirId,TAM) == -1)
				{
					printf("No se pudo dar de baja\n");
				}
				else
				{
					contEmpleados--;
					printf("Baja exitosa\n");
				}
			}
			break;
		case 4:
			contadorEmpleados(lista,&contEmpleados,TAM);
			if(contEmpleados == 0)
			{
				printf("Tenes que cargar un empleado como minimo \n");
			}
			else
			{
				printf("Opcion: [1]Ordenar Alfabeticamente por Apellido y sector. \n [2] Total,promedio Salarios, y cuantos empleados superan el promedio : ");
				scanf("%d",&opcionInformar);
				switch(opcionInformar)
				{
				case 1:
					pedirOrden = ingresarEntero("[1]Orden Ascendente A-Z [2]Orden Descedente Z-A : ");
					while(!validarRangoEntero(pedirOrden, 1 , 2))
					{
						pedirOrden = ingresarEntero("Error...[1]Orden Ascendente A-Z [2]Orden Descedenten Z-A : ");
					}
					if(pedirOrden == 1)
					{
						sortEmployees(lista,ASCENDENTE,TAM);
					}
					else
					{
						sortEmployees(lista,DESCENDENTE,TAM);
					}
					printEmployees(lista,TAM);
					break;
				case 2:
					mostrarTotalSalarios(lista,TAM);
					mostrarPromSalarios(lista,TAM);
					cantSuperanSalarioProm(lista,TAM);
					break;
				default:
					printf("Opcion incorrecta \n");
					break;
				}
			}
			break;
		 case 5:
				printf("[5]GRACIAS POR USAR EL PROGAMA\n");
				seguir = 'n';
				break;
			default:
				printf("Opcion incorrecta \n");
				break;
			}
			system("pause");
		}
	while(seguir == 's');
	return EXIT_SUCCESS;
}
