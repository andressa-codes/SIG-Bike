#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/tela_inicial.h"
#include "../include/funcionarios.h"

int validar_nome(const char *nome) {
    for (int i = 0; nome[i] != '\0'; i++) {
        unsigned char c = nome[i];

        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
            continue;

        if (c == ' ')
            continue;

        
        if (c >= 192) {
            if (nome[i + 1] != '\0') {
                i++; 
                continue;
            }
        }

        
        return 0;
    }
    return 1;
}

int validar_email(const char *email) {
    int tem_arroba = 0, tem_ponto = 0;
    int len = strlen(email);

    if (len < 5) return 0;
    if (email[0] == '@' || email[0] == '.' || email[len-1] == '@' || email[len-1] == '.')
        return 0;

    for (int i = 0; i < len; i++) {
        unsigned char c = (unsigned char)email[i];

        if (c == '@') {
            if (tem_arroba) return 0;
            tem_arroba = 1;
            if (i + 1 < len && email[i+1] == '.') return 0;
        }
        else if (c == '.' && tem_arroba) {
            tem_ponto = 1;
        }
        else if (c == ' ') {
            return 0;
        }
        else if ((c >= 'A' && c <= 'Z')) {
            return 0;
        }
        else if (c >= 0xC0) { 

            return 0;
        }
    }

    return (tem_arroba && tem_ponto) ? 1 : 0;
}


int validar_cpf(const char *cpf) {
    int i;

    if (strlen(cpf) != 11)
        return 0;

    for (i = 0; cpf[i] != '\0'; i++) {
        if (!isdigit((unsigned char)cpf[i]))
            return 0;
    }

    return 1;
}

