/*
Se desea desarrollar un programa que permita verificar las calificaciones
de los alumnos y tendrá las siguientes funcionalidades:
1. Ver alumnos (Mostrará todos los alumnos Nombre apellido, promedio y si esta aprobado o no)
2. Buscar Alumnos (Se deberí ingresar el apellido del alumno y buscar entre todos los alumnos,
                    se deberá imprimir el nombre, apellido, notas, promedio y si esta aprobado o no)
3.Editar calificaciones(Se deberá ingresar el apellido del alumno para poder editar las calificaciones parciales)
Nota: el promedio para aprobar es 6.
*/


#include <stdio.h>
#include "funciones.h"

int main(int argc, char *argv[]) {
    char Aprobado[6];

    char alumnos[6][2][20] = {{"Juan", "Perez"},
                              {"Luis", "Yanez"},
                              {"Jose", "Ayala"},
                              {"Ana", "Perez"},
                              {"Laura", "Yanez"},
                              {"Maria", "Gomez"}};

    double notas[6][3] = {{5, 10, 7},
                          {9, 8, 4},
                          {4, 3, 10},
                          {9, 7, 5},
                          {10, 8, 9},
                          {6, 10, 8}};

    int opcion1, opcion3;

    do {
        printf("Elija una opcion:\n1.Ver Alumnos\n2.Buscar Alumno\n3.Editar Calificaciones\n>> ");
        scanf("%d", &opcion1);

        switch (opcion1) {
            case 1:
                calcularAprobado(notas, Aprobado);  
                imprimirAlumnos(alumnos, notas, Aprobado);
                break;
            case 2:
                buscarAlumnoXApellido(alumnos, notas);
                break;
            case 3:
                editarCalificaciones(alumnos, notas);
                break;
            default:
                printf("Opción no válida\n");
                break;
        }

        printf("Desea volver a elegir otra opcion?\n1.Si\n2.No\n>> ");
        scanf("%d", &opcion3);
    } while (opcion3 == 1);

    return 0;
}
