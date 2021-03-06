#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#define NOMBRE_TAM 128
typedef struct
{
    int id;
    char nombre[NOMBRE_TAM];
    float horasTrabajadas;
    float sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametrosTxt(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
Employee* employee_newParametros(int id,char* nombre,float horasTrabajadas,float sueldo);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);
int employee_setIdTxt(Employee* this,char* id);//texto
int employee_getIdTxt(Employee* this,char* id);//texto

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,float horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,float* horasTrabajadas);
int employee_setHorasTrabajadasTxt(Employee* this,char* horasTrabajadas);//texto
int employee_getHorasTrabajadasTxt(Employee* this,char* horasTrabajadas);//texto

int employee_setSueldo(Employee* this,float sueldo);
int employee_getSueldo(Employee* this,float* sueldo);
int employee_setSueldoTxt(Employee* this,char* sueldo);//texto
int employee_getSueldoTxt(Employee* this,char* sueldo);//texto

int employeeCmpId(void* a, void* b);
int employeeCmpNombre(void* a, void* b);
int employeeCmpHoras(void* a, void* b);
int employeeCmpSueldo(void* a, void* b);

#endif // employee_H_INCLUDED
