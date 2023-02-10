#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

int main(){
   char leitura[27];

   node *n = malloc(sizeof(node));
   queueInitialize(n);
   
   while (scanf("%s", leitura) == 1) {
    enqueue(n, leitura);
   }

   while (!isEmpty(n)) {
    node *temp = malloc(sizeof(node));
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
}