#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Territorio
{
    char nome[50];
    char cor[30];
    int tropas;
};
int main() {
    struct Territorio mapa[5];

    for (int i = 0; i < 5; i++)
    {
        printf("\n--- Cadastro do territorio %d ---\n",i + 1);
        
        printf("nome do territorio: ");
        scanf("%s",mapa[i].nome);

        printf("Cor do exercito: ");
        scanf("%s", mapa[i].cor);

        printf("Numero de tropas: ");
        scanf("%d",&mapa[i].tropas);
    }
    printf("\n ===== ESTADO DO MAPA ====\n");
    for (int i = 0; i < 5; i++)
    {
        printf("\nTerritorio %d\n",i + 1);
        printf("Nome: %s\n",mapa[i].nome);
        printf("cor: %s\n",mapa[i].cor);
        printf("Numero de tropas: %d\n",mapa[i].tropas);
    }
    return 0;
}