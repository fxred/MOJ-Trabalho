#include <stdio.h>

typedef struct node {
    long unsigned int curr;
    long unsigned int prev;
    long unsigned int post;
} node;

node n[100000];

void merge(node *n, int l, int m, int r) {
    //int subVet1[m-l+1], subVet2[r-m];
    //char * subVetChar1[m-l+1], subVetChar2[r-m];
    node tmp[m-l+1], tmp2[r-m];

    for (int i = 0; i < m-l+1; i++) {
        tmp[i] = n[l+i];
    }

    for (int j = 0; j < r-m; j++) {
        tmp2[j] = n[m+1+j];
    }

    int i = 0, j = 0, k = l;

    while (i < m-l+1 && j < r-m) {
        if (tmp[i].curr > tmp2[j].curr) {
            n[k++] = tmp2[j++];
        }
        else {
            n[k++] = tmp[i++];
        }
    }

    while (i < m-l+1) {
        n[k++] = tmp[i++];
    }
    while (j < r-m) {
        n[k++] = tmp2[j++];
    }
}

void mergeSort(node *n, int l, int r) {
    if (r > l) {
        int m = (r+l)/2;
        mergeSort(n, l, m);
        mergeSort(n, m+1, r);
        merge(n, l, m, r);
    }
}

int binarySearch(node *n, int l, int r, long unsigned int find) {
    if (r >= l) {
        int m = (r+l)/2;
        if (n[m].curr == find) {
            return m;
        }
        else if (n[m].curr > find) {
            binarySearch(n, l, m-1, find);
        }
        else if (n[m].curr < find) {
            binarySearch(n, m+1, r, find);
        }
    }
    else {
        return -1;
    }
}

void checkSanity(long unsigned int * firstNode, long unsigned int * lastNode, node *n, int size) {
    if (firstNode[2] == lastNode[0]) {
        if (firstNode[0] == lastNode[1]) {
            printf("sana\n");
            return;
        }
        else {
            printf("insana\n");
            return;
        }
    }
    //No *temp = h->inicio;

    int index;

    index = binarySearch(n, 0, size, firstNode[2]);

    printf("%d\n", index);
    //printf("%d\n", index);

    if (index == -1) {
        printf("insana\n");
        return;
    }

    else if (firstNode[2] == n[index].curr) {
        firstNode[0] = n[index].curr;
        firstNode[1] = n[index].prev;
        firstNode[2] = n[index].post;
        checkSanity(firstNode, lastNode, n, size);
    }

}


int main() {

    long unsigned int curr, prev, post;
    long unsigned int firstNode[3];
    long unsigned int lastNode[3];
    scanf("%lx %lx %lx", &firstNode[0], &firstNode[1], &firstNode[2]);
    scanf("%lx %lx %lx", &lastNode[0], &lastNode[1], &lastNode[2]);

    int i = 0;

    while (scanf("%lx %lx %lx", &curr, &prev, &post) == 3) {
        n[i].curr = curr;
        n[i].prev = prev;
        n[i++].post = post;
    }

    //size_t n = sizeof(n)/sizeof(n[0]);

    mergeSort(n, 0, i-1);

    for (int j = 0; j < i; j++) {
        printf("%lx %lx %lx\n", n[j].curr, n[j].prev, n[j].post);
    }
    checkSanity(firstNode, lastNode, n, i);
}

