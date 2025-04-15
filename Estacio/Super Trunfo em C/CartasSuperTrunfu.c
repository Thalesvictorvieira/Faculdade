#include <stdio.h>

int main()
{
    int CodigoCarta1,CodigoCarta2,NumeroDePontoTuristico1,NumeroDePontoTuristico2;
    char Estado1,Estado2,NomeCidade1[50],NomeCidade2[50];
    float NumeroPopulacao1,NumeroPopulacao2,Area1,Area2,Pib1,Pib2;


    //Solicita ao usuário o numero da carta 
    printf("Digite o Numero da carta (1 - 2): ");
    scanf("%d",&CodigoCarta1);
    //getchar() limpa o endereço de memoria
    getchar();
   
    // Solicita ao Usuário o Estado da carta, Armazena o valor na variavel   Estado
    printf("Digite o Estado da Carta (A - H): ");
    scanf("%c",&Estado1);
    getchar();

    //Solicita ao usuário o nome da ciadade. Armazena o valor na variavel   NomeCidade
    printf("Digite o nome da cidade: ");
    scanf("%[^\n]",NomeCidade1);
    getchar();


    //Solicitao ao usuário o numero da população e armazeno o valor na variavel   NumeroPupulacao
    printf("Digite o valor da populacao: ");
    scanf("%f",&NumeroPopulacao1);

    //Solicita ao usuário o valor da area e armazena o valor na variavel   Area
    printf("Digite o valor da area: ");
    scanf("%f",&Area1);
    getchar();

    //Solicita ao usuário o PIB e armazena o valor na variavel    Pib
    printf("Digite o PIB: ");
    scanf("%f",&Pib1);
    getchar();

    //Solicita ao Usuário o numero de pontos turisticos E armazena na variavel    NumeroDePontoTuristico
    printf("Digite o numero de pontos turisticos: ");
    scanf("%d",&NumeroDePontoTuristico1);


    //Alerta ao usuario que ele irar preencher os dados da 2 carta
    printf("\n -------------AGORA VOCE IRA INSERIR OS DADOS DA 2 CARTA----------------\n");



    //Solicita ao usuário o numero da carta 
    printf("Digite o Numero da carta (1 - 2): ");
    scanf("%d",&CodigoCarta2);
    //getchar() limpa o endereço de memoria
    getchar();

    // Solicita ao Usuário o Estado da carta, Armazena o valor na variavel   Estado
    printf("Digite o Estado da Carta (A - H): ");
    scanf("%c",&Estado2);
    getchar();

    //Solicita ao usuário o nome da ciadade. Armazena o valor na variavel   NomeCidade
    printf("Digite o nome da cidade: ");
    scanf("%[^\n]",NomeCidade2);
    getchar();


    //Solicitao ao usuário o numero da população e armazeno o valor na variavel   NumeroPupulacao
    printf("Digite o valor da populacao: ");
    scanf("%f",&NumeroPopulacao2);

    //Solicita ao usuário o valor da area e armazena o valor na variavel   Area
    printf("Digite o valor da area: ");
    scanf("%f",&Area2);
    getchar();

    //Solicita ao usuário o PIB e armazena o valor na variavel    Pib
    printf("Digite o PIB: ");
    scanf("%f",&Pib2);
    getchar();

    //Solicita ao Usuário o numero de pontos turisticos E armazena na variavel    NumeroDePontoTuristico
    printf("Digite o numero de pontos turisticos: ");
    scanf("%d",&NumeroDePontoTuristico2);


    printf("\nCarta: %d \n", CodigoCarta1);
    printf("Estado: %c \n", Estado1);
    printf("Codigo: %c%02d  \n", Estado1,CodigoCarta1);  //  Para contatenar o valor do codigo usa %c%02d Para juntar os vlores das variaveis Estado com Codigo carta
    printf("Nome da Cidade: %s \n", NomeCidade1);
    printf("Populacao: %f \n", NumeroPopulacao1);  // 
    printf("Area: %.2f \n", Area1);  // Limitando a 2 casas decimais
    printf("PIB: %.2f \n", Pib1);  // Limitando a 2 casas decimais
    printf("Numero de pontos turisticos: %d \n", NumeroDePontoTuristico1);


    printf("\nCarta: %d \n", CodigoCarta2);
    printf("Estado: %c \n", Estado2);
    printf("Codigo: %c%02d  \n", Estado2,CodigoCarta2);  //  Para contatenar o valor do codigo usa %c%02d Para juntar os vlores das variaveis Estado com Codigo carta
    printf("Nome da Cidade: %s \n", NomeCidade2);
    printf("Populacao: %f \n", NumeroPopulacao2);  // 
    printf("Area: %.2f \n", Area2);  // Limitando a 2 casas decimais
    printf("PIB: %.2f \n", Pib2);  // Limitando a 2 casas decimais
    printf("Numero de pontos turisticos: %d \n", NumeroDePontoTuristico2);
    return 0;
}
