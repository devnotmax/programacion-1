#include <stdio.h>

int main()
{
    const float IVA = 0.21;
    float consumo, subtotal_sin_iva, subtotal_con_iva, total_a_pagar;
    char categoria, metodo;

    /* A1: LEER(consumo, categoría, método) */
    printf("Consumo en m3: ");
    scanf("%f", &consumo);
    printf("\nCONSUMO: %f\n", consumo);
    printf("Categoria (H/C/I):");
    fflush(stdin);
    scanf(" %c", &categoria);
    printf("Metodo de pago (E/T/D): ");
    fflush(stdin);
    scanf(" %c", &metodo);

    /* A2 SEGÚN(categoría) */
    switch (categoria)
    {
    case 'H':
        if (consumo <= 20)
            subtotal_sin_iva = 1200 + consumo * 45;
        else
            subtotal_sin_iva = 1200 + 20 * 45 + (consumo - 20) * 70;
        break;

    case 'C':
        if (consumo <= 50)
            subtotal_sin_iva = 3000 + consumo * 60;
        else
            subtotal_sin_iva = 3000 + 50 * 60 + (consumo - 50) * 95;
        break;

    case 'I':
        subtotal_sin_iva = 7500 + consumo * 130;
        break;

    default:
        printf("Categoria invalida.\n");
        subtotal_sin_iva = 0;
    }

    /* CONTINUAR... */
    /* A3: AJUSTES_FONDO_AMBIENTAL_IVA */
    /* A4: TOTAL_METODO_DE_PAGO */
    /* A5: ESCRIBIR(subtotal_sin_iva, subtotal_con_iva, total_a_pagar) */

    return 0; // A6: PARAR
}
