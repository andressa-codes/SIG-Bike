#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/tela_inicial.h"
#include "../include/funcionarios.h"


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
        printf("/////////////////////////////////////////////////////////////////////////////\n\n");

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
            default:
                printf("Opção inválida!\n");
                Enter();
        }
    } while(opcao != 6);
}

void tela_cadastrar_funcionario(void){
    FILE *arq_funcionarios;
    system("cls||clear");

    Funcionario novo;

    printf("Nome: ");
    fgets(novo.nome, TAM_NOME_FUNC, stdin);
    novo.nome[strcspn(novo.nome, "\n")] = 0;

    printf("Email: ");
    fgets(novo.email, TAM_EMAIL_FUNC, stdin);
    novo.email[strcspn(novo.email, "\n")] = 0;

    printf("Cargo: ");
    fgets(novo.cargo, TAM_CARGO_FUNC, stdin);
    novo.cargo[strcspn(novo.cargo, "\n")] = 0;

    printf("CPF (apenas números): ");
    fgets(novo.cpf, TAM_CPF_FUNC, stdin);
    novo.cpf[strcspn(novo.cpf, "\n")] = 0;

    arq_funcionarios = fopen("dados_funcionarios/funcionarios.csv", "a");
    if(arq_funcionarios == NULL){
        printf("Erro ao abrir o arquivo de funcionários.\n");
        return;
    }

    fprintf(arq_funcionarios, "%s;%s;%s;%s\n", novo.nome, novo.email, novo.cargo, novo.cpf);
    fclose(arq_funcionarios);

    printf("===================================\n");
    printf("= Cadastro realizado com sucesso! =\n");
    printf("===================================\n");
    Enter();
}

void carregar_funcionario_por_cpf(char cpfBuscado[]) {
    FILE *arq;
    char nome[TAM_NOME_FUNC], email[TAM_EMAIL_FUNC], cargo[TAM_CARGO_FUNC], cpf[TAM_CPF_FUNC];

    arq = fopen("dados_funcionarios/funcionarios.csv", "rt");
    if (arq == NULL) {
        printf("Erro: não foi possível abrir o arquivo de funcionários.\n");
        getchar();
        return;
    }

    while (fscanf(arq, "%[^;];%[^;];%[^;];%[^\n]\n", nome, email, cargo, cpf) == 4) {
        if (strcmp(cpf, cpfBuscado) == 0) {
            printf("\n=== Funcionário encontrado ===\n");
            printf("Nome: %s\n", nome);
            printf("Email: %s\n", email);
            printf("Cargo: %s\n", cargo);
            printf("CPF: %s\n", cpf);
            fclose(arq);
            return;
        }
    }

    printf("\nFuncionário com CPF %s não encontrado.\n", cpfBuscado);
    fclose(arq);
}

void tela_ver_funcionarios(void){
    system("cls||clear");
    printf("\n=== Funcionários Cadastrados ===\n");

    FILE *arq = fopen("dados_funcionarios/funcionarios.csv", "rt");
    if (arq == NULL) {
        printf("Nenhum funcionário cadastrado (arquivo vazio ou não encontrado).\n");
        Enter();
        return;
    }

    char nome[TAM_NOME_FUNC], email[TAM_EMAIL_FUNC], cargo[TAM_CARGO_FUNC], cpf[TAM_CPF_FUNC];
    int count = 0;

    while (fscanf(arq, "%[^;];%[^;];%[^;];%[^\n]\n", nome, email, cargo, cpf) == 4) {
        printf("%d. Nome: %s | Email: %s | Cargo: %s | CPF: %s\n",
               ++count, nome, email, cargo, cpf);
    }

    if (count == 0) {
        printf("Nenhum funcionário cadastrado.\n");
    }

    fclose(arq);
    Enter();
}

void tela_pesquisar_funcionario(void){
    system("cls||clear");

    char cpf[TAM_CPF_FUNC];
    printf("Digite o CPF do funcionário que deseja visualizar: ");
    fgets(cpf, TAM_CPF_FUNC, stdin);
    cpf[strcspn(cpf, "\n")] = 0;

    carregar_funcionario_por_cpf(cpf);
    Enter();
}

