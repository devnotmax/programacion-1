#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 50

// Definimos las estructuras

typedef struct {
  int codigo;
  char nombre[MAX];
  char localidad[MAX];
  float altura;
} Estacion;

void cargarEstaciones(Estacion *e, int cant);
void mostrarEstaciones(Estacion *e, int cant);
void actualizarAltura(Estacion *e, int cant, int codigo);

int main() {
  int cantidad;
  printf("Ingrese la cantidad de estaciones que tiene la red: ");
  scanf("%d", &cantidad);

  Estacion *estaciones = malloc(cantidad * sizeof(Estacion));
  cargarEstaciones(estaciones, cantidad);

  int opcion;
  int codigo;
  do {
    // menu principal
    printf("\n===================== Menu principal=====================\n");
    printf("1 - Ver las estaciones\n");
    printf("2 - Actualizar altura\n");

    printf("Ingresa una opcion: ");
    scanf("%d", &opcion);
    printf("\n");

    switch (opcion) {
    case 1:
      mostrarEstaciones(estaciones, cantidad);
      break;
    case 2:
      printf("Ingresa el codigo de la estacion a modificar: ");
      scanf("%d", &codigo);
      actualizarAltura(estaciones, cantidad, codigo);
      break;
    default:
      printf("Error: Opcion invalida");
      break;
    }
  } while (opcion != 0);

  free(estaciones);
  return 0;
}

void cargarEstaciones(Estacion *e, int cant) {
  e[0] = (Estacion){101, "Estacion centro", "San Miguel de Tucuman", 450};
  e[1] = (Estacion){102, "Estacion Tafi", "Tafi Viejo", 290};
}

void mostrarEstaciones(Estacion *e, int cant) {
  printf("\n==================== Estaciones ====================\n");
  for (int i = 0; i < cant; i++) {
    printf("\n--------------------------------------\n");
    printf("Estacion  %d: \n", i + 1);
    printf("Nombre: %s\n", e[i].nombre);
    printf("Localidad: %s\n", e[i].localidad);
    printf("Altura: %2.f\n", e[i].altura);
    printf("\n--------------------------------------\n");
  }
  printf("\n====================================================\n");
}

void actualizarAltura(Estacion *e, int cant, int codigo) {
  float alturaNueva;
  printf(
      "\n============== Actualizar la altura de una estacion ==============\n");
  for (int i = 0; i < cant; i++) {
    if (e[i].codigo == codigo) {
      // Encontramos la estacion
      printf("Ingresar altura nueva: ");
      scanf("%f", &alturaNueva);
      e[i].altura = alturaNueva;
    } else {
      printf("Error: No se encontro el codigo de la estacion\n");
    }
  }
  printf("\n==================================================================="
         "=\n");
}
