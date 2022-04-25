#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>



struct Tarea{
    int TareaID; //Numerado en ciclo iterativo
    char *Descripcion;
    int Duracion; //entre 10 - 100
} typedef Tarea;

struct Usuario{
    int idUsuario;
    char * NombreUsuario;
    Tarea * Tareas;
}typedef Usuario;

int cantidadTareas();
void leerTareas(Tarea ** tareas, int cantTareas);

int main()
{
    
    Usuario * nuevoUsuario = (Usuario *) malloc(sizeof(Usuario));
    nuevoUsuario->idUsuario = 1;
    nuevoUsuario->NombreUsuario = (char *) malloc(sizeof(char) * 100);
    strcpy(nuevoUsuario->NombreUsuario, "Santiago");

    printf("Hola %s cuantas tareas debes realizar, ingresalas \n", nuevoUsuario->NombreUsuario);
    int cantTareas = cantidadTareas();


    nuevoUsuario->Tareas = (Tarea * ) malloc(sizeof(Tarea) * cantTareas);


    for (int i = 0; i < cantTareas; i++)
    {
        nuevoUsuario->Tareas->TareaID = i+1;
        nuevoUsuario->Tareas->Duracion = 10 + i;
    }


        for (int i = 0; i < cantTareas; i++)
    {
        printf("\n-------Tarea numero %d-------\n", i+1);

        nuevoUsuario->Tareas->TareaID = i+1;
        printf("%d\n",nuevoUsuario->Tareas->TareaID);
        nuevoUsuario->Tareas->Duracion = 10 + i;
        printf("%d\n",nuevoUsuario->Tareas->Duracion);
        
        printf("--------------------------------");
    }


    
}

int cantidadTareas(){
    int retorno = 0;
    scanf("%d", &retorno);

    return retorno;
}

void leerTareas(Tarea ** tareas, int cantTareas){

    Tarea ** aux = tareas;

    for (int i = 0; i < cantTareas; i++)
    {

        printf("\n----Tarea = %d --------\n", aux[i]->TareaID);

        printf("Descripcion = %s \n", aux[i]->Descripcion);

        printf("Duracion %d", aux[i]->Duracion);

        printf("\n------------------------------------");
    }
    
}

