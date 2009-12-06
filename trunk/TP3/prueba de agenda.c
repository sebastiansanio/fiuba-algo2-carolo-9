#include <stdio.h>
#include <stdlib.h>
#include "Pantalla.h"
#include "agenda.h"
int main()
{
    TAgenda agenda;
    char nombre[LONG_NOMBRE];
    char nombre2[LONG_NOMBRE];
    char telefono[LONG_TEL];
    char telefono2[LONG_TEL];
    int i;
    agenda_crear(&agenda);
    do
    {
    printf("Ingrese 1:Cargar, 2:Mostrar,3:Eliminar 4:Salir \n");
    scanf("%d",&i);
    switch(i)
    {
    case 1:
    {
        printf("Nombre a insertar: \n");
        scanf("%s",nombre);
        printf("Telefono a insertar: \n");
        scanf("%s",telefono);
        agenda_agregar(&agenda,nombre,telefono);
        break;
    }
    case 2:
    {
        printf("Nombre a buscar: \n");
        scanf("%s",nombre2);
        agenda_buscar(agenda,nombre2,telefono2);
        printf("El telefono de %s es %s \n",nombre2,telefono2);
        break;
    }
    case 3:
    {
        printf("Nombre a eliminar: \n");
        scanf("%s",nombre2);
        agenda_borrar(&agenda,nombre2);
    }
    }
    }
    while (i!=4);
    agenda_destruir(&agenda);
    return 0;

}
