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
        system("cls||clear");
        printf("\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                                                                         ///\n");
        printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
        printf("///                 Centro de Ensino Superior do Seridó                     ///\n");
        printf("///               Departamento de Computação e Tecnologia                   ///\n");
        printf("///                  Disciplina DCT1106 -- Programação                      ///\n");
        printf("///          Projeto Sistema de Gestão de uma loja de bicicletas            ///\n");
        printf("///   Developed by @andressa-codes and @Jezreel-Asaias -- since Aug, 2025   ///\n");
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

    printf("===================================\n");
    printf("= Cadastro realizado com sucesso! =\n");
    printf("===================================\n");
    Enter();
}

void tela_ver_clientes(void){
    system("cls||clear");
    printf("\n=== Clientes Cadastrados ===\n");
    if(qtd_clientes == 0){
        printf("Nenhum cliente cadastrado.\n");
    } else {
        for(int i = 0; i < qtd_clientes; i++){
            printf("%d. Nome: %s | Email: %s | Cidade: %s | CPF: %s\n",
                i+1, clientes[i].nome, clientes[i].email, clientes[i].cidade, clientes[i].cpf);
        }
    }
    Enter();
}

void tela_pesquisar_cliente(void){
    system("cls||clear");

    if(qtd_clientes == 0){
        printf("Nenhum cliente cadastrado.\n");
        Enter();
        return;
    }

    char cpf[TAM_CPF];
    printf("Digite o CPF do cliente que deseja visualizar: ");
    fgets(cpf, TAM_CPF, stdin);
    cpf[strcspn(cpf, "\n")] = 0;   

    int encontrado = -1;
    for(int i = 0; i < qtd_clientes; i++){
        if(strcmp(clientes[i].cpf, cpf) == 0){
            encontrado = i;
            break;
        }
    }

    if(encontrado == -1){
        printf("\nCliente com CPF %s não encontrado.\n", cpf);
    } else {
        int i = encontrado;
        printf("Nome: %s | cidade: %s | Email: %s | CPF: %s \n",
            clientes[i].nome, clientes[i].cidade, clientes[i].email, clientes[i].cpf
        );
    }
    Enter();
}

void tela_editar_cliente(void){
    system("cls||clear");

    if(qtd_clientes == 0){
        printf("Nenhum cliente cadastrado.\n");
        Enter();
        return;
    }

    char cpf[TAM_CPF];
    printf("Digite o CPF do cliente que deseja editar: ");
    fgets(cpf, TAM_CPF, stdin);
    cpf[strcspn(cpf, "\n")] = 0; 

    int encontrado = -1;
    for(int i = 0; i < qtd_clientes; i++){
        if(strcmp(clientes[i].cpf, cpf) == 0){
            encontrado = i;
            break;
        }
    }

    if(encontrado == -1){
        printf("\nCliente com CPF %s não encontrado.\n", cpf);
        Enter();
        return;
    }

    Cliente *c = &clientes[encontrado];

    printf("Nome: ");
    fgets(c->nome, TAM_NOME, stdin);
    c->nome[strcspn(c->nome, "\n")] = 0;

    printf("Email: ");
    fgets(c->email, TAM_EMAIL, stdin);
    c->email[strcspn(c->email, "\n")] = 0;

    printf("Cidade: ");
    fgets(c->cidade, TAM_CIDADE, stdin);
    c->cidade[strcspn(c->cidade, "\n")] = 0;

    printf("CPF (apenas números): ");
    fgets(c->cpf, TAM_CPF, stdin);
    c->cpf[strcspn(c->cpf, "\n")] = 0;

    printf("=======================================\n");
    printf("=    Edição realizada com sucesso!    =\n");
    printf("=======================================\n");
    Enter();
}

void tela_excluir_cliente(void){
    system("cls||clear");
    if(qtd_clientes == 0){
        printf("Nenhum cliente para excluir.\n");
        Enter();
        return;
    }

    char cpf[TAM_CPF];
    printf("Digite o CPF do cliente para excluir: ");
    fgets(cpf, TAM_CPF, stdin);
    cpf[strcspn(cpf, "\n")] = 0;

    int encontrado = -1;
    for(int i = 0; i < qtd_clientes; i++){
        if(strcmp(clientes[i].cpf, cpf) == 0){
            encontrado = i;
            break;
        }
    }

    system("cls||clear");
    if(encontrado == -1){
        printf("===========================\n");
        printf("= Cliente não encontrado! =\n");
        printf("===========================\n");
    } else {
        for(int i = encontrado; i < qtd_clientes - 1; i++){
            clientes[i] = clientes[i+1];
        }
        qtd_clientes--;
        printf("===================================\n");
        printf("= Exclusão realizada com sucesso! =\n");
        printf("===================================\n");
    }
    Enter();
}