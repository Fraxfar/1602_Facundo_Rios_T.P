#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Llenar_Vector(int v[], int l);
void Mostrar_Vector(int v[], int l);
void Mostrar_Vector_Veces(int v[], int l);
void Suplantar_Repetidos(int v[], int l);
void Resta_Repetidos(int v[], int repet[], int l, int q);
void Suplantar_No_Repetidos(int v[], int l);

int main() {
    srand(time(NULL));

    int Vector1[10];
    int Vector2[10];
    int Vector_sin_rep[20];
    int Vector_de_rep[20];

    Llenar_Vector(Vector1, 10);
    Llenar_Vector(Vector2, 10);

    printf("Vectores originales:\n");
    printf("Vector 1: ");
    Mostrar_Vector(Vector1, 10);

    printf("Vector 2: ");
    Mostrar_Vector(Vector2, 10);

    Suplantar_Repetidos(Vector1, 10);
    Suplantar_Repetidos(Vector2, 10);

    printf("\nVectores despues de suplantar repetidos:\n");
    printf("Vector 1: ");
    Mostrar_Vector_Veces(Vector1, 10);

    printf("Vector 2: ");
    Mostrar_Vector_Veces(Vector2, 10);

    for(int i=0;i<10;i++) {
        Vector_sin_rep[i]=Vector1[i];
        Vector_de_rep[i]=Vector1[i];
        Vector_sin_rep[i+10]=Vector2[i];
        Vector_de_rep[i+10]=Vector2[i];
    }
    
    Suplantar_Repetidos(Vector_sin_rep, 20);
    Suplantar_No_Repetidos(Vector_de_rep, 20);

    printf("\nVector sin repetidos:\n");
    Mostrar_Vector(Vector_sin_rep, 20);
    printf("\nVector de repetidos:\n");
    Mostrar_Vector(Vector_de_rep, 20);
    int q=0;
    for (int i=0;i<10;i++){
        if(Vector_de_rep[i]!=0){
            Vector_de_rep[q]=Vector_de_rep[i];
        } else {
            q--;
        }
        q++;
    }
    Resta_Repetidos(Vector1, Vector_de_rep, 20, q);
    Resta_Repetidos(Vector2, Vector_de_rep, 20, q);

    printf("\nResta vector1-vector2: \n");
    Mostrar_Vector(Vector1, 10);
    printf("\nResta vector2-vector1: \n");
    Mostrar_Vector(Vector2, 10);

    return 0;
}

void Llenar_Vector(int v[], int l) {
    int min=20,max=35;
    for(int i=0;i<l;i++) {
        v[i]=min+(rand()%(max-min+1));
    }
}

void Mostrar_Vector(int v[], int l) {
    for(int i=0;i<l;i++) {
        if (v[i]!=0){
            printf("%d ", v[i]);
        }
    }
    printf("\n");
}

void Mostrar_Vector_Veces(int v[], int l) {
    int k=0;
    for(int i=0;i<l;i++) {
        if (v[i]!=0){
            printf("%d ", v[i]);
        } else {
            k++;
        }
    }
    printf("        se repitio %d veces",k);
    printf("\n");
}

void Suplantar_Repetidos(int v[], int l) {
    for(int i=0;i<l;i++) {
        for(int j=i+1;j<l;j++) {
            if(v[i]==v[j]) {
                v[j]=0;
            }
        }
    }
}

void Resta_Repetidos(int v[], int repet[], int l, int q) {
    for(int i=0;i<l;i++) {
        for(int j=0;j<q;j++) {
            if(v[i]==repet[j]) {
                v[i]=0;
            }
        }
    }
}

void Suplantar_No_Repetidos(int v[], int l) {
    for(int i=0;i<l;i++) {
        int repetido=0;
        for(int j=i+1;j<l;j++) {
            if(i!=j && v[i]==v[j]) {
                repetido=1;
                break;
            }
        }
        if(!repetido) {
            v[i]=0;
        }
    }
}