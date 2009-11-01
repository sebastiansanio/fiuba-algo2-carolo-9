#include "diccionario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int Diccionario_BuscarPos(TDiccionario dicc, char* clave); /* prototipo */

int Diccionario_Crear(TDiccionario* dicc, int tamanioDato)
{
	dicc->size_elem = tamanioDato;
	dicc->cantidad = 0;
	return RES_OK;
}

int Diccionario_CantidadEntradas(TDiccionario dicc)
{
    return dicc.cantidad;
}

int Diccionario_Existe(TDiccionario dicc, char* clave)
{
	int i = Diccionario_BuscarPos(dicc, clave);
	if (i==-1) return FALSE;
	return TRUE;
}

void Diccionario_Obtener(TDiccionario dicc, char* clave, void* elem)
{
/* PRE: 'elem' tiene la memoria necesaria y 'clave' existe en 'dicc'.
 * POST: 'elem' contiene el elemento de 'dicc' con clave 'clave'.
 * */
    int pos = Diccionario_BuscarPos(dicc, clave);
    memcpy(elem, dicc.entradas[pos]->elem, dicc.size_elem);
}

int Diccionario_Asignar(TDiccionario* dicc, char* clave, void* elem)
{
/* PRE:
 * POST: 'dicc' contiene 'elem' en la clave 'clave'.
 * 'clave' se trunca a largo SIZE_CLAVE.
 * Si 'clave' existia se sobreescribe su contenido.
 * */
	int pos = Diccionario_BuscarPos(*dicc, clave);

	if (pos==-1){
		int cmpres, i, j, x;
		TEntrada ** aux;
		aux = (TEntrada **) malloc(sizeof(TEntrada*) * (dicc->cantidad + 1));
		if (!aux){
			return RES_OUT_OF_MEM;
		}
		for(i=0; i<dicc->cantidad; i++){
			cmpres=strncmp(clave,dicc->entradas[i]->clave,SIZE_CLAVE);
			if (cmpres<0){/* La clave es menor y se debe insertar en esta posicion. */
				break;
			}
		}
		aux[i] = (TEntrada *) malloc(sizeof(TEntrada));
		if (!aux[i]){
			free(aux);
			return RES_OUT_OF_MEM;
		}
		aux[i]->elem = malloc(dicc->size_elem);
		if (!aux[i]->elem){
					free(aux);
					free(aux[i]);
					return RES_OUT_OF_MEM;
				}
		memcpy(aux[i]->elem, elem, dicc->size_elem); /* Copia el elemento al diccionario */
		memcpy(aux[i]->clave, clave, SIZE_CLAVE); /* Copia la clave al diccionario */
		/* Copio las entradas que habia, salteando el lugar de la nueva. */
		for(j=x=0; x<dicc->cantidad; j++){
			if (j==i){j++;}
			aux[j] = dicc->entradas[x++];
		}
		if (i!=0){free(dicc->entradas);}
		dicc->entradas = aux;
		dicc->cantidad++;
	}else{
		memcpy(dicc->entradas[pos]->elem, elem, dicc->size_elem); /* Copia el elemento al diccionario */
	}
	return RES_OK;
}

void Diccionario_Claves(TDiccionario dicc, char* claves[])
{
/* PRE: claves tiene la memoria necesaria.
 * POST: claves contiene todas las claves de dicc.
 * */
    int i;
    for(i=0; i<dicc.cantidad; i++){
    	strcpy(claves[i], dicc.entradas[i]->clave);
    }
}

void Diccionario_Eliminar(TDiccionario* dicc, char* clave)
{
/* PRE:
 * POST: Si 'clave' existe en 'dicc' se elimina.
 * */
	int pos = Diccionario_BuscarPos(*dicc, clave), j, x;
	if (pos!=-1){
		TEntrada ** aux;
		aux = (TEntrada **) malloc(sizeof(TEntrada*) * (dicc->cantidad - 1));
		if (!aux){return;}
		/* Copio las entradas que habia, exceptuando y liberando la que se elimina. */
		for(j=x=0; j<dicc->cantidad; x++){
			if (j==pos){
				free(dicc->entradas[j]);
				j++;
				if (j==dicc->cantidad){break;}
			}
			aux[x] = dicc->entradas[j++];
		}
		free(dicc->entradas);
		dicc->entradas = aux;
		dicc->cantidad--;
	}
}

void Diccionario_Destruir(TDiccionario* dicc)
{	/* Libera la memoria de todos los elementos */
	int i;
	for(i=0; i<dicc->cantidad; i++){
		free(dicc->entradas[i]->elem);
		free(dicc->entradas[i]);
	}
	dicc->cantidad = 0;
	dicc->size_elem = 0;
}

int Diccionario_BuscarPos(TDiccionario dicc, char* clave)
{	/* Devuelve la posicion de 'clave' en 'dicc.entradas' o -1 si no existe.*/
	int cmpres,i;
	for(i=0; i<dicc.cantidad; i++){
		cmpres = strncmp(clave, dicc.entradas[i]->clave, SIZE_CLAVE);
		if (cmpres==0){ /* La clave buscada esta en la actual posicion */
			return i;
		}
		if (cmpres<0){ /* La clave buscada es menor que la actual ergo no existe */
			return -1;
		}
	}/* Recorrimos el diccionario entero y no existe.*/
	return -1;
}
