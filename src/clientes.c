#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/tela_inicial.h"
#include "../include/clientes.h"

Cliente clientes[MAX_CLIENTES];
int qtd_clientes = 0;

void modulo_clientes(void) {
    int opcao;

    do {
        system("clear||cls");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                                                                         ///\n");
        printf("///                   ____ ___ ____       ____  _ _                         ///\n");
        printf("///                  / ___|_ _/ ___|     | __ )(_) | _____                  ///\n");
        printf("///                  \\___ \\| | |  _ _____|  _ \\| | |/ / _ \\                 ///\n");
        printf("///                   ___) | | |_| |_____| |_) | |   <  __/                 ///\n");
        printf("///                  |____/___\\____|     |____/|_|_|\\_\\___|                 ///\n");
        printf("///                                                                         ///\n");
        printf("///                                                                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                                                                         ///\n");
        printf("///                    = = = = = SIG-Bike = = = = =                         ///\n");
        printf("///                                                                         ///\n");
        printf("///            1. Cadastrar cliente                                         ///\n");
        printf("///            2. Ver clientes cadastrados                                  ///\n");
        printf("///            3. Pesquisar dados de um cliente                             ///\n");
        printf("///            4. Editar dados de um cliente                                ///\n");
        printf("///            5. Excluir cliente do sistema                                ///\n");
        printf("///            6. Voltar para o menu principal                              ///\n");
        printf("///                                                                         ///\n");
        printf("///            Escolha a opção desejada:                                    ///\n");
        printf("///                                                                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        if(scanf("%d", &opcao) != 1){
            while(getchar() != '\n');
            opcao = 0;
        }
        while(getchar() != '\n');

        switch(opcao){
            case 1:
                tela_cadastrar_cliente();
                break;
            case 2:
                tela_ver_clientes();
                break;
            case 3:
                tela_pesquisar_cliente();
                break;
            case 4:
                tela_editar_cliente();
                break;
            case 5:
                tela_excluir_cliente();
                break;
            case 6: 
                return;
            default:
                printf("Opção inválida!\n");
                Enter();
        }
    } while(opcao != 6);
}

void tela_cadastrar_cliente(void){
    FILE *arq_clientes;
    system("cls||clear");
    if(qtd_clientes >= MAX_CLIENTES){
        printf("Limite de clientes atingido!\n");
        Enter();
        return;
    }

    Cliente novo;

    printf("Nome: ");
    fgets(novo.nome, TAM_NOME, stdin);
    novo.nome[strcspn(novo.nome, "\n")] = 0;

    printf("Email: ");
    fgets(novo.email, TAM_EMAIL, stdin);
    novo.email[strcspn(novo.email, "\n")] = 0;

    printf("Cidade: ");
    fgets(novo.cidade, TAM_CIDADE, stdin);
    novo.cidade[strcspn(novo.cidade, "\n")] = 0;

    printf("CPF (apenas números): ");
    fgets(novo.cpf, TAM_CPF, stdin);
    novo.cpf[strcspn(novo.cpf, "\n")] = 0;

    clientes[qtd_clientes++] = novo;

    arq_clientes = fopen("dados/clientes.csv", "a");
    if(arq_clientes == NULL){
        printf("Erro ao abrir o arquivo de clientes.\n");
        return;
    }

    fprintf(arq_clientes, "%s;", novo.nome);
    fprintf(arq_clientes, "%s;", novo.email);
    fprintf(arq_clientes, "%s;", novo.cidade);
    fprintf(arq_clientes, "%s\n", novo.cpf);
    fclose(arq_clientes);

    printf("===================================\n");
    printf("= Cadastro realizado com sucesso! =\n");
    printf("===================================\n");
    Enter();
}

void carregar_cliente_por_cpf(char cpfBuscado[]) {
    FILE *arq;
    char nome[TAM_NOME];
    char email[TAM_EMAIL];
    char cidade[TAM_CIDADE];
    char cpf[TAM_CPF];

    arq = fopen("dados/clientes.csv", "rt");
    if (arq == NULL) {
        printf("Erro: não foi possível abrir o arquivo de clientes.\n");
        getchar();
        return;
    }

    while (fscanf(arq, "%[^;];%[^;];%[^;];%[^\n]\n", nome, email, cidade, cpf) == 4) {
        if (strcmp(cpf, cpfBuscado) == 0) {
            printf("\n=== Cliente encontrado ===\n");
            printf("Nome: %s\n", nome);
            printf("Email: %s\n", email);
            printf("Cidade: %s\n", cidade);
            printf("CPF: %s\n", cpf);
            fclose(arq);
            return;
        }
    }

    printf("\nCliente com CPF %s não encontrado.\n", cpfBuscado);
    fclose(arq);
}

