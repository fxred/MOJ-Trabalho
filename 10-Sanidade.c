#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    long unsigned int curr;
    long unsigned int prev;
    long unsigned int post;
} node;

typedef node* Item;

typedef struct no_st{
    Item item;
    struct no_st *prox;
}No;

typedef struct header_St{
    No *inicio;
    No *final;
    int no_count;
}Header;

int list_initialize(Header *H){
    H -> inicio = NULL;
    H -> final = NULL;
    H -> no_count = 0;

    return 1;
}

int is_empty(Header *H){return H -> no_count == 0;}

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
    Header *h = malloc(sizeof(Header));
    list_initialize(h);
    long unsigned int curr, prev, post;

    long unsigned int firstNode[3];
    long unsigned int lastNode[3];

    scanf("%x %x %x", &firstNode[0], &firstNode[1], &firstNode[2]);
    scanf("%x %x %x", &lastNode[0], &lastNode[1], &lastNode[2]);

    while (scanf("%x %x %x", &curr, &prev, &post) == 3) {
        node *n = malloc(sizeof(node));
        n->curr = curr;
        n->prev = prev;
        n->post = post;
        push_back(h, n);
    }

    //printf("%d %d %d", h->inicio->item->curr, h->inicio->prox->item->curr, h->inicio->prox->prox->item->curr);

    verifySanity(firstNode, lastNode, h);

    //printf("%x %x %x %x\n", h->inicio->item->curr, h->inicio->prox->item->curr, h->inicio->prox->prox->item->curr, h->inicio->prox->prox->prox->item->curr);

}

void verifySanity(long unsigned int firstNode[], long unsigned int lastNode[], Header *h) {
    if (firstNode[2] == lastNode[0]) {
        if (firstNode[0] == lastNode[1]) {
            printf("sana\n");
            return;
        }
        else {
            printf("insana\n");
            return;
        }
    }
    Header *temp = h;

    while (firstNode[2] != temp->inicio->item->curr && temp->inicio == NULL) {
        temp->inicio = temp->inicio->prox;  
    }
    if (firstNode[2] == temp->inicio->item->curr) {
        printf("achei\n");
        firstNode[0] = temp->inicio->item->curr;
        firstNode[1] = temp->inicio->item->prev;
        firstNode[2] = temp->inicio->item->post;
        //printf("%x\n", temp->inicio->item->curr);
        //printf("%x %x %x\n", firstNode[0], firstNode[1], firstNode[2]);
        verifySanity(firstNode, lastNode, h);
    }
    else {
        printf("insana\n");
    }
}