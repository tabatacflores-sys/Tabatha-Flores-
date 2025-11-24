#include <stdio.h>

int validarEnteroPositivo(char mensaje[]) {
    int valor;
    do {
        printf("%s", mensaje);
        scanf("%d", &valor);
        if (valor <= 0)
            printf("Error: ingrese un numero entero positivo.\n");
    } while (valor <= 0);

    return valor;
}

float validarFlotantePositivo(char mensaje[]) {
    float valor;
    do {
        printf("%s", mensaje);
        scanf("%f", &valor);
        if (valor <= 0)
            printf("Error: ingrese un numero positivo.\n");
    } while (valor <= 0);

    return valor;
}

int longitudCadenaManual(char *cadena) {
    int i = 0;
    while (cadena[i] != '\0') i++;
    return i;
}

void validarCadena(char *cadena, char mensaje[]) {
    do {
        printf("%s", mensaje);
        scanf(" %[^\n]", cadena);

        if (longitudCadenaManual(cadena) == 0)
            printf("Error: la cadena no puede estar vacia.\n");

    } while (longitudCadenaManual(cadena) == 0);
}
