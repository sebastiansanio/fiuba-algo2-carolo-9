/*
 * Aca hay que implementar las primitivas definidas en propiedades.h
 */


int Propiedades_Crear(TPropiedades *propiedades);
{
int i;
i=Diccionario_crear(&propiedades.diccionario,sizeof(char)*tamaño);
return i;
}

int Propiedades_Cargar(TPropiedades *propiedades, char *rutaArchivo);
{
    file*arch;
    char auxclave[tamaño];
    char auxvalor[tamaño];
    int i;
    arch=fopen(rutaArchivo,"rt");
    If (arch==NULL)
        return 1;
    else
        while (!feof(arch))
        {
            if !(arch==#)
            fscanf("%s=%s",arch,&auxclave,&auxvalor);
            i=Diccionario_asignar(&propiedades.diccionario,&auxclave,&auxvalor);}
            if (i==0)
                return 0;
            else
                return 2;
        fclose(arch);
}

int Propiedades_Guardar(TPropiedades propiedades, char *rutaArchivo);
{
    typedef char string[tamaño];
    string claves[cantidad];
    char valor[maxvalor];
    file*arch;
    arch=fopen(rutaArchivo,"wt");
    Diccionario_claves(propiedades.diccionario,&claves);
    for (int a=0,claves[a],a++){
        Diccionario_obtener(&propiedades.diccionario,claves[a],valor);
        fprintf("%s=%s",arch,claves[a],valor);
    }
    fclose(arch);
    return 0;
}

int Propiedades_Obtener(TPropiedades propiedades, char *nombre, char *valorDefault, char *valor);
{
    char elem[tamaño];
    elem[0]=NULL;
    Diccionario_Obtener(propiedades.diccionario,nombre,elem);
    if ((elem[0]==NULL) && (*valorDefault=NULL))
        return 1;
    else
        if !elem=NULL{
            *valor=elem;
            return 0;
        }
        else
            {
            *valor=*valorDefault;
            return 0;
            }
    }


int Propiedades_Asignar(TPropiedades *propiedades, char *nombre, char *valor);
{
    int i;
    i=Diccionario_Asignar(propiedades.diccionario,nombre,valor);
    return i;
}


int Propiedades_Existe(TPropiedades propiedades, char *nombre);
{
    int i;
    i=Diccionario_Existe(propiedades.diccionario,*nombre);
    return i;
}

int Propiedades_Nombres(TPropiedades propiedades, char *nombres[]);
{
    Diccionario_Claves(propiedades.diccionario,nombres[]);
    return(Diccionario_CantidadEntradas(propiedades.diccionario));
}

void Propiedades_Eliminar(TPropiedades *propiedades, char *nombre);
{
    Diccionario_Eliminar(propiedades.diccionario,nombre);
}

void Propiedades_Destruir(TPropiedades *propiedades);
{
    Diccionario_Destruir(propiedades.diccionario);
}
