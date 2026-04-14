#include <stdio.h>
#include <string.h>

#define TOTAL 5

typedef struct 
{
    char nome[50];
    char cor[50];
    int tropas;
} Territorio;

// Remove o \n do fgets
void limpar_enter(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

int main()
{
    Territorio territorios[TOTAL];

    printf("=========================================\n");
    printf("   WAR ESTRUTURADO - CADASTRO INICIAL\n");
    printf("=========================================\n");

    // Cadastro
    for (int i = 0; i < TOTAL; i++) {
        printf("\n--- Cadastrando Territorio %d ---\n", i + 1);

        printf("Nome do Territorio: ");
        fgets(territorios[i].nome, 50, stdin);
        limpar_enter(territorios[i].nome);

        printf("Cor do exercito: ");
        fgets(territorios[i].cor, 50, stdin);
        limpar_enter(territorios[i].cor);

        printf("Numero de tropas: ");
        scanf("%d", &territorios[i].tropas);
        getchar(); // limpa o ENTER do buffer
    }

    // Exibição
    printf("\n=========================================\n");
    printf("      TERRITORIOS CADASTRADOS\n");
    printf("=========================================\n");

    for (int i = 0; i < TOTAL; i++) {
        printf("\nTerritorio %d\n", i + 1);
        printf("Nome   : %s\n", territorios[i].nome);
        printf("Cor    : %s\n", territorios[i].cor);
        printf("Tropas : %d\n", territorios[i].tropas);
    }

    return 0;
}