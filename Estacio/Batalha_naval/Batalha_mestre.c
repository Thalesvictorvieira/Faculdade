#include <stdio.h>

#define TAM 10
#define HABILIDADE 5

void imprimirTabuleiro(int tabuleiro[TAM][TAM], char letras[TAM]) {
    printf("\n  ");
    for (int i = 0; i < TAM; i++) {
        printf(" %d", i);
    }
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == 0)
                printf(" 0");
            else if (tabuleiro[i][j] == 1)
                printf(" 1");
            else if (tabuleiro[i][j] == 2)
                printf(" 2");
            else if (tabuleiro[i][j] == 3)
                printf(" 3");
        }
        printf("\n");
    }
}

//FUncao que coloca a habilidade no tabuleiro
void sobreporHabilidade(int tabuleiro[TAM][TAM], int habilidade[5][5], int x, int y, int valor) {
    int vari = HABILIDADE / 2;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int nx = x + i - vari;
            int ny = y + j - vari;
            if (nx >= 0 && nx < TAM && ny >= 0 && ny < TAM && habilidade[i][j] == 1) {
                tabuleiro[nx][ny] = valor;
            }
        }
    }
}

//Cria o cone
void preencherHabilidadeCone(int habilidade[5][5]) {
    int matriz[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            habilidade[i][j] = matriz[i][j];
}

//cria a cruz
void preencherHabilidadeCruz(int habilidade[5][5]) {
    int matriz[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            habilidade[i][j] = matriz[i][j];
}


//cria o octaedro
void preencherHabilidadeOctaedro(int habilidade[5][5]) {
    int matriz[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            habilidade[i][j] = matriz[i][j];
}

int main() {
    int tabuleiro[TAM][TAM] = {0};
    char letras[TAM] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
    int habilidade[5][5];


                                            //X,Y formato da abilidade
    preencherHabilidadeCone(habilidade);
    sobreporHabilidade(tabuleiro, habilidade, 2, 2, 1);

    preencherHabilidadeCruz(habilidade);
    sobreporHabilidade(tabuleiro, habilidade, 7, 2, 3);

    preencherHabilidadeOctaedro(habilidade);
    sobreporHabilidade(tabuleiro, habilidade, 4, 7, 2);

    imprimirTabuleiro(tabuleiro, letras);

    return 0;
}
