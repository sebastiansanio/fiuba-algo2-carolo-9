#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "diccionario.h"
void mostrar(TDiccionario dicc, int cant);

int main(int argc, char* argv[]){
	TDiccionario dicc;
	int res, tam_dato = 23 * sizeof(char), i;
	char clave[SIZE_CLAVE], elem[23];

	printf("** Programa de prueba del TDA Diccionario nuevo. **\n");
	Diccionario_Crear(&dicc, tam_dato);

	strcpy(clave, "Juan");
	strcpy(elem, "Perez");
	for(i=0; i<6; i++){
		sprintf(clave, "%s%d", clave, i);
		sprintf(elem, "%s%d", elem, i);
		res = Diccionario_Asignar(&dicc, clave, elem);
		printf("-%d", res);
	}
	mostrar(dicc, Diccionario_CantidadEntradas(dicc));
	for(i=0; i<5; i++){
		sprintf(elem, "%s%d", elem, i);
		res = Diccionario_Asignar(&dicc, clave, elem);
		printf("-%d", res);
		mostrar(dicc, Diccionario_CantidadEntradas(dicc));
	}
	strcpy(clave, "Juan");
	for(i=0; i<6; i++){
		sprintf(clave, "%s%d", clave, i);
		Diccionario_Eliminar(&dicc, clave);
		mostrar(dicc, Diccionario_CantidadEntradas(dicc));
	}
	printf("Fin.-");
	return RES_OK;
}

void mostrar(TDiccionario dicc, int cant){
/*
 * Se comprueba la asignacion de memoria para evitar errores.
 * No se libera la memoria por simplicidad.
 */
	int i;
	char **claves, **elems;
	printf("\nEstado actual del diccionario:\n");
	claves = (char **) malloc(cant*sizeof(char*));
	if (!claves){return;}
	elems = (char **) malloc(cant*sizeof(char*));
	if (!elems){return;}
	for(i=0; i<cant; i++){
		claves[i] = (char*) malloc(SIZE_CLAVE * sizeof(char));
		if (!claves[i]){return;}
		elems[i] = (char*) malloc(dicc.size_elem * sizeof(char));
		if (!elems[i]){return;}
	}
	Diccionario_Claves(dicc, claves);
	for(i=0; i<cant; i++){
		Diccionario_Obtener(dicc, claves[i], elems[i]);
		printf("%s : %s\n",claves[i],elems[i]);
	}
}
