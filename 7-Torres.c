#include <stdio.h>

int main(){
    int linhas, colunas, contador = 0;
    scanf("%d %d", &linhas, &colunas);

    char parque[linhas][colunas];
    char caractere;

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            scanf("%c", &caractere);
            parque[i][j] = caractere;
            if(caractere == 't'){contador++;}
        }
    }

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            printf("%c", parque[i][j]);
        }
    }
    
    printf("\n");
    printf("%d\n", contador);
}