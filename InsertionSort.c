#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InicializaRand_v(int v[], int n){
    for(int i=0;i<n;i++){
        v[i] = rand()%(2*n);
    }
}

void InsertionSort(int v[], int n){
    int i, j, x;

    for(j=1;j<n;j++){
        x = v[j];
        for(i=j-1;i>=0&&v[i]>x;i--){
            v[i+1] = v[i];
        }
    v[i+1] = x;
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
    InsertionSort(v, n);
    t = clock() - t;

    printf("O algoritmo levou %lf s para ser executado", t/CLOCKS_PER_SEC);
    return 0;
}
