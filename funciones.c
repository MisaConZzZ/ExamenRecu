#include "funciones.h"
#include <stdio.h>
#include <string.h>

void calcularAprobado(double notas[][3], char Aprobado[]) {
    for (int i = 0; i < 6; i++) {
        double promedio = (notas[i][0] + notas[i][1] + notas[i][2]) / 3.0;
        if (promedio >= 6.0) {  
            Aprobado[i] = 'S';
        } else {
            Aprobado[i] = 'N';
        }
    }
}

void imprimirAlumnos(char alumnos[][2][20], double notas[][3], char Aprobado[]) {
    printf("Nombres \tApellido \t Promedio\t Aprobado\n");

    for (int i = 0; i < 6; i++) {
        double promedio = (notas[i][0] + notas[i][1] + notas[i][2]) / 3.0;
        printf("%s \t \t%s \t \t %.2lf \t \t %c\n", alumnos[i][0], alumnos[i][1], promedio, Aprobado[i]);
    }
}

void buscarAlumnoXApellido(char alumnos[][2][20], double notas[][3]) {
    char Apellido[20];
    int NoExiste = 1;

    printf("Ingrese el Apellido del Alumno: ");
    scanf("%s", Apellido);

    for (int i = 0; i < 6; i++) {
        if (strcmp(alumnos[i][1], Apellido) == 0) {
            double promedio = (notas[i][0] + notas[i][1] + notas[i][2]) / 3.0;
            char Aprobado;
            if (promedio >= 6.0) {  
                Aprobado = 'S';
            } else {
                Aprobado = 'N';
            }
            printf("%s \t %s \t %.2lf \t %c\n", alumnos[i][0], alumnos[i][1], promedio, Aprobado);
            NoExiste = 0;
        }
    }

    if (NoExiste) {
        printf("No existe el Estudiante\n");
    }
}

void editarCalificaciones(char alumnos[][2][20], double notas[][3]) {
    char Apellido[20];
    char Nombre[20];
    double NotaNueva;
    int NoExiste = 1;
    int indices[6];
    int count = 0;

    printf("Ingrese el Apellido del Alumno: ");
    scanf("%s", Apellido);

    for (int i = 0; i < 6; i++) {
        if (strcmp(alumnos[i][1], Apellido) == 0) {
            indices[count++] = i;
        }
    }

    if (count > 1) {
        printf("Se encontraron varios alumnos con el mismo apellido\n");
        printf("Ingrese el nombre del Alumno: ");
        scanf("%s", Nombre);
        for (int i = 0; i < count; i++) {
            if (strcmp(alumnos[indices[i]][0], Nombre) == 0) {
                printf("Ingrese la primera nota: ");
                scanf("%lf", &NotaNueva);
                notas[indices[i]][0] = NotaNueva;
                printf("Ingrese la segunda nota: ");
                scanf("%lf", &NotaNueva);
                notas[indices[i]][1] = NotaNueva;
                printf("Ingrese la tercera nota: ");
                scanf("%lf", &NotaNueva);
                notas[indices[i]][2] = NotaNueva;
                NoExiste = 0;
                break;
            }
        }
    } else if (count == 1) {
        printf("Ingrese la primera nota: ");
        scanf("%lf", &NotaNueva);
        notas[indices[0]][0] = NotaNueva;
        printf("Ingrese la segunda nota: ");
        scanf("%lf", &NotaNueva);
        notas[indices[0]][1] = NotaNueva;
        printf("Ingrese la tercera nota: ");
        scanf("%lf", &NotaNueva);
        notas[indices[0]][2] = NotaNueva;
        NoExiste = 0;
    }

    if (NoExiste) {
        printf("No existe el Alumno\n");
    }
}
