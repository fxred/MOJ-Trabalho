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

int insere_Inicio(Header *H, Item insert){
    No *temp = malloc(sizeof(No));
    if(temp == NULL)return 0;

    temp -> item = insert;
    temp -> prox = H -> inicio;

    H -> inicio = temp;
    H -> no_count = H -> no_count++;
    
    return 1;
}

Item remove_Inicio(Header *H){
    No *remove = H -> inicio;
    Item devolve = remove -> item;
    free(remove);

    H -> inicio = H -> inicio -> prox;
    H -> no_count = H -> no_count--;

    return devolve;
}

int insere_Depois(No *no, Item insert){
    No *new = malloc(sizeof(Item));
    if(new == NULL)return 0;

    new -> item = insert;
    new -> prox = no -> prox;

    no -> prox = new;
    return 1;
}

void insertAtEnd(No *n, Item data) {
    No *temp = malloc(sizeof(node));
    temp->value = data;
    temp->next = NULL;
    node *ptr = n;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = temp;
}