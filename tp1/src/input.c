/*
 * input.c
 *
 *  Created on: 21 sep. 2021
 *      Author: franc
 */
#include <stdio.h>
#include "input.h"
int ingresarNumeroFlotante(char mensaje[], float*pNumero)
{
	int todoOk = 0;
	if(pNumero != NULL)
	{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%f",pNumero);
		todoOk = 1;
	}

	return todoOk;
}

