#include <stdio.h>
#define aguaMin 6.5
#define aguaMax 8.5
#define sueloAgMin 5.5
#define sueloAgMax 7.5
#define alimentoAcMin 4.0
#define alimentoAcMax 7.0

int main(void)
{
    float lectura1, lectura2, lectura3, promedio;
    float limInf, limSup;
    int tipoMuestra, muestraValida = 1;

    printf("------------ Evaluacion de PH ---------------\n");

    printf("Ingresar la primera lectura: ");
    scanf("%f", &lectura1);

    printf("Ingresar la segunda lectura: ");
    scanf("%f", &lectura2);

    printf("Ingresar la tercera lectura: ");
    scanf("%f", &lectura3);

    if (lectura1 < 0 || lectura1 > 14 || lectura2 < 0 || lectura2 > 14 || lectura3 < 0 || lectura3 > 14)
    {
        printf("Error: lectura fuera del intervalo (0 a 14)\n");
    }
    else
    {
        printf("--------- Seleccionar tipo de muestra -----------\n");
        printf("1. Agua potable\n");
        printf("2. Suelo agricola\n");
        printf("3. Alimento acido\n");
        printf("Tipo de muestra: ");
        scanf("%d", &tipoMuestra);

        promedio = (lectura1 + lectura2 + lectura3) / 3.0;

        switch (tipoMuestra)
        {
        case 1:
            limInf = aguaMin;
            limSup = aguaMax;
            break;
        case 2:
            limInf = sueloAgMin;
            limSup = sueloAgMax;
            break;
        case 3:
            limInf = alimentoAcMin;
            limSup = alimentoAcMax;
            break;
        default:
            printf("Error: tipo de muestra invalido\n");
            muestraValida = 0;
            break;
        }

        if (muestraValida == 1)
        {
            printf("\n--- Resultados ---\n");
            printf("pH promedio: %.2f\n", promedio);
            printf("Rango: %.2f - %.2f\n", limInf, limSup);
            // Evaluamos si está dentro del rango
            printf("Estado: \n");
            if (promedio >= limInf && promedio <= limSup)
            {
                printf("- Dentro del rango\n");

                if ((promedio - limInf < 0.2) || (limSup - promedio < 0.2))
                {
                    printf("- Cerca del limite\n");
                }
            }
            else if (promedio < limInf)
            {
                printf("- Por debajo del rango\n");

                if (limInf - promedio > 1.0)
                {
                    printf("- Alerta prioritaria\n");
                }
            }
            else
            {
                printf("- Por encima del rango\n");

                if (promedio - limSup > 1.0)
                {
                    printf("- Alerta prioritaria\n");
                }
            }
        }
    }

    return 0;
}