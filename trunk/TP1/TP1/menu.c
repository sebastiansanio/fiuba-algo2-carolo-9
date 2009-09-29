#include <stdio.h>
#include <stdlib.h>
#include "propiedades.h"

int menu ()
{
    char op_menu_char[10];
    int op_menu_int;
    TPropiedades propiedades;
    char nombre[SIZE_CLAVE];
    char* nombres [255];
    char valor[SIZE_VALOR];
    char valorDefault[SIZE_VALOR];
    char rutaArchivo [255];
    int validaCreacion; /* esta variable esta para que no pinche cuando destruimos una propiedad sin haberla creado antes*/

    validaCreacion=-1;

    do
		{
        printf ("\nSeleccione la opcion deseada:\n");
		printf ("1 Crear Propiedad\n");
		printf ("2 Cargar Propiedad\n");
		printf ("3 Guardar Propiedad\n");
		printf ("4 Obtener Propiedad\n");
		printf ("5 Asignar Propiedad\n");
		printf ("6 Existe Propiedad\n");
		printf ("7 Nombre Propiedades\n");
		printf ("8 Eliminar Propiedad\n");
		printf ("9 Destruir Propiedad\n");
		printf ("10 Salir\n");
		scanf ("%s",op_menu_char);
		op_menu_int=atoi(op_menu_char);
		switch (op_menu_int)
		{
		case 1:
		{
			if (!Propiedades_Crear(&propiedades)){ /* '&' pues propiedades no es puntero.*/
				validaCreacion=0;
				printf ("La Propiedad ha sido creada satisfactoriamente.\n");
			}
			break;
		}
		case 2:
		{
			if(validaCreacion==0){printf ("Ingrese la ruta al archivo de propiedades:\n");
			scanf ("%s",rutaArchivo);
			if (!Propiedades_Cargar(&propiedades,rutaArchivo)){
				printf ("La Propiedad ha sido cargada satisfactoriamente.\n");
                }
			}
			else
			{   printf("Propiedad no creada");}

			break;
		}
		case 3:
		{
			if(validaCreacion==0){
			printf ("Ingrese la ruta al archivo de propiedades:\n");
			scanf ("%s",rutaArchivo);
			if (!Propiedades_Guardar(propiedades,rutaArchivo)){
				printf ("La Propiedad ha sido guardada satisfactoriamete\n");
                }
			}
			else{
			    printf("Propiedad no ha sido creada");}
			break;
		}
		case 4:
		{

            if (validaCreacion==0){
                printf("Ingrese nombre de la propiedad\n");
                scanf("%s",nombre);
                if (Propiedades_Existe(propiedades,nombre)){
                    Propiedades_Obtener(propiedades,nombre,valorDefault,valor);
                    printf ("El valor de la Propiedad es: %s\n",valor);}
                else
                {
                    printf("La propiedad %s no existe \n",nombre);}}
            else{
                printf("Propiedad no ha sido creada");}

			break;
		}
		case 5:
		{
		    if (validaCreacion==0){
			printf("Ingrese el nombre de la propiedad:\n");
			scanf("%s",nombre);
			printf("Ingrese el valor de la propiedad:\n");
			scanf("%s",valor);
			if (!Propiedades_Asignar(&propiedades,nombre,valor)){
				printf("Propiedad cargada satisfactoriamente.\n");
			}}
			else{printf("Propiedad no ha sido creada");}
			break;
		}
		case 6:
		{
			printf("Ingrese el nombre de la propiedad:\n");
			scanf("%s",nombre);
			if (Propiedades_Existe(propiedades,nombre)) {
				printf("La propiedad existe.\n");
			}else{
				printf ("La propiedad NO existe.\n");
			}
			break;
		}
		case 7:
		{
			Propiedades_Nombres(propiedades,nombres);


			break;
		}
		case 8:
		{
			printf("Ingrese el nombre de la propiedad:\n");
			scanf("%s",nombre);
			Propiedades_Eliminar(&propiedades,nombre);
			printf("La Propiedad ha sido eliminada satisfactoriamente.\n");
			break;
		}
		case 9:
		{
			if (validaCreacion==0){
				Propiedades_Destruir(&propiedades);
				validaCreacion=-1;
				printf("Propiedad ha sido destruida satisfactoriamente.\n");
        			}
            else{printf("Propiedad no se pudo destruir, no esta creada\n");}
			break;
		}
		} /* cierra el Switch*/
	}while (op_menu_int!=10);
	return 0;
} /* cierra la función menu*/
