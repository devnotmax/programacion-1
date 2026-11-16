
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 50

typedef struct {
  char usuario[MAX];
  char password[MAX];
} Cuenta;

typedef struct {
  int day;
  int month;
  int year;
} Fecha;

typedef struct {
  int codigoReserva;
  Fecha checkIn;
  Fecha checkOut;
  int tipoHabitacion;
  float montoTotal;
} Reserva;

typedef struct {
  char apellido[MAX];
  char nombre[MAX];
  int dni;
  Fecha fechaNacimiento;
  char telefono[MAX];
  Cuenta datos;
  Reserva reserva;
  int reservaVigente;
} Huesped;

// Modulos
void listarHuespedes(Huesped arreglo[], int cantHuespedes);
Huesped agregarReserva(Huesped h);
Huesped cancelarReserva(Huesped h);
void verReserva(Huesped h);
Huesped cambiarContrasenia(Huesped h);
void mostrarInformacion(Huesped h);
int fechaValida(Fecha date);
int correspondeciaDeFechas(Fecha checkIn, Fecha checkOut);

int main() {
  srand(time(NULL));
  Huesped huespedes[3] = {{"Perez",
                           "Laura",
                           12345678,
                           {12, 3, 1985},
                           "1122334455",
                           {"lauraP", "clave123"},
                           {0},
                           0},
                          {"Ramirez",
                           "Carlos",
                           87654321,
                           {7, 7, 1990},
                           "1198765432",
                           {"carlosR", "pass456"},
                           {0},
                           0},
                          {"Martinez",
                           "Sofia",
                           45678912,
                           {20, 12, 1975},
                           "1100112233",
                           {"sofiaM", "s3gura"},
                           {0},
                           0}};

  int huespedElegido;
  int opcion;

  do {
    // Listamos los huespedes
    listarHuespedes(huespedes, 3);

    printf("Ingrese el huesped con el que desea interactuar (0 para salir): ");
    scanf("%d", &huespedElegido);

    // Mostrar menu principal
    do {
      printf("\n==================== Menu principal ====================\n");
      printf("Hola %s! que deseas hacer?\n",
             huespedes[huespedElegido - 1].nombre);
      printf("1 - Agregar reserva\n");
      printf("2 - Cancelar reserva\n");
      printf("3 - Ver reserva\n");
      printf("4 - Cambiar contrasenia\n");
      printf("5 - Ver informacion personal\n");
      printf("6 - Volver al menu principal\n");
      printf("\n========================================================\n");
      printf("\n");
      printf("Ingresa una opcion: ");
      scanf("%d", &opcion);

      printf("\n");

      switch (opcion) {
      case 1:
        // Agregar reserva
        if (huespedes[huespedElegido - 1].reservaVigente == 1) {
          printf("\nEl huesped ya tiene una reserva activa.\n");
        } else {
          huespedes[huespedElegido - 1] =
              agregarReserva(huespedes[huespedElegido - 1]);
          printf("\nReserva agregada con exito!\n");
        }
        break;

      case 2:
        // Cancelar reserva
        if (huespedes[huespedElegido - 1].reservaVigente == 0) {
          printf("\nEl huesped no tiene una reserva vigente.\n");
        } else {
          huespedes[huespedElegido - 1] =
              cancelarReserva(huespedes[huespedElegido - 1]);
          printf("\nReserva cancelada con exito!");
        }
        break;

      case 3:
        // Ver reserva
        verReserva(huespedes[huespedElegido - 1]);
        break;

      case 4:
        // Cambiar contraseña
        huespedes[huespedElegido - 1] =
            cambiarContrasenia(huespedes[huespedElegido - 1]);
        printf("\nContraseña cambiada con exito!\n");
        break;

      case 5:
        // Ver informacion personal
        mostrarInformacion(huespedes[huespedElegido - 1]);
        break;

      case 6:
        // Volver al menu principal
        printf("\nVolviendo a la lista de huespedes...\n");
        break;

      default:
        printf("Error: Opcion incorrecta\n");
        break;
      }

    } while (opcion != 6);

  } while (huespedElegido != 0);

  return 0;
}

void listarHuespedes(Huesped arreglo[], int cantHuespedes) {
  printf("\n==================== Lista de huespedes ====================\n");

  for (int i = 0; i < cantHuespedes; i++) {
    printf("%d - %s %s %d\n", i + 1, arreglo[i].apellido, arreglo[i].nombre,
           arreglo[i].dni);
  }

  printf("\n============================================================\n");
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

int correspondeciaDeFechas(Fecha checkIn, Fecha checkOut) {
  if (checkIn.year > checkOut.year) {
    return 0;
  }

  if (checkIn.month > checkOut.month && checkIn.year < checkOut.year) {
    return 0;
  }

  if(checkIn.day > checkOut.day && checkIn.month < checkOut.month){
    return 0;
  }

  return 1;
}

Huesped agregarReserva(Huesped h) {
  printf("\n========== Agregando una reserva... ==========\n");
  // Generar el codigo de la reserva
  h.reserva.codigoReserva = 100000 + rand() % 900000;

  // Generar fecha del check-in
  do {
    printf("Ingresar la fecha de check-in: ");
    scanf("%d %d %d", &h.reserva.checkIn.day, &h.reserva.checkIn.month,
          &h.reserva.checkIn.year);
  } while (fechaValida(h.reserva.checkIn) == 0);

  do {
    printf("Ingresar la fecha del check-out: ");
    scanf("%d %d %d", &h.reserva.checkOut.day, &h.reserva.checkOut.month,
          &h.reserva.checkOut.year);

  } while (fechaValida(h.reserva.checkOut) == 0 &&
           (h.reserva.checkOut.year >= h.reserva.checkIn.year) &&
           (h.reserva.checkIn.month <= h.reserva.checkOut.month));

  return h;
}