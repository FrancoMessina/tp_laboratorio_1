/*
 * input.c
 *
 *  Created on: 15 oct. 2021
 *      Author: franc
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int ingresarString(char mensaje[], char dato[])
{
	int todoOk = 0;

	    if(mensaje != NULL && dato !=NULL)
	    {
	        printf("%s", mensaje);
	        fflush(stdin);
	        gets(dato);

	        todoOk = 1;
	    }

	    return todoOk;
}
int ingresarEntero(char mensaje[])
{
    int numeroIngresado;
    printf("%s",mensaje);

    scanf("%d",&numeroIngresado);

    return numeroIngresado;

}
float ingresarFlotante(char mensaje[])
{
    float numeroIngresado;
    printf("%s",mensaje);

    scanf("%f",&numeroIngresado);

    return numeroIngresado;

}

int pedirOpcion(void)
{
	printf("-------------------------------\n");
	printf("  *** ABM EMPLEADOS ***\n\n");
	printf("-------------------------------\n");
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

