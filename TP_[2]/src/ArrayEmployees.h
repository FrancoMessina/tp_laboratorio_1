/*
 * ArrayEmployees.h
 *
 *  Created on: 15 oct. 2021
 *      Author: franc
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} typedef Employee;
/// @fn int initEmployees(Employee*, int)
/// @brief Incializam todos los Empleados en la flag isEmpty en 1 que es Cargado
/// @param list Lista de empleados
/// @param len  Largo de la lista
/// @return int Return(-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int initEmployees(Employee *list,int len);
/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int addEmployees(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee *list,int id,int len);
/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee *list,int id,int len);
/// @fn int buscarLibre(Employee*, int)
/// @brief Buscar posicion libre
/// @param list
/// @param len
/// @return -1 Si no hay indice vacio, 0 Si Ok.
int buscarLibre(Employee *list, int len);
/// @fn int modificarEmployee(Employee*, int)
/// @brief Modificar la opcion que eliga el usuario
/// @param list
/// @param len
/// @return Return 0 si Hay error en el largo o es NUL. 1 Si ok.
int modificarEmployee(Employee *list,int len);
/** \brief Sort the elements in the array of employees, the argument order
indicate ASCENDENTE or DESCENDENTE order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate ASCENDENTE - [0] indicate DESCENDENTE
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee *list,int order, int len);
/// @fn int contadorEmpleados(Employee*, int*, int)
/// @brief Cuenta la cantidad de empleados activos
/// @param lista
/// @param contadorEmpleados
/// @param len
/// @return int Return 0 Si hay error por el length or NULL pointer. 1 Si Ok.
int contadorEmpleados(Employee *lista,int *contadorEmpleados, int len);
/// @fn int acumuladorSueldos(Employee*, float*, int)
/// @brief Acumula el sueldo total de los empleados activos.
/// @param lista
/// @param acumuladorSueldos
/// @param len
/// @return Retorna 0 Si hay error en el length or NULL pointer. 1 Si Ok.
int acumuladorSueldos(Employee *lista,float *acumuladorSueldos,int len);
/// @fn int promedioSalarios(Employee*, float*, int)
/// @brief Promedio de salario de los empleados activos
/// @param lista
/// @param promedioSalarios
/// @param len
/// @return 0 Si hay error por el length or NULL pointer. 1 Si Ok.
int promedioSalarios(Employee *lista,float *promedioSalarios,int len);
/// @fn int cantSuperanSalarioProm(Employee[], int)
/// @brief Cantidad de personas que superan el salario promedio.
/// @param lista
/// @param len
/// @return 0 Si hay error en el length or NULL pointer. 1 Si Ok.
int cantSuperanSalarioProm(Employee lista[],int len);
/// @fn int mostrarTotalSalarios(Employee*, int)
/// @brief Mostrar el total de la suma de todos los salarios
/// @param lista
/// @param len
/// @return 0 Si hay error en el length or NULL pointer. 1 Si Ok.
int mostrarTotalSalarios(Employee *lista, int len);
/// @fn int mostrarPromSalarios(Employee*, int)
/// @brief Muestra el promedio de salarios de los empleados activos
/// @param lista
/// @param len
/// @return 0 Si hay error en el length o NULL pointer. 1 Si Ok.
int mostrarPromSalarios(Employee *lista, int len);
/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(Employee *lista, int len);
/// @fn void printEmployee(Employee)
/// @brief Muestra las caracteristicas de un empleado.
/// @param x
void printEmployee(Employee x);
/// @fn int sortEmployeeByLastName(Employee*, int, int)
/// @brief Ordena por Apellido y si son iguales desempate por sector
/// @param list
/// @param len
/// @param order
/// @return 0 Error length or NULL pointer . 1 Si Ok.
int sortEmployeeByLastName(Employee* list, int  len , int order);
/// @fn int sortEmployeeBySector(Employee*, int, int)
/// @brief Ordena por Sector y si son iguales desempate por Apellido
/// @param list
/// @param len
/// @param order
/// @return 0 Error length or NULL pointer . 1 Si Ok.
int sortEmployeeBySector(Employee* list, int  len , int order);
/// @fn int cargarEmployees(int*, char[], char[], float*, int*)
/// @brief  Carga todos los datos de un empleado
/// @param pId
/// @param name
/// @param lastName
/// @param salary
/// @param sector
/// @return 0 Error length or NULL pointer . 1 Si Ok.
int cargarEmployee(int *pId, char name[],char lastName[],float *salary,int *sector);
#endif /* ARRAYEMPLOYEES_H_ */
