#include <stdio.h>

int main()
{
    int tabuleiro[10][10];
    char letras[10] = {'A','B','C','D','E','F','G','H','I','J'};
    int linha, coluna;
    char colunaLetra;

    // Inicializando o tabuleiro com 0
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Navio Horizontal
    printf("Escolha a linha para o navio horizontal (1-10): ");
    scanf("%d", &linha);
    linha--;

    printf("Escolha a coluna inicial para o navio horizontal (A-H): ");
    scanf(" %c", &colunaLetra);
    coluna = colunaLetra - 'A';

    for (int i = 0; i < 3; i++) {
        tabuleiro[linha][coluna + i] = 3;
    }

    // Navio Vertical
    printf("Escolha a linha inicial para o navio vertical (1-8): ");
    scanf("%d", &linha);
    linha--;

    printf("Escolha a coluna para o navio vertical (A-J): ");
    scanf(" %c", &colunaLetra);
    coluna = colunaLetra - 'A';

    for (int i = 0; i < 3; i++) {
        tabuleiro[linha + i][coluna] = 4;
    }

    // Navio Diagonal Principal (\)
    printf("Escolha a linha inicial para o navio diagonal principal (1-8): ");
    scanf("%d", &linha);
    linha--;

    printf("Escolha a coluna inicial para o navio diagonal principal (A-H): ");
    scanf(" %c", &colunaLetra);
    coluna = colunaLetra - 'A';

    for (int i = 0; i < 3; i++) {
        tabuleiro[linha + i][coluna + i] = 5;
    }

    // Navio Diagonal  (/)
    printf("Escolha a linha inicial para o navio diagonal secundaria (1-8): ");
    scanf("%d", &linha);
    linha--;

    printf("Escolha a coluna inicial para o navio diagonal secundaria (C-J): ");
    scanf(" %c", &colunaLetra);
    coluna = colunaLetra - 'A';

    for (int i = 0; i < 3; i++) {
        tabuleiro[linha + i][coluna - i] = 6;
    }

    // Imprimindo o cabeçalho (letras)
    printf("\n  ");
    for (int i = 0; i < 10; i++) {
        printf(" %c", letras[i]);
    }
    printf("\n");

    // Imprimindo o tabuleiro com números
    for (int i = 0; i < 10; i++) {
        printf("%2d", i + 1);  // Números da linha
        for (int j = 0; j < 10; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
