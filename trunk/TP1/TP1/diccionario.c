int Diccionario_Crear(TDiccionario* dicc, int tamanioDato)




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
    if ((dicc->dicc[buscar_dicc(dicc,clave,Diccionario_CantidadEntradas(dicc))]->valor)<>NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Diccionario_Obtener(TDiccionario dicc, char* clave, void* elem, int tamanioDato)
{
    memcpy(elem,dicc->dicc[buscar_dicc(dicc,clave,Diccionario_CantidadEntradas(dicc))]->valor,tamanioDato);
    }

int Diccionario_Asignar(TDiccionario* dicc, char* clave, void* elem, int tamanioDato)
{
    if (dicc[clave]<>Null)
    {
        memcpy(dicc->dicc[buscar_dicc(dicc,clave,Diccionario_CantidadEntradas(dicc))]->valor,elem,tamanioDato);
        return 0;
    }
    else
    {
        if (dicc[clave]==Null)&&
        {
            return 1;
        }
    }
}




