/*
Nombre: Ender Cruz
Fecha: 19/04/2026
*/
#include <stdio.h>

int main (int argc, char *argv[]) {

    float cal[5][3][3]={0};
    char nombres[5][20];
    char asignaturas[3][20]={"Fisica","Quimica","Calculo"};

    float prom[5][3]={0};
    int opc = 0, opc2 = 0;
    int contE = 0;
    int selE=0;

    do{
        printf("\nSeleccione una opcion:\n");
        printf("1.Registrar estudiante\n");
        printf("2.Registrar calificaciones\n");
        printf("3.Promedios por estudiante\n");
        printf("4.Promedios por asignatura\n");
        printf("5.Nota mas alta y baja por estudiante\n");
        printf("6.Nota mas alta y baja por asignatura\n");
        printf("7.Aprobados y reprobados por asignatura\n");
        printf(">> ");
        scanf("%d",&opc);

        switch (opc)
        {
        case 1:
            printf("Registre el nombre del estudiante %d:\n",contE+1);
            getchar();
            fgets(nombres[contE],20,stdin);
            contE++;
            break;

        case 2:
            printf("Seleccione el estudiante:\n");
            for (int i = 0; i < contE; i++)
            {
                printf("%d.%s",i,nombres[i]);
            }
            printf(">> ");
            scanf("%d",&selE);

            for (int i = 0; i < 3; i++)
            {
                prom[selE][i]=0;

                printf("\n%s\n",asignaturas[i]);
                for (int j = 0; j < 3; j++)
                {
                    do{
                        printf("Nota %d: ",j+1);
                        scanf("%f",&cal[selE][i][j]);
                    }while(cal[selE][i][j]<0 || cal[selE][i][j]>10);

                    prom[selE][i]+=cal[selE][i][j];
                }
                prom[selE][i]/=3;
            }
            break;

        case 3:{
            float promAux = 0;
            printf("\nPROMEDIOS POR ESTUDIANTE\n");
            printf("%s\t%s\t%s\tPromedio\tNombre\n",
                    asignaturas[0],asignaturas[1],asignaturas[2]);

            for (int i = 0; i < contE; i++)
            {
                promAux = (prom[i][0] + prom[i][1] + prom[i][2])/3;
                printf("%.2f\t%.2f\t%.2f\t%.2f\t\t%s",
                        prom[i][0],prom[i][1],prom[i][2],
                        promAux,nombres[i]);
            }
            break;
        }

        case 4:{
            float promA[3]={0};

            for(int i=0;i<contE;i++){
                for(int j=0;j<3;j++){
                    promA[j]+=prom[i][j];
                }
            }

            printf("\nPROMEDIOS POR ASIGNATURA\n");
            for(int j=0;j<3;j++){
                printf("%s: %.2f\n",asignaturas[j],promA[j]/contE);
            }
            break;
        }

        case 5:{
            printf("\nMAX Y MIN POR ESTUDIANTE\n");

            for(int i=0;i<contE;i++){
                float max=cal[i][0][0];
                float min=cal[i][0][0];

                for(int j=0;j<3;j++){
                    for(int k=0;k<3;k++){
                        if(cal[i][j][k]>max) max=cal[i][j][k];
                        if(cal[i][j][k]<min) min=cal[i][j][k];
                    }
                }
                printf("%s -> Max: %.2f | Min: %.2f\n",nombres[i],max,min);
            }
            break;
        }

        case 6:{
            printf("\nMAX Y MIN POR ASIGNATURA\n");

            for(int j=0;j<3;j++){
                float max=cal[0][j][0];
                float min=cal[0][j][0];

                for(int i=0;i<contE;i++){
                    for(int k=0;k<3;k++){
                        if(cal[i][j][k]>max) max=cal[i][j][k];
                        if(cal[i][j][k]<min) min=cal[i][j][k];
                    }
                }
                printf("%s -> Max: %.2f | Min: %.2f\n",asignaturas[j],max,min);
            }
            break;
        }

        case 7:{
            int aprob=0, reprob=0;

            printf("\nAPROBADOS Y REPROBADOS\n");

            for(int j=0;j<3;j++){
                aprob=0;
                reprob=0;

                for(int i=0;i<contE;i++){
                    if(prom[i][j] >= 6)
                        aprob++;
                    else
                        reprob++;
                }

                printf("%s -> Aprobados: %d | Reprobados: %d\n",
                        asignaturas[j],aprob,reprob);
            }
            break;
        }

        default:
            printf("Opcion invalida\n");
            break;
        }

        printf("\nDesea seleccionar otra opcion? 1.Si/2.No: ");
        scanf("%d",&opc2);

    }while(opc2==1);

    return 0;
}