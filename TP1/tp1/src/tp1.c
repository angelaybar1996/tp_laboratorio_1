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
#include "ecuaciones.h"

int main(void)
{
	setbuf(stdout,NULL);

	int operandoUno;
	int operandoDos;
	int validacion;
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
	int retornoFactorialUno;
	int retornoFactorialDos;
    int factorialUno;
	int factorialDos;

	salir='n';
	respuesta='n';
	flagA=0;
	flagB=0;
	flagC=0;

	do
	{
		opcion=menu(operandoUno,operandoDos,flagA,flagB);

		switch(opcion)
		{
		   case 1:

			  validacion=utn_getNumero(&operandoUno,"Ingrese el 1er operando:", "Error,debe ingresar un numero entero\n", -1000, 1000,100);

			  if(!validacion)
			  {
				  system("pause");
				  flagA=1;
			  }
		   break;
		   case 2:
			   if(!flagA)
			   {
				   printf("primero hay que ir a la opcion 1 \n\n");
				   system("pause");
			   }
			   else
			   {
				  validacion=utn_getNumero(&operandoDos,"Ingrese el 2do operando:", "Error,debe ingresar un numero entero \n", -1000, 1000, 100);
				  if(!validacion)
				  {
					  system("pause");
					  flagB=1;
				  }
			   }
		  break;
		  case 3:
			  if(flagA==0||flagB==0)
			  {
				  printf("primero hay que ir a la opcion 1 y despues a la opcion 2 \n\n");
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
				  retornoFactorialUno=factorial(operandoUno,&factorialUno);
				  retornoFactorialDos=factorial(operandoDos,&factorialDos);

				  printf("TODAS LAS OPERACIONES FUERON CALCULADAS \n\n");
				  system("pause");
			  }
		  break;
		  case 4:
			  if(!flagC)
			  {
				  printf("primero hay que pasar por la opcion 3 \n\n");
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

				  if(!retornoDivision)
				  {
					printf("El resultado de %d / %d es %.2f \n",operandoUno,operandoDos,resultadoDivision);
				  }
				  else
				  {
					  printf("No se puede dividir por cero \n");
				  }

				  if(!retornoFactorialUno)
				  {
					  printf("El factorial de %d es %d \n",operandoUno,factorialUno);
				  }
				  else
				  {
					  printf("No existe factorial de %d \n",operandoUno);
				  }

				  if(!retornoFactorialDos)
				  {
					  printf("El factorial de %d es %d \n",operandoDos,factorialDos);
				  }
				  else
				  {
					  printf("No existe factorial de %d\n",operandoDos);
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
			  fflush(stdin);
			  printf("Error,la opcion no es valida \n");
			  system("pause");
		  break;

		}

	}while(salir=='n');

	return EXIT_SUCCESS;
}
