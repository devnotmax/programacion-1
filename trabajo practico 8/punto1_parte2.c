#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 50

// Definimos las estructuras
typedef struct {
  int dia;    // Valor entre 1 y 365
  float temp; // temperatura en celsius
} Medicion;

typedef struct {
  int codigo;
  char nombre[MAX];
  char localidad[MAX];
  float altura;
  int cantidadMediciones;
  Medicion *mediciones;
} Estacion;

// Parte 1
void cargarEstaciones(Estacion *e, int cant);
void mostrarEstaciones(Estacion *e, int cant);
void actualizarAltura(Estacion *e, int cant, int codigo);

// Parte 2
void cargarMediciones(Estacion *e, int cant);
float temperaturaPromedio(Estacion e);
void liberarMemoria(Estacion *e, int cant);

int main() {
  int cantidad;
  printf("Ingrese la cantidad de estaciones que tiene la red: ");
  scanf("%d", &cantidad);

  Estacion *estaciones = malloc(cantidad * sizeof(Estacion));
  cargarEstaciones(estaciones, cantidad);
  cargarMediciones(estaciones, cantidad);
  int opcion;
  int codigo;
  do {
    // menu principal
    printf("\n===================== Menu principal=====================\n");
    printf("1 - Ver las estaciones\n");
    printf("2 - Actualizar altura\n");
    printf("3 - Calcular promedio de mediciones\n");

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
    case 3:
      printf("\n==================== Promedio de temperatura "
             "====================\n");
      for (int i = 0; i < cantidad; i++) {
        float promedio = temperaturaPromedio(estaciones[i]);
        printf("\n- - - - - - - - - - - - - - - -\n");
        printf("Estacion %d\n", i + 1);
        printf("Temperatura promedio: %.2f\n", promedio);
        printf("\n- - - - - - - - - - - - - - - -\n");
      }
      printf("\n====================                         "
             "====================\n");
      break;
    default:
      printf("Error: Opcion invalida");
      break;
    }
  } while (opcion != 0);

  liberarMemoria(estaciones, cantidad);
  return 0;
}

void cargarEstaciones(Estacion *e, int cant) {
  e[0] = (Estacion){101, "Estacion centro", "San Miguel de Tucuman", 450, 2};
  e[1] = (Estacion){102, "Estacion Tafi", "Tafi Viejo", 290, 3};
}

void mostrarEstaciones(Estacion *e, int cant) {
  printf("\n==================== Estaciones ====================\n");
  for (int i = 0; i < cant; i++) {
    printf("\n--------------------------------------\n");
    printf("Estacion  %d: \n", i + 1);
    printf("Nombre: %s\n", e[i].nombre);
    printf("Localidad: %s\n", e[i].localidad);
    printf("Altura: %2.f\n", e[i].altura);
    printf("#### Mediciones estacion %d ####\n", i + 1);
    for (int j = 0; j < e[i].cantidadMediciones; j++) {
      printf("\n=============================\n");
      printf("  - Medicion %d\n", j + 1);
      printf("      - Dia: %d\n", e[i].mediciones[j].dia);
      printf("      - Temperatura: %.2f\n", e[i].mediciones[j].temp);
      printf("\n=============================\n");
    }
    printf("\n--------------------------------------\n");
  }
  printf("\n====================================================\n");
}

void actualizarAltura(Estacion *e, int cant, int codigo) {
  float alturaNueva;
  int encontrada = 0;

  printf("\n============== Actualizar altura ==============\n");

  for (int i = 0; i < cant; i++) {
    if (e[i].codigo == codigo) {
      printf("Ingresar altura nueva: ");
      scanf("%f", &alturaNueva);
      e[i].altura = alturaNueva;
      encontrada = 1;
      break;
    }
  }

  if (!encontrada) {
    printf("Error: No se encontro el codigo de la estacion\n");
  }

  printf("\n=============================================\n");
}

void cargarMediciones(Estacion *e, int cant) {
  for (int i = 0; i < cant; i++) {
    e[i].mediciones = malloc(e[i].cantidadMediciones * sizeof(Medicion));
  }

  e[0].mediciones[0] = (Medicion){1, 25.5};
  e[0].mediciones[1] = (Medicion){2, 26.0};
  e[1].mediciones[0] = (Medicion){1, 22.5};
  e[1].mediciones[1] = (Medicion){2, 23.0};
  e[1].mediciones[2] = (Medicion){3, 24.0};
}

float temperaturaPromedio(Estacion e) {
  float suma = 0;

  for (int i = 0; i < e.cantidadMediciones; i++) {
    suma += e.mediciones[i].temp;
  }

  return suma / e.cantidadMediciones;
}

void liberarMemoria(Estacion *e, int cant) {
  for (int i = 0; i < cant; i++) {
    free(e[i].mediciones);
  }
  free(e);
}