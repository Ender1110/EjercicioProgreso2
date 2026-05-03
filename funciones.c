#include <stdio.h>
#include <string.h>
#include "funciones.h"

void ingresarDatos(char nombres[MAX][50], float precios[MAX], int *n) {
    printf("Ingrese numero de productos (max 10): ");
    scanf("%d", n);

    for (int i = 0; i < *n; i++) {
        printf("Nombre: ");
        scanf("%s", nombres[i]);

        printf("Precio: ");
        scanf("%f", &precios[i]);
    }
}

float totalInventario(float precios[MAX], int n) {
    float suma = 0;
    for (int i = 0; i < n; i++) {
        suma += precios[i];
    }
    return suma;
}

void productoCaroBarato(char nombres[MAX][50], float precios[MAX], int n) {
    int caro = 0, barato = 0;

    for (int i = 1; i < n; i++) {
        if (precios[i] > precios[caro]) caro = i;
        if (precios[i] < precios[barato]) barato = i;
    }

    printf("Mas caro: %s - %.2f\n", nombres[caro], precios[caro]);
    printf("Mas barato: %s - %.2f\n", nombres[barato], precios[barato]);
}

float promedio(float precios[MAX], int n) {
    return totalInventario(precios, n) / n;
}

void buscarProducto(char nombres[MAX][50], float precios[MAX], int n) {
    char buscar[50];
    int encontrado = 0;

    printf("Buscar: ");
    scanf("%s", buscar);

    for (int i = 0; i < n; i++) {
        if (strcmp(nombres[i], buscar) == 0) {
            printf("Encontrado: %s - %.2f\n", nombres[i], precios[i]);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("No encontrado\n");
    }
}