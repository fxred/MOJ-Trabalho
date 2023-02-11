#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Item;

typedef struct no_st{
    Item item;
    struct no_st *prox;
}No;

typedef struct header_St{
    No *inicio;
    No *final;
    int no_count;
}Header;

void reverseQueue(Header *H) {
    No *prev = malloc(sizeof(No));
    prev = NULL;
    No *curr = H;
    No *post = H -> inicio;

    while (curr -> prox != NULL) {
        post = curr -> prox;
        curr -> prox = prev;
        prev = curr;
        curr = post;
    }

    curr -> prox = prev;
    No *temp = H -> inicio;
    H -> inicio = H -> final;
    H -> final = temp;
}

int initialize_queue(Header *H){
    H -> inicio = NULL;
    H -> final = NULL;
    H -> no_count = 0;

    return 1;
}

int is_empty(Header *H){return H -> no_count == 0;}

void front(Header *H){
    if(is_empty(H))return printf("No job for Ada?\n");

    printf("%d\n", H -> inicio -> item);
    H -> inicio = H -> inicio -> prox;
    H -> no_count--;
}

void back(Header *H){
    if(is_empty(H))return printf("No job for Ada?\n");

    printf("%d\n", H -> final -> item);

    No *aux = H -> inicio;
    if(aux == H -> final){
        H -> inicio = NULL;
        H -> final = NULL;
        H -> no_count--;
    } else{
        while(aux -> prox != H -> final){aux = aux -> prox;}
        H -> final = aux;
        H -> no_count--;
    }
}

int toFront(Header *H, Item insert){
    No *temp = malloc(sizeof(No));
    if(temp == NULL)return 0;
    temp -> item = insert;

    temp -> prox = H -> inicio;
    
    H -> inicio = temp;

    if(H -> final == NULL){H -> final = H -> inicio;}
    H -> no_count++;

    return 1;
}

int push_back(Header *H, Item insert){
    No *temp = malloc(sizeof(No));
    if(temp == NULL)return 0;

    temp -> item = insert;
    temp -> prox = NULL;
    
    if(H -> final == NULL){H -> final = temp;} 
    else{
        H -> final -> prox = temp;
        H -> final = temp;
    }

    if(H -> inicio == NULL){H -> inicio = H -> final;}
    H -> no_count++;

    return 1;
}

int main() {
    int instrucoes;
    scanf("%d", &instrucoes);
    Header h;
    initialize_queue(&h);

    for (int i = 0; i < instrucoes; i++) {
        char instrucao[10];
        int queue;
        scanf("%s", instrucao);

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

        if (!strcmp(instrucao, "reverse")){reverseQueue(&h);}
    }
}