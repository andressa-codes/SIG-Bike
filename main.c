#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLIENTES 100
#define TAM_NOME 50
#define TAM_EMAIL 50
#define TAM_CIDADE 50
#define TAM_CPF 15

#define MAX_BICICLETAS 200
#define TAM_MARCA 50
#define TAM_MODELO 50
#define TAM_COR 30

typedef struct {
    char nome[TAM_NOME];
    char email[TAM_EMAIL];
    char cidade[TAM_CIDADE];
    char cpf[TAM_CPF];
} Cliente;

Cliente clientes[MAX_CLIENTES];
int qtd_clientes = 0;

typedef struct {
    char marca[TAM_MARCA];
    char modelo[TAM_MODELO];
    int ano;
    char cor[TAM_COR];
    float preco;
    int estoque;
    int id;
} Bicicleta;

Bicicleta bicicletas[MAX_BICICLETAS];
int qtd_bicicletas = 0;

// ==== Assinaturas de funções ====
// Funções principais (telas)
void tela_principal(void);
void tela_sobre(void);
void tela_equipe(void);
void tela_sair(void);

// Módulo bicicletas
void modulo_bicicletas(void);
void tela_cadastrar_bicicleta(void);
void tela_ver_bicicletas(void);
void tela_pesquisar_bicicleta(void);
void tela_editar_bicicleta(void);
void tela_excluir_bicicleta(void);

// Módulo clientes
void modulo_clientes(void);
void tela_cadastrar_cliente(void);
void tela_ver_clientes(void);
void tela_pesquisar_cliente(void);
void tela_editar_cliente(void);
void tela_excluir_cliente(void);

// Módulo funcionários (protótipos sem implementação completa (apenas menu simples))
void modulo_funcionarios(void);
void tela_cadastrar_funcionario(void);
void tela_ver_funcionarios(void);
void tela_pesquisar_funcionario(void);
void tela_editar_funcionario(void);
void tela_excluir_funcionario(void);

void Enter(void);
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
        printf("///            1. Módulo bicicletas                                         ///\n");
        printf("///            2. Módulo clientes                                           ///\n");
        printf("///            3. Módulo vendas                                             ///\n");
        printf("///            4. Módulo funcionários                                       ///\n");
        printf("///            5. Módulo Relatórios                                         ///\n");
        printf("///            6. Voltar ao menu principal                                  ///\n");
        printf("///                                                                         ///\n");
        printf("///            Escolha a opção desejada:                                    ///\n");
        printf("///                                                                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        if (scanf("%d", &opcao) != 1) {
            while (getchar() != '\n');
            opcao = 0;
        }
        while (getchar() != '\n');

        switch(opcao) {
            case 1:
                modulo_bicicletas();
                break;
            case 2:
                modulo_clientes();
                break;
            case 3:
                printf(">>> Módulo vendas em criação...\n");
                Enter();
                break;
            case 4:
                modulo_funcionarios();
                break;
            case 5:
                printf(">>> Módulo relatórios em criação...\n");
                Enter();
                break;
            case 6:
                return;
            default:
                printf("Opção inválida! Tente novamente.\n");
                Enter();
        }
    } while (opcao != 6);
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

void modulo_funcionarios(void) {
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
    Enter();
}


void modulo_bicicletas(void) {
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
        printf("///            1. Cadastrar bicicleta                                       ///\n");
        printf("///            2. Ver bicicletas cadastradas                                ///\n");
        printf("///            3. Pesquisar dados de uma bicicleta                          ///\n");
        printf("///            4. Editar dados de uma bicicleta                             ///\n");
        printf("///            5. Excluir bicicleta do sistema                              ///\n");
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
                tela_cadastrar_bicicleta();
                break;
            case 2:
                tela_ver_bicicletas();
                break;
            case 3:
                tela_pesquisar_bicicleta();
                break;
            case 4:
                tela_editar_bicicleta();
                break;
            case 5:
                tela_excluir_bicicleta();
                break;
            case 6:
                return;
            default:
                printf("Opção inválida!\n");
                Enter();
        }
    } while(opcao != 6);
}

void tela_cadastrar_bicicleta(void){
    system("cls||clear");
    if(qtd_bicicletas >= MAX_BICICLETAS){
        printf("Limite de bicicletas atingido!\n");
        Enter();
        return;
    }

    Bicicleta novo;
    char entrada[50]; 
    novo.id = qtd_bicicletas + 1;

    printf("Marca: ");
    fgets(novo.marca, TAM_MARCA, stdin);
    novo.marca[strcspn(novo.marca, "\n")] = 0;

    printf("Modelo: ");
    fgets(novo.modelo, TAM_MODELO, stdin);
    novo.modelo[strcspn(novo.modelo, "\n")] = 0;

    printf("Ano: ");
    fgets(entrada, sizeof(entrada), stdin);
    novo.ano = atoi(entrada);   

    printf("Cor: ");
    fgets(novo.cor, TAM_COR, stdin);
    novo.cor[strcspn(novo.cor, "\n")] = 0;

    printf("Preço: ");
    fgets(entrada, sizeof(entrada), stdin);
    novo.preco = atof(entrada); 

    printf("Quantidade em estoque: ");
    fgets(entrada, sizeof(entrada), stdin);
    novo.estoque = atoi(entrada);

    bicicletas[qtd_bicicletas++] = novo;

    printf("\n===================================\n");
    printf("= Cadastro realizado com sucesso!   =\n");
    printf("= ID da bicicleta: %d\n", novo.id);
    printf("===================================\n");
    Enter();
}

