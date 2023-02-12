#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char Item[4194305];

typedef struct no_st{
    Item palavra;
    struct no_st *prox;
}No;

typedef struct Header{
    No *inicio;
    No *final;
    int no_count;
}Header;

int inicializa_Fila(Header *H){
    H -> inicio = NULL;
    H -> final = NULL;
    H -> no_count = 0;

    return 1;
}

int esta_Vazia(Header *H){return H -> no_count == 0;}

int enfila(Header *H, Item insert){
    No *temp = malloc(sizeof(No));
    if(temp == NULL) return 0;

    strcpy(temp -> palavra, insert);
    temp -> prox = NULL;

    if(H -> inicio == NULL){
        H -> inicio = temp;
        H -> final = temp;
        H -> no_count++;

        return 1;
    }

    H -> final -> prox = temp;
    H -> final = temp;
    H -> no_count++;

    return 1;
}

Item * espia(Header *H){return H -> inicio -> palavra;}

Item * procura(Header *H){
    H -> no_count--;
    return H -> final -> palavra;
}

void desenfila(Header *H){
    No *temp = H -> inicio;

    H -> inicio = temp -> prox;
    H -> no_count--;

    free(temp);
}

void finaliza_Fila(Header *H){
    H -> no_count = 0;
    free(H);
}

int main(){
    Item palavra;

    Header H;
    inicializa_Fila(&H);
    
    while(scanf(" %s", palavra) == 1 && palavra != EOF){enfila(&H, palavra);}

    Item *string = procura(&H);
    int contador;
    while(!esta_Vazia(&H)){
        contador = 0;
        Item *temp = espia(&H);
    }
}