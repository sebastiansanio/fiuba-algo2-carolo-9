#ifndef PROPIEDADES_H_INCLUDED
#define PROPIEDADES_H_INCLUDED
#include "diccionario.h"
#define SIZE_VALOR 200

typedef struct{
	TDiccionario diccionario;
}TPropiedades;

int Propiedades_Crear(TPropiedades *propiedades);

int Propiedades_Cargar(TPropiedades *propiedades, char *rutaArchivo);

int Propiedades_Guardar(TPropiedades propiedades, char *rutaArchivo);

int Propiedades_Obtener(TPropiedades propiedades, char *nombre, char *valorDefault, char *valor);

int Propiedades_Asignar(TPropiedades *propiedades, char *nombre, char *valor);

int Propiedades_Existe(TPropiedades propiedades, char *nombre);

int Propiedades_Nombres(TPropiedades propiedades, char *nombres[]);

void Propiedades_Eliminar(TPropiedades *propiedades, char *nombre);

void Propiedades_Destruir(TPropiedades *propiedades);

#endif
