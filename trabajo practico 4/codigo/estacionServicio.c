#include <stdio.h>
#include <ctype.h>
#define NAFTA 1500
#define DIESEL 1300

// definición de funciones
float calcularVenta(char combustible, float litros, char medioPago);
void mostrarVenta(char combustible, float litros, char medioPago, float total);
void mostrarResumen(int clientes, float litrosVendidos, float recaudacion);

int main(void)
{
    int clientes = 0, valido;
    float litrosVendidos = 0, recaudacion = 0, total = 0, litros;
    char opcion, combustible, medioPago;

    do
    {
        valido = 1;

        printf("Ingrese el tipo de combustible (N - Nafta / D - Diesel): ");
        scanf(" %c", &combustible);
        printf("\n");

        combustible = toupper(combustible);

        if (combustible != 'N' && combustible != 'D')
        {
            printf("Error: Tipo de combustible invalido.\n");
            valido = 0;
        }

        if (valido == 1)
        {
            printf("Ingrese los litros a cargar: \n");
            scanf("%f", &litros);

            if (litros <= 0)
            {
                printf("Error: La cantidad de litros debe ser mayor a cero.\n");
                valido = 0;
            }
        }

        if (valido == 1)
        {
            printf("Ingrese el medio de pago (E - Efectivo / T - Tarjeta / B - Billetera virtual): ");
            scanf(" %c", &medioPago);
            printf("\n");

            medioPago = toupper(medioPago);

            if (medioPago != 'E' && medioPago != 'T' && medioPago != 'B')
            {
                printf("Error: Medio de pago invalido.\n");
                valido = 0;
            }
        }

        if (valido == 1)
        {
            total = calcularVenta(combustible, litros, medioPago);
            mostrarVenta(combustible, litros, medioPago, total);

            clientes++;
            litrosVendidos += litros;
            recaudacion += total;
        }
        else
        {
            printf("Venta cancelada debido a errores de ingreso.\n\n");
        }

        printf("Desea seguir cargando ventas S/N: ");
        scanf(" %c", &opcion);
        printf("\n");

        opcion = tolower(opcion);

    } while (opcion == 's');

    mostrarResumen(clientes, litrosVendidos, recaudacion);
    return 0;
}

float calcularVenta(char combustible, float litros, char medioPago)
{
    float monto = 0;
    float total = 0;
    float descuento = 0;

    switch (combustible)
    {
    case 'N':
        monto = litros * NAFTA;
        break;
    case 'D':
        monto = litros * DIESEL;
        break;
    }

    if (litros > 30)
    {
        descuento += 3;
    }

    switch (medioPago)
    {
    case 'E':
        descuento += 10;
        break;
    case 'T':
        descuento += 0;
        break;
    case 'B':
        descuento += 5;
        break;
    }

    total = monto - (monto * descuento) / 100;
    return total;
}

void mostrarVenta(char combustible, float litros, char medioPago, float total)
{
    printf("---------- Venta ----------\n");
    printf("Cantidad de litros cargados: %.2f\n", litros);

    if (combustible == 'N')
    {
        printf("Tipo de combustible: Nafta\n");
    }
    else
    {
        printf("Tipo de combustible: Diesel\n");
    }

    switch (medioPago)
    {
    case 'E':
        printf("Medio de pago: Efectivo (10%% descuento)\n");
        break;
    case 'T':
        printf("Medio de pago: Tarjeta (Sin descuentos)\n");
        break;
    case 'B':
        printf("Medio de pago: Billetera virtual (5%% descuento)\n");
        break;
    }

    printf("Total a pagar: $%.2f\n", total);
    printf("--------------------------------\n");
}

void mostrarResumen(int clientes, float litrosVendidos, float recaudacion)
{
    printf("---------- Resumen de ventas ----------\n");
    printf("Cantidad de clientes atendidos: %d\n", clientes);
    printf("Cantidad de litros vendidos: %.2f\n", litrosVendidos);
    printf("Recaudacion total del dia: $%.2f\n", recaudacion);
    printf("---------------------------------------\n");
}