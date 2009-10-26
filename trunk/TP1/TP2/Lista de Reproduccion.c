#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>  /*libreria de la función sleep. NOTA: Es UNIX no ANSI*/
#include "Lista de Reproduccion.h"
#define RES_FOPEN_FAILED 2
#define RES_OUT_OF_MEM 1
#define RES_COULD_NOT_CREATE_FILE 3
#define RES_FILE_EXISTS 4
#define RES_EMPTY_LIST 5

void* clonar_Propiedades(void* propiedades);
void destruir_Propiedades(void* propiedades);

int crear_Lista_Reproduccion(TLista_Reproduccion* listaReproduccion, char* nomArch)
{
	FILE* arch_m3u;
	f_destruir destructor = destruir_Propiedades;
	f_clonar clonador = clonar_Propiedades;

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
		}else{
			if(!Propiedades_Cargar(&propiedad, rutaProp)){
				insertar_En_Lista_DEC(&listaReproduccion->lista,&propiedad,LDEC_POS_SIG); /*Insertar en la lista como siguiente.*/
			}
		}
	}

	Diccionario_Crear(&(listaReproduccion->dicc_alias),SIZE_CLAVE);/* Guarda las claves representadas por los ordenes validos. */
	Diccionario_Asignar(listaReproduccion->dicc_alias, "ARTISTA", "artista");
	Diccionario_Asignar(listaReproduccion->dicc_alias, "ALBUM", "album");
	Diccionario_Asignar(listaReproduccion->dicc_alias, "TITULO", "titulo");
	Diccionario_Asignar(listaReproduccion->dicc_alias, "GENERO", "genero");
	Diccionario_Asignar(listaReproduccion->dicc_alias, "AUTOR", "autor");
	Diccionario_Asignar(listaReproduccion->dicc_alias, "ANIO_EDICION", "anio_edicion");
	Diccionario_Asignar(listaReproduccion->dicc_alias, "TAPA_ALBUM", "tapa_album");
	Diccionario_Asignar(listaReproduccion->dicc_alias, "SHUFFLE", "SHUFFLE");
	Diccionario_Asignar(listaReproduccion->dicc_alias, "INVERTIR", "INVERTIR");

	return 0;
}

/*PRE: La lista debe estar creada, cantidad debe ser un parametro valido*/
/*POST: Muestra por pantalla el número indicado de temas, repitiendoles en caso de ser necesario, devuelve la cantidad de veces que llego al ultimo elemento*/
int reproducir_Lista_Reproduccion(TLista_Reproduccion listaReproduccion, int cantidad)
{int i,contador;
void** elemento;
char* valorDef, *titulo;
void* clave_del_alias;
if(mover_Cte_Lista_DEC(&(listaReproduccion.lista),LDEC_POS_PRI)){return RES_EMPTY_LIST;};
contador=0;
Diccionario_Obtener(listaReproduccion.dicc_alias,"TITULO",clave_del_alias);
for (i=0,i<cantidad,i++){
    obtener_Cte_Lista_DEC(listaReproduccion.lista,elemento);
    Propiedades_Obtener(*((TPropiedades*)*elemento),(char*)clave_del_alias,valorDef,titulo);
    printf("%s\n",titulo);
    sleep(1);
    mover_Cte_Lista_DEC(&(listaReproduccion.lista),LDEC_POS_SIG);
    if(!(es_Primero_Lista_DEC(&(listaReproduccion.lista))){contador=contador++;}}
return contador;
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
	TLista_DEC *LDEC_aux;
	TPropiedades cancion1, cancion2;
	f_destruir destructor = destruir_Propiedades;
	f_clonar clonador = clonar_Propiedades;
	char *valor1, *valor2, nombre_campo[SIZE_CLAVE];
	int res_cmp, res_mov;

	LDEC_aux = (TLista_DEC *) malloc(sizeof(TLista_DEC));
	if(!LDEC_aux){return RES_OUT_OF_MEM;}
	crear_Lista_DEC(LDEC_aux, clonador, destructor);
	mover_Cte_Lista_DEC(listaReproduccion->lista,LDEC_POS_PRI);

	Diccionario_Obtener(listaReproduccion->dicc_alias, orden, nombre_campo);/* Obtengo en "nombre_campo" la clave para la propiedad.*/
	/*
	El siguiente codigo depende de que LDEC_aux tenga al menos una primera cancion.
	Se copia a LDEC_aux la primera cancion de LDEC y si no hay una segunda cancion, LDEC ya estaba ordenada.
	*/
	obtener_Cte_Lista_DEC(listaReproduccion->lista, &cancion1);
	insertar_En_Lista_DEC(LDEC_aux,LDEC_POS_PRI,&cancion1);
	mover_Cte_Lista_DEC(&(listaReproduccion->lista),LDEC_POS_SIG);
	if (es_Primero_Lista_DEC(listaReproduccion->lista))return RES_OK;

	do {
		obtener_Cte_Lista_DEC(listaReproduccion->lista, &cancion1);
		Propiedades_Obtener(cancion1, nombre_campo, valor1);
		while (!0){
			obtener_Cte_Lista_DEC(*LDEC_aux, &cancion2);
			Propiedades_Obtener(cancion2, nombre_campo, valor2);
			res_cmp=strcmp(valor1,valor2);
			if (res_cmp<0){
				insertar_En_Lista_DEC(LDEC_aux,LDEC_POS_ANT,&cancion1);
				break;
			}
			mover_Cte_Lista_DEC(LDEC_aux,LDEC_POS_SIG);
			if (es_Primero_Lista_DEC(*LDEC_aux)){
				insertar_En_Lista_DEC(LDEC_aux,LDEC_POS_ANT,&cancion1);
				break;
			}
		}
		mover_Cte_Lista_DEC(&(listaReproduccion->lista),LDEC_POS_SIG);
		mover_Cte_Lista_DEC(LDEC_aux,LDEC_POS_PRI);
	} while (es_Primero_Lista_DEC(listaReproduccion->lista));

	destruir_Lista_DEC(&(listaReproduccion->lista));
	&(listaReproduccion->lista)=LDEC_aux;

return 0;
}

int guardar_Lista_Reproduccion(TLista_Reproduccion* listaReproduccion, char* nomArch)
{
	FILE* nuevo_m3u;

	nuevo_m3u = fopen(nomArch, "rt");
	if (nuevo_m3u){return RES_FILE_EXISTS;}
	nuevo_m3u = fopen(nomArch, "wt");
	if (!nuevo_m3u){return RES_COULD_NOT_CREATE_FILE;}
	/* Aca hay que escribir en el archivo las rutas a las propiedades y las canciones en el orden actual. */

return 0;
}

int destruir_Lista_Reproduccion(TLista_Reproduccion* listaReproduccion)
{
	Diccionario_Destruir(&(listaReproduccion->dicc_alias));
	destruir_Lista_DEC(&(listaReproduccion->lista));
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
