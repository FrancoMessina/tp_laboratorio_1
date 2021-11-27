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
#include "input.h"
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


int getIntFloat (float* pResultado)
    {
        int retorno = -1;
        char buffer[4096];


        if (myGetsFloat(buffer, sizeof(buffer)) && esNumericoFlotante(buffer))
        {
            retorno = 0;
            *pResultado = atof(buffer);
        }
        return retorno;
    }




    int myGetsFloat(char* cadena, int longitud)
    {
        char buffer[4096];
        fflush(stdin);
        scanf("%s", buffer);
        strncpy(cadena, buffer,longitud);
        return -1;
    }



    int validarEnteroFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
    {
        int retorno = -1;
        float buffer;

        if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
        {
            do
            {
                printf("%s", mensaje);

                if (getIntFloat(&buffer)== 0 && buffer >= minimo && buffer <= maximo)
                {
                    *pResultado = buffer;
                    retorno = 0;
                    break;
                }
                reintentos--;
                printf("%s", mensajeError);
            }
            while (reintentos >= 0);
        }

        return retorno;
    }


    int esNumericoFlotante(char str[])
    {
        int i = 0;
        int cantidadPuntos = 0;
        while (str[i] != '\0')
        {
            if (i == 0 && str[i] == '-')
            {
                i++;
                continue;
            }
            if (str[i] == '.' && cantidadPuntos == 0)
            {
                cantidadPuntos++;
                i++;
                continue;

            }
            if (str[i] < '0' || str[i] > '9')
                return 0;
            i++;
        }
        return 1;
    }
