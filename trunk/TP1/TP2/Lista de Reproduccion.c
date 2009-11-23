#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>  /*libreria de la funcion sleep. NOTA: Es UNIX no ANSI*/
#include "Lista de Reproduccion.h"
#define RES_FOPEN_FAILED 2
#define RES_OUT_OF_MEM -2
#define RES_COULD_NOT_CREATE_FILE 3
#define RES_FILE_EXISTS 4
#define RES_EMPTY_LIST 5
#define RES_OK 0

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
				/* se cargo la propiedad y agrego la ruta a los archivos*/
				int i;
				Propiedades_Asignar(&propiedad, "rutaProp", rutaProp);
				do{
					i=fscanf(arch_m3u, "%[^#\n]\n", &linea);
					if (!i){fscanf(arch_m3u, "%*[^\n]\n");}/* Leemos e ignoramos la linea */
				}while(!i);
				Propiedades_Asignar(&propiedad, "rutaCancion", linea);
				insertar_En_Lista_DEC(&listaReproduccion->lista, &propiedad, LDEC_POS_SIG); /*Insertar en la lista como siguiente.*/
			}
		}
	}
    mover_Cte_Lista_DEC(&listaReproduccion->lista,LDEC_POS_SIG);
	Diccionario_Crear(&(listaReproduccion->dicc_alias),SIZE_CLAVE);/* Guarda las claves representadas por los ordenes validos. */
	/*strcpy(orden,"");
	strcpy(alias,"");
	Diccionario_Asignar(&listaReproduccion->dicc_alias, orden, alias);*/

	Diccionario_Asignar(&listaReproduccion->dicc_alias, "ARTISTA", "artista");
	Diccionario_Asignar(&listaReproduccion->dicc_alias, "ALBUM", "album");
	Diccionario_Asignar(&listaReproduccion->dicc_alias, "TITULO", "titulo");
	Diccionario_Asignar(&listaReproduccion->dicc_alias, "GENERO", "genero");
	Diccionario_Asignar(&listaReproduccion->dicc_alias, "AUTOR", "autor");
	Diccionario_Asignar(&listaReproduccion->dicc_alias, "ANIO_EDICION", "anio_edicion");
	Diccionario_Asignar(&listaReproduccion->dicc_alias, "TAPA_ALBUM", "tapa_album");
	Diccionario_Asignar(&listaReproduccion->dicc_alias, "SHUFFLE", "SHUFFLE");
	Diccionario_Asignar(&listaReproduccion->dicc_alias, "INVERTIR", "INVERTIR");

	return 0;
}

/*PRE: La lista debe estar creada, cantidad debe ser un parametro valido*/
/*POST: Muestra por pantalla el n�mero indicado de temas, repitiendoles en caso de ser necesario, devuelve la cantidad de veces que llego al ultimo elemento*/
int reproducir_Lista_Reproduccion(TLista_Reproduccion listaReproduccion, int cantidad)
{
	int i,contador;
	TPropiedades* cancion;
	char titulo[SIZE_VALOR], clave_del_alias[SIZE_CLAVE];

	if(vacia_Lista_DEC(&(listaReproduccion.lista))){return RES_EMPTY_LIST;}
	contador=0;
	Diccionario_Obtener(listaReproduccion.dicc_alias,"TITULO",clave_del_alias);
	for (i=0;i<cantidad;i++){
		obtener_Cte_Lista_DEC(listaReproduccion.lista,(void**)&cancion);
		Propiedades_Obtener(*cancion, clave_del_alias, "N/A", titulo);
		printf("%s\n",titulo);
	/*	sleep(1);  */
		mover_Cte_Lista_DEC(&(listaReproduccion.lista),LDEC_POS_SIG);
		if(es_Primero_Lista_DEC(&(listaReproduccion.lista))){contador++;}}
	return contador;
}

int adelantar_Lista_Reproduccion(TLista_Reproduccion* listaReproduccion)
{
	TPropiedades* cancion;
	char titulo[SIZE_VALOR], clave_del_alias[SIZE_CLAVE];

	Diccionario_Obtener(listaReproduccion->dicc_alias,"TITULO",clave_del_alias);
	if(mover_Cte_Lista_DEC(&(listaReproduccion->lista),LDEC_POS_SIG)){return 1;}
	obtener_Cte_Lista_DEC(listaReproduccion->lista,(void**)&cancion);
	Propiedades_Obtener(*cancion, clave_del_alias, "N/A", titulo);
	printf("%s\n",titulo);
	return 0;
}

