#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/tela_inicial.h"
#include "../include/funcionarios.h"

Funcionario funcionarios[MAX_FUNCIONARIOS];
int qtd_funcionarios = 0;

void modulo_funcionarios(void) {
    int opcao;
    do {
        system("cls||clear");
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
        printf("///            1. Cadastrar funcionários                                    ///\n");
        printf("///            2. Ver funcionários cadastrados                              ///\n");
        printf("///            3. Pesquisar dados de um funcionário                         ///\n");
        printf("///            4. Editar dados de um funcionário                            ///\n");
        printf("///            5. Excluir funcionários do sistema                           ///\n");
        printf("///            6. Voltar para o menu principal                              ///\n");
        printf("///                                                                         ///\n");
        printf("///            Escolha a opção desejada:                                    ///\n");
        printf("///                                                                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("\n");
        if(scanf("%d", &opcao) != 1){
            while(getchar() != '\n');
            opcao = 0;
        }
        while(getchar() != '\n');

        switch(opcao){
            case 1: tela_cadastrar_funcionario(); break;
            case 2: tela_ver_funcionarios(); break;
            case 3: tela_pesquisar_funcionario(); break;
            case 4: tela_editar_funcionario(); break;
            case 5: tela_excluir_funcionario(); break;
            case 6: return;
            default: printf("Opção inválida!\n"); Enter();
        }
    } while(opcao != 6);
}

void tela_cadastrar_funcionario(void) {
    system("cls||clear");
    if(qtd_funcionarios >= MAX_FUNCIONARIOS){
        printf("Limite de funcionários atingido!\n");
        Enter();
        return;
    }

    Funcionario novo;

    printf("Nome: ");
    fgets(novo.nome, TAM_NOME_FUNC, stdin);
    novo.nome[strcspn(novo.nome, "\n")] = 0;

    printf("Email: ");
    fgets(novo.email, TAM_EMAIL_FUNC, stdin);
    novo.email[strcspn(novo.email, "\n")] = 0;

    printf("Cargo: ");
    fgets(novo.cargo, TAM_CARGO, stdin);
    novo.cargo[strcspn(novo.cargo, "\n")] = 0;

    printf("CPF (apenas números): ");
    fgets(novo.cpf, TAM_CPF_FUNC, stdin);
    novo.cpf[strcspn(novo.cpf, "\n")] = 0;

    funcionarios[qtd_funcionarios++] = novo;

    printf("===================================\n");
    printf("= Cadastro realizado com sucesso! =\n");
    printf("===================================\n");
    Enter();
}

void tela_ver_funcionarios(void) {
    system("cls||clear");
    printf("\n=== Funcionários Cadastrados ===\n");
    if(qtd_funcionarios == 0){
        printf("Nenhum funcionário cadastrado.\n");
    } else {
        for(int i = 0; i < qtd_funcionarios; i++){
            printf("%d. Nome: %s | Email: %s | Cargo: %s | CPF: %s\n",
                i+1, funcionarios[i].nome, funcionarios[i].email, funcionarios[i].cargo, funcionarios[i].cpf);
        }
    }
    Enter();
}

void tela_pesquisar_funcionario(void) {
    system("cls||clear");

    if(qtd_funcionarios == 0){
        printf("Nenhum funcionário cadastrado.\n");
        Enter();
        return;
    }

    char cpf[TAM_CPF_FUNC];
    printf("Digite o CPF do funcionário que deseja visualizar: ");
    fgets(cpf, TAM_CPF_FUNC, stdin);
    cpf[strcspn(cpf, "\n")] = 0;

    int encontrado = -1;
    for(int i = 0; i < qtd_funcionarios; i++){
        if(strcmp(funcionarios[i].cpf, cpf) == 0){
            encontrado = i;
            break;
        }
    }

    if(encontrado == -1){
        printf("\nFuncionário com CPF %s não encontrado.\n", cpf);
    } else {
        int i = encontrado;
        printf("Nome: %s | Email: %s | Cargo: %s | CPF: %s\n",
            funcionarios[i].nome, funcionarios[i].email, funcionarios[i].cargo, funcionarios[i].cpf);
    }
    Enter();
}

void tela_editar_funcionario(void) {
    system("cls||clear");

    if(qtd_funcionarios == 0){
        printf("Nenhum funcionário cadastrado.\n");
        Enter();
        return;
    }

    char cpf[TAM_CPF_FUNC];
    printf("Digite o CPF do funcionário que deseja editar: ");
    fgets(cpf, TAM_CPF_FUNC, stdin);
    cpf[strcspn(cpf, "\n")] = 0;

    int encontrado = -1;
    for(int i = 0; i < qtd_funcionarios; i++){
        if(strcmp(funcionarios[i].cpf, cpf) == 0){
            encontrado = i;
            break;
        }
    }

    if(encontrado == -1){
        printf("\nFuncionário com CPF %s não encontrado.\n", cpf);
        Enter();
        return;
    }

    Funcionario *f = &funcionarios[encontrado];

    printf("Nome: ");
    fgets(f->nome, TAM_NOME_FUNC, stdin);
    f->nome[strcspn(f->nome, "\n")] = 0;

    printf("Email: ");
    fgets(f->email, TAM_EMAIL_FUNC, stdin);
    f->email[strcspn(f->email, "\n")] = 0;

    printf("Cargo: ");
    fgets(f->cargo, TAM_CARGO, stdin);
    f->cargo[strcspn(f->cargo, "\n")] = 0;

    printf("CPF (apenas números): ");
    fgets(f->cpf, TAM_CPF_FUNC, stdin);
    f->cpf[strcspn(f->cpf, "\n")] = 0;

    printf("=======================================\n");
    printf("=    Edição realizada com sucesso!    =\n");
    printf("=======================================\n");
    Enter();
}

void tela_excluir_funcionario(void) {
    system("cls||clear");
    if(qtd_funcionarios == 0){
        printf("Nenhum funcionário para excluir.\n");
        Enter();
        return;
    }

    char cpf[TAM_CPF_FUNC];
    printf("Digite o CPF do funcionário para excluir: ");
    fgets(cpf, TAM_CPF_FUNC, stdin);
    cpf[strcspn(cpf, "\n")] = 0;

    int encontrado = -1;
    for(int i = 0; i < qtd_funcionarios; i++){
        if(strcmp(funcionarios[i].cpf, cpf) == 0){
            encontrado = i;
            break;
        }
    }

    if(encontrado == -1){
        printf("===============================\n");
        printf("= Funcionário não encontrado! =\n");
        printf("===============================\n");
    } else {
        for(int i = encontrado; i < qtd_funcionarios - 1; i++){
            funcionarios[i] = funcionarios[i+1];
        }
        qtd_funcionarios--;
        printf("===================================\n");
        printf("= Exclusão realizada com sucesso! =\n");
        printf("===================================\n");
    }
    Enter();
}


