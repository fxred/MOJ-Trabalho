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

    while (scanf(" %[^\n]", input) == 1) {
        if (strlen(input) == 8) {
            printf("1");
            // pop
            
        }
        else {
            char inputNoKeyword[strlen(input)-8];
            for (unsigned int i = 8; i < strlen(input)+1; i++) { // +1 é por causa do '\0'
                inputNoKeyword[i-8] = input[i];
            }
            insertAtBeginning(head, inputNoKeyword);
        }
        printf("%s\n", head->value);
    }

}
