#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/vendas.h"
#include "../include/tela_inicial.h"

#define MAX_VENDAS 500

Venda vendas[MAX_VENDAS];
int qtd_vendas = 0;

// === Funções auxiliares para CSV ===

int cliente_existe(const char *cpf) {
    FILE *arq = fopen("dados/clientes.csv", "rt");
    if (!arq) return 0;

    char nome[100], email[100], cidade[100], cpf_lido[TAM_CPF];
    while (fscanf(arq, "%99[^;];%99[^;];%99[^;];%14[^\n]\n", nome, email, cidade, cpf_lido) == 4) {
        if (strcmp(cpf, cpf_lido) == 0) {
            fclose(arq);
            return 1;
        }
    }

    fclose(arq);
    return 0;
}

int funcionario_existe(const char *cpf) {
    FILE *arq = fopen("dados/funcionarios.csv", "rt");
    if (!arq) return 0;

    char nome[100], email[100], cargo[50], cpf_lido[TAM_CPF_FUNC];
    while (fscanf(arq, "%99[^;];%99[^;];%49[^;];%14[^\n]\n", nome, email, cargo, cpf_lido) == 4) {
        if (strcmp(cpf, cpf_lido) == 0) {
            fclose(arq);
            return 1;
        }
    }

    fclose(arq);
    return 0;
}

// === Nova função: obtém informações completas da bicicleta ===
int obter_info_bicicleta(int id, float *preco, int *estoque) {
    FILE *arq = fopen("dados/bicicletas.csv", "rt");
    if (!arq) return 0;

    char marca[50], modelo[50], cor[50];
    int id_lido, ano_lido, estoque_lido;
    float preco_lido;

    while (fscanf(arq, "%d;%49[^;];%49[^;];%d;%49[^;];%f;%d\n",
                  &id_lido, marca, modelo, &ano_lido, cor, &preco_lido, &estoque_lido) == 7) {
        if (id_lido == id) {
            *preco = preco_lido;
            *estoque = estoque_lido;
            fclose(arq);
            return 1;
        }
    }

    fclose(arq);
    return 0;
}

void atualizar_estoque_bicicleta(int id, int novo_estoque) {
    FILE *arq = fopen("dados/bicicletas.csv", "rt");
    FILE *temp = fopen("dados/temp.csv", "wt");
    if (!arq || !temp) { if(arq) fclose(arq); return; }

    char marca[50], modelo[50], cor[50];
    int id_lido, ano_lido, estoque_lido;
    float preco_lido;

    while (fscanf(arq, "%d;%49[^;];%49[^;];%d;%49[^;];%f;%d\n",
                  &id_lido, marca, modelo, &ano_lido, cor, &preco_lido, &estoque_lido) == 7) {
        if (id_lido == id) estoque_lido = novo_estoque;
        fprintf(temp, "%d;%s;%s;%d;%s;%.2f;%d\n", id_lido, marca, modelo, ano_lido, cor, preco_lido, estoque_lido);
    }

    fclose(arq);
    fclose(temp);
    remove("dados/bicicletas.csv");
    rename("dados/temp.csv", "dados/bicicletas.csv");
}

// === Funções de persistência de vendas ===

void salvar_vendas_csv() {
    FILE *arq = fopen("dados/vendas.csv", "wt");
    if (!arq) return;

    for (int i = 0; i < qtd_vendas; i++) {
        fprintf(arq, "%d;%s;%s;%d;%d;%.2f\n",
                vendas[i].id, vendas[i].cpf_cliente, vendas[i].cpf_funcionario,
                vendas[i].id_bicicleta, vendas[i].quantidade, vendas[i].valor_total);
    }

    fclose(arq);
}

void carregar_vendas_csv() {
    FILE *arq = fopen("dados/vendas.csv", "rt");
    if (!arq) return;

    qtd_vendas = 0;
    while (fscanf(arq, "%d;%14[^;];%14[^;];%d;%d;%f\n",
                  &vendas[qtd_vendas].id,
                  vendas[qtd_vendas].cpf_cliente,
                  vendas[qtd_vendas].cpf_funcionario,
                  &vendas[qtd_vendas].id_bicicleta,
                  &vendas[qtd_vendas].quantidade,
                  &vendas[qtd_vendas].valor_total) == 6) {
        qtd_vendas++;
        if (qtd_vendas >= MAX_VENDAS) break;
    }

    fclose(arq);
}

// === Funções principais do módulo de vendas ===

void modulo_vendas() {
    carregar_vendas_csv();
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
        if (scanf("%d", &opcao) != 1) { while(getchar()!='\n'); opcao = 0; }
        while(getchar()!='\n');

        switch(opcao) {
            case 1: tela_cadastrar_venda(); break;
            case 2: tela_ver_vendas(); break;
            case 3: tela_pesquisar_venda(); break;
            case 4: tela_editar_venda(); break;
            case 5: tela_excluir_venda(); break;
            case 6: return;
            default: printf("Opção inválida!\n"); Enter();
        }
    } while(opcao != 6);
}

// === CRUD de vendas ===

