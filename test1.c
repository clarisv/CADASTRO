#include<stdio.h>
#define TAM 3 //<- o TAM 3 significa quantos pode cadastrar
 typedef struct{
    char nome[20];
    int idade;
    int id;
    int status;
}Pessoa;

void cadastrar(Pessoa p[], int indice){
    p[indice].status = 1;
    p[indice].id = rand() % 100;
    printf("Digite o nome do aluno:\n");
    fflush(stdin);

    fgets(p[indice].nome, sizeof(p[indice].nome), stdin);
    fflush(stdin);

    printf("Digite a idade:\n");
    fflush(stdin);
    scanf("%d", &p[indice].idade);

    fflush(stdin);
    printf("\n\n");
}
void imprimirLista(Pessoa p[], int totalCadastrados){
    for(int i = 0; i < totalCadastrados; i++){
        printf("ID: %d\n", p[i].id);
        printf("Nome: %s", p[i].nome);
        printf("Idade: %d", p[i].idade);
        if(p[i].status == 1){
            printf("\nStatus Ativo.");
        }else{
            printf("\nStatus Inativo.");
        }
        printf("\n\n");
    }
}

void buscar(Pessoa p[], int totalCadastrados, int id){
    if(totalCadastrados == 0){
        printf("Lista vazia");
        return;

    }else{
        for(int i = 0; i < totalCadastrados; i++){
            if(p[i].id == id){
                printf("Nome: %s", p[i].nome);
                printf("Idade: %d", p[i].idade);
                return;

            }

        }

    }
    printf("Nao existe o registro na lista.\n");
}

void alterar(Pessoa p[], int totalCadastrados, int id){
    int escolha;
    if(totalCadastrados == 0){
        printf("Lista vazia");
        return;

    }else{
        for(int i = 0; i < totalCadastrados; i++){
            if(p[i].id == id){
                //achei na lista
                printf("\n1 - Alterar nome");
                printf("\n2 - Alterar idade");
                printf("\n3 - Alterar status");
                printf("\n4 - Alterar tudo");
                printf("\nEscolha uma opcao:");
                scanf("%d", &escolha);

                switch(escolha){
                    case 1:
                        printf("1- Alterar nome:\n");
                        fgets(p[i].nome, sizeof(p[i].nome), stdin);
                        break;

                    case 2:
                        printf("\n2 - Alterar idade:");
                        scanf("%d", &p[i].idade);
                        break;

                    case 3: 
                        printf("Alterar status 3 - Ativo / 0 - Inativo: ");
                        scanf("%d", &p[i].status);
                        break;

                    case 4: 
                        printf("Alterar nome:\n");
                        fgets(p[i].nome, sizeof(p[i].nome), stdin);

                        printf("\nAlterar idade:");
                        scanf("%d", &p[i].idade);

                        printf("Alterar status 1 - Ativo / 0 - Inativo");
                        scanf("%d", &p[i].status);

                    default:{
                        printf("Opcao invalida.\n");
                    }  
                    }

                return;

            }

        }

    }
    //nao achei na lista
    printf("Nao existe o registro na lista.\n");
}

void excluir(Pessoa p[], int totalCadastrados, int id){
    if(totalCadastrados == 0){
        printf("Lista vazia");
        return;

    }else{
        for(int i = 0; i < totalCadastrados; i++){
            if(p[i].id == id){
                //percorrer as posicoes subsequentes para reposicionar o id
                for(int j = i; j < totalCadastrados; j++){
                    p[j] = p[j+1];
                }
                return;

            }

        }

    }
    printf("Nao existe o registro na lista.\n");
}


int main(){

    Pessoa p[TAM];

    int opcao, totalCadastrados = 0, buscaID;

    do{
        printf("\nPara cadastrar, digite 1.\n");
        printf("Para visualizar o cadastro, digite 2.\n");
        printf("Para buscar um cadastro, digite 3.\n");
        printf("Para alterar um cadastro, digite 4.\n");
        printf("Para excluir um cadastro, digite 5.\n");
        printf("Para sair, digite 0.\n");
        

        printf("\n\n");

        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            if(totalCadastrados < TAM){
                cadastrar(p, totalCadastrados);
                totalCadastrados++;
            }else{
                printf("\nTotal de cadastros atingido.");
            }
            break;
        case 2:
        if(totalCadastrados == 0){
            printf("\nNao existem pessoas na lista");
        }else{
            imprimirLista(p, totalCadastrados);
        }
            break;

        case 3:
            printf("\nDigite o id para buscar: ");
            scanf("%d", &buscaID);
            buscar(p, totalCadastrados, buscaID);
            break;

            printf("Voce digitou 0, o cadastro sera encerrado");
        
        case 4:
            printf("\nDigite o id para alterar: ");
            scanf("%d", &buscaID);
            alterar(p, totalCadastrados, buscaID);
            break;

        case 5:
            printf("\nDigite o id para excluir: ");
            scanf("%d", &buscaID);
            excluir(p, totalCadastrados, buscaID);
            printf("\nRegistro excluido com sucesso.\n");
            break;

        default:
            printf("Voce digitou 0, o cadastro sera encerrado");
        }
    }while(opcao != 0);
}