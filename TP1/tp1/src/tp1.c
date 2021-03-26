/*
 ============================================================================
 Name        : tp1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(void)
{

	setbuf(stdout,NULL);

	int operandoUno;
	int operandoDos;
	int opcion;
	char salir;
	int flagA;
	int flagB;
	int flagC;
	char respuesta;
	int resultadoSuma;
	int resultadoResta;
	int resultadoMultiplicacion;
	float resultadoDivision;
	int retornoDivision;
	int retornoFactorial;
	int factorialUno;
	int factorialDos;

	salir='n';
	respuesta='n';
	flagA=0;
	flagB=0;
	flagC=0;

	do
	{
		system("cls");//limpia la pantalla
		printf("***MENU DE OPCIONES*** \n\n");

		printf("1.Ingrese el 1er operando \n");//opcion 1
		printf("2.Ingrese el 2do operando \n");//opcion 2
		printf("3.Calcular todas las operaciones \n");//opcion 3
		printf("4.Informar resultados \n");//opcion 4
		printf("5.Salir \n");

		printf("Ingrese opcion:");
		scanf("%d",&opcion);

		switch(opcion)
		{
		   case 1:
			  printf("1.Ingrese el 1er operando:");
			  scanf("%d",&operandoUno);
			  printf("A:%d \n",operandoUno);
			  system("pause");
			  flagA=1;
		   break;
		   case 2:
			   if(flagA==0)
			   {
				   printf("primero hay que ir a la opcion 1 \n");
				   system("pause");
			   }
			   else
			   {
				  printf("2.Ingrese el 2do operando:");
				  scanf("%d",&operandoDos);
				  printf("B:%d \n",operandoDos);
				  system("pause");
				  flagB=1;
			   }
		  break;
		  case 3:
			  if(flagA==0||flagB==0)
			  {
				  printf("primero hay que ir a la opcion 1 y despues a la opcion 2 \n");
				  system("pause");
			  }
			  else
			  {
				  flagC=1;
				  //aca van las funciones que calculan las operaciones
				  resultadoSuma=sumar(operandoUno,operandoDos);
				  resultadoResta=restar(operandoUno,operandoDos);
				  resultadoMultiplicacion=multiplicar(operandoUno,operandoDos);
				  retornoDivision=dividir(operandoUno,operandoDos,&resultadoDivision);
				  retornoFactorial=factorial(operandoUno,&factorialUno);
				  retornoFactorial=factorial(operandoDos,&factorialDos);

				  printf("TODAS LAS OPERACIONES FUERON CALCULADAS \n");
				  system("pause");
			  }
		  break;
		  case 4:
			  if(flagC==0)
			  {
				  printf("primero hay que pasar por la opcion 3 \n");
				  system("pause");
			  }
			  else
			  {
				  //el reseteo, para que vuelva a hacer todo de nuevo
				  flagA=0;
				  flagB=0;
				  flagC=0;
				  //aca muestro los resultados de la funcion
				  printf("El resultado de %d + %d es %d \n",operandoUno,operandoDos,resultadoSuma);
				  printf("El resultado de %d - %d es %d \n",operandoUno,operandoDos,resultadoResta);
				  printf("El resultado de %d * %d es %d \n",operandoUno,operandoDos,resultadoMultiplicacion);

				  if(retornoDivision==0)
				  {
					printf("El resultado de %d / %d es %.2f \n",operandoUno,operandoDos,resultadoDivision);
				  }
				  else
				  {
					  printf("No se puede dividir por cero \n");
				  }

				  if(retornoFactorial==0)
				  {
					  printf("El factorial de %d es %d \n",operandoUno,factorialUno);
					  printf("El factorial de %d es %d \n",operandoDos,factorialDos);
				  }
				  else
				  {
					  printf("no existe factorial de %d \n",factorialUno);
					  printf("no existe factorial de %d \n",factorialDos);
				  }
				  system("pause");
			  }
		  break;
		  case 5:
			  printf("Esta seguro que desea salir (s/n)?");
			  fflush(stdin);
			  scanf("%c",&respuesta);
			  if(respuesta=='s')
			  {
				  salir='s';
			  }
			  else
			  {
				  if(respuesta=='n')
				  {
					  system("pause");
				  }
				  else
				  {
					  printf("la letra no es valida \n");
					  system("pause");
				  }
			  }
		  break;
		  default:
			  printf("Error,la opcion no es valida \n");
			  system("pause");
		  break;

		}

	}while(salir=='n');






	return EXIT_SUCCESS;
}