#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/tela_inicial.h"
#include "../include/funcionarios.h"

#define TEMP_FUNC "dados/temp_funcionarios.dat"

void modulo_funcionarios(void) {
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

        if (scanf("%d", &opcao) != 1) { while(getchar()!='\n'); opcao = 0; }
        while(getchar()!='\n');

        switch (opcao) {
            case 1: tela_cadastrar_funcionario(); break;
            case 2: tela_ver_funcionarios(); break;
            case 3: tela_pesquisar_funcionario(); break;
            case 4: tela_editar_funcionario(); break;
            case 5: tela_excluir_funcionario(); break;
            case 6: return;
            default: printf("Opção inválida!\n"); Enter();
        }
    } while (opcao != 6);
}

int funcionario_existe_arquivo(const char *cpf) {
    FILE *arq = fopen(ARQ_FUNCIONARIOS, "rb");
    if (!arq) return 0;
    Funcionario f;
    while (fread(&f, sizeof(Funcionario), 1, arq) == 1) {
        if (strcmp(cpf, f.cpf) == 0) { fclose(arq); return 1; }
    }
    fclose(arq);
    return 0;
}

void tela_cadastrar_funcionario(void) {
    FILE *fp = fopen(ARQ_FUNCIONARIOS, "ab");
    if (!fp) { printf("Erro ao abrir o arquivo de funcionários.\n"); Enter(); return; }

    Funcionario novo;
    system("cls||clear");
    printf("=== Cadastro de Funcionário ===\n");

    printf("Nome: ");
    fgets(novo.nome, TAM_NOME_FUNC, stdin); novo.nome[strcspn(novo.nome, "\n")] = 0;
    printf("Email: ");
    fgets(novo.email, TAM_EMAIL_FUNC, stdin); novo.email[strcspn(novo.email, "\n")] = 0;
    printf("Cargo: ");
    fgets(novo.cargo, TAM_CARGO_FUNC, stdin); novo.cargo[strcspn(novo.cargo, "\n")] = 0;
    printf("CPF (apenas números): ");
    fgets(novo.cpf, TAM_CPF_FUNC, stdin); novo.cpf[strcspn(novo.cpf, "\n")] = 0;

    if (funcionario_existe_arquivo(novo.cpf)) {
        printf("\nErro: já existe um funcionário com esse CPF.\n");
        fclose(fp);
        Enter();
        return;
    }

    fwrite(&novo, sizeof(Funcionario), 1, fp);
    fclose(fp);

    printf("\n================================\n");
    printf("= Cadastro realizado com sucesso!=\n");
    printf("==================================\n");
    Enter();
}

void tela_ver_funcionarios(void) {
    FILE *fp = fopen(ARQ_FUNCIONARIOS, "rb");
    if (!fp) { printf("Nenhum funcionário cadastrado ainda.\n"); Enter(); return; }

    Funcionario f;
    int count = 0;
    system("cls||clear");
    printf("=== Funcionários Cadastrados ===\n\n");
    while (fread(&f, sizeof(Funcionario), 1, fp) == 1) {
        printf("%d. Nome: %s | Email: %s | Cargo: %s | CPF: %s\n",
               ++count, f.nome, f.email, f.cargo, f.cpf);
    }
    if (count == 0) printf("Nenhum funcionário encontrado.\n");
    fclose(fp);
    Enter();
}

