/*
    No código final enviado existia um merge sort, mas como nao foi usado, foi retirado
*/

#include <stdio.h>
#include <stdlib.h>

typedef int Item;

#define Key(A) (A)
#define less(A, B) (Key(A) < Key(B))
#define lessequal(A, B) (Key(A) <= Key(B))
#define exch(A, B) {Item t = A; A = B; B = t;}

void InsertionSortSentinela(Item *vetor, int l, int r){
    for(int i = r; i > l; i--){
        if(less(vetor[i], vetor[(i - 1)])){
            exch(vetor[i], vetor[(i - 1)]);
        }
    }

    for(int i = (l + 2); i <= r; i++){
        int j = i;
        Item temp = vetor[j];
        while(less(temp, vetor[(j - 1)])){
            vetor[j] = vetor[j - 1];
            j--;
        }

        vetor[j] = temp;
    }


}

void Merge(Item *vetor, int l, int r1, int r2){
    Item *vetor_aux = malloc(sizeof(Item) * (r2 - l + 1));
    int k = 0;

    int i = l;
    int j = (r1 + 1);

    while(i <= r1 && j <= r2){
        if(lessequal(vetor[i], vetor[j])){vetor_aux[k++] = vetor[i++];}
        else{vetor_aux[k++] = vetor[j++];}
    }

    while(i <= r1){vetor_aux[k++] = vetor[i++];}
    while(j <= r2){vetor_aux[k++] = vetor[j++];}

    k = 0;

    for(int i = l; i <= r2; i++){vetor[i] = vetor_aux[k++];}

    free(vetor_aux);
}


void insere(int *vetor, int placa){
    if(vetor[99] > placa){vetor[99] = placa;}
    Merge(vetor, 0, 98, 99);
}

int main(){
    int placas[100];
    int contador = 0;

    int op, placa;

     while(scanf("%d", &op) == 1){
        if(op == 1){
            scanf("%d", &placa);
            if(contador > 99){insere(&placas, placa);}
            else{
                placas[contador++] = placa;
                InsertionSortSentinela(&placas, 0, (contador - 1));
            }
        }
        else if(op == 2){
            scanf("%d", &placa);
            for(int i = 0; i < placa; i++){
                if(i == (placa - 1)){printf("%d\n", placas[i]);}
                else {printf("%d ", placas[i]);}
            }
        }
    }
}