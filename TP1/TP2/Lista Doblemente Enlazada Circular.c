#include <stdio.h>
#include <stdlib.h>
#include "Lista Doblemente Enlazada Circular.h"

/*PRE: listaDEC no creada */
/*PRE: listaDEC creada */
int crear_Lista_DEC(TLista_DEC* listaDEC, f_clonar clonador, f_destruir destructor, int TamanioDato)
{
    listaDec->TamanioDato=TamanioDato;
    listaDEC->clonador=clonador;
    listaDEC->destructor=destructor;
    listaDEC->primero = NULL;
    listaDEC->corriente = NULL;
    return 0;
    }

/*PRE: listaDEC creada */
/*PRE: listaDEC no creada */
int destruir_Lista_DEC(TLista_DEC* listaDEC)
{
    	TNodoDoble *pAux;
    	listaDEC->corriente=listaDEC->primero->siguiente;
    	while (listaDEC->corriente!=listaDEC->primero)
    	{
    	    listaDEC->destructor(listaDEC->corriente->Elem);
    	    pAux=listaDEC->corriente->siguiente;
    	    free(listaDEC->corriente);
    	    listaDEC->corriente=pAux;
    	}
            listaDEC->destructor(listaDEC->corriente->Elem);
            free(listaDEC->corriente);
            listaDEC->primero=listaDEC->corriente=NULL;
            listaDEC->destructor=NULL;
            listaDEC->clonador=NULL;
    }


int insertar_En_Lista_DEC(TLista_DEC* listaDEC, void* elemento, int posicion);

int obtener_Cte_Lista_DEC(TLista_DEC listaDEC, void** elemento);

int mover_Cte_Lista_DEC(TLista_DEC* listaDEC, int posicion);

int modificar_Cte_Lista_DEC(TLista_DEC* listaDEC, void* elemento);

int vacia_Lista_DEC(TLista_DEC* listaDEC);

int es_Primero_Lista_DEC(TLista_DEC* listaDEC);

