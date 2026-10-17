#include <stdio.h>

void mostrarMenu(void);
float celsiusAFahrenheit(float celsius);
float fahrenheitACelsius(float fahrenheit);

int main(void)
{
    int opcionValida = 1;
    int opcionElegida;
    float temperaturaCelsius, temperaturaFahrenheit;

    do
    {
        mostrarMenu();

        printf("Elija una opcion: ");
        scanf("%d", &opcionElegida);
        printf("\n");

        switch (opcionElegida)
        {
        case 1:
            printf("Ingrese la temperatura en Celsius: ");
            scanf("%f", &temperaturaCelsius);

            temperaturaFahrenheit = celsiusAFahrenheit(temperaturaCelsius);

            printf("\n");
            printf("-- Resultados --\n");
            printf("Temperatura en Celsius: %.2f\n", temperaturaCelsius);
            printf("Temperatura en Fahrenheit: %.2f\n", temperaturaFahrenheit);
            printf("\n");

            break;

        case 2:
            printf("Ingrese la temperatura en Fahrenheit: ");
            scanf("%f", &temperaturaFahrenheit);

            temperaturaCelsius = fahrenheitACelsius(temperaturaFahrenheit);

            printf("\n");
            printf("-- Resultados --\n");
            printf("Temperatura en Fahrenheit: %.2f\n", temperaturaFahrenheit);
            printf("Temperatura en Celsius: %.2f\n", temperaturaCelsius);
            printf("\n");

            break;

        case 3:
            printf("Programa finalizado.\n");
            opcionValida = 0;
            break;

        default:
            printf("Error: opcion no valida. Intente nuevamente.\n\n");
            break;
        }

    } while (opcionValida);

    return 0;
}

void mostrarMenu(void)
{
    printf("-- Conversor de Temperaturas --\n");
    printf("1 - Celsius a Fahrenheit\n");
    printf("2 - Fahrenheit a Celsius\n");
    printf("3 - Cerrar programa\n");
    printf("----------------------------------\n");
}

float celsiusAFahrenheit(float celsius)
{
    return celsius * 9 / 5 + 32;
}

float fahrenheitACelsius(float fahrenheit)
{
    return (fahrenheit - 32) * 5 / 9;
}