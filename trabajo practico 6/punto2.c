#include <stdio.h>
#include <ctype.h>
#define MAX 80

// Declaración funciones
void convertirCadena(char *p_cadena, char *p_resultado);
void mostrarCadena(char *p_cadena);

int main()
{
    char cadena[MAX], *p_cadena, resultado[MAX], *p_resultado;

    printf("Ingresa la oracion: ");
    fgets(cadena, MAX, stdin);
    p_cadena = cadena;

    while (*p_cadena != '\0' && *p_cadena != '\n')
    {
        p_cadena++;
    }

    *p_cadena = '\0';

    p_cadena = cadena;
    p_resultado = resultado;

    convertirCadena(p_cadena, p_resultado);

    printf("Cadena original: ");
    mostrarCadena(cadena);

    printf("Cadena convertida: ");
    mostrarCadena(resultado);

    return 0;
}

void convertirCadena(char *p_cadena, char *p_resultado)
{
    while (*p_cadena == ' ')
    {
        p_cadena++;
    }

    while (*p_cadena != '\0')
    {
        if (*p_cadena == ' ')
        {
            while (*p_cadena == ' ')
            {
                p_cadena++;
            }

            if (*p_cadena != '\0')
            {
                *p_resultado = '_';
                p_resultado++;
            }
        }
        else
        {
            *p_resultado = tolower(*p_cadena);
            p_resultado++;
            p_cadena++;
        }
    }

    *p_resultado = '\0';
}

void mostrarCadena(char *p_cadena)
{
    while (*p_cadena != '\0')
    {
        printf("%c", *p_cadena);
        p_cadena++;
    }

    printf("\n");
}