#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Pessoa
{
    int id;
    char nome[30];
    int idade;
    struct Pessoa *prox;  
    //ponteiro que irar apontar para uma nova pessoa na lista 
    //guarda o endereço de memoria da proxima pessoa
}Pessoa;
//funcao que cria a lista vazia
Pessoa* criarListaVazia(){ //iniciar lista vazia
    return NULL;    
}
//criar funcao que ira criar uma nova pessoa
//retornar o endereço da nova pessoa
Pessoa* criarPessoa(){
    //definir endereço de memoria da pessoa,alocando de forme dinamica
    Pessoa *novaPessoa;
    novaPessoa = (Pessoa*)malloc(sizeof(Pessoa));
        if(novaPessoa == NULL){
        //verificar se foi criado corretamente o armazenamento da nova pessoa ou se retornou nulo
        //memoria insuficiente
        printf("Erro de alocacao");
        exit(EXIT_FAILURE); //funcao que sai do programa e para de executar
        }
        novaPessoa->prox = NULL;
        return novaPessoa; //endereco de memoria alocado para a nova pessoa
}
//agora criar funcao para cadastrar pessoa na lista
Pessoa* cadastrar(Pessoa *lista){//chamar funcao que cria pessoas como parametro
    //criar ponteiro que ira cadastrar pessoa
    Pessoa *novaPessoa = criarPessoa();
    //no endereco de memoria iremos inserir as informacoes
    srand(time(NULL));
    novaPessoa->id = rand() % 100;
    printf("Digite o nome: ");
    fflush(stdin);
    fgets(novaPessoa->nome, sizeof(novaPessoa), stdin);
    printf("Digite a idade: ");
    fflush(stdin);
    scanf("%d", &novaPessoa->idade);

    //duas situacoes 1 - lista vazia, 2 - ja tem alguem na lista
    
    if (lista == NULL){
        return novaPessoa;
    }else{
        //percorrer a lista ate encontrar quem aponta pra NULL
        //criar um ponteiro auxiliar para percorrer
        //atual aponta para lista que a 1 pessoa
        //enquanto o proximo da lista for diferente de NULL
        //quando atual apontar para NULL inserimos a nova pessoa

        Pessoa *atual = lista;
        while (atual->prox != NULL){
            atual = atual->prox;
        }

        atual->prox = novaPessoa;
        return lista;
    }
}

void mostrar(Pessoa *lista){
    if (lista == NULL){
        printf("Lista vazia\n");
    }else{
        Pessoa *atual = lista;
        while (atual != NULL){
            printf("ID: %d\n", atual->id);
            printf("Nome: %s\n", atual->nome);
            printf("Idade: %d\n", atual->idade);
            atual = atual->prox;
        }
    }
}


main(){
    
    int opcao;
    Pessoa *lista = criarListaVazia(); //inicializa a lista vazia no main
    do
    {
        printf("\n1: Cadastrar");
        printf("\n2: Mostrar");
        printf("\n3: Buscar");
        printf("\n4: Alterar");
        printf("\n5: Excluir");
        printf("\n0 : Sair");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            lista = cadastrar(lista);
            break;
        case 2:
            
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            break;
        }

    } while (opcao != 0);
    
}

