
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define CUPO_MAXIMO 15

typedef struct Fecha {
  int day;
  int month;
  int year;
} Fecha;

typedef struct Persona {
  char nombrePersona[MAX];
  char apellidoPersona[MAX];
  int dni;
} Persona;

typedef struct Taller {
  char nombreTaller[MAX];
  Persona profesor;
  Fecha inicializacionCurso;
  Fecha finalizacionCurso;
  float costoInscripcion;
  int cantidadAlumnos;
  int alumnosInscriptos[CUPO_MAXIMO];
} Taller;

// Declaracion de modulos
Taller cargarTaller();
void mostrarTaller(Taller p);
void actualizarCosto(Taller *p, int porcentaje);
int fechaValida(Fecha date);

int main() {
  srand(time(NULL));

  Taller p;
  p = cargarTaller();

  mostrarTaller(p);

  int opcionValida = 0;
  char opcion;

  do {
    printf("\nQuiere actualizar el costo de inscripcion? S/N: ");
    scanf(" %c", &opcion);
    printf("\n");

    opcion = tolower(opcion);

    if (opcion != 's' && opcion != 'n') {
      printf("Error: Opcion invalida.\n");
    } else {
      opcionValida = 1;
    }

  } while (opcionValida == 0);

  if (opcion == 's') {
    int porcentaje;

    printf("Porcentaje de incremento: ");
    scanf("%d", &porcentaje);

    actualizarCosto(&p, porcentaje);

    printf("\nCosto actualizado correctamente.\n");
    mostrarTaller(p);
  }

  return 0;
}

Taller cargarTaller() {
  Taller p;

  printf("\n================ CARGAR TALLER ================\n");

  printf("Ingresar el nombre del taller: ");
  fflush(stdin);
  gets(p.nombreTaller);
  printf("\n");

  printf("-------- Datos del profesor/a ---------\n");

  printf("Ingresar el nombre del profesor/a: ");
  fflush(stdin);
  gets(p.profesor.nombrePersona);
  printf("\n");

  printf("Ingresar el apellido del profesor/a: ");
  fflush(stdin);
  gets(p.profesor.apellidoPersona);
  printf("\n");

  printf("Ingresar el DNI del profesor/a: ");
  scanf(" %d", &p.profesor.dni);
  printf("\n");

  printf("-------- Fechas del taller ---------\n");

  do {
    printf("Ingresar fecha de inicio (dia mes anio): ");
    scanf(" %d %d %d", &p.inicializacionCurso.day, &p.inicializacionCurso.month,
          &p.inicializacionCurso.year);
    printf("\n");

    if (fechaValida(p.inicializacionCurso) == 0) {
      printf("Fecha invalida. Intente nuevamente.\n");
    }

  } while (fechaValida(p.inicializacionCurso) == 0);

  do {
    printf("Ingresar fecha de finalizacion (dia mes anio): ");
    scanf(" %d %d %d", &p.finalizacionCurso.day, &p.finalizacionCurso.month,
          &p.finalizacionCurso.year);
    printf("\n");

    if (fechaValida(p.finalizacionCurso) == 0) {
      printf("Fecha invalida. Intente nuevamente.\n");
    } else if (p.finalizacionCurso.year < p.inicializacionCurso.year ||
               (p.finalizacionCurso.year == p.inicializacionCurso.year &&
                p.finalizacionCurso.month < p.inicializacionCurso.month) ||
               (p.finalizacionCurso.year == p.inicializacionCurso.year &&
                p.finalizacionCurso.month == p.inicializacionCurso.month &&
                p.finalizacionCurso.day < p.inicializacionCurso.day)) {
      printf(
          "La fecha de finalizacion no puede ser anterior a la de inicio.\n");
    }

  } while (fechaValida(p.finalizacionCurso) == 0 ||
           p.finalizacionCurso.year < p.inicializacionCurso.year ||
           (p.finalizacionCurso.year == p.inicializacionCurso.year &&
            p.finalizacionCurso.month < p.inicializacionCurso.month) ||
           (p.finalizacionCurso.year == p.inicializacionCurso.year &&
            p.finalizacionCurso.month == p.inicializacionCurso.month &&
            p.finalizacionCurso.day < p.inicializacionCurso.day));

  printf("Ingresar el costo de inscripcion: ");
  scanf(" %f", &p.costoInscripcion);
  printf("\n");

  printf("-------- Alumnos inscriptos ---------\n");

  do {
    printf("Ingrese la cantidad de alumnos inscriptos (maximo 15): ");
    scanf("%d", &p.cantidadAlumnos);
  } while (p.cantidadAlumnos < 0 || p.cantidadAlumnos > CUPO_MAXIMO);

  printf("\n");

  for (int i = 0; i < p.cantidadAlumnos; i++) {
    p.alumnosInscriptos[i] = 40000000 + rand() % 20000000;

    printf("DNI del alumno %d: %d\n", i + 1, p.alumnosInscriptos[i]);
  }

  return p;
}

void mostrarTaller(Taller p) {
  printf("\n================ DATOS DEL TALLER ================\n");

  printf("Nombre del taller: %s\n", p.nombreTaller);

  printf("\n-------- Datos del profesor/a ---------\n");
  printf("Apellido: %s\n", p.profesor.apellidoPersona);
  printf("Nombre: %s\n", p.profesor.nombrePersona);
  printf("DNI: %d\n", p.profesor.dni);

  printf("\n-------- Fechas del taller ---------\n");

  printf("Fecha de inicio: %02d/%02d/%d\n", p.inicializacionCurso.day,
         p.inicializacionCurso.month, p.inicializacionCurso.year);

  printf("Fecha de finalizacion: %02d/%02d/%d\n", p.finalizacionCurso.day,
         p.finalizacionCurso.month, p.finalizacionCurso.year);

  printf("\nCosto de inscripcion: $%.2f\n", p.costoInscripcion);

  printf("\n-------- Alumnos inscriptos ---------\n");
  printf("Cantidad de alumnos: %d\n", p.cantidadAlumnos);

  for (int i = 0; i < p.cantidadAlumnos; i++) {
    printf("DNI del alumno %d: %d\n", i + 1, p.alumnosInscriptos[i]);
  }

  printf("===================================================\n");
}

void actualizarCosto(Taller *p, int porcentaje) {
  p->costoInscripcion = p->costoInscripcion * (1 + (float)porcentaje / 100);
}

int fechaValida(Fecha date) {
  int diasMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if (date.month < 1 || date.month > 12) {
    return 0;
  }

  if (date.day < 1 || date.day > diasMes[date.month - 1]) {
    return 0;
  }

  if (date.year != 2026) {
    return 0;
  }

  return 1;
}
