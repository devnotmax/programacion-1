#include <stdio.h>

int main(void)
{
    float temperatura, superior, promedio, sumaTemperaturas;
    int cantidadDiasSuperior = 0;

    printf("Buscar temperaturas superiores a:");
    scanf("%f", &superior);
    printf("\n");

    for (int i = 1; i <= 7; i++)
    {
        printf("Ingresar la temperatura %d:", i);
        scanf("%f", &temperatura);
        printf("\n");

        if (temperatura > superior)
        {
            cantidadDiasSuperior++;
        }

        sumaTemperaturas += temperatura;
    }

    promedio = sumaTemperaturas / 7;

    // salidas
    printf("El promedio de temperaturas de la semana fue: %.2f\n", promedio);
    printf("La cantidad de dias donde hubo una temperatura superior a %.2f es: %d\n", superior, cantidadDiasSuperior);
    return 0;
}