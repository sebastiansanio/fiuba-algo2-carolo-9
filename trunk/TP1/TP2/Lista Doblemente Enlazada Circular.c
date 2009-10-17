#include <stdio.h>
#include <stdlib.h>
#include "Lista Doblemente Enlazada Circular.h"

/*PRE: listaDEC no creada */
/*POST: listaDEC creada */
int crear_Lista_DEC(TLista_DEC* listaDEC, f_clonar clonador, f_destruir destructor)
{
    listaDEC->clonador=clonador;
    listaDEC->destructor=destructor;
    listaDEC->primero = NULL;
    listaDEC->corriente = NULL;
    return 0;
}

/*PRE: listaDEC creada */
/*POST: listaDEC no creada */
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
    return 0;
}

int insertar_En_Lista_DEC(TLista_DEC* listaDEC, void* elemento, int posicion)
{
}

int eliminar_Cte_Lista_DEC(TLista_DEC* listaDEC);
{
}


/*PRE: listaDEC creada */
/*POST: Si la lista está vacía devuelve 1, sino guarda en elemento una copia del dato en corriente */
int obtener_Cte_Lista_DEC(TLista_DEC listaDEC, void** elemento)
{
    if(listaDEC.corriente)
        return 1;
    else
        {
            *elemento=listaDEC.clonador(listaDEC.corriente->Elem);
            return 0;
        }
}



int mover_Cte_Lista_DEC(TLista_DEC* listaDEC, int posicion)
{
}

/*PRE: listaDEC creada */
/*POST: Si la lista está vacía devuelve 1, sino guarda en corriente elemento */
int modificar_Cte_Lista_DEC(TLista_DEC* listaDEC, void* elemento)
{
    if(listaDEC->corriente)
        return 1;
    else
        {
            listaDEC->destructor(listaDEC->corriente->Elem);
            listaDEC->corriente->Elem=listaDEC->clonador(elemento);
            return 0;
        }
}

/*PRE: listaDEC creada */
/*POST: Si la lista está vacía devuelve 1, sino devuelve 0 */
int vacia_Lista_DEC(TLista_DEC* listaDEC)
{
    if(listaDEC->primero)
        return 1;
    else
        return 0;
}

/*PRE: listaDEC creada y no vacía */
/*POST: Si el corriente es el primer elemento de la lista devuelve 1, sino devuelve 0. */
int es_Primero_Lista_DEC(TLista_DEC* listaDEC)
{
    if(listaDEC->primero==listaDEC->corriente)
        return 1;
    else
        return 0;
}


