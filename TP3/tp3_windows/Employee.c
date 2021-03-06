#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

static int isValidId(char* cadena);
static int isValidNombre(char* nombre,int longitud);
static int isValidHorasTrabajadas(char* cadena);
static int isValidSueldo(char* cadena);

/**
 * brief construye un empleado en memoria
 * return retorna el puntero al empleado creado
 */
Employee* employee_new()
{
	Employee* auxiliarP;
	auxiliarP=(Employee*)malloc(sizeof(Employee));
	return auxiliarP;
}

/**
 * brief carga los datos ingresados por parametros en un puntero Empleado
 * param idStr, id a cargar en el puntero Empleado
 * param nombreStr,nombre a cargar en el puntero Empleado
 * param horasTrabajadasStr,horasTrabajadas a cargar en el puntero Empleado
 * param sueldoStr, sueldo a cargar en el puntero Empleado
 * return retorno el puntero de Empleado cargado
 */
Employee* employee_newParametrosTxt(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee* punteroEmpleado;
	punteroEmpleado=employee_new();

		if(punteroEmpleado!=NULL && idStr!=NULL && nombreStr !=NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
		{
			if(employee_setIdTxt(punteroEmpleado,idStr)==-1 ||
			   employee_setNombre(punteroEmpleado, nombreStr)==-1 ||
			   employee_setHorasTrabajadasTxt(punteroEmpleado, horasTrabajadasStr)==-1 ||
			   employee_setSueldoTxt(punteroEmpleado, sueldoStr)==-1 )
			 {
				employee_delete(punteroEmpleado);
				punteroEmpleado=NULL;
			 }

		}
		return punteroEmpleado;
}

/**
 * brief carga los datos ingresados por parametros en un puntero Empleado
 * param nombre,nombre a cargar en el puntero Empleado
 * param horasTrabajadas,horasTrabajadas a cargar en el puntero Empleado
 * param id, id a cargar en el puntero Empleado
 * param sueldo,sueldo a cargar en el puntero Empleado
 * return retorno el puntero de alumno cargado
 */
Employee* employee_newParametros(int id,char* nombre,float horasTrabajadas,float sueldo)
{
	Employee* punteroEmpleado;
	punteroEmpleado=employee_new();

	if(punteroEmpleado!=NULL && id>=0 && nombre!=NULL && horasTrabajadas>0 && sueldo>0)
	{
		if(employee_setId(punteroEmpleado,id)==-1 ||
		   employee_setNombre(punteroEmpleado, nombre)==-1 ||
		   employee_setHorasTrabajadas(punteroEmpleado, horasTrabajadas)==-1 ||
		   employee_setSueldo(punteroEmpleado, sueldo)==-1 )
		 {
			employee_delete(punteroEmpleado);
			punteroEmpleado=NULL;
		 }

	}
	return punteroEmpleado;
}

/**
 * brief libera un alumno de la memoria
 */
void employee_delete(Employee* this)
{
	if(this!=NULL)
	{
		free(this);
	}
}

/**
 * brief recibe un id  lo verifica y lo cargar en el punteroEmpleado
 * param this, es un punteroEmpleado
 * param id, es el id a agregar y validar
 * return retorno -1 (ERROR) 0 (EXITO)
 */
int employee_setId(Employee* this,int id)
{
	int retorno=-1;
	if(this!=NULL && id>=0)
	{
		this->id=id;
		retorno=0;
	}
	return retorno;
}

/**
 * brief le asigna el valor del id del punteroEmpleado a otra variable recibida por parametro
 * param this, es un punteroEmpleado
 * param id,puntero cargado con el valor del id del PunteroEmpleado
 * return retorno -1 (ERROR) 0 (EXITO)
 */
int employee_getId(Employee* this,int* id)
{
	int retorno=-1;
	if(this!=NULL && id!=NULL)
	{
	   *id=this->id;
		retorno=0;
	}
	return retorno;
}

/**
 * brief recibe un id en texto lo verifica y lo cargar en el punteroEmpleado
 * param this, es un punteroEmpleado
 * param id, es el id a agregar y validar
 * return retorno -1 (ERROR) 0 (EXITO)
 */
int employee_setIdTxt(Employee* this,char* id)
{
	int retorno=-1;
	if(this!=NULL && id!=NULL)
	{
		if(isValidId(id))
		{
			this->id=atoi(id);
			retorno=0;
		}
	}
	return retorno;
}

/**
 * brief le asigna el valor del id del punteroEmpleado a otra variable recibida por parametro
 * param this, es un punteroEmpleado
 * param id,puntero cargado con el valor del id del PunteroEmpleado
 * return retorno -1 (ERROR) 0 (EXITO)
 */
int employee_getIdTxt(Employee* this,char* id)
{
	int retorno=-1;
	if(this!=NULL && id!=NULL)
	{
       sprintf(id,"%d",this->id);
		retorno=0;
	}
	return retorno;
}

/**
 * brief recibe un nombre lo verifica y lo cargar en el punteroEmpleado
 * param this, es un punteroEmpleado
 * param nombre, es el nombre a agregar y validar
 * return retorno -1 (ERROR) 0 (EXITO)
 */
int employee_setNombre(Employee* this,char* nombre)
{
	int retorno=-1;
	if(this!=NULL && nombre!=NULL)
	{
		if(isValidNombre(nombre,NOMBRE_TAM))
		{
			strcpy(this->nombre,nombre);
			retorno=0;
		}
	}
	return retorno;
}

/**
 * brief le asigna el valor del nombre del punteroEmpleado a otra variable recibida por parametro
 * param this, es un punteroEmpleado
 * param nombre,puntero cargado con el valor del nombre del PunteroEmpleado
 * return retorno -1 (ERROR) 0 (EXITO)
 */
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno=-1;
	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre,this->nombre);
		retorno=0;
	}
	return retorno;
}

