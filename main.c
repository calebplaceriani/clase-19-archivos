#include <stdio.h>
#include <stdlib.h>
#include "persona.h"
#define CANT_EMPLEADOS 10
#include <string.h>

int main()
{
    FILE *pArchivo;
    int i;
    Empleado* empleados[CANT_EMPLEADOS];

    char bufferEdad[50000];
    char bufferNombre[50000];
    char bufferApellido[50000];

    pArchivo=fopen("archivo.ext","r"); //siempre verificar que no devuelva NULL

    if(pArchivo!=NULL)
    {
        while(!feof(pArchivo))
        {
            strcpy(bufferApellido,"---------*---------");
            fscanf(pArchivo,"%[^,],%[^,],%[^\n]\n",bufferEdad,bufferNombre,bufferApellido);
        }
        fclose(pArchivo);
    }

    for(i=0;i<CANT_EMPLEADOS;i++)
    {

        empleados[i]=empleado_newParametros(bufferNombre,bufferApellido,bufferEdad);
        printf("nombre %s",empleados[i]->nombre);
    }

    for(i=0;i<CANT_EMPLEADOS;i++)
    {
        empleado_print((Empleado*)empleados);
    }

    return 0;
}
