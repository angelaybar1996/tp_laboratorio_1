#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"
#include "arrayEmployees.h"


/**
 * \brief Inicializa el array
 * \param  list Array de empleados a ser actualizados
 * \param len Limite del array de empleados
 * \return Retorna 0 (EXITO) -1 (ERROR)
 */
int initEmployees(Employee* list, int len)
{
    int retorno=-1;

    if(list!=NULL && len >0)
    {
        retorno=0;

        for(int i=0; i<len; i++)
        {
            list[i].isEmpty=1;
        }
    }
    return retorno;
}

/**
 * \brief Imprime el array de empleados
 * \param list Array de empleados a ser actualizados
 * \param len limite del array de empleados
 * \return Retorna 0 (EXITO) -1 (ERROR)
 */
int printEmployees(Employee* list, int len)
{
    int retorno=-1;

    printf("\nLista de Empleados\n");
    printf("-----------------------------------------------\n");
    printf("Id       Nombre   Apellido     Sueldo    Sector\n");
    printf("-----------------------------------------------\n");
    if(list!=NULL && len>0 )
    {
        retorno=0;
        for(int i=0; i<len; i++)
        {
            mostrarEmpleado(&list[i]);
        }
        printf("\n\n");
    }
    return retorno;
}

/**
 * \brief Imprime los datos de un empleado
 * \param unEmpleado Puntero al empleado que se busca imprimir
 * \return Retorna 0 (EXITO) -1 (ERROR)
 */
int mostrarEmpleado(Employee* unEmpleado)
{
    int retorno=-1;

    if(unEmpleado!=NULL && unEmpleado->isEmpty==0)
    {
        retorno=0;
      //printf("Id       Nombre   Apellido     Sueldo    Sector\n");
        printf("\n%d      %10s     %10s         %.2f      %d\n",
        	   unEmpleado->id,
               unEmpleado->name,
               unEmpleado->lastName,
               unEmpleado->salary,
               unEmpleado->sector);
    }

    return retorno;
}

/**
 * \brief Da de alta un empleado en una posicion del array
 * \param list array de empleados a ser actualizados
 * \param len Limite del array de empleados
 * \param id Puntero identificador a ser asignado al empleado
 * \return Retorna 0 (EXITO) -1 (ERROR)
 */
int altaEmpleado(Employee* list,int len ,int* id)
{
    int retorno=-1;
    Employee auxEmpleado;

    if(list!=NULL && len>=0 && id!=NULL)
    {
        printf("\nId: %d\n",*id);

		if(utn_getCadena(auxEmpleado.name,TAM_NOMBRE,"Ingrese nombre:","\nError,nombre no valido\n",2)==0 &&
		   utn_getCadena(auxEmpleado.lastName,TAM_APELLIDO,"Ingrese apellido:","\nError,apellido no valido\n",2)==0 &&
		   utn_getNumeroFlotante(&auxEmpleado.salary,"Ingrese sueldo:","\nError,sueldo no valido\n",1,1000000,2)==0 &&
		   utn_getNumero(&auxEmpleado.sector,"Ingrese sector [1-10]:","\nError,sector no valido\n",1,10,2)==0)
		{
			retorno=0;
			auxEmpleado.isEmpty=0;
			auxEmpleado.id=*id;
			addEmployees(list,len,auxEmpleado.id,auxEmpleado.name,auxEmpleado.lastName,auxEmpleado.salary,auxEmpleado.sector);
			(*id)++;
		}
    }
    return retorno;
}

/**
 * \brief busca la primer posicion vacia en un array de empleados y carga los datos en esa posicion
 * \param list array de empleados
 * \param len limite del array de empleados
 * \param name nombre a ser cargado en el array
 * \param lastName apellido  a ser cargado en el array
 * \param salary salario a ser cargado en el array
 * \param sector sector a ser cargado en el array
 * \return Retorna 0 (EXITO) -1 (ERROR)
 */
