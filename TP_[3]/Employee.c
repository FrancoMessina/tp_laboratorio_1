#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Employee.h"


Employee* employee_new()//Devuelve un puntero a empleado
{

	Employee* nuevoEmpleado =  (Employee*)malloc(sizeof(Employee));
	//Estamos encapsulando esta llamada a la funcion que hace malloc que pide un
	//empleado y que lo castea
    //Lo encapsulo dentro esta funcion. Entonces ahora si quiero creer un empleado
    //Hago : eEmpleado* pEmp = newEmpleado();
    if(nuevoEmpleado != NULL )
    {
        nuevoEmpleado->id = 0;
        strcpy(nuevoEmpleado->nombre," ");
        nuevoEmpleado->horasTrabajadas = 0;
        nuevoEmpleado->sueldo = 0;
    }
    return nuevoEmpleado;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* pEmployee = employee_new();
	    if(pEmployee != NULL)
	    {
	        if(!( employee_setId(pEmployee,atoi(idStr) )
	           && employee_setNombre(pEmployee,nombreStr)
	           && employee_setHorasTrabajadas(pEmployee,atoi(horasTrabajadasStr))
	           && employee_setSueldo(pEmployee,atoi(sueldoStr)))){

	                free(pEmployee);
	                pEmployee = NULL;

	        }
	    }
	    return pEmployee;
}
int employee_setId(Employee* this,int id)
{

	int todoOk = 0;
	if(this != NULL && id > 0)
	{
		this->id = id;
		todoOk = 1;
	}
	return todoOk;
}
int employee_getId(Employee* this,int* id)
{
	int todoOk = 0;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		todoOk = 1;
	}
	return todoOk;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int todoOk = 0;
	if(this != NULL && this != NULL && strlen(nombre) > 3 && strlen(nombre) < 19)
	{
		strcpy(this->nombre,nombre);
		todoOk = 1;
	}
	return todoOk;

}
int employee_getNombre(Employee* this,char* nombre)
{
	int todoOk = 0;
	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		todoOk = 1;
	}
	return todoOk;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int todoOk = 0;
	if(this != NULL && horasTrabajadas > 0)
	{
		this->horasTrabajadas = horasTrabajadas;
		todoOk = 1;
	}
	return todoOk;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int todoOk = 0;
	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		todoOk = 1;
	}
	return todoOk;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int todoOk = 0;
	if(this != NULL && sueldo > 0)
	{
		this->sueldo = sueldo;
		todoOk = 1;
	}
	return todoOk;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int todoOk = 0;
	if(this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;
		todoOk = 1;
	}
	return todoOk;
}
void employee_delete(Employee* this)
{
	if(this!= NULL)
	{
		free(this);
	}

}
