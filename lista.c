#include "lista.h"

nodo * inicLista()
{
    return NULL;
}

nodo * crearNodo(int dato)
{
    nodo * aux = (nodo*)malloc(sizeof(nodo));
    aux->dato = dato;
    aux->siguiente = NULL;
    return aux;
}

nodo * agregarPpio(nodo * lista, nodo * nuevoNodo)
{

    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else

    {
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
    }
    return lista;
}

nodo * buscarUltimo(nodo * lista)
{
    nodo * seg = lista;
    if(seg != NULL)
    {
        while(seg->siguiente != NULL)
        {
            seg = seg->siguiente;
        }
    }
    return seg;
}

nodo * buscarNodo(int dato, nodo * lista)

{
    nodo * seg;
    seg = lista;

    while ((seg != NULL) && (seg->dato!=dato))
    {
        seg=seg->siguiente;
    }

    return seg;
}

nodo * agregarFinal(nodo * lista, nodo * nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nodo * ultimo = buscarUltimo(lista);
        ultimo->siguiente = nuevoNodo;
    }
    return lista;
}



nodo * agregarEnOrden(nodo * lista, nodo * nuevoNodo)

{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {

        if(nuevoNodo->dato < lista->dato)
            lista = agregarPpio(lista, nuevoNodo);
        else
        {

            nodo * ante = lista;
            nodo * seg = lista;
            while(seg != NULL && nuevoNodo->dato > seg->dato)
            {
                ante = seg;
                seg = seg->siguiente;
            }

            ante->siguiente = nuevoNodo;
            nuevoNodo->siguiente = seg;
        }
    }
    return lista;
}

nodo * borrarTodaLaLista(nodo * lista)
{
    nodo * proximo;
    nodo * seg;
    seg = lista;
    while(seg != NULL)
    {
        proximo = seg->siguiente;
        free(seg);
        seg = proximo;
    }
    return seg;
}



nodo * borrarUltimoNodo(nodo * lista)
{
    nodo * aux;
    nodo * ante;

    if(lista){
        if(lista->siguiente==NULL) { /// la lista tiene un solo nodo
            aux=lista;
            lista=lista->siguiente;
           free(aux);
        }
        else {  /// la lista tiene mas de un nodo
            aux=lista;
            while(aux->siguiente!=NULL) {
                ante=aux;
                aux=aux->siguiente;
            }
            free(aux);
            ante->siguiente=NULL;
        }
    }
    return lista;
}


void mostrarNodo(nodo * aux)
{
    if (aux != NULL)
        printf("- %d -",aux->dato);
    else
        printf("\nLa lista esta vacia\n");
}

void recorrerYmostrar(nodo * lista)
{
    if (lista != NULL) {
        nodo * aux=lista;
        while(aux!=NULL)
        {
            mostrarNodo(aux);
            aux=aux->siguiente;
        }
    }
    else
        printf("\nLa lista esta vacia\n");
}

nodo * IngresarDatosAlFinal(nodo * lista)
{
    int dato;
    int cant;
    nodo * aux;
    printf("ingrese cantidad ingresar: ");
    scanf("%d",&cant);
    while(cant>0)
    {
        printf("ingrese un dato: ");
        scanf("%d",&dato);
        aux=crearNodo(dato);
        lista=agregarFinal(lista,aux);
        cant--;
    }
    return lista;
}

nodo * IngresarDatosAlPpio(nodo * lista)
{
    int dato;
    int cant;
    nodo * aux;
    printf("ingrese cantidad ingresar: ");
    scanf("%d",&cant);
    while(cant>0)
    {
        printf("ingrese un dato: ");
        scanf("%d",&dato);
        aux=crearNodo(dato);
        lista=agregarPpio(lista,aux);
        cant--;
    }
    return lista;
}

nodo * AgregarUnNodoEnOrden(nodo * lista)
{
    int dato;
    nodo * aux=lista;
    printf("ingrese un dato: ");
    scanf("%d",&dato);
    aux=agregarEnOrden(lista,crearNodo(dato));
    return aux;
}

nodo * CrearListaOrdenada(nodo * lista)
{
    int cant;
    nodo * aux=lista;
    printf("ingrese cantidad a ingresar: ");
    scanf("%d",&cant);
    while(cant>0)
    {
        aux=AgregarUnNodoEnOrden(aux);
        cant--;
    }
    return aux;
}

void SubprogramaBusquedaDeUnNodo(nodo * lista)
{
    int dato;
    printf("ingrese dato a buscar: ");
    scanf("%d",&dato);
    nodo * aux=inicLista();
    aux=buscarNodo(dato,lista);
    if(aux!=NULL)
        printf("%d",aux->dato);
}

nodo * SubprogramaBorrarNodo(nodo * lista){
    int dato;
    printf("ingrese dato a borrar de la lista: ");
    scanf("%d",&dato);
    lista=borrarNodoBuscado(dato,lista);
    return lista;
}

nodo * SubprogramaIngresarNuevoDato()
{
    int dato;
    nodo * nuevoNodo;
    printf("\nIngrese un numero:");
    scanf("%d", &dato);
    nuevoNodo = crearNodo(dato);
    return nuevoNodo;
}

nodo * borrarNodoBuscado(int dato, nodo* lista)
{
    nodo* seg;
    nodo* ante;
    if(lista!=NULL){
        if(lista->dato==dato){
            nodo* aux = lista;
            lista= lista->siguiente;
            free(aux);
        }
       else{
            seg = lista;
            while((seg!=NULL)&&(seg->dato!=dato)){
                ante = seg;
                seg = seg->siguiente;
            }
            if(seg!=NULL){
                ante->siguiente = seg->siguiente;
                free(seg);
            }
        }
    }
    return lista;
}

////////////////////////////////////////////////////


nodo* borrarPrimerNodo(nodo* lista)
{
    if(lista != NULL)
    {
        nodo* aux= lista;
        lista= lista->siguiente;
        free(aux);
    }
    return lista;
}

int retornarPrimerDato(nodo* lista)
{
    int rta = -99999; // no hay soluciones perfectas...
    if (lista==NULL)
    {
        printf("\n La lista esta vacia, se retornar� un -99999\n");
    }
    else
    {
        rta = lista->dato;
    }
    return rta; // si est� vacia la lista retorna -99999
}

