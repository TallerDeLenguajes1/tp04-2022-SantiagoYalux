#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct Tarea
{
    int TareaID; // Numerado en ciclo iterativo
    char *Descripcion;
    int Duracion; // entre 10 - 100
} typedef Tarea;

struct Nodos
{
    struct Nodos *siguiente;
    Tarea Tarea;
} typedef Nodos;

int cantidadTareas();
Nodos *CrearNodos();
void insertarTarea(Nodos **TareasPendientes);
void insertarTareaCreada(Nodos **Tareas, Nodos *NodosAgregar);
void leerTareas(Nodos **TareasPendientes, Nodos **TareasRealizadas, int cantidadTareas);
void mostrarTareasRealizadasYpendientes(Tarea **tareasRealizadas, Tarea **tareasPendientes, int cantidadTareas);

Tarea *buscarTareaPorId(Tarea **tareasRealizadas, int idTarea, int cantidadTareas);
Tarea *buscarTareaPorPalabra(Tarea **tareasRealizadas, char *PalabraClave, int cantidadTareas);

int main()
{
    printf("Hola, cuantas tareas debes realizar, ingresalas \n");
    int cantTareas = cantidadTareas();

    Nodos *TareasPendientes = NULL;
    Nodos *TareasRealizadas = NULL;

    for (int i = 0; i < cantTareas; i++)
    {
        insertarTarea(&TareasPendientes);
    }

    leerTareas(&TareasPendientes, &TareasRealizadas, cantTareas);
    /*char * palabraClave = (char *) malloc(sizeof(char) * 100);
    printf("\nIngresa la palabra con la que buscaras la tarea\n");
    scanf("%s", palabraClave);
    Tarea * tareaEncontrada = buscarTareaPorPalabra(tareas, palabraClave, cantTareas);
    printf("\n--------------TAREA ENCONTRADA-------------\n");
    printf("TAREA ID: %d \n", tareaEncontrada->TareaID);
    printf("DESCRIPCIÓN: %s \n", tareaEncontrada->Descripcion);
    printf("DURACIÓN: %d \n", tareaEncontrada->Duracion);


    int idTareaBuscar = 0;
    printf("\nBusca una tarea a partir de su Id: \n");
    scanf("%d", &idTareaBuscar);
    Tarea * tareaEntontrada = buscarTareaPorId(tareas, idTareaBuscar, cantTareas);
    printf("\n-------ENCONTRADA-----------\n");
    printf("ID de tarea: %d\n", tareaEntontrada->TareaID);
    printf("DESCRIPCIÓN: %s \n", tareaEntontrada->Descripcion);
    printf("Duración de tarea: %d\n", tareaEntontrada->Duracion);*/
    printf("--------------------");
    /*insertarTarea(TareasRealizadas);
    insertarTarea(TareasPendientes);
    insertarTarea(TareasRealizadas);
    insertarTarea(TareasPendientes);*/

    // mostrarTareasRealizadasYpendientes(TareasRealizadas, TareasPendientes, cantTareas);
}

int cantidadTareas()
{
    int retorno = 0;
    scanf("%d", &retorno);

    return retorno;
}

void leerTareas(Nodos **TareasPendientes, Nodos **TareasRealizadas, int cantidadTareas)
{
    int realizada = 0;
    int i = 0;
    while ((*TareasPendientes) != NULL)
    {
        printf("\n---------Tarea numero %d---------\n", (i + 1));

        printf("TAREA ID: %d \n", (*TareasPendientes)->Tarea.TareaID);
        printf("DESCRIPCIÓN: %s \n", (*TareasPendientes)->Tarea.Descripcion);
        printf("DURACIÓN: %d \n", (*TareasPendientes)->Tarea.Duracion);

        printf("Realizaste la tarea? 1-si 2-no\n");
        scanf("%d", &realizada);

        if (realizada == 1)
        {
            //   insertarTareaCreada(TareasRealizadas, &TareasPendientes[i]->Tarea);
            // TareasPendientes[i]->Tarea = NULL;
        }
        else
        {
            // TareasRealizadas[i]->Tarea = NULL;
        }

        i++;
        (*TareasPendientes)++;
    }

    printf("--------------------------------");
}

void insertarTarea(Nodos **TareasPendientes)
{
    Nodos *nuevoNodos = CrearNodos();

    nuevoNodos->siguiente = *TareasPendientes;
    *TareasPendientes = nuevoNodos;
}

/*
void mostrarTareasRealizadasYpendientes(Tarea **tareasRealizadas, Tarea **tareasPendientes, int cantidadTareas)
{
    printf("*** MOSTRAR TAREAS REALIZADAS Y TAREAS PENDIENTES ***\n\n");
    Tarea **auxRealizadas = tareasRealizadas;
    Tarea **auxPendientes = tareasPendientes;

    printf("\n-------------TAREAS REALIZADAS-------------\n");
    for (int i = 0; i < cantidadTareas; i++)
    {
        if (auxRealizadas[i] != NULL)
        {
            printf("\n------------------\n");
            printf("ID de tarea: %d\n", auxRealizadas[i]->TareaID);
            printf("DESCRIPCIÓN: %s \n", auxRealizadas[i]->Descripcion);
            printf("Duración de tarea: %d\n", auxRealizadas[i]->Duracion);
            printf("--------------------");
        }
    }
    printf("\n");

    printf("\n-------------TAREAS PENDIENTES-------------\n");
    for (int i = 0; i < cantidadTareas; i++)
    {
        if (auxPendientes[i] != NULL)
        {
            printf("\n------------------\n");
            printf("ID de tarea: %d\n", auxPendientes[i]->TareaID);
            printf("DESCRIPCIÓN: %s \n", auxPendientes[i]->Descripcion);
            printf("Duración de tarea: %d\n", auxPendientes[i]->Duracion);
            printf("--------------------");
        }
    }
    printf("\n");
}


void insertarTareaCreada(Nodos ** Tareas, Nodos * NodosAgregar)
{
    Nodos * nuevoNodos = NodosAgregar;

    nuevoNodos->siguiente = *Tareas;
    *Tareas = nuevoNodos;
}
*/
Nodos *CrearNodos()
{
    Nodos *nuevoNodos = (Nodos *)malloc(sizeof(Nodos));
    Tarea *tareaAsociadaNodos = (Tarea *)malloc(sizeof(Tarea));

    // ahora pedimos los datos de esta nueva tarea
    tareaAsociadaNodos->TareaID = rand() % 99;
    tareaAsociadaNodos->Duracion = rand() % 99;
    tareaAsociadaNodos->Descripcion = (char *)malloc(sizeof(char) * 150);
    printf("Ingresa la descripcion de la tarea Id: %d\n", tareaAsociadaNodos->TareaID);
    scanf("%s", tareaAsociadaNodos->Descripcion);

    nuevoNodos->Tarea = *tareaAsociadaNodos;
    nuevoNodos->siguiente = NULL;
    return nuevoNodos;
}
/*
Tarea * buscarTareaPorPalabra(Tarea **tareasRealizadas, char * PalabraClave, int cantidadTareas)
{
    for (int i = 0; i < cantidadTareas; i++)
    {
        if(!(strcmp(tareasRealizadas[i]->Descripcion, PalabraClave))){
            return tareasRealizadas[i];
        }
    }
}

Tarea * buscarTareaPorId(Tarea **tareasRealizadas, int idTarea, int cantidadTareas)
{
    for (int i = 0; i < cantidadTareas; i++)
    {
        if(tareasRealizadas[i]->TareaID == idTarea){
            return tareasRealizadas[i];
        }
    }
}
*/