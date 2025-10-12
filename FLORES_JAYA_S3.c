#include <stdio.h>

#define ESTUDIANTES 5
#define ASIGNATURAS 3

int main(void) {
    float notas[ESTUDIANTES][ASIGNATURAS];
    float promEstudiantes[ESTUDIANTES] = {0};
    float promAsignaturas[ASIGNATURAS] = {0};
    int aprobados[ASIGNATURAS] = {0};
    int reprobados[ASIGNATURAS] = {0};

    for (int i = 0; i < ESTUDIANTES; i++) {
        for (int j = 0; j < ASIGNATURAS; j++) {
            float valor;
            int ok;
            do {
                printf("Ingrese nota del Estudiante %d, Asignatura %d (0 a 10): ", i+1, j+1);
                ok = scanf("%f", &valor);
                if (ok != 1) {
                    printf("  Entrada invalida: debe ser numero.\n");
                    while (getchar() != '\n'); 
                } else if (valor < 0.0f || valor > 10.0f) {
                    printf("  Fuera de rango: debe estar entre 0 y 10.\n");
                }
            } while (ok != 1 || valor < 0.0f || valor > 10.0f);

            notas[i][j] = valor;
        }
    }

    printf("\n=== TABLA DE NOTAS (Filas=Estudiantes, Columnas=Asignaturas) ===\n");
    for (int i = 0; i < ESTUDIANTES; i++) {
        for (int j = 0; j < ASIGNATURAS; j++) {
            printf("%6.2f ", notas[i][j]);
        }
        printf("\n");
    }

    printf("\n=== POR ESTUDIANTE ===\n");
    for (int i = 0; i < ESTUDIANTES; i++) {
        float suma = 0.0f;
        float min = notas[i][0];
        float max = notas[i][0];

        for (int j = 0; j < ASIGNATURAS; j++) {
            float v = notas[i][j];
            suma += v;
            if (v < min) min = v;
            if (v > max) max = v;
        }
        promEstudiantes[i] = suma / ASIGNATURAS;
        printf("Estudiante %d -> Promedio: %.2f | Min: %.2f | Max: %.2f\n",
               i+1, promEstudiantes[i], min, max);
    }

    printf("\n=== POR ASIGNATURA ===\n");
    for (int j = 0; j < ASIGNATURAS; j++) {
        float suma = 0.0f;
        float min = notas[0][j];
        float max = notas[0][j];
        int contaAprobados = 0;

        for (int i = 0; i < ESTUDIANTES; i++) {
            float v = notas[i][j];
            suma += v;
            if (v < min) min = v;
            if (v > max) max = v;
            if (v >= 6.0f) contaAprobados++;
        }

        promAsignaturas[j] = suma / ESTUDIANTES;
        aprobados[j] = contaAprobados;
        reprobados[j] = ESTUDIANTES - contaAprobados;

        printf("Asignatura %d -> Promedio: %.2f | Min: %.2f | Max: %.2f | Aprobados: %d | Reprobados: %d\n",
               j+1, promAsignaturas[j], min, max, aprobados[j], reprobados[j]);
    }

    return 0;
}
