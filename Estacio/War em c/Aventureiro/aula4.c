//mão no codigo
//Pratica: sistema de bibilioteca
//Objetico desta parte
//Adicionar a funcionalidade de emprestimo e introduzir alocação de dinâminca
// - os Arrays de livros e empréstimos são alocados com malloc/calloc
// - Novas struct para Emprestimos
// - liberação de memoria com free

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// ---- Constantes Globais ----

#define MAX_LIVROS 50
#define MAX_EMPRESTIMOS 100
#define TAM_string 100

//-- definição de estrutura 
// struct livro agora tem um campo "disponivel " para controlar o status

struct livro
{
    char nome[TAM_string];
    char autor[TAM_string];
    char editora[TAM_string];
    int edicao;
    int disponivel; // 1 para sim e 0 para não
};

//Nova struct para armazenar informações de emprestimo
struct Emprestimo
{
    int indicieLivro; 
    char nomeUsuario[TAM_string];
};

// -- Função para limpar o buffer de entrada --
void limparBufferEntrada(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


// Função principal
int main(){
    //1 Alicação dinamica de memoria
    //Agora, em vez de arrays estáticos, usamos ponteiros
    struct livro *bibiloteca;
    struct Emprestimo *emprestimo;

    //Usamos calloc para o array de livros .calloc(num_elemntos, tamanhos_de_cada_elemento)
    // Vantagem: inicializa toda a memoria com zeros. isso significa que "indisponivel ja começa com 0"
    bibiloteca = (struct Livro *) calloc(MAX_LIVROS, sizeo(struct Livro));

    //Usamos malloca para o array de emprestimos. malloc tamanhi titak en bytes
    emprestimo = (struct Emprestimo *) malloc (MAX_EMPRESTIMOS * sizeof (struct Emprestimo));

    //VERIFICAÇÂO: É crucial verificar se a alocação de memoria deu certo
    if (bibiloteca == NULL || emprestimo == NULL){
        printf("Erro: falha ao alocar memoria.\n");
        return 1;
    }

    int totalLivros = 0;
    int totalEmprestimos = 0;
    int opcao;

    do
    {
        printf("===========================================\n");
        printf("    Biblioteca - parte 2\n");
        printf("===========================================\n");
        printf("1 - Cadastrar novo livro\n");
        printf("2 - Listar todos os livros\n");
        printf("3 - Realizar Emprestimos\n");
        printf("4 - Listar emprestimos\n");
        printf("0 - SAIR\n");
        printf("===================================================\n");
        printf("Escolha uma das opções acima\n");
        scanf("%d",&opcao);
        limparBufferEntrada();
        
        






    } while (condition);
    
}

