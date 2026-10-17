#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

void cargarMatriz(int m[MAX][MAX], int filas, int columnas);
void mostrarMatriz(int m[MAX][MAX], int filas, int columnas);
void sumarMatriz(int a[MAX][MAX], int b[MAX][MAX], int resultado[MAX][MAX], int filas, int columnas);
int sumarElementos(int m[MAX][MAX], int filas, int columnas);

int main(void)
{
    srand(time(NULL));
    int filas, columnas, valido; // filas = puestos , columnas = productos

    do
    {
        printf("Ingrese la cantidad de puestos: \n");
        scanf(" %d", &filas);

        if (filas <= 0 || filas > 10)
        {
            printf("Error: El numero de puestos debe estar entre 1 y 10.\n");
            valido = 1;
        }
        else
        {
            valido = 0;
        }
    } while (valido == 1);

    do
    {
        printf("Ingrese la cantidad de productos: \n");
        scanf(" %d", &columnas);
        if (columnas <= 0 || columnas > 10)
        {
            printf("Error: El numero de productos debe estar entre 1 y 10.\n");
            valido = 1;
        }
        else
        {
            valido = 0;
        }
    } while (valido == 1);

    int sabado[filas][columnas];
    int domingo[filas][columnas];

    cargarMatriz(sabado, filas, columnas);
    cargarMatriz(domingo, filas, columnas);

    return 0;
}

void cargarMatriz(int m[MAX][MAX], int filas, int columnas)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            m[i][j] = rand() % 51; //Genera numeros aleatorios entre 0 y 50
        }
    }
}