void tela_cadastrar_venda() {
    if (qtd_vendas >= MAX_VENDAS) { printf("Limite de vendas atingido!\n"); Enter(); return; }

    Venda nova;
    char entrada[50];
    nova.id = qtd_vendas + 1;

    printf("CPF do cliente: "); fgets(nova.cpf_cliente, TAM_CPF, stdin);
    nova.cpf_cliente[strcspn(nova.cpf_cliente, "\n")] = 0;
    if (!cliente_existe(nova.cpf_cliente)) { printf("Cliente não encontrado!\n"); Enter(); return; }

    printf("CPF do funcionário: "); fgets(nova.cpf_funcionario, TAM_CPF_FUNC, stdin);
    nova.cpf_funcionario[strcspn(nova.cpf_funcionario, "\n")] = 0;
    if (!funcionario_existe(nova.cpf_funcionario)) { printf("Funcionário não encontrado!\n"); Enter(); return; }

    printf("ID da bicicleta: "); fgets(entrada, sizeof(entrada), stdin);
    nova.id_bicicleta = atoi(entrada);
    float preco; int estoque;
    if (!obter_info_bicicleta(nova.id_bicicleta, &preco, &estoque)) { 
        printf("Bicicleta não encontrada!\n"); Enter(); return; 
    }

    printf("Quantidade: "); fgets(entrada, sizeof(entrada), stdin);
    nova.quantidade = atoi(entrada);
    if (nova.quantidade > estoque) { printf("Estoque insuficiente!\n"); Enter(); return; }

    estoque -= nova.quantidade;
    atualizar_estoque_bicicleta(nova.id_bicicleta, estoque);
    nova.valor_total = preco * nova.quantidade;

    vendas[qtd_vendas++] = nova;
    salvar_vendas_csv();
    printf("Venda realizada com sucesso!\n"); 
    Enter();
}

void tela_ver_vendas() {
    if (qtd_vendas == 0) { printf("Nenhuma venda cadastrada.\n"); Enter(); return; }
    for (int i = 0; i < qtd_vendas; i++)
        printf("%d. Cliente: %s | Funcionário: %s | Bicicleta: %d | Qtde: %d | Total: %.2f\n",
               vendas[i].id, vendas[i].cpf_cliente, vendas[i].cpf_funcionario,
               vendas[i].id_bicicleta, vendas[i].quantidade, vendas[i].valor_total);
    Enter();
}

void tela_pesquisar_venda() {
    if (qtd_vendas == 0) { printf("Nenhuma venda cadastrada.\n"); Enter(); return; }

    char entrada[50]; int id;
    printf("ID da venda: "); fgets(entrada, sizeof(entrada), stdin); id = atoi(entrada);

    for (int i = 0; i < qtd_vendas; i++) {
        if (vendas[i].id == id) {
            printf("%d. Cliente: %s | Funcionário: %s | Bicicleta: %d | Qtde: %d | Total: %.2f\n",
                   vendas[i].id, vendas[i].cpf_cliente, vendas[i].cpf_funcionario,
                   vendas[i].id_bicicleta, vendas[i].quantidade, vendas[i].valor_total);
            Enter(); return;
        }
    }
    printf("Venda não encontrada.\n"); Enter();
}

void tela_editar_venda() {
    if (qtd_vendas == 0) { printf("Nenhuma venda cadastrada.\n"); Enter(); return; }

    char entrada[50]; int id;
    printf("ID da venda: "); fgets(entrada, sizeof(entrada), stdin); id = atoi(entrada);

    for (int i = 0; i < qtd_vendas; i++) {
        Venda *v = &vendas[i];
        if (v->id == id) {
            float preco; int estoque;
            if (obter_info_bicicleta(v->id_bicicleta, &preco, &estoque)) {
                estoque += v->quantidade;
                atualizar_estoque_bicicleta(v->id_bicicleta, estoque);
            }

            printf("CPF cliente: "); fgets(v->cpf_cliente, TAM_CPF, stdin);
            v->cpf_cliente[strcspn(v->cpf_cliente,"\n")]=0;
            if (!cliente_existe(v->cpf_cliente)) { printf("Cliente não encontrado!\n"); Enter(); return; }

            printf("CPF funcionário: "); fgets(v->cpf_funcionario, TAM_CPF_FUNC, stdin);
            v->cpf_funcionario[strcspn(v->cpf_funcionario,"\n")]=0;
            if (!funcionario_existe(v->cpf_funcionario)) { printf("Funcionário não encontrado!\n"); Enter(); return; }

            printf("ID bicicleta: "); fgets(entrada, sizeof(entrada), stdin); v->id_bicicleta=atoi(entrada);
            if (!obter_info_bicicleta(v->id_bicicleta, &preco, &estoque)) { printf("Bicicleta não encontrada!\n"); Enter(); return; }

            printf("Quantidade: "); fgets(entrada, sizeof(entrada), stdin); v->quantidade=atoi(entrada);
            if (v->quantidade > estoque) { printf("Estoque insuficiente!\n"); Enter(); return; }

            estoque -= v->quantidade; atualizar_estoque_bicicleta(v->id_bicicleta, estoque);
            v->valor_total = preco * v->quantidade;
            salvar_vendas_csv();
            printf("Venda editada com sucesso!\n"); Enter();
            return;
        }
    }
    printf("Venda não encontrada.\n"); Enter();
}

void tela_excluir_venda() {
    if (qtd_vendas == 0) { printf("Nenhuma venda cadastrada.\n"); Enter(); return; }

    char entrada[50]; int id;
    printf("ID da venda: "); fgets(entrada, sizeof(entrada), stdin); id = atoi(entrada);

    for (int i = 0; i < qtd_vendas; i++) {
        if (vendas[i].id == id) {
            float preco; int estoque;
            if (obter_info_bicicleta(vendas[i].id_bicicleta, &preco, &estoque)) {
                estoque += vendas[i].quantidade;
                atualizar_estoque_bicicleta(vendas[i].id_bicicleta, estoque);
            }

            for (int j = i; j < qtd_vendas-1; j++) vendas[j] = vendas[j+1];
            qtd_vendas--;
            salvar_vendas_csv();
            printf("Venda excluída com sucesso!\n"); Enter();
            return;
        }
    }
    printf("Venda não encontrada.\n"); Enter();
}
