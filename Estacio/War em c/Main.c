#include <stdio.h>
#include <string.h>

#define QTD_TERRITORIOS 5

typedef struct {
    char nome[50];
    char cor[20];
    int tropas;
} Territorio;

int main() {
    Territorio territorios[QTD_TERRITORIOS];

    for (int i = 0; i < QTD_TERRITORIOS; i++) {
        printf("\n=== Cadastro do Território %d ===\n", i + 1);

        printf("Digite o nome: ");
        fgets(territorios[i].nome, sizeof(territorios[i].nome), stdin);
        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = '\0';

        printf("Digite a cor: ");
        fgets(territorios[i].cor, sizeof(territorios[i].cor), stdin);
        territorios[i].cor[strcspn(territorios[i].cor, "\n")] = '\0';

        printf("Digite o número de tropas: ");
        scanf("%d", &territorios[i].tropas);
        getchar(); // limpa o ENTER do buffer
    }

    printf("\n===== TERRITÓRIOS CADASTRADOS =====\n");

    for (int i = 0; i < QTD_TERRITORIOS; i++) {
        printf("\nTerritório %d:\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor: %s\n", territorios[i].cor);
        printf("Tropas: %d\n", territorios[i].tropas);
    }

    return 0;
}