int validar_cargo(const char *cargo) {
    for (int i = 0; cargo[i] != '\0'; i++) {
        unsigned char c = cargo[i];

        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
            continue;
        if (c >= '0' && c <= '9')
            continue;
        if (c == ' ')
            continue;
        if (c >= 192) {
            if (cargo[i + 1] != '\0') { 
                continue;
            }
        }

        return 0;
    }
    return 1;
}



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
    novo.status = 'A';
    system("cls||clear");
    printf("=== Cadastro de Funcionário ===\n");

        do {
        printf("Nome: ");
        fgets(novo.nome, TAM_NOME_FUNC, stdin);
        novo.nome[strcspn(novo.nome, "\n")] = 0;

        if (!validar_nome(novo.nome) || strlen(novo.nome) == 0) {
            printf("Erro: o nome deve conter apenas letras e espaços.\n");
        }
    } while (!validar_nome(novo.nome) || strlen(novo.nome) == 0);


        do {
        printf("Email (minúsculas, sem espaços, deve conter '@' e '.'): ");
        fgets(novo.email, TAM_EMAIL_FUNC, stdin);
        novo.email[strcspn(novo.email, "\n")] = 0;

        if (!validar_email(novo.email)) {
            printf("Erro: o email deve estar em minúsculas e sem acento, não conter espaços e ter '@' e '.'\n");
        }
    } while (!validar_email(novo.email));


        do {
        printf("Cargo: ");
        fgets(novo.cargo, TAM_CARGO_FUNC, stdin);
        novo.cargo[strcspn(novo.cargo, "\n")] = 0;

        if (!validar_cargo(novo.cargo) || strlen(novo.cargo) == 0) {
            printf("Erro: o cargo deve conter apenas letras, números e espaços.\n");
        }
    } while (!validar_cargo(novo.cargo) || strlen(novo.cargo) == 0);


        do {
        printf("CPF (apenas números, 11 dígitos): ");
        fgets(novo.cpf, TAM_CPF_FUNC, stdin);
        novo.cpf[strcspn(novo.cpf, "\n")] = 0;

        if (!validar_cpf(novo.cpf)) {
            printf("Erro: o CPF deve conter apenas números e ter exatamente 11 dígitos.\n");
        }
    } while (!validar_cpf(novo.cpf));

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
        if (f.status == 'I') continue;
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
        if (f. status == 'I') continue;
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
    if (!fp) { 
        printf("Erro ao abrir o arquivo.\n"); 
        Enter(); 
        return; 
    }

    FILE *temp = fopen(TEMP_FUNC, "wb");
    if (!temp) { 
        fclose(fp); 
        printf("Erro ao criar arquivo temporário.\n"); 
        Enter(); 
        return; 
    }

    char cpf[TAM_CPF_FUNC];
    Funcionario f;
    int encontrado = 0;

    system("cls||clear");
    printf("Digite o CPF do funcionário que deseja editar: ");
    fgets(cpf, TAM_CPF_FUNC, stdin); 
    cpf[strcspn(cpf, "\n")] = 0;

    while (fread(&f, sizeof(Funcionario), 1, fp) == 1) {

        if (strcmp(f.cpf, cpf) == 0) {
            encontrado = 1;
            printf("\n--- Editando funcionário %s ---\n", f.nome);

            // Validar Nome
            do {
                printf("Novo Nome: ");
                fgets(f.nome, TAM_NOME_FUNC, stdin);
                f.nome[strcspn(f.nome, "\n")] = 0;
                if (!validar_nome(f.nome) || strlen(f.nome) == 0) {
                    printf("Erro: o nome deve conter apenas letras e espaços.\n");
                }
            } while (!validar_nome(f.nome) || strlen(f.nome) == 0);

            // Validar Email
            do {
                printf("Novo Email (minúsculas, sem espaços, deve conter '@' e '.'): ");
                fgets(f.email, TAM_EMAIL_FUNC, stdin);
                f.email[strcspn(f.email, "\n")] = 0;
                if (!validar_email(f.email)) {
                    printf("Erro: o email deve estar em minúsculas e sem acento, não conter espaços e ter '@' e '.'\n");
                }
            } while (!validar_email(f.email));

            // Validar Cargo
            do {
                printf("Novo Cargo: ");
                fgets(f.cargo, TAM_CARGO_FUNC, stdin);
                f.cargo[strcspn(f.cargo, "\n")] = 0;
                if (!validar_cargo(f.cargo) || strlen(f.cargo) == 0) {
                    printf("Erro: o cargo deve conter apenas letras, números e espaços.\n");
                }
            } while (!validar_cargo(f.cargo) || strlen(f.cargo) == 0);

            // Validar CPF
            do {
                printf("Novo CPF (apenas números, 11 dígitos): ");
                fgets(f.cpf, TAM_CPF_FUNC, stdin);
                f.cpf[strcspn(f.cpf, "\n")] = 0;

                if (!validar_cpf(f.cpf)) {
                    printf("Erro: o CPF deve conter apenas números e ter exatamente 11 dígitos.\n");
                    continue;
                }

                FILE *arq = fopen(ARQ_FUNCIONARIOS, "rb");
                if (!arq) break;

                Funcionario tempF;
                int cpf_duplicado = 0;
                while (fread(&tempF, sizeof(Funcionario), 1, arq) == 1) {
                    if (strcmp(tempF.cpf, f.cpf) == 0 && strcmp(tempF.cpf, cpf) != 0) {
                        cpf_duplicado = 1;
                        break;
                    }
                }
                fclose(arq);

                if (cpf_duplicado) {
                    printf("Erro: já existe outro funcionário com esse CPF.\n");
                    continue;
                }

                break;
            } while (1);
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
    } else {
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
    int tipo_exclusao;

    system("cls||clear");
    printf("Digite o CPF do funcionário a excluir: ");
    fgets(cpf, TAM_CPF_FUNC, stdin); cpf[strcspn(cpf, "\n")] = 0;

    printf("============== Tipo de exclusão =============\n");
    printf("= 1. Exclusão lógica (inativar funcionário) =\n");
    printf("= 2. Exclusão física (remover do sistema)   =\n");
    printf("=============================================\n");
    printf("Escolha uma opção: ");
    scanf("%d", &tipo_exclusao);
    getchar();

    while (fread(&f, sizeof(Funcionario), 1, fp) == 1) {
        if (strcmp(f.cpf, cpf) == 0) {
            encontrado = 1;
            if (tipo_exclusao == 1) {
                f.status = 'I'; // Exclusão lógica
                printf("Funcionário inativado com sucesso.\n");
                fwrite(&f, sizeof(Funcionario), 1, temp);
            }
            // Exclusão física: não escreve o registro no temp
        } else {
            fwrite(&f, sizeof(Funcionario), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove(ARQ_FUNCIONARIOS);
    rename(TEMP_FUNC, ARQ_FUNCIONARIOS);

    if (encontrado && tipo_exclusao == 2) {
        printf("===================================\n");
        printf("= Funcionário excluído com sucesso! =\n");
        printf("===================================\n");
    } else if (!encontrado) {
        printf("===================================\n");
        printf("= Funcionário não encontrado!     =\n");
        printf("===================================\n");
    }

    Enter();
} 



