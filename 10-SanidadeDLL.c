#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    long unsigned int curr;
    long unsigned int prev;
    long unsigned int post;
} node;

typedef node* Item;

typedef struct no_st{
    Item item;
    struct no_st *prox;
    struct no_st *ant;
}No;

typedef struct header_St{
    No *inicio;
    No *final;
}Header;

void list_initialize(Header *H){
    H -> inicio = NULL;
    H -> final = NULL;
}

void push_back(Header *H, Item insert){
    No *temp = malloc(sizeof(No));
    temp->item = insert;
    temp->prox = NULL;

    if (H->final == NULL || H->inicio == NULL) {
        temp->ant = NULL;
        H->final = temp;
        H->inicio = H->final;
    }
    else {
        H->final->prox = temp;
        temp->ant = H->final;
        H->final = temp;
    }
    //free(temp);
}

void checkSanity(long unsigned int * firstNode, long unsigned int * lastNode, Header *h) {
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
    No *temp = h->inicio;

    while (firstNode[2] != temp->item->curr && temp->prox != NULL) {
        temp = temp->prox;
    }
    if (firstNode[2] == temp->item->curr) {
        firstNode[0] = temp->item->curr;
        firstNode[1] = temp->item->prev;
        firstNode[2] = temp->item->post;

        if (temp->prox != NULL) {
            if (temp->ant != NULL) {
                temp->ant->prox = temp->prox;
                temp->prox = NULL;
                temp->ant->prox->ant = temp->ant;
                temp->ant = NULL;
            }
        }
        // while (temp != NULL) {
        //     No *prox = temp->prox;
        //     free(temp->item);
        //     free(temp);
        //     temp->prox;
        // }

        checkSanity(firstNode, lastNode, h);
    }
    else if (temp->prox == NULL) {
        printf("insana\n");
        return;
    }
}

int main() {
    Header *h = malloc(sizeof(Header));
    list_initialize(h);
    long unsigned int curr, prev, post;

    long unsigned int firstNode[3];
    long unsigned int lastNode[3];

    scanf("%lx %lx %lx", &firstNode[0], &firstNode[1], &firstNode[2]);
    scanf("%lx %lx %lx", &lastNode[0], &lastNode[1], &lastNode[2]);

    while (scanf("%lx %lx %lx", &curr, &prev, &post) == 3) {
        node *n = malloc(sizeof(node));
        n->curr = curr;
        n->prev = prev;
        n->post = post;
        push_back(h, n);
    }

    checkSanity(firstNode, lastNode, h);

}