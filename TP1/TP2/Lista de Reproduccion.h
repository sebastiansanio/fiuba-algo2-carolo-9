#ifndef LISTA_DE_REPRODUCCION_H_INCLUDED
#define LISTA_DE_REPRODUCCION_H_INCLUDED
#include "Lista Doblemente Enlazada Circular.h"
#include "propiedades.h"
#include "diccionario.h"

typedef struct
{
TLista_DEC lista;
TDiccionario dicc_alias;
} TLista_Reproduccion; /* Lista de reproduccion */

int crear_Lista_Reproduccion(TLista_Reproduccion* listaReproduccion, char* nomArch);

int reproducir_Lista_Reproduccion(TLista_Reproduccion listaReproduccion, int cantidad);

int adelantar_Lista_Reproduccion(TLista_Reproduccion* listaReproduccion);

int retroceder_Lista_Reproduccion(TLista_Reproduccion* listaReproduccion);

int ordenar_Lista_Reproduccion(TLista_Reproduccion* listaReproduccion, char* orden);

int guardar_Lista_Reproduccion(TLista_Reproduccion* listaReproduccion, char* nomArch);

int destruir_Lista_Reproduccion(TLista_Reproduccion* listaReproduccion);



#endif