/**
 * brief recibe horasTrabajadas,lo verifica y lo cargar en el punteroEmpleado
 * param this, es un punteroEmpleado
 * param horasTrabajadas, son las  horasTrabajadas a agregar y validar
 * return retorno -1 (ERROR) 0 (EXITO)
 */
int employee_setHorasTrabajadas(Employee* this,float horasTrabajadas)
{
	int retorno=-1;
	if(this!=NULL && horasTrabajadas>=0)
	{
		retorno=0;
		this->horasTrabajadas=horasTrabajadas;
	}
	return retorno;
}

/**
 * brief le asigna el valor de las horas trabajadas del punteroEmpleado a otra variable recibida por parametro
 * param this, es un punteroEmpleado
 * param horasTrabajadas,puntero cargado con el valor de las horas Trabajadas del PunteroEmpleado
 * return retorno -1 (ERROR) 0 (EXITO)
 */
int employee_getHorasTrabajadas(Employee* this,float* horasTrabajadas)
{
	int retorno=-1;
	if(this!=NULL && horasTrabajadas!=NULL)
	{
	   retorno=0;
	  *horasTrabajadas=this->horasTrabajadas;
	}
	return retorno;
}

/**
 * brief recibe horasTrabajadas en texto,lo verifica y lo cargar en el punteroEmpleado
 * param this, es un punteroEmpleado
 * param horasTrabajadas, horasTrabajadas a agregar y validar
 * return retorno -1 (ERROR) 0 (EXITO)
 */
int employee_setHorasTrabajadasTxt(Employee* this,char* horasTrabajadas)
{
	int retorno=-1;
	float auxHorasTrabajadas;
	if(this!=NULL && horasTrabajadas!=NULL)
	{
		if(isValidHorasTrabajadas(horasTrabajadas))
		{
			auxHorasTrabajadas= atof(horasTrabajadas);
			if(auxHorasTrabajadas>=0)
			{
				this->horasTrabajadas=auxHorasTrabajadas;
				retorno=0;
			}
		}
	}
	return retorno;
}

