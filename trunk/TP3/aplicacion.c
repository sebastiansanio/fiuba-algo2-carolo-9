#include "pantalla.h"
#include "agenda.h"
#include <stdio.h>
#include <stdlib.h>
#include "aplicacion.h"


void imprimir_por_pantalla(void*arg)
{
    printf("\n%s \n",(char*)arg);
}

void agregar_numero(void*arg)
{
    char nombre[255];
    char telefono[255];
    printf("Ingrese datos del contacto\n");
    printf("Nombre:\n");
    scanf("%s",nombre);
    printf("Telefono:\n");
    scanf("%s",telefono);
    agenda_agregar((TAgenda*)arg,nombre,telefono);
}

void buscar_numero(void*arg)
{
    char nombre[255];
    char telefono[255];
    int i;
    printf("Ingrese nombre del contacto a buscar \n");
    scanf("%s",nombre);
    i=agenda_buscar(*(TAgenda*)arg,nombre,telefono);
    if (!i)
        printf("El numero del contacto es %s\n",telefono);
    else
        printf("Contacto no existe");
}

void eliminar_numero(void*arg)
{
    char nombre[255];
    printf("Ingrese nombre del contacto a eliminar\n");
    scanf("%s",nombre);
    agenda_borrar((TAgenda*)arg,nombre);
}

void exit_f(void*arg)
{
    agenda_destruir(((TExit*)arg)->agenda);
    Pantalla_Destruir(((TExit*)arg)->pantalla);
    exit(((TExit*)arg)->codigo_salida);
}
