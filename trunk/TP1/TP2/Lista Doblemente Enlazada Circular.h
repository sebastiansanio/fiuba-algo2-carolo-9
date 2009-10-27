#ifndef LISTA_DOBLEMENTE_ENLAZADA_CIRCULAR_H_INCLUDED
#define LISTA_DOBLEMENTE_ENLAZADA_CIRCULAR_H_INCLUDED
/*Codigos de error*/
#define FALTA_MEMORIA 1
#define LISTA_DESTRUIDA 0
#define ELEMENTO_OBTENIDO 0
#define LISTA_VACIA 1
#define ELEMENTO_INSERTADO 0
#define LISTA_LLENA 1
#define LISTA_SIN_ELEMENTOS 0
#define ES_PRIMERO_VERDADERO 1
#define ES_PRIMERO_FALSO 0

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
f_clonar clonador;
f_destruir destructor;
} TLista_DEC; /*Lista doblemente enlazada */

enum posicion
{
    LDEC_POS_PRI,
    LDEC_POS_SIG,
    LDEC_POS_ANT
    } ;

int crear_Lista_DEC(TLista_DEC* listaDEC, f_clonar clonador, f_destruir destructor);

int destruir_Lista_DEC(TLista_DEC* listaDEC);

int insertar_En_Lista_DEC(TLista_DEC* listaDEC, void* elemento, int posicion);

int obtener_Cte_Lista_DEC(TLista_DEC listaDEC, void* elemento);

int eliminar_Cte_Lista_DEC(TLista_DEC* listaDEC);

int mover_Cte_Lista_DEC(TLista_DEC* listaDEC, int posicion);

int modificar_Cte_Lista_DEC(TLista_DEC* listaDEC, void* elemento);

int vacia_Lista_DEC(TLista_DEC* listaDEC);

int es_Primero_Lista_DEC(TLista_DEC* listaDEC);

#endif
