#include <stdio.h>
#include <stdlib.h>
#include "propiedades.h"
#include <string.h> /* para que esta? */
int menu ()
{
    char op_menu_char[10];
    int op_menu_int;
    TPropiedades propiedades; /* TPropiedades es el TDA que debidamente ser� creado*/
    char nombre[SIZE_CLAVE];             /* Declar� todas la variables ac�. D�ganme si les parece bien, o si las deber�a declara en el Main.*/
    char* nombres [15];
    char valor[SIZE_VALOR];
    char valorDefault[SIZE_VALOR];
    char rutaArchivo [255];
    /* L�neas 11 a la 56 son el t�pico men� que hac�amos en Algo1. D�gname si hay alg� error.*/

    do
		{
        printf ("Seleccione la opcion deseada\n");
		printf ("1 Crear Propiedad\n");
		printf ("2 Cargar Propiedad\n");
		printf ("3 Guardar Propiedad\n");
		printf ("4 Obtener Propiedad\n");
		printf ("5 Asignar Propiedad\n");
		printf ("6 Existe Propiedad\n");
		printf ("7 Nombre Propiedades\n");
		printf ("8 Eliminar Propiedad\n");
		printf ("9 Destuir Propiedad\n");
		printf ("10 Salir Programa\n");
		scanf ("%s",op_menu_char);
		op_menu_int=atoi(op_menu_char);
		switch (op_menu_int)
		{
		case 1:
		{
		Propiedades_Crear (&propiedades); /* pasa con & porque yo lo declar� como variable y no como puntero a variable*/
		break;
		}
		case 2:
		{
		printf ("Ingrese el Path (i.e. la dirección del Archivo) de propiedades\n");
		scanf (rutaArchivo);
		Propiedades_Cargar(&propiedades,rutaArchivo); /* pasa con & porque yo lo declar� como variable y no como puntero a variable*/
		break;}
		case 3:
		{
		printf ("Ingrese el Path (i.e. la dirección del Archivo) de propiedades\n");
		scanf (rutaArchivo);
		Propiedades_Guardar(propiedades,rutaArchivo);
		break;
		}
		case 4:
		{
        printf("Ingrese nombre de la propiedad\n");
        scanf("%s",nombre);
		Propiedades_Obtener(propiedades,nombre,"NOEXISTE",valor); /* pasa con & porque yo lo declar� como variable y no como puntero a variable*/
		break;
		}
		case 5:
		{
		printf("Ingrese nombre de la propiedad\n");
        scanf("%s",nombre);
        printf("Ingrese valor de la propiedad\n");
        scanf("%s",valor);
		Propiedades_Asignar(&propiedades,nombre,valor);
		break;
		}
		case 6:
		{
		printf("Ingrese nombre de la propiedad\n");
        scanf("%s",nombre);
		Propiedades_Existe(propiedades,nombre);
		break;
		}
		case 7:
		{
		Propiedades_Nombres(propiedades,&nombres[15]);
		break;
		}
		case 8:
		{
		printf("Ingrese nombre de la propiedad\n");
        scanf("%s",nombre);
        Propiedades_Eliminar(&propiedades,nombre);
		break;
		}
		case 9:
		{
		Propiedades_Destruir(&propiedades);
		break;
		}
		} /* cierra el Switch*/
	}
	while (!(op_menu_int==10));
	return 0;
} /* cierra la funci�n menu*/
