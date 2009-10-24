#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista de Reproduccion.h"
#define RES_FOPEN_FAILED 2
#define RES_OUT_OF_MEM 1

void* clonar_Propiedades(void* propiedades);
void destruir_Propiedades(void* propiedades);

int crear_Lista_Reproduccion(TLista_Reproduccion* listaReproduccion, char* nomArch)
{
	FILE* arch_m3u;
	f_destruir destructor;
	f_clonar clonador;

	destructor = destruir_Propiedades;
	clonador = clonar_Propiedades;

	arch_m3u = fopen(nomArch,"r");
	if (!arch_m3u){return RES_FOPEN_FAILED;}

	crear_Lista_DEC(&listaReproduccion->lista, clonador, destructor);

	while (!feof(arch_m3u)){
		char linea[255],rutaProp[255];
		TPropiedades propiedad;
		Propiedades_Crear(&propiedad);

		fscanf(arch_m3u, "%[^\n]\n", &linea);
		if(!sscanf(linea,"#%[^#\n]", rutaProp)){
			rutaProp[0]='\0';
		}
		if (rutaProp[0]){
			if(!Propiedades_Cargar(&propiedad, rutaProp)){
				insertar_En_Lista_DEC(&listaReproduccion->lista,&propiedad,Siguiente); /*Insertar en la lista como siguiente.*/
			}
		}
	}

	return 0;
}

int reproducir_Lista_Reproduccion(TLista_Reproduccion listaReproduccion, int cantidad)
{
return 0;
}

int adelantar_Lista_Reproduccion(TLista_Reproduccion listaReproduccion)
{
return 0;
}

int retroceder_Lista_Reproduccion(TLista_Reproduccion listaReproduccion)
{
return 0;
}

int ordenar_Lista_Reproduccion(TLista_Reproduccion* listaReproduccion, char* orden)
{
return 0;
}

int guardar_Lista_Reproduccion(TLista_Reproduccion* listaReproduccion, char* nomArch)
{
return 0;
}

int destruir_Lista_Reproduccion(TLista_Reproduccion* listaReproduccion)
{
return 0;
}

void* clonar_Propiedades(void* propiedades){
	char *nombres[SIZE_CLAVE], *valor;
	int i,cant;
	TPropiedades *prop_clon = (TPropiedades*) malloc(sizeof(TPropiedades));
	TPropiedades *prop_orig = (TPropiedades*)propiedades;
	if (!prop_clon){return NULL;}

	Propiedades_Crear(prop_clon);
	cant=Propiedades_Nombres(*prop_clon,nombres);
	for (i=0;i<cant;i++){
		Propiedades_Obtener(*prop_orig,nombres[i],NULL,valor);
		Propiedades_Asignar(prop_clon,nombres[i],valor);
	}

	return prop_clon;
}

void destruir_Propiedades(void* propiedades){
    propiedades = (TPropiedades*)propiedades;
	Propiedades_Destruir(propiedades);
}
