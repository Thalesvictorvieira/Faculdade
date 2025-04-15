#include <stdio.h>
#include <string.h>

int main()
{
    int CodigoCarta1, CodigoCarta2, NumeroDePontoTuristico1, NumeroDePontoTuristico2;
    int Escolha1, Escolha2, Somapopuloacao;
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

    DensidadePoPulacional1 = (float)NumeroPopulacao1 / Area1;
    PibPcapta1 = (float)Pib1 / NumeroPopulacao1;

    // Entrada para Carta 2
    printf("\n-------------AGORA VOCE IRA INSERIR OS DADOS DA 2 CARTA----------------\n");

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

    DensidadePoPulacional2 = (float)NumeroPopulacao2 / Area2;
    PibPcapta2 = (float)Pib2 / NumeroPopulacao2;

    // Escolha de atributos
    printf("\n*********** MENU DE ESCOLHA DE ATRIBUTOS ***********\n");
    printf("Escolha o primeiro atributo para comparar:\n");
    printf("(1) Populacao\n");
    printf("(2) Area\n");
    printf("(3) PIB\n");
    printf("(4) Pontos Turisticos\n");
    printf("(5) Densidade Demografica (MENOR ganha)\n");
    printf("*****************************************************\n");
    printf("Digite a opção do primeiro atributo: ");
    scanf("%d", &Escolha1);

    // Mostrar opções restantes para o segundo atributo
    printf("\nAgora escolha o segundo atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 5; i++) {
        if (i != Escolha1) {
            switch (i) {
                case 1: printf("(1) Populacao\n"); break;
                case 2: printf("(2) Area\n"); break;
                case 3: printf("(3) PIB\n"); break;
                case 4: printf("(4) Pontos Turisticos\n"); break;
                case 5: printf("(5) Densidade Demografica\n"); break;
            }
        }
    }
    printf("Digite a opção do segundo atributo: ");
    scanf("%d", &Escolha2);

    if (Escolha1 == Escolha2) {
        printf("Erro: os atributos escolhidos devem ser diferentes.\n");
        return 1;
    }

    float valor1_carta1 = 0, valor2_carta1 = 0;
    float valor1_carta2 = 0, valor2_carta2 = 0;

    // Comparação do primeiro atributo
    switch (Escolha1) {
        case 1:
            valor1_carta1 = NumeroPopulacao1;
            valor1_carta2 = NumeroPopulacao2;
            break;
        case 2:
            valor1_carta1 = Area1;
            valor1_carta2 = Area2;
            break;
        case 3:
            valor1_carta1 = Pib1;
            valor1_carta2 = Pib2;
            break;
        case 4:
            valor1_carta1 = NumeroDePontoTuristico1;
            valor1_carta2 = NumeroDePontoTuristico2;
            break;
        case 5:
            valor1_carta1 = DensidadePoPulacional1;
            valor1_carta2 = DensidadePoPulacional2;
            break;
    }

    // Comparação do segundo atributo
    switch (Escolha2) {
        case 1:
            valor2_carta1 = NumeroPopulacao1;
            valor2_carta2 = NumeroPopulacao2;
            break;
        case 2:
            valor2_carta1 = Area1;
            valor2_carta2 = Area2;
            break;
        case 3:
            valor2_carta1 = Pib1;
            valor2_carta2 = Pib2;
            break;
        case 4:
            valor2_carta1 = NumeroDePontoTuristico1;
            valor2_carta2 = NumeroDePontoTuristico2;
            break;
        case 5:
            valor2_carta1 = DensidadePoPulacional1;
            valor2_carta2 = DensidadePoPulacional2;
            break;
    }

    float soma1 = valor1_carta1 + valor2_carta1;
    float soma2 = valor1_carta2 + valor2_carta2;

    printf("\n========== RESULTADO DA COMPARAÇÃO ==========\n");
    printf("Cidade 1: %s\n", NomeCidade1);
    printf("Cidade 2: %s\n\n", NomeCidade2);

    printf("Atributo 1 (");
    switch (Escolha1) {
        case 1: printf("População"); break;
        case 2: printf("Área"); break;
        case 3: printf("PIB"); break;
        case 4: printf("Pontos Turísticos"); break;
        case 5: printf("Densidade Demográfica"); break;
    }
    printf("):\n");
    printf(" - %s: %.2f\n", NomeCidade1, valor1_carta1);
    printf(" - %s: %.2f\n\n", NomeCidade2, valor1_carta2);

    printf("Atributo 2 (");
    switch (Escolha2) {
        case 1: printf("População"); break;
        case 2: printf("Área"); break;
        case 3: printf("PIB"); break;
        case 4: printf("Pontos Turísticos"); break;
        case 5: printf("Densidade Demográfica"); break;
    }
    printf("):\n");
    printf(" - %s: %.2f\n", NomeCidade1, valor2_carta1);
    printf(" - %s: %.2f\n\n", NomeCidade2, valor2_carta2);

    printf("Soma dos atributos:\n");
    printf(" - %s: %.2f\n", NomeCidade1, soma1);
    printf(" - %s: %.2f\n", NomeCidade2, soma2);

    // Lógica da vitória
    int vencedor = 0; // 0 = empate, 1 = carta 1, 2 = carta 2

    if (Escolha1 == 5) {  // Densidade: MENOR ganha
        if (valor1_carta1 < valor1_carta2) vencedor++;
        else if (valor1_carta2 < valor1_carta1) vencedor += 2;
    } else {
        if (valor1_carta1 > valor1_carta2) vencedor++;
        else if (valor1_carta2 > valor1_carta1) vencedor += 2;
    }

    if (Escolha2 == 5) {
        if (valor2_carta1 < valor2_carta2) vencedor++;
        else if (valor2_carta2 < valor2_carta1) vencedor += 2;
    } else {
        if (valor2_carta1 > valor2_carta2) vencedor++;
        else if (valor2_carta2 > valor2_carta1) vencedor += 2;
    }

    printf("\nResultado final: ");
    if (soma1 > soma2)
        printf("Vencedor: %s\n", NomeCidade1);
    else if (soma2 > soma1)
        printf("Vencedor: %s\n", NomeCidade2);
    else
        printf("Empate!\n");

    return 0;
}
