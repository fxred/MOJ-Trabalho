#include <stdio.h>

#include <stdlib.h>

typedef int Item;

typedef struct no_st{
    Item item;
    struct no_st *prox;
}No;

typedef struct header_St{
    No *inicio;
    int no_count;
}Header;

int inicializa_Lista(Header *H){
    H -> inicio = NULL;
    H -> no_count = 0;

    return 1;
}

int insere(Header *H, Item insert){
    No *temp = malloc(sizeof(No));
    if(temp == NULL)return 0;

    temp -> item = insert;

    if(H -> inicio == NULL){
        H -> inicio = temp;
        H -> no_count++;

        temp -> prox = NULL;
        return 1;
    }

    else{
        No *aux = H -> inicio;
        while((aux -> item <= temp -> item) || aux -> prox != NULL){aux = aux -> prox;}

        if(aux -> prox != NULL){
            temp -> prox = aux -> prox;
            aux -> prox = temp;

            H -> no_count++;
        } else{
            aux -> prox = temp;
            temp -> prox = NULL;

            H -> no_count++;
        }
    }

    H -> inicio = temp;
    H -> no_count = H -> no_count++;
    
    return 1;
}

int main(){
    int op, placa;

    Header H;
    inicializa_Lista(&H);
    
    while(scanf("%d %d", &op, &placa) == 2 && (op != EOF || placa != EOF)){
        if(op == 1){insere(&H, placa);} 
        else if(op == 2){
            for(int i = 0; i < placa; i++){
                No *aux = H.inicio;

                if(i == (placa - 1)){printf("%d\n", aux -> item);}
                else{printf("%d ", aux -> item);}
            }
        }
    }
}