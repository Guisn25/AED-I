#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InicializaRand_v(int v[], int n){
    for(int i=0;i<n;i++){
        v[i] = rand()%(2*n);
    }
}

//Incorreto na última iteração
void Merge(int v[], int p, int q, int r){
    int i, j, k;
    int *aux = (int *) malloc((r+1)*sizeof(int *));

    for(i=p;i<=q;i++){
        aux[i] = v[i];
    }

    for(j=r;j>=q+1;j--){
        aux[j] = v[j];
    }

    for(i=p, j=r, k=p;k<=r;k++){
        if(aux[i] <= aux[j]){
            v[k] = aux[i];
            v[i++] = aux[k];
        }else{
            v[k] = aux[j];
            v[j--] = aux[k];
        }
    }

    free(aux);
}

void MergeSort(int v[], int p, int r){
    int q;

    if(p<r){
        q = (int) (p+r)/2;
        MergeSort(v, p, q);
        MergeSort(v, q+1, r);
        Merge(v, p, q, r);
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
    MergeSort(v, 0, n-1);
    t = clock() - t;

    printf("O algoritmo levou %lf s para ser executado", t/CLOCKS_PER_SEC);
    free(v);
    return 0;
}
