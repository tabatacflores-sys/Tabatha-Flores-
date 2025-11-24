#include <stdio.h>
#include "productos.h"
#include "validaciones.h"

int main() {
    char productos[5][20];
    int cantidades[5];
    float tiempos[5];
    int recursos[5];
    int activos[5] = {0};

    int indexProductos = 0;
    int opcion;

    float tiempoDisponible = 500;
    int recursosDisponibles = 300;

    do {
        printf("\n===== MENU PRINCIPAL =====\n");
        printf("1. Ingresar producto\n");
        printf("2. Editar producto\n");
        printf("3. Eliminar producto\n");
        printf("4. Calcular produccion total\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
        case 1:
            ingresarProducto(productos, cantidades, tiempos, recursos, activos, &indexProductos);
            break;

        case 2:
            editarProducto(productos, cantidades, tiempos, recursos, activos, indexProductos);
            break;

        case 3:
            eliminarProducto(productos, cantidades, tiempos, recursos, activos, &indexProductos);
            break;

        case 4: {
            float tiempoTotal;
            int recursosTotales;
            calcularTotales(cantidades, tiempos, recursos, activos, indexProductos, &tiempoTotal, &recursosTotales);
            mostrarResultados(tiempoTotal, recursosTotales, tiempoDisponible, recursosDisponibles);
            break;
        }

        case 5:
            printf("Saliendo...\n");
            break;

        default:
            printf("Opcion invalida.\n");
        }

    } while (opcion != 5);

    return 0;
}
