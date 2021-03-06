/*
 ============================================================================
 Name        : tp1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"
#include "menu.h"
#include "input.h"
#include "validaciones.h"

int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	char seguir = 's';
	float numeroUno;
	float numeroDos;
	float resultadoSuma;
	float resultadoResta;
	float resultadoMultiplicacion;
	float resultadoDivision;
	double resultadoFactorialUno;
	double resultadoFactorialDos;
	int verificacionDivision;
	int verificacionFactorialUno;
	int verificacionFactorialDos;
	int flagSegundoNumero = 0;
	int flagPrimerNumero = 0;
	int verificarFlags = 0;
	int flagCalculosRealizados = 0;

	do
	{
		mostrarOpciones(flagPrimerNumero , flagSegundoNumero, numeroUno, numeroDos,'A','B');
		opcion = validarMenu(1,5);
		system("cls");
		switch(opcion)
		{
			case 1:
				flagPrimerNumero = ingresarNumeroFlotante("Ingresa el Primer N?mero : ",&numeroUno);
			break;
			case 2:
				flagSegundoNumero = ingresarNumeroFlotante("Ingresa el Segundo N?mero :",&numeroDos);
			break;
			case 3:
				verificarFlags = verificarSiIngresoNumeros(flagPrimerNumero,flagSegundoNumero);
				if(verificarFlags == 1)
				{
					resultadoSuma = sumarDosNumeros(numeroUno,numeroDos);
					resultadoResta = restarDosNumeros(numeroUno,numeroDos);
					resultadoMultiplicacion = multiplicarDosNumeros(numeroUno,numeroDos);
					verificacionDivision = dividir(numeroUno,numeroDos,&resultadoDivision);
					verificacionFactorialUno= calcularFactorial(numeroUno,&resultadoFactorialUno);
					verificacionFactorialDos= calcularFactorial(numeroDos,&resultadoFactorialDos);
					flagCalculosRealizados = 1;
					mostrarCalculosARealizar(numeroUno,numeroDos);
					printf("Calculos realizados\n");
				}
				else
				{
					mostrarSiIngresoNumeros(verificarFlags);
				}
			break;
			case 4:
				if(flagCalculosRealizados == 1)
				{
					mostrarSuma(numeroUno, numeroDos,resultadoSuma);
					mostrarResta(numeroUno,numeroDos,resultadoResta);
					mostrarMultiplicacion(numeroUno,numeroDos,resultadoMultiplicacion);
					mostrarDivision(numeroUno,numeroDos, resultadoDivision,verificacionDivision);
					mostrarFactorial(numeroUno, resultadoFactorialUno, verificacionFactorialUno);
					mostrarFactorial(numeroDos, resultadoFactorialDos, verificacionFactorialDos);

				}
				else
				{
					verificarFlags = verificarSiIngresoNumeros(flagPrimerNumero,flagSegundoNumero);
					;
					if(verificarFlags == 1)
					{
						printf("No realizaste los calculos\n");
					}
					else
					{
						 mostrarSiIngresoNumeros(verificarFlags);
					}
				}
			break;
			case 5:
				seguir = 'n';
				printf("Gracias por usar la calculadora de Franco Messina\n");
			break;

		}
		system("pause");
	}while(seguir == 's');
	return EXIT_SUCCESS;
}
