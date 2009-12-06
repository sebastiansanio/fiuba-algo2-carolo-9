#include "agenda.h"

int comparar(TContacto* contacto1,TContacto* contacto2)
{
    int i;
    i=(strcmp(contacto1->nombre,contacto2->nombre));
    return i;
}


void agenda_crear(TAgenda*agenda)
{
    AB_Busq_Crear(&(agenda->arbol),sizeof(TContacto),&comparar);
}

void agenda_destruir(TAgenda*agenda)
{
    AB_Busq_Destruir(&(agenda->arbol));
}

int agenda_agregar(TAgenda*agenda,char*nombre, char*telefono)
{
    TContacto contacto;
    strcpy(contacto.nombre,nombre);
    strcpy(contacto.telefono,telefono);
    return(AB_Busq_Insertar(&(agenda->arbol),&contacto));
}

int agenda_buscar(TAgenda agenda,char*nombre,char*telefono)
{
    TContacto contacto_a_buscar;
    TContacto contacto_encontrado;
    int i;
    strcpy(contacto_a_buscar.nombre,nombre);
    i=(AB_Busq_Buscar(&(agenda.arbol),&contacto_a_buscar,&contacto_encontrado));
    strcpy(telefono,contacto_encontrado.telefono);
    return i;
}

void agenda_borrar(TAgenda*agenda,char*nombre)
{
    TContacto contacto_a_borrar;
    strcpy(contacto_a_borrar.nombre,nombre);
    AB_Busq_Borrar(&(agenda->arbol),&contacto_a_borrar);
}


