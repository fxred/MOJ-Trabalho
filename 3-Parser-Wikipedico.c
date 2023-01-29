#include <stdio.h>

typedef char Item;

struct Pilha{
    Item *pilha;
    int topo;
    int size;
};

int inicializa_pilha(struct Pilha *P, int s){
    P -> pilha = malloc(sizeof(Item) * s);
    
    if(P -> pilha == NULL){return 0;}

    P -> size = s;
    P -> topo = 0;

    return 1;
}

int empilha(struct Pilha *P, Item insert){
    if(P -> size == P -> topo){return 0;}

    P -> pilha[P -> topo++] = insert;

    return 1;
}

int esta_vazia(struct Pilha *P){return P -> topo == 0;}

void desempilha(struct Pilha *P){P -> topo--;}

Item topo(struct Pilha *P){return P -> pilha[P -> topo - 1];}

void finaliza_pilha(struct Pilha *P){
    free(P -> pilha);

    P->size = 0;
}

void pilha_Contrario(struct Pilha *P){
    if(esta_vazia(P)){return;}
    Item temp = topo(P);
    desempilha(P);

    pilha_Contrario(P);

    empilha(P, temp);
}

int main() {
    int linhas;

    scanf("%d", &linhas);

    struct Pilha p;

    char inputCharEspecial[linhas*100000];

    int contador = 0;

    for (int i = 0; i < linhas; i++) {
        char inputParcial[100001];
        scanf(" %[^\n]", inputParcial);
        for (unsigned int j = 0; j < strlen(inputParcial); j++) {
            if (inputParcial[j] == '/' || inputParcial[j] == '_' || inputParcial[j] == '*') {
                inputCharEspecial[contador++] = inputParcial[j];
            }
        }
    }
    //printf("%d\n", contador);
    if ((contador)%2 == 1) {
        printf("E\n");
    }
    else {
        inicializa_pilha(&p, contador);
        for (int i = 0; i < contador; i++) {
            if (inputCharEspecial[i] == topo(&p)) {
                desempilha(&p);
            }
            else {
                empilha(&p, inputCharEspecial[i]);
            }
        }
        if (esta_vazia(&p)) {
            printf("C\n");
            finaliza_pilha(&p);
        }
        else {
            printf("E\n");
            finaliza_pilha(&p);
        }
    }
}