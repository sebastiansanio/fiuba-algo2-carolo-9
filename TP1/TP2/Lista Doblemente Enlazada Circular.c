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
    return LISTA_DESTRUIDA;
}


/*PRE: listaDEC creada */
/*POST: Si la lista está vacía devuelve LISTA_VACIA, sino elimina el actual elemento corriente y el corriente pasa a ser el siguiente */
int eliminar_Cte_Lista_DEC(TLista_DEC* listaDEC)
{
    TNodo_Doble *pAux;
    if(!listaDEC->corriente)
        return LISTA_VACIA;
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
        return LISTA_VACIA;
    else
        {
            *elemento=listaDEC.clonador(listaDEC.corriente->Elem);
            return ELEMENTO_OBTENIDO;
        }
}


/*PRE: listaDEC creada */
/*POST: Si la lista está vacía devuelve LISTA_VACIA. Si posicion es 0 el corriente pasa al primero, sino el corriente se mueve la cantidad
en posicion (hacia izquierda o derecha según el signo)  */
int mover_Cte_Lista_DEC(TLista_DEC* listaDEC, int posicion)
{
    int i;
    if (!listaDEC->primero)
        return LISTA_VACIA;
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
/*POST: Si la lista está vacía devuelve LISTA_VACIA, sino guarda en corriente elemento */
int modificar_Cte_Lista_DEC(TLista_DEC* listaDEC, void* elemento)
{
    if(!listaDEC->corriente)
        return LISTA_VACIA;
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
        return LISTA_LLENA;
    else
        return LISTA_SIN_ELEMENTOS;
}

/*PRE: listaDEC creada y no vacía */
/*POST: Si el corriente es el primer elemento de la lista devuelve 1, sino devuelve 0. */
int es_Primero_Lista_DEC(TLista_DEC* listaDEC)
{
    if(listaDEC->primero==listaDEC->corriente)
        return ES_PRIMERO_VERDADERO;
    else
        return ES_PRIMERO_FALSO;
}

/*PRE: ldec creada, elemento y posición validos*/
/*POST: Inserta según posición el elemento en la lista, devuelve FALTA_MEMORIA si no pudo insertar, y ELEMENTO_INSERTADO si pudo*/
int insertarEnLDEC(LDEC* ldec, void* elemento, int posición);{
    Nodo* pNodo=(Nodo*)malloc(sizeof(Nodo));
    if(!pNodo){return FALTA_MEMORIA;}
    pNodo->pElemento=ldec->pfClonador(elemento);
    if(!pNodo){
        free(pNodo);
        return FALTA_MEMORIA;}
    if ((ldec->pPrimero == NULL) || (posicion==PRIMERO) ||
    ((posicion==ANTERIOR) && (ldec->pPrimero==ldec->pCorriente))){
        pNodo->pSiguiente=ldec->pPrimero;
        pNodo->pAnterior=ldec->pPrimero->pAnterior;
        ldec->pPrimero->pAnterior->pSiguiente=pNodo;
        ldec->pPrimero->pAnterior=pNodo;
        ldec->pPrimero=ldec->pCorriente=pNodo;}
    else{
        if(posicion==SIGUIENTE){
            pNodo->pSiguiente=ldec->pCorriente->pSiguiente;
            pNodo->pAnterior=ldec->pCorriente;
            ldec->pCorriente->pSiguiente->pAnterior=pNodo;
            ldec->pCorriente->pSiguiente=pNodo;
            ldec->pCorriente=pNodo;}
        else{/*ANTERIOR*/
            pNodo->pSiguiente=ldec->pCorriente;
            pNodo->pAnterior=ldec->pCorriente->pAnterior;
            ldec->pCorriente->pAnterior-pSiguiente=pNodo;
            ldec->pCorriente->pAnterior=pNodo;
            ldec->pCorriente=pNodo;}}
    return ELEMENTO_INSERTADO;}


