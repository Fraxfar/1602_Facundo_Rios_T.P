#include <stdio.h>
#include <string.h>

void mostrar(int x,int y,int m[x][y]);

int main()
{
    char nom_mat[6][4]={"mat","len","ing","geo","bio"};
    char nombre_ape[20];
    int i,j,x=5,y=3,sum=0,aprob=0,notas[5][3]={0};
    float prom,prom_mate[5]={0};

    printf("ingrese el nombre y apellido del alumno: ");
    gets(nombre_ape);
    fflush(stdin);
    for(i=0;i<5;i++){
       for(j=0;j<3;j++){
            printf("ingrese nota de %s trim %d: ",nom_mat[i],j+1);
            scanf("%d",&notas[i][j]);
            sum=sum+notas[i][j];
            prom_mate[i]=prom_mate[i]+notas[i][j];
        }   
    }
    mostrar(x,y,notas);
    for(i=0;i<5;i++){
        prom_mate[i]=(float)prom_mate[i]/3;
        printf("el promedio de %s es: %.2f\n",nom_mat[i],prom_mate[i]);
        if (prom_mate[i]>=6){
            aprob++;
        }
    }
    printf("el porcentaje de materias aprobadas es: %d\n",(aprob*100)/5); // 5=100%
    prom=(float)sum/15;
    printf("promedio general: %.2f",prom);
    return 0;
}
void mostrar(int x,int y,int m[x][y]){
    char nom_mat[6][4]={"mat","len","ing","geo","bio"};
    int i,j;
    for(j=0;j<4;j++){
        if(j==0){
            printf("     |");
        } else {
            printf("trim %d |",j);
        }
    }
    printf("\n");
    for(i=0;i<5;i++){
        for(j=0;j<3;j++){
            if(j==0){
                printf("%s  |",nom_mat[i]);
            }
            printf(" %d     |",m[i][j]);
        }   
        printf("\n");
    } 
}