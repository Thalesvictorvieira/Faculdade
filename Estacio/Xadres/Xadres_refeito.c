#include <stdio.h>
#include <stdlib.h>

// Função recursiva para movimentação da Torre (Esquerda)
void moverTorre(int movimentos) {
    if (movimentos == 0) return;
    printf("Torre: Esquerda\n");
    moverTorre(movimentos - 1);
}

// Função  para movimentação do Bispo (Cima, Direita)
void moverBispoRecursivo(int movimentos) {
    if (movimentos == 0) return;
    printf("Bispo: Cima, Direita\n");
    moverBispoRecursivo(movimentos - 1);
}

// Função para o Bispo (movimento diagonal)
void moverBispoLoop(int movimentos) {
    for (int i = 0; i < movimentos; i++) {
        for (int j = 0; j < 1; j++) { 
            printf("Bispo: Cima, Direita\n");
        }
    }
}

// Função  para movimentação da Rainha (Esquerda)
void moverRainha(int movimentos) {
    if (movimentos == 0) return;
    printf("Rainha: Esquerda\n");
    moverRainha(movimentos - 1);
}

// Função parao o Cavalo (Cima, Cima, Direita) 
void moverCavalo() {
    int mov_cima = 2;
    int mov_direita = 1;

    for (int i = 0; i < mov_cima; i++) {
        printf("Cavalo: Cima\n");
    }

    for (int j = 0; j < mov_direita; j++) {
        if (j == 1) continue; 
        printf("Cavalo: Direita\n");
        break; 
    }
}

int main() {
    // Movimentação da Torre
    moverTorre(5);
    printf("\n"); 

    // Movimentação do Bispo 
    moverBispoRecursivo(5);
    printf("\n");

    // Movimentação do Bispo 
    moverBispoLoop(5);
    printf("\n");

    // Movimentação da Rainha
    moverRainha(8);
    printf("\n");

    // Movimentação do Cavalo
    moverCavalo();
    printf("\n");

    return 0;
}
