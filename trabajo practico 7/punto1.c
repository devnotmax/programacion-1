#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 100
#define MAX_NOM 30

struct Fecha {
  int day;
  int month;
  int year;
};

typedef struct Director {
  char nombre[MAX_NOM];
  char apellido[MAX_NOM];
  int edad;
} Director;

typedef struct Pelicula {
  int codigo;
  char titulo[MAX];
  struct Director director;
  struct Fecha fechaEstreno;
  float precioBase;
  int genero;
} Pelicula;

// Prototipo de funciones
Pelicula cargarDatos();
void mostrarDatos(Pelicula p);
float calcularCosto(Pelicula p);
int VerificarPorGenero(Pelicula p, int generoSeleccionado);
char genero[6][20] = {"Accion", "Comedia",         "Drama",
                      "Terror", "Ciencia Ficcion", "Romance"};

int main() {
  srand(time(NULL));
  Pelicula p = cargarDatos();
  float costoFinal = calcularCosto(p);
  mostrarDatos(p);
  printf("\nCosto final de la pelicula: %.2f\n", costoFinal);
}

Pelicula cargarDatos() {
  Pelicula p;

  p.codigo = 100 + rand() % (1000 - 100 + 1);
  printf("\n========== Ingreso de pelicula ==========\n");

  printf("Ingresa el titulo de la pelicula: ");
  fflush(stdin);
  gets(p.titulo);
  printf("\n");

  printf("\n------ Datos del director ------\n");

  printf("Ingresa el nombre del director: ");
  fflush(stdin);
  gets(p.director.nombre);
  printf("\n");

  printf("Ingrese el apellido del director: ");
  fflush(stdin);
  gets(p.director.apellido);
  printf("\n");

  printf("Ingresa la edad del director: ");
  scanf("%d", &p.director.edad);
  printf("\n");

  printf("\n------ Fecha de estreno ------\n");

  int valido = 1;

  do {

    printf("Ingresa el dia: ");
    scanf("%d", &p.fechaEstreno.day);
    printf("\n");

    printf("Ingresa el mes: ");
    scanf("%d", &p.fechaEstreno.month);
    printf("\n");

    printf("Ingresa el anio: ");
    scanf("%d", &p.fechaEstreno.year);

    if (p.fechaEstreno.year > 2025) {
      printf("Error: Fecha invalida, ingresala nuevamente");
    } else {
      valido = 0;
    }

  } while (valido == 1);

  printf("\n");
  printf("Ingresa el precio base: ");
  scanf("%f", &p.precioBase);
  printf("\n");

  do {
    printf("\nIngresa el genero (1 = Accion, 2 = Comedia, 3 = Drama, 4 = "
           "Terror, 5 = Ciencia Ficcion, 6 = Romance): ");
    scanf("%d", &p.genero);

    if (p.genero < 1 || p.genero > 6) {
      printf("Genero invalido. Intente de nuevo.\n");
    }
  } while (p.genero < 1 || p.genero > 6);

  return p;
}

void mostrarDatos(Pelicula p) {
  printf("\n ======== Informacion de la pelicula ========\n");
  printf("Titulo: %s\n", p.titulo);
  printf("Director: %s %s\n", p.director.nombre, p.director.apellido);
  printf("Edad del director: %d\n", p.director.edad);
  printf("Fecha de estreno: %d/%d/%d\n", p.fechaEstreno.day,
         p.fechaEstreno.month, p.fechaEstreno.year);
  printf("Precio base: %.2f\n", p.precioBase);
  printf("Genero: %s", genero[p.genero - 1]);
  printf("\n=============================================\n");
}

float calcularCosto(Pelicula p) {
  float costoFinalPelicula;

  if (p.fechaEstreno.year == 2025 &&
      (strcmp(genero[p.genero - 1], "Accion") == 0 ||
       strcmp(genero[p.genero - 1], "Ciencia ficcion") == 0)) {
    costoFinalPelicula = p.precioBase * 1.50f;
  } else if (p.fechaEstreno.year == 2024 &&
             (strcmp(genero[p.genero - 1], "Romance") == 0 ||
              strcmp(genero[p.genero - 1], "Terror") == 0)) {
    costoFinalPelicula = p.precioBase * 1.25f;
  } else {
    costoFinalPelicula = p.precioBase;
  }

  return costoFinalPelicula;
}

int VerificarPorGenero(Pelicula p, int generoSeleccionado) {
  if (strcmp(genero[p.genero - 1], genero[generoSeleccionado - 1]) == 0) {
    return 1;
  } else {
    return 0;
  }
}