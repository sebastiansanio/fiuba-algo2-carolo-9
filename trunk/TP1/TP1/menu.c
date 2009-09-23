#include <stdio.h>

int menu ()
{
    int op_menu;
    printf ("Bienvenido al programa de manejo de Propiedades\n");
    printf ("Seleccione la opción deseada\n");
    printf ("1 Crear Propiedad\n");
    printf ("2 Moficar Propiedad\n");

    do
    {
    scanf (op_menu);
    }
    while
    (op_menu < 10);

    switch (op_menu)
    {
        case 1:
        crear_propiedades ();
        case 2:
        modificar_propiedades ();
    }


    return 0;
}
