#include <stdio.h>
#include <stdlib.h>
#include "Lista de Reproduccion.h"


int main()
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
		printf ("3 Avanzar canción\n");
		printf ("4 Retroceder canción\n");
		printf ("5 Ordenar canciones\n");
		printf ("6 Guardar lista de reproduccion\n");
		printf ("10 Salir\n");
		scanf ("%s",op_menu_char);
		op_menu_int=atoi(op_menu_char);
		switch (op_menu_int)
		{
		case 1:
		{
		    printf ("Ingrese ruta del archivo lista de reproduccion.\n");
		    scanf("%s",nomArch);
			if (validaCreacion==0)
			{
				crear_Lista_Reproduccion(&Lista_Reproduccion,nomArch);
				printf ("Lista de reproduccion cargada.\n");
				validaCreacion=1;
			}
            else
            {
                destruir_Lista_Reproduccion(&Lista_Reproduccion);
                crear_Lista_Reproduccion(&Lista_Reproduccion,nomArch);
                printf ("Nueva lista de reproduccion cargada.\n");
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
			    printf("Ingrese cantidad de temas a reproducir");
			    scanf("%d",&cant_temas);
			    printf("La lista recomenzo %d veces",reproducir_Lista_Reproduccion(Lista_Reproduccion,cant_temas));
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
			    adelantar_Lista_Reproduccion(Lista_Reproduccion);
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
			    retroceder_Lista_Reproduccion(Lista_Reproduccion);
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
			    printf("Ingrese criterio de ordenamiento\n");
                printf("\"ARTISTA\",\"ALBUM\",\"TITULO\",\"GENERO\",\"AUTOR\",\"ANIO_EDICION\",\"TAPA_ALBUM\",\"SHUFFLE\",\"INVERTIR\"\n");
                scanf("%s",criterio_orden);
                ordenar_Lista_Reproduccion(&Lista_Reproduccion,criterio_orden);
                printf("Lista ordenada segun %s\n",criterio_orden);
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
			    printf("Ingrese ruta donde desea guardar el archivo");
			    scanf("%s",nomArch);
                guardar_Lista_Reproduccion(&Lista_Reproduccion,nomArch);
                printf("Lista de reproduccion guardada");
			}
			break;
		}
        } /* cierra el Switch*/
	}while (op_menu_int!=10);
	return 0;
}
