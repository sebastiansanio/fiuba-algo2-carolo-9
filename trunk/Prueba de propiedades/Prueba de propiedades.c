#include <stdio.h>
#include <stdlib.h>
#define SIZE_CLAVE 20
#define SIZE_DICC 20
#define SIZE_VALOR 20

int main()
{
    /*DEFINICION DE TIPOS*/
    typedef struct
    {
	char clave[SIZE_CLAVE];
	void *elem;
}TEntrada;
typedef struct {
	TEntrada entradas[SIZE_DICC];
	int size_elem;
}TDiccionario;

    typedef struct{
	TDiccionario diccionario;} TPropiedades;
	/*FIN DE DEFINICION DE TIPOS*/

TPropiedades propiedades;
void* elem;
char rutaArchivo[30];


int Propiedades_Crear(TPropiedades *propiedades);
{
int i;
i=Diccionario_Crear(&propiedades.diccionario,sizeof(char)*SIZE_VALOR);
return i;
}

int Propiedades_Cargar(TPropiedades *propiedades, char *rutaArchivo);
{
    FILE*arch;
    char auxclave[SIZE_CLAVE];
    char auxvalor[SIZE_VALOR];
    int i;
    arch=fopen(rutaArchivo,"rt");
    if (arch==NULL)
        return 1;
    else
        while (!feof(arch))
        {
            fscanf(arch,"%s=%s\n",auxclave,auxvalor);
            i=Diccionario_Asignar(&propiedades.diccionario,auxclave,&auxvalor);}
            if (i==0)
                return 0;
            else
                return 2;
        fclose(arch);
}

int Propiedades_Guardar(TPropiedades propiedades, char *rutaArchivo);
{
    typedef char string[SIZE_CLAVE];
    string claves[SIZE_DICC];
    char valor[SIZE_VALOR];
    FILE*arch;
    arch=fopen(rutaArchivo,"wt");
    Diccionario_Claves(propiedades.diccionario,&claves[0]);
    for (int a=0,claves[a],a++){
        Diccionario_obtener(&propiedades.diccionario,claves[a],valor);
        fprintf("%s=%s\n",arch,claves[a],valor);
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

}
