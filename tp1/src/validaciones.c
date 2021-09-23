/*
 * validaciones.c
 *
 *  Created on: 21 sep. 2021
 *      Author: franc
 */
#include <stdio.h>
#include "validaciones.h"
int verificarSiEsEntero(float flotanteRecibido)
{
    int todoOk = 0;
    int numero;
	float resto;
	numero = flotanteRecibido;
	resto = flotanteRecibido - numero;
	if(resto == 0)
	{
		todoOk = 1;
	}
    return todoOk;
}
int verificarSiIngresoNumeros(int flagPrimerNumero,int flagSegundoNumero)
{
    int todoOk;
    if(flagPrimerNumero == 1 && flagSegundoNumero == 1)
    {
        todoOk = 1;//Ingreso los numeros
    }
    else
    {
        if(flagPrimerNumero == 0 && flagSegundoNumero == 0 )
        {
            todoOk = 0;//No ingreso los dos numeros
        }

        else
        {
            if(flagSegundoNumero == 0)
            {
                todoOk = -1;//No ingreso el segundo numero

            }
            else
            {
                todoOk = -2;//No ingreso el primer numero
            }
        }
     }
    return todoOk;
}
int validarMenu(int limiteInferior,int limiteSuperior)
{
	int opcion;
	printf("Elegi una opcion del %d al %d \n",limiteInferior, limiteSuperior);
	scanf("%d",&opcion);
	while(opcion < limiteInferior || opcion >limiteSuperior )
	{
		printf("Error.Elegi una opcion del %d al %d \n",limiteInferior, limiteSuperior);
		scanf("%d",&opcion);
	}
	return opcion;
}
int cambiarSignoCero(float numero)
{
	int todoOk = 1;//Retorno 1 si el numero no es 0
	if(numero == 0)
	{
		todoOk = 0; //Retorno 0 si el numero es 0 asi cambia el signo
	}
	return todoOk;
}
