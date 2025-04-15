#include <string.h>
int main(){
    int dia;
    printf("Digite um numero de 1 a 7 para representar um dia da semana\n");
    scanf("%d",&dia);
    switch (dia)
    {
    case 1:
        printf("Domingo\n");
        break;
    case 2:
        printf("Segunda\n");
        break;
    case 3:
        printf("Terça\n");
        break;
    case 4:    
        printf("Quarta\n");
        break;
    case 5:   
        printf("Quinta\n");
        break;
    case 6:
        printf("Sexta\n");
        break;
    case 7:
        printf("Sabado\n");
        break;
    
    default:
        printf("opcao invalida Por favor digite um numero inteiro valido");
        break;
    }
    return 0;
}