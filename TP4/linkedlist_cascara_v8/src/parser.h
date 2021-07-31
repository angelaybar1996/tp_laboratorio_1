#ifndef PARSER_H_
#define PARSER_H_
#include "Controller.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee,char auxId[],char auxNombre[],char auxHoras[],char auxSueldo[]);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee,Employee* auxEmpleado);

#endif /* PARSER_H_ */
