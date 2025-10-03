#include <stdio.h>

int main()
{
    // ingrese cuantos estudiantes hay, ingrese las notas y saque el promedio
    int numEstudiantes, nota, suma = 0, validar, validacion;
    float promedio;

    do {
            printf("Ingrese el numero de estudiantes: ");
            validar = scanf("%d", &numEstudiantes);

        if (validar != 1) {
            printf(" No ingresó un numero valido.\n");
            while (getchar() != '\n');
        }

    } while (validar != 1);

    while (numEstudiantes <= 0) {
        printf("El valor debe ser positivo\n");
        printf("Ingrese el numero de estudiantes: ");
        scanf("%d", &numEstudiantes);
    }

    for (int i = 0; i < numEstudiantes; i++) {
        printf("Estudiante %d\n", (i + 1));
        do {
            
            do {
                    printf("Ingrese la nota, debe estar entre 1 y 10: ");
                    validacion= scanf("%d", &nota);

                if (validacion != 1) {
                    printf(" No ingresó un numero valido.\n");
                     while (getchar() != '\n');
                }
                if (nota > 10 || nota < 1) {
                    printf("La nota no es valida, intente nuevamente\n");
                }
            } while (validacion != 1);
        } while (nota > 10 || nota < 1);

        suma += nota;
    }

    promedio = (float)suma / numEstudiantes;
    printf("El promedio de las notas es: %.2f\n", promedio);

    return 0;
}
