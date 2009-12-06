#ifndef AGENDA_H_INCLUDED
#define AGENDA_H_INCLUDED
#include "arbol de busqueda.h"
#include <string.h>
#define LONG_NOMBRE 255
#define LONG_TEL 255

typedef struct{
    TAB_BUSQ arbol;
} TAgenda;

typedef struct{
    char nombre[LONG_NOMBRE];
    char telefono[LONG_TEL];
} TContacto;

void agenda_crear(TAgenda*agenda);

void agenda_destruir(TAgenda*agenda);

int agenda_agregar(TAgenda*agenda,char*nombre, char*telefono);

int agenda_buscar(TAgenda agenda,char*nombre,char*telefono);

void agenda_borrar(TAgenda*agenda,char*nombre);

#endif
