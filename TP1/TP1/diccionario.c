int Diccionario_Crear(TDiccionario* dicc, int tamanioDato)      /*Seguire mañana dsps de las 15hs chequeen el codigo*/




int Diccionario_CantidadEntradas(TDiccionario dicc)
{
    int cantidad;
    cantidad=0;
    while ((dicc->dicc[cantidad]->clave)<>NULL)
    {
        cantidad=cantidad++;
    }
    return cantidad;
}

int Diccionario_Existe(TDiccionario dicc, char* clave)
{
    if ((dicc->dicc[buscar_dicc(dicc,* clave,Diccionario_CantidadEntradas(dicc))]->valor)<>NULL)            /*Comprueba la existencia de un elemnto, buscandolo primero*/
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Diccionario_Obtener(TDiccionario dicc, char* clave, void* elem)
{
    memcpy(elem,dicc->dicc[buscar_dicc(dicc,* clave,Diccionario_CantidadEntradas(dicc))]->valor,dicc->tamanioDato);         /*Busca el elemento en el diccionario y lo copia en una variable*/
    }

int Diccionario_Asignar(TDiccionario* dicc, char* clave, void* elem, int tamanioDato)
{
    int posicion;
    int NumEnt;
    NumEnt=Diccionario_CantidadEntradas(* dicc);            /*Recupera el valor de la cantidad de elemntos*/
    posicion=buscar_dicc(* dicc,* clave,Diccionario_CantidadEntradas(* dicc));    /*Busca la posición en la que esta la clave*/
    if (posicion=NULL)&&(NumEnt<MaxCantEnt)
    {                                                                   /*Si la clave no existe, la agrega al final*/
        posicion==NumEnt+1;
        memcpy(dicc->dicc[posicion]->clave,clave,tamanioDato);
    }
    if ((dicc->dicc[posicion]->valor)<>NULL)||(NumEnt<MaxCantEnt)           /*Se fija si se puede escribir o si diccionario esta lleno*/
    {
        memcpy(dicc->dicc[posicion]->valor,elem,tamanioDato);
        return 0;
    }
    else
    {
            return 1;
    }
}




