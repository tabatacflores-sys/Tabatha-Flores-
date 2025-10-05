#include <stdio.h>

int main(void){
    int idProducto, stock = 0, cantidadVendida, cantidadReabastecer;
    float precio = 0, totalVentas, ganancias = 0;
    char nombreProducto[50];
    int opcion, validar;
    int productoRegistrado;

    do {
        do {
            printf("\nMENÚ\n");
            printf("1. Registrar producto\n");
            printf("2. Vender producto\n");
            printf("3. Reabastecer el producto\n");
            printf("4. Consultar información actualizada\n");
            printf("5. Ganancias obtenidas\n");
            printf("6. Salir\n");
            printf("Seleccione una opción: ");
            validar = scanf("%d", &opcion);
            if (validar != 1 || opcion < 1 || opcion > 6) {
                printf("Entrada inválida. Ingrese un número entre 1 y 6.\n");
                while (getchar() != '\n'); 
                validar = 0;
            }
        } while (validar != 1);

        switch (opcion){

        case 1: 
            do {
                printf("Ingrese ID del producto: ");
                validar = scanf("%d", &idProducto);
                if (validar != 1 || idProducto <= 0) {
                    printf(" No ingresó un número válido.\n");
                    while (getchar() != '\n');
                    validar = 0;
                }
            } while (validar != 1);

            printf("Ingrese el nombre del producto: ");
            scanf("%49s", nombreProducto);

            do {
                printf("Ingrese cantidad en stock: ");
                validar = scanf("%d", &stock);
                if (validar != 1 || stock < 0) {
                    printf(" Entrada inválida. Debe ser un entero >= 0.\n");
                    while (getchar() != '\n');
                    validar = 0;
                }
            } while (validar != 1);

            do {
                printf("Ingrese precio unitario: ");
                validar = scanf("%f", &precio);
                if (validar != 1 || precio <= 0.0f) {
                    printf(" Entrada inválida, debe ser un número mayor que 0.\n");
                    while (getchar() != '\n');
                    validar = 0;
                }
            } while (validar != 1);

            ganancias = 0;
            totalVentas = 0;
            productoRegistrado = 1;
            printf("Producto registrado correctamente.\n");
            break;

        case 2: 
            if (!productoRegistrado) {
                printf("Primero registre un producto (opción 1).\n");
                break;
            }
            if (stock <= 0) {
                printf("No hay stock disponible.\n");
                break;
            }

            do {
                printf("Ingrese cuántas unidades desea vender (1..%d): ", stock);
                validar = scanf("%d", &cantidadVendida);
                if (validar != 1 || cantidadVendida <= 0 || cantidadVendida > stock) {
                    printf(" Cantidad inválida. Debe ser un entero entre 1 y %d.\n", stock);
                    while (getchar() != '\n');
                    validar = 0;
                }
            } while (validar != 1);

            stock -= cantidadVendida;
            ganancias += (cantidadVendida * precio);
            totalVentas += (cantidadVendida * precio);

            printf("Venta realizada, el stock restante es: %d\n", stock);
            break;

        case 3: 
            if (!productoRegistrado) {
                printf("Primero registre un producto (opción 1).\n");
                break;
            }

            do {
                printf("Ingrese cantidad a reabastecer: ");
                validar = scanf("%d", &cantidadReabastecer);
                if (validar != 1 || cantidadReabastecer <= 0) {
                    printf(" Entrada inválida. Debe ser un entero > 0.\n");
                    while (getchar() != '\n');
                    validar = 0;
                }
            } while (validar != 1);

            stock += cantidadReabastecer;
            printf("Reabastecimiento realizado. Nuevo stock: %d\n", stock);
            break;

        case 4: 
            if (!productoRegistrado) {
                printf("No hay producto registrado aún.\n");
            } else {
                printf("\n--- Información del producto ---\n");
                printf("ID Producto: %d\n", idProducto);
                printf("Nombre: %s\n", nombreProducto);
                printf("Stock: %d\n", stock);
                printf("Precio unitario: %.2f\n", precio);
                printf("Total vendido: %.2f\n", totalVentas);
            }
            break;

        case 5: 
            printf("Ganancias obtenidas hasta el momento: %.2f\n", ganancias);
            break;

        case 6:
            printf("\nSaliendo... Gracias por usar nuestro programa\n");
            break;

        default:
            printf("Opción no válida.\n");
            break;
        }
    } while(opcion != 6);
    return 0;
}
