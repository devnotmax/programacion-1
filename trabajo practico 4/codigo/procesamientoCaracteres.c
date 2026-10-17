#include <stdio.h>
#include <ctype.h>

int esVocal(char caracter);
int esDigitoPar(char caracter);
void mostrarResumen(int letras, int vocales, int consonantes, int digitosPares, int digitosImpares, int espacios, int otros);

int main()
{
    char c;
    int letras = 0, vocales = 0, consonantes = 0;
    int digitosPares = 0, digitosImpares = 0;
    int espacios = 0, otros = 0;

    printf("Ingrese una secuencia de caracteres finalizada en punto (.):\n");

    scanf("%c", &c);

    while (c != '.')
    {

        if (isalpha(c))
        {
            letras++;
            printf("Letra procesada: %c\n", toupper(c));

            if (esVocal(c))
            {
                vocales++;
            }
            else
            {
                consonantes++;
            }
        }
        else if (isdigit(c))
        {
            if (esDigitoPar(c))
            {
                digitosPares++;
            }
            else
            {
                digitosImpares++;
            }
        }
        else if (isspace(c))
        {
            espacios++;
        }
        else
        {
            otros++;
        }

        scanf("%c", &c);
    }

    mostrarResumen(letras, vocales, consonantes, digitosPares, digitosImpares, espacios, otros);

    return 0;
}

int esVocal(char caracter)
{
    char c = toupper(caracter);
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
    {
        return 1;
    }
    return 0;
}

int esDigitoPar(char caracter)
{
    if (caracter % 2 == 0)
    {
        return 1;
    }
    return 0;
}

void mostrarResumen(int letras, int vocales, int consonantes, int digitosPares, int digitosImpares, int espacios, int otros)
{
    printf("--- RESUMEN DE DATOS ---\n");
    printf("Total de Letras: %d\n", letras);
    printf("   -> Vocales: %d\n", vocales);
    printf("   -> Consonantes: %d\n", consonantes);
    printf("Total de Digitos pares: %d\n", digitosPares);
    printf("Total de Digitos impares: %d\n", digitosImpares);
    printf("Espacios en blanco (y saltos): %d\n", espacios);
    printf("Otros caracteres (simbolos): %d\n", otros);
    printf("--------------------------------------------\n");
}