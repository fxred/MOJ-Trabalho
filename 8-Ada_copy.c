#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Item;

typedef struct no_st{
    Item item;
    struct no_st *prox;
    struct no_st *ant;
}No;

typedef struct header_St{
    No *inicio;
    No *final;
    int no_count;
}Header;

int initialize_queue(Header *H){
    H -> inicio = NULL;
    H -> final = NULL;

    return 1;
}

int is_empty(Header *H){return H->inicio == NULL && H->final == NULL;}

void front(Header *H){
    if(is_empty(H))return printf("No job for Ada?\n");

    printf("%d\n", H -> inicio -> item);

    if (H->inicio == H->final && H->inicio != NULL) {
        H -> final = NULL;
        H -> inicio = NULL;
    }
    else {
        H -> inicio = H -> inicio -> prox;
    }
    
}

void back(Header *H){
    if(is_empty(H))return printf("No job for Ada?\n");

    printf("%d\n", H -> final -> item);

    if(H -> inicio == H -> final && H->inicio != NULL){
        H -> inicio = NULL;
        H -> final = NULL;
    } else{
        H->final = H->final->ant;
        //H->final->prox = NULL;
    }
}

int toFront(Header *H, Item insert){
    No *temp = malloc(sizeof(No));
    if(temp == NULL)return 0;
    
    temp->item = insert;
    temp->prox = NULL;
    temp->ant = NULL;

    if (H->inicio == NULL && H->final == NULL) {
        H->inicio = temp;
        H->final = H->inicio;
    }
    else {
        H->inicio->ant = temp;
        temp->prox = H->inicio;
        H->inicio = temp;
    }

    return 1;
}

int push_back(Header *H, Item insert){
    No *temp = malloc(sizeof(No));
    if (temp == NULL)return 0;

    temp->item = insert;
    temp->prox = NULL;
    temp->ant = NULL;

    if (H->final == NULL || H->inicio == NULL) {
        H->final = temp;
        H->inicio = H->final;
    }
    else {
        H->final->prox = temp;
        temp->ant = H->final;
        H->final = temp;
    }
    return 1;
}

int main() {
    int instrucoes;
    scanf("%d", &instrucoes);
    Header h;
    initialize_queue(&h);

    int reverse = 0;
    for (int i = 0; i < instrucoes; i++) {
        char instrucao[9]; // trocar pra 10 se der erro
        int queue;
        
        scanf("%s", instrucao);

        if (!strcmp(instrucao, "reverse")) {
            if (reverse == 0) {
                reverse = 1;
            }
            else if (reverse == 1) {
                reverse = 0;
            }
        }

        if (reverse == 0) {
            if (!strcmp(instrucao, "toFront")){
                scanf("%d", &queue);
                toFront(&h, queue);
            }
            if (!strcmp(instrucao, "front")){front(&h);}
            
            if (!strcmp(instrucao, "push_back")){
                scanf("%d", &queue);
                push_back(&h, queue);
            }
            if (!strcmp(instrucao, "back")){back(&h);}

        }
        if (reverse == 1) {
            if (!strcmp(instrucao, "toFront")){
                scanf("%d", &queue);
                push_back(&h, queue);
            }
            if (!strcmp(instrucao, "front")){back(&h);}
            
            if (!strcmp(instrucao, "push_back")){
                scanf("%d", &queue);
                toFront(&h, queue);
            }
            if (!strcmp(instrucao, "back")){front(&h);}

        }

    }
}