int addEmployees(Employee* list, int len,int id,char name[],char lastName[],float salary,int sector)
{
    int retorno=-1;
    if(list!=NULL && len>=0)
    {
    	retorno=0;
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty)
            {
                list[i].id=id;
                strcpy(list[i].name,name);
                strcpy(list[i].lastName,lastName);
                list[i].salary=salary;
                list[i].sector=sector;
                list[i].isEmpty=0;
                break;
            }
        }
    }
    return retorno;
}

/**
 * \brief busca un id en un array y devuelve la posicion en que se encuentra
 * \param list array de empleados
 * \param len limite del array de empleados
 * \param id el valor buscado
 * \return Retorna la posicion en que se encuentra el id ? -1 (ERROR)
 */
int findEmployeeById(Employee* list, int len, int id)
{
    int retorno=-1;
	int i;

	if(list!=NULL &&len>0 && id>=0 )
	{
		retorno=0;
		for(i=0;i<len;i++)
		{
			if(list[i].id==id && list[i].isEmpty==0)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Actualiza una posicion del array
 * \param  list array de empleados a ser actualizados
 * \param len limite del array de empleados
 * \param id Posicion a ser actualizada
 * \return Retorna 0 (EXITO) -1 (ERROR)
 */
int removeEmployee(Employee* list, int len,int id)
{
    int retorno=-1;

    if(list!=NULL && len>=0 && id >=0)
    {
        list[id].isEmpty=1;
        retorno=0;
    }
    return retorno;
}

/**
 * \brief Menu de opciones de los datos del empleado a modificar
 * \param  lista array de empleados a ser actualizados
 * \param tam limite del array de empleados
 * \param indice Posicion recibida
 * \return Retorna 0 (EXITO) -1 (ERROR)
 */
int menuModificar(Employee* list,int tam,int indice)
{
    int retorno=-1;
    int opcion;
    Employee auxEmpleado;

	if(list!=NULL &&tam>0 &&indice<tam && list[indice].isEmpty==0)
	{
	    do
        {
            if(utn_getNumero(&opcion,
                             "***Modificar datos del empleado***\n\n"
                             "\n1.Modificar nombre"
                             "\n2.Modificar apellido"
                             "\n3.Modificar salario"
                             "\n4.Modificar sector"
                             "\n5.Salir\n\n"
                             "Ingrese opcion:","\nError,opcion no valida\n",1,5,2)==0)
            {
                retorno=0;
                switch(opcion)
                {
                    case 1:
                        if(utn_getCadena(auxEmpleado.name,TAM_NOMBRE,
                                      "Ingrese nombre:",
                                      "\nError,nombre no valido\n",2)==0)
                        {
                            strcpy(list[indice].name,auxEmpleado.name);
                        }
                        break;
                    case 2:
                    	 if(utn_getCadena(auxEmpleado.lastName,TAM_APELLIDO,
									  "Ingrese apellido:",
									  "\nError,apellido no valido\n",2)==0)
						{
							strcpy(list[indice].lastName,auxEmpleado.lastName);
						}
                        break;
                    case 3:
                    	if(utn_getNumeroFlotante(&auxEmpleado.salary,
                    			"\nIngrese salario:",
                    	        "\nError,salario no valido\n",1,1000000,2)==0)
						{
						   list[indice].salary = auxEmpleado.salary;
						}
                        break;
                    case 4:
                    	if(utn_getNumero(&auxEmpleado.sector,
								"\nIngrese sector[1-10]:",
								"\nError,sector no valido\n",1,10,2)==0)
						{
							list[indice].sector = auxEmpleado.sector;
						}
                        break;
                 }
            }
        }while(opcion!=5);
	}
	return retorno;
}

/**
 * \brief Menu de opciones de los informes
 * \param  lista Array de empleados
 * \param tam limite del array de empleados
 * \return Retorna 0 (EXITO) -1 (ERROR)
 */
int menuInformes(Employee* lista,int tam)
{
    int retorno=-1;
    int opcion;
    int criterio;

    if(lista!=NULL &&tam>0)
	{
        do
        {
            if(utn_getNumero(&opcion,
                             "\n\n----------------------------------------\n"
                             "INFORMES"
                             "\n-------------------------------------------"
                             "\n1.Listado de empleados ordenados alfabeticamente por Apellido y Sector"
                             "\n2.Total y promedio de los salarios, y cuantos empleados superan el salario promedio"
                             "\n3.Salir\n\n"
                             "Ingrese opcion:","\nError,opcion no valida\n",1,3,2)==0)
            {
                retorno=0;
                switch(opcion)
                {
                    case 1:
                    	if(utn_getNumero(&criterio,
								 "Indique criterio\n"
                    			"----------------\n\n"
								 "\n1.ASCENDENTE"//A a Z
								 "\n2.DESCENDENTE"// Z a A
								 "\n3.SALIR\n\n"
								 "Ingrese opcion:","\nError,opcion no valida\n",1,3,2)==0)
                    	{
                    	sortEmployees(lista,tam,criterio);
                    	}
                        break;
                    case 2:
                    	salariosPromedios(lista,tam);
                        break;
                }
            }
        }while(opcion!=3);
	}
    return retorno;
}

 /**
  * \brief Ordenamiento de empleados por apellido y sector segun criterio
  * \param  list array de empleados a ser actualizados
  * \param len limite del array de empleados
  * \param order Criterio de ordenamiento de empleados
  * \return Retorna 0 (EXITO) -1 (ERROR)
  */
int sortEmployees(Employee* list, int len,int order)
{
    int retorno=-1;
    Employee auxEmpleado;

    if(list!=NULL &&len>0 && order>0 )
	{
        retorno=0;
        for(int i=0; i<len-1; i++)
        {
            for(int j=i+1; j<len; j++)
            {
                if(((order==1 && strcmp(list[i].lastName,list[j].lastName)>0) ||
                (strcmp(list[i].lastName,list[j].lastName)==0 && list[i].sector >list[j].sector))
                		||
                ((order==2 && strcmp(list[i].lastName,list[j].lastName)<0) ||
                (strcmp(list[i].lastName,list[j].lastName)==0 && list[i].sector < list[j].sector)))
                {
                    auxEmpleado=list[i];
                    list[i]=list[j];
                    list[j]=auxEmpleado;
                }

            }
        }
        printEmployees(list,len);
	}
    return retorno;
}

/**
  * \brief muestra el total y promedio de los salarios, y cuantos empleados superan el salario promedio
  * \param  list array de empleados a ser actualizados
  * \param len limite del array de empleados
  * \return Retorna 0 (EXITO) -1 (ERROR)
  */
int salariosPromedios(Employee* list, int len)
{
    int retorno=-1;
    float totalSalarios=0;
    float promedioSalarios=0;
    int numEmpleados=0;
    int cantEmpleados=0;

    if(list!=NULL &&len>0)
	{
        retorno=0;
        for(int i=0; i<len; i++)
        {
        	if(list[i].isEmpty==0)
        	{
        	  totalSalarios+=list[i].salary;
        	  numEmpleados++;
        	}
        }

        promedioSalarios=totalSalarios/numEmpleados;

        for(int j=0; j<len; j++)
		{
        	if(list[j].isEmpty==0 && list[j].salary >promedioSalarios)
        	{
        		cantEmpleados++;
        	}
		}

        printf("\nTOTAL SALARIOS: %.2f",totalSalarios);
        printf("\nSALARIO PROMEDIO: %.2f",promedioSalarios);
        printf("\nCANTIDAD DE EMPLEADOS QUE SUPERAN EL SALARIO PROMEDIO: %d",cantEmpleados);

	}
    return retorno;
}


