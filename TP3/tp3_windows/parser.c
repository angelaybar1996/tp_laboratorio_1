#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param pFile, puntero del archivo que se va a cargar en el linkedList
 * \param pArrayListEmployee puntero de la lista de empleados
 * \param auxId es el buffer donde se va a cargar en un principio el id obtenido del archivo
 * \param auxNombre es el buffer donde se va a cargar en un principio el nombre obtenido del archivo
 * \param auxHoras es el buffer donde se va a cargar en un principio las horas obtenido del archivo
 * \param auxSueldo es el buffer donde se va a cargar en un principio el sueldo obtenido del archivo
 * \return retorno -1(ERROR) 0 (EXITO)
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee,char auxId[],char auxNombre[],char auxHoras[],char auxSueldo[])
{

	Employee* auxEmpleado;
	int retorno=-1;

	do
	{
		if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxHoras,auxSueldo)==4)
		{
			auxEmpleado= employee_newParametrosTxt(auxId, auxNombre, auxHoras, auxSueldo);
			if(auxEmpleado!=NULL)
			{
				ll_add(pArrayListEmployee, auxEmpleado);
			}
		}

	}while(!feof(pFile));
	retorno=0;

    return retorno;
}

/** \brief Parsea los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param param pFile, puntero del archivo que se va a cargar en el linkedList
 * \param pArrayListEmployee puntero de la lista de empleados
 * \param auxEmpleado,puntero empleado donde se cargan los datos del archivo en un principio
 * \return retorno -1(ERROR) 0 (EXITO)
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee,Employee* auxEmpleado)
{
	int cant;
	int retorno=-1;

	do
	{
		auxEmpleado=employee_new();

		if(auxEmpleado!=NULL)
		{
			cant = fread(auxEmpleado,sizeof(Employee),1,pFile);
			if(cant<1)
			{
				break;
			}
			else
			{
				ll_add(pArrayListEmployee, auxEmpleado);
			}
		}

	}while(!feof(pFile));
	retorno=0;

    return retorno;
}