void tela_pesquisar_funcionario(void) {
    FILE *fp = fopen(ARQ_FUNCIONARIOS, "rb");
    if (!fp) { printf("Erro ao abrir arquivo.\n"); Enter(); return; }

    char cpfBuscado[TAM_CPF_FUNC];
    Funcionario f;
    int encontrado = 0;

    system("cls||clear");
    printf("Digite o CPF do funcionário que deseja buscar: ");
    fgets(cpfBuscado, TAM_CPF_FUNC, stdin); cpfBuscado[strcspn(cpfBuscado, "\n")] = 0;

    while (fread(&f, sizeof(Funcionario), 1, fp) == 1) {
        if (strcmp(f.cpf, cpfBuscado) == 0) {
            printf("\n=== Funcionário encontrado ===\n");
            printf("Nome: %s\nEmail: %s\nCargo: %s\nCPF: %s\n",
                   f.nome, f.email, f.cargo, f.cpf);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) printf("\nFuncionário com CPF %s não encontrado.\n", cpfBuscado);
    fclose(fp);
    Enter();
}

void tela_editar_funcionario(void) {
    FILE *fp = fopen(ARQ_FUNCIONARIOS, "rb");
    if (!fp) { printf("Erro ao abrir o arquivo.\n"); Enter(); return; }

    FILE *temp = fopen(TEMP_FUNC, "wb");
    if (!temp) { fclose(fp); printf("Erro ao criar arquivo temporário.\n"); Enter(); return; }

    char cpf[TAM_CPF_FUNC];
    Funcionario f;
    int encontrado = 0;

    system("cls||clear");
    printf("Digite o CPF do funcionário que deseja editar: ");
    fgets(cpf, TAM_CPF_FUNC, stdin); cpf[strcspn(cpf, "\n")] = 0;

    while (fread(&f, sizeof(Funcionario), 1, fp) == 1) {
        if (strcmp(f.cpf, cpf) == 0) {
            encontrado = 1;
            printf("\n--- Editando funcionário %s ---\n", f.nome);

            printf("Novo Nome: ");
            fgets(f.nome, TAM_NOME_FUNC, stdin); f.nome[strcspn(f.nome, "\n")] = 0;
            printf("Novo Email: ");
            fgets(f.email, TAM_EMAIL_FUNC, stdin); f.email[strcspn(f.email, "\n")] = 0;
            printf("Novo Cargo: ");
            fgets(f.cargo, TAM_CARGO_FUNC, stdin); f.cargo[strcspn(f.cargo, "\n")] = 0;
        }
        fwrite(&f, sizeof(Funcionario), 1, temp);
    }

    fclose(fp);
    fclose(temp);
    remove(ARQ_FUNCIONARIOS);
    rename(TEMP_FUNC, ARQ_FUNCIONARIOS);

    if (encontrado) {
        printf("=======================================\n");
        printf("=    Edição realizada com sucesso!    =\n");
        printf("=======================================\n");
    } 
    else {
        printf("===============================\n");
        printf("= Funcionário não encontrado! =\n");
        printf("===============================\n");
}

Enter();  
}

void tela_excluir_funcionario(void) {
    FILE *fp = fopen(ARQ_FUNCIONARIOS, "rb");
    if (!fp) { printf("Erro ao abrir arquivo.\n"); Enter(); return; }

    FILE *temp = fopen(TEMP_FUNC, "wb");
    if (!temp) { fclose(fp); printf("Erro ao criar arquivo temporário.\n"); Enter(); return; }

    char cpf[TAM_CPF_FUNC];
    Funcionario f;
    int encontrado = 0;

    system("cls||clear");
    printf("Digite o CPF do funcionário a excluir: ");
    fgets(cpf, TAM_CPF_FUNC, stdin); cpf[strcspn(cpf, "\n")] = 0;

    while (fread(&f, sizeof(Funcionario), 1, fp) == 1) {
        if (strcmp(f.cpf, cpf) != 0) fwrite(&f, sizeof(Funcionario), 1, temp);
        else encontrado = 1;
    }

    fclose(fp);
    fclose(temp);
    remove(ARQ_FUNCIONARIOS);
    rename(TEMP_FUNC, ARQ_FUNCIONARIOS);

    if (encontrado) {
    printf("===================================\n");
    printf("= Exclusão realizada com sucesso! =\n");
    printf("===================================\n");
}   else {
    printf("===============================\n");
    printf("= Funcionário não encontrado! =\n");
    printf("===============================\n");
}
    Enter();
}
