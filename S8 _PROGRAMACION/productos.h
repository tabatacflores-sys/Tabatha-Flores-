int buscarProducto(char productos[][20], int activos[], int total, char *nombreBuscado);

void ingresarProducto(
    char productos[][20],
    int cantidades[],
    float tiempos[],
    int recursos[],
    int activos[],
    int *indexProductos
);

void editarProducto(
    char productos[][20],
    int cantidades[],
    float tiempos[],
    int recursos[],
    int activos[],
    int indexProductos
);

void eliminarProducto(
    char productos[][20],
    int cantidades[],
    float tiempos[],
    int recursos[],
    int activos[],
    int *indexProductos
);

void calcularTotales(
    int cantidades[],
    float tiempos[],
    int recursos[],
    int activos[],
    int indexProductos,
    float *tiempoTotal,
    int *recursosTotales
);

void mostrarResultados(
    float tiempoTotal,
    int recursosTotales,
    float tiempoDisponible,
    int recursosDisponibles
);
