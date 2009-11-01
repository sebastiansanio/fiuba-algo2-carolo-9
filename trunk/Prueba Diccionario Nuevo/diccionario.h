#ifndef DICCIONARIO_H_INCLUDED
#define DICCIONARIO_H_INCLUDED
#define SIZE_CLAVE 20
#define TRUE 1
#define FALSE 0
#define RES_OK 0
#define RES_OUT_OF_MEM -2

typedef struct {
	char clave[SIZE_CLAVE];
	void *elem;
}TEntrada;
typedef struct {
	int size_elem;
	int cantidad;
	TEntrada ** entradas;
}TDiccionario;

int Diccionario_Crear(TDiccionario* dicc, int tamanioDato);

void Diccionario_Obtener(TDiccionario dicc, char* clave, void* elem);

int Diccionario_Asignar(TDiccionario* dicc, char* clave, void* elem);

int Diccionario_Existe(TDiccionario dicc, char* clave);

void Diccionario_Claves(TDiccionario dicc, char* claves[]);

int Diccionario_CantidadEntradas(TDiccionario dicc);

void Diccionario_Eliminar(TDiccionario* dicc, char* clave);

void Diccionario_Destruir(TDiccionario* dicc);


#endif
