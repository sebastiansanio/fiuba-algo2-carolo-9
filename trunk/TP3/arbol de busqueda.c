#include "arbol de busqueda.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ABB_NO_MEM -1
#define RES_ELEM_EXISTE -2
#define RES_OK 0
#define ELEM_NO_ENCONTRADO -1


TNodoAB_BUSQ* AB_Busq_Rec(TAB_BUSQ*a,void* elem)
{
    if (!a->comparar(elem,a->cte->elem))
        return (a->cte);
    else
        if (a->comparar(elem,a->cte->elem)<0)
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
    if (!a->comparar(elem,a->cte->elem))
        return NULL;
    else
        if (a->comparar(elem,a->cte->elem)<0)
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

void AB_Busq_Crear(TAB_BUSQ*a,int tamdato,f_comparar comparar)
{
    a->tamdato=tamdato;
    a->raiz=NULL;
    a->cte=NULL;
}


int AB_Busq_Buscar(TAB_BUSQ*a,void*elem_a_comparar,void*elem_devuelto)
{
    TNodoAB_BUSQ* nodoaux;
    a->cte=a->raiz;
    nodoaux=(AB_Busq_Rec(a,elem_a_comparar));
    if (!nodoaux)
        return ELEM_NO_ENCONTRADO;
    else
    {
        elem_devuelto=nodoaux->elem;
        return RES_OK;
    }
}

int AB_Busq_Insertar(TAB_BUSQ* a,void*elem)
{
    TNodoAB_BUSQ* nodo;
    TNodoAB_BUSQ* nodoaux;
    a->cte=a->raiz;
    nodo=(TNodoAB_BUSQ*)malloc(sizeof(TNodoAB_BUSQ));
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
            memcpy(nodo->elem,elem,a->tamdato);
    if (!a->cte)
        {
            a->cte=a->raiz=nodo;
            return RES_OK;
        }
    else
        {
            nodoaux=(AB_Busq_Rec_Ins(a,elem));
            if (!nodoaux)
            {
                free(nodo->elem);
                free(nodo);
                return RES_ELEM_EXISTE;
            }
            else
                if (a->comparar(nodoaux->elem,elem)==-1)
                    nodoaux->der=nodo;
                else
                    nodoaux->izq=nodo;
        }
    return RES_OK;
}

void AB_Busq_Rec_Destruir(TNodoAB_BUSQ *pnodo)
{
    if (pnodo != NULL)
    {
        if ((pnodo->izq == NULL) && (pnodo->der == NULL))
        {
            free(pnodo->elem);
            free(pnodo);
        }
        else
        {
            AB_Busq_Rec_Destruir(pnodo->izq);
            AB_Busq_Rec_Destruir(pnodo->der);
            free(pnodo->elem);
            free(pnodo);
        }
    }
}

void AB_Busq_Destruir(TAB_BUSQ*a)
{
    AB_Busq_Rec_Destruir(a->raiz);
    a->raiz = NULL;
    a->cte = NULL;
    a->comparar = NULL;
    a->tamdato = 0;
}








