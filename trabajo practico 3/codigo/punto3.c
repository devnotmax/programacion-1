#include <stdio.h>

int main(void)
{
    int numero;
    int cantidadDigitos = 0;
    int cantidadPrimos = 0;
    int sumaPrimos = 0;
    int sumaImpares = 0;
    int aux;

    do
    {
        printf("Ingrese un numero entero entre 10 y 999999: ");
        scanf("%d", &numero);

        if (numero < 10 || numero > 999999)
        {
            printf("Error: el numero debe estar entre 10 y 999999.\n");
        }
    } while (numero < 10 || numero > 999999);

    printf("\nNumero ingresado: %d\n", numero);

    aux = numero;

    while (aux != 0)
    {
        int digito = aux % 10;
        int esPrimo = 1;

        cantidadDigitos++;

        if (digito < 2)
        {
            esPrimo = 0;
        }
        else
        {
            for (int i = 2; i * i <= digito; i++)
            {
                if (digito % i == 0)
                {
                    esPrimo = 0;
                    break;
                }
            }
        }

        if (esPrimo)
        {
            cantidadPrimos++;
            sumaPrimos += digito;
        }

        if (digito % 2 != 0)
        {
            sumaImpares += digito;
        }

        aux = aux / 10;
    }

    printf("a. Cantidad de digitos: %d\n", cantidadDigitos);
    printf("b. Cantidad de digitos primos: %d\n", cantidadPrimos);
    printf("c. Suma de los digitos primos: %d\n", sumaPrimos);
    printf("d. Suma de los digitos impares: %d\n", sumaImpares);

    return 0;
}