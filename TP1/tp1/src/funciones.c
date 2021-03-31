/*
 * funciones.c
 *
 *  Created on: 25 mar. 2021
 *      Author: RYZEN 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * brief Muestra el menu de opciones
 * return devuelve la opcion elegida
 */
int menu()
{
	int opcion;

	system("cls");
	printf("***MENU DE OPCIONES*** \n\n");

	printf("1.Ingrese el 1er operando \n");
	printf("2.Ingrese el 2do operando \n");
	printf("3.Calcular todas las operaciones \n");
	printf("4.Informar resultados \n");
	printf("5.Salir \n");

	printf("Ingrese opcion:");
	scanf("%d",&opcion);

	return opcion;
}

/**
 * brief valida que el dato ingresado sea numerico
 * param pResultado, se carga en la direccion de memoria en numero ingresado
 * param mensaje, es el mensaje para ingresar numero
 * param mensajeError, es el mensaje que se ejecuta en caso de que no sea de tipo numerico
 * return devuelve el retorno -1 si no es numerico y 0 si es numerico
 */
int getNumero(int* pResultado, char* mensaje,char* mensajeError)
{
	int retorno;
	int auxiliar;
	int verifica;

	retorno=-1;

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL )
	{

		printf("%s",mensaje);
		verifica=scanf("%d",&auxiliar);
		if(verifica)
		{
				*pResultado=auxiliar;
				retorno=0;
		}
		else
		{
			fflush(stdin);
			printf("%s",mensajeError);
			system("pause");
		}
	}

	return retorno;
}

/**
 * brief realiza la suma de dos parametros
 * param operadoUno es el primer numero que recibe
 * param operadorDos es el segundo numero que recibe
 * return retorno el resultado
 */
int sumar(int operadorUno,int operadorDos)
{
    int resultado;
    resultado=operadorUno+operadorDos;

    return resultado;
}

/**
 * brief realiza la resta de dos numeros
 * param operadoUno es el primer numero que recibe
 * param operadoDos es el segundo numero que recibe
 * return devuelve el resultado de la resta
 */
int restar(int operadorUno,int operadorDos)
{
    int resultado;
    resultado=operadorUno-operadorDos;

    return resultado;
}

/**
 * brief realiza la multiplicacion de dos numeros
 * param operadorUno es el primer numero que recibe
 * param operadorDos es el segundo numero que recibe
 * return devuelve el resultado de la multiplicacion
 */
int multiplicar(int operadorUno,int operadorDos)
{
    int resultado;
    resultado=operadorUno*operadorDos;

    return resultado;
}

/**
 * brief realiza la division de dos numeros
 * param operadorUno es el primer numero que recibe
 * param operadorDos es el segundo numero que recibe
 * param pResultado es la direccion de memoria donde se va a cargar el resultado
 * return devuelve -1 si no es posbible la division y 0 si es posible
 */
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

/**
 * brief
 * param
 * param
 * param
 * return
 */
int factorial(int operador,int* pResultado,char * mensajeError)
{
    int factorial;
    int retorno;

    factorial=1;
    retorno=-1;

    if(pResultado!= NULL && operador>=0 && mensajeError!=NULL)
    {
        if(operador==0)
        {
            *pResultado=factorial;
            retorno=0;
        }
        else
        {
        	if(operador>0)
        	{
				 for(int i=1; i<=operador; i++)
				 {
					factorial=factorial*i;
				 }
			    *pResultado=factorial;
        	}
        	else
        	{
				fflush(stdin);
				printf("%s",mensajeError);
				system("pause");
        	}
        }
    }

    return retorno;
}




