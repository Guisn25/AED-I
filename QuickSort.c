#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InicializaRand_v(int v[], int n){
    for(int i=0;i<n;i++){
        v[i] = rand()%(2*n);
    }
}

//CORRIGIR TUDO

int Separa(int v[], int p, int r){
    int k, t;
    int c = v[r], j = p;

    for(k=p;k<r;k++){
        if(v[k]<=c){
            t = v[j];
            v[j] = v[k];
            v[k] = t;
            j++;
        }
        v[r] = v[j];
        v[j] = c;
    }
    return j;
}


void QuickSort(int v[], int p, int r){
    int j;

    if(p<r){
        j = Separa(v, p, r);
        QuickSort(v, p, j-1);
        QuickSort(v, j+1, r);
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
    QuickSort(v, 0, n-1);
    t = clock() - t;

    printf("O algoritmo levou %lf s para ser executado", t/CLOCKS_PER_SEC);
    free(v);
    return 0;
}
