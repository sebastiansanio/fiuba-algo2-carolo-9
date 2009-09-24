typedef struct{char clave[tamañoclave];char valor[tamañovalor]} tauxdicc; /*registro con dos campos strings */

typedef struct{tauxdicc dicc[cantidaddeclaves];int tamanoiodato} TDiccionario; /*un vector del tipo anterior+un entero para guardar el tamaño de dato */

# define MaxCantEnt a;          /*Con a perteneciendo a N*/

# define NULL 0;

int Diccionario_Crear(TDiccionario* dicc, int tamanioDato)
{
	TDiccionario nuevo_dicc;
	int i;
	nuevo_dicc->tamaniodato=tamanioDato;           /*Setea el tamaño dato*/
	for (i=0,i<=MaxCantEnt,i++)
	{
      nuevo_dicc->*(dicc+i)->clave=NULL;              /*Inicializa las posiciones clave y valor en NULL*/
      nuevo_dicc->*(dicc+i)->valor=NULL;
	}
	*dicc=nuevo_dicc;
	return 0;
}

int Diccionario_CantidadEntradas(TDiccionario dicc)
{
    int i=0;
    while ((dicc.entradas[i].clave[0])!=NULL) /* Recorre las entradas hasta que el primer char de una clave sea NULL */
    {
    	i++;
    }
    return i;
}

int Diccionario_Existe(TDiccionario dicc, char* clave)
{
    if ((dicc->dicc[buscar_dicc(dicc, *clave,Diccionario_CantidadEntradas(dicc))]->valor)!=NULL) /*Comprueba la existencia de un elemnto, buscandolo primero*/
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Diccionario_Obtener(TDiccionario dicc, char* clave, void* elem)
{
    memcpy(elem,dicc->dicc[buscar_dicc(dicc,* clave,Diccionario_CantidadEntradas(dicc))]->valor,dicc->tamanioDato);         /*Busca el elemento en el diccionario y lo copia en una variable*/
    }

int Diccionario_Asignar(TDiccionario* dicc, char* clave, void* elem)
{
    int posicion;
    int NumEnt;
    NumEnt=Diccionario_CantidadEntradas(* dicc);            /*Recupera el valor de la cantidad de elemntos*/
    posicion=buscar_dicc(* dicc,* clave,Diccionario_CantidadEntradas(* dicc));    /*Busca la posiciï¿½n en la que esta la clave*/
    if ((posicion==NULL)&&(NumEnt<MaxCantEnt))
    {                                                                   /*Si la clave no existe, la agrega al final*/
        posicion=NumEnt+1;
        memcpy(dicc->dicc[posicion]->clave,clave,tamanioDato);
    }
    if (((dicc->dicc[posicion]->valor)!=NULL)||(NumEnt<MaxCantEnt))          /*Se fija si se puede escribir o si diccionario esta lleno*/
    {
        memcpy(dicc->dicc[posicion]->valor,elem,tamanioDato);
        return 0;
    }
    else
    {
            return 1;
    }
}

void Diccionario_Claves(TDiccionario dicc, char* claves[])
{
    int i;
    i=0;
    while ((dicc->*(dicc+i)->clave)!=NULL)
    {
        *(claves+i)=(dicc->*(dicc+i)->clave);                       /*Copia las claves alarreglo*/
        i=i++;
    }
    *(claves+i)=NULL;                                           /*Le asigna a la posición siguiente al ultimo elemento del arreglo NULL, para representar el fin del arreglo*/
}

void Diccionario_Eliminar(TDiccionario* dicc, char* clave)
{
    memcpy(dicc->dicc[buscar_dicc(dicc,* clave,Diccionario_CantidadEntradas(dicc))]->valor,NULL,dicc->tamaniodato);     /*Busca el elemento en el diccionario y le asigna NULL, que representa elemento vacio*/
    }

void Diccionario_Destruir(TDiccionario* dicc)
{
	int i;
	dicc->tamaniodato=0;                            /*Setea el tamanio dato en 0*/
	for (i=0,i<=MaxCantEnt,i++)
	{
	    dicc->*(dicc+i)->clave=NULL;              /*Setea las posiciones clave y valor en NULL*/
        dicc->*(dicc+i)->valor=NULL;
	}
}
