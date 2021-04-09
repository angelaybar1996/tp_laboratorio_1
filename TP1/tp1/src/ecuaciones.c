/*
 * ecuaciones.c
 *
 *  Created on: 8 abr. 2021
 *      Author: RYZEN 20
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/**
 * \brief realiza la suma de dos parametros
 * \param operadoUno es el primer numero que recibe
 * \param operadorDos es el segundo numero que recibe
 * \return retorno el resultado
 */
int sumar(int operadorUno,int operadorDos)
{
    int resultado;
    resultado=operadorUno+operadorDos;

    return resultado;
}

/**
 * \brief realiza la resta de dos numeros
 * \param operadoUno es el primer numero que recibe
 * \param operadoDos es el segundo numero que recibe
 * \return devuelve el resultado de la resta
 */
int restar(int operadorUno,int operadorDos)
{
    int resultado;
    resultado=operadorUno-operadorDos;

    return resultado;
}

/**
 * \brief realiza la multiplicacion de dos numeros
 * \param operadorUno es el primer numero que recibe
 * \param operadorDos es el segundo numero que recibe
 * \return devuelve el resultado de la multiplicacion
 */
int multiplicar(int operadorUno,int operadorDos)
{
    int resultado;
    resultado=operadorUno*operadorDos;

    return resultado;
}

/**
 * \ realiza la division de dos numeros
 * \param operadorUno es el primer numero que recibe
 * \param operadorDos es el segundo numero que recibe
 * \param pResultado es la direccion de memoria donde se va a cargar el resultado
 * \return devuelve -1 si no es posbible la division y 0 si es posible
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
 *\ brief Realiza el factorial de un numero
 * \param operador es el numero que recibe
 * \param pResultado es la direccion de memoria donde se va a mandar el resultado
 * \return devuelve -1 en caso de que no se pueda realizar el factorial y 0 en caso de que si se pueda
 */
int factorial(int operador,int* pResultado)
{
    int factorial;
    int retorno;

    factorial=1;
    retorno=-1;

    if(pResultado!= NULL && operador>=0 )
    {
    	retorno=0;

        if(operador==0)
        {
            *pResultado=factorial;
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
        }
    }

    return retorno;
}


