#include <stdio.h>
#include "funciones.h"

int main() {
    char nombres[MAX][50];
    float precios[MAX];
    int n;

    ingresarDatos(nombres, precios, &n);

    printf("Total: %.2f\n", totalInventario(precios, n));

    productoCaroBarato(nombres, precios, n);

    printf("Promedio: %.2f\n", promedio(precios, n));

    buscarProducto(nombres, precios, n);

    return 0;
}