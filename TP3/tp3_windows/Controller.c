#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "parser.h"



/**\brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 * \param path char* es el nombre del archivo
 * \param pArrayListEmployee LinkedList* el puntero de array de empleados
 * \return retorna 0 (EXITO) -1 (ERROR)
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{

	int retorno=-1;
	FILE* fpArchivo;
	char auxNombre[NOMBRE_TAM];
	char auxHoras[100];
	char auxId[100];
	char auxSueldo[100];

	if(pArrayListEmployee!=NULL && path!=NULL)
	{
		fpArchivo=fopen(path,"r");
		if(fpArchivo!=NULL)
		{
			retorno=0;
			parser_EmployeeFromText(fpArchivo, pArrayListEmployee, auxId, auxNombre, auxHoras, auxSueldo);
		}
		fclose(fpArchivo);
	}
	return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
 * \param path char* es el nombre del archivo
 * \param pArrayListEmployee LinkedList* el puntero de array de empleados
 * \return retorna 0 (EXITO) -1 (ERROR)
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	FILE* fpArchivo;
	Employee* auxEmpleado=NULL;

	if(pArrayListEmployee!=NULL && path!=NULL)
	{
		fpArchivo=fopen(path,"rb");

		if(fpArchivo!=NULL)
		{
			retorno=0;
			parser_EmployeeFromBinary(fpArchivo,pArrayListEmployee,auxEmpleado);

		}
		fclose(fpArchivo);
	}

	return retorno;
}

/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList* el puntero de array de empleados
 * \param pId, es el id inicial al dar del alta
 * \return retorna 0 (EXITO) -1 (ERROR)
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee,int* pId)
{
	int retorno=-1;
	Employee* auxEmpleado;
	char auxNombre[NOMBRE_TAM];
	float auxHorasTrabajadas;
	float auxSueldo;


	if(pArrayListEmployee!=NULL && pId!=NULL)
	{
		if(!utn_getCadena(auxNombre,NOMBRE_TAM,"\nIngrese nombre:","\nError,nombre no valido",2) &&
		   !utn_getNumeroFlotante(&auxHorasTrabajadas, "\nIngrese Horas trabajadas:", "\nError,horas no validas",1, 1000000, 2) &&
		   !utn_getNumeroFlotante(&auxSueldo, "\nIngrese Sueldo:", "\nError,sueldo no valido",1, 1000000, 2))
		{
			auxEmpleado=employee_newParametros(*pId, auxNombre, auxHorasTrabajadas, auxSueldo);
			if(auxEmpleado!=NULL)
			{
				ll_add(pArrayListEmployee, auxEmpleado);
				 (*pId)++;
				 retorno=0;
			}
		}
	}

	return retorno;
}

/** \brief Modifica datos de empleado
 *
 * \param pArrayListEmployee LinkedList* el puntero de array de empleados
 * \param auxId, es el id del empleado a ser modificados sus datos
 * \return retorna 0 (EXITO) -1 (ERROR)
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee, int auxId)
{
	int retorno=-1;
	int indiceModificar;
	Employee* auxEmpleado;
	int buffer;
	char auxNombre[NOMBRE_TAM];
	float auxHoras;
	float auxSueldo;



	if(pArrayListEmployee!=NULL && auxId>=0)
	{
		for(int i=0;i<ll_len(pArrayListEmployee);i++)
		{
			auxEmpleado=(Employee*)ll_get(pArrayListEmployee, i);
			employee_getId(auxEmpleado,&buffer);
			if(buffer==auxId)
			{
				indiceModificar=i;
				break;
			}
		}

		if(indiceModificar>=0)
		{
			if(!utn_getCadena(auxNombre,NOMBRE_TAM,"\nIngrese nombre:","\nError,nombre no valido",2) &&
			   !utn_getNumeroFlotante(&auxHoras, "\nIngrese horas trabajadas:", "\nError,horas  no valida",1, 1000000, 2) &&
			   !utn_getNumeroFlotante(&auxSueldo, "\nIngrese sueldo:", "\nError,sueldo  no valido",1, 1000000, 2) )
			{

				employee_setNombre(auxEmpleado, auxNombre);
				employee_setHorasTrabajadas(auxEmpleado, auxHoras);
				employee_setSueldo(auxEmpleado, auxSueldo);

			}
			ll_set(pArrayListEmployee, indiceModificar,(Employee*) auxEmpleado);
			retorno=0;
		}
	}
	return retorno;
}

/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList* el puntero de array de empleados
 * \param auxId, es el id del empleado a ser dado de baja
 * \return retorna 0 (EXITO) -1 (ERROR)
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee, int auxId)
{
	int retorno=-1;
	int indiceBorrar;
	Employee* auxEmpleado;
	int buffer;
	if(pArrayListEmployee!=NULL && auxId>=0)
	{
		for(int i=0;i<ll_len(pArrayListEmployee);i++)
		{
			auxEmpleado=(Employee*)ll_get(pArrayListEmployee, i);
			employee_getId(auxEmpleado,&buffer);
			if(buffer==auxId)
			{
				indiceBorrar=i;
				break;
			}
		}

		if(indiceBorrar>=0)
		{
			ll_remove(pArrayListEmployee, indiceBorrar);
		    retorno=0;
		}
	}

	return retorno;
}

/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList* el puntero de array de empleados
 * \return retorna 0 (EXITO) -1 (ERROR)
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int i;
	Employee* auxEmpleado;
	int auxId;
	char auxNombre[NOMBRE_TAM];
	float auxHoras;
	float auxSueldo;

	if(pArrayListEmployee!=NULL)
	{
		printf("\n----------LISTA EMPLEADOS-------------\n");
		for(i=0;i<ll_len(pArrayListEmployee);i++)
		{
			auxEmpleado=(Employee*)ll_get(pArrayListEmployee, i);

			if(!employee_getId(auxEmpleado,&auxId) &&
			   !employee_getNombre(auxEmpleado,auxNombre) &&
			   !employee_getHorasTrabajadas(auxEmpleado,&auxHoras) &&
			   !employee_getSueldo(auxEmpleado,&auxSueldo))
			{
				printf("ID: %d - Nombre: %s - Horas Trabajadas: %.2f - Sueldo: %.2f\n",auxId,auxNombre,auxHoras,auxSueldo);
			}
		}
		retorno=0;
	}

	return retorno;
}

/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList* el puntero de array de empleados
 * \return retorna 0 (EXITO) -1 (ERROR)
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int opcion;
    if(pArrayListEmployee!=NULL)
    {
    	if(!utn_getNumero(&opcion,
    			"\n1.Ordenar por id"
    			"\n2.Ordenar por nombre"
    			"\n3.Ordenar por horas trabajadas"
    			"\n4.Ordenar por sueldo"
    			"\nIngrese opcion:", "\nError,opcion no valida", 1, 4, 3))
    	{
    		switch(opcion)
    		{
    		case 1:
    			ll_sort(pArrayListEmployee, employeeCmpId, 1);
    			printf("\nLos empleados fueron ordenados ascendentemente por id ");
    		 break;
    		case 2:
    			ll_sort(pArrayListEmployee, employeeCmpNombre, 1);
    			printf("\nLos empleados fueron ordenados por nombre de la A a la Z");
    		 break;
    		case 3:
    			ll_sort(pArrayListEmployee, employeeCmpHoras, 0);
				printf("\nLos empleados fueron ordenados descendentemente por horas trabajadas");
    		 break;
    		case 4:
    			ll_sort(pArrayListEmployee, employeeCmpSueldo, 0);
				printf("\nLos empleados fueron ordenados descendentemente por sueldo");
    		 break;
    		}
    	}
    	retorno=0;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path nombre del archivo
 * \param pArrayListEmployee LinkedList*  el puntero de array de empleados
 * \return retorna 0 (EXITO) -1 (ERROR)
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int i;
	FILE* fpArchivo;
	Employee* auxEmpleado;

	int auxId;
	char auxNombre[NOMBRE_TAM];
	float auxHoras;
	float auxSueldo;


	if(pArrayListEmployee!=NULL && path!=NULL)
	{
		fpArchivo=fopen(path,"w");
		if(fpArchivo!=NULL)
		{
			retorno=0;
			for(i=0;i<ll_len(pArrayListEmployee);i++)
			{
				auxEmpleado=(Employee*)ll_get(pArrayListEmployee,i);

				if(!employee_getId(auxEmpleado,&auxId) &&
				   !employee_getNombre(auxEmpleado, auxNombre) &&
				   !employee_getHorasTrabajadas(auxEmpleado,&auxHoras) &&
				   !employee_getSueldo(auxEmpleado, & auxSueldo))
				{
					fprintf(fpArchivo,"%d,%s,%f,%f\n",auxId,auxNombre,auxHoras,auxSueldo);
				}
			}
			fclose(fpArchivo);
		}
	}

	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 *
 * \param path nombre del archivo
 * \param pArrayListEmployee LinkedList*  el puntero de array de empleados
 * \return retorna 0 (EXITO) -1 (ERROR)
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	FILE* fpArchivo;
	Employee* auxEmpleado;


	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		fpArchivo=fopen(path,"wb");
		if(fpArchivo ==NULL)
		{
			printf("\nNo se pudo abrir el archivo");
		}
		else
		{
			for(int i=0;i<ll_len(pArrayListEmployee);i++)
			{
				auxEmpleado=(Employee*)ll_get(pArrayListEmployee,i);
				fwrite(auxEmpleado,sizeof(Employee),1,fpArchivo);
			}
		}
		fclose(fpArchivo);
		retorno=0;
	}
	return retorno;
}


/** \brief Busca el id mas grande del pArrayListEmployee previamente cargado de un archivo
 *  y le suma 1 para que el siguiente id dado de alta sea continuo
 *
 * \param pArrayListEmployee LinkedList*  el puntero de array de empleados
 * \param id, es el id actual a ser actualizado
 * \return retorna 0 (EXITO) -1 (ERROR)
 *
 */
int buscarMayorId(LinkedList* pArrayListEmployee,int* id)
{
    int retorno=-1;
    Employee* auxEmp=NULL;
    int mayor;
    if(pArrayListEmployee!=NULL)
    {
        for(int i=0;i<ll_len(pArrayListEmployee);i++)
        {
            auxEmp=(Employee*)ll_get(pArrayListEmployee,i);
            if(i==0 || auxEmp->id > mayor)
            {
                employee_getId(auxEmp, &mayor);//mayor=auxEmp->id;
            }
        }
        *id=mayor+1;

        retorno=0;
    }
    return retorno;
}

