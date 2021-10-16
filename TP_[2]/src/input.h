/*
 * input.h
 *
 *  Created on: 15 oct. 2021
 *      Author: franc
 */

#ifndef INPUT_H_
#define INPUT_H_
/// @fn int ingresarString(char[], char[])
/// @brief Ingresar string y guardarlo en dato. En Mensaje lo que quiere ver el usuario
/// @param mensaje
/// @param dato
/// @return 0 Si hay error en el length o NULL pointer. 1 Si Ok.
int ingresarString(char mensaje[], char dato[]);
/// @fn int ingresarEntero(char[])
/// @brief Pide un numero Entero y lo retorna
/// @param mensaje
/// @return Retorna el numero ingresado por el usuario
int ingresarEntero(char mensaje[]);
/// @fn float ingresarFlotante(char[])
/// @brief Pide un numero Flotante y lo retorna
/// @param mensaje
/// @return Retorna el numero ingresado por el usuario
float ingresarFlotante(char mensaje[]);
/// @fn int validarRangoEntero(int, int, int)
/// @brief Validar rango de un numero entero con limites.
/// @param valor
/// @param limiteInferior
/// @param limiteSuperior
/// @return Retorna 0 si no esta en el rango. 1 Si esta en el rango.
int validarRangoEntero(int valor, int limiteInferior, int limiteSuperior);
/// @fn int stringPrimeroLetraMayuscula(char[])
/// @brief Pasa la primer letra de una palabra/palabras a mayuscula y todas las demas en miniscula
/// @param string
/// @return 0 Si hay error de length o NULL pointer. 1 Si Ok.
int stringPrimeroLetraMayuscula(char string[]);
#endif /* INPUT_H_ */