/**
 * brief le asigna el valor de las horas trabajadas del punteroEmpleado a otra variable recibida por parametro
 * param this, es un punteroEmpleado
 * param horasTrabajadas,puntero cargado con el valor de las horas Trabajadas del PunteroEmpleado
 * return retorno -1 (ERROR) 0 (EXITO)
 */
int employee_getHorasTrabajadasTxt(Employee* this,char* horasTrabajadas)
{
	int retorno=-1;
	if(this!=NULL && horasTrabajadas!=NULL)
	{
	   sprintf(horasTrabajadas,"%f",this->horasTrabajadas);
	   retorno=0;
	}
	return retorno;
}

/**
 * brief recibe un sueldo,lo verifica y lo cargar en el PunteroEmpleado
 * param this, es un PunteroEmpleado
 * param sueldo, es la altura a agregar y validar
 * return retorno -1 (ERROR) 0 (EXITO)
 */
int employee_setSueldo(Employee* this,float sueldo)
{
	int retorno=-1;
	if(this!=NULL && sueldo>=0)
	{
		retorno=0;
		this->sueldo=sueldo;
	}
	return retorno;
}

/**
 * brief le asigna el valor del sueldo del punteroEmpleado a otra variable recibida por parametro
 * param this, es un punteroEmpleado
 * param sueldo,puntero cargado con el valor del sueldo del PunteroEmpleado
 * return retorno -1 (ERROR) 0 (EXITO)
 */
int employee_getSueldo(Employee* this,float* sueldo)
{
	int retorno=-1;
	if(this!=NULL && sueldo!=NULL)
	{
	   retorno=0;
	  *sueldo=this->sueldo;
	}
	return retorno;
}

/**
 * brief recibe un sueldo en texto,lo verifica y lo carga en el PunteroEmpleado
 * param this, es un PunteroEmpleado
 * param sueldo, es el sueldo a agregar y validar
 * return retorno -1 (ERROR) 0 (EXITO)
 */
int employee_setSueldoTxt(Employee* this,char* sueldo)
{
	int retorno=-1;
	float auxSueldo;
	if(this!=NULL && sueldo!=NULL)
	{
		if(isValidSueldo(sueldo))
		{
			auxSueldo= atof(sueldo);
			if(auxSueldo>=0)
			{
				this->sueldo=auxSueldo;
				retorno=0;
			}
		}
	}
	return retorno;
}

/**
 * brief le asigna el valor del sueldo del punteroEmpleado a otra variable recibida por parametro
 * param this, es un punteroEmpleado
 * param sueldo,puntero cargado con el valor del sueldo del PunteroEmpleado
 * return retorno -1 (ERROR) 0 (EXITO)
 */
int employee_getSueldoTxt(Employee* this,char* sueldo)
{
	int retorno=-1;
	if(this!=NULL && sueldo!=NULL)
	{
	   sprintf(sueldo,"%f",this->sueldo);
		retorno=0;
	}
	return retorno;
}

