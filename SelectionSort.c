#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InicializaRand_v(int v[], int n){
    for(int i=0;i<n;i++){
        v[i] = rand()%(2*n);
    }
}

void SelectionSort(int v[], int n){
    int i, j, min, x;

    for(i=0;i<n-1;i++){
        min = i;
        for(j=i+1;j<n;j++){
            if (v[j]<v[min]){
                min = j;
            }
        }
        x = v[i];
        v[i] = v[min];
        v[min] = x;
    }
}

int main(){
    int n;
    int *v;
    double t;

    printf("Insira o tamanho n do vetor: ");
    scanf("%i", &n);

    v = (typeof(v)) malloc(n*sizeof(v));

    InicializaRand_v(v, n);

    t = clock();
    SelectionSort(v, n);
    t = clock() - t;

    printf("O algoritmo levou %lf s para ser executado", t/CLOCKS_PER_SEC);
    free(v);
    return 0;
}
