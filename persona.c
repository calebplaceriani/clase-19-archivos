#include <stdio.h>
#include <stdlib.h>
#include "persona.h"
#include <string.h>

static int isValidNombre(char* nombre);
static int isValidApellido(char* apellido);
static int isValidEdad(char* edad);

Empleado* empleado_new(void)
{
    return (Empleado*) malloc(sizeof(Empleado));
}

Empleado* empleado_newParametros(char* nombre,char* apellido,char* edad)
{
    Empleado* this = empleado_new();

    if( this == NULL
        || empleado_setNombre(this,nombre)
        || empleado_setApellido(this,apellido)
        || empleado_setEdad(this,edad) )//valido todo
    {
        empleado_delete(this);
        this = NULL;
    }

    return this;

}

void empleado_delete(Empleado* this)
{
    free(this);
}

int empleado_setNombre(Empleado* this,char* nombre)
{
    int retorno=-1;

    if(this != NULL && isValidNombre(nombre))
    {
        strcpy(this->nombre,nombre);
        retorno = 0;
    }


    return retorno;
}

int empleado_getNombre(Empleado* this,char* nombre)
{
    int retorno=-1;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        retorno = 0;
    }


    return retorno;
}

static int isValidNombre(char* nombre)
{
    return 1;
}

int empleado_compareNombre(void* thisA,void* thisB)
{
    Empleado* A = (Empleado*)thisA;
    Empleado* B = (Empleado*)thisB;

    return strcmp(A->nombre,B->nombre);
}

// --------- APELLIDO ---------

int empleado_setApellido(Empleado* this,char* apellido)
{
    int retorno=-1;

    if(this != NULL && isValidApellido(apellido))
    {
        strcpy(this->apellido,apellido);
        retorno = 0;
    }


    return retorno;
}


int empleado_getApellido(Empleado* this,char* apellido)
{
    int retorno=-1;

    if(this != NULL && apellido != NULL)
    {
        strcpy(apellido,this->apellido);
        retorno = 0;
    }


    return retorno;
}

static int isValidApellido(char* apellido)
{
    return 1;
}

// -----------EDAD-----------------

int empleado_setEdad(Empleado* this,char* edad)
{
    int retorno=-1;

    if(this != NULL && isValidEdad((char*)edad))
    {
        strcpy(this->edad,(char*)edad);
        retorno = 0;
    }


    return retorno;
}


int empleado_getEdad(Empleado* this,char* edad)
{
    int retorno=-1;

    if(this != NULL && edad != NULL)
    {
        strcpy(*edad,this->edad);
        retorno = 0;
    }


    return retorno;
}

static int isValidEdad(char* edad)
{
    return 1;
}

void empleado_print(Empleado* this)
{
    printf("\n%s - %s  - %s \n",this->nombre,this->apellido,this->edad);
}