/**
 * \brief Verifica si el nombre ingresado es un nombre valido
 * \param nombre Cadena de caracteres a ser analizada
 * \param longitud Es la longitud del array resultado
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 */
static int isValidNombre(char* nombre,int longitud)
{
	int i=0;
	int retorno = 1;

	if(nombre != NULL && longitud > 0)
	{
		for(i=0 ; nombre[i] != '\0' && i < longitud; i++)
		{
			if((nombre[i] < 'A' || nombre[i] > 'Z' ) && (nombre[i] < 'a' || nombre[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 *\brief verifica si la cadena ingresada es numerica entera
 *\param cadena, cadena de caracteres a ser analizada
 *\return retorna 1 si es verdadera y 0 si es falsa
 */
static int isValidId(char* cadena)
{
	int retorno=1;
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

/**
 *\brief verifica si la cadena ingresada es flotante
 *\param cadena, cadena de caracteres a ser analizada
 *\return retorna 1 si es verdadera y 0 si es falsa
 */
static int isValidHorasTrabajadas(char* cadena)
{
	int retorno=1;
	int i=0;
	int contadorPuntos=0;

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
				if(cadena[i]=='.' && contadorPuntos==0)
				{
					contadorPuntos++;
				}
				else
				{
					retorno=0;
				    break;
				}
			}
		}
	}
	return retorno;
}


/**
 *\brief verifica si la cadena ingresada es flotante
 *\param cadena, cadena de caracteres a ser analizada
 *\return retorna 1 si es verdadera y 0 si es falsa
 */
static int isValidSueldo(char* cadena)
{
	int retorno=1;
	int i=0;
	int contadorPuntos=0;

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
				if(cadena[i]=='.' && contadorPuntos==0)
				{
					contadorPuntos++;
				}
				else
				{
					retorno=0;
				    break;
				}
			}
		}
	}
	return retorno;
}

/** \brief Determina el orden del id
 *
 * \param a void* puntero a castear para que sea puntero eEmpleado
 * \param b void* puntero a castear para que sea puntero eEmpleado
 * \return retorna 0 si son iguales,1 si a>b y -1 si a<b
 *
 */
int employeeCmpId(void* a, void* b)
{
    int retorno=0;
    Employee* emp1;
    Employee* emp2;
    if(a!=NULL && b!=NULL)
    {
        emp1=( Employee*)a;
        emp2=( Employee*)b;

        if(emp1->id > emp2->id)
        {
            retorno=1;
        }
        else if(emp1->id < emp2->id)
        {
            retorno=-1;
        }
    }
    return retorno;
}

/** \brief Determina el orden del nombre
 *
 * \param a void* puntero a castear para que sea puntero eEmpleado
 * \param b void* puntero a castear para que sea puntero eEmpleado
 * \return retorna 0 si son iguales,1 si a>b y -1 si a<b
 *
 */
int employeeCmpNombre(void* a, void* b)
{
    int retorno=0;
    Employee* emp1;
    Employee* emp2;
    if(a!=NULL && b!=NULL)
    {
       emp1=(Employee*)a;//casteo
       emp2=(Employee*)b;//casteo

       retorno=strcmp(emp1->nombre,emp2->nombre);
    }
    return retorno;
}

/** \brief Determina el orden de las horas
 *
 * \param a void* puntero a castear para que sea puntero eEmpleado
 * \param b void* puntero a castear para que sea puntero eEmpleado
 * \return retorna 0 si son iguales,1 si a>b y -1 si a<b
 */
int employeeCmpHoras(void* a, void* b)
{
    int retorno=0;
    Employee* emp1;
    Employee* emp2;
    if(a!=NULL && b!=NULL)
    {
        emp1=( Employee*)a;
        emp2=( Employee*)b;

        if(emp1->horasTrabajadas > emp2->horasTrabajadas)
        {
            retorno=1;
        }
        else if(emp1->horasTrabajadas < emp2->horasTrabajadas)
        {
            retorno=-1;
        }
    }
    return retorno;
}

/** \brief Determina el orden del sueldo
 *
 * \param a void* puntero a castear para que sea puntero eEmpleado
 * \param b void* puntero a castear para que sea puntero eEmpleado
 * \return retorna 0 si son iguales,1 si a>b y -1 si a<b
 *
 */
int employeeCmpSueldo(void* a, void* b)
{
    int retorno=0;
    Employee* emp1;
    Employee* emp2;
    if(a!=NULL && b!=NULL)
    {
        emp1=( Employee*)a;
        emp2=( Employee*)b;

        if(emp1->sueldo > emp2->sueldo)
        {
            retorno=1;
        }
        else if(emp1->sueldo < emp2->sueldo)
        {
            retorno=-1;
        }
    }
    return retorno;
}



