#include <stdio.h>

struct valueIdentifiers {
    int identifier1;
    int value;
    int identifier2;
};

int main() {
    int iterations;
    scanf("%d", &iterations);

    struct valueIdentifiers vi[iterations];
    
    for (int i = 0; i < iterations; i++) {
        scanf("%d %d %d", &vi[i].identifier1, &vi[i].value, &vi[i].identifier2);
    }
    printf("%d\n", vi[0].value);

    printValues(vi, 0, iterations);

}

void printValues(struct valueIdentifiers vi[], int startIndex, int iterations) {

    int stopIndex;

    if (vi[startIndex].identifier2 == -1) {
        return;
    }

    for (int i = 0; i < iterations; i++) {
        if (vi[i].identifier1 == vi[startIndex].identifier2) {
            printf("%d\n", vi[i].value);
            stopIndex = i;
            break;
        }
    }

    printValues(vi, stopIndex, iterations);

}