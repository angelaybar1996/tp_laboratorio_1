/*
 ============================================================================
 Name        : employe.c
 Author      : Angel Aybar
 Version     :
 Copyright   :
 Description : TRABAJO PRACTICO 2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "utn.h"
#include "arrayEmployees.h"

#define TAM 1000

int main(void)
{
	setbuf(stdout,NULL);


	    Employee nomina[TAM];
	    int opcion;
	    int id=20000;
	    int auxId;
	    int auxIndice;
	    int decision;
	    int flag=0;

	    initEmployees(nomina,TAM);

	    do
	    {
	        if(utn_getNumero(&opcion,
	                         "\n-------------------\n"
	                         "ABM Empleado\n"
	                         "---------------------"
	                         "\n1.Alta Empleado"
	                         "\n2.Modificar Empleado"
	                         "\n3.Baja Empleado"
	        		         "\n4.Informes"
	                         "\n5.Salir\n\n"
	                         "Ingrese opcion:",
	                         "Opcion no valida",1,5,3)==0)
	        {
	            switch(opcion)
	            {
	                case 1:
	                    if(altaEmpleado(nomina,TAM,&id)==0)
	                    {
	                        system("cls");
	                        printf("Alta empleado exitosa\n");
	                        flag=1;
	                        system("pause");
	                    }
	                    else
	                    {
	                        system("cls");
	                        printf("No hay lugar\n");
	                        system("pause");
	                    }
	                    break;
	                case 2:
	                	if(flag)
	                	{
							printEmployees(nomina,TAM);
							if(utn_getNumero(&auxId,
											 "\nIngrese id del empleado a modificar",
											 "\nError, id no valido",20000,id,1)==0)
							{
								auxIndice=findEmployeeById(nomina,TAM,auxId);
								if(auxIndice>=0 && mostrarEmpleado(&nomina[auxIndice])==0)
								{
									if(utn_getNumero(&decision,
													 "Desea modificarlo?\n"
													 "\n1.[si]\n"
													 "\n2.[no]\n",
													 "Opcion no valida",1,2,1)==0)
									{
										if(decision==1 &&
												menuModificar(nomina,TAM,auxIndice)==0)
										{
											system("cls");
											printf("\nModificacion realizada con exito\n");
											system("pause");
										}
										else
										{
											system("cls");
											printf("\nModificacion cancelada\n");
											system("pause");
										}
									}
								}
							}
	                	}
	                	else
	                	{
	                		system("cls");
	                		printf("Debe dar de alta un empleado antes de entrar a esta opcion\n");
	                		system("pause");
	                	}

	                    break;
	                case 3:
	                	if(flag)
	                	{
							printEmployees(nomina,TAM);
							if(utn_getNumero(&auxId,
											 "\nIngrese ID del empleado a eliminar",
											 "\nError, ID no valido",20000,id,1)==0)
							{
								auxIndice=findEmployeeById(nomina,TAM,auxId);
								if(auxIndice>=0 && mostrarEmpleado(&nomina[auxIndice])==0)
								{
									if(utn_getNumero(&decision,
													 "Desea eliminarlo?\n"
													 "\n1.[si]\n"
													 "\n2.[no]\n",
													 "Opcion no valida",1,2,1)==0)
									{
										if(decision==1 &&
												removeEmployee(nomina,TAM,auxIndice)==0)
										{
											system("cls");
											printf("\nBaja realizada con exito\n");
											system("pause");
										}
										else
										{
											system("cls");
											printf("\nDar de baja cancelada\n");
											system("pause");
										}
									}
								}
							}
	                	}
	                	else
	                	{
	                		system("cls");
							printf("Debe dar de alta un empleado antes de entrar a esta opcion\n");
							system("pause");
	                	}
	                    break;
	                case 4:
	                	if(flag)
	                	{
	                		system("cls");
							menuInformes(nomina,TAM);
							system("pause");
	                	}
	                	else
	                	{
	                		system("cls");
							printf("Debe dar de alta un empleado antes de entrar a esta opcion\n");
							system("pause");
	                	}
	                    break;
	            }
	        }
	    }while(opcion!=5);


	return EXIT_SUCCESS;
}
