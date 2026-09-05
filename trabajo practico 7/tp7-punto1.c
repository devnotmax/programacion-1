/*
------------------------------------------------------------
TP6 - Punto 1: Estructuras en C

Este programa introduce el uso de estructuras (struct) para
organizar información compleja en C. A partir del registro
de una película, se busca trabajar con estructuras anidadas
(Fecha, Persona, Pelicula) y comprender cómo acceder a sus
miembros mediante el operador punto (.)

El objetivo de esta base es servir como guía inicial para
completar las funciones del programa. Los estudiantes deberán:
 - Implementar la carga completa de los datos de una película.
 - Mostrar la información registrada de forma legible.
 - Calcular el costo final de la película según ciertas condiciones.
 - Verificar si el género ingresado coincide con el de la película.

El código se entrega parcialmente comentado para orientar
la comprensión y favorecer la práctica autónoma.
------------------------------------------------------------
*/

#include <stdio.h>
#include <string.h>

// ------------------------------------
// Definición de estructuras
// ------------------------------------

// Estructura para guardar una fecha (día, mes, año)
typedef struct
{
    // completar...
} Fecha;

// Estructura para guardar los datos del director
typedef struct
{
    // completar...
} Persona;

// Estructura principal: Película
typedef struct
{
    // completar...
} Pelicula;

// ------------------------------------
// Arreglo de géneros disponibles
// ------------------------------------
char genero[6][20] = {
    "Accion",
    "Comedia",
    "Drama",
    "Terror",
    "Ciencia ficcion",
    "Romance"};

// ------------------------------------
// Prototipos de funciones
// ------------------------------------
Pelicula cargarDatos();
void mostrarDatos(Pelicula p);
float calcularCosto(Pelicula p);
int verificarPorGenero(Pelicula p, int generoSeleccionado);

int main()
{
    // 1️- Declarar variable de tipo Pelicula

    // 2- Cargar datos
    // Completar dentro de la función "cargarDatos"

    // 3- Mostrar datos
    // Completar dentro de la función "mostrarDatos"

    // 4- Calcular costo final

    // 5- Verificar género

    return 0;
}

// ------------------------------------
// Función para cargar datos
// ------------------------------------
Pelicula cargarDatos()
{
    Pelicula p;

    // ⚙️ Completar la carga de los datos paso a paso:
    // código, título, director, fecha, precio base y género.
    // Recordar: para acceder a los miembros de una estructura, se usa el operador punto (.)

    printf("Ingrese el código de la película: ");
    // scanf("%d", &p.codigo); Comento esta linea porque el struct está comentado

    // Continuar...

    return p;
}

// ------------------------------------
// Función para mostrar los datos
// ------------------------------------
void mostrarDatos(Pelicula p)
{
    printf("\n--- DATOS DE LA PELÍCULA ---\n");
    // printf("Código: %d\n", p.codigo); Comento esta linea porque el struct está comentado

    // Continuar...
}

// ------------------------------------
// Función para calcular el costo final
// ------------------------------------
float calcularCosto(Pelicula p)
{
    // Completar...
}

// ------------------------------------
// Función para verificar coincidencia de género
// ------------------------------------
int verificarPorGenero(Pelicula p, int generoSeleccionado)
{
    // Completar...
}