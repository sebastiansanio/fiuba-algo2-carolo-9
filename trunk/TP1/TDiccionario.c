/*
 * Definicion e implementacion del TDA TDiccionario.
 */
#define NULL 0
#define SIZE_CLAVE 20
#define SIZE_DICC 20

typedef struct {
	char clave[SIZE_CLAVE]={};
	void *elem;
}TEntrada;
typedef struct {
	TEntrada entradas[SIZE_DICC];
	int size_elem;
}TDiccionario;

int Diccionario_Crear(TDiccionario* dicc, int tamanioDato)
{
	TDiccionario nuevo_dicc;
	nuevo_dicc.size_elem=tamanioDato;
	*dicc=nuevo_dicc;
	return 0;
}

int Diccionario_CantidadEntradas(TDiccionario dicc)
{
    int i=0;
    while (dicc.entradas[i].clave[0]!=NULL) /* Recorre las entradas hasta que el primer char de una clave sea NULL */
    {
    	i++;
    }
    return i;
}

int Diccionario_Existe(TDiccionario dicc, char* clave)
{
	int i;
	i=Diccionario_BuscarPos(dicc, clave);
	if (i==-1) return 0;
	else return 1;
}

void Diccionario_Obtener(TDiccionario dicc, char* clave, void* elem)
{
    int pos;
    pos=Diccionario_BuscarPos(dicc, clave);
    memcpy(elem, dicc.entradas[pos].elem, dicc.size_elem); /* Busca el elemento en el diccionario y lo copia en una variable */
}

int Diccionario_Asignar(TDiccionario* dicc, char* clave, void* elem)
{
	int cmpres,i=0,cant;
	while(0){
		cmpres=strncmp(clave,dicc.entradas[i].clave,SIZE_CLAVE);
		if (cmpres>0){ /* La clave buscada es mayor que la actual */
			i++;
		}
		else if (cmpres==0){ /* La clave buscada esta en la actual posicion */
			break;
		}
		else if (cmpres<0){ /* La clave buscada es menor que la actual ergo no existe y se debe insertar en esta posicion*/
			cant=Diccionario_CantidadEntradas(dicc);
			if (cant==SIZE_DICC) return 1;
			for (cant--; cant>=i; cant--){
				*dicc.entradas[cant]=*dicc.entradas[cant+1];
			}
			break;
		}
	}
	memcpy(*dicc.entradas[i].elem, elem, *dicc.size_elem); /* Copia el elemento al diccionario */
	return 0;
}

void Diccionario_Claves(TDiccionario dicc, char* claves[])
{
    int i=0;
    while (dicc.entradas[i].clave[0]!=NULL){
    	strncpy(claves[i], dicc.entradas[i].clave, SIZE_CLAVE);            /*Copia las claves al arreglo*/
    	i++;
    }
    claves[i]=NULL;                                           /*Le asigna a la posicion siguiente al ultimo elemento del arreglo NULL, para representar el fin del arreglo*/
}

void Diccionario_Eliminar(TDiccionario* dicc, char* clave)
{
	/*
	 * A partir de la posicion a eliminar, "baja" todas las entradas siguientes.
	 * Si el diccionario estaba lleno, ademas, la ultima posicion se destruye.
	 * [Por ahora solo setea en NULL al primer char de 'clave'. Habria que liberar memoria de 'elem' quizas.]
	 *
	 */
	int pos;
	pos=Diccionario_BuscarPos(*dicc, clave);
	for (;(*dicc.entradas[pos].clave[0]==NULL); pos++){
		if (pos==SIZE_DICC-1){
			*dicc.entradas[pos].clave[0]=NULL;
		}
		*dicc.entradas[pos]=*dicc.entradas[pos+1];
	}
}

void Diccionario_Destruir(TDiccionario* dicc)
{
}

int Diccionario_BuscarPos(TDiccionario dicc, char* clave)
{
	/* Devuelve la posicion de 'clave' en 'dicc.entradas' o -1 si no existe.*/
	int cmpres,i=0;
	while(dicc.entradas[i].clave[0]!=NULL){
		cmpres=strncmp(clave,dicc.entradas[i].clave,SIZE_CLAVE);
		if (cmpres>0){ /* La clave buscada es mayor que la actual */
			i++;
		}
		else if (cmpres==0){ /* La clave buscada esta en la actual posicion */
			return i;
		}
		else if (cmpres<0){ /* La clave buscada es menor que la actual ergo no existe */
			return -1;
		}
		if (i==SIZE_DICC) return -1; /* Llegamos a la ultima entrada ergo no existe */
	}
}
