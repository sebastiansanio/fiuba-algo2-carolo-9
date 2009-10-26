#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista de Reproducción.h"


int crear_Lista_Reproducción(TLista_Reproducción* listaReproducción, char* nomArch)
{
return 0;
};

int reproducir_Lista_Reproducción(Lista_Reproducción listaReproducción, int cantidad)
{
return 0;
};

/*PRE: listaReproducción creada*/
/*POST: Muestra el nombre de la canción ubicada despues que la actual*/
int adelantar_Lista_Reproducción(Lista_Reproducción listaReproducción)
{Posicion Movimiento=Posicion.Siguiente;
void** elemento;
int resultado;
resultado=moverCteLDEC(listaReproduccion.Canciones,Movimiento);
if (resultado==LISTA_VACIA){return FALTA_MEMORIA;}
resultado=obtenerCteLDEC(listaReproducción.Canciones,elemento);
if (resultado==FALTA_MEMORIA){return FALTA_MEMORIA;}
/*Mostrar el elemento*/
return ELEMENTO_CONSEGUIDO;
}

/*PRE: listaReproducción creada*/
/*POST: Muestra el nombre de la canción ubicada antes que la actual*/
int retroceder_Lista_Reproducción(Lista_Reproducción listaReproducción)
{Posicion Movimiento=Posicion.Anterior;
void** elemento;
int resultado;
resultado=moverCteLDEC(listaReproduccion.Canciones,Movimiento);
if (resultado==LISTA_VACIA){return LISTA_VACIA;}
resultado=obtenerCteLDEC(listaReproducción.Canciones,elemento);
if (resultado==FALTA_MEMORIA){return FALTA_MEMORIA;}
/*Mostrar el elemento*/
return ELEMENTO_CONSEGUIDO;
}

int ordenar_Lista_Reproducción(Lista_Reproducción* listaReproducción, char* orden)
{
return 0;
};

int guardar_Lista_Reproducción(Lista_Reproducción* listaReproducción, char* nomArch)
{
return 0;
};

/*PRE: listaReproducción creada*/
/*POST: listaReproduccion destruida*/
int destruir_Lista_Reproducción(Lista_Reproducción* listaReproducción)
{destruir_Lista_DEC(listaReproducción->Canciones);
Diccionario_Destruir(listaReproducción->Dicc_Alias);
return LISTA_REPRODUCCION_DESTRUIDA;
}
