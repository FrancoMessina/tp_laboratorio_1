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
/// @fn int pedirOpcion(void)
/// @brief Pedir opciones del menu y retorna ese valor.
/// @return La opcion que eligio el usuario
int pedirOpcion(void);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int getIntFloat (float* pResultado);

int myGetsFloat(char* cadena, int longitud);


int validarEnteroFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);


int esNumericoFlotante(char str[]);

#endif /* INPUT_H_ */
