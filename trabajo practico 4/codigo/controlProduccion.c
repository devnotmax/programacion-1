#include <stdio.h>
#include <ctype.h>

#define MINIMO_MAN 500
#define MINIMO_TAR 450
#define MINIMO_NOCHE 400

// Declaración de funciones
float calcularPorcentajeDefectuosas(int producidas, int defectuosas);
int cumpleObjetivo(int producidas, int defectuosas, char turno);
void mostrarResultado(int numeroMaquina, int producidas, int defectuosas, char turno);

int main(void)
{
    char respuesta;

    // Variables para el reporte final (Acumuladores y Contadores)
    int totalMaquinas = 0;
    int totalCumplen = 0;
    int totalNoCumplen = 0;
    int totalProducidas = 0;
    int totalDefectuosas = 0;

    // Variables para calcular el máximo
    int maxProducidas = 0;
    int maqMaxProducidas = 0;

    do
    {
        int numeroMaquina, piezasProducidas, piezasDefectuosas;
        char turno;
        int valido;

        // Ingreso del número de máquina
        printf("\nIngresar Nro de maquina: ");
        scanf(" %d", &numeroMaquina);

        // Validación del turno
        do
        {
            printf("Ingresar Turno (M = Manana, T = Tarde, N = Noche): ");
            scanf(" %c", &turno);
            turno = toupper(turno); // Convierte a mayúscula por si ingresa 'm', 't' o 'n'

            if (turno != 'M' && turno != 'T' && turno != 'N')
            {
                printf("Error: Turno invalido. Ingrese M, T o N.\n");
                valido = 0;
            }
            else
            {
                valido = 1;
            }
        } while (valido == 0);

        // Validación de piezas producidas
        do
        {
            printf("Cantidad de piezas producidas: ");
            scanf(" %d", &piezasProducidas);

            if (piezasProducidas <= 0)
            {
                printf("Error: las piezas producidas deben ser mayores a cero.\n");
                valido = 0;
            }
            else
            {
                valido = 1;
            }
        } while (valido == 0);

        // Validación de piezas defectuosas
        do
        {
            printf("Cantidad de piezas defectuosas: ");
            scanf(" %d", &piezasDefectuosas);

            if (piezasDefectuosas < 0 || piezasDefectuosas > piezasProducidas)
            {
                printf("Error: Las piezas defectuosas no pueden ser menores a cero ni mayores a las producidas.\n");
                valido = 0;
            }
            else
            {
                valido = 1;
            }
        } while (valido == 0);

        printf("\n----------------------------------------\n");
        // Mostrar resultados individuales
        mostrarResultado(numeroMaquina, piezasProducidas, piezasDefectuosas, turno);
        printf("----------------------------------------\n");

        // --- ACTUALIZACIÓN DE VARIABLES PARA EL REPORTE FINAL ---
        totalMaquinas++;
        totalProducidas += piezasProducidas;
        totalDefectuosas += piezasDefectuosas;

        if (cumpleObjetivo(piezasProducidas, piezasDefectuosas, turno) == 1)
        {
            totalCumplen++;
        }
        else
        {
            totalNoCumplen++;
        }

        // Lógica para encontrar la máquina con mayor producción
        // Si es la primera máquina (totalMaquinas == 1) o si produce más que el máximo actual
        if (totalMaquinas == 1 || piezasProducidas > maxProducidas)
        {
            maxProducidas = piezasProducidas;
            maqMaxProducidas = numeroMaquina;
        }

        // Consultar si desea continuar
        printf("\nDesea ingresar los datos de otra maquina? (S/N): ");
        scanf(" %c", &respuesta);
        respuesta = toupper(respuesta);

    } while (respuesta == 'S');

    // --- REPORTE FINAL ---
    printf("\n============= REPORTE FINAL =============\n");
    if (totalMaquinas > 0)
    {
        printf("Cantidad total de maquinas procesadas: %d\n", totalMaquinas);
        printf("Maquinas que cumplieron el objetivo: %d\n", totalCumplen);
        printf("Maquinas que no cumplieron el objetivo: %d\n", totalNoCumplen);
        printf("Cantidad total de piezas producidas: %d\n", totalProducidas);
        printf("Cantidad total de piezas defectuosas: %d\n", totalDefectuosas);

        // Reutilizamos la función para calcular el porcentaje general
        float porcentajeGeneral = calcularPorcentajeDefectuosas(totalProducidas, totalDefectuosas);
        printf("Porcentaje general de piezas defectuosas: %.2f%%\n", porcentajeGeneral);

        printf("Maquina con mayor produccion: Nro %d (con %d piezas)\n", maqMaxProducidas, maxProducidas);
    }
    else
    {
        printf("No se ingresaron datos.\n");
    }
    printf("=========================================\n");

    return 0;
}

// Implementación de funciones

float calcularPorcentajeDefectuosas(int producidas, int defectuosas)
{
    return ((float)defectuosas / producidas) * 100.0;
}

int cumpleObjetivo(int producidas, int defectuosas, char turno)
{
    int cumple = 1;
    float porcentaje = calcularPorcentajeDefectuosas(producidas, defectuosas);

    switch (turno)
    {
    case 'M': // Mañana
        if (producidas < MINIMO_MAN || porcentaje > 5.0)
        {
            cumple = 0;
        }
        break;

    case 'T': // Tarde
        if (producidas < MINIMO_TAR || porcentaje > 5.0)
        {
            cumple = 0;
        }
        break;

    case 'N': // Noche
        if (producidas < MINIMO_NOCHE || porcentaje > 5.0)
        {
            cumple = 0;
        }
        break;

    default:
        cumple = 0;
        break;
    }
    return cumple;
}

void mostrarResultado(int numeroMaquina, int producidas, int defectuosas, char turno)
{
    float porcentaje = calcularPorcentajeDefectuosas(producidas, defectuosas);
    int objetivoCumplido = cumpleObjetivo(producidas, defectuosas, turno);

    printf("Resultado de la maquina %d:\n", numeroMaquina);
    printf("Piezas producidas: %d\n", producidas);
    printf("Piezas defectuosas: %d\n", defectuosas);
    printf("Turno: %c\n", turno);
    printf("Porcentaje de piezas defectuosas: %.2f%%\n", porcentaje);

    if (objetivoCumplido)
    {
        printf("El objetivo de produccion SE HA CUMPLIDO.\n");
    }
    else
    {
        printf("El objetivo de produccion NO SE HA CUMPLIDO.\n");
    }
}