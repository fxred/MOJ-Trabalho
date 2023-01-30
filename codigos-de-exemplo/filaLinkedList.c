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
        int data = head->value;
        head = NULL;
        tail = NULL;
        free(temp);
        return data;
    }
    else {
        printf("You cannot remove a node from an empty list.\n");
    }
}

int isEmpty(node *n) {
    return head == NULL && tail == NULL;
}

void reversePrint(node *n) {
    if (isEmpty(n)) {
        return;
    }
    int data = dequeue(n);
    printf("%d ", data);
    reversePrint(n);
    enqueue(n, data);
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
    dequeue(n);
    dequeue(n);
    dequeue(n);
    enqueue(n, 1);
    enqueue(n, 2);
    enqueue(n, 3);
    printf("%d %d %d\n", head->next->next->value, head->next->value, head->value);
    reversePrint(n);
}