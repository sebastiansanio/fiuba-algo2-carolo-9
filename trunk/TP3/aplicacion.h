#ifndef APLICACION_H_INCLUDED
#define APLICACION_H_INCLUDED

typedef int (*TFuncion)(void* arg);

typedef struct{
    char*nombre;
    char*telefono;
    TAgenda* agenda;
} TFAgenda;



typedef struct {
TFuncion funcion;
void* arg;
} TSector;

void imprimir_por_pantalla(char*mensaje);

#endif
