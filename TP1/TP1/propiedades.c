#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "propiedades.h"

int Propiedades_Crear(TPropiedades *propiedades)
{
int i;
i=Diccionario_Crear(&(propiedades->diccionario),SIZE_VALOR);
return i;
}

int Propiedades_Cargar(TPropiedades *propiedades, char *rutaArchivo)
{
    FILE*arch;
    char auxclave[SIZE_CLAVE];
    char auxvalor[SIZE_VALOR];
    int i=-1, error=0;
    arch=fopen(rutaArchivo,"rt");
    if (arch==NULL)
        return 1;
    else{
        while (!feof(arch))
        {
            fscanf(arch,"%[^=]=%s\n",auxclave,auxvalor);
            i=Diccionario_Asignar(&propiedades->diccionario,auxclave,auxvalor);
            if (i)	error=1;
        }
		fclose(arch);
		if (error) return 2;
		return 0;
	}
}

int Propiedades_Guardar(TPropiedades propiedades, char *rutaArchivo)
{
    char* claves[255];
    char valor[SIZE_VALOR];
    int a;
    int b;
    int i;
    FILE*arch;
    b=Diccionario_CantidadEntradas(propiedades.diccionario);
    for(i=0;i<b;i++){claves[i]=malloc(SIZE_CLAVE);}
    arch=fopen(rutaArchivo,"wt");
    Diccionario_Claves(propiedades.diccionario,claves);
    for (a=0;a<b;a++)
    {
        Diccionario_Obtener(propiedades.diccionario,claves[a],valor);
        fprintf(arch,"%s=%s\n",claves[a],valor);
    }
    fclose(arch);
    for(i=0;i<b;i++){free(claves[i]);}
    return 0;
}

int Propiedades_Obtener(TPropiedades propiedades, char *nombre, char *valorDefault, char *valor)
{
    if (Diccionario_Existe(propiedades.diccionario,nombre)){
    	Diccionario_Obtener(propiedades.diccionario,nombre,valor);
	}else{
    	if (valorDefault==NULL)
    		return 1;
    	else
    		strcpy(valor,valorDefault);
	}
    return 0;
}

int Propiedades_Asignar(TPropiedades *propiedades, char *nombre, char *valor)
{
    int i;
    i=Diccionario_Asignar(&(propiedades->diccionario),nombre,valor);
    return i;
}


int Propiedades_Existe(TPropiedades propiedades, char *nombre)
{
    int i;
    i=Diccionario_Existe(propiedades.diccionario,nombre);
    return i;
}

int Propiedades_Nombres(TPropiedades propiedades, char *nombres[])
{   int b;
    int i;
    b=Diccionario_CantidadEntradas(propiedades.diccionario);
    Diccionario_Claves(propiedades.diccionario,nombres);
    return(Diccionario_CantidadEntradas(propiedades.diccionario));
}

void Propiedades_Eliminar(TPropiedades *propiedades, char *nombre)
{
    Diccionario_Eliminar(&(propiedades->diccionario),nombre);
}

void Propiedades_Destruir(TPropiedades *propiedades)
{
    Diccionario_Destruir(&(propiedades->diccionario));
}
