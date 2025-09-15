#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/tela_inicial.h"
#include "../include/modulos_info.h"
#include "../include/bicicletas.h"
#include "../include/clientes.h"

#define MAX_FUNCIONARIOS 100
#define TAM_NOME_FUNC 50
#define TAM_EMAIL_FUNC 50
#define TAM_CARGO 30
#define TAM_CPF_FUNC 15

#define MAX_VENDAS 500

typedef struct {                 
    char cpf_cliente[TAM_CPF];   
    char cpf_funcionario[TAM_CPF_FUNC]; 
    int id_bicicleta;         
    int quantidade;           
    float valor_total;   
    int id;      
} Venda;

Venda vendas[MAX_VENDAS];
int qtd_vendas = 0;

// ==== Assinaturas de funções ====
// Funções principais
void tela_principal(void);
void tela_sobre(void);
void tela_equipe(void);
void tela_sair(void);

// Módulo vendas
void modulo_vendas(void);
void tela_cadastrar_venda(void);
void tela_ver_vendas(void);
void tela_pesquisar_venda(void);
void tela_editar_venda(void);
void tela_excluir_venda(void);

// Módulo funcionários
void modulo_funcionarios(void);
void tela_cadastrar_funcionario(void);
void tela_ver_funcionarios(void);
void tela_pesquisar_funcionario(void);
void tela_editar_funcionario(void);
void tela_excluir_funcionario(void);

typedef struct {
    char nome[TAM_NOME_FUNC];
    char email[TAM_EMAIL_FUNC];
    char cargo[TAM_CARGO];
    char cpf[TAM_CPF_FUNC];
} Funcionario;

Funcionario funcionarios[MAX_FUNCIONARIOS];
int qtd_funcionarios = 0;

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

