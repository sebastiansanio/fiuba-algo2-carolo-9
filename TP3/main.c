#include <stdio.h>
#include <stdlib.h>
#include "Pantalla.h"
#include "agenda.h"
#include "ListaSimple.h"

int main(int argc,char*argv[])
{
    char op_menu_char[10];
    int op_menu_int;
    char nomArch[255];
    TDivision division;
    TAgenda agenda;
    TPantalla pantalla;
    FILE archivo;
    TListaSimple lista;
    printf("Inserte ruta del archivo para crear pantalla: \n");
    scanf("%s",nomArch);
    fopen(archivo,nomArch);
    LS_Crear(%lista);
    while (!feof(archivo))
    {
        fscanf("%d,%d;%d,%d",division.inicio.x,division.inicio.y,division.fin.x,division.fin.y);
        LS_Insertar(&lista,LS_SIGUIENTE,&division);
    }
    do
		{
        printf ("\nSeleccione la opcion deseada:\n");
		printf ("10 Salir\n");
		scanf ("%s",op_menu_char);
		op_menu_int=atoi(op_menu_char);
		switch (op_menu_int)
		{
		default: printf("Opcion incorrecta\n\n");
        } /* cierra el Switch*/
	}while (op_menu_int!=10);
	return 0;
}
