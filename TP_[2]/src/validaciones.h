/*
 * validaciones.h
 *
 *  Created on: 16 oct. 2021
 *      Author: franc
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

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
int stringPrimerLetraMayuscula(char string[]);
/// @brief Validar el largo de un string si se supera el max o no se supera el min lo pide de vuelta.
/// @param string
/// @param mensaje
/// @param min
/// @param max
/// @return 0 Si hay error de length o NULL pointer. 1 Si Ok.
int validarLargoString(char string[],char mensaje [], int min , int max);
int verificarSueldo(float numero);
#endif /* VALIDACIONES_H_ */
