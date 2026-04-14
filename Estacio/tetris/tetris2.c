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

/* Gera uma nova peça com tipo aleatório e ID único */
Peca gerarPeca() {
    Peca nova;
    nova.tipo = tipos[rand() % 4];
    nova.id = contadorID++;
    return nova;
}

/* Inicializa a fila */
void inicializarFila(Fila *fila) {
    fila->inicio = 0;
    fila->fim = 0;
    fila->quantidade = 0;
}

/* Verifica se a fila está cheia */
int filaCheia(Fila *fila) {
    return fila->quantidade == TAM_FILA;
}

/* Verifica se a fila está vazia */
int filaVazia(Fila *fila) {
    return fila->quantidade == 0;
}

/* Insere elemento no final da fila */
void enqueue(Fila *fila, Peca peca) {
    if (filaCheia(fila)) {
        printf("  Fila cheia!\n");
        return;
    }

    fila->dados[fila->fim] = peca;
    fila->fim = (fila->fim + 1) % TAM_FILA;
    fila->quantidade++;
}

/* Remove elemento do início da fila */
Peca dequeue(Fila *fila) {
    Peca removida = {'?', -1};

    if (filaVazia(fila)) {
        printf("  Fila vazia!\n");
        return removida;
    }

    removida = fila->dados[fila->inicio];
    fila->inicio = (fila->inicio + 1) % TAM_FILA;
    fila->quantidade--;

    return removida;
}

/* Inicializa a pilha */
void inicializarPilha(Pilha *pilha) {
    pilha->topo = -1;
}

/* Verifica se a pilha está cheia */
int pilhaCheia(Pilha *pilha) {
    return pilha->topo == TAM_PILHA - 1;
}

/* Verifica se a pilha está vazia */
int pilhaVazia(Pilha *pilha) {
    return pilha->topo == -1;
}

/* Empilha uma peça */
void push(Pilha *pilha, Peca peca) {
    if (pilhaCheia(pilha)) {
        printf("  Reserva cheia!\n");
        return;
    }

    pilha->dados[++pilha->topo] = peca;
}

/* Desempilha uma peça */
Peca pop(Pilha *pilha) {
    Peca removida = {'?', -1};

    if (pilhaVazia(pilha)) {
        printf("  Reserva vazia!\n");
        return removida;
    }

    return pilha->dados[pilha->topo--];
}

/* Exibe a fila de forma organizada */
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

/* Exibe a pilha de forma organizada */
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

/* Função principal */
int main() {
    Fila fila;
    Pilha pilha;
    int opcao;

    srand(time(NULL));

    inicializarFila(&fila);
    inicializarPilha(&pilha);

    /* Preenche a fila com 5 peças iniciais */
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
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1: {
                Peca p = dequeue(&fila);
                if (p.id != -1) {
                    printf("✔ Jogou: [%c %d]\n", p.tipo, p.id);
                    enqueue(&fila, gerarPeca());
                }
                break;
            }

            case 2: {
                if (!pilhaCheia(&pilha)) {
                    Peca p = dequeue(&fila);
                    if (p.id != -1) {
                        push(&pilha, p);
                        printf("✔ Enviado para reserva: [%c %d]\n", p.tipo, p.id);
                        enqueue(&fila, gerarPeca());
                    }
                }
                break;
            }

            case 3: {
                if (!pilhaVazia(&pilha) && !filaCheia(&fila)) {
                    Peca p = pop(&pilha);
                    enqueue(&fila, p);
                    printf("✔ Usou da reserva: [%c %d]\n", p.tipo, p.id);
                }
                break;
            }

            case 0:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("  Opção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}