#include <stdio.h>

int main()
{
    int day;
    int month;
    int year;
    int fechaValida = 0;
    int esBisiesto = 0;
    int mesValido = 0;
    int anioValido = 0;
    int diaValido = 0;

    printf("-------------------------- \n");

    printf("Ingresar el dia: ");
    scanf("%d", &day);
    printf("\n");

    printf("Ingresar el mes: ");
    scanf("%d", &month);
    printf("\n");

    printf("Ingresar el anio: ");
    scanf("%d", &year);
    printf("\n");

    printf("-------------------------- \n");

    // verificar si es bisiesto - Un año es bisiesto si es divisible por 400
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
    {
        esBisiesto = 1;
    }
    else
    {
        esBisiesto = 0;
    }

    // validar mes
    if (month >= 1 && month <= 12)
    {
        mesValido = 1;
    }
    else
    {
        printf("Error: Mes invalido \n");
    }

    // validar anio
    if (year >= 1)
    {
        anioValido = 1;
    }
    else
    {
        printf("Error: anio invalido \n");
    }

    // validar dia
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (day >= 1 && day <= 31)
        {
            diaValido = 1;
        }
        else
        {
            printf("Error: El mes %d tiene 31 dias \n", month);
        }
        break;

    case 2:
        if (esBisiesto == 1)
        {
            if (day >= 1 && day <= 29)
            {
                diaValido = 1;
            }
            else
            {
                printf("Error: El mes %d tiene 29 dias y el anio %d es bisiesto \n", year);
            }
        }
        else
        {
            if (day >= 1 && day <= 28)
            {
                diaValido = 1;
            }
            else
            {
                printf("Error: El mes %d tiene solo 28 dias porque el anio %d no es bisiesto \n", month, year);
            }
        }
        break;

    case 4:
    case 6:
    case 9:
    case 11:
        if (day >= 1 && day <= 30)
        {
            diaValido = 1;
        }
        else
        {
            printf("Error: El mes %d solo tiene 30 dias. \n", month);
        }

    default:
        break;
    }

    if (diaValido == 1 && mesValido == 1 && anioValido == 1)
    {
        fechaValida = 1;
    }
    else
    {
        fechaValida = 0;
    }

    if (fechaValida == 1)
    {
        printf("Resultado: Fecha valida \n");
        printf("Fecha: %d/%.2d/%d\n", day, month, year);

        // año bisiesto
        if (esBisiesto == 1)
        {
            printf("Anio bisiesto: SI\n");
        }
        else
        {
            printf("Anio bisiesto: NO\n");
        }

        // evaluar trimestre
        switch (month)
        {
        case 1:
        case 2:
        case 3:
            printf("Trimestre: T1\n");
            /* code */
            break;
        case 4:
        case 5:
        case 6:
            printf("Trimestre: T2\n");
            break;
        case 7:
        case 8:
        case 9:
            printf("Trimestre: T3\n");
            break;
        case 10:
        case 11:
        case 12:
            printf("Trimestre: T4\n");
            break;
        default:
            break;
        }

        // evaluar invierno
        if (month == 7 || month == 8)
        {
            printf("Invierno: SI\n");
        }
        else if (month == 6 && day >= 21)
        {
            printf("Invierno: SI\n");
        }
        else if (month == 9 && day <= 20)
        {
            printf("Invierno: SI\n");
        }
        else
        {
            printf("Invierno: NO\n");
        }
    }
    else
    {
        printf("Resultado: Fecha invalida \n");
    }

    return 0;
}