/*
 * ArrayEmployees.c
 *
 *  Created on: 15 oct. 2021
 *      Author: franc
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "input.h"
#include "validaciones.h"
#define VACIO 1
#define CARGADO 0
#define SUELDO_MIN 500
#define SUELDO_MAX 1000000
#define TRUE 1
int initEmployees(Employee *list,int len)//Primer funcion
{
	int todoOk = -1;
	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len ; i++)
		{
			list[i].isEmpty = VACIO;
		}
		todoOk = 0;
	}
	return todoOk;
}
int addEmployees(Employee* list, int len, int id, char name[],char
		lastName[],float salary,int sector)
{
	int todoOk = -1 ;
	int indice;
	Employee auxEmployee;
	if(list != NULL && name != NULL && lastName != NULL && len > 0)
	{
		indice = buscarLibre(list,len);
		if(indice == -1)
		{
			printf("Error\n");
		}
		else
		{
			auxEmployee.id = id;
			strncpy(auxEmployee.name,name,sizeof(auxEmployee.name));
			strncpy(auxEmployee.lastName,lastName,sizeof(auxEmployee.lastName));
			auxEmployee.salary = salary;
			auxEmployee.sector = sector;
			auxEmployee.isEmpty = CARGADO;
			list[indice] = auxEmployee;
			todoOk = 0;
		}

	}
	return todoOk;
}
int buscarLibre(Employee *list, int len)
{
	int indice = -1;
	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len ; i++)
		{
			if(list[i].isEmpty == VACIO)
			{
				indice = i;
				break;
			}
		}
	}
	return indice;
}
int findEmployeeById(Employee *list,int id,int len)
{
	int indice = -1;
	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len ; i++)
		{
			if(id == list[i].id && list[i].isEmpty == CARGADO)
			{
				indice = i;
				break;
			}
		}
	}
	return indice;
}
int removeEmployee(Employee *list,int id,int len)
{
	int todoOk = -1;
	int indice;
	int opcion;
	if(list !=NULL && len > 0)
	{
		indice = findEmployeeById(list,id,len);
		if(indice == -1)
		{
			printf("Error \n");
		}
		else
		{
			printf(" Id       Name     	LastName     Salary    	Sector \n");
			printEmployee(list[indice]);
			opcion = ingresarEntero("[1]Si estas seguro de remover, [2] para cancelar");

			while(!validarRangoEntero(opcion , 1 , 2))
			{
				opcion = ingresarEntero("Error Ingresa [1] o [2].[1]Si estas seguro de remover, [2] para cancelar");
			}
			switch(opcion)
			{
			case 1:
				list[indice].isEmpty = VACIO;
				todoOk = 0;
				break;
			case 2:
				printf("Baja cancelada\n");
				break;
			}
		}

	}
	return todoOk;
}
int modificarEmployee(Employee *list,int len)
{
	int todoOk = 0;
	int indice;
	int opcion;
	int id;
	int flagYes;
	int flagNo;
	char seguir[101];
	char auxName[101];
	char auxLastName[101];
	float auxSalary;
	int auxSector;
	if(list != NULL && len >0)
	{
		id = ingresarEntero("Ingresa el ID que queres modificar");
		indice = findEmployeeById(list,id,len);
		if(indice == -1)
		{
			printf("El id: %d no esta registrado\n",id);
		}
		else
		{
			do
			{
				printf(" Id       Name     	LastName     Salary    	Sector \n");
				printEmployee(list[indice]);
				opcion = ingresarEntero("Opcion [1]Nombre [2]Apellido [3]Salario [4]Sector : ");

				while(!validarRangoEntero(opcion , 1 , 4))
				{
					opcion = ingresarEntero("Error Ingresa opcion valida. Opcion [1]Nombre [2]Apellido 3-Salario 4-Sector : ");
				}
				switch(opcion)
				{
				case 1:
					ingresarString("Ingresa el nombre : ",auxName);
					while(verificarSiContieneNumero(auxName) == TRUE || validarLargoString(auxName,3, 16))
					{
						ingresarString("Error(Ingresa solo caracteres),Min 3 letras Max 16. Ingresa el Nombre: ", auxName);
					}
					stringPrimerLetraMayuscula(auxName);
					strcpy(list[indice].name,auxName);
					break;
				case 2:
					ingresarString("Ingresa el Apellido : ",auxLastName);
					while(verificarSiContieneNumero(auxLastName) == TRUE|| validarLargoString(auxLastName,3, 16))
					{
						ingresarString("Error(Ingresa solo caracteres),Min 3 letras Max 16. Ingresa el Apellido: ", auxLastName);
					}
					stringPrimerLetraMayuscula(auxLastName);
					strcpy(list[indice].lastName,auxLastName);
					break;
				case 3:
					auxSalary = ingresarFlotante("Ingresar el salario : ");
					while(!verificarSueldo(auxSalary,SUELDO_MIN,SUELDO_MAX))
					{
						auxSalary = ingresarFlotante("Error(Salario Mayor a $500 y menor a $1.000.000). Ingresar el salario : ");
					}
					list[indice].salary = auxSalary;
					break;
				case 4:
					auxSector = ingresarEntero("Ingresa el sector : [1]Contabilidad [2] Finanzas [3] Recursos Humanos [4] Sistemas : ");
					while(!validarRangoEntero(auxSector, 1 , 4))
					{
						auxSector = ingresarEntero("Error. Ingresa el sector : [1]Contabilidad [2] Finanzas [3] Recursos Humanos [4] Sistemas : ");
					}
					list[indice].sector = auxSector;
					break;
				default:
					printf("Opcion incorrecta");
					break;

				}
				ingresarString("Quieres cambiar otro campo? Yes/No : ",seguir);
				stringPrimerLetraMayuscula(seguir);
				flagNo =  strcmp(seguir,"No");
				flagYes = strcmp(seguir,"Yes");
				while(flagNo != 0 && flagYes != 0)
				{
					ingresarString("Error Ingresar Yes/No.Quieres cambiar otro campo? Yes/No : ",seguir);
					stringPrimerLetraMayuscula(seguir);
					flagNo =  strcmp(seguir,"No");
					flagYes = strcmp(seguir,"Yes");
				}
			}while(strcmp(seguir, "No") != 0);
			todoOk = 1;
		}

	}
	return todoOk;
}
int sortEmployees(Employee *list,int order, int len)
{
	int todoOk = -1;
	int opcion;
	if(list != NULL && len > 0)
	{
		opcion = ingresarEntero("Queres ordenar por Apellido o Sector. [1]Apellido [2]Sector : ");
		while(!validarRangoEntero(opcion,1,2))
		{
			opcion = ingresarEntero("Error. Queres ordenar por Apellido o Sector. [1]Apellido [2]Sector : ");
		}
		switch(opcion)
		{
		case 1:
			sortEmployeeByLastName(list, len ,order);
			break;
		case 2:
			sortEmployeeBySector(list, len ,order);
			break;

		}
		todoOk = 0;
	}
	return todoOk;
}
int contadorEmpleados(Employee *lista,int *contadorEmpleados, int len)
{
	int todoOk = 0;
	int auxContador = 0;
	if(lista != NULL && len > 0)
	{
		for(int i = 0; i < len ; i++)
		{
			if(lista[i].isEmpty == CARGADO)
			{
				auxContador++;
			}
		}
		todoOk = 1 ;
	}
	*contadorEmpleados = auxContador;
	return todoOk;
}
int acumuladorSueldos(Employee *lista,float *acumuladorSueldos,int len)
{
	int todoOk = 0;
	float auxAcum = 0;
	if(lista != NULL && len > 0)
	{
		for(int i = 0; i < len ; i++)
		{
			if(lista[i].isEmpty == CARGADO)
			{
				auxAcum = auxAcum + lista[i].salary;
			}
		}
		todoOk = 1;
	}
	*acumuladorSueldos = auxAcum;
	return todoOk;
}
int promedioSalarios(Employee *lista,float *promedioSalarios,int len)
{
	int todoOk = 0;
	int contador;
	float acumulador;
	if(lista != NULL && len > 0)
	{
		contadorEmpleados(lista,&contador,len);
		acumuladorSueldos(lista,&acumulador,len);
		*promedioSalarios = acumulador/contador;
		todoOk = 1;
	}

	return todoOk;
}
int cantSuperanSalarioProm(Employee *lista,int len)
{
	int todoOk = 0;
	float promSalarios;
	int contador = 0;
	if(lista != NULL && len > 0)
	{

		promedioSalarios(lista,&promSalarios,len);
		for(int i = 0; i < len ; i++)
		{
			if(lista[i].isEmpty == CARGADO && lista[i].salary > promSalarios)
			{
				contador++;
			}
		}
		printf("Superan el salario promedio : %d\n",contador);

		todoOk = 1;
	}
	return todoOk;
}
int mostrarTotalSalarios(Employee *lista, int len)
{
	int todoOk = 0;
	float acum;
	if(lista != NULL && len > 0)
	{
		acumuladorSueldos(lista,&acum,len);
		todoOk = 1;
		printf("Total de salarios acumulados: %.2f\n",acum);
	}
	return todoOk;
}
int mostrarPromSalarios(Employee *lista, int len)
{
	int todoOk = 0;
	float promedio;
	if(lista != NULL && len > 0)
	{
		promedioSalarios(lista,&promedio,len);
		todoOk = 1;
		printf("Promedio de los salarios :  %.2f\n",promedio);
	}
	return todoOk;
}
void printEmployee(Employee x)
{
	printf(" %4d   %10s    %10s    $%5.2f    %4d \n",x.id,x.name,x.lastName,x.salary,x.sector);
}
int printEmployees(Employee *lista , int len)
{
	int todoOk = 0;
	if(lista != NULL && len > 0)
	{
		printf("-------------------------------------------------------------------------------------------\n");
		printf("           ***Lista de Empleados***         \n");
		printf("-------------------------------------------------------------------------------------------\n");
		printf(" Id       Name     	LastName     Salary    	Sector \n");
		printf("-------------------------------------------------------------------------------------------\n");
		for(int i = 0; i < len; i++)
		{
			if(lista[i].isEmpty == CARGADO)
			{
				printEmployee(lista[i]);
			}

		}
		todoOk = 1;
	}
	return todoOk;
}
int sortEmployeeByLastName(Employee* list, int  len , int order)
{
	int todoOk =0;
	int aux;
	Employee auxEmpleado;
	if(list != NULL && len > 0)
	{
		for(int i = 0 ; i < len - 1; i++)
		{
			for(int j = i + 1; j < len ; j++)
			{
				//Devuelve 1 Si J es menor que el primero.
				//Devuelve -1 Si J es mayor que el primero.
				aux = strcmp(list[i].lastName,list[j].lastName);
				if(list[j].isEmpty== CARGADO)
				{
					if((aux == 1 && order)|| (aux == -1 && !order)
							|| (aux == 0  && list[i].sector > list[j].sector && order) || (aux == 0 &&
									list[i].sector < list[j].sector && !order))
					{
						auxEmpleado = list[i];
						list[i] = list[j];
						list[j] = auxEmpleado;
					}

				}

			}
		}
		todoOk = 1;
	}
	return todoOk;
}
int sortEmployeeBySector(Employee* list, int  len , int order)
{
	int todoOk =0;
	int aux;
	Employee auxEmpleado;
	if(list != NULL && len > 0)
	{
		for(int i = 0 ; i < len - 1; i++)
		{
			for(int j = i + 1; j < len ; j++)
			{
				//Devuelve 1 Si J es menor que el primero.
				//Devuelve -1 Si J es mayor que el primero.
				// Devuelve 0 si son iguales
				aux = strcmp(list[i].lastName,list[j].lastName);
				if(list[j].isEmpty== CARGADO)
				{
					if((list[i].sector > list[j].sector && order) || (list[i].sector < list[j].sector && !order) || (aux == 1  && list[i].sector == list[j].sector && order) || (aux == -1  && list[i].sector == list[j].sector && !order))

					{
						auxEmpleado = list[i];
						list[i] = list[j];
						list[j] = auxEmpleado;
					}

				}

			}
		}
		todoOk = 1;
	}
	return todoOk;
}
int cargarEmployee(int *pId, char name[],char lastName[],float *salary,int *sector)
{
	int todoOk = 0;
	char auxName[101];
	char auxLastName[101];
	float auxSalary;
	int auxSector;
	if(name != NULL && lastName != NULL && pId != NULL && salary != NULL && sector != NULL)
	{
		(*pId)++;
		ingresarString("Ingresa el nombre : ", auxName);
		while(verificarSiContieneNumero(auxName) == TRUE || validarLargoString(auxName,3, 16))
		{
			ingresarString("Error(Ingresa solo caracteres),Min 3 letras Max 16. Ingresa el Nombre: ", auxName);
		}
		ingresarString("Ingresa el apellido: ", auxLastName);
		while(verificarSiContieneNumero(auxLastName) == TRUE || validarLargoString(auxLastName,3, 16))
		{
			ingresarString("Error(Ingresa solo caracteres),Min 3 letras Max 16. Ingresa el Apellido: ", auxLastName);
		}
		auxSalary = ingresarFlotante("Ingresa el salario del empleado : ");
		while(!verificarSueldo(auxSalary,SUELDO_MIN,SUELDO_MAX))
		{
			auxSalary = ingresarFlotante("Error(Salario Mayor a $500 y menor a $1.000.000). Ingresar el salario : ");
		}
		*salary = auxSalary;
		auxSector = ingresarEntero("Ingresa el sector : [1]Contabilidad [2] Finanzas [3] Recursos Humanos [4] Sistemas : ");
		while(!validarRangoEntero(auxSector, 1 , 4))
		{
			auxSector = ingresarEntero("Error. Ingresa el sector : [1]Contabilidad [2] Finanzas [3] Recursos Humanos [4] Sistemas : ");
		}
		*sector = auxSector;
		stringPrimerLetraMayuscula(auxName);
		stringPrimerLetraMayuscula(auxLastName);
		strcpy(name,auxName);
		strcpy(lastName,auxLastName);
		todoOk = 1;
	}
	return todoOk;
}
