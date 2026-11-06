#include <stdio.h>
#include <ctype.h>
#include <string.h> // Necesario para strlen y strcmp

#define MAX_LETRAS 21 // Lo subimos a 21 para que entren 20 letras + el '\0'
#define INTENTOS 3

// Declaración de funciones
void ingresarPalabra(char palabra[]);
void inicializarProgreso(char progreso[], int longitud);
void mostrarProgreso(char progreso[]);
int revelarLetra(char palabra[], char progreso[], char letra);
int adivinoPalabra(char palabra[], char progreso[]);
int yaIngresada(char usadas[], int cantidad, char letra);

int main()
{
    int intentosRestantes = INTENTOS;
    char palabra[MAX_LETRAS];
    char progreso[MAX_LETRAS];
    char usadas[MAX_LETRAS] = "";
    int gano = 0; // Bandera para saber si el jugador 2 adivinó (1) o no (0)

    // 1. Ingresa la palabra el Jugador 1
    ingresarPalabra(palabra);

    // 2. Calculamos la longitud y preparamos los guiones
    int longitud = strlen(palabra);
    inicializarProgreso(progreso, longitud);

    printf("\n--- TURNO DEL JUGADOR 2 ---\n");

    // 3. Bucle principal del juego
    // Repetimos MIENTRAS queden intentos Y el jugador no haya ganado aún
    do
    {
        printf("\nPalabra: ");
        mostrarProgreso(progreso);
        printf("Intentos disponibles: %d\n", intentosRestantes);

        char letra;
        printf("Ingresa una letra: ");
        scanf(" %c", &letra); // El espacio antes del %c es clave para limpiar saltos de línea
        int usadas = strlen(usadas);

        int letrasReveladas = revelarLetra(palabra, progreso, letra);

        if (letrasReveladas == 0)
        {
            printf("La letra no esta en la palabra.\n");
            intentosRestantes--; // Descontamos un intento porque se equivocó
        }
        else
        {
            printf("¡Bien! Revelaste %d letra/s.\n", letrasReveladas);
        }

        // Revisamos si con esta última letra completó la palabra
        gano = adivinoPalabra(palabra, progreso);

    } while (intentosRestantes > 0 && gano == 0);

    // 4. Resultados finales al salir del bucle
    printf("\n============================\n");
    if (gano == 1)
    {
        printf("¡Felicidades! Adivinaste la palabra: %s\n", palabra);
    }
    else
    {
        printf("¡Derrota! Te quedaste sin intentos.\n");
        printf("La palabra correcta era: %s\n", palabra);
    }

    return 0;
}

void ingresarPalabra(char palabra[])
{
    int valido;

    do
    {
        valido = 1;

        printf("Jugador 1 - Ingresa la palabra a adivinar: ");
        scanf("%s", palabra);

        int longitud = strlen(palabra);

        if (longitud < 3 || longitud > 20)
        {
            printf("Error: La palabra debe tener entre 3 y 20 caracteres.\n\n");
            valido = 0;
        }
        else
        {
            // Validar carácter por carácter
            for (int i = 0; i < longitud && valido == 1; i++)
            {
                // islower verifica que sea minúscula (y al mismo tiempo rechaza números y mayúsculas)
                if (!islower(palabra[i]) || palabra[i] == 'ñ' || palabra[i] == 'Ñ')
                {
                    printf("Error: Solo se permiten minusculas, sin tildes ni eñes.\n\n");
                    valido = 0;
                }
            }
        }

    } while (valido == 0);
}

void inicializarProgreso(char progreso[], int longitud)
{
    for (int i = 0; i < longitud; i++)
    {
        progreso[i] = '_'; // El enunciado pide guión bajo
    }
    // IMPORTANTÍSIMO: Agregar el terminador al final para que strcmp funcione
    progreso[longitud] = '\0';
}

void mostrarProgreso(char progreso[])
{
    for (int i = 0; progreso[i] != '\0'; i++)
    {
        printf("%c ", progreso[i]);
    }
    printf("\n"); // Salto de línea por prolijidad
}

int revelarLetra(char palabra[], char progreso[], char letra)
{
    int letrasReveladas = 0;

    // Condición corregida: avanzar hasta encontrar el '\0'
    for (int i = 0; palabra[i] != '\0'; i++)
    {
        if (letra == palabra[i])
        {
            // Si la letra ya había sido revelada antes, no la contamos de nuevo
            if (progreso[i] == '_')
            {
                progreso[i] = palabra[i];
                letrasReveladas++;
            }
        }
    }

    return letrasReveladas;
}

int adivinoPalabra(char palabra[], char progreso[])
{
    // strcmp devuelve 0 si las cadenas son exactamente iguales
    if (strcmp(palabra, progreso) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}