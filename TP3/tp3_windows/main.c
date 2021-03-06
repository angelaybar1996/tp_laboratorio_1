#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);
    int opcion;
    int nextId=1001;
    int flag=0;
    int flagBin=0;
    int auxId;
    LinkedList* listaEmpleados = ll_newLinkedList();
    
    do{
    	if(utn_getNumero(&opcion,
			 "\n---------------------\n"
			 "EMPLEADOS\n"
			 "---------------------\n"
			 "\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)"
			 "\n2. Cargar los datos de los empleados desde el archivo data.bin (modo binario)"
			 "\n3. Alta de empleado"
			 "\n4. Modificar datos de empleado"
			 "\n5. Baja de empleado"
			 "\n6. Listar empleados"
			 "\n7. Ordenar empleados"
			 "\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto)"
    		 "\n9. Guardar los datos de los empleados en el archivo data.bin (modo binario)"                                                                      
			 "\n10.Salir\n\n"
			 "Ingrese opcion:",
			 "Opcion no valida",1,10,3)==0)
       {
			switch(opcion)
			{
				case 1:
					if(flagBin==0)
					{
						if(!controller_loadFromText("data.csv",listaEmpleados))
						{
							buscarMayorId(listaEmpleados,&nextId);
							printf("\nDatos cargados del archivo texto exitosamente");
						}
						flag=1;
					}
					else
					{
						printf("\nLos datos ya fueron cargados del archivo binario");
					}
					
				break;
				case 2:
					if(flag==0)
					{
						if(!controller_loadFromBinary("data.bin",listaEmpleados))
						{
							printf("\nDatos cargados del archivo binario exitosamente");
							buscarMayorId(listaEmpleados,&nextId);
							flagBin=1;
						}
						else
						{
							printf("\nEl archivo binario no existe");
						}
					}
					else
					{
						printf("\nLos datos ya fueron cargados del archivo texto");
					}
			   break;
				case 3:
					if( (flag!=0 && flagBin==0) || (flag==0 && flagBin!=0) )
					{
						if(!controller_addEmployee(listaEmpleados,&nextId))
						{
							printf("\nAlta empleado exitosa");
						}
					}
					else
					{
						printf("\nPrimero debe cargar los datos de los empleados");
					}
				   
			   break;
				case 4:
					if((flag!=0 && flagBin==0) || (flag==0 && flagBin!=0))
					{
						controller_ListEmployee(listaEmpleados);
						if(!utn_getNumero(&auxId,"\nIngrese el id del empleado que desea modificar:","\nError,id no valido",1,nextId,3))
						{
							if(!controller_editEmployee(listaEmpleados,auxId))
							{
								printf("\nModificaci?n empleado exitosa");
							}
						}	
					}
					else
					{
						printf("\nPrimero debe cargar los datos de los empleados");
					}
			   break;
				case 5:
					if((flag!=0 && flagBin==0) || (flag==0 && flagBin!=0))
					{
						controller_ListEmployee(listaEmpleados);
						if(!utn_getNumero(&auxId,"\nIngrese el id del empleado que desea eliminar:","\nError,id no valido",1,nextId,3))
						{
							if(!controller_removeEmployee(listaEmpleados,auxId))
							{
								printf("\nBaja empleado exitosa");
							}
						}	
					}
					else
					{
						printf("\nPrimero debe cargar los datos de los empleados");
					}
			   break;
				case 6:
					if((flag!=0 && flagBin==0) || (flag==0 && flagBin!=0))
					{
						controller_ListEmployee(listaEmpleados);
					}
					else
					{
						printf("\nPrimero debe cargar los datos de los empleados");
					}
			   break;
				case 7:
					if((flag!=0 && flagBin==0) || (flag==0 && flagBin!=0))
					{
						if(!controller_sortEmployee(listaEmpleados))
						{
							printf("\nOrdenamiento empleado exitosa");
						}
					}
					else
					{
						printf("\nPrimero debe cargar los datos de los empleados");
					}
			   break;
				case 8:
					if((flag!=0 && flagBin==0) || (flag==0 && flagBin!=0))
					{
						if(!controller_saveAsText("data.csv",listaEmpleados))
						{
							printf("\nDatos guardados en archivo de texto exitosamente");
						}
					}
					else
					{
						printf("\nPrimero debe cargar los datos de los empleados");
					}
			   break;
				case 9:
					if((flag!=0 && flagBin==0) || (flag==0 && flagBin!=0))
					{
						if(!controller_saveAsBinary("data.bin",listaEmpleados))
						{
							printf("\nDatos guardados en archivo binario exitosamente");
						}
					}
					else
					{
						printf("\nPrimero debe cargar los datos de los empleados");
					}
			   break;      
			}
       }
    }while(opcion != 10);
    
     ll_deleteLinkedList(listaEmpleados);
    
    return 0;
}

