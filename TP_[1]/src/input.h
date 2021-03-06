/*
 * input.h
 *
 *  Created on: 21 sep. 2021
 *      Author: franc
 */

#ifndef INPUT_H_
#define INPUT_H_

/// @fn int ingresarNumero(char[], float*)
/// @brief Va a recibir una cadena de caracteres que la va a mostrar en pantalla, y puntero flotante para guardar el valor ingresado
/// @param mensaje El mensaje que quiero mostrar en pantalla
/// @param pNumero El puntero flotante.
/// @return 1 Si hizo todo correcto, 0 si existio algun problema con el puntero.
int ingresarNumeroFlotante(char mensaje[], float*pNumero);


#endif /* INPUT_H_ */
