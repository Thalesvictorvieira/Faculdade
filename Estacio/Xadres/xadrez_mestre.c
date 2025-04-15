#include <stdio.h>
#include <stdlib.h>


// Função para o movimento da TORRE (Direita)

void moverTorre(int movimentos_restantes) {
    if (movimentos_restantes <= 0) return;

    printf("Torre: Direita\n");
    moverTorre(movimentos_restantes - 1); 
}

// 
// Função para o movimento do BISPO 
// 
void moverBispoInterno(int passos_horizontal) {
    if (passos_horizontal <= 0) return;

    printf("Bispo: Direita\n");
    moverBispoInterno(passos_horizontal - 1);
}

void moverBispo(int passos_diagonais) {
    if (passos_diagonais <= 0) return;

    printf("Bispo: Cima\n");
    moverBispoInterno(1); 

    moverBispo(passos_diagonais - 1); 
}


// Função para o movimento da RAINHA

void moverRainha(int movimentos_restantes) {
    if (movimentos_restantes <= 0) return;

    printf("Rainha: Esquerda\n");
    moverRainha(movimentos_restantes - 1); //  recursiva
}

// 
// Função com loops para o movimento do CAVALO 
// 
void moverCavalo(int movimentos) {
    for (int i = 0; i < movimentos; i++) {
        int vertical = 0;
        int horizontal = 0;

        // Loop para mover 2 casas para cima
        while (vertical < 2) {
            if (vertical == 1) {
                printf("Cavalo: Cima\n");
            } else {
                vertical++;
                continue; // ignora esta 
            }
            vertical++;
        }

        // Loop para mover 1 casa para a direita
        do {
            if (horizontal == 0) {
                printf("Cavalo: Direita\n");
                horizontal++;
            } else {
                break; // sai do do-while
            }
        } while (horizontal < 1);

        printf("\n"); // separa cada movimento do cavalo
    }
}


// Função main

int main() {
    // Dimensões do tabuleiro
    const int Tamanho_tabuleiro_X = 8;
    const int Tamanho_tabuleiro_Y = 8;

    // Quantidade de movimentos de cada peça
    const int movimentos_torre = 5;
    const int movimentos_bispo = 5;
    const int movimentos_rainha = 8;
    const int movimentos_cavalo = 3;

    
    // Movimentos das peças
    

    // TORRE
    moverTorre(movimentos_torre);
    printf("\n");

    // BISPO
    moverBispo(movimentos_bispo);
    printf("\n");

    // RAINHA
    moverRainha(movimentos_rainha);
    printf("\n");

    // CAVALO
    moverCavalo(movimentos_cavalo);

    return 0;
}