void tela_ver_clientes(void){
    system("cls||clear");
    printf("\n=== Clientes Cadastrados ===\n");

    FILE *arq = fopen("dados/clientes.csv", "rt");
    if (arq == NULL) {
        printf("Nenhum cliente cadastrado (arquivo vazio ou não encontrado).\n");
        Enter();
        return;
    }

    char nome[TAM_NOME], email[TAM_EMAIL], cidade[TAM_CIDADE], cpf[TAM_CPF];
    int count = 0;

    while (fscanf(arq, "%[^;];%[^;];%[^;];%[^\n]\n", nome, email, cidade, cpf) == 4) {
        printf("%d. Nome: %s | Email: %s | Cidade: %s | CPF: %s\n",
               ++count, nome, email, cidade, cpf);
    }

    if (count == 0) {
        printf("Nenhum cliente cadastrado.\n");
    }

    fclose(arq);
    Enter();
}

void tela_pesquisar_cliente(void) {
    system("cls||clear");

    char cpf[TAM_CPF];
    printf("Digite o CPF do cliente que deseja visualizar: ");
    fgets(cpf, TAM_CPF, stdin);
    cpf[strcspn(cpf, "\n")] = 0;

    carregar_cliente_por_cpf(cpf);
    Enter();
}

void tela_editar_cliente(void) {
    system("cls||clear");

    char cpf[TAM_CPF];
    printf("Digite o CPF do cliente que deseja editar: ");
    fgets(cpf, TAM_CPF, stdin);
    cpf[strcspn(cpf, "\n")] = 0;

    FILE *arq = fopen("dados/clientes.csv", "rt");
    if (!arq) {
        printf("Erro ao abrir arquivo de clientes.\n");
        Enter();
        return;
    }

    FILE *temp = fopen("dados/temp.csv", "wt");
    if (!temp) {
        fclose(arq);
        printf("Erro ao criar arquivo temporário.\n");
        Enter();
        return;
    }

    char nome[TAM_NOME], email[TAM_EMAIL], cidade[TAM_CIDADE], cpfArq[TAM_CPF];
    int encontrado = 0;

    while (fscanf(arq, "%[^;];%[^;];%[^;];%[^\n]\n", nome, email, cidade, cpfArq) == 4) {
        if (strcmp(cpfArq, cpf) == 0) {
            encontrado = 1;
            Cliente editado;

            printf("Novo Nome: ");
            fgets(editado.nome, TAM_NOME, stdin);
            editado.nome[strcspn(editado.nome, "\n")] = 0;

            printf("Novo Email: ");
            fgets(editado.email, TAM_EMAIL, stdin);
            editado.email[strcspn(editado.email, "\n")] = 0;

            printf("Nova Cidade: ");
            fgets(editado.cidade, TAM_CIDADE, stdin);
            editado.cidade[strcspn(editado.cidade, "\n")] = 0;

            strcpy(editado.cpf, cpfArq);

            fprintf(temp, "%s;%s;%s;%s\n", editado.nome, editado.email, editado.cidade, editado.cpf);
        } else {
            fprintf(temp, "%s;%s;%s;%s\n", nome, email, cidade, cpfArq);
        }
    }

    fclose(arq);
    fclose(temp);
    remove("dados/clientes.csv");
    rename("dados/temp.csv", "dados/clientes.csv");

    if (encontrado) {
        printf("=======================================\n");
        printf("=    Edição realizada com sucesso!    =\n");
        printf("=======================================\n");
    } else {
        printf("\nCliente com CPF %s não encontrado.\n", cpf);
    }
    Enter();
}

void tela_excluir_cliente(void) {
    system("cls||clear");

    char cpf[TAM_CPF];
    printf("Digite o CPF do cliente para excluir: ");
    fgets(cpf, TAM_CPF, stdin);
    cpf[strcspn(cpf, "\n")] = 0;

    FILE *arq = fopen("dados/clientes.csv", "rt");
    if (!arq) {
        printf("Erro ao abrir arquivo de clientes.\n");
        Enter();
        return;
    }

    FILE *temp = fopen("dados/temp.csv", "wt");
    if (!temp) {
        fclose(arq);
        printf("Erro ao criar arquivo temporário.\n");
        Enter();
        return;
    }

    char nome[TAM_NOME], email[TAM_EMAIL], cidade[TAM_CIDADE], cpfArq[TAM_CPF];
    int encontrado = 0;

    while (fscanf(arq, "%[^;];%[^;];%[^;];%[^\n]\n", nome, email, cidade, cpfArq) == 4) {
        if (strcmp(cpfArq, cpf) != 0) {
            fprintf(temp, "%s;%s;%s;%s\n", nome, email, cidade, cpfArq);
        } else {
            encontrado = 1;
        }
    }

    fclose(arq);
    fclose(temp);
    remove("dados/clientes.csv");
    rename("dados/temp.csv", "dados/clientes.csv");

    if (encontrado) {
        printf("===================================\n");
        printf("= Exclusão realizada com sucesso! =\n");
        printf("===================================\n");
    } else {
        printf("===========================\n");
        printf("= Cliente não encontrado! =\n");
        printf("===========================\n");
    }
    Enter();
}