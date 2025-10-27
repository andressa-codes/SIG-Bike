#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/tela_inicial.h"
#include "../include/clientes.h"
#include "../include/validations.h"


#define ARQ_CLIENTES "dados/clientes.dat"
#define TEMP_CLIENTE "dados/temp_clientes.dat"


// ======================== VModulo inicial ==============================

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
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                    = = = = = SIG-Bike = = = = =                         ///\n");
        printf("///                                                                         ///\n");
        printf("///            1. Cadastrar cliente                                         ///\n");
        printf("///            2. Ver clientes cadastrados                                  ///\n");
        printf("///            3. Pesquisar dados de um cliente                             ///\n");
        printf("///            4. Editar dados de um cliente                                ///\n");
        printf("///            5. Excluir cliente do sistema                                ///\n");
        printf("///            6. Voltar para o menu principal                              ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("Escolha a opção desejada: ");

        if (scanf("%d", &opcao) != 1) { while(getchar()!='\n'); opcao = 0; }
        while (getchar() != '\n');

        switch(opcao){
            case 1: tela_cadastrar_cliente(); break;
            case 2: tela_ver_clientes(); break;
            case 3: tela_pesquisar_cliente(); break;
            case 4: tela_editar_cliente(); break;
            case 5: tela_excluir_cliente(); break;
            case 6: return;
            default: printf("Opção inválida!\n"); Enter();
        }
    } while(opcao != 6);
}

int cliente_existe_arquivo(const char *cpf) {
    FILE *arq = fopen(ARQ_CLIENTES, "rb");
    if (!arq) return 0;
    Cliente c;
    while (fread(&c, sizeof(Cliente), 1, arq) == 1) {
        if (strcmp(cpf, c.cpf) == 0) { fclose(arq); return 1; }
    }
    fclose(arq);
    return 0;
}

// ======================== Cadastrar ==============================
void tela_cadastrar_cliente(void) {
    FILE *fp = fopen(ARQ_CLIENTES, "ab");
    if (!fp) { printf("Erro ao abrir o arquivo de clientes.\n"); Enter(); return; }

    Cliente novo;
    novo.status = 'A';
    system("cls||clear");
    printf("=== Cadastro de Cliente ===\n");

    // Nome
    do {
        printf("Nome: ");
        fgets(novo.nome, TAM_NOME, stdin); novo.nome[strcspn(novo.nome, "\n")] = 0;
        if (!validar_nome(novo.nome) || strlen(novo.nome) == 0) {
            printf("Erro: o nome deve conter apenas letras e espaços.\n");
        }
    } while (!validar_nome(novo.nome) || strlen(novo.nome) == 0);

    // Email
    do {
        printf("Email (minúsculas, sem espaços, deve conter '@' e '.'): ");
        fgets(novo.email, TAM_EMAIL, stdin); novo.email[strcspn(novo.email, "\n")] = 0;
        if (!validar_email(novo.email)) {
            printf("Erro: o email deve estar em minúsculas e sem acento, não conter espaços e ter '@' e '.'\n");
        }
    } while (!validar_email(novo.email));

    // Cidade
    do {
        printf("Cidade: ");
        fgets(novo.cidade, TAM_CIDADE, stdin); novo.cidade[strcspn(novo.cidade, "\n")] = 0;
        if (!validar_cidade(novo.cidade) || strlen(novo.cidade) == 0) {
            printf("Erro: a cidade deve conter apenas letras e espaços.\n");
        }
    } while (!validar_cidade(novo.cidade) || strlen(novo.cidade) == 0);

    // CPF
    do {
        printf("CPF (apenas números, 11 dígitos): ");
        fgets(novo.cpf, TAM_CPF, stdin); novo.cpf[strcspn(novo.cpf, "\n")] = 0;
        if (!validar_cpf(novo.cpf)) {
            printf("Erro: o CPF deve conter apenas números e ter exatamente 11 dígitos.\n");
        }
    } while (!validar_cpf(novo.cpf));

    if (cliente_existe_arquivo(novo.cpf)) {
        printf("\nErro: já existe um cliente com esse CPF.\n");
        fclose(fp);
        Enter();
        return;
    }

    fwrite(&novo, sizeof(Cliente), 1, fp);
    fclose(fp);

    printf("\n====================================\n");
    printf("= Cadastro realizado com sucesso!  =\n");
    printf("====================================\n");
    Enter();
}

// ======================== VER ==============================
void tela_ver_clientes(void) {
    FILE *fp = fopen(ARQ_CLIENTES, "rb");
    if (!fp) { printf("Nenhum cliente cadastrado ainda.\n"); Enter(); return; }

    Cliente c;
    int count = 0;
    system("cls||clear");
    printf("=== Clientes Cadastrados ===\n\n");
    while (fread(&c, sizeof(Cliente), 1, fp) == 1) {
        if (c.status == 'I') continue;
        printf("%d. Nome: %s | Email: %s | Cidade: %s | CPF: %s\n",
               ++count, c.nome, c.email, c.cidade, c.cpf);
    }
    if (count == 0) printf("Nenhum cliente encontrado.\n");
    fclose(fp);
    Enter();
}

