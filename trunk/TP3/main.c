#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    TPunto punto1,punto2;
    TAgenda agenda;
    TPantalla pantalla;
    FILE*arch;
    TListaSimple lista;
    nomArch=(char*)malloc(255*sizeof(char));
    printf("Inserte ruta del archivo para crear pantalla: \n");
    scanf("%s",nomArch);
    arch=fopen(nomArch,"r");
    free(nomArch);
    if (arch==NULL)
    {
        fclose(arch);
        return RES_ERROR_ABRIENDO_ARCHIVO;
    }
    ls_Crear(&lista,sizeof(TDivision));
    agenda_crear(&agenda);
    while (!feof(arch))
    {
        double aux1,aux2,aux3,aux4;
        fscanf(arch,"%lf,%lf;%lf,%lf",&aux1,&aux2,&aux3,&aux4);
        Punto_Cargar(&punto1,aux1,aux2);
        Punto_Cargar(&punto2,aux3,aux4);
        Division_Crear(&division,punto1,punto2);
        ls_Insertar(&lista,LS_SIGUIENTE,&division);
    }
    fclose(arch);
    Pantalla_Crear(&pantalla,&lista,sizeof(TElemPantalla));
    do
		{
        printf ("\nSeleccione la opcion deseada:\n");
        printf ("1 Asociar accion \n");
		printf ("10 Salir\n");
		scanf ("%s",op_menu_char);
		op_menu_int=atoi(op_menu_char);
		switch (op_menu_int)
		{
		    case 1:
		    {
		        TPunto punto;
		        double aux_x,aux_y;
		        do
		        {
                    printf("Ingrese coordenadas con formato x:y (entre 0 y 1)\n");
                    scanf("%lf:%lf",&aux_x,&aux_y);
                    if (aux_x<0 || aux_x>1 || aux_y<0 || aux_y>1)
                        printf("Coordenadas incorrectas \n");
		        } while (aux_x<0 || aux_x>1 || aux_y<0 || aux_y>1);
		        Punto_Cargar(&punto,aux_x,aux_y);
		        Pantalla_Asociar_Elemento(&pantalla,punto,&printf);
		        break;
		    }
		    case 10:
		    {
		        break;
            }
            default: printf("Opcion incorrecta\n\n");
        } /* cierra el Switch*/
	}while (op_menu_int!=10);
	ls_Vaciar(&lista);
	Pantalla_Destruir(&pantalla);
	agenda_destruir(&agenda);
	return 0;
}