void tela_editar_funcionario(void){
    system("cls||clear");

    char cpf[TAM_CPF_FUNC];
    printf("Digite o CPF do funcionário que deseja editar: ");
    fgets(cpf, TAM_CPF_FUNC, stdin);
    cpf[strcspn(cpf, "\n")] = 0;

    FILE *arq = fopen("dados_funcionarios/funcionarios.csv", "rt");
    if (!arq) { printf("Erro ao abrir arquivo de funcionários.\n"); Enter(); return; }

    FILE *temp = fopen("dados_funcionarios/temp.csv", "wt");
    if (!temp) { fclose(arq); printf("Erro ao criar arquivo temporário.\n"); Enter(); return; }

    char nome[TAM_NOME_FUNC], email[TAM_EMAIL_FUNC], cargo[TAM_CARGO_FUNC], cpfArq[TAM_CPF_FUNC];
    int encontrado = 0;

    while (fscanf(arq, "%[^;];%[^;];%[^;];%[^\n]\n", nome, email, cargo, cpfArq) == 4) {
        if (strcmp(cpfArq, cpf) == 0) {
            encontrado = 1;
            Funcionario editado;

            printf("Novo Nome: ");
            fgets(editado.nome, TAM_NOME_FUNC, stdin);
            editado.nome[strcspn(editado.nome, "\n")] = 0;

            printf("Novo Email: ");
            fgets(editado.email, TAM_EMAIL_FUNC, stdin);
            editado.email[strcspn(editado.email, "\n")] = 0;

            printf("Novo Cargo: ");
            fgets(editado.cargo, TAM_CARGO_FUNC, stdin);
            editado.cargo[strcspn(editado.cargo, "\n")] = 0;

            strcpy(editado.cpf, cpfArq);

            fprintf(temp, "%s;%s;%s;%s\n", editado.nome, editado.email, editado.cargo, editado.cpf);
        } else {
            fprintf(temp, "%s;%s;%s;%s\n", nome, email, cargo, cpfArq);
        }
    }

    fclose(arq);
    fclose(temp);
    remove("dados_funcionarios/funcionarios.csv");
    rename("dados_funcionarios/temp.csv", "dados_funcionarios/funcionarios.csv");

if (encontrado) {
    printf("=======================================\n");
    printf("=    Edição realizada com sucesso!    =\n");
    printf("=======================================\n");
} else {
        printf("===============================\n");
        printf("= Funcionário não encontrado! =\n");
        printf("===============================\n");
}
Enter();  
}

void tela_excluir_funcionario(void){
    system("cls||clear");

    char cpf[TAM_CPF_FUNC];
    printf("Digite o CPF do funcionário para excluir: ");
    fgets(cpf, TAM_CPF_FUNC, stdin);
    cpf[strcspn(cpf, "\n")] = 0;

    FILE *arq = fopen("dados_funcionarios/funcionarios.csv", "rt");
    if (!arq) { printf("Erro ao abrir arquivo de funcionários.\n"); Enter(); return; }

    FILE *temp = fopen("dados_funcionarios/temp.csv", "wt");
    if (!temp) { fclose(arq); printf("Erro ao criar arquivo temporário.\n"); Enter(); return; }

    char nome[TAM_NOME_FUNC], email[TAM_EMAIL_FUNC], cargo[TAM_CARGO_FUNC], cpfArq[TAM_CPF_FUNC];
    int encontrado = 0;

    while (fscanf(arq, "%[^;];%[^;];%[^;];%[^\n]\n", nome, email, cargo, cpfArq) == 4) {
        if (strcmp(cpfArq, cpf) != 0)
            fprintf(temp, "%s;%s;%s;%s\n", nome, email, cargo, cpfArq);
        else
            encontrado = 1;
    }

    fclose(arq);
    fclose(temp);
    remove("dados_funcionarios/funcionarios.csv");
    rename("dados_funcionarios/temp.csv", "dados_funcionarios/funcionarios.csv");
    

if (encontrado) {
    printf("===================================\n");
    printf("= Exclusão realizada com sucesso! =\n");
    printf("===================================\n");
} else {
    printf("===============================\n");
    printf("= Funcionário não encontrado! =\n");
    printf("===============================\n");
}
Enter();
}
