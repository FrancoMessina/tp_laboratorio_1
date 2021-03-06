/*
 * operaciones.h
 *
 *  Created on: 21 sep. 2021
 *      Author: franc
 */

#ifndef OPERACIONES_H_
#define OPERACIONES_H_
/// @fn float sumarDosNumeros(float, float)
/// @brief Calcula la Suma dos numeros flotantes y devuelve el resultado.
/// @param numeroUno El primer numero ingresado por el usuario.
/// @param numeroDos El segundo numero ingresado por el usuario.
/// @return El resultado de la suma de los dos numeros.
float sumarDosNumeros(float numeroUno, float numeroDos);
/// @fn float restarDosNumeros(float, float)
/// @brief Calcula la Resta de  primer numero ingresado - segundo numero ingresado y devuelve el resultado.
/// @param numeroUno El primer numero ingresado por el usuario
/// @param numeroDos El segundo numero ingresado por el usuario
/// @return El resultado de la resta de los dos numeros. A - B
float restarDosNumeros(float numeroUno, float numeroDos);
/// @fn int dividir(float, float, float*)
/// @brief Calcula la division de dos numeros flotantes y devuelve un int para verificar.
/// @param numeroUno El primer numero ingresado por el usuario.
/// @param numeroDos El segundo numero ingresado por el usuario.
/// @param pResultado Puntero flotante donde se guarda el numero.
/// @return Retorno 0 si el error es del puntero, 1 Si funciona correctamente,  -1 Si hay error de divisior (numeroDos=0).
int dividir(float numeroUno, float numeroDos, float *pResultado);
/// @fn double multiplicarDosNumeros(float, float)
/// @brief Multiplicacion de dos numeros flotantes y devuelve el resultado.
/// @param numeroUno El primer numero ingresado por el usuario
/// @param numeroDos El segundo numero ingresado por el usuario
/// @return Retorno la multplicacion numeroUno * numeroDos
float multiplicarDosNumeros(float numeroUno, float numeroDos);
/// @fn int calcularFactorial(float, double*)
/// @brief Calcular el factorial de un numero entero por ejemplo: 12.00. Y devolver un int para verificar si se pudo calcular
/// @param numero Numero ingresado por el usuario
/// @param pResultado Puntero double donde se va a guardar el resultado
/// @return Retorna un entero. 1 si Funciona, 0 Error de puntero, -1 Error menor a 0, -2 Error por ser un flotante - 3 error por ser mayor a 21.
int calcularFactorial(float numero, double *pResultado);

#endif /* OPERACIONES_H_ */
