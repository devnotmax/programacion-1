// El costo de cada tiro es de 1000
#include <stdio.h>
#include <stdlib.h> //Para el tema de la asignación dinamica de memoria
#include <time.h>
#define COSTO_TIRO 1000

// Declación de funciones
void cargarTiros(int *puntos, int tiros);                       // Función para cargar los puntajes de los tiros.
float calcularGanancia(int *puntos, int tiros, float *perdida); // Función que calcula cuánto ganó el jugador

int main()
{
    srand(time(NULL));
    int tiros, *puntos;
    float perdida, ganancia;
    printf("- - - - - EL JUEGO DEL SAPO - - - - -\n");
    printf("El costo de cada tiro es $%d\n", COSTO_TIRO);
    printf("Ingrese cuantos tiros desea realizar: ");
    scanf(" %d", &tiros);
    printf("\n");
    puntos = (int *)malloc(tiros * sizeof(int));
    perdida = tiros * COSTO_TIRO;

    if (puntos == NULL)
    {
        printf("Hubo un error al reservar memoria para los tiros.\n");
        return 0;
    }
    printf("- - - - - - - - - - - - - - - - - - -\n");

    cargarTiros(puntos, tiros);
    ganancia = calcularGanancia(puntos, tiros, &perdida);

    printf("\n");
    printf("=================== RESULTADOS =====================\n");
    printf("Cantidad de tiros realizados: %d\n", tiros);
    printf("Costo de los tiros:           $%.2f\n", (float)(tiros * COSTO_TIRO));
    printf("Penalizaciones por 0 puntos:  $%.2f\n", perdida - (tiros * COSTO_TIRO));
    printf("Total de dinero perdido:      $%.2f\n", perdida);
    printf("Total de premios obtenidos:   $%.2f\n", ganancia + perdida);
    printf("----------------------------------------------------\n");
    printf("SALDO FINAL:                  $%.2f\n", ganancia);
    printf("====================================================\n");

    free(puntos);

    return 0;
}

void cargarTiros(int *puntos, int tiros)
{
    for (int i = 0; i < tiros; i++)
    {
        *puntos = rand() % 11;

        printf("\n========================================\n");
        printf("              TIRO N° %d\n", i + 1);
        printf("========================================\n");
        printf("Puntos obtenidos: %d\n", *puntos);

        switch (*puntos)
        {
        case 10:
            // La boca de la vieja xd tiene un premio de $5000
            printf("Resultado: BOCA DE LA VIEJA!\n");
            printf("Premio: $5000\n");
            break;

        case 9:
            // La boca del sapo tiene un premio de $3000
            printf("Resultado: BOCA DEL SAPO!\n");
            printf("Premio: $3000\n");
            break;

        case 8:
        case 7:
        case 6:
        case 5:
        case 4:
        case 3:
        case 2:
        case 1:
            // Cualquiera de los otros tiene premio de $1000
            printf("Resultado: BOCA COMUN\n");
            printf("Premio: $1000\n");
            break;

        default:
            // El 0 no tiene premio y encima perdes plata
            printf("Resultado: SIN PREMIO\n");
            printf("Perdida: -$500\n");
            break;
        }

        printf("========================================\n");

        puntos++;
    }
}

float calcularGanancia(int *puntos, int tiros, float *perdida)
{
    float premios = 0, ganancia = 0;

    *perdida = tiros * COSTO_TIRO;

    for (int i = 0; i < tiros; i++)
    {
        switch (*puntos)
        {
        case 10:
            premios += 5000;
            break;

        case 9:
            premios += 3000;
            break;

        case 8:
        case 7:
        case 6:
        case 5:
        case 4:
        case 3:
        case 2:
        case 1:
            premios += 1000;
            break;

        default:
            *perdida += 500;
            break;
        }

        puntos++;
    }

    ganancia = premios - *perdida;

    return ganancia;
}