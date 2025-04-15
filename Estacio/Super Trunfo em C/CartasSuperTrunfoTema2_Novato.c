#include <stdio.h>

int main()
{
    int CodigoCarta1, CodigoCarta2, NumeroDePontoTuristico1, NumeroDePontoTuristico2;
    char Estado1, Estado2, NomeCidade1[50], NomeCidade2[50];
    float Area1, Area2, Pib1, Pib2;
    float DensidadePoPulacional1, DensidadePoPulacional2, PibPcapta1, PibPcapta2;
    float Super_Poder1, Super_Poder2;
    unsigned long int NumeroPopulacao1, NumeroPopulacao2;

     //Entrada para Carta 1
    printf("Digite o Numero da carta (1 - 2): ");
    scanf("%d", &CodigoCarta1);
    
    printf("Digite o Estado da Carta (A - H): ");
    scanf(" %c", &Estado1);   //Adiciona espaço antes do %c para ignorar espaços em branco
    
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", NomeCidade1);

    printf("Digite o valor da populacao: ");
    scanf("%lu", &NumeroPopulacao1);
    getchar();

    printf("Digite o valor da area: ");
    scanf("%f", &Area1);   //Alterado para %f
    getchar();

    printf("Digite o PIB: ");
    scanf("%f", &Pib1);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &NumeroDePontoTuristico1);

    //Cálculos para a carta 1
    DensidadePoPulacional1 = (float)NumeroPopulacao1 / Area1;
    PibPcapta1 = (float)Pib1 / NumeroPopulacao1;
    

    printf("\n -------------AGORA VOCE IRA INSERIR OS DADOS DA 2 CARTA----------------\n");

     //Entrada para Carta 2
    printf("Digite o Numero da carta (1 - 2): ");
    scanf("%d", &CodigoCarta2);
    
    printf("Digite o Estado da Carta (A - H): ");
    scanf(" %c", &Estado2);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", NomeCidade2);

    printf("Digite o valor da populacao: ");
    scanf("%lu", &NumeroPopulacao2);

    printf("Digite o valor da area: ");
    scanf("%f", &Area2);   //Alterado para %f

    printf("Digite o PIB: ");
    scanf("%f", &Pib2);

   printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &NumeroDePontoTuristico2);

     //Cálculos para a carta 2
    DensidadePoPulacional2 = (float)NumeroPopulacao2 / Area2;
    PibPcapta2 = (float)Pib2 / NumeroPopulacao2;
    

    Super_Poder1 = NumeroPopulacao1 + Area1 + Pib1 + NumeroDePontoTuristico1 + PibPcapta1 + DensidadePoPulacional1;
    Super_Poder2 = NumeroPopulacao2 + Area2 + Pib2 + NumeroDePontoTuristico2 + PibPcapta2 + DensidadePoPulacional2;

    // Exibição dos resultados
    
    if (NumeroPopulacao1 > NumeroPopulacao2)
    {
        printf("*******************\n"); 
        printf("Comparação de Cartas (Atributos: População)\n");
        printf("Carta 1 - %s :%d\n",NomeCidade1,NumeroPopulacao1);
        printf("Carta 2 - %s :%d\n",NomeCidade2,NumeroPopulacao2);
        printf("resultado: Carta 1 (%s) Venceu\n",NomeCidade1);
        printf("*******************\n"); 
    }
   
    else if (NumeroPopulacao1 = NumeroPopulacao2)
    {
        printf("Resultado: Empate/n");
        printf("Comparação de Cartas (Atributos: População)\n");
    }
    else
    {
        printf("*******************\n"); 
        printf("Comparação de Cartas (Atributos: População)\n");
        printf("Carta 1 - %s :%d\n",NomeCidade1,NumeroPopulacao1);
        printf("Carta 2 - %s :%d\n",NomeCidade2,NumeroPopulacao2);
        printf("resultado: Carta 2 (%s) Venceu\n",NomeCidade2);
        printf("*******************\n ");
    }
    return 0;
}