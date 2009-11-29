#ifndef ARBOL_DE_BUSQUEDA_H_INCLUDED
#define ARBOL_DE_BUSQUEDA_H_INCLUDED

typedef int (*f_comparar)(void*,void*);

typedef struct TNodoAB_BUSQ
{
    void* elem;
    struct TNodoAB_BUSQ *izq, *der;
} TNodoAB_BUSQ;

typedef struct TAB
{
    TNodoAB_BUSQ *raiz,*cte;
    int tamdato;
    f_comparar comparar;
} TAB_BUSQ;

void AB_Busq_Crear(TAB_BUSQ*a,int tamdato,f_comparar comparar);

int AB_Busq_Buscar(TAB_BUSQ*a,void*elem_a_comparar,void*elem_devuelto);

int AB_Busq_Insertar(TAB_BUSQ*a,void*elem);

void AB_Busq_Destruir(TAB_BUSQ*a);

#endif
