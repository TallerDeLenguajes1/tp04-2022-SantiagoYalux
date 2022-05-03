#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

struct Tarea
{
    int TareaId;
    char *Descripcion;
    int Duracion;
} typedef tarea;

struct Nodo
{
    tarea T;
    struct Nodo *Siguiente;
} typedef nodo;

nodo *CrearListaVacia();
nodo *crearNodo();
void InsertarNodo(nodo **cabeceraLista);
void MostrarTareas(nodo **listaTarea);
void cargarTareasRealizadas(nodo **listaTarea, nodo **listaTareaRealizadas);
nodo *nodoEncontradoPorId(nodo **listaTarea, int Id);

int main()
{
    int cantidadTarea = 0;

    tarea *cabeceraTarea = CrearListaVacia();
    tarea *cabeceraTareaRealizada = CrearListaVacia();

    printf("Ingresa la cantidad Tareas: \n");
    fflush(stdin);
    scanf("\n%d", &cantidadTarea);

    for (int i = 0; i < cantidadTarea; i++)
    {
        InsertarNodo(&cabeceraTarea);
    }

    cargarTareasRealizadas(&cabeceraTarea, &cabeceraTareaRealizada);
    printf("\n MOSTRAR LAS TAREAS PENDIENTES \n");
    MostrarTareas(&cabeceraTarea);
    printf("\n MOSTRAR LAS TAREAS REALIZADAS \n");
    MostrarTareas(&cabeceraTareaRealizada);


}

nodo *CrearListaVacia()
{
    return NULL;
}

nodo *crearNodo()
{
    nodo *nuevoNodo = (nodo *)malloc(sizeof(nodo));

    nuevoNodo->T.TareaId = rand() % 99;
    nuevoNodo->T.Duracion = rand() % 55;
    nuevoNodo->T.Descripcion = (char *)malloc(sizeof(char) * 150);
    printf("Ingresa la descripcion del nuevo nodo \n");
    fflush(stdin);
    scanf("%s", nuevoNodo->T.Descripcion);

    nuevoNodo->Siguiente = NULL;

    return nuevoNodo;
}

nodo *nodoEncontradoPorId(nodo **listaTarea, int Id)
{
    while (*listaTarea)
    {
        if ((*listaTarea)->T.TareaId == Id)
        {
            return (*listaTarea);
        }
    }
    return NULL;
}

void InsertarNodo(nodo **cabeceraLista)
{
    nodo *nuevoNodo = crearNodo();

    nuevoNodo->Siguiente = *cabeceraLista;
    *cabeceraLista = nuevoNodo;
}

void InsertarNodoRealizado(nodo **cabeceraListaRealizda, nodo *nodoRealizado)
{
    nodoRealizado->Siguiente = *cabeceraListaRealizda;
    *cabeceraListaRealizda = nodoRealizado;
}


void cargarTareasRealizadas(nodo **listaTarea, nodo **listaTareaRealizadas)
{
    int realizada = 0;
    nodo *TareaAuxiliar = CrearListaVacia();
    nodo *siguienteAux;
    while (*listaTarea != NULL)
    {
        printf("\n----------------------------------\n");
        printf("\nTAREA DE ID %d", (*listaTarea)->T.TareaId);
        printf("\nDURACION: %d", (*listaTarea)->T.Duracion);
        printf("\nDESCRIPCION: %s", (*listaTarea)->T.Descripcion);
        printf("\nIngrese 1 si la tarea ya fue realizada");
        fflush(stdin);
        scanf("%d", &realizada);
        siguienteAux = (*listaTarea)->Siguiente;
        if (realizada == 1)
        {
            (*listaTarea)->Siguiente = *listaTareaRealizadas;
            *listaTareaRealizadas = *listaTarea;
        }
        else
        {
            (*listaTarea)->Siguiente = TareaAuxiliar;
            TareaAuxiliar = *listaTarea;
        }
        *listaTarea = siguienteAux;
        printf("\n----------------------------------\n");
    }
    *listaTarea = TareaAuxiliar;
}

void MostrarTareas(nodo **listaTarea)
{
    nodo *aux = *listaTarea;

    printf("\n----------------TAREAS---------------\n");
    while (aux)
    {
        printf("\n----------------------------------\n");
        printf("\nTAREA DE ID %d", aux->T.TareaId);
        printf("\nDURACION: %d", aux->T.Duracion);
        printf("\nDESCRIPCION: %s", aux->T.Descripcion);
        aux = aux->Siguiente;
    }
}