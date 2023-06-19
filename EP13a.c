#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Shash{
    char *c;
    struct Shash *prox;
}Thash;

void IniciaHash(Thash* **hash){
    *hash = (Thash **) malloc(26*sizeof(Thash));
    for(int i=0;i<26;i++){
        (*hash)[i] = NULL;
    }
}

void SeparaPalavras(char linha[]){
    //percorrer linha at� encontrar n�o letra e substituir por '\0'
}

void InsereHash(Thash **hash, char linha[]){
    //inserir cada palavras separada com hash de: hashk = hashk + (int)string[i]
}

void printHash(Thash **hash){
    //printar Hash linha a linha, pois j� estar� em ordem alfab�tica
}

int main(){
    char linha[201];
    Thash **hash;


    fgets(linha, 200, stdin);
    do{
        //fazer tolower dentro de outra fun��o pra ficar bonitinho
        tolower(linha);

        IniciaHash(&hash);

        SeparaPalavras(linha);

        InsereHash(hash, linha);

        printHash(hash);

        fgets(linha, 200, stdin);
    }while(linha[0]!=EOF);

    return 0;
}
