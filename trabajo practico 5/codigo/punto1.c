#include <stdio.h>
#define PARTIDAS 8
#define MAX_KILLS 25

// declaración de funciones
void cargarArreglo(int kills[], int size);
void mostrarArreglo(int kills[], int size);
int buscarMejorPartida(int kills[], int size);
float calcularPromedio(int kills[], int size);
int contarSuperioresAlPromedio(int kills[], int size);
int mejorRacha(int kills[], int size, float promedio);

int main(void)
{
    int indiceMejorPartida;
    float promedioKills;
    int superioresAlPromedio;
    int kills[PARTIDAS];
    cargarArreglo(kills, PARTIDAS);
    mostrarArreglo(kills, PARTIDAS);

    printf("\n");
    printf("------------- Resumen de la noche -------------\n");
    // mejor partida
    indiceMejorPartida = buscarMejorPartida(kills, PARTIDAS);
    printf("Mejor partida: Partida %d con %d eliminaciones\n", indiceMejorPartida + 1, kills[indiceMejorPartida]);

    // promedio
    promedioKills = calcularPromedio(kills, PARTIDAS);
    printf("Promedio: %.2f eliminaciones por partida\n", promedioKills);

    // partidas por encima del promedio
    superioresAlPromedio = contarSuperioresAlPromedio(kills, PARTIDAS);
    printf("Partidas superiores al promedio: %d\n", superioresAlPromedio);
    // mejor racha
    int mejorStreak = mejorRacha(kills, PARTIDAS, promedioKills);
    printf("Mejor racha: %d partidas superiores al promedio\n", mejorStreak);
    return 0;
}

void cargarArreglo(int kills[], int size)
{
    for (int i = 0; i < size; i++)
    {
        do
        {
            printf("Ingrese la cantidad de kills del jugador en la partida %d (0-25): ", i + 1);
            scanf("%d", &kills[i]);
            printf("\n");

            if (kills[i] < 0 || kills[i] > 25)
            {
                printf("Error: La cantidad ingresada no es valida. Debe estar entre 0 y 25.\n");
            }

        } while (kills[i] < 0 || kills[i] > 25);
    }
}

void mostrarArreglo(int kills[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Kills de la partida %d: %d\n", i + 1, kills[i]);
    }
}

int buscarMejorPartida(int kills[], int size)

{
    int mejorPartida = 0;
    int mejorKills = kills[0];

    for (int i = 1; i < size; i++)
    {
        if (kills[i] > mejorKills)
        {
            mejorKills = kills[i];
            mejorPartida = i;
        }
    }

    return mejorPartida;
}

float calcularPromedio(int kills[], int size)
{
    int suma = 0;
    float promedio;
    for (int i = 0; i < size; i++)
    {
        suma += kills[i];
    }

    promedio = (float)suma / size;

    return promedio;
}

int contarSuperioresAlPromedio(int kills[], int size)
{
    float promedio = calcularPromedio(kills, PARTIDAS);
    int cantidadSuperiores = 0;
    for (int i = 0; i < size; i++)
    {
        if (kills[i] > promedio)
        {
            cantidadSuperiores++;
        }
    }

    return cantidadSuperiores;
}

int mejorRacha(int kills[], int size, float promedio)
{
    int streakActual = 0;
    int mejorStreak = 0;
    for (int i = 0; i < size; i++)
    {
        if (kills[i] > promedio)
        {
            streakActual++;
        }
        else
        {
            if (streakActual > mejorStreak)
            {
                mejorStreak = streakActual;
            }
            streakActual = 0;
        }
    }
    return mejorStreak;
}