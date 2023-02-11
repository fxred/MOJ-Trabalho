#include <stdio.h>
#include <stdlib.h>

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
    while(aux -> prox != H -> final){aux = aux -> prox;}
    H -> final = aux;
    H -> no_count--;
}

int toFront(Header *H, Item insert){
    No *temp = malloc(sizeof(No));
    if(temp == NULL)return 0;
    temp -> item = insert;

    temp -> prox = H -> inicio;
    
    H -> inicio = temp;
    H -> no_count++;

    return 1;
}

int push_back(Header *H, Item insert){
    No *temp = malloc(sizeof(No));
    if(temp == NULL)return 0;
    temp -> item = insert;

    temp -> prox = NULL;
    
    H -> final -> prox = temp;
    H -> final = temp;
    H -> no_count++;

    return 1;
}