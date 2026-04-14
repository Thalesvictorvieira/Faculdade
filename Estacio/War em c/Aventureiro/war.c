#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TOTAL 5

typedef struct
{
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

void cadastrarTerritorios(Territorio *mapa)
{
    for (int i = 0; i < TOTAL; i++)
    {
        printf("\n--- Cadastro do territorio %d ---\n", i + 1);

        printf("Nome: ");
        scanf("%s", mapa[i].nome);

        printf("Cor do exercito: ");
        scanf("%s", mapa[i].cor);

        printf("Numero de tropas: ");
        scanf("%d", &mapa[i].tropas);
    }
}


void mostrarMapa(Territorio *mapa)
{
    printf("\n===== MAPA ATUAL =====\n");
    for (int i = 0; i < TOTAL; i++)
    {
        printf("%d - %s (Exercito %s, Tropas: %d)\n",i + 1,mapa[i].nome,mapa[i].cor,mapa[i].tropas);
    }
}

int escolherTerritorio(char tipo[])
{
    int escolha;
    printf("\nEscolha o territorio %s (1 a 5, ou 0 para sair): ", tipo);
    scanf("%d", &escolha);
    return escolha;}

int rolarDado(){return rand() % 6 + 1;
}

void atacar(Territorio *atacante, Territorio *defensor)
{
    int dadoAtacante = rolarDado();
    int dadoDefensor = rolarDado();
    printf("\n--- Resultado da Batalha ---\n");
    printf("Atacante (%s) tirou: %d\n", atacante->nome, dadoAtacante);
    printf("Defensor (%s) tirou: %d\n", defensor->nome, dadoDefensor);
    if (dadoAtacante >= dadoDefensor)
    {
        printf(">>> Atacante venceu!\n");
        defensor->tropas--;
        if (defensor->tropas <= 0)
        {
            printf(">>> Territorio conquistado!\n");
            strcpy(defensor->cor, atacante->cor);
            defensor->tropas = 1;
        }
    }
    else
    {
        printf(">>> Defensor venceu!\n");
        atacante->tropas--;
    }
}

void liberarMemoria(Territorio *mapa)
{
    free(mapa);
}

int main()
{
    srand(time(NULL));
    Territorio *mapa = calloc(TOTAL, sizeof(Territorio));
    cadastrarTerritorios(mapa);
    int atacante, defensor;
    while (1)
    {
        mostrarMapa(mapa);
        atacante = escolherTerritorio("ATACANTE");
        if (atacante == 0)
            break;
        defensor = escolherTerritorio("DEFENSOR");
    atacante--;
        defensor--;
        atacar(&mapa[atacante], &mapa[defensor]);
    }
    liberarMemoria(mapa);
    return 0;
}