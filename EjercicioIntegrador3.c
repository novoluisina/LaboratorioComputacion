
/*Deseamos realizar un programa que gestione las notas de una clase de 10 alumnos de los
cuales sabemos el DNI y la nota. El programa debe mostrar un menú con las siguientes
opciones a resolver:
1. Cargar Alumnos
2. Buscar un alumno
3. Modificar la nota de un alumno
4. Mostrar un listado de los 10 alumnos
5. Salir
Donde, la opción 1 permite cargar los 10 alumnos ingresando para cada uno: DNI y nota.
Validar que el DNI no sea menor que 1000000 ni mayor que 99999999. Validar que la nota sea
mayor a 0 y menor o igual que 10.
La opción 2 debe pedir el DNI de un alumno y mostrar en consola DNI y nota. Si el DNI
ingresado no existe, informar la situación con un mensaje “DNI inexistente”.
La opción 3 debe pedir el DNI del alumno al cual se desea cambiar la nota y la nueva nota. Si el
DNI ingresado no existe, informar la situación con un mensaje “DNI inexistente”, si el DNI si se
encuentra modificar la nota del alumno por la ingresada.
La opción 4 debe mostrar en la consola el listado de alumnos.
SÓLO se saldrá de la aplicación si se selecciona la opción 5.*/

#include <stdio.h>
#include <stdlib.h>

struct alumno // estructura
{
    int dni;
    int nota;
};

void main()
{
    struct alumno lista_alumnos[10];
    int opcion;
    int cant_alumnos = 10;
    float dni_ingresado;
    float nota_ingresada;
    int bandera = 0;
    int validacion;
    float nueva_nota;
    int numero_alumno;

    do
    {
        printf("Ingrese una opci%cn \n", 162);
        printf("1-Cargar alumnos \n");
        printf("2-Buscar un alumno \n");
        printf("3-Modificar la nota de un alumno \n");
        printf("4-Mostrar un listado de los 10 alumnos \n");
        printf("5-Salir \n");
        scanf("%i", &opcion);

        if (opcion < 1 || opcion > 5)
        {
            printf("ERROR, vueva a intentarlo\n");
        }

        if (opcion != 5)
        {
            switch (opcion)
            {
            case 1: // carga de datos

                printf("Ingrese datos de los alumnos \n");
                for (int i = 0; i < cant_alumnos; i++)
                {
                    do
                    {
                        printf("DNI:\n");
                        scanf("%i", &lista_alumnos[i].dni);
                        if (lista_alumnos[i].dni < 1000000 || lista_alumnos[i].dni > 99999999)
                        {
                            printf("ERROR: DNI inv%clido\n", 160);
                        }
                    } while (lista_alumnos[i].dni < 1000000 || lista_alumnos[i].dni > 99999999);

                    do
                    {
                        printf("Nota:\n");
                        scanf("%i", &lista_alumnos[i].nota);
                        if (lista_alumnos[i].nota < 0 || lista_alumnos[i].nota > 10)
                        {
                            printf("ERROR: nota inv%clida\n", 160);
                        }
                    } while (lista_alumnos[i].nota < 0 || lista_alumnos[i].nota > 10);
                    printf("Nota: \n");
                }

                break;

            case 2: // búsqueda de alumno por DNI

                printf("Ingrese DNI del alumno que desea buscar\n");
                scanf("%f", &dni_ingresado);

                for (int i = 0; i < cant_alumnos; i++)
                {
                    if (dni_ingresado == lista_alumnos[i].dni)
                    {
                        bandera = 1;
                        numero_alumno = i;
                    }
                }

                if (bandera == 1)
                {
                    printf("DNI: %i \t nota: %i \n", lista_alumnos[numero_alumno].dni, lista_alumnos[numero_alumno].nota);
                }
                else
                {
                    printf("No se encontr%c un alumno con ese DNI \n", 162);
                }

                bandera = 0;

                break;

            case 3: // modificación de nota de alumno

                printf("Ingrese DNI del alumno del cual desea modificar la nota\n");
                scanf("%f", &dni_ingresado);

                for (int i = 0; i < cant_alumnos; i++)
                {
                    if (dni_ingresado == lista_alumnos[i].dni)
                    {
                        bandera = 1;
                        numero_alumno = i;
                    }
                }

                if (bandera == 1)
                {
                    printf("Ingrese la nueva nota \n");
                    scanf("%f", &nueva_nota);
                    lista_alumnos[numero_alumno].nota = nueva_nota;

                    printf("DNI: %i \t nota: %i \n", lista_alumnos[numero_alumno].dni, lista_alumnos[numero_alumno].nota);
                }
                else
                {
                    printf("No se encontr%c un alumno con ese DNI \n", 162);
                }

                break;

            case 4: // listado de alumnos

                printf(" Lista de alumnos \n");
                for (int i = 0; i < cant_alumnos; i++)
                {
                    printf("Alumno %i \t DNI: %i \t nota: %i \n", i + 1, lista_alumnos[i].dni, lista_alumnos[i].nota);
                }

                break;

            default:
                printf("Opci%cn INCORRECTA. Vuelva a intentarlo \n", 162);
                break;
            }
        }

    } while (opcion != 5);

    system("pause");
}
