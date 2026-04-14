#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5
typedef struct {
    char tipo; 
    int id;
} Peca;
typedef struct {
    Peca dados[TAM];
    int inicio;
    int fim;
    int quantidade;
} Fila;


char tipos[] = {'I', 'O', 'T', 'L'};
int contadorID = 0;

Peca gerarPeca() {
    Peca p;
    p.tipo = tipos[rand() % 4];
    p.id = contadorID++;
    return p;
}


void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
    f->quantidade = 0;
}


int filaCheia(Fila *f) {
    return f->quantidade == TAM;
}


int filaVazia(Fila *f) {
    return f->quantidade == 0;
}


void enqueue(Fila *f, Peca p) {
    if (filaCheia(f)) {
        printf("Fila cheia! Não é possível adicionar nova peça.\n");
        return;
    }

    f->dados[f->fim] = p;
    f->fim = (f->fim + 1) % TAM;
    f->quantidade++;
}




void dequeue(Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia! Não há peças para jogar.\n");
        return;
    }

    Peca removida = f->dados[f->inicio];
    printf("Peça jogada: [%c %d]\n", removida.tipo, removida.id);

    f->inicio = (f->inicio + 1) % TAM;
    f->quantidade--;
}



void exibirFila(Fila *f) {
    printf("\nFila de Pecas: ");

    if (filaVazia(f)) {
        printf("Vazia\n");
        return;
    }

    int i = f->inicio;
    for (int count = 0; count < f->quantidade; count++) {
        printf("[%c %d] ", f->dados[i].tipo, f->dados[i].id);
        i = (i + 1) % TAM;
    }

    printf("\n");
}



int main() {
    Fila fila;
    int opcao;

    srand(time(NULL));

    inicializarFila(&fila);

    


    
    for (int i = 0; i < TAM; i++) {
        enqueue(&fila, gerarPeca());
    }

    do {
        exibirFila(&fila);

        printf("\n1 - Jogar peça (dequeue)\n");
        printf("2 - Inserir nova peça (enqueue)\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                dequeue(&fila);
                break;

            case 2:
                enqueue(&fila, gerarPeca());
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}