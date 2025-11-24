#include <stdio.h>
#include "productos.h"
#include "validaciones.h"

void copiarCadena(char destino[], char origen[]) {
    int i = 0;
    while (origen[i] != '\0') {
        destino[i] = origen[i];
        i++;
    }
    destino[i] = '\0';
}

int compararCadenas(char *a, char *b) {
    int i = 0;
    while (a[i] != '\0' || b[i] != '\0') {
        if (a[i] != b[i])
            return 0;
        i++;
    }
    return 1;
}

int buscarProducto(char productos[][20], int activos[], int total, char *nombreBuscado) {
    for (int i = 0; i < total; i++) {
        if (activos[i] == 1) {
            if (compararCadenas(productos[i], nombreBuscado))
                return i;
        }
    }
    return -1;
}

void ingresarProducto(
    char productos[][20],
    int cantidades[],
    float tiempos[],
    int recursos[],
    int activos[],
    int *indexProductos
) {
    if (*indexProductos >= 5) {
        printf("No se pueden agregar mas productos.\n");
        return;
    }

    int i = *indexProductos;

    validarCadena(productos[i], "Nombre del producto: ");
    cantidades[i] = validarEnteroPositivo("Cantidad requerida: ");
    tiempos[i] = validarFlotantePositivo("Tiempo por unidad (horas): ");
    recursos[i] = validarEnteroPositivo("Recursos por unidad: ");

    activos[i] = 1;
    (*indexProductos)++;

    printf("Producto agregado correctamente.\n");
}

void editarProducto(
    char productos[][20],
    int cantidades[],
    float tiempos[],
    int recursos[],
    int activos[],
    int indexProductos
) {
    char nombre[20];
    validarCadena(nombre, "Ingrese el nombre del producto a editar: ");

    int pos = buscarProducto(productos, activos, indexProductos, nombre);

    if (pos == -1) {
        printf("Producto no encontrado.\n");
        return;
    }

    printf("Editando el producto: %s\n", productos[pos]);

    validarCadena(productos[pos], "Nuevo nombre: ");
    cantidades[pos] = validarEnteroPositivo("Nueva cantidad requerida: ");
    tiempos[pos] = validarFlotantePositivo("Nuevo tiempo por unidad: ");
    recursos[pos] = validarEnteroPositivo("Nuevos recursos por unidad: ");

    printf("Producto editado correctamente.\n");
}

void eliminarProducto(
    char productos[][20],
    int cantidades[],
    float tiempos[],
    int recursos[],
    int activos[],
    int *indexProductos
) {
    char nombre[20];
    validarCadena(nombre, "Nombre del producto a eliminar: ");

    int pos = buscarProducto(productos, activos, *indexProductos, nombre);

    if (pos == -1) {
        printf("Producto no encontrado.\n");
        return;
    }

    for (int i = pos; i < (*indexProductos) - 1; i++) {
        copiarCadena(productos[i], productos[i + 1]);
        cantidades[i] = cantidades[i + 1];
        tiempos[i] = tiempos[i + 1];
        recursos[i] = recursos[i + 1];
        activos[i] = activos[i + 1];
    }

    (*indexProductos)--;

    printf("Producto eliminado correctamente.\n");
}

void calcularTotales(
    int cantidades[],
    float tiempos[],
    int recursos[],
    int activos[],
    int indexProductos,
    float *tiempoTotal,
    int *recursosTotales
) {
    *tiempoTotal = 0;
    *recursosTotales = 0;

    for (int i = 0; i < indexProductos; i++) {
        if (activos[i]) {
            *tiempoTotal += cantidades[i] * tiempos[i];
            *recursosTotales += cantidades[i] * recursos[i];
        }
    }
}

void mostrarResultados(
    float tiempoTotal,
    int recursosTotales,
    float tiempoDisponible,
    int recursosDisponibles
) {
    printf("\n===== RESULTADOS =====\n");
    printf("Tiempo total requerido: %.2f horas\n", tiempoTotal);
    printf("Recursos totales requeridos: %d\n", recursosTotales);
    printf("Tiempo disponible: %.2f horas\n", tiempoDisponible);
    printf("Recursos disponibles: %d\n", recursosDisponibles);

    if (tiempoTotal <= tiempoDisponible && recursosTotales <= recursosDisponibles)
        printf("\nLa fabrica si puede cumplir con la demanda.\n");
    else
        printf("\nLa fabrica no puede cumplir con la demanda.\n");
}
