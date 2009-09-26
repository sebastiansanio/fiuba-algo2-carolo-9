#include <stdio.h>
#include <stdlib.h>
#include "propiedades.h"
#include <string.h> /* para que esta? */
int menu ()
{
    char* op_menu_char;
    int op_menu_int;
    TPropiedades propiedades; /* TPropiedades es el TDA que debidamente ser� creado*/
    char nombre;             /* Declar� todas la variables ac�. D�ganme si les parece bien, o si las deber�a declara en el Main.*/
    char* nombres [15];
    char valor;
    char valorDefault;
    char rutaArchivo [255];
    /* L�neas 11 a la 56 son el t�pico men� que hac�amos en Algo1. D�gname si hay alg� error.*/

    printf ("Seleccione la opci�n deseada\n");
		printf ("1 Crear Propiedad\n");
		printf ("2 Cargar Propiedad\n");
		printf ("3 Guardar Propiedad\n");
		printf ("4 Obtener Propiedad\n");
		printf ("5 Asignar Propiedad\n");
		printf ("6 Existe Propiedad\n");
		printf ("7 Nombre Propiedad\n");
		printf ("8 Eliminar Propiedad\n");
		printf ("9 Destuir Propiedad\n");
		printf ("0 Salir Programa\n");

    do
		{
		scanf ("%c",&op_menu_char);
		op_menu_int=atoi(op_menu_char);
		}
		while
		(op_menu_int > 57 || op_menu_int < 48); /* ASCII de 0-9 == 48-57 . Si estamos fuera del rango repite.*/

    while (op_menu_int > 57 || op_menu_int < 48)/* Este ciclo termina cuando se ingresa la opcion de salir, en virtud de un "return 0". */
    {                                           /* la idea estaba buena, pero lo optimicé, lo hize como un while clásico, asi es más robusto. además, me parece que antes no entraba al primer ciclo*/
		switch (op_menu_int)
		{
		case 49:
		Propiedades_Crear (&propiedades); /* pasa con & porque yo lo declar� como variable y no como puntero a variable*/
		case 50:
		printf ("Ingrese el Path (i.e. la dirección del Archivo) de propiedades\n");
		scanf (rutaArchivo);
		Propiedades_Cargar(&propiedades,rutaArchivo); /* pasa con & porque yo lo declar� como variable y no como puntero a variable*/
		printf ("Ingrese el Path (i.e. la dirección del Archivo) de propiedades\n");
		scanf (rutaArchivo);
		case 51:
		Propiedades_Guardar(propiedades,rutaArchivo);
		case 52:
		Propiedades_Obtener(propiedades,&nombre,&valorDefault,&valor); /* pasa con & porque yo lo declar� como variable y no como puntero a variable*/
		case 53:
		Propiedades_Asignar(&propiedades,&nombre,&valor);
		case 54:
		Propiedades_Existe(propiedades,&nombre);
		case 55:
		Propiedades_Nombres(propiedades,&nombres[15]);
		case 56:
		Propiedades_Eliminar(&propiedades,&nombre);
		case 57:
		Propiedades_Destruir(&propiedades);
		case 48:
            return 0;

		} /* cierra el Switch*/

		printf ("Seleccione la opci�n deseada\n");
		printf ("1 Crear Propiedad\n");
		printf ("2 Cargar Propiedad\n");
		printf ("3 Guardar Propiedad\n");
		printf ("4 Obtener Propiedad\n");
		printf ("5 Asignar Propiedad\n");
		printf ("6 Existe Propiedad\n");
		printf ("7 Nombre Propiedad\n");
		printf ("8 Eliminar Propiedad\n");
		printf ("9 Destuir Propiedad\n");
		printf ("0 Salir Programa\n");

		do
		{
		scanf ("%c",&op_menu_char);
		op_menu_int=atoi(op_menu_char);
		}
		while
		(op_menu_int > 57 || op_menu_int < 49); /* ASCII de 0-9 == 48-57 . Si estamos fuera del rango repite.*/


	} /* while */
	return 0;
} /* cierra la funci�n menu*/
