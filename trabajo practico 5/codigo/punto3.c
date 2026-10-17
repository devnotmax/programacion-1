#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

void cargarMatriz(int m[MAX][MAX], int filas, int columnas);
void mostrarMatriz(int m[MAX][MAX], int filas, int columnas);
void sumarMatriz(int a[MAX][MAX], int b[MAX][MAX], int resultado[MAX][MAX], int filas, int columnas);
int sumarElementos(int m[MAX][MAX], int filas, int columnas);
int puestoMasVendedor(int m[MAX][MAX], int filas, int columnas);
int productoMasVendido(int m[MAX][MAX], int filas, int columnas);

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

    int sabado[MAX][MAX];
    int domingo[MAX][MAX];
    int ventasTotales[MAX][MAX];

    cargarMatriz(sabado, filas, columnas);
    cargarMatriz(domingo, filas, columnas);

    printf("---- Ventas del sabado ----\n");
    mostrarMatriz(sabado, filas, columnas);

    int ventaSabado = sumarElementos(sabado, filas, columnas);
    printf("Ventas totales del sabado: %d", ventaSabado);

    printf("---- Ventas del domingo ----\n");
    mostrarMatriz(domingo, filas, columnas);

    int ventaDomingo = sumarElementos(domingo, filas, columnas);
    printf("Ventas totales del domingo: %d\n", ventaDomingo);

    printf("---- Ventas totales ----\n");
    sumarMatriz(sabado, domingo, ventasTotales, filas, columnas);
    mostrarMatriz(ventasTotales, filas, columnas);

    int total = sumarElementos(ventasTotales, filas, columnas);
    printf("Total de unidades vendidas en el festival: %d", total);

    return 0;
}

void cargarMatriz(int m[MAX][MAX], int filas, int columnas)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            m[i][j] = rand() % 51; // Genera numeros aleatorios entre 0 y 50
        }
    }
}

void mostrarMatriz(int m[MAX][MAX], int filas, int columnas)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
}

void sumarMatriz(int a[MAX][MAX], int b[MAX][MAX], int resultado[MAX][MAX], int filas, int columnas)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            resultado[i][j] = a[i][j] + b[i][j];
        }
    }
}

int sumarElementos(int m[MAX][MAX], int filas, int columnas)
{
    int contador = 0;

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            contador += m[i][j];
        }
    }

    return contador;
}

int puestoMasVendedor(int m[MAX][MAX], int filas, int columnas){
    //Tiene que devolver el indice buscado.
}