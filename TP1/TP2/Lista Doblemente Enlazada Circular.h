#ifndef LISTA_DOBLEMENTE_ENLAZADA_CIRCULAR_H_INCLUDED
#define LISTA_DOBLEMENTE_ENLAZADA_CIRCULAR_H_INCLUDED

typedef void (*f_destruir)(void*);

typedef void* (*f_clonar)(void*);

typedef struct TNodo_Doble
{
void* Elem;
struct TNodo_Doble *siguiente,*anterior;
} TNodoDoble; /* Nodo de una lista doblemente enlazada */


typedef struct
{
TNodoDoble *primero, *corriente;
int TamanioDato;
f_clonar clonador;
f_destruir destructor;
} TLista_DEC; /*Lista doblemente enlazada */

int crear_Lista_DEC(TLista_DEC* listaDEC, f_clonar clonador, f_destruir destructor, int TamanioDato);

int destruir_Lista_DEC(TLista_DEC* listaDEC);

int insertar_En_Lista_DEC(TLista_DEC* listaDEC, void* elemento, int posicion);

int obtener_Cte_Lista_DEC(TLista_DEC listaDEC, void** elemento);

int mover_Cte_Lista_DEC(TLista_DEC* listaDEC, int posicion);

int modificar_Cte_Lista_DEC(TLista_DEC* listaDEC, void* elemento);

int vacia_Lista_DEC(TLista_DEC* listaDEC);

int es_Primero_Lista_DEC(TLista_DEC* listaDEC);

#endif // LISTA_DOBLEMENTE_ENLAZADA_CIRCULAR_H_INCLUDED
