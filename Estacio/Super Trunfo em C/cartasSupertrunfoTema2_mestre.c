#include <stdio.h>

int main()
{
    int CodigoCarta1, CodigoCarta2, NumeroDePontoTuristico1, NumeroDePontoTuristico2, Escolha1,Escolha2,Somapopuloacao;
    char Estado1, Estado2, NomeCidade1[50], NomeCidade2[50];
    float Area1, Area2, Pib1, Pib2,DensidadePoPulacional1, DensidadePoPulacional2, PibPcapta1, PibPcapta2,Super_Poder1, Super_Poder2;
    unsigned long int NumeroPopulacao1, NumeroPopulacao2;

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


    //Tratramento de dados para a carta 2
    // Cálculos para a carta 2
    DensidadePoPulacional2 = (float)NumeroPopulacao2 / Area2;
    PibPcapta2 = (float)Pib2 / NumeroPopulacao2;

    Super_Poder1 = NumeroPopulacao1 + Area1 + Pib1 + NumeroDePontoTuristico1 + PibPcapta1 + DensidadePoPulacional1;
    Super_Poder2 = NumeroPopulacao2 + Area2 + Pib2 + NumeroDePontoTuristico2 + PibPcapta2 + DensidadePoPulacional2;


    //Menu interativo
    printf("\n*******************************\n");
    printf("Escolha quais atributos serao usados para realizar a comparação \n");
    printf("(1) Populacao\n");
    printf("(2) area\n");
    printf("(3) pib\n");
    printf("(4) numero de ponto turisticos\n");
    printf("(5) Densidade Demografica quem tem menor ganha \n");
    printf("***********************\n");
    scanf("%d", &Escolha1);
    scanf("%d", &Escolha2);
    if (Escolha1 == Escolha2)
    {
        printf("Não pode escolher o mesmo atributo\n");
        return 0;
    }
    
   
   switch (Escolha1,Escolha2)
   {
    case 1:
    printf("Opção escolhida: População\n");
    printf("Populacao da carta 1 = %lu\n", NumeroPopulacao1);
    printf("Populacao da carta 2 = %lu\n", NumeroPopulacao2);
    if (NumeroPopulacao1 > NumeroPopulacao2){
        printf("Carta 1 venceu\n");
    }
    else if (NumeroPopulacao1 = NumeroPopulacao2){}
    Somapopuloacao = NumeroPopulacao1 + NumeroPopulacao2;
    case 2:
    printf("Opção escolhida: Area\n");
    printf("Area da carta 1 = %.2f\n", Area1);
   default:
    printf("Opção invalida\n");
    break;
   }
    return 0;
}