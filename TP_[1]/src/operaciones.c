/*
 * operaciones.c
 *
 *  Created on: 21 sep. 2021
 *      Author: franc
 */
#include <stdio.h>
#include "operaciones.h"
#include "validaciones.h"

float sumarDosNumeros(float numeroUno, float numeroDos)
{
	float resultado;
	resultado = numeroUno + numeroDos;
	return resultado;
}

float restarDosNumeros(float numeroUno, float numeroDos)
{
	float resultado;
	resultado = numeroUno - numeroDos;
	return resultado;
}

int dividir(float numeroUno, float numeroDos, float *pResultado)
{
	int todoOk = 0;//Error Puntero
	    if(pResultado != NULL && numeroDos !=0)
	    {
	        *pResultado = numeroUno /numeroDos;
	        todoOk=1;//Funciona
	    }
	    else
	    {
	        if(numeroDos == 0){
	            todoOk = -1;//Error divisor por  0
	        }
	    }
	    return todoOk;
}

float multiplicarDosNumeros(float numeroUno, float numeroDos)
{
	float resultado;
	resultado = numeroUno * numeroDos;
	return resultado;
}

int calcularFactorial(float numero, double *pResultado)
{
	int todoOk = 0;//Error puntero
	double fact = 1;
	int numeroEsEntero = verificarSiEsEntero(numero);
	if(pResultado != NULL && numero >= 0 && numeroEsEntero == 1 && numero < 22)
	{
		for(int i = numero; i > 1;i--)
		{
			fact = fact * i;
		}
		*pResultado= fact;
		todoOk = 1;//Funciona
	}
	else
	{
		if(numero < 0)
		{
			todoOk = -1;// Error menor a 0
		}
		else
		{
			if(numeroEsEntero == 0)
			{
				todoOk = -2;//Error por ser un flotante
			}
			else
			{
				todoOk = -3; //Error por ser mayor a  21
			}

		}
	}

	return todoOk;
}
