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

int adelantar_Lista_Reproducci�n(Lista_Reproducci�n listaReproducci�n)
{
return 0;
};

int rotroceder_Lista_Reproducci�n(Lista_Reproducci�n listaReproducci�n)
{
return 0;
};

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
return LISTA_REPRODUCCIO_DESTRUIDA;
};
