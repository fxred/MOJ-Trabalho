#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} node;

int initializeLinkedList(node *n) {
    if (n == NULL) {
        return 0;
    }
    n->value = NULL;
    n->next = NULL;
    return 1;
}

node * insertAtBeginning(node *n, int data) {
    node *temp = malloc(sizeof(node));
    temp->value = data;
    temp->next = n;
    n = temp;
}

node * insertAtEnd(node *n, int data) {
    node *temp = malloc(sizeof(node));
    temp->value = data;
    temp->next = NULL;
    node *ptr = n;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = temp;
}

void printLinkedList(node *n) {
    node *temp = n;
    while (temp != NULL) {
        printf("%d\n", temp->value);
        temp = temp->next;
    }
}

node * insertAtGivenPosition(node *n, int position, int data) {
    // if (position == 0) {
    //     insertAtBeginning(n, data);
    // }
    node *temp = malloc(sizeof(node));
    temp->value = data;
    node *ptrFirst = n;
    node *ptrLast = n;
    for (int i = 0; i < position; i++) {
        ptrLast = ptrLast->next;
        if (i > 0) {
            ptrFirst = ptrFirst->next;
        }
    }
    if (ptrLast->next != NULL) {
        temp->next = ptrLast;
        ptrFirst->next = temp;
    }
    else if (ptrLast->next == NULL) {
        insertAtEnd(n, data);
    }
        
    

}

int main() {
    node *n = malloc(sizeof(node));
    initializeLinkedList(n);
    printf("%d\n", n->value);

    // insertAtEnd(n, 3);
    // //n = insertAtBeginning(n, 5);
    
    // n = insertAtGivenPosition(n, 2, 6);

    // printLinkedList(n);
    int opcao, placa, count = 0;

    while (scanf("%d %d", &opcao, &placa) == 2) {
        if (opcao == 1) {
            if (count == 0) {
                insertAtEnd(n, placa);
                printf("%d\n", n->value);
            }
            else {
                node *aux = n;
                while (placa <= aux->value && aux->value == NULL) {
                   aux = aux->next; 
                   count++;
                }
                if (aux->value == NULL) {
                    insertAtEnd(n, placa);
                }
                else if (placa <= aux->value) {
                    insertAtGivenPosition(n, count, placa);
                }
            }
        }
        if (opcao == 2) {
            int range = placa;
            node *aux = n;
            for (int i = 0; i < range; i++) {
                printf("%d ", aux->value);
                aux = aux->next;
            }
        }
    }
    printf("%d %d %d\n", n->value, n->next->value, n->next->next->value);

}