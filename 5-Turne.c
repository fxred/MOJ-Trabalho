#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char Item[27];

typedef struct no_st{
    Item cidade;
    No *prox;
}No;

typedef struct header_St{
    No *inicio;
    int no_count;
}Header;

int inicializa_Fila(Header *H){
    H -> inicio = NULL;
    H -> no_count = 0;

    return 1;
}

void enfila(Header *H, char *cidade){
    No *new_No = malloc(sizeof(No));
    strcpy(new_No -> cidade, cidade);
    new_No -> prox = NULL;

    if(H -> inicio == NULL){
        H -> inicio = new_No;

    } else{
        No *temp = H;
        while(temp -> prox != NULL){temp = temp -> prox;}

        temp -> prox = new_No;
        H -> no_count++;
    }
}

void desenfila(Header *H){
    No *temp = H -> inicio;
    H -> inicio = temp -> prox;
    temp -> prox == NULL;

    free(temp);
}

No * espia(Header *H){
    return H -> inicio;
    H -> no_count--;
}

int esta_Vazia(Header *H){return H -> no_count == 0;}


/*
typedef struct node {
    char value[27];
    struct node *next;
} node;

node *head;
node *tail;

int queueInitialize(node *n) {
    if (n == NULL) {
        return 0;
    }
    node* head = NULL;
    node* tail = NULL;
    return 1;
}

char * check(node *n) {
    return head->value;
}

void enqueue(node *n, char valueToEnqueue[]) {
    node *temp = malloc(sizeof(node));
    strcpy(temp->value, valueToEnqueue);
    temp->next = NULL;

    if (head == NULL && tail == NULL) {
        head = temp;
        tail = temp;
    }
    else {
        tail->next = temp;
        tail = temp;
    }
}

void dequeue(node *n) {
    if (head != NULL && head != tail) {
        node *temp = head;
        char *value = temp->value;
        head = temp->next;
        free(temp);
    }
    else if (head == tail && head != NULL && tail != NULL) {
        node *temp = head;
        char *data = head->value;
        head = NULL;
        tail = NULL;
        free(temp);
    }
    else {
        printf("You cannot remove a node from an empty list.\n");
    }
}

int isEmpty(node *n) {
    return head == NULL && tail == NULL;
}
*/

int main(){
/*
   node *n = malloc(sizeof(node));
   queueInitialize(n);
   
   while (scanf("%s", leitura) == 1) {
    enqueue(n, leitura);
   }

   while (!isEmpty(n)) {
    node *temp;
    strcpy(temp->value, check(n));
    
    printf("%s\n", temp->value);
    dequeue(n);
    if (isEmpty(n)) {
        break;
    }
    
    if (temp->value[strlen(temp->value) - 1] == check(n)[0]+32) {
        enqueue(n, check(n));
        dequeue(n);
    }
   }

   */
    
    char leitura[27];
    Header H;
    inicializa_Fila(&H);

    while(scanf("%s", leitura) == 1 && leitura != EOF){enfila(&H, leitura);}

    while(!esta_Vazia(&H)){
        No *temp = espia(&H);
        printf("%s\n", temp->cidade);
        desenfila(&H);

        if(temp -> cidade[strlen(temp -> cidade) - 1] == (espia(&H) -> cidade[0] + 32)){
            enfila(&H, espia(&H));
            desenfila(&H);
        }
    }
}