#include <stdio.h>
#include <stdlib.h>
#define ELEMENTO_DESTRUIDO=0;
#define FALLO_LA_DESTRUCCION_DEL_ELEMENTO=1;
#define LISTA_DESTRUIDA=0;
#define ELEMENTO_OBTENIDO=0;
#define ELEMENTO_COPIADO=0;
#define ELEMETNO_INSERTADO=0;


int destruirLDEC(LDEC* ldec);{
    Nodo *Eliminar,*Siguiente;
    int resultado;
    int Fin=1;
    Eliminar=ldec->pPrimero;
    if (!(Eliminar==NULL)){
        Siguiente=Eliminar->pSiguiente;
        While (!Fin){
            if(Siguiente==pPrimero){
                Fin=0;}
            resultado=ldec->pfDestructor(Eliminar->pElemento);
            if (!(resultado==ELEMENTO_DESTRUIDO)){return FALLO_LA_DESTRUCCIÓN_DEL_ELEMENTO;}
            free(Eliminar);
            Eliminar=Siguiente;
            Siguiente=Eliminar->pSiguiente;}}
    free(ldec->pPrimero);
    free(ldec->pCorriente);
    free(ldec->pfClonador);
    free(ldec->pfDestructor);
return LISTA_DESTRUIDA;}



int destruir (void* Elemento);{
    TPropiedades*Propiedad=(TPropiedades*)Elemento;
    Propiedades_Destruir(Propiedad);
    return ELEMENTO_DESTRUIDO;}



int ObtenerCteLDEC(LDEC ldec, void** elemento);{
/*Función clonador*/
return ELEMENTO_OBTENIDO;}


int modificarCteLDEC(LDEC* ldec, void* elemento);{
    int resultado;
    resultado=ldec->pfDestructor(ldec->pCorriente->pElemento);
    if (!(resultado==ELEMENTO_DESTRUIDO)){return FALLO_LA_DESTRUCCIÓN_DEL_ELEMENTO;}
    /*Función clonador*/
    return ELEMENTO_COPIADO;}









void* clonar (void* ACopiar);{
    TPropiedades* Copiado;
    char* valor, *valordef/*Innecesaria*/;
    char* claves[MAXPROP];
    int resultado,i;
    resultado=Propiedades_Crear(Copiado);
    if ((resultado==0)){
        Propiedades_Nombres((TPropiedades*)ACopiar, claves);
        for (i=0,i<MAX_PROP,i++){
        Propiedades_Obtener(*((TPropiedades*)ACopiar),claves[i],valordef,valor);
        Propiedades_Asignar(Copiado,claves[i],valor);}}
    else{ resultado=NULL;
        return (void*)resultado;}
    return (void*)Copiado;}





