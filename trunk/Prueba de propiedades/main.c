#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
char nombre[SIZE_CLAVE];
char valorDefault[SIZE_VALOR];
char valor[SIZE_VALOR];
char* (nombres[SIZE_DICC]);

int Diccionario_Crear(TDiccionario* dicc, int tamanioDato);
{return 0;}

void Diccionario_Obtener(TDiccionario dicc, char* clave, void* elem);
{elem="prueba";}

int Diccionario_Asignar(TDiccionario* dicc, char* clave, void* elem);

int Diccionario_Existe(TDiccionario dicc, char* clave);

void Diccionario_Claves(TDiccionario dicc, char* claves[]);

int Diccionario_CantidadEntradas(TDiccionario dicc);

void Diccionario_Eliminar(TDiccionario* dicc, char* clave);

void Diccionario_Destruir(TDiccionario* dicc);

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
    char* (claves[SIZE_DICC]);
    char valor[SIZE_VALOR];
    int a;
    int b;
    FILE*arch;
    b=Diccionario_CantidadEntradas(propiedades.diccionario);
    arch=fopen(rutaArchivo,"wt");
    Diccionario_Claves(propiedades.diccionario,claves);
    for (a=0;a<b;a++)
    {
        Diccionario_Obtener(propiedades.diccionario,claves[a],valor);
        fprintf(arch,"%s=%s\n",claves[a],valor);
    }
    fclose(arch);
    return 0;
}

int Propiedades_Obtener(TPropiedades propiedades, char *nombre, char *valorDefault, char *valor);
{
    char elem[SIZE_VALOR];
    elem[0]=0;
    Diccionario_Obtener(propiedades.diccionario,nombre,elem);
    if ((elem[0]==0) && (!(strcmp(valorDefault,"NULL"))))
        return 1;
    else
        if (!(elem[0]==0)){
            strcpy(valor,elem);
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
    i=Diccionario_Asignar(&propiedades.diccionario,nombre,valor);
    return i;
}


int Propiedades_Existe(TPropiedades propiedades, char *nombre);
{
    int i;
    i=Diccionario_Existe(propiedades.diccionario,nombre);
    return i;
}

int Propiedades_Nombres(TPropiedades propiedades, char *nombres[]);
{
    Diccionario_Claves(propiedades.diccionario,nombres);
    return(Diccionario_CantidadEntradas(propiedades.diccionario));
}

void Propiedades_Eliminar(TPropiedades *propiedades, char *nombre);
{
    Diccionario_Eliminar(&propiedades.diccionario,nombre);
}

void Propiedades_Destruir(TPropiedades *propiedades);
{
    Diccionario_Destruir(&propiedades.diccionario);
}

}
