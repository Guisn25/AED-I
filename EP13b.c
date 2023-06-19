#include <stdio.h>
#include <string.h>

void LerIdiomas(int K){
    char idioma[20], aux[20];
    int ingles=0;

    scanf("%s", idioma);
    for(int i=1;i<K;i++){
        scanf("%s", aux);
        if(strcmp(idioma, aux)!=0){
            ingles = 1;
        }
    }
    if(ingles){
        printf("ingles");
    }else{
        printf("%s", idioma);
    }

}

int main(){
    int N, K;

    scanf("%i", &N);

    for(int i=0;i<N;i++){
        scanf("%i", &K);
        LerIdiomas(K);
        printf("\n");
    }

    return 0;
}
