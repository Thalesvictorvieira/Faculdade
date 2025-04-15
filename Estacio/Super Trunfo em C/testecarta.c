#include <stdio.h>
#include <string.h>

int main()
{
    int CodigoCarta1,CodigoCarta2, NumeroDePontoTuristico1, NumeroDePontoTuristico2, Escolha1, Escolha2;
    char Estado1, Estado2, NomeCidade1[50], NomeCidade2[50];
    float Area1, Area2, Pib1, Pib2, DensidadePoPulacional1, DensidadePoPulacional2, PibPcapta1, PibPcapta2;
    unsigned long int NumeroPopulacao1, NumeroPopulacao2;
    float soma1 = 0, soma2 = 0;

     // Entrada para Carta 1
     printf("Digite o Numero da carta (1 - 2): ");
     scanf("%d", &CodigoCarta1);
 
     printf("Digite o Estado da Carta (A - H): ");
     scanf(" %c", &Estado1);  // Adiciona espaço antes do %c para ignorar espaços em branco
 
     printf("Digite o nome da cidade: ");
     scanf(" %[^\n]", NomeCidade1);
 
     printf("Digite o valor da populacao: ");
     scanf("%lu", &NumeroPopulacao1);
     getchar();
 
     printf("Digite o valor da area: ");
     scanf("%f", &Area1);  // Alterado para %f
     getchar();
 
     printf("Digite o PIB: ");
     scanf("%f", &Pib1);
 
     printf("Digite o numero de pontos turisticos: ");
     scanf("%d", &NumeroDePontoTuristico1);
 
 
     //Tratramento de dados para a carta 1
     // Cálculos para a carta 1
     DensidadePoPulacional1 = (float)NumeroPopulacao1 / Area1;
     PibPcapta1 = (float)Pib1 / NumeroPopulacao1;
 
     printf("\n -------------AGORA VOCE IRA INSERIR OS DADOS DA 2 CARTA----------------\n");
 
     // Entrada para Carta 2
     printf("Digite o Numero da carta (1 - 2): ");
     scanf("%d", &CodigoCarta2);
 
     printf("Digite o Estado da Carta (A - H): ");
     scanf(" %c", &Estado2);
 
     printf("Digite o nome da cidade: ");
     scanf(" %[^\n]", NomeCidade2);
 
     printf("Digite o valor da populacao: ");
     scanf("%lu", &NumeroPopulacao2);
 
     printf("Digite o valor da area: ");
     scanf("%f", &Area2);  // Alterado para %f
 
     printf("Digite o PIB: ");
     scanf("%f", &Pib2);
 
     printf("Digite o numero de pontos turisticos: ");
     scanf("%d", &NumeroDePontoTuristico2);
    DensidadePoPulacional1 = (float)NumeroPopulacao1 / Area1;
    PibPcapta1 = (float)Pib1 / NumeroPopulacao1;
    DensidadePoPulacional2 = (float)NumeroPopulacao2 / Area2;
    PibPcapta2 = (float)Pib2 / NumeroPopulacao2;

    // Menu interativo
    printf("\n*******************************\n");
    printf("Escolha quais atributos serao usados para realizar a comparacao\n");
    printf("(1) Populacao\n");
    printf("(2) Area\n");
    printf("(3) PIB\n");
    printf("(4) Numero de pontos turisticos\n");
    printf("(5) Densidade Demografica (quem tem menor ganha)\n");
    printf("*******************************\n");
    
    printf("Escolha o primeiro atributo: ");
    scanf("%d", &Escolha1);
    printf("Escolha o segundo atributo: ");
    scanf("%d", &Escolha2);
    printf("**********************************\n");
    

    //Tratramento se o usuario escolher o mesmo atributo para ser comparado
    if (Escolha1 == Escolha2) {
        printf("Nao pode escolher o mesmo atributo\n");
        return 1;
    }
    
    // Função auxiliar para somar os valores escolhidos

    for (int i = 1; i <= 5; i++) {
        if (Escolha1 == i || Escolha2 == i) {
            switch (i) {
                case 1:
                    soma1 += NumeroPopulacao1;
                    soma2 += NumeroPopulacao2;
                    break;
                case 2:
                    soma1 += Area1;
                    soma2 += Area2;
                    break;
                case 3:
                    soma1 += Pib1;
                    soma2 += Pib2;
                    break;
                case 4:
                    soma1 += NumeroDePontoTuristico1;
                    soma2 += NumeroDePontoTuristico2;
                    break;
                case 5:
                    soma1 += DensidadePoPulacional1;
                    soma2 += DensidadePoPulacional2;
                    break;
            }
        }
    }
    
    
    printf("Soma dos valores da carta 1: %.2f\n", soma1);
    printf("Soma dos valores da carta 2: %.2f\n", soma2);
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    
    if (soma1 > soma2) {
        printf("Carta 1 venceu!\n");
    } else if (soma1 < soma2) {
        printf("Carta 2 venceu!\n");
    } else {
        printf("Empate!\n");
    }
    printf("-=-=-=-=-=-=-=-=-=-=-=\n");
    return 0;
}

