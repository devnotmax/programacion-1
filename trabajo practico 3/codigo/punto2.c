#include <stdio.h>

int main(void)
{
    float montoDeseado, aporte, montoRestante, mayorAporte = 0, totalRecaudado;
    int cantidadAportes = 0;
    printf("Ingrese el monto deseado:");
    scanf("%f", &montoDeseado);
    printf("\n");

    printf("----------------------------\n");
    montoRestante = 0;

    do
    {
        printf("Monto aporte:");
        scanf("%f", &aporte);
        printf("\n");

        cantidadAportes++;
        if (aporte > mayorAporte)
        {
            mayorAporte = aporte;
        }
        totalRecaudado += aporte;
        montoRestante += aporte;

    } while (montoRestante < montoDeseado);

    printf("Cantidad de aportes recibidos: %d\n", cantidadAportes);
    printf("El mayor aporte recibido fue: %.2f\n", mayorAporte);
    printf("El total del dinero recaudado es: %.2f\n", totalRecaudado);

    return 0;
}