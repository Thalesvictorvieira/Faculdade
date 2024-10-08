#include <stdio.h>
#include <math.h>
#include <string.h>
int main(){
    float nota1, nota2, media;
    printf("Digite uma nota");
    scanf("%f", &nota1);
    
    printf("Digite a outra nota");
    scanf("%f", &nota2);
    media = (nota1 + nota2) / 2;

    if (media>= 70)
    {printf("O aluno foi aprovado\n");}
    
    else if (media >=40)
    {printf("O aluno esta de recuperaçao");}
    else
        printf("REprovado\n");
    
    printf("A média foi de %.2f",media);

    return 0;
};