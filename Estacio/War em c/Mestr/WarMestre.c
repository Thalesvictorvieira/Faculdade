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

void toLowerCase(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
        }
    }
}
void atribuirMissao(char *missao, char corJogador[], Territorio *mapa)
{
    char coresDisponiveis[TOTAL][10];
    int totalCores = 0;
    
    for (int i = 0; i < TOTAL; i++)
    {
        int existe = 0;
        for (int j = 0; j < totalCores; j++)
        {
            if (strcmp(coresDisponiveis[j], mapa[i].cor) == 0)
            {
                existe = 1;
                break;
            }
        }

        if (!existe)
        {
            strcpy(coresDisponiveis[totalCores], mapa[i].cor);
            totalCores++;
        }
    }
    
    char corNormalizada[10];
    strcpy(corNormalizada, corJogador);
    toLowerCase(corNormalizada);
    int indice;

    do
    {
        indice = rand() % totalCores;
    } while (strcmp(coresDisponiveis[indice], corJogador) == 0);
    sprintf(missao, "Sua missao (%s): destruir o exercito %s",
            corJogador, coresDisponiveis[indice]);
}

void exibirMissao(char *missao)
{
    printf("\n===== MISSAO =====\n%s\n", missao);
}

int verificarMissao(char *missao, Territorio *mapa)
{
    char corAlvo[10];
    sscanf(missao, "Sua missao (%*[^)]): destruir o exercito %s", corAlvo);
    for (int i = 0; i < TOTAL; i++)
    {
        if (strcmp(mapa[i].cor, corAlvo) == 0)
            return 0;
    }
    return 1;
}

void cadastrarTerritorios(Territorio *mapa)
{
    for (int i = 0; i < TOTAL; i++)
    {
        printf("\n--- Territorio %d ---\n", i + 1);

        printf("Nome: ");
        scanf("%s", mapa[i].nome);

        printf("Cor: ");
        scanf("%s", mapa[i].cor);

        printf("Tropas: ");
        scanf("%d", &mapa[i].tropas);
    }
}

void mostrarMapa(Territorio *mapa)
{
    printf("\n===== MAPA =====\n");
    for (int i = 0; i < TOTAL; i++)
    {
        printf("%d - %s (%s, %d tropas)\n",
               i + 1,
               mapa[i].nome,
               mapa[i].cor,
               mapa[i].tropas);
    }
}

int menu()
{
    int op;
    printf("\n===== MENU =====\n");
    printf("1 - Atacar\n");
    printf("2 - Ver Missao\n");
    printf("0 - Sair\n");
    printf("Escolha: ");
    scanf("%d", &op);
    return op;
}

int escolherTerritorio(char tipo[])
{
    int escolha;
    printf("\nEscolha territorio %s (1 a 5): ", tipo);
    scanf("%d", &escolha);
    return escolha;
}

int rolarDado()
{
    return rand() % 6 + 1;
}

void atacar(Territorio *atacante, Territorio *defensor)
{
    int dA = rolarDado();
    int dD = rolarDado();

    printf("\n--- BATALHA ---\n");
    printf("%s tirou %d\n", atacante->nome, dA);
    printf("%s tirou %d\n", defensor->nome, dD);
    
    if (dA > dD)
    {
        printf("Atacante venceu!\n");
        strcpy(defensor->cor, atacante->cor);

        int metade = atacante->tropas / 2;

        defensor->tropas = metade;
        atacante->tropas -= metade;
    }
    else
    {
        printf("Defensor venceu!\n");
        atacante->tropas -= 1;

        if (atacante->tropas < 1)
        {
            atacante->tropas = 1;
        }
    }
}

int verificarFimDeJogo(Territorio *mapa)
{
    char corBase[10];
    strcpy(corBase, mapa[0].cor);

    for (int i = 1; i < TOTAL; i++)
    {
        if (strcmp(corBase, mapa[i].cor) != 0)
            return 0;
    }

    return 1;
}

int main()
{
    srand(time(NULL));

    Territorio *mapa = calloc(TOTAL, sizeof(Territorio));
    char *missao = malloc(100);

    cadastrarTerritorios(mapa);
    char corJogador[10];
    strcpy(corJogador, mapa[0].cor);
    
    atribuirMissao(missao, corJogador,mapa);
    exibirMissao(missao);
    int op;

    while (1)
    {
        mostrarMapa(mapa);
        if (verificarFimDeJogo(mapa))
        {
            printf("\n>>> UM EXERCITO DOMINOU TODO O MAPA! <<<\n");
            break;
        }

        op = menu();
        if (op == 0)
            break;

        if (op == 2)
        {
            exibirMissao(missao);
        }

        if (op == 1)
        {
            int a = escolherTerritorio("ATACANTE") - 1;
            int d = escolherTerritorio("DEFENSOR") - 1;

            if (strcmp(mapa[a].cor, mapa[d].cor) == 0)
            {
                printf("Nao pode atacar mesma cor!\n");
                continue;
            }
            atacar(&mapa[a], &mapa[d]);

            if (verificarMissao(missao, mapa))
            {
                printf("\n>>> MISSAO CUMPRIDA! <<<\n");
            }
        }
    }

    free(mapa);
    free(missao);
    printf("\nJogo encerrado.\n");

    return 0;
}