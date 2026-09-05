#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 8

// Declaracion de funciones
void cargarArreglo(int arreglo[], int tama);
void mostrarArreglo(int arreglo[], int tama);
int buscarEliminado(int arreglo[], int tama, int salvado1, int salvado2, int salvado3);
int buscarEliminadoConEmpate(int arreglo[], int tama, int salvado1, int salvado2, int salvado3);

int main()
{

    //----------------------------------------------------------
    // inicialización explicita para probar empates
    // int puntuaciones[] = {15, 21, 14, 18, 12, 20, 17, 16}; // sin empate, salvados 2, 6 y 4
    // int puntuaciones[] = {15, 21, 12, 18, 12, 20, 17, 16}; // empate,  salvados 2, 6 y 4
    // int puntuaciones[] = {10, 18, 22, 10, 17, 19, 10, 20}; // triple empate, salvados 2 3 6
    // int puntuaciones[] = {20, 20, 15, 10, 15, 10, 17, 18}; // empate, salvados 1, 7, 8
    // int puntuaciones[] = {10, 18, 22, 10, 17, 19, 9, 9}; // empate, salvados 3, 5, 6
    //----------------------------------------------------------
    int puntuaciones[TAM]; // inicializado en tiempo de ejecución
    int salvado1, salvado2, salvado3;
    int eliminado;
    int valido = 0;

    srand(time(NULL));

    // Cargar puntuaciones aleatorias
    cargarArreglo(puntuaciones, TAM);

    // Leer y validar salvados
    do
    {
        printf("\nIngrese el numero de los 3 participantes salvados (1 a 8, sin repetir):\n");
        scanf("%d %d %d", &salvado1, &salvado2, &salvado3);

        // completar control..
    } while (valido == 0);

    // Buscar el puntaje mínimo entre no salvados
    // completar ...

    // Mostrar resultados
    printf("\n++++++++++++++++ RESULTADOS FINALES ++++++++++++++++:\n");
    // completar...
    return 0;
}

// Definicion de funciones