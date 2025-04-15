#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Dimensões do tabuleiro
    const int Tamanho_tabuleiro_X = 8;
    const int Tamanho_tabuleiro_Y = 8;

    // Contador para loops
    int contador = 0;

    // =
    // Movimento da TORRE
    
    // Move 5 casas para a direita
    for (int movimentacao = 0; movimentacao < 5; movimentacao++) {
        printf("Torre: Direita\n");
    }
    printf("\n");

   
    // Movimento do BISPo
    // Move 5 vezes em diagonal (cima + direita)
    contador = 0;
    while (contador < 5) {
        contador++;
        printf("Bispo: Cima\n");
        printf("Bispo: Direita\n");
    }
    printf("\n");

   
    // Movimento da RAINHA
    // Move 8 casas para a esquerda
    contador = 0;
    do {
        contador++;
        printf("Rainha: Esquerda\n");
    } while (contador < 8);
    printf("\n");

    // Movimento do CAVALO
    // Cavalo se move em "L": 2 para baixo e 1 para a esquerda
    // Loop externo (for) controla movimentos verticais
    // Loop interno (while) controla movimento horizontal

    const int movimentos_cavalo = 3; // número de movimentos em "L" que o cavalo fará

    for (int i = 0; i < movimentos_cavalo; i++) {
        int passo_vertical = 0;

        // Move duas casas para baixo
        while (passo_vertical < 2) {
            printf("Cavalo: Baixo\n");
            passo_vertical++;
        }

        // Move uma casa para a esquerda
        printf("Cavalo: Esquerda\n");

        // Linha em branco entre os movimentos do cavalo
        printf("\n");
    }

    return 0;
}
