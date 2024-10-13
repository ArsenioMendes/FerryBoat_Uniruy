#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//==================================================
// DECLARAÇÕES
//==================================================

typedef struct nodePessoa
{ // Estrutura para armazenamento de nomes de pessoas em estrutura de Lista.
    char nomePessoa[30];
    struct nodePessoa *proxPassageiro;
} nodePessoa;

typedef struct nodeCarro
{ // Estrutura principal para a FILA de carros.
    char placa[7];
    char modelo[10];
    struct nodeCarro *proxCarro;
    struct nodePessoa *proxPessoa;
} nodeCarro;

void iniciaFila();
void inserirCarro(nodeCarro* FILA);
void removerCarro(nodeCarro* FILA);
void imprimirCarro(nodeCarro* FILA);
void acessarListaPassageiros(nodeCarro* FILA);


//==================================================
// DECLARAÇÕES
//==================================================

int main()
{ // Método principal

    int opcao;

    nodeCarro *FILA = (nodeCarro *)malloc(sizeof(nodeCarro)); // Alocação de memória na FILA principal.
    nodeCarro *LISTA = (nodePessoa *)malloc(sizeof(nodePessoa)); // Alocação de memória na LISTA principal.
    if (FILA == NULL)
    { // Verifica se a memória foi alocada com sucesso.
        printf("Erro de alocacao de memoria de Fila de carros\n");
        exit(1);
    }
    if (LISTA == NULL)
    { // Verifica se a memória foi alocada com sucesso.
        printf("Erro de alocacao de memoria de Lista de pessoas\n");
        exit(1);
    }
    iniciaLista(LISTA); // Inicia primeiro nó da Lista de pessoas.
    iniciaFila(FILA); // Inicia primeiro nó da fila de carros.

    do // Loop de menu principal.
    {
        printf("\n\n=======MENU_PRINCIPAL_VEICULOS=======\n(1) Adicionar carro a fila \n(2) Retirar o primeiro carro da fila \n(3) Apresentar todos os carros \n(4) Acessar menu de passageiros...: \n(0) Encerrar programa.\nSelecione o numero correspondente a opcao desejada: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("\n==========ADICIONANDO_CARRO==========\n");
            inserirCarro(FILA);
            break;
        case 2:
            printf("\n==========REMOVENDO_CARRO==========\n");
            removerCarro(FILA); 
            break;
        case 3:
            printf("\n==========IMPRIMINDO_FILA_DE_CARROS==========\n");
            imprimirCarro(FILA); 
            break;
        case 4:
            printf("\n==========ACESSANDO_MENU_PASSAGEIROS==========\n");
            acessarListaPassageiros(FILA);
            break;
        }
    } while (opcao != 0);

    printf("\n=======================\n=O Ferry boat afundou.=\n=======================");
    return 0;
}

void iniciaFila(nodeCarro *FILA)
{
    FILA->proxCarro = NULL;
}
void iniciaLista(nodePessoa *LISTA)
{
    LISTA->proxPassageiro = NULL;
}


//==================================================
//METODOS DE CARROS
//==================================================
void removerCarro(nodeCarro* FILA){
	
	nodeCarro *ant=FILA;
	nodeCarro *suc=FILA->proxCarro;
	
	while(suc->proxCarro!=NULL){
		ant=suc;
		suc=suc->proxCarro;
	}
	ant->proxCarro=NULL;
	free(suc);
    printf("Removido o primeiro carro da fila.");
}

void inserirCarro(nodeCarro* FILA){
	nodeCarro *novo = (nodeCarro *)malloc(sizeof(nodeCarro));
    if (novo == NULL) {
        printf("Erro de alocacao de memoria\n");
        return;
    }
    
    printf("\nPlaca do carro por favor: ");
    scanf(" %6s", &novo->placa);  
    printf("\nModelo do carro por favor: ");
    scanf(" %9s", &novo->modelo);  

    novo->proxCarro = NULL;  // Novo carro será o último, então o próximo deve ser NULL.

    // Encontrar o último carro na fila
    nodeCarro *temp = FILA;
    while (temp->proxCarro != NULL) {
        temp = temp->proxCarro;
    }

    // Insere o novo carro no final da fila
    temp->proxCarro = novo;
}

void imprimirCarro(nodeCarro* FILA){
	nodeCarro *temp;
	temp=FILA->proxCarro;
    int posicao = 0;
    printf("Imprimindo por posicao:");
	while(temp!=NULL){
        printf("\n============\nPosicao: %d", posicao);
        if(posicao == 0){
            printf(" (Primeiro da fila)");
        }
		printf("\nPlaca: %s", temp->placa);
        printf("\nModelo: %s", temp->modelo);
		temp=temp->proxCarro;
        ++ posicao;
	}
}
//==================================================
//METODOS DE CARROS
//==================================================

void acessarListaPassageiros(nodeCarro *FILA)
{
    int posicaoCarro;
    int contador = 0;
    int opcaoMenu = 0;
    nodeCarro *AUX = FILA->proxCarro; //Aponta para a proxima pessoa baseada na estrutura de nó da fila de carro.

    printf("\n\nQual carro deseja acessar?:\n---------------------------\n");
    imprimirCarro(FILA);
    printf("\n---------------------------\nPosicao?: ");
    scanf("%d", &posicaoCarro); //Pega a posicao do carro.

    while (contador < posicaoCarro && AUX != NULL)
    {
        AUX = AUX->proxCarro;
        contador++;
    }

    if (AUX == NULL)
    {
        printf("Posicao nao encontrada.\n");
        return;
    }

    nodePessoa **LISTA = &AUX->proxPessoa; // Acessa o primeiro nó de passageiro.

    if (*LISTA == NULL)
    {
        *LISTA = NULL;
    }

    printf("\n====ACESSANDO_PLACA: %s====", AUX->placa);

    do
    {
        printf("\n\n====MENU_DE_PASSAGEIROS DA PLACA: %s====\n1. Adicionar Passageiro \n2. Remover Passageiro (Ferry + Placa) \n3. Transferir Passageiro \n4. Apresentar Passageiros. \n0. Voltar.\nOpcao?: ", AUX->placa);
        scanf("%d", &opcaoMenu);

        switch (opcaoMenu)
        {
        case 1:
            printf("\n==========Adicionando Passageiro à placa: %s==========\n", AUX->placa);
            adicionarPassageiro(LISTA);
            break;
        case 2:
            printf("\n==========Removendo Passageiro da placa (Remover do Ferry!): %s==========\n", AUX->placa);
            removerPassageiro(LISTA);
            break;
        case 3:
            printf("\n==========Transferir pessoa da placa: %s==========\n", AUX->placa);
            transferirPassageiro(LISTA);
            break;
        case 4:
            printf("\n==========Apresentando pessoa da placa: %s==========\n", AUX->placa);
            apresentarPassageiro(LISTA);
            break;
        }

    } while (opcaoMenu != 0);
    }

//==================================================
//METODOS DE PASSAGEIROS
//==================================================
    void adicionarPassageiro(nodePessoa **LISTA){
        //IMPLEMENTAR
    };

    void removerPassageiro(nodePessoa **LISTA){
        //IMPLEMENTAR
    };

    void transferirPassageiro(nodePessoa **LISTA){
        //IMPLEMENTAR
    };

    void apresentarPassageiro(nodePessoa **LISTA){
        //IMPLEMENTAR
    };

//==================================================
//METODOS DE PASSAGEIROS
//==================================================