int retroceder_Lista_Reproduccion(TLista_Reproduccion* listaReproduccion)
{
	TPropiedades* cancion;
	char titulo[SIZE_VALOR], clave_del_alias[SIZE_CLAVE];

	Diccionario_Obtener(listaReproduccion->dicc_alias,"TITULO",clave_del_alias);
	if(mover_Cte_Lista_DEC(&(listaReproduccion->lista),LDEC_POS_ANT)){return 1;}
	obtener_Cte_Lista_DEC(listaReproduccion->lista,(void**)&cancion);
	Propiedades_Obtener(*cancion, clave_del_alias, "N/A", titulo);
	printf("%s\n",titulo);
	return 0;
}

int ordenar_Lista_Reproduccion(TLista_Reproduccion* listaReproduccion, char* orden)
{
	TLista_DEC *LDEC_aux;
	TPropiedades *cancion1, *cancion2;
	f_destruir destructor = destruir_Propiedades;
	f_clonar clonador = clonar_Propiedades;
	char valor1[SIZE_VALOR], valor2[SIZE_VALOR], nombre_campo[SIZE_CLAVE];
	int res_cmp;

	LDEC_aux = (TLista_DEC *) malloc(sizeof(TLista_DEC));
	if(!LDEC_aux){return RES_OUT_OF_MEM;}
	crear_Lista_DEC(LDEC_aux, clonador, destructor);
	mover_Cte_Lista_DEC(&(listaReproduccion->lista),LDEC_POS_PRI);
    if (!strcmp(orden,"INVERTIR")){
            mover_Cte_Lista_DEC(&(listaReproduccion->lista),LDEC_POS_ANT);
            obtener_Cte_Lista_DEC(listaReproduccion->lista,(void**)&cancion1);
            insertar_En_Lista_DEC(LDEC_aux, cancion1, LDEC_POS_PRI);
            while(!es_Primero_Lista_DEC(&listaReproduccion->lista)){
            	mover_Cte_Lista_DEC(&(listaReproduccion->lista),LDEC_POS_ANT);
                obtener_Cte_Lista_DEC(listaReproduccion->lista,(void**)&cancion1);
                insertar_En_Lista_DEC(LDEC_aux, cancion1, LDEC_POS_SIG);
            }
            mover_Cte_Lista_DEC(LDEC_aux,LDEC_POS_PRI);
    }else if(!strcmp(orden,"SHUFFLE")){
    	do {
    		int i = rand() / (int)(RAND_MAX / 30);
			obtener_Cte_Lista_DEC(listaReproduccion->lista,(void**)&cancion1);
			for (;i>0;i--){mover_Cte_Lista_DEC(LDEC_aux, LDEC_POS_SIG);}
			insertar_En_Lista_DEC(LDEC_aux, cancion1, LDEC_POS_ANT);
			mover_Cte_Lista_DEC(&(listaReproduccion->lista),LDEC_POS_SIG);
		} while (!es_Primero_Lista_DEC(&listaReproduccion->lista));
    }else{
            Diccionario_Obtener(listaReproduccion->dicc_alias, orden, nombre_campo);/* Obtengo en "nombre_campo" la clave para la propiedad.*/
            /*
            El siguiente codigo depende de que LDEC_aux tenga al menos una primera cancion.
            Se copia a LDEC_aux la primera cancion de LDEC y si no hay una segunda cancion, LDEC ya estaba ordenada.
            */
            obtener_Cte_Lista_DEC(listaReproduccion->lista,(void**)&cancion1);
            insertar_En_Lista_DEC(LDEC_aux, cancion1, LDEC_POS_PRI);
            mover_Cte_Lista_DEC(&(listaReproduccion->lista), LDEC_POS_SIG);
            if (es_Primero_Lista_DEC(&listaReproduccion->lista))return RES_OK;

            do {
                obtener_Cte_Lista_DEC(listaReproduccion->lista,(void**)&cancion1);
                Propiedades_Obtener(*cancion1, nombre_campo, NULL, valor1);
                while (!0){
                    obtener_Cte_Lista_DEC(*LDEC_aux,(void**)&cancion2);
                    Propiedades_Obtener(*cancion2, nombre_campo, NULL, valor2);
                    res_cmp=strcmp(valor1, valor2);
                    if (res_cmp<0){
                        insertar_En_Lista_DEC(LDEC_aux, cancion1, LDEC_POS_ANT);
                        break;
                    }
                    mover_Cte_Lista_DEC(LDEC_aux, LDEC_POS_SIG);
                    if (es_Primero_Lista_DEC(LDEC_aux)){
                        mover_Cte_Lista_DEC(LDEC_aux, LDEC_POS_ANT);
                        insertar_En_Lista_DEC(LDEC_aux, cancion1, LDEC_POS_SIG);
                        break;
                    }
                }
                mover_Cte_Lista_DEC(&(listaReproduccion->lista),LDEC_POS_SIG);
                mover_Cte_Lista_DEC(LDEC_aux,LDEC_POS_PRI);
            } while (!es_Primero_Lista_DEC(&listaReproduccion->lista));
        }
    destruir_Lista_DEC(&(listaReproduccion->lista));
	listaReproduccion->lista=*LDEC_aux;

return RES_OK;
}

