#include "arbol de busqueda.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


TNodoAB_BUSQ* AB_Busq_Rec(TAB_BUSQ*a,void* elem)
{
    if (!comparar(elem,a->cte->elem))
        return (a->cte);
    else
        if (comparar(elem,a->cte->elem)<0)
            {
                if(a->cte->izq)
                {
                    a->cte=a->cte->izq;
                    return(AB_Busq_Rec(a,elem));
                }
                else
                    return NULL;
            }
        else
            {
                if(a->cte->der)
                {
                    a->cte=a->cte->der;
                    return(AB_Busq_Rec(a,elem));
                }
                else
                    return NULL;
            }
}

TNodoAB_BUSQ* AB_Busq_Rec_Ins(TAB_BUSQ*a,void* elem)
{
    if (!comparar(elem,a->cte->elem))
        return NULL;
    else
        if (comparar(elem,a->cte->elem)<0)
            {
                if(a->cte->izq)
                {
                    a->cte=a->cte->izq;
                    return(AB_Busq_Rec(a,elem));
                }
                else
                    return a->cte;
            }
        else
            {
                if(a->cte->der)
                {
                    a->cte=a->cte->der;
                    return(AB_Busq_Rec(a,elem));
                }
                else
                    return a->cte;
            }
}

void AB_Busq_Crear(TAB_BUSQ*a,int tamdato)
{
    a->tamdato=tamdato;
    a->raiz=NULL;
    a->cte=NULL;
}


TNodoAB_BUSQ* AB_Busq_Buscar(TAB_BUSQ*a,void*elem)
{
    a->cte=a->raiz;
    return(AB_Busq_Rec(a,elem));
}

int AB_Busq_Insertar(TAB_BUSQ*a,void*elem)
{
    TNodoAB_BUSQ* nodo;
    TNodoAB_BUSQ* nodoaux;
    a->cte=a->raiz;
    nodo=(TNodo_AB_BUSQ*)malloc(sizeof(TNodo_AB_BUSQ);
    if (!nodo)
        return ABB_NO_MEM;
    else
        nodo->elem=malloc(a->tamdato);
        if(!nodo->elem)
        {
            free(nodo);
            return ABB_NO_MEM;
        }
        else
            memcpy(nodo->elem,elem,tamdato);
    if (!a->cte)
        {
            a->cte=a->raiz=nodo;
            return RES_OK;
        }
    else

        if(!AB_Busq_Rec_Ins(a,elem))
        {
            free(nodo->elem);
            free(nodo);
            return RES_ELEM_EXISTE;
        }
            else






}
