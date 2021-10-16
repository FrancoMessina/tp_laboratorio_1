/*
 * validaciones.c
 *
 *  Created on: 16 oct. 2021
 *      Author: franc
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "input.h"

int validarRangoEntero(int valor, int limiteInferior, int limiteSuperior)
{
    int todoOk = 0;
    if(valor >= limiteInferior && valor <= limiteSuperior )
    {
        todoOk = 1;
    }
    return todoOk;
}
int stringPrimerLetraMayuscula(char string[])
{
    int todoOk = 0;
    int i = 0;

    if(string != NULL)
    {
        strlwr(string);
        string[0] = toupper(string[0]);
        while(string[i] != '\0')
        {
            if(string[i] == ' ')
            {
                string[i+1] = toupper(string[i+1]);
            }

            i++;
        }
        todoOk = 1;
    }

    return todoOk;
}

int validarLargoString(char string[],char mensaje [], int min , int max)
{
	int todoOk = 0;
	if(string != NULL && mensaje != NULL)
	{
		while(strlen(string) < min || strlen(string) > max)
		{
			ingresarString(mensaje, string);
		}
		todoOk = 1;
	}
	return todoOk;

}
int verificarSueldo(float numero)
{
	int todoOk = 0;
	if(numero > 0)
	{
		todoOk = 1;
	}
	return todoOk;
}
