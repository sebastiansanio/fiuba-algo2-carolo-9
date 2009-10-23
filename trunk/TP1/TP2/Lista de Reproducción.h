#ifndef LISTA_DE_REPRODUCCIóN_H_INCLUDED
#define LISTA_DE_REPRODUCCIóN_H_INCLUDED
/*Codigos de error*/
#define LISTA_REPRODUCCIO_DESTRUIDA=0;

typedef struct
{
TLista_DEC lista;
} TLista_Reproducción; /* Lista de reproducción */

int crear_Lista_Reproducción(TLista_Reproducción* listaReproducción, char* nomArch);

int reproducir_Lista_Reproducción(Lista_Reproducción listaReproducción, int cantidad);

int adelantar_Lista_Reproducción(Lista_Reproducción listaReproducción);

int rotroceder_Lista_Reproducción(Lista_Reproducción listaReproducción);

int ordenar_Lista_Reproducción(Lista_Reproducción* listaReproducción, char* orden);

int guardar_Lista_Reproducción(Lista_Reproducción* listaReproducción, char* nomArch);

int destruir_Lista_Reproducción(Lista_Reproducción* listaReproducción);



#endif // LISTA_DE_REPRODUCCIóN_H_INCLUDED
