#ifndef LISTA_DE_REPRODUCCI�N_H_INCLUDED
#define LISTA_DE_REPRODUCCI�N_H_INCLUDED
/*Codigos de error*/
#define LISTA_REPRODUCCIO_DESTRUIDA=0;

typedef struct
{
TLista_DEC lista;
} TLista_Reproducci�n; /* Lista de reproducci�n */

int crear_Lista_Reproducci�n(TLista_Reproducci�n* listaReproducci�n, char* nomArch);

int reproducir_Lista_Reproducci�n(Lista_Reproducci�n listaReproducci�n, int cantidad);

int adelantar_Lista_Reproducci�n(Lista_Reproducci�n listaReproducci�n);

int rotroceder_Lista_Reproducci�n(Lista_Reproducci�n listaReproducci�n);

int ordenar_Lista_Reproducci�n(Lista_Reproducci�n* listaReproducci�n, char* orden);

int guardar_Lista_Reproducci�n(Lista_Reproducci�n* listaReproducci�n, char* nomArch);

int destruir_Lista_Reproducci�n(Lista_Reproducci�n* listaReproducci�n);



#endif // LISTA_DE_REPRODUCCI�N_H_INCLUDED