void tela_ver_bicicletas(void){
    system("cls||clear");
    printf("\n=== Bicicletas Cadastradas ===\n");
    if(qtd_bicicletas == 0){
        printf("Nenhuma bicicleta cadastrada.\n");
    } else {
        for(int i = 0; i < qtd_bicicletas; i++){
            printf("%d. Marca: %s | Modelo: %s | Ano: %d | Cor: %s | Preço: R$ %.2f | Estoque: %d\n",
                i+1, bicicletas[i].marca, bicicletas[i].modelo, bicicletas[i].ano, bicicletas[i].cor, bicicletas[i].preco, bicicletas[i].estoque
            );
        }
    }
    Enter();
}

void tela_pesquisar_bicicleta(void){
    system("cls||clear");
    
    if(qtd_bicicletas == 0){
        printf("Nenhuma bicicleta cadastrada.\n");
        Enter();
        return;
    }

    int id;
    char entrada[50];

    printf("Digite o ID da bicicleta que deseja visualizar: ");
    fgets(entrada, sizeof(entrada), stdin);
    id = atoi(entrada);

    int encontrado = -1;
    for(int i = 0; i < qtd_bicicletas; i++){
        if(bicicletas[i].id == id){
            encontrado = i;
            break;
        }
    }

    if(encontrado == -1){
        printf("\nBicicleta com ID %d não encontrada.\n", id);
    } else {
        int i = encontrado;
        printf("%d. Marca: %s | Modelo: %s | Ano: %d | Cor: %s | Preço: R$ %.2f | Estoque: %d\n",
            bicicletas[i].id, bicicletas[i].marca, bicicletas[i].modelo, bicicletas[i].ano, 
            bicicletas[i].cor, bicicletas[i].preco, bicicletas[i].estoque
        );
    }
    Enter();
}

void tela_editar_bicicleta(void){
    system("cls||clear");
    if(qtd_bicicletas == 0){
        printf("Nenhuma bicicleta cadastrada.\n");
        Enter();
        return;
    }

    char entrada[50];
    int id;
    printf("Digite o ID da bicicleta que deseja editar: ");
    fgets(entrada, sizeof(entrada), stdin);
    id = atoi(entrada);

    int encontrado = -1;
    for(int i = 0; i < qtd_bicicletas; i++){
        if(bicicletas[i].id == id){
            encontrado = i;
            break;
        }
    }

    if(encontrado == -1){
        printf("\nBicicleta com ID %d não encontrada.\n", id);
        Enter();
        return;
    }

    Bicicleta *b = &bicicletas[encontrado];

    printf("Marca: ");
    fgets(b->marca, TAM_MARCA, stdin);
    b->marca[strcspn(b->marca, "\n")] = 0;

    printf("Modelo: ");
    fgets(b->modelo, TAM_MODELO, stdin);
    b->modelo[strcspn(b->modelo, "\n")] = 0;

    printf("Ano: ");
    fgets(entrada, sizeof(entrada), stdin);
    b->ano = atoi(entrada);   

    printf("Cor: ");
    fgets(b->cor, TAM_COR, stdin);
    b->cor[strcspn(b->cor, "\n")] = 0;

    printf("Preço: ");
    fgets(entrada, sizeof(entrada), stdin);
    b->preco = atof(entrada); 

    printf("Quantidade em estoque: ");
    fgets(entrada, sizeof(entrada), stdin);
    b->estoque = atoi(entrada);

    printf("=======================================\n");
    printf("=    Edição realizada com sucesso!    =\n");
    printf("=======================================\n");
    Enter();
}

void tela_excluir_bicicleta(void){
    system("cls||clear");

    if(qtd_bicicletas == 0){
        printf("Nenhuma bicicleta cadastrada para excluir.\n");
        Enter();
        return;
    }

    char entrada[50];
    int id;
    printf("Digite o ID da bicicleta para excluir: ");
    fgets(entrada, sizeof(entrada), stdin);
    id = atoi(entrada);

    int encontrado = -1;
    for(int i = 0; i < qtd_bicicletas; i++){
        if(bicicletas[i].id == id){
            encontrado = i;
            break;
        }
    }

    system("cls||clear");
    if(encontrado == -1){
        printf("=============================\n");
        printf("= Bicicleta não encontrada! =\n");
        printf("=============================\n");
    } else {

        for(int i = encontrado; i < qtd_bicicletas - 1; i++){
            bicicletas[i] = bicicletas[i+1];
        }
        qtd_bicicletas--; 

        printf("===================================\n");
        printf("= Exclusão realizada com sucesso! =\n");
        printf("===================================\n");
    }
    Enter();
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
