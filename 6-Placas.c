#include <stdio.h>
#include <stdlib.h>

typedef unsigned int Item;

typedef struct no_st{
    Item item;
    struct no_st *prox;
}No;

typedef struct header_St{
    No *inicio;
    No *final;
}Header;

int inicializa_Lista(Header *H){
    H -> inicio = NULL;
    H -> final = NULL;
    return 1;
}

int insere(Header *H, Item insert){
    No *temp = malloc(sizeof(No));
    if(temp == NULL)return 0;

    temp -> item = insert;

    if(H -> inicio == NULL){ // inserir no início
        H -> inicio = temp;
        H -> final = temp;

        temp -> prox = NULL;
        return 1;
    }

    else{ 
        No *aux = H -> inicio;

        if(aux -> item > temp -> item){
                temp -> prox = aux;
                H -> inicio = temp;

                return 1;
        } else{

            if(H -> final -> item < temp -> item){
                H -> final -> prox = temp;
                H -> final = temp;

                return 1;
            } else{
                 while(aux -> prox -> item < temp -> item){
                    aux = aux -> prox;
                }

                temp -> prox = aux -> prox;
                aux -> prox = temp;

                return 1;
            }
        }
    }
}

int main(){
    int op, placa;

    Header H;
    inicializa_Lista(&H);
    
    while(scanf("%d %d", &op, &placa) == 2){
        if(op == 1){insere(&H, placa);}
        else if(op == 2){
            No *aux = H.inicio;
            
            for(int i = 0; i < placa; i++){
                if(i == (placa - 1)){printf("%d\n", aux -> item);}
                else {
                    printf("%d ", aux -> item);
                    aux = aux->prox;
                }
            }
        }
    }
}