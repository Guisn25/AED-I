#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InicializaRand_v(int v[], int n){
    for(int i=0;i<n;i++){
        v[i] = rand()%(2*n);
    }
}

void InsereEmHeap (int m, int v[]) {
    int t;
    int f = m+1;

    while(f>1 && v[f/2]<v[f]){
        t = v[f/2];
        v[f/2] = v[f];
        v[f] = t;
        f = f/2;
    }
}

void SacodeHeap(int m, int v[]){
    int t, f = 2;

    while(f <= m){
        if(f<m && v[f]<v[f+1]){
            ++f;
        }
        if(v[f/2]>=v[f]){
            break;
        }
    t = v[f/2];
    v[f/2] = v[f];
    v[f] = t;
    f *= 2;
    }
}

void HeapSort(int v[], int n){
    int m;

    for(m=1;m<n;m++){
        InsereEmHeap(m, v);
    }

    for(m=n;m>1;m--){
        int t = v[1];
        v[1] = v[m];
        v[m] = t;
        SacodeHeap(m-1, v);
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
    HeapSort(v, n);
    t = clock() - t;

    printf("O algoritmo levou %lf s para ser executado", t/CLOCKS_PER_SEC);
    free(v);
    return 0;
}
