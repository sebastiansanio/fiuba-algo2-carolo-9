#ifndef DICCIONARIO_H_INCLUDED
#define DICCIONARIO_H_INCLUDED
#define SIZE_CLAVE 20
#define SIZE_DICC 20
#define SIZE_VALOR 50

typedef struct {
	char clave[SIZE_CLAVE];
	void *elem;
}TEntrada;
typedef struct {
	TEntrada entradas[SIZE_DICC];
	int size_elem;
}TDiccionario;

int Diccionario_Crear(TDiccionario* dicc, int tamanioDato);

void Diccionario_Obtener(TDiccionario dicc, char* clave, void* elem);

int Diccionario_Asignar(TDiccionario* dicc, char* clave, void* elem);

int Diccionario_Existe(TDiccionario dicc, char* clave);

void Diccionario_Claves(TDiccionario dicc, char* claves[]);

int Diccionario_CantidadEntradas(TDiccionario dicc);

void Diccionario_Eliminar(TDiccionario* dicc, char* clave);

void Diccionario_Destruir(TDiccionario* dicc);


#endif // DICCIONARIO_H_INCLUDED
