#include "Pantalla.h"
#include "memory.h"

void Division_Crear(TDivision*division,TPunto inicio,TPunto fin)
{
    division->inicio=inicio;
    division->fin=fin;
}

void Punto_Cargar(TPunto* punto,double x,double y)
{
    punto->x=x;
    punto->y=y;
}

TElemPantalla* Obtener_Sector(TPantalla* P, TPunto punto, int mov)
{
    TElemPantalla* elemP;
	int err;
	AB_MoverCte(&P->AB, mov, &err);
	elemP=(TElemPantalla*)malloc(sizeof(TElemPantalla));
	AB_ElemCte(P->AB, elemP);
	if (err)
	{
	    return elemP;
	}/*Llegamos a una hoja.*/

	if (elemP->div.inicio.x == elemP->div.fin.x)/*division vertical*/
	{
        if (punto.x > elemP->div.fin.x)
        {
            free(elemP);
            return Obtener_Sector(P, punto, DER);
        }
        free(elemP);
		return Obtener_Sector(P, punto, IZQ);
	}
	if (punto.y > elemP->div.fin.y)
	{
	    free(elemP);
		return Obtener_Sector(P, punto, DER);
	}
	free(elemP);
	return Obtener_Sector(P, punto, IZQ);
}


int Pantalla_Obtener_Elemento(TPantalla* pantalla, TPunto punto, void* elem){
	TElemPantalla* elemP = Obtener_Sector(pantalla, punto, RAIZ);
	if (!elemP->elem){
        free(elemP);
		return TPAN_NO_HAY_ELEM;}
	memcpy(elem, elemP->elem, pantalla->tamdato);
	free(elemP);
	return TPAN_OK;
}


int P_Insertar_Div(TPantalla* P, TListaSimple* divisiones, TPunto a, TPunto b, int mov){
	TDivision div;
	TElemPantalla elemP;
	int i, err;
	elemP.elem = NULL;

	ls_MoverCorriente(divisiones, LS_PRIMERO);
	do{
	    if(ls_Vacia(*divisiones)){return TPAN_OK;}
		ls_ElemCorriente(*divisiones, &div);
		if ((div.inicio.x == a.x && div.fin.x == b.x)||(div.inicio.y == a.y && div.fin.y == b.y)){
		    ls_BorrarCorriente(divisiones);
			memcpy(&elemP.div, &div, sizeof(TDivision));
			AB_Insertar(&P->AB, mov, &elemP, &err);
			if (err){return TPAN_ERR;}

			err = P_Insertar_Div(P, divisiones, a, div.fin, IZQ);
			if (err){return TPAN_ERR;}
			AB_MoverCte(&P->AB, PAD, &err);
			err = P_Insertar_Div(P, divisiones, div.inicio,b, DER);
			if (err){return TPAN_ERR;}
			AB_MoverCte(&P->AB, PAD, &err);

			return TPAN_OK;
		}
		i = ls_MoverCorriente(divisiones, LS_SIGUIENTE);
	} while(i!=FALSE);

	AB_Insertar(&P->AB, mov, &elemP, &err);/*HOJA*/
	if (err){return TPAN_ERR;}
	return TPAN_OK;
}


int Pantalla_Crear(TPantalla* pantalla, TListaSimple* divisiones, int tamdato){
	TPunto a, b;
	a.x=0.0;
	a.y=0.0;
	b.x=1.0;
	b.y=1.0;
	pantalla->tamdato = tamdato;
	AB_Crear(&pantalla->AB, sizeof(TElemPantalla));
	return P_Insertar_Div(pantalla, divisiones, a, b, RAIZ);
}

int Pantalla_Asociar_Elemento(TPantalla* pantalla, TPunto punto, void* elem){
	TElemPantalla* elemP = Obtener_Sector(pantalla, punto, RAIZ);
	elemP->elem = malloc(pantalla->tamdato);
	if (!elemP->elem){return TPAN_ERR;}
	memcpy(elemP->elem, elem, pantalla->tamdato);
	AB_ModifCte(&(pantalla->AB),elemP);
	free(elemP);
	return TPAN_OK;
}

int Pantalla_Desasociar_Elemento(TPantalla* pantalla, TPunto punto){
	TElemPantalla* elemP = Obtener_Sector(pantalla, punto, RAIZ);
	free(elemP->elem);
	elemP->elem = NULL;
	AB_ModifCte(&(pantalla->AB),elemP);
	free(elemP);
	return TPAN_OK;
}

int Pantalla_Hay_Elemento(TPantalla* pantalla, TPunto punto){
	TElemPantalla* elemP = Obtener_Sector(pantalla, punto, RAIZ);
	if (elemP->elem){
        free(elemP);
		return TPAN_HAY_ELEM;}
    free(elemP);
	return TPAN_NO_HAY_ELEM;
}

void Liberar_Elementos(TPantalla* pantalla, int mov){
	TElemPantalla* elemP;
	int err;
	AB_MoverCte(&pantalla->AB, mov, &err);
	elemP=(TElemPantalla*)malloc(sizeof(TElemPantalla));
	AB_ElemCte(pantalla->AB, elemP);
	if (err){
		if(elemP->elem)
			free(elemP->elem);

	}else{
		Liberar_Elementos(pantalla, IZQ);
		Liberar_Elementos(pantalla, DER);
	}
	free(elemP);
}



void Pantalla_Destruir(TPantalla* pantalla){
	Liberar_Elementos(pantalla, RAIZ);
	AB_Vaciar(&pantalla->AB);
}