// ======================== PESQUISAR ==============================
void tela_pesquisar_cliente(void) {
    FILE *fp = fopen(ARQ_CLIENTES, "rb");
    if (!fp) { printf("Erro ao abrir arquivo.\n"); Enter(); return; }

    char cpfBuscado[TAM_CPF];
    Cliente c;
    int encontrado = 0;

    system("cls||clear");
    printf("Digite o CPF do cliente que deseja buscar: ");
    fgets(cpfBuscado, TAM_CPF, stdin); cpfBuscado[strcspn(cpfBuscado, "\n")] = 0;

    while (fread(&c, sizeof(Cliente), 1, fp) == 1) {
        if (c.status == 'I') continue;
        if (strcmp(c.cpf, cpfBuscado) == 0) {
            printf("\n=== Cliente encontrado ===\n");
            printf("Nome: %s\nEmail: %s\nCidade: %s\nCPF: %s\n",
                   c.nome, c.email, c.cidade, c.cpf);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) printf("\nCliente com CPF %s não encontrado.\n", cpfBuscado);
    fclose(fp);
    Enter();
}

// ======================== EDITAR ==============================
void tela_editar_cliente(void) {
    FILE *fp = fopen(ARQ_CLIENTES, "rb");
    if (!fp) { printf("Erro ao abrir o arquivo.\n"); Enter(); return; }

    FILE *temp = fopen(TEMP_CLIENTE, "wb");
    if (!temp) { fclose(fp); printf("Erro ao criar arquivo temporário.\n"); Enter(); return; }

    char cpf[TAM_CPF];
    Cliente c;
    int encontrado = 0;

    system("cls||clear");
    printf("Digite o CPF do cliente que deseja editar: ");
    fgets(cpf, TAM_CPF, stdin); cpf[strcspn(cpf, "\n")] = 0;

    while (fread(&c, sizeof(Cliente), 1, fp) == 1) {
        if (strcmp(c.cpf, cpf) == 0) {
            encontrado = 1;
            printf("\n--- Editando cliente %s ---\n", c.nome);

            // Nome
            do {
                printf("Novo Nome: ");
                fgets(c.nome, TAM_NOME, stdin); c.nome[strcspn(c.nome, "\n")] = 0;
                if (!validar_nome(c.nome) || strlen(c.nome) == 0) {
                    printf("Erro: o nome deve conter apenas letras e espaços.\n");
                }
            } while (!validar_nome(c.nome) || strlen(c.nome) == 0);

            // Email
            do {
                printf("Novo Email (minúsculas, sem espaços, deve conter '@' e '.'): ");
                fgets(c.email, TAM_EMAIL, stdin); c.email[strcspn(c.email, "\n")] = 0;
                if (!validar_email(c.email)) {
                    printf("Erro: o email deve estar em minúsculas e sem acento, não conter espaços e ter '@' e '.'\n");
                }
            } while (!validar_email(c.email));

            // Cidade
            do {
                printf("Nova Cidade: ");
                fgets(c.cidade, TAM_CIDADE, stdin); c.cidade[strcspn(c.cidade, "\n")] = 0;
                if (!validar_cidade(c.cidade) || strlen(c.cidade) == 0) {
                    printf("Erro: a cidade deve conter apenas letras e espaços.\n");
                }
            } while (!validar_cidade(c.cidade) || strlen(c.cidade) == 0);
        }
        fwrite(&c, sizeof(Cliente), 1, temp);
    }

    fclose(fp);
    fclose(temp);
    remove(ARQ_CLIENTES);
    rename(TEMP_CLIENTE, ARQ_CLIENTES);

    if (encontrado) {
        printf("=======================================\n");
        printf("=    Edição realizada com sucesso!    =\n");
        printf("=======================================\n");
    } else {
        printf("=============================\n");
        printf("= Cliente não encontrado!   =\n");
        printf("=============================\n");
    }

    Enter();
}

// ======================== EXCLUIR ==============================
void tela_excluir_cliente(void) {
    FILE *fp = fopen(ARQ_CLIENTES, "rb");
    if (!fp) { 
        printf("Erro ao abrir arquivo.\n"); 
        Enter(); 
        return; 
    }

    FILE *temp = fopen(TEMP_CLIENTE, "wb");
    if (!temp) { 
        fclose(fp); 
        printf("Erro ao criar arquivo temporário.\n"); 
        Enter(); 
        return; 
    }

    char cpf[TAM_CPF];
    Cliente c;
    int encontrado = 0;
    int tipo_exclusao;

    system("cls||clear");
    printf("Digite o CPF do cliente a excluir: ");
    fgets(cpf, TAM_CPF, stdin); 
    cpf[strcspn(cpf, "\n")] = 0;

    printf("============== Tipo de exclusão =============\n");
    printf("= 1. Exclusão lógica (inativar cliente)    =\n");
    printf("= 2. Exclusão física (remover do sistema)  =\n");
    printf("============================================\n");
    printf("Escolha uma opção: ");
    scanf("%d", &tipo_exclusao);
    getchar();

    while (fread(&c, sizeof(Cliente), 1, fp) == 1) {
        if (strcmp(c.cpf, cpf) == 0) {
            encontrado = 1;
            if (tipo_exclusao == 1) {
                c.status = 'I';
                printf("Cliente inativado com sucesso.\n");
                fwrite(&c, sizeof(Cliente), 1, temp);
            }
         } else {
            fwrite(&c, sizeof(Cliente), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove(ARQ_CLIENTES);
    rename(TEMP_CLIENTE, ARQ_CLIENTES);

    if (encontrado && tipo_exclusao == 2) {
        printf("===================================\n");
        printf("= Cliente excluído com sucesso!    =\n");
        printf("===================================\n");
    } else if (!encontrado) {
        printf("===================================\n");
        printf("= Cliente não encontrado!         =\n");
        printf("===================================\n");
    }

    Enter();
}