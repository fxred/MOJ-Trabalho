#include <stdio.h>
#include <stdlib.h>
typedef int Item;
typedef struct no_st{
    Item item;
    struct no_st *prox;
}No;
typedef struct header_St{
    No *inicio;
}Header;
int inicializa_Lista(Header *H){
    H -> inicio = NULL;
    return 1;
}
int insere(Header *H, Item insert){
    No *temp = malloc(sizeof(No));
    if(temp == NULL)return 0;
    temp -> item = insert;
    if(H -> inicio == NULL){ // inserir no início
        H -> inicio = temp;
        temp -> prox = NULL;
        return 1;
    }

    else{ 
        No *aux = H -> inicio;

        if(aux -> item >= temp -> item){
                temp -> prox = aux;
                H -> inicio = temp;

                return 1;
        } else{

            while(aux -> prox != NULL && (aux -> prox -> item <= temp -> item)){
                aux = aux -> prox;
            }

            if(aux -> prox == NULL){
                aux -> prox = temp;
                temp -> prox = NULL;

                return 1;
            } else {
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