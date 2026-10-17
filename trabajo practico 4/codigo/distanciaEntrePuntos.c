#include <stdio.h>
#include <math.h>

float distancia(float x1, float y1, float x2, float y2);

int main()
{
    float x1, y1, x2, y2, resultado;
    char opcion;

    do
    {
        printf("\n--- Cálculo de distancia entre dos puntos ---\n");

        printf("Punto A:\n");
        printf("x: ");
        scanf("%f", &x1);
        printf("y: ");
        scanf("%f", &y1);

        printf("Punto B:\n");
        printf("x: ");
        scanf("%f", &x2);
        printf("y: ");
        scanf("%f", &y2);

        resultado = distancia(x1, y1, x2, y2);

        printf("Distancia entre A y B: %.2f\n", resultado);

        printf("\n¿Desea calcular la distancia de otros puntos? (s/n): ");
        scanf(" %c", &opcion); 
        opcion = tolower(opcion);

    } while (opcion == 's');

    printf("Programa finalizado.\n");
    return 0;
}

float distancia(float x1, float y1, float x2, float y2)
{
    float dx = x2 - x1;
    float dy = y2 - y1;

    return sqrtf(powf(dx, 2.0f) + powf(dy, 2.0f));
}