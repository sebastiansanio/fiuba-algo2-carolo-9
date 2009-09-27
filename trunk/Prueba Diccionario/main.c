#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <diccionario.h>

int main(int argv,char* argc[])
{
	TDiccionario dicc;
	int tamanioDato;
	char* elem;
	char** claves;
	int i,rta;
	tamanioDato=25*sizeof(char);
	printf("Funcion Crear/n");
	rta=Diccionario_Crear(&dicc,tamanioDato);
	if (rta==0)
	{
	    printf("Crear: TDA creado. Se evaluaran las primitivas. Presione ENTER para continuar./n");
        scanf();}
    else{
        printf("Crear: Fallo la creacion. Presione ENTER para continuar./n");
        scanf();
        return 1;}
    printf("Funcion Asignar/n");
    rta=Diccionario_Asignar(&dicc,"Color(RGB)","69X84X64");
    if (rta==0){
        rta=Diccionario_Asignar(&dicc,"Tamano","1024X768");
        if (rta==0){
            rta=Diccionario_Asignar(&dicc,"Idioma","English(US)");
            rta=Diccionario_Asignar(&dicc,"Idioma","Russkiy");
            rta=Diccionario_Asignar(&dicc,"Brillo","16cd");
        }
        else{
            printf("Asignar: Falló la asignacion en el segundo valor. Presione ENTER para continuar./n");
            scanf();
            return 1;}
    }
    else{
        printf("Asignar: Falló la asignacion en el primer valor. Presione ENTER para continuar./n");
        scanf();
        return 1;}
    if (rta==1){
            printf("Asignar: Se completo la asignación. Presione ENTER para continuar./n");
            scanf();}
    else{
        printf("Asignar: Fallo el maximo de la asignacion. Presione ENTER para continuar./n");
        scanf();
        return 1;}
    printf("Funcion Obtener/n");
    Diccionario_Obtener(dicc,"Idioma",elem);
    if (strcomp(elem,"Russkiy")){
        printf("Obtener: Se obtuvo el elemnto correcto. Presione ENTER para continuar./n");
        scanf();
    }
    else{
        printf("Obtener: Fallo la obtencion o hay un error en la estructura. Presione ENTER para continuar./n");
        scanf();}
    printf("Funcion Claves/n");
    Diccionario_Claves(dicc,claves);
    if ((strcomp(claves[0],"Color(RGB)"))&&((strcomp(claves[2],"Idioma"))||(strcomp(claves[2],"Tamano")))){
        printf("Claves: Claves se lleno correctamente. Presione ENTER para continuar./n");
        scanf();}
    else{
        printf("Claves: Claves no se lleno correctamente o hay un error en la estructura. Presione ENTER para continuar./n");
        scanf();}
    printf("Funcion CantidadEntradas/n");
    rta=Diccionario_CantidadEntradas(dicc);
    if (rta==3){
        printf("CantidadEntradas: La cantidad de entradas es correcta. Presione ENTER para continuar./n");
        scanf();}
    else{
        printf("CantidadEntradas: La cantidad de entradas es incorrecta, verificar la funcion de asignacion y esta. Presione ENTER para continuar./n");
        scanf();}
    printf("Funcion Eliminar/n");
    Diccionario_Eliminar(&dicc,"Tamano");
    printf("Eliminar: Se elimino el elemento guardado en Tamano. Presione ENTER para continuar./n");
    scanf();
    printf("Funcion Existe/n");
    rta=Diccionario_Existe(dicc,"Tamano");
    if (rta==0){
        printf("Eliminar: Eliminar funciona correctamente. Presione ENTER para continuar./n");
        scanf();
        rta=Diccionario_Existe(dicc,"Color(RGB)");
        if (rta==1){
            printf("Existe: La funcion trabaja correctamente. Presione ENTER para continuar./n");
            scanf();
        }
        else{
            printf("Eliminar: Hay una falla al leer claves con elementos asignados. Presione ENTER para continuar./n");
            scanf();}
    }
    else{
        printf("Eliminar: La funcion no logro eliminar el elemento o hay una falla en existe. Presione ENTER para continuar./n");
        scanf();}
    printf("Funcion Destruir/n");
    Diccionario_Destruir(&dicc);
    printf("Destruir: El diccionario ya no existe, no se verificara si esta función cumplio con su tarea. Presione ENTER para continuar./n");
    scanf();
    printf("Gracias por utilizar BMSW software. Esperamos que no haya encontrado errores en su programa. Presione ENTER para terminar./n");
    scanf();
    return 0;
}