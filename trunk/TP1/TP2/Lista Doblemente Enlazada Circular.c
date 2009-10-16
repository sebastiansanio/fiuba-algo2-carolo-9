#include <stdio.h>
#include <stdlib.h>
#include "Lista Doblemente Enlazada Circular.h"

int crear_Lista_DEC(TLista_DEC* listaDEC, f_clonar clonador, f_destruir destructor)
{




int destruir_Lista_DEC(TLista_DEC* listaDEC);

int insertar_En_Lista_DEC(TLista_DEC* listaDEC, void* elemento, int posicion);

int obtener_Cte_Lista_DEC(TLista_DEC listaDEC, void** elemento);

int mover_Cte_Lista_DEC(TLista_DEC* listaDEC, int posicion);

int modificar_Cte_Lista_DEC(TLista_DEC* listaDEC, void* elemento);

int vacia_Lista_DEC(TLista_DEC* listaDEC);

int es_Primero_Lista_DEC(TLista_DEC* listaDEC);
