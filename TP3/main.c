#include <stdio.h>
#include <stdlib.h>
#include "Pantalla.h"
#include "agenda.h"
#include "ListaSimple.h"
#define RES_ERROR_ABRIENDO_ARCHIVO -1

int main(int argc,char*argv[])
{
    char op_menu_char[10];
    int op_menu_int;
    char* nomArch;
    TDivision division;
    TAgenda agenda;
    TPantalla pantalla;
    FILE*arch;
    TListaSimple lista;
    nomArch=(char*)malloc(255*sizeof(char));
    printf("Inserte ruta del archivo para crear pantalla: \n");
    scanf("%s",nomArch);
    arch=fopen(nomArch,"rt");
    free(nomArch);
    ls_Crear(&lista,sizeof(TDivision));
    agenda_crear(&agenda);
    if (arch==NULL)
        return RES_ERROR_ABRIENDO_ARCHIVO;
    while (!feof(arch))
    {
        fscanf(arch,"%lf,%lf;%lf,%lf",&(division.inicio.x),&division.inicio.y,&division.fin.x,&division.fin.y);
        ls_Insertar(&lista,LS_SIGUIENTE,&division);
    }
    Pantalla_Crear(&pantalla,&lista,sizeof(TElemPantalla));
    do
		{
        printf ("\nSeleccione la opcion deseada:\n");
		printf ("10 Salir\n");
		printf ("1 Asociar accion");
		scanf ("%s",op_menu_char);
		op_menu_int=atoi(op_menu_char);
		switch (op_menu_int)
		{
		    case 1:
		    {
		        TPunto punto;
		        punto.x=0.2;
		        punto.y=0.2;
		        Pantalla_Asociar_Elemento(&pantalla,punto,&printf);
		    }
		    case 10:
		    {
		    }
            default: printf("Opcion incorrecta\n\n");
        } /* cierra el Switch*/
	}while (op_menu_int!=10);
	ls_Vaciar(&lista);
	Pantalla_Destruir(&pantalla);
	agenda_destruir(&agenda);
	return 0;
}
