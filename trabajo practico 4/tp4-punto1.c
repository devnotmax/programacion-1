#include <stdio.h>
#include <ctype.h>

/* ---- Prototipos exigidos ---- */
float monto_item(int categoria, int cantidad, float precio_unidad);
void mostrar_item(int categoria, int cantidad, float precio_unidad, float precio_cantidad);
float total_con_medio_pago(char medio, int cuotas, float total);
int validacion(int categoria, int cantidad, float precio);
void mostrar_menu_categorias(void);

/* ---- Programa principal ---- */
int main(void)
{

    /* Declarar Entradas */
    int categoria, cantidad;
    float precio_unidad;

    /* Declarar e inicializar acumuladores por categoría (unidades y montos) */

    /* Declarar salidas */
    float monto;

    /* Variables auxiliares */
    int control = 0;

    /* Programar función para mostrar el menú */
    // mostrar_menu_categorias();

    /* LEER LAS ENTRADAS */

    /* Bucle MIENTRAS, validamos las entradas */
    control = validacion(categoria, cantidad, precio_unidad);
    while (control == 1)
    {
        /* Calcular y mostrar ítem */

        /* Acumular por categoría */

        /* Acumular totales */

        /* LEER - Nueva lectura dentro del while */
    }

    /* Aplicar Medio de pago */

    /* Mostrar Resumen final */

    return 0;
}

/* ---- DEFINIR LAS FUNCIONES ---- */