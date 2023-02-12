#include <stdio.h>
#include <string.h>

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

void reverseQueue(node *n) {
    node *prev = malloc(sizeof(node));
    prev = NULL;
    node *curr = head;
    node *post = head->next;

    while (curr->next != NULL) {
        post = curr->next;
        curr->next = prev;
        prev = curr;
        curr = post;
    }
    curr->next = prev;
    node *temp = head;
    head = tail;
    tail = temp;
}

int main() {
    int repeats;
    scanf("%d", &repeats);

    for (int i = 0; i < repeats; i++) {
        node *n = malloc(sizeof(node));
        queueInitialize(n);
        char input[100000];
        scanf("%s", input);
        for (int i = 0; i < strlen(input); i++) {
            
        }
    }

    queueInitialize(n);
    enqueue(n, 1);
    enqueue(n, 2);
    enqueue(n, 3);
    enqueue(n, 4);
    printf("%d %d %d %d\n", head->value, head->next->value, head->next->next->value, head->next->next->next->value);
    reverseQueue(n);
    printf("%d %d %d %d\n", head->value, head->next->value, head->next->next->value, head->next->next->next->value);
}