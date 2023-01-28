#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[100];

    scanf("%[^\n]", input);

    if (strlen(input) == 8) {
        printf("1");
        // TODO: implementar o método pop da pilha
    }
    else {
        char inputNoKeyword[strlen(input)-8];
        for (int i = 8; i < strlen(input)+1; i++) { // +1 é por causa do '\0'
            inputNoKeyword[i-8] = input[i];
        }
        // TODO: implementar o método push da pilha
    }
}