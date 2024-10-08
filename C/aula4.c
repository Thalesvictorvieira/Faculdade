#include <stdio.h>
#include <math.h>
#include <string.h>

int main(){
    int tabuada = 0 ;
    int resultado = 0;
    
    printf("Digite um numero");
    scanf("%d",&tabuada);
    int cont = 0;
    


    while (cont <= 10)
    {
    resultado = tabuada * cont;
    printf("%d x %d = %d \n",tabuada,cont,resultado);
    cont++;
    }
    

}
