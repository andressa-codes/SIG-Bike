#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLIENTES 100
#define TAM_NOME 50
#define TAM_EMAIL 50
#define TAM_CIDADE 50
#define TAM_CPF 15

typedef struct {
    char nome[TAM_NOME];
    char email[TAM_EMAIL];
    char cidade[TAM_CIDADE];
    char cpf[TAM_CPF];
} Cliente;

Cliente clientes[MAX_CLIENTES];
int qtd_clientes = 0;

// ==== Assinaturas das funções ====
void tela_principal(void);
void tela_sobre(void);
void tela_equipe(void);
void tela_sair(void);

void modulo_clientes(void);
void tela_cadastrar_cliente(void);
void tela_ver_clientes(void);
void tela_excluir_cliente(void);

void Enter(void) {
    printf("\n\t\t>>> Tecle <ENTER> para continuar... \n");
    while (getchar() != '\n');
}

void tela_principal(void) {
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
        printf("///            1. Módulo categorias                                         ///\n");
        printf("///            2. Módulo bicicletas                                         ///\n");
        printf("///            3. Módulo clientes                                           ///\n");
        printf("///            4. Módulo vendas                                             ///\n");
        printf("///            5. Módulo funcionários                                       ///\n");
        printf("///            6. Módulo Relatórios                                         ///\n");
        printf("///            7. Voltar ao menu principal                                  ///\n");
        printf("///                                                                         ///\n");
        printf("///            Escolha a opção desejada:                                    ///\n");
        printf("///                                                                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        scanf("%d", &opcao);
        while (getchar() != '\n');

        switch(opcao) {
            case 1:
                printf(">>> Módulo categorias em criação...\n");
                Enter();
                break;
            case 2:
                printf(">>> Módulo bicicletas em criação...\n");
                Enter();
                break;
            case 3:
                modulo_clientes();
                break;
            case 4:
                printf(">>> Módulo vendas em criação...\n");
                Enter();
                break;
            case 5:
                printf(">>> Módulo funcionários em criação...\n");
                Enter();
                break;
            case 6:
                printf(">>> Módulo relatórios em criação...\n");
                Enter();
                break;
            case 7:
                return;
            default:
                printf("Opção inválida! Tente novamente.\n");
                Enter();
        }
    } while (opcao != 7);
}

void tela_sobre(){
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
    printf("///  O projeto SIG-Bike está sendo desenvolvido na disciplina DCT1106       ///\n");
    printf("///  – Programação, sob orientação do professor Flávius Gorgonio, durante   ///\n");
    printf("///  o semestre 2025.2. Trata-se de um sistema acadêmico criado para fins   ///\n");
    printf("///  de aprendizado, cujo objetivo principal é exercitar os conceitos de    ///\n");
    printf("///  programação em linguagem C por meio do desenvolvimento de um software  ///\n");
    printf("///  de gestão voltado a uma loja de bicicletas.                            ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    Enter();
}

void tela_equipe(){
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
    printf("///                    Este projeto foi desenvolvido pelos alunos:          ///\n");
    printf("///                                                                         ///\n");
    printf("///                    -> Andressa Carla da Silva                           ///\n");
    printf("///                       Email: andressa.silva.141@ufrn.edu.br             ///\n");
    printf("///                       Redes sociais: @andressa-codes                    ///\n");
    printf("///                                                                         ///\n");
    printf("///                    -> Jezreel Asaias da Silva Souza                     ///\n");
    printf("///                       Email: jezreel.asaias.silva.129@ufrn.edu.br       ///\n");
    printf("///                       Redes sociais: @Jezreel-Asaias                    ///\n");
    printf("///                                                                         ///\n");
    printf("///                Git: https://github.com/andressa-codes/SIG-Bike.git      ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    Enter();
}

void tela_sair(){
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
    printf("///   Muito obrigado por utilizar o nosso sistema, esperamos te ver         ///\n");
    printf("///   novamente em breve.                                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    Enter();
}


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
        printf("///            3. Excluir cliente do sistema                                ///\n");
        printf("///            4. Voltar para o menu principal                              ///\n");
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
                tela_excluir_cliente();
                break;
            case 4:
                return;
            default:
                printf("Opção inválida!\n");
                Enter();
        }
    } while(opcao != 4);
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


int main() {
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
        printf("//////////////////////////// Bem-vindo ao SIG-Bike! ///////////////////////////\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                                                                         ///\n");
        printf("///            1 - Entrar no sistema                                        ///\n");
        printf("///            2 - Equipe de desenvolvimento                                ///\n");
        printf("///            3 - Sobre o sistema                                          ///\n");
        printf("///            4 - Sair                                                     ///\n");
        printf("///                                                                         ///\n");
        printf("///            Escolha a opção desejada:                                    ///\n");
        printf("///                                                                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");

        printf("Digite uma opção para prosseguir: ");
        if (scanf("%d", &opcao) != 1) {
            while (getchar() != '\n');
            printf("Você escolheu uma opção que não existe. Por favor, tente novamente.\n");
            Enter();
            opcao = 0;
            continue;
        }

        while (getchar() != '\n');

        switch(opcao) {
            case 1:
                tela_principal();
                break;
            case 2:
                tela_equipe();
                break;
            case 3:
                tela_sobre();
                break;
            case 4:
                tela_sair();
                break;
            default:
                printf("Você escolheu uma opção que não existe. Por favor, tente novamente.\n");
                Enter();
        }
    } while(opcao != 4);

    return 0;
}
