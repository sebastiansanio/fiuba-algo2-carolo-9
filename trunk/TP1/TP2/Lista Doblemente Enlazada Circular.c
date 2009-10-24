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
    TNodoDoble *pAux;
    if(!listaDEC->corriente)
        return LISTA_VACIA;
    else
        if(listaDEC->corriente->siguiente!=listaDEC->corriente)
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
    if (!listaDEC->primero)
        return LISTA_VACIA;
    if (posicion==LDEC_POS_PRI)
        {
        listaDEC->corriente=listaDEC->primero;
        return 0;
        }
    if (posicion==LDEC_POS_SIG)
        listaDEC->corriente=listaDEC->corriente->siguiente;
    else
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
int insertar_En_Lista_DEC(TLista_DEC* ldec, void* elemento, int posicion)
{
    TNodoDoble* pNodo=(TNodoDoble*)malloc(sizeof(TNodoDoble));
    if(!pNodo){return FALTA_MEMORIA;}
    pNodo->Elem=ldec->clonador(elemento);
    if(!pNodo){
        free(pNodo);
        return FALTA_MEMORIA;}
    if ((ldec->primero == NULL) || (posicion==LDEC_POS_PRI) ||
    ((posicion==LDEC_POS_ANT) && (ldec->primero==ldec->corriente))){
        pNodo->siguiente=ldec->primero;
        pNodo->anterior=ldec->primero->anterior;
        ldec->primero->anterior->siguiente=pNodo;
        ldec->primero->anterior=pNodo;
        ldec->primero=ldec->corriente=pNodo;}
    else{
        if(posicion==LDEC_POS_SIG){
            pNodo->siguiente=ldec->corriente->siguiente;
            pNodo->anterior=ldec->corriente;
            ldec->corriente->siguiente->anterior=pNodo;
            ldec->corriente->siguiente=pNodo;
            ldec->corriente=pNodo;}
        else{/*Anterior*/
            pNodo->siguiente=ldec->corriente;
            pNodo->anterior=ldec->corriente->anterior;
            ldec->corriente->anterior->siguiente=pNodo;
            ldec->corriente->anterior=pNodo;
            ldec->corriente=pNodo;}}
    return ELEMENTO_INSERTADO;
}


