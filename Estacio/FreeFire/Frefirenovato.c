#include <stdio.h>
#include <string.h>

#define MAX_ITENS 10

typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

Item mochila[MAX_ITENS];
int numItens = 0;

void limparBuffer() {
    while (getchar() != '\n');
}


void adicionarItem() {
    if (numItens >= MAX_ITENS) {
        printf("\nMochila cheia!\n");
        return;
    }

    printf("\nNome do item: ");
    fgets(mochila[numItens].nome, 30, stdin);
    mochila[numItens].nome[strcspn(mochila[numItens].nome, "\n")] = '\0';

    printf("Tipo do item: ");
    fgets(mochila[numItens].tipo, 20, stdin);
    mochila[numItens].tipo[strcspn(mochila[numItens].tipo, "\n")] = '\0';

    printf("Quantidade: ");
    scanf("%d", &mochila[numItens].quantidade);
    limparBuffer();

    numItens++;

    printf("\nItem adicionado com sucesso!\n");
}


void removerItem() {
    char nomeBusca[30];
    int encontrado = 0;

    printf("\nDigite o nome do item para remover: ");
    fgets(nomeBusca, 30, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    for (int i = 0; i < numItens; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {

            // desloca os itens
            for (int j = i; j < numItens - 1; j++) {
                mochila[j] = mochila[j + 1];
            }

            numItens--;
            encontrado = 1;

            printf("\nItem removido com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("\nItem nao encontrado!\n");
    }
}


void listarItens() {
    printf("\n======= MOCHILA =======\n");

    if (numItens == 0) {
        printf("Mochila vazia!\n");
        return;
    }

    printf("Nome\t\tTipo\t\tQuantidade\n");
    printf("-------------------------------------------\n");

    for (int i = 0; i < numItens; i++) {
        printf("%s\t\t%s\t\t%d\n",
               mochila[i].nome,
               mochila[i].tipo,
               mochila[i].quantidade);
    }
}


int main() {
    int opcao;

    do {
        printf("\n=====================================\n");
        printf(" MOCHILA DE SOBREVIVENCIA - CODIGO DA ILHA\n");
        printf("=====================================\n");
        printf("Itens na Mochila: %d/%d\n", numItens, MAX_ITENS);

        printf("\n1. Adicionar Item\n");
        printf("2. Remover Item\n");
        printf("3. Listar Itens\n");
        printf("0. Sair\n");

        printf("-------------------------------------\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao) {
            case 1:
                adicionarItem();
                break;

            case 2:
                removerItem();
                break;

            case 3:
                listarItens();
                break;

            case 0:
                printf("\nSaindo...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}