#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_FILA 5
#define TAM_PILHA 3

typedef struct {
    char tipo;
    int id;
} Peca;

typedef struct {
    Peca dados[TAM_FILA];
    int inicio;
    int fim;
    int quantidade;
} Fila;

typedef struct {
    Peca dados[TAM_PILHA];
    int topo;
} Pilha;

char tipos[] = {'I', 'O', 'T', 'L'};
int contadorID = 0;

Peca gerarPeca() {
    Peca nova;
    nova.tipo = tipos[rand() % 4];
    nova.id = contadorID++;
    return nova;
}

void inicializarFila(Fila *fila) {
    fila->inicio = 0;
    fila->fim = 0;
    fila->quantidade = 0;
}

int filaCheia(Fila *fila) {
    return fila->quantidade == TAM_FILA;
}

int filaVazia(Fila *fila) {
    return fila->quantidade == 0;
}

void enqueue(Fila *fila, Peca peca) {
    if (filaCheia(fila)) {
        printf("Fila cheia!\n");
        return;
    }

    fila->dados[fila->fim] = peca;
    fila->fim = (fila->fim + 1) % TAM_FILA;
    fila->quantidade++;
}

Peca dequeue(Fila *fila) {
    Peca removida = {'?', -1};

    if (filaVazia(fila)) {
        printf("Fila vazia!\n");
        return removida;
    }

    removida = fila->dados[fila->inicio];
    fila->inicio = (fila->inicio + 1) % TAM_FILA;
    fila->quantidade--;

    return removida;
}

void inicializarPilha(Pilha *pilha) {
    pilha->topo = -1;
}

int pilhaCheia(Pilha *pilha) {
    return pilha->topo == TAM_PILHA - 1;
}

int pilhaVazia(Pilha *pilha) {
    return pilha->topo == -1;
}

void push(Pilha *pilha, Peca peca) {
    if (pilhaCheia(pilha)) {
        printf("Reserva cheia!\n");
        return;
    }

    pilha->dados[++pilha->topo] = peca;
}

Peca pop(Pilha *pilha) {
    Peca removida = {'?', -1};

    if (pilhaVazia(pilha)) {
        printf("Reserva vazia!\n");
        return removida;
    }

    return pilha->dados[pilha->topo--];
}

void mostrarFila(Fila *fila) {
    printf("\n========== FILA ==========\n");

    if (filaVazia(fila)) {
        printf("Fila vazia\n");
        return;
    }

    int i = fila->inicio;

    for (int count = 0; count < fila->quantidade; count++) {
        printf("[%c %d] ", fila->dados[i].tipo, fila->dados[i].id);
        i = (i + 1) % TAM_FILA;
    }

    printf("\n");
}

void mostrarPilha(Pilha *pilha) {
    printf("======== RESERVA ========\n");

    if (pilhaVazia(pilha)) {
        printf("Reserva vazia\n");
        return;
    }

    for (int i = pilha->topo; i >= 0; i--) {
        printf("[%c %d] ", pilha->dados[i].tipo, pilha->dados[i].id);
    }

    printf("\n");
}

/* Troca frente da fila com topo da pilha */
void trocarTopo(Fila *fila, Pilha *pilha) {
    if (filaVazia(fila) || pilhaVazia(pilha)) {
        printf("Não é possível trocar: fila ou pilha vazia.\n");
        return;
    }

    Peca temp = fila->dados[fila->inicio];
    fila->dados[fila->inicio] = pilha->dados[pilha->topo];
    pilha->dados[pilha->topo] = temp;

    printf("Troca realizada com sucesso.\n");
}

/* Troca 3 primeiros da fila com pilha */
void trocarTres(Fila *fila, Pilha *pilha) {
    if (pilha->topo != 2 || fila->quantidade < 3) {
        printf("Não é possível trocar 3 peças.\n");
        return;
    }

    for (int i = 0; i < 3; i++) {
        int indexFila = (fila->inicio + i) % TAM_FILA;

        Peca temp = fila->dados[indexFila];
        fila->dados[indexFila] = pilha->dados[i];
        pilha->dados[i] = temp;
    }

    printf("Troca de 3 peças realizada com sucesso.\n");
}

int main() {
    Fila fila;
    Pilha pilha;
    int opcao;

    srand(time(NULL));

    inicializarFila(&fila);
    inicializarPilha(&pilha);

    for (int i = 0; i < TAM_FILA; i++) {
        enqueue(&fila, gerarPeca());
    }

    do {
        mostrarFila(&fila);
        mostrarPilha(&pilha);

        printf("\n====== MENU ======\n");
        printf("1 - Jogar peça\n");
        printf("2 - Enviar para reserva\n");
        printf("3 - Usar peça da reserva\n");
        printf("4 - Trocar frente da fila com topo da pilha\n");
        printf("5 - Trocar 3 primeiros da fila com a pilha\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1: {
                Peca p = dequeue(&fila);
                if (p.id != -1) {
                    printf("Jogou: [%c %d]\n", p.tipo, p.id);
                    enqueue(&fila, gerarPeca());
                }
                break;
            }

            case 2: {
                if (!pilhaCheia(&pilha)) {
                    Peca p = dequeue(&fila);
                    if (p.id != -1) {
                        push(&pilha, p);
                        enqueue(&fila, gerarPeca());
                    }
                }
                break;
            }

            case 3: {
                if (!pilhaVazia(&pilha) && !filaCheia(&fila)) {
                    Peca p = pop(&pilha);
                    enqueue(&fila, p);
                }
                break;
            }

            case 4:
                trocarTopo(&fila, &pilha);
                break;

            case 5:
                trocarTres(&fila, &pilha);
                break;

            case 0:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}