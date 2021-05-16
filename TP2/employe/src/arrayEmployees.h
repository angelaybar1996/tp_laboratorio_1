
#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#define TAM_NOMBRE 51
#define TAM_APELLIDO 51

typedef struct{

    int id;
    char name[TAM_NOMBRE];
    char lastName[TAM_APELLIDO];
    float salary;
    int sector;
    int isEmpty;

}Employee;

int altaEmpleado(Employee* list, int len,int* id);
int printEmployees(Employee* list, int len);
int mostrarEmpleado(Employee* unEmpleado);

int initEmployees(Employee* list, int len);
int addEmployees(Employee* list, int len,int id,char name[],char lastName[],float salary,int sector);
int findEmployeeById(Employee* list, int len, int id);
int removeEmployee(Employee* list, int len,int id);
int sortEmployees(Employee* list, int len,int order);

int menuModificar(Employee* list,int tam,int indice);
int menuInformes(Employee* lista,int tam);

int salariosPromedios(Employee* list, int len);

#endif /* ARRAYEMPLOYEES_H_ */
