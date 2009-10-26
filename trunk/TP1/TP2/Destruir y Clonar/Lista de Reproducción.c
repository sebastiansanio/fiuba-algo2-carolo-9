#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista de Reproducci�n.h"


int crear_Lista_Reproducci�n(TLista_Reproducci�n* listaReproducci�n, char* nomArch)
{
return 0;
};

int reproducir_Lista_Reproducci�n(Lista_Reproducci�n listaReproducci�n, int cantidad)
{
return 0;
};

/*PRE: listaReproducci�n creada*/
/*POST: Muestra el nombre de la canci�n ubicada despues que la actual*/
int adelantar_Lista_Reproducci�n(Lista_Reproducci�n listaReproducci�n)
{Posicion Movimiento=Posicion.Siguiente;
void** elemento;
int resultado;
resultado=moverCteLDEC(listaReproduccion.Canciones,Movimiento);
if (resultado==LISTA_VACIA){return FALTA_MEMORIA;}
resultado=obtenerCteLDEC(listaReproducci�n.Canciones,elemento);
if (resultado==FALTA_MEMORIA){return FALTA_MEMORIA;}
/*Mostrar el elemento*/
return ELEMENTO_CONSEGUIDO;
}

/*PRE: listaReproducci�n creada*/
/*POST: Muestra el nombre de la canci�n ubicada antes que la actual*/
int retroceder_Lista_Reproducci�n(Lista_Reproducci�n listaReproducci�n)
{Posicion Movimiento=Posicion.Anterior;
void** elemento;
int resultado;
resultado=moverCteLDEC(listaReproduccion.Canciones,Movimiento);
if (resultado==LISTA_VACIA){return LISTA_VACIA;}
resultado=obtenerCteLDEC(listaReproducci�n.Canciones,elemento);
if (resultado==FALTA_MEMORIA){return FALTA_MEMORIA;}
/*Mostrar el elemento*/
return ELEMENTO_CONSEGUIDO;
}

int ordenar_Lista_Reproducci�n(Lista_Reproducci�n* listaReproducci�n, char* orden)
{
return 0;
};

int guardar_Lista_Reproducci�n(Lista_Reproducci�n* listaReproducci�n, char* nomArch)
{
return 0;
};

/*PRE: listaReproducci�n creada*/
/*POST: listaReproduccion destruida*/
int destruir_Lista_Reproducci�n(Lista_Reproducci�n* listaReproducci�n)
{destruir_Lista_DEC(listaReproducci�n->Canciones);
Diccionario_Destruir(listaReproducci�n->Dicc_Alias);
return LISTA_REPRODUCCION_DESTRUIDA;
}
