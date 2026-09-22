// #validar que el consumo sea un valor real >= 0
#include <stdio.h>
#define cargoFijoHogar 1200
#define cargoFijoComercio 3000
#define cargoFijoIndustria 7500
#define IVA 1.21

int main()
{
    float consumo;
    char categoria, metodo;

    printf("--------------------------\n");

    printf("Ingrese el consumo: ");
    scanf("%f", &consumo);

    printf("\n");

    printf("Ingrese la categoria: ");
    scanf(" %c", &categoria);

    printf("\n");

    printf("Ingrese el metodo de pago: ");
    scanf(" %c", &metodo);

    printf("\n");

    printf("--------------------------\n");

    // salidas
    float subtotalSinIva, subtotal, total;

    // auxiliares
    float consumoRestante;

    if (consumo >= 0)
    {
        switch (categoria)
        {
        case 'h':
        case 'H':
            // hogar
            subtotalSinIva = cargoFijoHogar;
            if (consumo > 20)
            {
                consumoRestante = consumo - 20;
                subtotalSinIva += (20 * 45) + (70 * consumoRestante);
            }
            else
            {
                subtotalSinIva += consumo * 45;
            }
            break;

        case 'c':
        case 'C':
            // comercio
            subtotalSinIva = cargoFijoComercio;
            if (consumo > 50)
            {
                consumoRestante = consumo - 20;
                subtotalSinIva += (20 * 60) + (95 * consumoRestante);
            }
            else
            {
                subtotalSinIva += consumo * 60;
            }
            break;

        case 'i':
        case 'I':
            // industria
            subtotalSinIva = cargoFijoIndustria + consumo * 130;
            break;
        default:
            break;
            printf("Error: categoria invalida\n");
        }

        // algunos ajustes
        if (consumo > 120)
        {
            subtotalSinIva += subtotalSinIva * 0.02;
        }

        // le aplicamos iba
        subtotal = subtotalSinIva * IVA;

        // ajustes por medio de pago (Trabajo ahora con el subtotal)
        switch (metodo)
        {
        case 'e':
        case 'E':
            // efectivo
            total = subtotal * 0.96; // descuento del 4%
            break;

        case 't':
        case 'T':
            // tarjeta
            total = subtotal * 1.015; // recargo del 1.5%
            break;

        case 'd':
        case 'D':
            // debito
            total = subtotal;
            break;
        default:
            printf("Error: metodo de pago invalido\n");
            break;
        }

        // SALIDAS
        printf("Subtotal (Sin iva): $%.2f\n", subtotalSinIva);
        printf("Subtotal (Con iva): $%.2f\n", subtotal);
        printf("Total a pagar: $%.2f\n", total);
    }
    else
    {
        printf("Error: consumo invalido\n");
    }

    return 0;
}