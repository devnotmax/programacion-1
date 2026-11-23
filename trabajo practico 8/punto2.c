// Cine la butaca
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
  int numeroSala;
  int capacidad;
  int tipoPantalla;
} Sala;

typedef struct {
  char titulo[30];
  int genero;
  int cantidadFunciones;
  int *espectadores;
  Sala sala;
} Pelicula;

// Declaración de funciones
void cargarPeliculas(Pelicula *pelis, int cant);
void cargarEspectadores(Pelicula *pelis, int cant);
void mostrarPeliculas(Pelicula *pelis, int cant);
void listarPorGenero(Pelicula *pelis, int cant, char genero[]);
float calcularPromedioEspectadores(Pelicula p);
void mostrarSalasGrandes(Pelicula *pelis, int cant);
int contarPeliculasIMAX(Pelicula *pelis, int cant);
void mostrarPeliculasSalaLlena(Pelicula *pelis, int cant);
void liberarMemoria(Pelicula *pelis, int cant);

char generos[][20] = {"Accion",          "Comedia", "Drama",    "Terror",
                      "Ciencia ficcion", "Romance", "Aventura", "Animacion"};

char tipoSalas[][10] = {"2D", "3D", "IMAX"};

int main() {
  srand(time(NULL));
  int cant;
  printf("Ingrese la cantidad de peliculas que desea cargar: ");
  scanf("%d", &cant);
  Pelicula *peliculas;
  peliculas = malloc(cant * sizeof(Pelicula));
  cargarPeliculas(peliculas, cant);

  // Menu principal
  int opcion;

  do {
    printf("\n= = = = = = = = = = CINE LA BUTACA = = = = = = = = = =\n");
    printf("1 - Mostrar peliculas\n");
    printf("2 - Listar peliculas por genero\n");
    printf("3 - Mostrar promedio de espectadores por pelicula\n");
    printf("4 - Mostrar salas grandes (+ de 200 espectadores)\n");
    printf("5 - Contar peliculas IMAX\n");
    printf("6 - Mostrar peliculas con sala llena\n");
    printf("0 - Salir\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);

    switch (opcion) {
    case 1:
      mostrarPeliculas(peliculas, cant);
      break;
    case 2: {
      int opcionGenero;
      printf("\nSeleccione un genero:\n");
      for (int i = 0; i < 8; i++) {
        printf("%d - %s\n", i + 1, generos[i]);
      }
      scanf("%d", &opcionGenero);
      listarPorGenero(peliculas, cant, generos[opcionGenero - 1]);
    } break;

    case 3:
      printf(
          "\n================= Promedio de espectadores =================\n");
      for (int i = 0; i < cant; i++) {
        printf("Pelicula: %s\n", peliculas[i].titulo);
        printf("Promedio de espectadores: %.2f\n",
               calcularPromedioEspectadores(peliculas[i]));
        printf("\n--------------------------------------\n");
      }
      break;

    case 4:
      printf("\n================= Mostrar salas grandes =================\n");
      mostrarSalasGrandes(peliculas, cant);
      printf("\n--------------------------------------\n");
      break;

    case 5:
      printf("\n================= Contar peliculas IMAX =================\n");
      int salasEncontradas = contarPeliculasIMAX(peliculas, cant);
      printf("Peliculas con IMAX encontradas: %d", salasEncontradas);
      printf("\n--------------------------------------\n");
      break;

    case 6:
      printf("\n================= Contar salas llenas =================\n");
      mostrarPeliculasSalaLlena(peliculas, cant);
      printf("\n--------------------------------------\n");
      break;
    }
  } while (opcion != 0);

  liberarMemoria(peliculas, cant);

  return 0;
}

void cargarPeliculas(Pelicula *pelis, int cant) {
  switch (cant) {
  case 8:
    pelis[7] = (Pelicula){"Gladiador", 4, 2, NULL, {108, 250, 3}};
  case 7:
    pelis[6] = (Pelicula){"Coco", 3, 3, NULL, {107, 180, 2}};
  case 6:
    pelis[5] = (Pelicula){"Batman", 1, 2, NULL, {106, 220, 1}};
  case 5:
    pelis[4] = (Pelicula){"El Padrino", 4, 2, NULL, {105, 150, 1}};
  case 4:
    pelis[3] = (Pelicula){"Interestelar", 2, 3, NULL, {104, 300, 3}};
  case 3:
    pelis[2] = (Pelicula){"Shrek", 3, 2, NULL, {103, 180, 2}};
  case 2:
    pelis[1] = (Pelicula){"Avatar", 2, 4, NULL, {102, 250, 3}};
  case 1:
    pelis[0] = (Pelicula){"Titanic", 1, 3, NULL, {101, 200, 1}};
    break;
  }

  for (int i = 0; i < cant; i++) {
    pelis[i].espectadores = malloc(pelis[i].cantidadFunciones * sizeof(int));
  }
}

void cargarEspectadores(Pelicula *pelis, int cant) {
  for (int i = 0; i < cant; i++) {
    for (int j = 0; j < pelis[i].cantidadFunciones; j++) {
      pelis[i].espectadores[j] = rand() % (pelis[i].sala.capacidad + 1);
    }
  }
}

void mostrarPeliculas(Pelicula *pelis, int cant) {
  printf("\n========================= Peliculas =========================\n");
  for (int i = 0; i < cant; i++) {
    printf("\n========== Pelicula %d ==========\n", i + 1);
    printf("Titulo: %s\n", pelis[i].titulo);
    printf("Genero: %s\n", generos[pelis[i].genero - 1]);
    printf("Cantidad de funciones: %d\n", pelis[i].cantidadFunciones);
    printf("    ########## Sala %d ##########\n", pelis[i].sala.numeroSala);
    printf("    Capacidad total de espectadores: %d\n",
           pelis[i].sala.capacidad);
    switch (pelis[i].sala.tipoPantalla) {
    case 1:
      printf("  Tipo de sala: 2D\n");
      break;

    case 2:
      printf("  Tipo de sala: 3D\n");
      break;

    case 3:
      printf("  Tipo de sala: IMAX\n");
      break;

    default:
      printf("  Error: Tipo de sala invalido\n");
      break;
    }
    for (int j = 0; j < pelis[i].cantidadFunciones; j++) {
      printf("\n------------- Funcion %d -------------\n", j + 1);
      printf("Espectadores: %d/%d\n", pelis[i].espectadores[j],
             pelis[i].sala.capacidad);
    }
    printf("\n=================================\n");
  }

  printf("\n===============================================================\n");
}

void listarPorGenero(Pelicula *pelis, int cant, char genero[]) {
  int encontradas = 0;

  printf(
      "\n======================= Listar por genero =======================\n");
  printf("Genero seleccionado: %s\n", genero);
  printf("########## Peliculas encontradas ##########");

  for (int i = 0; i < cant; i++) {
    if (strcmp(generos[pelis[i].genero - 1], genero) == 0) {
      encontradas++;

      printf("\n========== Pelicula %d ==========\n", i + 1);
      printf("Titulo: %s\n", pelis[i].titulo);
      printf("Genero: %s\n", genero);
      printf("Cantidad de funciones: %d\n", pelis[i].cantidadFunciones);
      printf("\n=================================\n");
    }
  }

  if (encontradas == 0) {
    printf("\nNo se encontro ninguna pelicula de ese genero :(");
  }

  printf(
      "\n=================================================================\n");
}

float calcularPromedioEspectadores(Pelicula p) {
  int suma = 0;
  for (int i = 0; i < p.cantidadFunciones; i++) {
    suma += p.espectadores[i];
  }

  return (float)suma / p.cantidadFunciones;
}

void mostrarSalasGrandes(Pelicula *pelis, int cant) {
  int encontradas = 0;
  printf("\n============ Salas grandes (+200) ============\n");
  for (int i = 0; i < cant; i++) {
    if (pelis[i].sala.capacidad > 200) {
      encontradas++;
      printf("\n############ Sala %d ############\n", pelis[i].sala.numeroSala);
      printf("\nPelicula que se proyecta: %s\n", pelis[i].titulo);
      printf("\nGenero: %s\n", generos[pelis[i].genero - 1]);
      printf("\nCapacidad: %d\n", pelis[i].sala.capacidad);
      printf("\n#################################\n");
    }
  }
  if (encontradas == 0) {
    printf("\nNo se encontraron salas grandes.\n");
  }
}

int contarPeliculasIMAX(Pelicula *pelis, int cant) {
  int encontradas = 0;
  for (int i = 0; i < cant; i++) {
    if (strcmp(tipoSalas[pelis[i].sala.tipoPantalla - 1], "IMAX") == 0) {
      encontradas++;
    }
  }

  return encontradas;
}

void mostrarPeliculasSalaLlena(Pelicula *pelis, int cant) {
  for (int i = 0; i < cant; i++) {
    int suma = 0;
    for (int j = 0; j < pelis[i].cantidadFunciones; j++) {
      if (pelis[i].sala.capacidad == pelis[i].espectadores[j]) {
        // Significa que la sala está llena
        printf("\n============ Sala llena encontrada ============\n");
        printf("\nPelicula: %s\n", pelis[i].titulo);
        printf("\nFuncion: %d\n", j + 1);
        printf("\nEspectadores: %d/%d\n", pelis[i].espectadores[j],
               pelis[i].sala.capacidad);
        printf("\n----------------------------------------------\n");
      }
    }
  }
}

void liberarMemoria(Pelicula *pelis, int cant) {
  for (int i = 0; i < cant; i++) {
    free(pelis[i].espectadores);
  }

  free(pelis);
}