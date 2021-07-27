#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee,int* pId);
int controller_editEmployee(LinkedList* pArrayListEmployee,int auxId);
int controller_removeEmployee(LinkedList* pArrayListEmployee,int auxId);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

//funcion para averiguar el mayor id de la lista cargada
//para luego al dar de alta sea con un id correspondiente
int buscarMayorId(LinkedList* pArrayListEmployee,int* id);

#endif /* CONTROLLER_H_ */







