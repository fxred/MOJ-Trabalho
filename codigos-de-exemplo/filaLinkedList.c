#include <stdio.h>

typedef struct node {
    int value;
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

int check(node *n) {
    return head->value;
}

void enqueue(node *n, int valueToEnqueue) {
    node *temp = malloc(sizeof(node));
    temp->value = valueToEnqueue;
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

int dequeue(node *n) {
    if (head != NULL && head != tail) {
        node *temp = head;
        int value = temp->value;
        head = temp->next;
        free(temp);
        return value;
    }
    else if (head == tail && head != NULL && tail != NULL) {
        node *temp = head;
        head = NULL;
        tail = NULL;
        free(temp);
    }
    else {
        printf("You cannot remove a node from an empty list.\n");
    }
}

int main() {
    node *n = malloc(sizeof(node));
    queueInitialize(n);
    enqueue(n, 1);
    enqueue(n, 2);
    printf("%d\n", head->value);
    printf("%d\n", tail->value);
    enqueue(n, dequeue(n));
    printf("%d\n", head->value);
    printf("%d\n", tail->value);
    dequeue(n);
    dequeue(n);
    enqueue(n, 1);
    enqueue(n, 2);
    while (1) {
        enqueue(n, dequeue(n));
        printf("%d\n", check(n));
    }
}