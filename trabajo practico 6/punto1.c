
#include <stdio.h>
#include <stdlib.h>

void cargarArreglo(int cantidad, int *arreglo);
void mostrarArreglo(int cantidad, int *arreglo);
int longitudSecuencia(int cantidad, int *arreglo);
void buscarSecuencia(int longitud, int *arreglo, int *secuencia, int cantidad);

int main()
{
    int n;
    int *arreglo;
    int *secuencia;

    do
    {
        printf("Ingrese la cantidad de elementos: ");
        scanf("%d", &n);

        if (n <= 1)
        {
            printf("Error: La cantidad debe ser mayor que 1.\n");
        }

    } while (n <= 1);

    arreglo = malloc(n * sizeof(int));

    if (arreglo == NULL)
    {
        printf("Error: No se pudo asignar memoria para el arreglo.\n");
        return 1;
    }

    cargarArreglo(n, arreglo);

    printf("\nArreglo ingresado:\n");
    mostrarArreglo(n, arreglo);

    int longSecuencia = longitudSecuencia(n, arreglo);

    secuencia = malloc((longSecuencia + 2) * sizeof(int));

    if (secuencia == NULL)
    {
        printf("Error: No se pudo asignar memoria para la secuencia.\n");
        free(arreglo);
        return 1;
    }

    buscarSecuencia(longSecuencia, arreglo, secuencia, n);

    printf("\nSubsecuencia, longitud y suma:\n");
    mostrarArreglo(longSecuencia + 2, secuencia);

    free(arreglo);
    free(secuencia);

    return 0;
}

void cargarArreglo(int cantidad, int *arreglo)
{
    for (int i = 0; i < cantidad; i++)
    {
        printf("Ingrese el elemento %d: ", i + 1);
        scanf("%d", &arreglo[i]);
    }
}

void mostrarArreglo(int cantidad, int *arreglo)
{
    for (int i = 0; i < cantidad; i++)
    {
        if (i > 0)
        {
            printf(" ");
        }

        printf("%d", arreglo[i]);
    }

    printf("\n");
}

int longitudSecuencia(int cantidad, int *arreglo)
{
    int longActual = 1;
    int longMaxima = 1;

    for (int i = 1; i < cantidad; i++)
    {
        if (arreglo[i] > arreglo[i - 1])
        {
            longActual++;

            if (longActual > longMaxima)
            {
                longMaxima = longActual;
            }
        }
        else
        {
            longActual = 1;
        }
    }

    return longMaxima;
}

void buscarSecuencia(int longitudSecuencia, int *arreglo, int *secuencia, int longitudArreglo)
{
    int longActual = 1;
    int inicioActual = 0;
    int inicioMaximo = 0;
    int encontrada = 0;

    for (int i = 1; i < longitudArreglo && encontrada == 0; i++)
    {
        if (arreglo[i] > arreglo[i - 1])
        {
            longActual++;
        }
        else
        {
            longActual = 1;
            inicioActual = i;
        }

        if (longActual == longitudSecuencia)
        {
            inicioMaximo = inicioActual;
            encontrada = 1;
        }
    }

    int suma = 0;

    for (int i = 0; i < longitudSecuencia; i++)
    {
        secuencia[i] = arreglo[inicioMaximo + i];
        suma += secuencia[i];
    }

    secuencia[longitudSecuencia] = longitudSecuencia;
    secuencia[longitudSecuencia + 1] = suma;
}
