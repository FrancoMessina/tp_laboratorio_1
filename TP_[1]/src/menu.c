/*
 * menu.c
 *
 *  Created on: 21 sep. 2021
 *      Author: franc
 */

#include <stdio.h>
#include "menu.h"
#include "validaciones.h"


void mostrarOpciones(int flagA , int flagB, float numeroUno, float numeroDos, char operadorA, char operadorB)
{
    printf("1. Ingresar primer digito.");
    mostrarOperandos(flagA, numeroUno, operadorA);
    printf("2. Ingresar segundo digito.");
    mostrarOperandos(flagB, numeroDos, operadorB);
    printf("3. Calcular operaciones. \n");
    printf("4. Imprimir resultados. \n");
    printf("5. Salir de la aplicacion. \n");
}
void mostrarSuma(float numeroUno, float numeroDos, float resultadoSuma)
{
	printf("La suma de %.2f + %.2f es : %.2f \n",numeroUno,numeroDos,resultadoSuma);
}
void mostrarResta(float numeroUno, float numeroDos, float resultadoResta)
{
	printf("La resta de %.2f - %.2f es : %.2f \n",numeroUno,numeroDos,resultadoResta);
}
void mostrarMultiplicacion(float numeroUno, float numeroDos, float resultadoMultiplicacion)
{
	 int numeroUnoEsCero;
	 int numeroDosEsCero;
	 numeroUnoEsCero = verificarSiEsCero(numeroUno);
	 numeroDosEsCero = verificarSiEsCero(numeroDos);
	 if(numeroUnoEsCero == 0 || numeroDosEsCero == 0)
	 {
		 printf("La multiplicacion de %.2f * %.2f es : 0 \n",numeroUno,numeroDos);
	 }
	 else
	 {
		 printf("La multiplicacion de %.2f * %.2f es : %.2f \n",numeroUno,numeroDos,resultadoMultiplicacion);
	 }

}
void mostrarDivision(float numeroUno, float numeroDos, float resultadoDivision, int verificacionDivision)
{
	int numeroUnoEsCero;
	numeroUnoEsCero = verificarSiEsCero(numeroUno);
	if(verificacionDivision == 1 && numeroUnoEsCero == 1)
	{
		printf("La division de %.2f / %.2f es : %.2f \n",numeroUno,numeroDos,resultadoDivision);
	}
	else
	{
		if(verificacionDivision == -1)
		{
			printf("Error no se puede dividir un numero por 0\n");
		}
		else
		{
			if(numeroUnoEsCero == 0)
			{
				printf("La division de %.2f / %.2f es : %d \n",numeroUno,numeroDos, numeroUnoEsCero);
			}
			else
			{
				printf("Error\n");
			}

		}
	}
}
void mostrarFactorial(float numero, double resultadoFactorial, int verificacionFactorial)
{
	if(verificacionFactorial== 1)
	{
		printf("El factorial de %.0f es : %.0lf \n",numero,resultadoFactorial);
	}
	else
	{

		if(verificacionFactorial == -1)
		{
			printf("Error no se puede calcular factorial menor a 0 \n");
		}
		else
		{
			if(verificacionFactorial == -2)
			{
				printf("Error no se puede calcular el factorial de un numero con decimales\n");
			}
			else
			{
				printf("Error no se puede calcular el factorial de un numero mayor a 21 \n");
			}
		}
	}
}
void mostrarOperandos(int flag, float numero, char operador)
{
	if(flag == 1)
	{
		printf("Operando %c = %.2f\n",operador,numero);
		fflush(stdin);
	}
	else
	{
		printf("Operando %c = No tiene ningun valor\n",operador);
		fflush(stdin);
	}
}
void mostrarSiIngresoNumeros(int verificarFlags)
{
	if(verificarFlags == 0 )
	{
		printf("No ingresaste los dos numeros \n");
	}
	else
	{
		if(verificarFlags == -1)
		{
			printf("No ingresaste el segundo numero \n");
		}
		else
		{
			if(verificarFlags == -2)
			{
			   printf("No ingresaste el primer numero \n");
			}
		}
	}
}
void mostrarCalculosARealizar(float numeroUno, float numeroDos)
{
	printf("1)Calcular la suma de  %.2f + %.2f = ?\n",numeroUno,numeroDos);
	printf("2)Calcular la resta de %.2f - %.2f = ?\n",numeroUno,numeroDos);
	printf("3)Calcular la multiplicacion de  %.2f * %.2f = ?\n",numeroUno,numeroDos);
	printf("4)Calcular la division de  %.2f / %.2f = ?\n",numeroUno,numeroDos);
	printf("5-A)Calcular el factorial de !%.2f = ?\n",numeroUno);
	printf("5-B)Calcular el factorial de !%.2f = ?\n",numeroDos);
}
