/*
 * funciones.c
 *
 *  Created on: 25 mar. 2021
 *      Author: RYZEN 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int getInt(int* pResultado);
static int myGets(char* cadena,int longitud);
static int esNumerica(char* cadena);

/**
 * \brief Muestra el menu de opciones
 * \param num1 es el valor del operandoUno
 * \param num2 es el valor del operandoDos
 * \param flagNum1 es el valor del flag del operandoUno
 * \param flagNum2 es el valor del flag del operandoDos
 * \return devuelve la opcion elegida
 */
int menu(int num1,int num2,int flagNum1,int flagNum2)
{

	int opcion;

	if(flagNum1==0&&flagNum2==0)
	{
		system("cls");
		printf("***MENU CALCULADORA*** \n\n");
		printf("1.Ingrese el 1er operando (A=x)\n");
		printf("2.Ingrese el 2do operando (B=y)\n");
		printf("3.Calcular todas las operaciones \n");
		printf("4.Informar resultados \n");
		printf("5.Salir \n");

		printf("Ingrese opcion:");
		scanf("%d",&opcion);

	}
	else
	{
		if(flagNum1==1&&flagNum2==0)
		{
			system("cls");
			printf("***MENU CALCULADORA*** \n\n");
			printf("1.Ingrese el 1er operando (A=%d)\n",num1);
			printf("2.Ingrese el 2do operando (B=y)\n");
			printf("3.Calcular todas las operaciones \n");
			printf("4.Informar resultados \n");
			printf("5.Salir \n");

			printf("Ingrese opcion:");
			scanf("%d",&opcion);

		}
		else
		{
			system("cls");
			printf("***MENU CALCULADORA*** \n\n");
			printf("1.Ingrese el 1er operando (A=%d)\n",num1);
			printf("2.Ingrese el 2do operando (B=%d)\n",num2);
			printf("3.Calcular todas las operaciones \n");
			printf("4.Informar resultados \n");
			printf("5.Salir \n");

			printf("Ingrese opcion:");
			scanf("%d",&opcion);
		}
	}

	return opcion;
}

/**
 *\brief solicita un numero al usuario, luego de verificarlo devuelve una respuesta
 *\param pResultado, puntero al espacio de memoria donde se dejara el resultado de la funcion
 *\param mensaje, es el mensaje a ser mostrado
 *\param mensajeError, es el mensaje de error a ser mostrado cuando sea necesario
 *\param minimo, es el numero minimo a ser aceptado
 *\param maximo, es el numero maximo a ser aceptado
 *\param reintentos, es la cantidad de oportunidades que tiene el usuario de operar
 *\return retorna 0 si es un numero y  retorna -1 si no lo es
 */
int utn_getNumero(int* pResultado,char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno;
	retorno=-1;
	int buffer;

	if(pResultado!=  NULL && mensaje != NULL && mensajeError != NULL && minimo<=maximo && reintentos>=0)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);

			if(getInt(&buffer)==0 && buffer>=minimo && buffer<=maximo)
			{
				*pResultado=buffer;
				retorno=0;
				break;
			}
			reintentos--;
			printf("%s",mensajeError);

		}while(reintentos>=0);
	}
	return retorno;
}
/**
 *\brief verifica si la cadena ingresada es entera
 *\param pResultado, puntero al espacio de memoria donde se dejara el resultado de la funcion
 *\return retorna 0(Exito) y -1 (Error)
 */
static int getInt(int* pResultado)
{
	int retorno;
	retorno=-1;
	char buffer[4096];

	if(myGets(buffer,sizeof(buffer))==0 && esNumerica (buffer))
	{
		retorno=0;
		*pResultado=atoi(buffer);
	}
	return retorno;
}
/**
 * \brief Lee de stdin hasta que encuentra un '\n'(enter) o hasta que haya copiado en cadena un maximo de 'longitud-1' caracteres.
 * \param pResultado, puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud, define el tama?o de cadena
 * \return retorno 0 (EXITO) si se obtiene cadena , -1(ERROR) en caso contrario
 */
static int myGets(char* cadena,int longitud)
{
	int retorno;
	retorno=-1;

	if(cadena!=NULL && longitud>0 &&fgets(cadena,longitud,stdin)==cadena)//file gets//este lee el enter por eso se le hace este ajuste
	{
		fflush(stdin);
		if(cadena[strlen(cadena)-1]=='\n')
		{
			cadena[strlen(cadena)-1]= '\0';
		}
		retorno=0;
	}

	return retorno;
}
/**
 *\brief verifica si la cadena ingresada es numerica entera
 *\param cadena, cadena de caracteres a ser analizada
 *\return, retorna -1 si es verdadera y 0 si es falsa
 */
static int esNumerica(char* cadena)
{
	int retorno=-1;
	int i=0;

	if(cadena!=NULL && strlen(cadena)>0)
	{
		for(i=0;cadena[i]!='\0';i++)
		{
			if(i==0 && (cadena[i]=='-'||cadena[i]=='+'))
			{
				continue;
			}
			if(cadena[i]<'0'||cadena[i] >'9')
			{
				retorno=0;
				break;
			}

		}
	}
	return retorno;
}





