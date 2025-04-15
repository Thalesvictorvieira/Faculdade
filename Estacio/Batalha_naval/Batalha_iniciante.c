#include <stdio.h>

int main()
{
    int tabuleiro[10][10];
    char letras[10] = {'A','B','C','D','E','F','G','H','I','J'};

//CRIAÇÃO DO TABULEIRO
    // Inicializando o tabuleiro com 0
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }




    //CRIAÇÃO DO NAVIO
    int linha, coluna, orientacao;
    //Pega a linha do usuário
    printf("Escolha a LINHA para o navio 1 - 10: ");
    scanf("%d", &linha);
    linha--; // Tirando 1 do valor começa em  0

    //Pega a coluna do usuário
    printf("Escolha a COLUNA para o navio A - J: ");
    scanf(" %d", &coluna);
    coluna--; // Tirando 1 do valor começa em  0


    //posicionamento do navio horizontal
    for (int i = 0; i < 3; i++)
    {
        tabuleiro[linha][coluna+i] =3;
    }

    //posicionamento do navio vertical
printf("Escolha a LINHA para o navio 1 - 10: ");
    scanf("%d", &linha);
    linha--; 

    printf("Escolha a COLUNA para o navio 1-8: ");
    scanf(" %d", &coluna);
    coluna--;

    //colocando o navio vertical
    for (int i = 0; i < 3; i++)
    {
        tabuleiro[linha+i][coluna] =3;
    }

//Escrevendo o tabuleiro na tela
    printf("\n ");
    for(int i =0; i <10; i++)
    {
        printf(" %c", letras[i]);
    }
    printf("\n");

    for (int i = 0; i < 10; i++)
    {
        printf("%2d", i +1); //imprime a linha
        for (int j = 0; j < 10; j++)
        {
            printf(" %d", tabuleiro[i][j]); //imprime o tabuleiro
        }
        printf("\n");
    }
    return 0;
}
