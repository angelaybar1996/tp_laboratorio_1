/*
 * funciones.h
 *
 *  Created on: 25 mar. 2021
 *      Author: RYZEN 20
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

int menu();
int getInt(char mensaje[]);

int sumar(int operadorUno,int operadorDos);
int restar(int operadorUno,int operadorDos);
int multiplicar(int operadorUno,int operadorDos);
int dividir(int operadorUno,int operadorDos,float*pResultado);
int factorial(int operador,int* pResultado);

#endif /* FUNCIONES_H_ */
