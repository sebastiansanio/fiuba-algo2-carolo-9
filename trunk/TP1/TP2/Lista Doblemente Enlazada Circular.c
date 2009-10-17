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

/*PRE: listaDEC creada */
/*POST: Si la lista está vacía devuelve 1, sino elimina el actual elemento corriente y el corriente pasa a ser el siguiente */
int eliminar_Cte_Lista_DEC(TLista_DEC* listaDEC)
{
    TNodo_Doble *pAux;
    if(!listaDEC->corriente)
        return 1;
    else
        if(!listaDEC->corriente->siguiente)
            {
            listaDEC->destructor(listaDEC->corriente->Elem);
            listaDEC->corriente->anterior->siguiente=listaDEC->corriente->siguiente;
            listaDEC->corriente->siguiente->anterior=listaDEC->corriente->anterior;
            pAux=listaDEC->corriente->siguiente;
            free(listaDEC->corriente);
            if(listaDEC->corriente==listaDEC->primero)
                listaDEC->corriente=listaDEC->primero=pAux;
            else
                listaDEC->corriente=pAux;
            return 0;
            }
        else
            {
            listaDEC->destructor(listaDEC->corriente->Elem);
            free(listaDEC->corriente);
            listaDEC->primero=listaDEC->corriente=NULL;
            return 0;
            }

}


/*PRE: listaDEC creada */
/*POST: Si la lista está vacía devuelve 1, sino guarda en elemento una copia del dato en corriente */
int obtener_Cte_Lista_DEC(TLista_DEC listaDEC, void** elemento)
{
    if(!listaDEC.corriente)
        return 1;
    else
        {
            *elemento=listaDEC.clonador(listaDEC.corriente->Elem);
            return 0;
        }
}


/*PRE: listaDEC creada */
/*POST: Si la lista está vacía devuelve 1,  */
int mover_Cte_Lista_DEC(TLista_DEC* listaDEC, int posicion)
{
    int i;
    if (!listaDEC->primero)
        return 1;
    if (posicion==0)
        {
        listaDEC->corriente=listaDEC->primero;
        return 0;
        }
    if (posicion>0)
        for(i=1;i<=posicion;i++)
            listaDEC->corriente=listaDEC->corriente->siguiente;
    else
        for(i=-1;i>=posicion;i--)
            listaDEC->corriente=listaDEC->corriente->anterior;
    return 0;
}

/*PRE: listaDEC creada */
/*POST: Si la lista está vacía devuelve 1, sino guarda en corriente elemento */
int modificar_Cte_Lista_DEC(TLista_DEC* listaDEC, void* elemento)
{
    if(!listaDEC->corriente)
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


