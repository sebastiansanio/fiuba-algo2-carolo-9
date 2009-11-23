#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista de Reproduccion.h"


int main(int argc,char*argv[])
{
    char op_menu_char[10];
    int op_menu_int;
    TLista_Reproduccion Lista_Reproduccion;
    char nomArch[255];
    char criterio_orden[30];
    int validaCreacion=0;
    int cant_temas;
    do
		{
        printf ("\nSeleccione la opcion deseada:\n");
		printf ("1 Abrir nueva lista de reproduccion\n");
		printf ("2 Reproducir canciones\n");
		printf ("3 Avanzar cancion\n");
		printf ("4 Retroceder cancion\n");
		printf ("5 Ordenar canciones\n");
		printf ("6 Guardar lista de reproduccion\n");
		printf ("10 Salir\n");
		scanf ("%s",op_menu_char);
		op_menu_int=atoi(op_menu_char);
		switch (op_menu_int)
		{
		case 1:
		{
			int res;
		    printf ("Ingrese ruta del archivo lista de reproduccion.\n");
		    scanf("%s",nomArch);
			if (validaCreacion!=0){
				destruir_Lista_Reproduccion(&Lista_Reproduccion);
				validaCreacion=0;
			}
			res = crear_Lista_Reproduccion(&Lista_Reproduccion,nomArch);
			switch (res){
				case 0:
					printf ("Lista de reproduccion cargada.\n");
					validaCreacion=1;
					break;
				case 2:
					printf ("Error abriendo el archivo.\n");
					break;
			}
			break;
		}
		case 2:
		{
			if(validaCreacion==0)
			{
			    printf ("No hay lista de reproduccion cargada\n");
            }
			else
			{
			    printf("Ingrese cantidad de temas a reproducir\n");
			    scanf("%d",&cant_temas);
			    printf("La lista recomenzo %d veces\n",reproducir_Lista_Reproduccion(Lista_Reproduccion,cant_temas));
			}
            break;
		}
		case 3:
		{
			if(validaCreacion==0)
			{
			    printf ("No hay lista de reproduccion cargada\n");
            }
			else
			{
			    adelantar_Lista_Reproduccion(&Lista_Reproduccion);
			}
			break;
		}
		case 4:
		{
		    if(validaCreacion==0)
		    {
		        printf ("No hay lista de reproduccion cargada\n");
            }
			else
			{
			    retroceder_Lista_Reproduccion(&Lista_Reproduccion);
			}
			break;
		}
		case 5:
		{
		    if (validaCreacion==0)
		    {
                printf("No hay lista de reproduccion cargada\n");
            }
			else
			{
			    do
			    {
			    printf("Ingrese criterio de ordenamiento\n");
                printf("\"ARTISTA\",\"ALBUM\",\"TITULO\",\"GENERO\",\"AUTOR\",\"ANIO_EDICION\",\"TAPA_ALBUM\",\"SHUFFLE\",\"INVERTIR\"\n");
                scanf("%s",criterio_orden);
                    if (!strcmp(criterio_orden,"ARTISTA") || !strcmp(criterio_orden,"ALBUM") || !strcmp(criterio_orden,"TITULO")
                    || !strcmp(criterio_orden,"AUTOR") || !strcmp(criterio_orden,"GENERO") ||
                     !strcmp(criterio_orden,"ANIO_EDICION") || !strcmp(criterio_orden,"TAPA_ALBUM") ||
                     !strcmp(criterio_orden,"SHUFFLE") || !strcmp(criterio_orden,"INVERTIR"))
                    {
                        ordenar_Lista_Reproduccion(&Lista_Reproduccion,criterio_orden);
                        printf("Lista ordenada segun %s\n",criterio_orden);
                        break;
                    }
                    else
                        printf("Criterio incorrecto \n \n");
			    }
                while (!0);
			}
			break;
		}
		case 6:
		{
			if (validaCreacion==0)
			{
                printf("No hay lista de reproduccion cargada\n");
            }
			else
			{
				int res;
			    printf("Ingrese ruta donde desea guardar el archivo \n");
			    scanf("%s",nomArch);
                res = guardar_Lista_Reproduccion(&Lista_Reproduccion,nomArch);
                switch (res){
					case 0:	printf("Lista de reproduccion guardada. \n"); break;
					case 3:	printf("No se pudo crear el archivo. \n"); break;
					case 4:	printf("Ya existe un archivo con ese nombre. \n"); break;
                }
			}
			break;
		}
		case 10:
		{
		    if (validaCreacion!=0)
		    {
				destruir_Lista_Reproduccion(&Lista_Reproduccion);
				validaCreacion=0;
			}
		    break;
		}
		default: printf("Opcion incorrecta\n\n");
        } /* cierra el Switch*/
	}while (op_menu_int!=10);
	return 0;
}
