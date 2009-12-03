#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED
#include "ListaSimple.h"
#include "ABO.h"
#define TPAN_ERR -1
#define TPAN_OK 0
#define TPAN_NO_HAY_ELEM 1
#define TPAN_HAY_ELEM 2

typedef struct {
	double x;
	double y;
} TPunto;

typedef struct {
	TPunto inicio;
	TPunto fin;
} TDivision;

typedef struct {
	TDivision div;
	void* elem;
} TElemPantalla;

typedef struct {
	TAB AB;
	int tamdato;
} TPantalla;


int Pantalla_Crear(TPantalla* pantalla, TListaSimple* divisiones, int tamdato);
/*
    Precondiciones: pantalla tiene sizeof(TPantalla) bytes reservados.
         divisiones es una lista simple creada y no vacia de objetos TDivision.
         La lista divisiones representa una pantalla valida. tamdato es mayor o
         igual a uno.
    Postcondiciones: pantalla inicializado con las divisiones de la lista.
    Devuelve: TPAN_OK si todo salio bien. TPAN ERR si ocurrio algun error.
*/
int Pantalla_Asociar_Elemento(TPantalla* pantalla, TPunto punto, void* elem);
/*
    Precondiciones: pantalla creado. punto tiene coordenadas mayores que
         cero y menores que uno. elem apunta a un objeto de size tamdato.
         el sector de punto no tiene un elemento asociado
    Postcondiciones: el elemento elem se asocio con el sector señalado por
         punto.
    Devuelve: TPAN_OK si todo salio bien. TPAN ERR si ocurrio algun error.
*/
int Pantalla_Desasociar_Elemento(TPantalla* pantalla, TPunto punto);
/*
    Precondiciones: pantalla creado. punto tiene coordenadas mayores que
         cero y menores que uno. el sector de punto tiene un elemento
         asociado.
    Postcondiciones: no hay ningun elemento asociado al sector.
    Devuelve: TPAN_OK si todo salio bien. TPAN ERR si ocurrio algun error.
*/
int Pantalla_Hay_Elemento(TPantalla* pantalla, TPunto punto);
/*
    Descripcion: Consulta si hay un elemento asociado al sector de punto.
    Precondiciones: pantalla creado. punto tiene coordenadas mayores que
         cero y menores que uno.
    Postcondiciones: no se modifica la pantalla.
    Devuelve: TPAN_HAY_ELEM si hay un elemento asociado al sector de
         punto. TPAN_NO_HAY_ELEM en caso contrario.
*/
int Pantalla_Obtener_Elemento(TPantalla* pantalla, TPunto punto, void* elem);
/*
	Descripcion: Devuelve el elemento asociado con el sector de punto.
    Precondiciones: pantalla creado. punto tiene coordenadas mayores que
         cero y menores que uno. elem tiene memoria reservada para un objeto
         de size tamdato.
    Postcondiciones: si el sector de punto tiene un elemento asociado, se lo copia a elem.
    Devuelve: TPAN_OK si todo salio bien. TPAN NO HAY ELEM si el sector no tiene
         un elemento asociado. TPAN_ERR si ocurrio otro error.
*/
void Pantalla_Destruir(TPantalla* pantalla);
/*
    Descripcion: Libera todos los recursos asociados a pantalla.
    Precondiciones: pantalla creado.
    Postcondiciones: pantalla destruido.
*/

#endif
