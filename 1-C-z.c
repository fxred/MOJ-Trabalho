// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// VERSÃO IMPLEMENTADA COM LISTAS ENCADEADAS

typedef struct node {
    char value[100];
    struct node *next;
} node;

void initializeStack(node *head) {
    strcpy(head->value, "NULL");
    head->next = NULL;
}

node* insertAtBeginning(node *head, char inputNoKeyword[]) { // método PUSH, provavelmente vai precisar de refatoração
    node *temp = malloc(sizeof(node));
    strcpy(temp->value, inputNoKeyword);
    temp->next = head;
    head = temp;
    return head;
}

node* removeAtBeginning(node *head) { // método POP
    if (!(strcmp(head->value, "NULL"))) {
        return head;
    }
    else {
        head = head->next;
        return head;
    }
}

int main() {

    node *head = malloc(sizeof(node));

    initializeStack(head);

    char input[110];

    while (scanf(" %[^\n]", input) == 1) {
        if (!(strcmp(input, "desfazer"))) {
            printf("%s\n", head->value);
            head = removeAtBeginning(head);
        }
        else {
            char inputNoKeyword[strlen(input)-8];
            for (unsigned int i = 8; i < strlen(input)+1; i++) { // +1 é por causa do '\0'
                inputNoKeyword[i-8] = input[i];
            }
            head = insertAtBeginning(head, inputNoKeyword);
            //printf("%s\n", head->value);
        }
        
        
    }

}
