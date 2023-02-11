#include <stdio.h>

typedef struct torre {
    int posicao[2];
    int tamanho;
} torre;

int main(){
    int linhas, colunas, contador = 0;
    scanf("%d %d", &linhas, &colunas);

    char parque[linhas][colunas];
    char caractere;

<<<<<<< HEAD
    char posicoes[linhas*colunas][2];
=======
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            scanf(" %c", &caractere);
            parque[i][j] = caractere;
            if(caractere == 't'){contador++;}
        }
    }
>>>>>>> 9a2ec1f (Teste)

    for(int i = 0; i < contador; i++){
        
    }

    /*for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            scanf(" %c", &caractere);
            parque[i][j] = caractere;
            if (caractere == 't') {
                posicoes[contador][0] = i;
                posicoes[contador][1] = j;
                contador++;
            }
        }
<<<<<<< HEAD
    }
    
    torre t[contador-1];

    for (int i = 0; i < contador; i++) {
        int tamanho;
        scanf("%d", &tamanho);
        t[i].posicao[0] = posicoes[i][0];
        t[i].posicao[1] = posicoes[i][1];
        t[i].tamanho = tamanho;
    }
    // for (int i = 0; i < contador; i++) {
    //     printf("%d %d %d\n", t[i].posicao[0], t[i].posicao[1], t[i].tamanho);
    // }

    for (int i = 0; i < contador; i++) {

        int comecoLinha = t[i].posicao[0] - t[i].tamanho;
        int comecoColuna = t[i].posicao[1] - t[i].tamanho;

        if (comecoLinha < 0) {
            comecoLinha = 0;
        }

        if (comecoColuna < 0) {
            comecoColuna = 0;
        }

        if (comecoLinha > linhas) {
            comecoLinha = linhas;
        }

        if (comecoColuna > colunas) {
            comecoColuna = colunas;
        }

        for (int i = comecoLinha; i < comecoLinha+3; i++) {

            if (comecoLinha <= linhas && comecoLinha >= 0) {

                for (int j = comecoColuna; j < comecoColuna+3; j++) {

                    if (comecoColuna <= colunas && comecoColuna >= 0) {

                        parque[i][j] = '.';
                        
                    }
                }
            }
        }


        

        // 1,2, tamanho 1 -> 0,1
        // 2,5, tamanho 2 -> 0,3
        
    }


    // for(int i = 0; i < linhas; i++){
    //     for(int j = 0; j < colunas; j++){
    //         printf("%c", parque[i][j]);
    //     }
    //     printf("\n");
    // }

    // printf("%d\n", contador);

    // for (int i = 0; i < contador; i++) {

    // }
=======
        printf("\n");
    }*/
>>>>>>> 9a2ec1f (Teste)
}