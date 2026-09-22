#include <stdio.h>

int main()
{
    char codigo;
    int cantidadEntradas;
    float importeTotal;

    printf("Ingresar codigo: ");
    scanf("%c", &codigo);

    printf("Ingresar la cantidad de entradas: ");
    scanf(" %d", &cantidadEntradas);

    switch (codigo)
    {
    case 'G':
    case 'g':
        // general
        importeTotal = cantidadEntradas * 8000;
        printf("Precio final: $%.2f", importeTotal);
        break;

    case 'E':
    case 'e':
        // estudiante
        importeTotal = cantidadEntradas * 5000;
        printf("Precio final: $%.2f", importeTotal);
        break;

    case 'J':
    case 'j':
        // Jubilado
        importeTotal = cantidadEntradas * 4000;
        printf("Precio final: $%.2f", importeTotal);
        break;

    default:
        printf("Codigo incorrecto\n");
        printf("Precio final: $0");
        break;
    }

    return 0;
}