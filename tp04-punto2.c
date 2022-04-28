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

int cantidadTareas();
void leerTareas(Tarea **tareas, int cantidadTareas);
void mostrarTareasRealizadasYpendientes(Tarea **tareasRealizadas, Tarea **tareasPendientes, int cantidadTareas);
Tarea * buscarTareaPorId(Tarea **tareasRealizadas, int idTarea, int cantidadTareas);
Tarea * buscarTareaPorPalabra(Tarea **tareasRealizadas, char * PalabraClave, int cantidadTareas);


int main()
{
    printf("Hola, cuantas tareas debes realizar, ingresalas \n");
    int cantTareas = cantidadTareas();

    Tarea **tareas;
    tareas = (Tarea *)malloc(sizeof(Tarea) * cantTareas);
    Tarea **aux = tareas;

    for (int i = 0; i < cantTareas; i++)
    {
        tareas[i] = (Tarea *)malloc(sizeof(Tarea));
        tareas[i]->TareaID = i + 1;
        tareas[i]->Descripcion = (char *)malloc(sizeof(char) * 150);
        getchar();
        printf("ingresa la descripcion de la tarea %d \n", i + 1);
        scanf("%s", tareas[i]->Descripcion);
        tareas[i]->Duracion = 10 + i;
    }

    //leerTareas(tareas, cantTareas);
    char * palabraClave = (char *) malloc(sizeof(char) * 100);
    printf("\nIngresa la palabra con la que buscaras la tarea\n");
    scanf("%s", palabraClave);
    Tarea * tareaEncontrada = buscarTareaPorPalabra(tareas, palabraClave, cantTareas);
    printf("\n--------------TAREA ENCONTRADA-------------\n");
    printf("TAREA ID: %d \n", tareaEncontrada->TareaID);
    printf("DESCRIPCIÓN: %s \n", tareaEncontrada->Descripcion);
    printf("DURACIÓN: %d \n", tareaEncontrada->Duracion);

    
    int idTareaBuscar = 0;
    
    Tarea * tareaEntontrada = buscarTareaPorId(tareas, 1, cantTareas);
    printf("\n-------ENCONTRADA-----------\n");
    printf("ID de tarea: %d\n", tareaEntontrada->TareaID);
    printf("DESCRIPCIÓN: %s \n", tareaEntontrada->Descripcion);
    printf("Duración de tarea: %d\n", tareaEntontrada->Duracion);
    printf("--------------------");


}

int cantidadTareas()
{
    int retorno = 0;
    scanf("%d", &retorno);

    return retorno;
}

void leerTareas(Tarea **tareas, int cantidadTareas)
{
    Tarea **aux = tareas;

    Tarea **tareaRealizadas;
    tareaRealizadas = (Tarea *)malloc(sizeof(Tarea) * cantidadTareas);


    int realizada = 0;

    for (int i = 0; i < cantidadTareas; i++)
    {
        printf("\n---------Tarea numero %d---------\n", (i + 1));

        printf("TAREA ID: %d \n", aux[i]->TareaID);
        printf("DESCRIPCIÓN: %s \n", aux[i]->Descripcion);
        printf("DURACIÓN: %d \n", aux[i]->Duracion);

        printf("Realizaste la tarea? 1-si 2-no\n");
        scanf("%d", &realizada);

        if (realizada == 1)
        {
            tareaRealizadas[i] = (Tarea *)malloc(sizeof(Tarea) * cantidadTareas);
            tareaRealizadas[i]->TareaID = aux[i]->TareaID;
            tareaRealizadas[i]->Descripcion = aux[i]->Descripcion;
            tareaRealizadas[i]->Duracion = aux[i]->Duracion;

            aux[i] = NULL;
        }
        else
        {
            tareaRealizadas[i] = NULL;
        }

        printf("--------------------------------");
    }

    mostrarTareasRealizadasYpendientes(tareaRealizadas, aux, cantidadTareas);
}

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