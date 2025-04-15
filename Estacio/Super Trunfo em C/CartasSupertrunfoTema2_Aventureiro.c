#include <stdio.h>

int main()
{
    int CodigoCarta1, CodigoCarta2, NumeroDePontoTuristico1, NumeroDePontoTuristico2, Escolha;
    char Estado1, Estado2, NomeCidade1[50], NomeCidade2[50];
    float Area1, Area2, Pib1, Pib2;
    float DensidadePoPulacional1, DensidadePoPulacional2, PibPcapta1, PibPcapta2;
    float Super_Poder1, Super_Poder2;
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

    // Cálculos para a carta 2
    DensidadePoPulacional2 = (float)NumeroPopulacao2 / Area2;
    PibPcapta2 = (float)Pib2 / NumeroPopulacao2;

    Super_Poder1 = NumeroPopulacao1 + Area1 + Pib1 + NumeroDePontoTuristico1 + PibPcapta1 + DensidadePoPulacional1;
    Super_Poder2 = NumeroPopulacao2 + Area2 + Pib2 + NumeroDePontoTuristico2 + PibPcapta2 + DensidadePoPulacional2;

    // Exibição do menu interativo

    printf("\n*******************************\n");
    printf("Escolhe que atributo sera usado para comparar\n");
    printf("(1) Populacao\n");
    printf("(2) area\n");
    printf("(3) pib\n");
    printf("(4) numero de ponto turisticos\n");
    printf("(5) Densidade Demografica quem tem menor ganha \n");
    printf("***********************\n");
    scanf("%d", &Escolha);
    switch (Escolha)
    {
    case 1:
        if (NumeroPopulacao1 > NumeroPopulacao2)
        {
            printf("Carta 1 \n");
            printf("Populacao %lu", NumeroPopulacao1);
            printf("Carta 2 \n");
            printf("Populacao %lu", NumeroPopulacao2);
            printf("Carta 1 e a vencendora");
        }
        else if (NumeroDePontoTuristico1 = NumeroDePontoTuristico2)
        {
            printf("OS valores escolhido para atribuicao sao iguais");
        }
        else
        {
            printf("Carta 1 \n");
            printf("Populacao %lu", NumeroPopulacao1);
            printf("Carta 2 \n");
            printf("Populacao %lu", NumeroPopulacao2);
            printf("Carta 2 e a vencendora");
        }    
    case 2 :
        if (Area1 > Area2)
        {
            printf("Carta 1 \n");
            printf("Area %f", Area1);
            printf("Carta 2 \n");
            printf("Area %f", Area2);
            printf("Carta 1 e a vencendora");
        }
        else if (Area1 = Area2)
        {
            printf("Os valores sao iguais");
        }
        else
        {
            printf("Carta 1 \n");
            printf("Area %f", Area1);
            printf("Carta 2 \n");
            printf("Area %f", Area2);
            printf("Carta 2 e a vencendora");
        }
    case 3:  
        if (Pib1 > Pib2)
        {
            printf("Carta 1 \n");
            printf("PIB %f", Pib1);
            printf("Carta 2 \n");
            printf("PIB  %f", Pib2);
            printf("Carta 1 e a vencendora");
        }
        else if (Pib1 == Pib2)
        {
            printf("Os valores sao iguais");
        }
        else
        {
            printf("Carta 1 \n");
            printf("PIB %f", Pib1);
            printf("Carta 2 \n");
            printf("PIB  %f", Pib2);
            printf("Carta 2 e a vencendora");
        }
    case 4:
        if (NumeroDePontoTuristico1>NumeroDePontoTuristico2)
        {
            printf("Carta 1 \n");
            printf("Numero de ponto turistico %d", NumeroDePontoTuristico1);
            printf("Carta 2 \n");
            printf("Numero de ponto turistico %d", NumeroDePontoTuristico2);
            printf("Carta 1 e a vencendora");
        }
        else if (NumeroDePontoTuristico1 == NumeroDePontoTuristico2)
        {
            printf("Empate");
        }
        else
        {
            printf("Carta 1 \n");
            printf("Numero de ponto turistico %d", NumeroDePontoTuristico1);
            printf("Carta 2 \n");
            printf("Numero de ponto turistico %d", NumeroDePontoTuristico2);
            printf("Carta 1 e a vencendora");
        }
    case 5:
        if (DensidadePoPulacional2>DensidadePoPulacional1)
        {
            printf("Carta 1 \n");
            printf("Densidade populacioanl da carta 1 %f", DensidadePoPulacional1);
            printf("Carta 2 \n");
            printf("Desnsidade populacional da carta 2 %f \n",DensidadePoPulacional2);
            printf("Carta 1 e a vencendora");
        }
        else if (DensidadePoPulacional1 == DensidadePoPulacional2)
        {
            printf("Empate");
        }
        else
        {
            printf("Carta 1 \n");
            printf("Densidade populacioanl da carta 1 %f", DensidadePoPulacional1);
            printf("Carta 2 \n");
            printf("Desnsidade populacional da carta 2 %f",DensidadePoPulacional2);
            printf("Carta 2 e a vencendora");
        }
        break;
    }
    return 0;
}