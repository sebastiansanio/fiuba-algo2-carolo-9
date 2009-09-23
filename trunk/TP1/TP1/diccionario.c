int Diccionario_Crear(TDiccionario* dicc, int tamanioDato)





/*Es un prototrabajo, el hecho es q todavia no tngo confirmado como funciona la estructura diccionario, sigo dsps*/

void Diccionario_Obtener(TDiccionario dicc, char* clave, void* elem, int tamanioDato)
{
    memcpy(elem,dicc.dicc[buscar_dicc(dicc.dicc,clave,,tamanioDato);
    }

int Diccionario_Existe(TDiccionario dicc, char* clave)
{


int Diccionario_Asignar(TDiccionario* dicc, char* clave, void* elem, int tamanioDato)
{
    if (dicc[clave]<>Null)
    {
        memcpy(dicc.clave,elem,tamanioDato);
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
