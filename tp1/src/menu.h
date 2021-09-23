/*
 * menu.h
 *
 *  Created on: 21 sep. 2021
 *      Author: franc
 */

#ifndef MENU_H_
#define MENU_H_
/// @fn void mostrarOpciones(int, int, float, float, char, char)
/// @brief Va a mostrar las opciones que el usuario puede elegir.
/// @param flagA La primer flag la utilizo para saber si el usuario ya ingreso un numero y si es asi mostrarlo
/// @param flagB La segundno flag la utilizo para saber si el usuario ya ingreso un numero y si es asi mostrarlo
/// @param numeroUno El primer numero ulitizo para mostrarlo cuando el usuario ya lo ingreso para que lo vea en pantalla
/// @param numeroDos El segundo numero ulitizo para mostrarlo cuando el usuario ya lo ingreso para que lo vea en pantalla
/// @param operadorA Es un char donde Ingreso que es del operador 'A'
/// @param operadorB Es un char donde Ingreso que es del operador 'B'
void mostrarOpciones(int flagA , int flagB, float numeroUno, float numeroDos, char operadorA, char operadorB);
/// @fn void mostrarSuma(float, float, float)
/// @brief Mostrar el resultado de la suma.
/// @param numeroUno Primer numero ingresado por el usuario.
/// @param numeroDos Segundo numero ingresado por el usuario.
/// @param resultadoSuma Resultado de la suma

void mostrarSuma(float numeroUno, float numeroDos, float resultadoSuma);
/// @fn void mostrarResta(float, float, float)
/// @brief Mostrar el resultado de la resta.
/// @param numeroUno Primer numero ingresado por el usuario.
/// @param numeroDos Segundo numero ingresado por el usuario.
/// @param resultadoResta Resultado de la resta
void mostrarResta(float numeroUno, float numeroDos, float resultadoResta);
/// @fn void mostrarMultiplicacion(float, float, double)
/// @brief Mostrar el resultado de la multplicacion. Dentro de la funcion al manejar variables float
/// (me puede devolver -0.00, en caso que el resultado sea 0. Por ej: -2.5 * 0 == -0.00)
/// .Entonces llamo a una funcion para preguntar si numUno o numDos es 0. Si es asi muestro que el resultado es 0.
/// @param numeroUno Primer numero ingresado por el usuario.
/// @param numeroDos Segundo numero ingresado por el usuario.
/// @param resultadoMultiplicacion Resultado de la multiplicacion.
void mostrarMultiplicacion(float numeroUno, float numeroDos, float resultadoMultiplicacion);
/// @fn void mostrarDivision(float, float, float, int)
/// @brief Mostrar el resultado de la division o si existio un error.
/// @param numeroUno Primer numero ingresado por el usuario.
/// @param numeroDos Segundo numero ingresado por el usuario.
/// @param resultadoDivision Resultado de la division.
/// @param verificacionDivision Si la verificacion de la division es 1 muestro el resultado, -1 Error no se pudo dividir por 0, 0 error de puntero
void mostrarDivision(float numeroUno, float numeroDos, float resultadoDivision, int verificacionDivision);
/// @fn void mostrarFactorial(float, double, int)
/// @brief Mostrar el resultado o si existio un error.Dentro de la funcion al manejar variables float
/// (me puede devolver -0.00, en caso que el resultado sea 0. Por ej: 0 / 2.5 == -0.00)
/// .Entonces llamo a una funcion para preguntar si numUno es 0. Si es asi muestro que el resultado es 0.
/// @param numero Numero ingresado por el usuario.
/// @param resultadoFactorial Resultado del factorial si se pudo calcular.
/// @param verificacionFactorial Si es 1 muestra en pantalla el resultado, si es -1  no se puede calcular
//el factorial menor a 0, si es -2 no se puede calcular el factorial de un numero
//con decimales , y si es -3 no se puede calcular el factorial de un numero mayor a 150.
void mostrarFactorial(float numero, double resultadoFactorial, int verificacionFactorial);
/// @fn void mostrarOperandos(int, float, char)
/// @brief Mostrar en pantalla cuanto vale el operador por ej: A = 10 o A = "No tiene ningun valor"
/// @param flag Para saber si ingreso el numero
/// @param numero Numero a mostrar
/// @param operador Un character que voy a mostar por ej : 'A','B','X',Y'.
void mostrarOperandos(int flag, float numero, char operador);
/// @fn void mostrarSiIngresoNumeros(int)
/// @brief Imprimir en pantalla si ingreso los numeros.
/// @param verificarFlags Es un entero que va a evaluar los siguientes casos:  0 No ingreso los dos numeros, - 1 No ingreso el segundo numero, -2 no ingreso el primer numero.
void mostrarSiIngresoNumeros(int verificarFlags);


#endif /* MENU_H_ */
