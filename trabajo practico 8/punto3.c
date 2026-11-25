// FleetPointers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{
    int day;
    int month;
    int year;
} Fecha;

typedef struct
{
    Fecha fechaMantenimiento;
    char descripcion[100];
    float costoReparacion;
    char nombreTaller[50];
} Mantenimiento;

typedef struct
{
    char patente[4];
    char marca[50];
    int year;
    float kmActuales;
    int cantMantenimientos;
    Mantenimiento *mantenimientos;
} Camion;

// Declaracion de funciones
void cargarCamiones(Camion *camiones);
void cargarMantenimientos(Camion *camiones, int cant);
void actualizarKilometraje(Camion *camiones, int cant, char patente[], float nuevoKm);
float calcularGastoTotal(Camion camion);
void mostrarCamionesPorTaller(Camion *camiones, int cant, char taller[]);
void mostrarCamionMayorMantenimientos(Camion *camiones, int cant, char taller[]);
void listarCamionesCostoReparacion(Camion *camiones, int cant, float monto);

int main()
{
    int cant = 5;

    Camion *camiones = malloc(cant * sizeof(Camion));
    // cargar los camiones
    cargarCamiones(camiones);

    // cargar los mantenimientos
    cargarMantenimientos(camiones, cant);

    printf("========= Camiones cargados =========\n");
    // menu principal

    return 0;
}

void cargarCamiones(Camion *camiones)
{
    camiones[0] = (Camion){"AB12", "Volvo", 2015, 520000, 2, NULL};
    camiones[1] = (Camion){"AC45", "Scania", 2019, 210000, 2, NULL};
    camiones[2] = (Camion){"AD78", "Mercedes-Benz", 2017, 380000, 1, NULL};
    camiones[3] = (Camion){"AE01", "Tesla", 2020, 150000, 1, NULL};
    camiones[4] = (Camion){"AF34", "MAN", 2018, 290000, 1, NULL};
}

void cargarMantenimientos(Camion *camiones, int cant)
{
    for (int i = 0; i < cant; i++)
    {
        camiones[i].mantenimientos = malloc(camiones[i].cantMantenimientos * sizeof(Mantenimiento));
    }

    camiones[0].mantenimientos[0] = (Mantenimiento){{15, 1, 2024}, "Cambio de aceite", 85000, "Taller Norte"};
    camiones[0].mantenimientos[1] = (Mantenimiento){{10, 5, 2024}, "Revision de frenos", 150000, "Taller Sur"};
    camiones[1].mantenimientos[0] = (Mantenimiento){{28, 1, 2025}, "Revision de suspension", 230000, "Taller Norte"};
    camiones[1].mantenimientos[1] = (Mantenimiento){{5, 3, 2025}, "Cambio de filtros", 60000, "Taller Centro"};
    camiones[2].mantenimientos[0] = (Mantenimiento){{12, 1, 2024}, "Revision de frenos", 175000, "Taller Norte"};
    camiones[3].mantenimientos[0] = (Mantenimiento){{20, 2, 2024}, "Cambio de llantas", 120000, "Taller Sur"};
    camiones[4].mantenimientos[0] = (Mantenimiento){{15, 4, 2024}, "Revision de motor", 300000, "Taller Norte"};
}

void actualizarKilometraje(Camion *camiones, int cant, char patente[], float nuevoKm)
{
    // Buscar entre los camiones cargados la patente solicitada
    int patenteEncontrada = 0;
    for (int i = 0; i < cant; i++)
    {
        if (strcmp(camiones[i].patente, patente) == 0)
        {
            // Significa que son iguales entonces hacemos el cambio.
            patenteEncontrada = 1;

            // Hago la validacion de si los km viejos eran mayores al nuevo
            if (nuevoKm > camiones[i].kmActuales)
            {
                camiones[i].kmActuales = nuevoKm;
            }
            else
            {
                printf("Error: El kilometraje nuevo no puede ser menor al actual\n");
            }
        }
    }

    if (patenteEncontrada == 0)
    {
        printf("Error: No se encontro la patente solicitada.\n");
    }
}

float calcularGastoTotal(Camion camion)
{
    float suma = 0;
    for (int i = 0; i < camion.cantMantenimientos; i++)
    {
        suma += camion.mantenimientos[i].costoReparacion;
    }

    return suma;
}

void mostrarCamionMayorMantenimientos(Camion *camiones, int cant, char taller[])
{
    int camionMostrar = -1;
    int cantMaxima = 0;

    for (int i = 0; i < cant; i++)
    {
        int cantActual = 0;

        for (int j = 0; j < camiones[i].cantMantenimientos; j++)
        {
            if (strcmp(camiones[i].mantenimientos[j].nombreTaller, taller) == 0)
            {
                cantActual++;
            }
        }

        if (cantActual > cantMaxima)
        {
            cantMaxima = cantActual;
            camionMostrar = i;
        }
    }

    if (camionMostrar == -1)
    {
        printf("Ningun camion tiene mantenimientos en el taller '%s'.\n", taller);
    }
    else
    {
        printf("El camion con mas mantenimientos en '%s' es: %s - %s (%d mantenimientos)\n",
               taller, camiones[camionMostrar].patente, camiones[camionMostrar].marca, cantMaxima);
    }
}

void mostrarCamionesPorTaller(Camion *camiones, int cant, char taller[])
{
    for (int i = 0; i < cant; i++)
    {
        int encontrado = 0;

        if (camiones[i].year < 2018)
        {
            for (int j = 0; j < camiones[i].cantMantenimientos && encontrado == 0; j++)
            {
                if (strcmp(camiones[i].mantenimientos[j].nombreTaller, taller) == 0)
                {
                    encontrado = 1;
                }
            }
        }

        if (encontrado == 1)
        {
            printf("Patente: %s - Kms: %.2f\n", camiones[i].patente, camiones[i].kmActuales);
        }
    }
}

void listarCamionesCostoReparacion(Camion *camiones, int cant, float monto)
{
    int resultados = 0;
    for (int i = 0; i < cant; i++)
    {
        int camionCumple = 0;
        for (int j = 0; j < camiones[i].cantMantenimientos && camionCumple == 0; j++)
        {
            if (camiones[i].mantenimientos[j].fechaMantenimiento.month == 1 && camiones[i].mantenimientos[j].costoReparacion > monto)
            {
                camionCumple = 1;
                resultados++;
            }
        }

        if (camionCumple)
        {
            printf("\n====================================\n");
            printf("- Patente: %s\n", camiones[i].patente);
            printf("- Marca: %s\n", camiones[i].marca);
            printf("- Anio de fabricacion: %d\n", camiones[i].year);
            printf("- Kms actuales: %.2f kms\n", camiones[i].kmActuales);
            printf("====================================\n");
        }
    }

    if (resultados == 0)
    {
        printf("Ningun camion supera ese monto en enero.\n");
    }
}