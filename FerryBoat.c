#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//==================================================
// DECLARAÇÕES
//==================================================

typedef struct nodePessoa
{ // Estrutura para armazenamento de nomes de pessoas em estrutura de Lista encadeada Simples.
    char nomePessoa[30];
    struct nodePessoa *prox;
} nodePessoa;

typedef struct nodeCarro
{ // Estrutura principal para a FILA de carros.
    char placa[7];
    char modelo[15];
    struct nodeCarro *prox;
    struct nodePessoa *proxPessoa;
} nodeCarro;

void iniciaLista();

//==================================================
// Funções/métodos:
//==================================================

int main()
{ // Método principal

    int opcao;

    nodeCarro *LISTA = (nodeCarro *)malloc(sizeof(nodeCarro)); // Alocação de memória na lista principal.
    if (LISTA == NULL)
    { // Verifica se a memória foi alocada com sucesso.
        printf("Erro de alocacao de memoria\n");
        exit(1);
    }
    iniciaLista(LISTA); // Inicia primeiro nó da fila de carros.

    do // Loop de menu principal.
    {
        printf("\n\n=======MENU_PRINCIPAL_VEICULOS=======\n(1) Adicionar carro a fila \n(2) Retirar o primeiro carro da fila \n(3) Apresentar todos os carros \n(4) Acessar menu de passageiros...: \n(0) Encerrar programa.\nSelecione o numero correspondente a opcao desejada: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("\n==========ADICIONANDO_CARRO==========\n");
            //adicionarCarro(LISTA); - ALUNO
            break;
        case 2:
            printf("\n==========REMOVENDO_CARRO==========\n");
            //removerCarro(LISTA); - ALUNO
            break;
        case 3:
            printf("\n==========IMPRIMINDO_FILA_DE_CARROS==========\n");
            //imprimirCarros(LISTA); - ALUNO
            break;
        case 4:
            printf("\n==========ACESSANDO_MENU_PASSAGEIROS==========\n");
            //acessarPassageiros(LISTA); - ALUNO
            break;
        }
    } while (opcao != 0);

    printf("\n=======================\n=O Ferry boat afundou.=\n=======================");
    return 0;
}

void iniciaLista(nodeCarro *LISTA)
{
    LISTA->prox = NULL;
}