int guardar_Lista_Reproduccion(TLista_Reproduccion* listaReproduccion, char* nomArch)
{
	FILE* nuevo_m3u;
	TPropiedades* cancion;
	char rutaProp[SIZE_VALOR], rutaCancion[SIZE_VALOR];

	nuevo_m3u = fopen(nomArch, "rt");
	if (nuevo_m3u){return RES_FILE_EXISTS;}
	nuevo_m3u = fopen(nomArch, "wt");
	if (!nuevo_m3u){return RES_COULD_NOT_CREATE_FILE;}
	/* Aca hay que escribir en el archivo las rutas a las propiedades y las canciones en el orden actual. */
	mover_Cte_Lista_DEC(&listaReproduccion->lista, LDEC_POS_PRI);
	obtener_Cte_Lista_DEC(listaReproduccion->lista,(void**)&cancion);
	do{
		Propiedades_Obtener(*cancion, "rutaProp", "N/A", rutaProp);
		Propiedades_Obtener(*cancion, "rutaCancion", "N/A", rutaCancion);
		fputs("#",nuevo_m3u);
		fputs(rutaProp,nuevo_m3u);
		fputs("\n",nuevo_m3u);
		fputs(rutaCancion,nuevo_m3u);
		fputs("\n",nuevo_m3u);
		mover_Cte_Lista_DEC(&listaReproduccion->lista, LDEC_POS_SIG);
		obtener_Cte_Lista_DEC(listaReproduccion->lista,(void**)&cancion);
	} while (!es_Primero_Lista_DEC(&listaReproduccion->lista));
	fclose(nuevo_m3u);
return 0;
}

int destruir_Lista_Reproduccion(TLista_Reproduccion* listaReproduccion)
{
	Diccionario_Destruir(&(listaReproduccion->dicc_alias));
	destruir_Lista_DEC(&(listaReproduccion->lista));
return 0;
}

void* clonar_Propiedades(void* propiedades){
	char *nombres[9], valor[SIZE_VALOR];
	int i,cant;
	TPropiedades *prop_clon = (TPropiedades*) malloc(sizeof(TPropiedades));
	TPropiedades *prop_orig = (TPropiedades*)propiedades;
	if (!prop_clon){return NULL;}
	for (i=0; i<9; i++){
		nombres[i] = malloc(SIZE_CLAVE * sizeof(char));
		if(!nombres[i]){
			for (; i>-1; i--){
				free(nombres[i]);
			}
			return NULL;
		}
	}

	Propiedades_Crear(prop_clon);
	cant=Propiedades_Nombres(*prop_orig,nombres);
	for (i=0;i<cant;i++){
		Propiedades_Obtener(*prop_orig,nombres[i],NULL,valor);
		Propiedades_Asignar(prop_clon,nombres[i],valor);
	}
	for (i=0; i<9; i++){
		free(nombres[i]);
	}
	return prop_clon;
}

void destruir_Propiedades(void* propiedades){
	propiedades = (TPropiedades*)propiedades;
	Propiedades_Destruir(propiedades);
}
