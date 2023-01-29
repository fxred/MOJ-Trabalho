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

void insertAtBeginning(node *head, char inputNoKeyword[]) { // método PUSH, provavelmente vai precisar de refatoração
    if (!(strcmp(head->value, "NULL"))) {
        strcpy(head->value, inputNoKeyword);
    }
    else {
        node *temp = head;
        strcpy(head->value, inputNoKeyword);
        head->next = temp;
    }
}

// void removeAtBeginning(node *head) { // método POP
//     if (head->value == "NULL") {
//         head->value = inputNoKeyword;
//     }
//     else {

//     }
// }

int main() {

    node *head = malloc(sizeof(node));

    initializeStack(head);

    char input[100];

    scanf("%[^\n]", input);

    if (strlen(input) == 8) {
        printf("1");
        // TODO: implementar o método pop da pilha
    }
    else {
        char inputNoKeyword[strlen(input)-8];
        for (unsigned int i = 8; i < strlen(input)+1; i++) { // +1 é por causa do '\0'
            inputNoKeyword[i-8] = input[i];
        }
        // TODO: implementar o método push da pilha
        insertAtBeginning(head, inputNoKeyword);
    }
    printf("%s", head->value);
}
