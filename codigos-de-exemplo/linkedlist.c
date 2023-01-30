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
    n->value = 0;
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
    if (position == 0) {
        insertAtBeginning(n, data);
    }
    else {
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
    

}

int main() {
    node *n = malloc(sizeof(node));
    initializeLinkedList(n);

    insertAtEnd(n, 3);
    n = insertAtBeginning(n, 5);
    
    n = insertAtGivenPosition(n, 2, 6);

    printLinkedList(n);

}