void modulo_vendas(void) {
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
        printf("///            1. Cadastrar venda                                           ///\n");
        printf("///            2. Ver vendas cadastradas                                    ///\n");
        printf("///            3. Pesquisar dados de uma venda                              ///\n");
        printf("///            4. Editar dados de uma venda                                 ///\n");
        printf("///            5. Excluir venda do sistema                                  ///\n");
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
                tela_cadastrar_venda();
                break;
            case 2:
                tela_ver_vendas();
                break;
            case 3:
                tela_pesquisar_venda();
                break;
            case 4:
                tela_editar_venda();
                break;
            case 5:
                tela_excluir_venda();
                break;
            case 6:
                return;
            default:
                printf("Opção inválida!\n");
                Enter();
        }
    } while(opcao != 6);
}
void tela_cadastrar_venda(void){
    system("cls||clear");
    if(qtd_vendas >= MAX_VENDAS){
        printf("Limite de vendas atingido!\n");
        Enter();
        return;
    }

    if(qtd_clientes == 0 || qtd_funcionarios == 0 || qtd_bicicletas == 0){
        printf("É necessário ter clientes, funcionários e bicicletas cadastrados.\n");
        Enter();
        return;
    }
    
    Venda nova;
    char entrada[50];
    nova.id = qtd_vendas + 1;

    printf("CPF do cliente: ");
    fgets(nova.cpf_cliente, TAM_CPF, stdin);
    nova.cpf_cliente[strcspn(nova.cpf_cliente, "\n")] = 0;

    int posicao_cliente = -1;
    for(int i = 0; i < qtd_clientes; i++){
        if(strcmp(clientes[i].cpf, nova.cpf_cliente) == 0){
            posicao_cliente = i;
            break;
        }
    }
    if(posicao_cliente == -1){
        printf("Cliente não encontrado. Cadastre o cliente primeiro.\n");
        Enter();
        return;
    }

    printf("CPF do funcionário: ");
    fgets(nova.cpf_funcionario, TAM_CPF_FUNC, stdin);
    nova.cpf_funcionario[strcspn(nova.cpf_funcionario, "\n")] = 0;

    int posicao_funcionario = -1;
    for(int i = 0; i < qtd_funcionarios; i++){
        if(strcmp(funcionarios[i].cpf, nova.cpf_funcionario) == 0){
            posicao_funcionario = i;
            break;
        }
    }
    if(posicao_funcionario == -1){
        printf("Funcionário não encontrado. Cadastre o funcionário primeiro.\n");
        Enter();
        return;
    }

    printf("ID da bicicleta: ");
    fgets(entrada, sizeof(entrada), stdin);
    nova.id_bicicleta = atoi(entrada);

    int posicao_bicicleta = -1;
    for(int i = 0; i < qtd_bicicletas; i++){
        if(bicicletas[i].id == nova.id_bicicleta){
            posicao_bicicleta = i;
            break;
        }
    }
    if(posicao_bicicleta == -1){
        printf("Bicicleta não encontrada. Cadastre a bicicleta primeiro.\n");
        Enter();
        return;
    }

    printf("Quantidade: ");
    fgets(entrada, sizeof(entrada), stdin);
    nova.quantidade = atoi(entrada);

    if(bicicletas[posicao_bicicleta].estoque < nova.quantidade){
        printf("Estoque insuficiente!\n");
        Enter();
        return;
    }

    bicicletas[posicao_bicicleta].estoque -= nova.quantidade;
    nova.valor_total = bicicletas[posicao_bicicleta].preco * nova.quantidade;

    vendas[qtd_vendas++] = nova;

    printf("=======================================\n");
    printf("=   Cadastro realizado com sucesso!   =\n");
    printf("=======================================\n");
    Enter();
}
void tela_ver_vendas(void){
    system("cls||clear");
    printf("\n=== Vendas cadastradas ===\n");
    if(qtd_vendas == 0){
        printf("Nenhum venda cadastrada.\n");
    } else {
        for(int i = 0; i < qtd_vendas; i++){
            printf("%d. CPF do cliente: %s | CPF do funcionário: %s | ID da bicicleta: %d | Quantidade comprada: %d | Valor total da compra: %.2f R$\n",
                vendas[i].id, vendas[i].cpf_cliente, vendas[i].cpf_funcionario, vendas[i].id_bicicleta, vendas[i].quantidade, vendas[i].valor_total);
        }
    }
    Enter();
}
void tela_pesquisar_venda(void){
    system("cls||clear");
    
    if(qtd_vendas == 0){
        printf("Nenhuma venda cadastrada.\n");
        Enter();
        return;
    }

    int id;
    char entrada[50];

    printf("Digite o ID da venda que deseja visualizar: ");
    fgets(entrada, sizeof(entrada), stdin);
    id = atoi(entrada);

    int encontrado = -1;
    for(int i = 0; i < qtd_vendas; i++){
        if(vendas[i].id == id){
            encontrado = i;
            break;
        }
    }

    if(encontrado == -1){
        printf("\nVenda com ID %d não encontrada.\n", id);
    } else {
        int i = encontrado;
        printf("%d. CPF do cliente: %s | CPF do funcionário: %s | ID da bicicleta: %d | Quantidade comprada: %d | Valor total da compra: R$ %.2f\n",
            vendas[i].id, vendas[i].cpf_cliente, vendas[i].cpf_funcionario, vendas[i].id_bicicleta, vendas[i].quantidade, vendas[i].valor_total
        );
    }
    Enter();
}
void tela_editar_venda(void){
    system("cls||clear");
    if(qtd_vendas == 0){
        printf("Nenhuma venda cadastrada.\n");
        Enter();
        return;
    }

    char entrada[50];
    int id;
    printf("Digite o ID da venda que deseja editar: ");
    fgets(entrada, sizeof(entrada), stdin);
    id = atoi(entrada);

    int encontrado = -1;
    for(int i = 0; i < qtd_vendas; i++){
        if(vendas[i].id == id){
            encontrado = i;
            break;
        }
    }

    if(encontrado == -1){
        printf("Venda com ID %d não encontrada.\n", id);
        Enter();
        return;
    }

    Venda *v = &vendas[encontrado];

    for(int i = 0; i < qtd_bicicletas; i++){
        if(bicicletas[i].id == v->id_bicicleta){
            bicicletas[i].estoque += v->quantidade;
            break;
        }
    }

    printf("CPF do cliente: ");
    fgets(v->cpf_cliente, TAM_CPF, stdin);
    v->cpf_cliente[strcspn(v->cpf_cliente, "\n")] = 0;

    int posicao_cliente = -1;
    for(int i = 0; i < qtd_clientes; i++){
        if(strcmp(clientes[i].cpf, v->cpf_cliente) == 0){
            posicao_cliente = i;
            break;
        }
    }
    if(posicao_cliente == -1){
        printf("Cliente não encontrado. Edição cancelada.\n");
        Enter();
        return;
    }

    printf("CPF do funcionário: ");
    fgets(v->cpf_funcionario, TAM_CPF_FUNC, stdin);
    v->cpf_funcionario[strcspn(v->cpf_funcionario, "\n")] = 0;

    int posicao_funcionario = -1;
    for(int i = 0; i < qtd_funcionarios; i++){
        if(strcmp(funcionarios[i].cpf, v->cpf_funcionario) == 0){
            posicao_funcionario = i;
            break;
        }
    }
    if(posicao_funcionario == -1){
        printf("Funcionário não encontrado. Edição cancelada.\n");
        Enter();
        return;
    }

    printf("ID da bicicleta: ");
    fgets(entrada, sizeof(entrada), stdin);
    v->id_bicicleta = atoi(entrada);

    int posicao_bicicleta = -1;
    for(int i = 0; i < qtd_bicicletas; i++){
        if(bicicletas[i].id == v->id_bicicleta){
            posicao_bicicleta = i;
            break;
        }
    }
    if(posicao_bicicleta == -1){
        printf("Bicicleta não encontrada. Edição cancelada.\n");
        Enter();
        return;
    }

    printf("Quantidade: ");
    fgets(entrada, sizeof(entrada), stdin);
    v->quantidade = atoi(entrada);

    if(bicicletas[posicao_bicicleta].estoque < v->quantidade){
        printf("Estoque insuficiente! Edição cancelada.\n");
        Enter();
        return;
    }

    bicicletas[posicao_bicicleta].estoque -= v->quantidade;
    v->valor_total = bicicletas[posicao_bicicleta].preco * v->quantidade;

    printf("=======================================\n");
    printf("=    Edição realizada com sucesso!    =\n");
    printf("=======================================\n");
    Enter();
}

void tela_excluir_venda(void){
    system("cls||clear");

    if(qtd_vendas == 0){
        printf("Nenhuma venda cadastrada para excluir.\n");
        Enter();
        return;
    }

    char entrada[50];
    int id;
    printf("Digite o ID da venda para excluir: ");
    fgets(entrada, sizeof(entrada), stdin);
    id = atoi(entrada);

    int encontrado = -1;
    for(int i = 0; i < qtd_vendas; i++){
        if(vendas[i].id == id){
            encontrado = i;
            break;
        }
    }

    system("cls||clear");
    if(encontrado == -1){
        printf("=============================\n");
        printf("= Venda não encontrada! =\n");
        printf("=============================\n");
    } else {

        for(int i = encontrado; i < qtd_vendas - 1; i++){
            vendas[i] = vendas[i+1];
        }
        qtd_vendas--; 

        printf("===================================\n");
        printf("= Exclusão realizada com sucesso! =\n");
        printf("===================================\n");
    }
    Enter();
}

int main(void){
    tela_inicial();
    return 0;
}
