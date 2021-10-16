/*
 * Menu.c
 *
 *  Created on: 15 oct. 2021
 *      Author: franc
 */
#include <stdio.h>
#include <stdlib.h>
int pedirOpcion(void)
{
	int opcion;
	system("cls");
	printf("[1]ALTA EMPLEADO\n");
	printf("[2]MODIFICACION EMPLEADO\n");
	printf("[3]BAJA EMPLEADO\n");
	printf("[4]LISTADO EMPLEADOS\n");
	printf("[5]GRACIAS POR USAR EL PROGAMA \n");
	fflush(stdin);
	scanf("%d",&opcion);
	return opcion;
}
