#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
		Employee* pEmpAux = NULL;
	    int cant;
	    char buffer[4][128];
	    int todoOk = 0;
	    if(pFile != NULL)
	    {
	    	 todoOk = 1;
	         cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);//Lectura fantasma
	         do
	         {
	            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);

	            if(cant < 4)
	            {
	                break;
	            }

	            pEmpAux = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);

	            if(pEmpAux != NULL)
	            {
	                    ll_add(pArrayListEmployee,pEmpAux);

	            }
	        }while(!feof(pFile));
	    }
	    else
	    {
	        printf("Error abriendo el archivo\n");
	    }
	    fclose(pFile);
	    return todoOk;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	int cantidad; //Cantidad leida
	Employee* pEmployee;

	if(pFile != NULL)
	{
		do
		{
			pEmployee = employee_new();
			cantidad = fread(pEmployee,sizeof(Employee),1,pFile);
			if(pEmployee != NULL && cantidad == 1)
			{
				ll_add(pArrayListEmployee,pEmployee);
				todoOk = 1;
			}
		}
		while(!feof(pFile));

	}
	return todoOk;
}
