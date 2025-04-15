#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Movimentação da Torre para a esquerda
    for (int i = 0; i < 5; i++)
    {
        printf("Torre: Esquerda\n");
    }

    // Movimentação do Bispo na diagonal (Cima, Direita)
    for (int i = 0; i < 5; i++)
    {
        printf("Bispo: Cima, Direita\n");
    }

    // Movimentação da Rainha para a esquerda
    for (int i = 0; i < 8; i++)
    {
        printf("Rainha: Esquerda\n");
    }

    // Linha em branco para separar os movimentos anteriores do Cavalo
    printf("\n");

    // Movimentação do Cavalo (duas casas para baixo e uma para a esquerda)
    const int MOV_BAIXO = 2;
    const int MOV_ESQUERDA = 1;

    for (int i = 0; i < MOV_BAIXO; i++)
    {
        printf("Cavalo: Baixo\n");
    }

    int j = 0;
    while (j < MOV_ESQUERDA)
    {
        printf("Cavalo: Esquerda\n");
        j++;
    }

    return 0;
}
