int Diccionario_CantidadElementos(TDiccionario dicc)
{
    int i=0;
    while ((dicc->entradas[i]->clave[0])!=NULL) /* Recorre las entradas hasta que el primer char de una clave sea NULL */
    {
    	i++;
    }
    return i;
}

void bubblesort(TDiccionario* dicc, int cantidad_elem)                  /*Tomado de la codificación del bubble sort en lenguaje PASCAL*/
{                                                                   /*Precondiciones: Que exista dicc, que clave y cantidad_elem sean validos*/
	int i,j,cambio,clave;                                       /*Establece las variables auxiliares valor y clave*/
	void valor;
	i=0;
	cambio=0;
	while ((i<(cantidad_elem-1))&&(cambio))
	{
		cambio=1;
		for (j=0,j<=cantidad_elem-i,j++)
		{
			if ((*dicc->entradas[j]->clave)>(*dicc->entradas[j+1]->clave))                  /*Compara cada elemento con su siguiente, haciendo que los mas chicos suban comoburbujas a la posicion superior del arreglo*/
			{
				memcpy(&valor,(dicc->entradas[j]->valor),dicc->size_elem);
				clave=dicc->entradas[j]->clave;
				memcpy((dicc->entradas[j]->valor),(dicc->entradas[j+1]->valor),dicc->size_elem);              /*Realiza el intercambio de claves y valor*/
				dicc->entradas[j]->clave=dicc->entradas[j+1]->clave;
				memcpy((dicc->entradas[j+1]->valor),&valor,dicc->size_elem);
				dicc->entradas[j+1]->clave=clave;
				cambio=0;
			}
		}
		i=i++;
	}
}

int buscar_dicc(TDiccionario dicc,char clave,int cantidad_elem)           /*Tomado de la codificación del binary sort en lenguaje PASCAL*/
{                                                                         /*Precondiciones: Que exista dicc, que clave y cantidad_elem sean validos y que el arreglo este ordenado de forma descendente*/
	int ini,medio,fin,terminado;
	ini=0;
	fin=cantidad_elem-1;
	terminado=1;
	while (!terminado)                                      /*Establce que mientras no haya terminado proceda con lo de abajo*/
	{
		if ((clave>(dicc->entradas[fin]->clave))||(clave<(dicc->entradas[ini]->clave)))
        	{
			return NULL;                                                                        /*Si el elemento sobrepasa el rango de busqueda deja de buscar*/
		}
		else
		{
			medio=(ini+fin)/2;
			if (clave==(dicc->entradas[medio]->clave))                  /*Usando el metodo "dividir y conquistar" parte el problema en 2 buscando en el medio*/
			{
				return medio;
			}
			else
			{
				if (clave>(dicc->entradas[medio]->clave))               /*Si el valor no esta en el medio del bloque, elige un bloque mayor o menor según corresponda*/
				{
					ini=medio+1;
				}
				else
				{
					fin=medio-1;
				}
			}
		}
	}
}

int Diccionario_Crear(TDiccionario* dicc, int size_elem)
{
	TDiccionario nuevo_dicc;
	int i;
	nuevo_dicc->size_elem=size_elem;           /*Setea el tamaño dato*/
	for (i=0,i<=SIZE_DICC,i++)
	{
      nuevo_dicc->*(entradas+i)->clave=NULL;              /*Inicializa las posiciones clave y valor en NULL*/
      memcpy(&(nuevo_dicc->entradas[i]->valor),&NULL,dicc->size_elem);
	}
	*dicc=nuevo_dicc;
	return 0;
}

int Diccionario_CantidadEntradas(TDiccionario dicc)
{
    int i=0;
    while ((dicc->entradas[i]->clave)!=NULL) /* Recorre las entradas hasta que el primer char de una clave sea NULL */
    {
    	i++;
    }
    return i;
}

int Diccionario_Existe(TDiccionario dicc, char* clave)
{
    int elementos;
    elementos=Diccionario_CantidadElementos(dicc)                     /*Guarda en elementos la cantidad de los mismos para poder hacer el ordenamiento y la busqueda*/
    bubblesort (&dicc,elementos);
    if ((dicc->entradas[buscar_dicc(dicc, *clave,elementos])->valor)!=NULL) /*Comprueba la existencia de un elemnto, buscandolo primero*/
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
    int elementos;
    elementos=Diccionario_CantidadElementos(dicc);                               /*Guarda en elementos la cantidad de los mismos para poder hacer el ordenamiento y la busqueda*/
    bubblesort (&dicc,elementos);                                                   /*Realiza el ordenamiento para poder buscar*/
    memcpy(elem,(dicc->entradas[buscar_dicc(dicc,* clave,elementos)]->valor),dicc->size_elem);         /*Busca el elemento en el diccionario y lo copia en una variable*/
    }

int Diccionario_Asignar(TDiccionario* dicc, char* clave, void* elem)
{
    int posicion;
    int NumEnt;
    NumEnt=Diccionario_CantidadElementos(*dicc);            /*Recupera el valor de la cantidad de elemntos*/
    bubblesort (dicc,NumEnt);                           /*Ordena el arreglo para realizar la busqueda*/
    posicion=buscar_dicc(*dicc,*clave,NumEnt);    /*Busca la posicion en la que esta la clave*/
    if ((posicion==NULL)&&(NumEnt<SIZE_DICC))
    {                                                                   /*Si la clave no existe, la agrega al final*/
        posicion=NumEnt+1;
        dicc->entradas[posicion]->clave=clave;
    }
    if (((dicc->entradas[posicion]->valor)!=NULL)||(NumEnt<SIZE_DICC))          /*Se fija si se puede escribir o si diccionario esta lleno*/
    {
        memcpy((dicc->entradas[posicion]->valor),elem,size_elem);
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
    while ((dicc->*(entradas+i)->clave)!=NULL)
    {
        *(claves+i)=(dicc->*(entradas+i)->clave);                       /*Copia las claves alarreglo*/
        i=i++;
    }
    *(claves+i)=NULL;                                           /*Le asigna a la posición siguiente al ultimo elemento del arreglo NULL, para representar el fin del arreglo*/
}

void Diccionario_Eliminar(TDiccionario* dicc, char* clave)
{
    int elementos;
    elementos=Diccionario_CantidadElementos(*dicc);                               /*Guarda en elementos la cantidad de los mismos para poder hacer el ordenamiento y la busqueda*/
    bubblesort (dicc,elementos);                                               /*Realiza el ordenamiento para poder buscar*/
    memcpy((dicc->entradas[buscar_dicc(*dicc,*clave,elementos)]->valor),&NULL,dicc->size_elem);     /*Busca el elemento en el diccionario y le asigna NULL, que representa elemento vacio*/
}

void Diccionario_Destruir(TDiccionario* dicc)
{
	int i;
	dicc->size_elem=0;                            /*Setea el tamanio dato en 0*/
	for (i=0,i<=SIZE_DICC,i++)
	{
	    dicc->*(entradas+i)->clave=NULL;              /*Setea las posiciones clave y valor en NULL*/
        memcpy((dicc->entradas[i]->valor),&NULL,dicc->size_elem);
	}
}
