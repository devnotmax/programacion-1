#include <stdio.h>

int main()
{
    int nota;
    printf("Ingrese la nota: ");
    scanf("%d", &nota);

    if (nota >= 0)
    {
        if (nota <= 3)
        {
            printf("Desaprobado");
        }
        else if (nota <= 6)
        {
            printf("Aprobado");
        }
        else if (nota >= 7 && nota <= 10)
        {
            printf("promocionado");
        }
        else
        {
            printf("Valor fuera del intervalo");
        }
    }
    else
    {
        printf("Nota invalida");
    }

    return 0;
}