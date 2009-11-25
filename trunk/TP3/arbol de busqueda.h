#ifndef ARBOL_DE_BUSQUEDA_H_INCLUDED
#define ARBOL_DE_BUSQUEDA_H_INCLUDED

typedef struct TNodoAB_BUSQ
{
    void* elem;
    struct TNodoAB_BUSQ *izq, *der;
} TNodoAB_BUSQ;

typedef struct TAB
{
    TNodoAB_BUSQ *raiz,*cte;
    int tamdato;
} TAB_BUSQ;

int (*comparar)(void*,void*);

void AB_Busq_Crear(TAB_BUSQ*a,int tamdato);

TNodoAB_BUSQ* AB_Busq_Buscar(TAB_BUSQ*a,void*elem);

void AB_Busq_Insertar(TAB_BUSQ*a,void*elem);

#endif
