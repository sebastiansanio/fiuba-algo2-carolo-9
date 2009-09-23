#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu ()
{
    int op_menu;
    TPropiedades propiedades; /* TPropiedades es el TDA que debidamente será creado*/
    char nombre;             /* Declaré todas la variables acá. Díganme si les parece bien, o si las debería declara en el Main.*/
    char nombres [15];
    char valor;
    char valorDefault;
    printf ("Bienvenido al programa de manejo de Propiedades\n"); /* Líneas 11 a la 56 son el típico menú que hacíamos en Algo1. Dígname si hay algú error.*/
    printf ("Seleccione la opción deseada\n");
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
    scanf (op_menu);
    }
    while
    (op_menu < 10 && => 0); /* la idea de las dos condiciones es que no pinche si nos mandan un núemero negativo*/

    /* ¡¡¡NO CONFUNDIR!!! Recordar que el DO-WHILE es el repeat de C. Ojo que el While de abajo es el while tradicional de Pascal*/

    while (op_menu >0)
    {
        switch (op_menu)
    {
        case 1:
        Propiedades_Crear (&propieades); /* pasa con & porque yo lo declaré como variable y no como puntero a variable*/
        case 2:
        Propiedades_Cargar(&propiedades,&rutaArchivo); /* pasa con & porque yo lo declaré como variable y no como puntero a variable*/
        case 3:
        Propiedades_Guardar( propiedades,&rutaArchivo);
        case 4:
        Propiedades_Obtener(propiedades,&nombre,&valorDefault,&valor); /* pasa con & porque yo lo declaré como variable y no como puntero a variable*/
        case 5:
        Propiedades_Asignar(&propiedades,&nombre,&valor);
        case 6:
        Propiedades_Existe(propiedades,&nombre);
        case 7:
        Propiedades_Nombres(propiedades,&nombres[15]);
        case 8:
        Propiedades_Eliminar(&propiedades,&nombre);
        case 9:
        Propiedades_Destruir(&propiedades);


    } /* cierra el Switch*/
    } /* cierra el While*/

    return 0;
} /* cierra la función menu*/
