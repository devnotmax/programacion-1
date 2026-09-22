#include <stdio.h>

int main(void)
{
    int cantidadPalabras = 0;
    int longitudMasLarga = 0;
    int longitudMasCorta = 0;

    char caracter;

    int errorEncontrado = 0;
    int longitudActual = 0;
    int totalCaracteres = 0;
    int cantidadEspacios = 0;
    int cantidadLetras = 0;

    float promedioCaracPorPalabra;
    float porcentEspacios;

    printf("Ingresar la frase a analizar: ");

    do
    {
        scanf("%c", &caracter);

        if (caracter == ' ')
        {
            cantidadEspacios++;

            if (longitudActual > 0)
            {
                cantidadPalabras++;

                if (longitudActual > longitudMasLarga)
                {
                    longitudMasLarga = longitudActual;
                }

                if (longitudMasCorta == 0 || longitudActual < longitudMasCorta)
                {
                    longitudMasCorta = longitudActual;
                }

                longitudActual = 0;
            }
        }
        else
        {
            // Verificamos que sea una letra o número
            if ((caracter >= 'a' && caracter <= 'z') ||
                (caracter >= 'A' && caracter <= 'Z') ||
                (caracter >= '0' && caracter <= '9') ||
                caracter == 'ñ' ||
                caracter == 'Ñ')
            {
                longitudActual++;
                cantidadLetras++;
            }
            else if (caracter != '.')
            {
                printf("\nError: caracter no permitido.\n");
                errorEncontrado = 1;
            }
        }

    } while (caracter != '.' && errorEncontrado != 1);

    if (errorEncontrado == 0 && longitudActual > 0)
    {
        cantidadPalabras++;

        if (longitudActual > longitudMasLarga)
        {
            longitudMasLarga = longitudActual;
        }

        if (longitudMasCorta == 0 || longitudActual < longitudMasCorta)
        {
            longitudMasCorta = longitudActual;
        }
    }

    // Calcular y mostrar
    if (errorEncontrado == 0)
    {
        totalCaracteres = cantidadLetras + cantidadEspacios;

        if (cantidadPalabras > 0)
        {
            promedioCaracPorPalabra =
                (float)cantidadLetras / cantidadPalabras;
        }

        if (totalCaracteres > 0)
        {
            porcentEspacios =
                ((float)cantidadEspacios / totalCaracteres) * 100;
        }

        printf("\n");
        printf("------ INFORME FINAL ------\n");
        printf("Cantidad de palabras: %d\n", cantidadPalabras);
        printf("Longitud de la palabra mas larga: %d\n", longitudMasLarga);
        printf("Longitud de la palabra mas corta: %d\n", longitudMasCorta);
        printf("Promedio de caracteres por palabra: %.2f\n", promedioCaracPorPalabra);
        printf("Porcentaje de espacios sobre el total de caracteres: %.2f%%\n", porcentEspacios);
    }

    return 0;
}