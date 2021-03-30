/*
 * funciones.c
 *
 *  Created on: 25 mar. 2021
 *      Author: RYZEN 20
 */
#include <stdio.h>
#include <stdlib.h>


int menu()
{
	int opcion;

	system("cls");//limpia la pantalla
	printf("***MENU DE OPCIONES*** \n\n");

	printf("1.Ingrese el 1er operando \n");//opcion 1
	printf("2.Ingrese el 2do operando \n");//opcion 2
	printf("3.Calcular todas las operaciones \n");//opcion 3
	printf("4.Informar resultados \n");//opcion 4
	printf("5.Salir \n");

	printf("Ingrese opcion:");
	scanf("%d",&opcion);

	return opcion;
}

int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}


int sumar(int operadorUno,int operadorDos)
{
    int resultado;
    resultado=operadorUno+operadorDos;

    return resultado;
}

int restar(int operadorUno,int operadorDos)
{
    int resultado;
    resultado=operadorUno-operadorDos;

    return resultado;
}

int multiplicar(int operadorUno,int operadorDos)
{
    int resultado;
    resultado=operadorUno*operadorDos;

    return resultado;
}

int dividir(int operadorUno,int operadorDos,float*pResultado)
{
    int retorno;
    float resultado;
    retorno=-1;

    if(pResultado!=NULL&&operadorDos!=0)
    {
        resultado=(float)operadorUno/operadorDos;
        (*pResultado)=resultado;
        retorno=0;
    }
    return retorno;
}

int factorial(int operador,int* pResultado)
{
    int factorial;
    int retorno;

    factorial=1;
    retorno=-1;

    if(pResultado!= NULL && operador>=0)
    {
        if(operador==0)
        {
            *pResultado=factorial;
        }
        else
        {
            for(int i=1; i<=operador; i++)
            {
                factorial=factorial*i;
            }
            *pResultado=factorial;
        }
        retorno=0;
    }

    return retorno;
}




