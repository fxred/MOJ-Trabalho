#include <stdio.h>

typedef int Item;

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

int esta_vazia_pilha(struct Pilha *P){return P -> topo == 0;}

void desempilha(struct Pilha *P){P -> topo--;}

Item topo(struct Pilha *P){return P -> pilha[P -> topo - 1];}

int finaliza_pilha(struct Pilha *P){
    free(P -> pilha);

    if(P -> pilha == NULL){return 1;}
    else{return 0;}
}

struct Fila {
    Item *fila;
    int size;
    int ocupados;
    int inicio;
    int fim;
};

int inicializa_fila(struct Fila *F, int s){
    F -> size = s;
    F -> fila = malloc(sizeof(Item) * s);

    if(F -> fila == NULL){return 0;}

    F -> ocupados = 0;
    F -> inicio = -1;
    F -> fim = 0;

    return 1;
}

int emfila(struct Fila *F, Item insert){
    if(F -> fim == F -> size){return 0;}

    F -> fila[F -> fim++] = insert;
    F -> fim = (F -> fim % F -> size);
    F -> ocupados++;
    return 1;
}

int esta_vazia_fila(struct Fila *F){return F -> ocupados == 0;}

void desemfila(struct Fila *F){
    F -> ocupados--;
    F -> inicio = ((F -> inicio + 1) % F -> size);
}

Item espia(struct Fila *F){return F -> fila[(F -> inicio + 1) % F -> size];}

int finaliza_fila(struct Fila *F){
    free(F -> fila);
    F -> size = 0;
}

int main() {
    int repeticoes, truck;
    while (1) {
        scanf("%d", &repeticoes);
        if (repeticoes == 0) {
            break;
        }
        struct Fila f;
        inicializa_fila(&f, repeticoes);
        for (int i = 0; i < repeticoes; i++) {
            scanf("%d", &truck);
            emfila(&f, truck);
        }
        struct Pilha p;
        inicializa_pilha(&p, repeticoes);

        int i = 1;
        while (i <= repeticoes) {
            while (espia(&f) != i) {
                //printf("%d %d\n", espia(&f), i);
                empilha(&p, espia(&f));
                desemfila(&f); 
            }
            desemfila(&f);
            while (topo(&p) == ++i) {
                desempilha(&p);
            }
        }
        //printf("%d\n", topo(&p));
        if (esta_vazia_pilha(&p)) {
            printf("yes\n");
        }
        else {
            printf("no\n");
        }
    }
}