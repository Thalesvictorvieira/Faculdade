#include <stdio.h>

int main()
{
    int CodigoCarta1, CodigoCarta2, NumeroDePontoTuristico1, NumeroDePontoTuristico2;
    int Escolha1, Escolha2;
    char Estado1, Estado2, NomeCidade1[50], NomeCidade2[50];
    float Area1, Area2, Pib1, Pib2;
    float DensidadePoPulacional1, DensidadePoPulacional2, PibPcapta1, PibPcapta2;
    float Super_Poder1, Super_Poder2;
    unsigned long int NumeroPopulacao1, NumeroPopulacao2;

    // Entrada para Carta 1
    printf("Digite o Numero da carta (1 - 2): ");
    scanf("%d", &CodigoCarta1);

    printf("Digite o Estado da Carta (A - H): ");
    scanf(" %c", &Estado1);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", NomeCidade1);

    printf("Digite o valor da populacao: ");
    scanf("%lu", &NumeroPopulacao1);

    printf("Digite o valor da area: ");
    scanf("%f", &Area1);

    printf("Digite o PIB: ");
    scanf("%f", &Pib1);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &NumeroDePontoTuristico1);

    // Cálculos para a carta 1
    DensidadePoPulacional1 = (float)NumeroPopulacao1 / Area1;
    PibPcapta1 = (float)Pib1 / NumeroPopulacao1;

    printf("\n-------------AGORA VOCE IRA INSERIR OS DADOS DA 2 CARTA----------------\n");

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
    scanf("%f", &Area2);

    printf("Digite o PIB: ");
    scanf("%f", &Pib2);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &NumeroDePontoTuristico2);

    // Cálculos para a carta 2
    DensidadePoPulacional2 = (float)NumeroPopulacao2 / Area2;
    PibPcapta2 = (float)Pib2 / NumeroPopulacao2;

    // Super poder
    Super_Poder1 = NumeroPopulacao1 + Area1 + Pib1 + NumeroDePontoTuristico1 + PibPcapta1 + DensidadePoPulacional1;
    Super_Poder2 = NumeroPopulacao2 + Area2 + Pib2 + NumeroDePontoTuristico2 + PibPcapta2 + DensidadePoPulacional2;

    // Escolha de atributos
    printf("\nEscolha dois atributos diferentes para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos turísticos\n");
    printf("5 - Densidade populacional\n");
    printf("6 - PIB per capita\n");
    printf("7 - Super poder (todos somados)\n");

    printf("Digite o número do primeiro atributo: ");
    scanf("%d", &Escolha1);
    printf("Digite o número do segundo atributo (diferente do primeiro): ");
    scanf("%d", &Escolha2);

    if (Escolha1 == Escolha2 || Escolha1 < 1 || Escolha1 > 7 || Escolha2 < 1 || Escolha2 > 7) {
        printf("Erro: seleções inválidas.\n");
        return 1;
    }

    float valor1_carta1 = 0, valor2_carta1 = 0;
    float valor1_carta2 = 0, valor2_carta2 = 0;

    // Atribuir os valores do atributo 1
    switch (Escolha1) {
        case 1: valor1_carta1 = NumeroPopulacao1; valor1_carta2 = NumeroPopulacao2; break;
        case 2: valor1_carta1 = Area1; valor1_carta2 = Area2; break;
        case 3: valor1_carta1 = Pib1; valor1_carta2 = Pib2; break;
        case 4: valor1_carta1 = NumeroDePontoTuristico1; valor1_carta2 = NumeroDePontoTuristico2; break;
        case 5: valor1_carta1 = DensidadePoPulacional1; valor1_carta2 = DensidadePoPulacional2; break;
        case 6: valor1_carta1 = PibPcapta1; valor1_carta2 = PibPcapta2; break;
        case 7: valor1_carta1 = Super_Poder1; valor1_carta2 = Super_Poder2; break;
    }

    // Atribuir os valores do atributo 2
    switch (Escolha2) {
        case 1: valor2_carta1 = NumeroPopulacao1; valor2_carta2 = NumeroPopulacao2; break;
        case 2: valor2_carta1 = Area1; valor2_carta2 = Area2; break;
        case 3: valor2_carta1 = Pib1; valor2_carta2 = Pib2; break;
        case 4: valor2_carta1 = NumeroDePontoTuristico1; valor2_carta2 = NumeroDePontoTuristico2; break;
        case 5: valor2_carta1 = DensidadePoPulacional1; valor2_carta2 = DensidadePoPulacional2; break;
        case 6: valor2_carta1 = PibPcapta1; valor2_carta2 = PibPcapta2; break;
        case 7: valor2_carta1 = Super_Poder1; valor2_carta2 = Super_Poder2; break;
    }

    // Exibir resultados
    printf("\nRESULTADO DAS COMPARAÇÕES:\n");

    printf("Atributo %d: %s = %.2f | %s = %.2f\n", Escolha1, NomeCidade1, valor1_carta1, NomeCidade2, valor1_carta2);
    if (valor1_carta1 > valor1_carta2)
        printf(">> %s venceu no atributo %d\n", NomeCidade1, Escolha1);
    else if (valor1_carta2 > valor1_carta1)
        printf(">> %s venceu no atributo %d\n", NomeCidade2, Escolha1);
    else
        printf(">> Empate no atributo %d\n", Escolha1);

    printf("\nAtributo %d: %s = %.2f | %s = %.2f\n", Escolha2, NomeCidade1, valor2_carta1, NomeCidade2, valor2_carta2);
    if (valor2_carta1 > valor2_carta2)
        printf(">> %s venceu no atributo %d\n", NomeCidade1, Escolha2);
    else if (valor2_carta2 > valor2_carta1)
        printf(">> %s venceu no atributo %d\n", NomeCidade2, Escolha2);
    else
        printf(">> Empate no atributo %d\n", Escolha2);

    return 0;
}
