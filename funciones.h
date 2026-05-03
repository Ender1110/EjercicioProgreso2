#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX 10

void ingresarDatos(char nombres[MAX][50], float precios[MAX], int *n);
float totalInventario(float precios[MAX], int n);
void productoCaroBarato(char nombres[MAX][50], float precios[MAX], int n);
float promedio(float precios[MAX], int n);
void buscarProducto(char nombres[MAX][50], float precios[MAX], int n);

#endif