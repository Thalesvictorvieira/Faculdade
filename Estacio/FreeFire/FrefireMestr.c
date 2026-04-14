#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 20

typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
    int prioridade;
} Componente;


Componente mochila[MAX];
int numItens = 0;
int comparacoes = 0;
int ordenadoPorNome = 0; // controle da ordenação


void limparBuffer() {
    while (getchar() != '\n');
}


void listar() {
    printf("\n=========== INVENTARIO ===========\n");

    if (numItens == 0) {
        printf("Mochila vazia!\n");
        return;
    }

    printf("%-15s %-15s %-10s %-10s\n", "Nome", "Tipo", "Quantidade", "Prioridade");
    printf("----------------------------------------------------------\n");

    for (int i = 0; i < numItens; i++) {
        printf("%-15s %-15s %-10d %-10d\n",
               mochila[i].nome,
               mochila[i].tipo,
               mochila[i].quantidade,
               mochila[i].prioridade);
    }

    printf("\nStatus da ordenacao por Nome: ");
    if (ordenadoPorNome)
        printf("Ordenado\n");
    else
        printf("Nao ordenado\n");
}


void adicionar() {
    if (numItens >= MAX) {
        printf("\nMochila cheia!\n");
        return;
    }

    int tipoOpcao;

    printf("\nNome: ");
    fgets(mochila[numItens].nome, 30, stdin);
    mochila[numItens].nome[strcspn(mochila[numItens].nome, "\n")] = '\0';

    printf("\nEscolha o tipo:\n");
    printf("1 - Estrutural\n");
    printf("2 - Eletronico\n");
    printf("3 - Energia\n");
    printf("Opcao: ");
    scanf("%d", &tipoOpcao);
    limparBuffer();

    switch (tipoOpcao) {
        case 1: strcpy(mochila[numItens].tipo, "Estrutural"); break;
        case 2: strcpy(mochila[numItens].tipo, "Eletronico"); break;
        case 3: strcpy(mochila[numItens].tipo, "Energia"); break;
        default: strcpy(mochila[numItens].tipo, "Desconhecido");
    }

    printf("Quantidade: ");
    scanf("%d", &mochila[numItens].quantidade);
    limparBuffer();

    do {
        printf("Prioridade (1-5): ");
        scanf("%d", &mochila[numItens].prioridade);
        limparBuffer();

        if (mochila[numItens].prioridade < 1 || mochila[numItens].prioridade > 5) {
            printf("Valor invalido! Digite entre 1 e 5.\n");
        }

    } while (mochila[numItens].prioridade < 1 || mochila[numItens].prioridade > 5);

    numItens++;
    ordenadoPorNome = 0; // desorganiza

    printf("\nComponente adicionado com sucesso!\n");

    listar(); // mostra inventário
}


void descartar() {
    char nome[30];

    printf("\nNome para descartar: ");
    fgets(nome, 30, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    for (int i = 0; i < numItens; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {

            for (int j = i; j < numItens - 1; j++) {
                mochila[j] = mochila[j + 1];
            }

            numItens--;
            ordenadoPorNome = 0;

            printf("\nComponente descartado!\n");
            return;
        }
    }

    printf("\nComponente nao encontrado!\n");
}

void organizar() {
    int escolha;

    printf("\n1 - Nome (Bubble Sort)\n");
    printf("2 - Tipo (Insertion Sort)\n");
    printf("3 - Prioridade (Selection Sort)\n");
    printf("Escolha: ");
    scanf("%d", &escolha);
    limparBuffer();

    comparacoes = 0;
    clock_t inicio = clock();

    if (escolha == 1) {
        Componente temp;

        for (int i = 0; i < numItens - 1; i++) {
            for (int j = 0; j < numItens - i - 1; j++) {
                comparacoes++;
                if (strcmp(mochila[j].nome, mochila[j + 1].nome) > 0) {
                    temp = mochila[j];
                    mochila[j] = mochila[j + 1];
                    mochila[j + 1] = temp;
                }
            }
        }

        ordenadoPorNome = 1;
        printf("\nOrdenado por NOME\n");
    }

    else if (escolha == 2) {
        for (int i = 1; i < numItens; i++) {
            Componente chave = mochila[i];
            int j = i - 1;

            while (j >= 0 && strcmp(mochila[j].tipo, chave.tipo) > 0) {
                comparacoes++;
                mochila[j + 1] = mochila[j];
                j--;
            }
            mochila[j + 1] = chave;
        }

        ordenadoPorNome = 0;
        printf("\nOrdenado por TIPO\n");
    }

    else if (escolha == 3) {
        for (int i = 0; i < numItens - 1; i++) {
            int min = i;

            for (int j = i + 1; j < numItens; j++) {
                comparacoes++;
                if (mochila[j].prioridade < mochila[min].prioridade) {
                    min = j;
                }
            }

            Componente temp = mochila[i];
            mochila[i] = mochila[min];
            mochila[min] = temp;
        }

        ordenadoPorNome = 0;
        printf("\nOrdenado por PRIORIDADE\n");
    }

    clock_t fim = clock();

    printf("Comparacoes: %d\n", comparacoes);
    printf("Tempo: %.5f segundos\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
}


void buscaBinaria() {

    if (!ordenadoPorNome) {
        printf("\n ALERTA!\n");
        printf("A busca binaria requer que a mochila esteja ordenada por NOME.\n");
        printf("Use a opcao 4 para organizar a mochila primeiro.\n");
        printf("\nPressione ENTER para voltar...");
        getchar();
        return;
    }

    char nome[30];

    printf("\nNome para busca binaria: ");
    fgets(nome, 30, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    int inicio = 0, fim = numItens - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        int cmp = strcmp(mochila[meio].nome, nome);

        if (cmp == 0) {
            printf("\nEncontrado!\n");
            printf("%s | %s | %d | %d\n",
                   mochila[meio].nome,
                   mochila[meio].tipo,
                   mochila[meio].quantidade,
                   mochila[meio].prioridade);
            return;
        } else if (cmp < 0) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    printf("\nComponente nao encontrado!\n");
}


int main() {
    int opcao;

    do {
        printf("\n=====================================\n");
        printf(" CODIGO DA ILHA - TORRE DE FUGA\n");
        printf("=====================================\n");

        printf("\n1 Adicionar\n");
        printf("2 Descartar\n");
        printf("3 Listar\n");
        printf("4 Organizar Mochila\n");
        printf("5 Buscar Binaria\n");
        printf("0 Ativar Torre de Fuga\n");

        printf("\nEscolha: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao) {
            case 1: adicionar(); break;
            case 2: descartar(); break;
            case 3: listar(); break;
            case 4: organizar(); break;
            case 5: buscaBinaria(); break;
            case 0: printf("\nFuga ativada...\n"); break;
            default: printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}