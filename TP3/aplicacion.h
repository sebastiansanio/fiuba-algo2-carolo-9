#ifndef APLICACION_H_INCLUDED
#define APLICACION_H_INCLUDED

typedef int (*TFuncion)(void* arg);

typedef struct {
    TFuncion funcion;
    void* arg;
} TSector;

typedef struct {
    TPantalla*pantalla;
    TAgenda*agenda;
    int codigo_salida;
} TExit;


void imprimir_por_pantalla(void*arg);

void agregar_numero(void*arg);

void buscar_numero(void*arg);

void eliminar_numero(void*arg);

void exit_f(void*arg);

#endif
