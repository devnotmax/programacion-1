#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_ENTRADA 101
#define MAX_ENTRADA 100000
#define MAX_VENTAS 1000
#define MAX_PREMIOS 5

void cargarArreglo(int entradas[], int size);
void mostrarArreglo(int entradas[], int size);
int buscarNumero(int arreglo[], int cantidad, int numero);
void sortearGanadores(int entradas[], int size, int ganadores[], int premios);

int main(void)
{
    srand(time(NULL));

    int cantidadEntradas;
    int premios;

    do
    {
        printf("Ingrese la cantidad de entradas vendidas (%d a %d): ", 1, MAX_VENTAS);
        scanf("%d", &cantidadEntradas);

        if (cantidadEntradas < 1)
        {
            printf("Cantidad invalida: debe haber al menos 1 entrada vendida.\n");
        }
        else if (cantidadEntradas > MAX_VENTAS)
        {
            printf("Cantidad invalida: no puede superar las %d entradas.\n", MAX_VENTAS);
        }
    } while (cantidadEntradas < 1 || cantidadEntradas > MAX_VENTAS);

    do
    {
        printf("Ingrese la cantidad de premios a sortear (%d a %d): ", 1, MAX_PREMIOS);
        scanf("%d", &premios);

        if (premios < 1 || premios > MAX_PREMIOS)
        {
            printf("Cantidad invalida: no se pueden sortear mas de %d premios.\n", MAX_PREMIOS);
        }
        else if (premios > cantidadEntradas)
        {
            printf("Cantidad invalida: no puede haber mas premios que entradas vendidas.\n");
        }

    } while (premios < 1 || premios > MAX_PREMIOS || premios > cantidadEntradas);

    int entradas[cantidadEntradas];
    int ganadores[premios];

    cargarArreglo(entradas, cantidadEntradas);

    printf("\n+++++ ENTRADAS VENDIDAS +++++\n");
    mostrarArreglo(entradas, cantidadEntradas);

    sortearGanadores(entradas, cantidadEntradas, ganadores, premios);

    printf("\n+++++ GANADORES DEL SORTEO +++++\n");
    for (int i = 0; i < premios; i++)
    {
        printf("Premio %d: Entrada N° %d\n", i + 1, ganadores[i]);
    }

    return 0;
}

int buscarNumero(int arreglo[], int cantidad, int numero)
{
    for (int i = 0; i < cantidad; i++)
    {
        if (arreglo[i] == numero)
        {
            return i;
        }
    }
    return -1;
}

void cargarArreglo(int entradas[], int size)
{
    int numGenerado;
    int i = 0;

    while (i < size)
    {
        numGenerado = rand() % (MAX_ENTRADA - MIN_ENTRADA + 1) + MIN_ENTRADA;

        if (buscarNumero(entradas, i, numGenerado) == -1)
        {
            entradas[i] = numGenerado;
            i++;
        }
    }
}

void mostrarArreglo(int entradas[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Entrada %d: N° %d\n", i + 1, entradas[i]);
    }
}

void sortearGanadores(int entradas[], int size, int ganadores[], int premios)
{
    int indiceSorteado;
    int ticketGanador;
    int i = 0;

    while (i < premios)
    {
        indiceSorteado = rand() % size;
        ticketGanador = entradas[indiceSorteado];

        if (buscarNumero(ganadores, i, ticketGanador) == -1)
        {
            ganadores[i] = ticketGanador;
            i++;
        }
    }
}