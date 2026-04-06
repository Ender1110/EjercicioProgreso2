/*
Nombre: Ender Cruz
Fecha: 05/04/2026
*/
#include <stdio.h>
#include <string.h>

int main()
{
    char ID[10];
    char nombre[20];
    int stock = 0;
    float precio = 0;

    int opc = 0, opc2 = 0;
    int len;
    int aux;

    int cantidad;
    int agregar;

    float ganancias = 0;
    float total;
    float descuento;

    do{
        printf("\nSeleccione una opcion:\n");
        printf("1. Registrar producto\n");
        printf("2. Vender producto\n");
        printf("3. Reabastecer producto\n");
        printf("4. Informacion producto\n");
        printf("5. Ganancias totales\n");
        printf("6. Salir\n");

        do{
            printf(">> ");
            aux = scanf("%d",&opc);
            if(aux != 1 || opc < 1 || opc > 6){
                printf("Ingrese una opcion valida\n");
                while(getchar()!='\n');
            }
        }while (aux != 1 || opc < 1 || opc > 6);

        switch(opc){

            case 1:

                printf("Ingresar el ID del producto: ");
                scanf("%s",ID);

                printf("Ingresar el nombre del producto: ");
                getchar();
                fgets(nombre,20,stdin);

                len = strlen(nombre) - 1;
                nombre[len] = '\0';

                printf("Ingresar el stock del producto: ");
                scanf("%d",&stock);

                printf("Ingresar el precio del producto: ");
                scanf("%f",&precio);

                break;

            case 2:

                printf("Cantidad a vender: ");
                scanf("%d",&cantidad);

                if(cantidad <= 0){
                    printf("Cantidad invalida\n");
                }

                else if(cantidad > stock){
                    printf("No hay suficiente stock\n");
                }

                else{

                    printf("Ingrese descuento (0-100): ");
                    scanf("%f",&descuento);

                    total = cantidad * precio;

                    total = total - (total * descuento / 100);

                    stock = stock - cantidad;

                    ganancias = ganancias + total;

                    printf("Venta realizada\n");
                    printf("Total venta: %.2f\n",total);
                }

                break;

            case 3:

                printf("Cantidad a agregar al stock: ");
                scanf("%d",&agregar);

                if(agregar > 0){
                    stock = stock + agregar;
                    printf("Stock actualizado\n");
                }
                else{
                    printf("Cantidad invalida\n");
                }

                break;

            case 4:

                printf("\nInformacion del producto:\n");
                printf("ID: %s\n",ID);
                printf("Nombre: %s\n",nombre);
                printf("Stock: %d\n",stock);
                printf("Precio: %.2f\n",precio);

                break;

            case 5:

                printf("Ganancias totales: %.2f\n",ganancias);

                break;

            case 6:

                printf("Saliendo del programa...\n");

                break;
        }

        if(opc != 6){
            printf("\nDesea seleccionar otra opcion: 1.Si / 2.No: ");
            scanf("%d",&opc2);
        }

    }while(opc2 == 1 && opc != 6);

    return 0;
}