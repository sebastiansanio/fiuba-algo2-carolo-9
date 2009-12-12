#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pantalla.h"
#include "agenda.h"
#include "ListaSimple.h"
#include "aplicacion.h"
#define RES_ERROR_ABRIENDO_ARCHIVO -1

int main(int argc,char*argv[])
{
    char op_menu_char[10];
    int op_menu_int;
    char* nomArch;
    TSector sector;
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
    Pantalla_Crear(&pantalla,&lista,sizeof(TSector));
    ls_Vaciar(&lista);
    do
		{
        printf ("\nSeleccione la opcion deseada:\n");
        printf ("1 Asociar accion \n");
        printf("2 Ejecutar accion \n");
		printf ("10 Salir\n");
		scanf ("%s",op_menu_char);
		op_menu_int=atoi(op_menu_char);
		switch (op_menu_int)
		{
		    case 1:
		    {
		        TPunto punto;
		        double aux_x,aux_y;
		        char opaux_char[10];
		        int opaux_int;
		        do
		        {
                    printf("Ingrese coordenadas con formato x:y (entre 0 y 1)\n");
                    scanf("%lf:%lf",&aux_x,&aux_y);
                    if (aux_x<0 || aux_x>1 || aux_y<0 || aux_y>1)
                        printf("Coordenadas incorrectas \n");
		        } while (aux_x<0 || aux_x>1 || aux_y<0 || aux_y>1);
		        Punto_Cargar(&punto,aux_x,aux_y);
		        do
		        {
		        printf("Que accion desea asociar? \n");
		        printf("1 Imprimir mensaje por pantalla \n");
		        printf("2 Agregar contacto a la agenda\n");
		        printf("3 Buscar contacto\n");
		        printf("4 Eliminar contacto\n");
		        printf("5 Salir\n");
		        scanf("%s",opaux_char);
		        opaux_int=atoi(opaux_char);
		        if (opaux_int!=1 && opaux_int!=2 && opaux_int!=3 && opaux_int!=4 && opaux_int!=5)
                    printf("Opcion incorrecta \n \n");
		        }
		        while (opaux_int!=1 && opaux_int!=2 && opaux_int!=3 && opaux_int!=4 && opaux_int!=5);
		        switch (opaux_int)
		        {
		        case 1:
                    {
                        char* mensaje;
                        mensaje=(char*)malloc(255*sizeof(char));
                        printf("Ingrese mensaje \n");
                        scanf("%s",mensaje);
                        sector.funcion=&imprimir_por_pantalla;
                        sector.arg=mensaje;
                        Pantalla_Asociar_Elemento(&pantalla,punto,&sector);
                        break;
                    }
                case 2:
                    {
                        sector.funcion=&agregar_numero;
                        sector.arg=&agenda;
                        Pantalla_Asociar_Elemento(&pantalla,punto,&sector);
                        break;
                    }
                case 3:
                    {
                        sector.funcion=&buscar_numero;
                        sector.arg=&agenda;
                        Pantalla_Asociar_Elemento(&pantalla,punto,&sector);
                        break;
                    }
                case 4:
                    {
                        sector.funcion=&eliminar_numero;
                        sector.arg=&agenda;
                        Pantalla_Asociar_Elemento(&pantalla,punto,&sector);
                        break;
                    }
                case 5:
                    {
                        TExit*aux_exit;
                        aux_exit=(TExit*)malloc(sizeof(TExit));
                        aux_exit->codigo_salida=0;
                        aux_exit->agenda=&agenda;
                        aux_exit->pantalla=&pantalla;
                        sector.funcion=&exit_f;
                        sector.arg=aux_exit;
                        Pantalla_Asociar_Elemento(&pantalla,punto,&sector);
                        break;
                    }
		        }
		        break;
		    }
		    case 2:
		    {
		        TPunto punto;
		        double aux_x,aux_y;
		        int error;
		        do
		        {
		            printf("\nIngrese coordenadas con formato x:y (entre 0 y 1)\n \n");
                    scanf("%lf:%lf",&aux_x,&aux_y);
                    if (aux_x<0 || aux_x>1 || aux_y<0 || aux_y>1)
                        printf("\nCoordenadas incorrectas \n");
		        } while (aux_x<0 || aux_x>1 || aux_y<0 || aux_y>1);
		        Punto_Cargar(&punto,aux_x,aux_y);
		        error=Pantalla_Obtener_Elemento(&pantalla,punto,&sector);
		        if (error==TPAN_OK)
                    sector.funcion(sector.arg);
                else
                    printf("\nNo hay accion asociada al sector \n");
		    }

		    case 10:
		    {
		        break;
            }
            default: printf("Opcion incorrecta\n\n");
        } /* cierra el Switch*/
	}while (op_menu_int!=10);
	Pantalla_Destruir(&pantalla);
	agenda_destruir(&agenda);
	return 0;
}
