/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "Controller.h"
#include "parser.h"
#include "utn.h"
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"


int main(void)
{
    int opcion;
    int nextId=1001;
    int flag=0;
    int flagBin=0;
    int auxId;
    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listaEmpleadosBin = ll_newLinkedList();
    LinkedList* subListaEmpleados = ll_newLinkedList();
    LinkedList* listaClonada = ll_newLinkedList();
    Employee* auxEmpleado;
    Employee* auxEmpleado2;
    Employee* auxEmpleado3;
    Employee* auxEmpleado4;
    int otroId;
    char auxNombre[50];
    float auxHoras;
    float auxSueldo;
    int indice;
    int index;
    int indiceMin;
    int indiceMax;

    if(listaEmpleados!=NULL)
    {
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
                 "\n10.Vaciar lista de empleados"
                 "\n11.Buscar el indice de un empleado en la lista"
                 "\n12.Verificar estado de la lista"
                 "\n13.Inserta un empleado en un indice especificado de la lista"
                 "\n14.Elimina un empleado en un indice especificado de la lista"
                 "\n15.Buscar un empleado en la lista"
                 "\n16.Verificar si todos los empleados de la lista binaria estan en la lista empleados texto"
                 "\n17.Crear una nueva lista de empleados a partir de la actual"
                 "\n18.Clonar lista de empleados"
                 "\n19.Salir\n\n"
                 "Ingrese opcion:",
                 "Opcion no valida",1,19,3)==0)
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
                                printf("\nHay %d empleados en la lista",ll_len(listaEmpleados));
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
                                printf("\nHay %d empleados en la lista",ll_len(listaEmpleados));
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
                                    printf("\nModificación empleado exitosa");
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
                    case 10:
                        if(!ll_clear(listaEmpleados))
                        {
                            printf("\nLa lista fue vaciada, ahora debe volver a cargarla");
                            flag=0;
                            flagBin=0;
                        }
                    break;
                     case 11:
                         if(!utn_getNumero(&otroId,"\nIngrese id:","\nError, id no valido",1,nextId,3) &&
                            !utn_getCadena(auxNombre,50,"\nIngrese nombre:","\nError,nombre no valido",3) &&
                            !utn_getNumeroFlotante(&auxHoras,"\nIngrese horas trabajadas:","\nHoras no validas",1,1000000,3) &&
                            !utn_getNumeroFlotante(&auxSueldo,"\nIngrese sueldo:","\nError,sueldo no valido",1,1000000,3))
                         {
                            auxEmpleado=employee_newParametros(otroId, auxNombre, auxHoras,auxSueldo);
                            if(auxEmpleado!=NULL)
                            {
                                index=ll_indexOf(listaEmpleados,auxEmpleado);
                                printf("\nEl empleado se encuentra en el indice %d",index);
                            }
                         }
                    break;
                     case 12:
                         if(!ll_isEmpty(listaEmpleados))
                         {
                             printf("\nLa lista esta cargada!!");
                         }
                         else if(ll_isEmpty(listaEmpleados))
                         {
                             printf("\nLa lista esta vacia!!");
                         }

                        break;
                     case 13:
                         if(!utn_getCadena(auxNombre,50,"\nIngrese nombre:","\nError,nombre no valido",3) &&
                            !utn_getNumeroFlotante(&auxHoras,"\nIngrese horas trabajadas:","\nHoras no validas",1,1000000,3) &&
                            !utn_getNumeroFlotante(&auxSueldo,"\nIngrese sueldo:","\nError,sueldo no valido",1,1000000,3))
                         {
                            auxEmpleado2=employee_newParametros(nextId, auxNombre, auxHoras,auxSueldo);
                            if(auxEmpleado2!=NULL)
                            {
                                if(!utn_getNumero(&indice,"\nIngrese indice:","\nError,indice no valido",0,ll_len(listaEmpleados),3))
                                {
                                    if(!ll_push(listaEmpleados,indice,auxEmpleado2))
                                    {
                                        printf("\nEl nuevo empleado fue cargado en el indice indicado");
                                    }
                                }
                            }
                         }
                    break;
                     case 14:
                            if(!utn_getNumero(&indice,"\nIngrese indice:","\nError,indice no valido",0,ll_len(listaEmpleados),3))
                            {
                                auxEmpleado3=ll_pop(listaEmpleados,indice);
                                if(!employee_getId(auxEmpleado3,&otroId) &&
                                   !employee_getNombre(auxEmpleado3,auxNombre) &&
                                   !employee_getHorasTrabajadas(auxEmpleado3,&auxHoras) &&
                                   !employee_getSueldo(auxEmpleado3,&auxSueldo))
                                {
                                    printf("\nEl empleado ID:%d - Nombre: %s - Horas: %.2f - Sueldo: %.2f fue eliminado de la lista",otroId,auxNombre,auxHoras,auxSueldo);
                                }

                            }
                        break;
                     case 15:
                             if(!utn_getNumero(&otroId,"\nIngrese id:","\nError, id no valido",1,nextId,3) &&
                                !utn_getCadena(auxNombre,50,"\nIngrese nombre:","\nError,nombre no valido",3) &&
                                !utn_getNumeroFlotante(&auxHoras,"\nIngrese horas trabajadas:","\nHoras no validas",1,1000000,3) &&
                                !utn_getNumeroFlotante(&auxSueldo,"\nIngrese sueldo:","\nError,sueldo no valido",1,1000000,3))
                             {
                                auxEmpleado4=employee_newParametros(otroId, auxNombre, auxHoras,auxSueldo);
                                if(auxEmpleado4!=NULL)
                                {
                                    if(ll_contains(listaEmpleados,auxEmpleado))
                                    {
                                        printf("\nEl empleado se encuentra en la lista");
                                    }
                                    else
                                    {
                                        printf("\nEl empleado no se encuentra en la lista");
                                    }
                                }
                             }
                        break;
                    case 16:
                            if(!controller_loadFromBinary("data.bin",listaEmpleadosBin))
                            {
                                if(ll_containsAll(listaEmpleados,listaEmpleadosBin))
                                {
                                    printf("\nTodos los empleados estan en la lista");
                                }
                                else
                                {
                                    printf("\nFaltan empleados en la lista");
                                }
                            }
                         break;
                    case 17:
                        if(!utn_getNumero(&indiceMin,"\nIngrese indice"
                                                  "\nDesde:","\nError, no valido",0,ll_len(listaEmpleados),3) &&
                           !utn_getNumero(&indiceMax,"\nHasta:","\nError, no valido",0,ll_len(listaEmpleados),3))
                        {
                            subListaEmpleados=ll_subList(listaEmpleados,indiceMin,indiceMax);
                            controller_ListEmployee(subListaEmpleados);
                        }

                        break;
                    case 18:
                        listaClonada = ll_clone(listaEmpleados);
                        printf("\nLista clonada con exito");

                        break;
                }
           }
        }while(opcion !=19);
    }
    ll_deleteLinkedList(listaEmpleados);
    ll_deleteLinkedList(listaEmpleadosBin);
    ll_deleteLinkedList(subListaEmpleados);
    ll_deleteLinkedList(listaClonada);

    return 0;
}

/*
   //startTesting(1);  // ll_newLinkedList
   //startTesting(2);  // ll_len
   //startTesting(3);  // getNode - test_getNode
   //startTesting(4);  // addNode - test_addNode
    //startTesting(5);  // ll_add
    //startTesting(6);  // ll_get
    //startTesting(7);  // ll_set
    //startTesting(8);  // ll_remove
    //startTesting(9);  // ll_clear
    //startTesting(10); // ll_deleteLinkedList
    //startTesting(11); // ll_indexOf
    //startTesting(12); // ll_isEmpty
    //startTesting(13); // ll_push
    //startTesting(14); // ll_pop
    //startTesting(15); // ll_contains
    //startTesting(16); // ll_containsAll
    //startTesting(17); // ll_subList
    //startTesting(18); // ll_clone
    //startTesting(19); // ll_sort
*/



































