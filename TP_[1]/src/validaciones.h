/*
 * validaciones.h
 *
 *  Created on: 21 sep. 2021
 *      Author: franc
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

/// @fn int verificarSiEsEntero(float)
/// @brief Verifico si un numero flotante es un entero, es decir 12.00(es un int), y 12.50 (es un float). Devuelvo un int para verificar.
/// @param flotanteRecibido A verificar si es int o float.
/// @return Retorna 1 si es entero y 0 si es un flotante
int verificarSiEsEntero(float flotanteRecibido);
/// @fn int verificarSiIngresoNumeros(int, int)
/// @brief Verifica si ingreso numeros, utilizando dos flags y devuelve un entero dependiendo de cual sea el caso correspondiente.
/// @param flagPrimerNumero
/// @param flagSegundoNumero
/// @return Retorna 1 si ingreso los dos numeros, 0 si no ingreso ninguno de los dos numeros, -1 no ingreso el segundo numero, -2 no ingreso el primer numero
int verificarSiIngresoNumeros(int flagPrimerNumero,int flagSegundoNumero);
/// @fn int validarMenu(int, int)
/// @brief Pedir al usuario que ingrese la opcion correspondiente, como parametro le paso los limites y retorno el entero que eligio. Por ej: Si elige 1, va al case 1.
/// @param limiteInferior
/// @param limiteSuperior
/// @return Retorna la opcion elegida por el usuario dentro de los limites.
int validarMenu(int limiteInferior,int limiteSuperior);
/// @fn int verificarSiEsCero(float)
/// @brief Verifico si el numero es cero.Devuelvo un int con una verificacion.
/// @param numero Flotante recibido.
/// @return Retorno 0 Si el flotante recibido es 0 y 1 si no es 0.
int verificarSiEsCero(float numero);




#endif /* VALIDACIONES_H_ */
