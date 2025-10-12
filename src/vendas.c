/* src/vendas.c
   Módulo de vendas — armazena vendas em binário (VENDAS_FILE)
   Depende das funções públicas:
     - cliente_existe_arquivo(const char*)
     - funcionario_existe_arquivo(const char*)
     - obter_info_bicicleta(int, float*, int*)
     - atualizar_estoque_bicicleta(int, int)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/tela_inicial.h"
#include "../include/vendas.h"
#include "../include/funcionarios.h"
#include "../include/clientes.h"
#include "../include/bicicletas.h"

Venda vendas[MAX_VENDAS];
int qtd_vendas = 0;

// carrega todas as vendas do arquivo binário para o array 'vendas'
static void carregar_vendas_binario(void) {
    FILE *arq = fopen(VENDAS_FILE, "rb");
    if (!arq) { qtd_vendas = 0; return; }

    qtd_vendas = 0;
    while (fread(&vendas[qtd_vendas], sizeof(Venda), 1, arq) == 1) {
        qtd_vendas++;
        if (qtd_vendas >= MAX_VENDAS) break;
    }

    fclose(arq);
}

// salva todas as vendas do array 'vendas' no arquivo binário
static int salvar_vendas_binario(void) {
    FILE *arq = fopen(VENDAS_FILE, "wb");
    if (!arq) return 0;

    for (int i = 0; i < qtd_vendas; i++) {
        if (fwrite(&vendas[i], sizeof(Venda), 1, arq) != 1) {
            fclose(arq);
            return 0;
        }
    }

    fclose(arq);
    return 1;
}

// Menu principal do módulo de vendas
void modulo_vendas(void) {
    carregar_vendas_binario();
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

        printf("Escolha a opção desejada: ");
        if (scanf("%d", &opcao) != 1) { while (getchar() != '\n'); opcao = 0; }
        while (getchar() != '\n');

        switch (opcao) {
            case 1: tela_cadastrar_venda(); break;
            case 2: tela_ver_vendas(); break;
            case 3: tela_pesquisar_venda(); break;
            case 4: tela_editar_venda(); break;
            case 5: tela_excluir_venda(); break;
            case 6: return;
            default:
                printf("Opção inválida!\n");
                Enter();
        }
    } while (opcao != 6);
}

// Cadastrar uma venda
void tela_cadastrar_venda(void) {
    carregar_vendas_binario();
    if (qtd_vendas >= MAX_VENDAS) { printf("Limite de vendas atingido!\n"); Enter(); return; }

    Venda nova;
    char entrada[64];
    float preco;
    int estoque;

    // gerar ID automático
    nova.id = (qtd_vendas == 0) ? 1 : vendas[qtd_vendas - 1].id + 1;

    printf("CPF do cliente: ");
    fgets(nova.cpf_cliente, sizeof(nova.cpf_cliente), stdin);
    nova.cpf_cliente[strcspn(nova.cpf_cliente, "\n")] = 0;
    if (!cliente_existe_arquivo(nova.cpf_cliente)) { printf("Cliente não encontrado!\n"); Enter(); return; }

    printf("CPF do funcionário: ");
    fgets(nova.cpf_funcionario, sizeof(nova.cpf_funcionario), stdin);
    nova.cpf_funcionario[strcspn(nova.cpf_funcionario, "\n")] = 0;
    if (!funcionario_existe_arquivo(nova.cpf_funcionario)) { printf("Funcionário não encontrado!\n"); Enter(); return; }

    printf("ID da bicicleta: ");
    fgets(entrada, sizeof(entrada), stdin);
    nova.id_bicicleta = atoi(entrada);
    if (!obter_info_bicicleta(nova.id_bicicleta, &preco, &estoque)) { printf("Bicicleta não encontrada!\n"); Enter(); return; }

    printf("Quantidade: ");
    fgets(entrada, sizeof(entrada), stdin);
    nova.quantidade = atoi(entrada);
    if (nova.quantidade <= 0) { printf("Quantidade inválida!\n"); Enter(); return; }
    if (nova.quantidade > estoque) { printf("Estoque insuficiente!\n"); Enter(); return; }

    // atualizar estoque
    estoque -= nova.quantidade;
    atualizar_estoque_bicicleta(nova.id_bicicleta, estoque);

    nova.valor_total = preco * nova.quantidade;

    // adiciona ao array e salva
    vendas[qtd_vendas++] = nova;
    if (!salvar_vendas_binario()) { printf("Erro ao salvar venda.\n"); Enter(); return; }

    printf("Venda realizada com sucesso! ID: %d\n", nova.id);
    Enter();
}

// Ver todas as vendas
void tela_ver_vendas(void) {
    carregar_vendas_binario();
    if (qtd_vendas == 0) { printf("Nenhuma venda cadastrada.\n"); Enter(); return; }

    system("cls||clear");
    for (int i = 0; i < qtd_vendas; i++) {
        printf("%d. Cliente: %s | Funcionário: %s | Bicicleta: %d | Qtde: %d | Total: %.2f\n",
               vendas[i].id, vendas[i].cpf_cliente, vendas[i].cpf_funcionario,
               vendas[i].id_bicicleta, vendas[i].quantidade, vendas[i].valor_total);
    }
    Enter();
}

// Pesquisar venda por ID
void tela_pesquisar_venda(void) {
    carregar_vendas_binario();
    if (qtd_vendas == 0) { printf("Nenhuma venda cadastrada.\n"); Enter(); return; }

    char entrada[64];
    int id;
    printf("ID da venda: ");
    fgets(entrada, sizeof(entrada), stdin);
    id = atoi(entrada);

    for (int i = 0; i < qtd_vendas; i++) {
        if (vendas[i].id == id) {
            printf("%d. Cliente: %s | Funcionário: %s | Bicicleta: %d | Qtde: %d | Total: %.2f\n",
                   vendas[i].id, vendas[i].cpf_cliente, vendas[i].cpf_funcionario,
                   vendas[i].id_bicicleta, vendas[i].quantidade, vendas[i].valor_total);
            Enter();
            return;
        }
    }

    printf("Venda não encontrada.\n");
    Enter();
}

// Editar uma venda
void tela_editar_venda(void) {
    carregar_vendas_binario();
    if (qtd_vendas == 0) { printf("Nenhuma venda cadastrada.\n"); Enter(); return; }

    char entrada[64];
    int id;
    printf("ID da venda: ");
    fgets(entrada, sizeof(entrada), stdin);
    id = atoi(entrada);

    for (int i = 0; i < qtd_vendas; i++) {
        Venda *v = &vendas[i];
        if (v->id == id) {
            // devolver estoque da venda antiga
            float preco_old;
            int estoque_old;
            if (obter_info_bicicleta(v->id_bicicleta, &preco_old, &estoque_old)) {
                estoque_old += v->quantidade;
                atualizar_estoque_bicicleta(v->id_bicicleta, estoque_old);
            }

            printf("Novo CPF cliente: ");
            fgets(v->cpf_cliente, sizeof(v->cpf_cliente), stdin);
            v->cpf_cliente[strcspn(v->cpf_cliente, "\n")] = 0;
            if (!cliente_existe_arquivo(v->cpf_cliente)) { printf("Cliente não encontrado!\n"); Enter(); return; }

            printf("Novo CPF funcionário: ");
            fgets(v->cpf_funcionario, sizeof(v->cpf_funcionario), stdin);
            v->cpf_funcionario[strcspn(v->cpf_funcionario, "\n")] = 0;
            if (!funcionario_existe_arquivo(v->cpf_funcionario)) { printf("Funcionário não encontrado!\n"); Enter(); return; }

            printf("Novo ID bicicleta: ");
            fgets(entrada, sizeof(entrada), stdin);
            v->id_bicicleta = atoi(entrada);

            {
                float preco_new;
                int estoque_new;
                if (!obter_info_bicicleta(v->id_bicicleta, &preco_new, &estoque_new)) { printf("Bicicleta não encontrada!\n"); Enter(); return; }

                printf("Nova quantidade: ");
                fgets(entrada, sizeof(entrada), stdin);
                v->quantidade = atoi(entrada);
                if (v->quantidade <= 0) { printf("Quantidade inválida!\n"); Enter(); return; }
                if (v->quantidade > estoque_new) { printf("Estoque insuficiente!\n"); Enter(); return; }

                estoque_new -= v->quantidade;
                atualizar_estoque_bicicleta(v->id_bicicleta, estoque_new);
                v->valor_total = preco_new * v->quantidade;
            }

            if (!salvar_vendas_binario()) { printf("Erro ao salvar vendas.\n"); Enter(); return; }
            printf("Venda editada com sucesso!\n");
            Enter();
            return;
        }
    }

    printf("Venda não encontrada.\n");
    Enter();
}

// Excluir uma venda
void tela_excluir_venda(void) {
    carregar_vendas_binario();
    if (qtd_vendas == 0) { printf("Nenhuma venda cadastrada.\n"); Enter(); return; }

    char entrada[64];
    int id;
    printf("ID da venda: ");
    fgets(entrada, sizeof(entrada), stdin);
    id = atoi(entrada);

    for (int i = 0; i < qtd_vendas; i++) {
        if (vendas[i].id == id) {
            // devolver estoque da venda
            float preco;
            int estoque;
            if (obter_info_bicicleta(vendas[i].id_bicicleta, &preco, &estoque)) {
                estoque += vendas[i].quantidade;
                atualizar_estoque_bicicleta(vendas[i].id_bicicleta, estoque);
            }

            // remove venda do array
            for (int j = i; j < qtd_vendas - 1; j++) vendas[j] = vendas[j + 1];
            qtd_vendas--;
            if (!salvar_vendas_binario()) { printf("Erro ao salvar vendas.\n"); Enter(); return; }

            printf("Venda excluída com sucesso!\n");
            Enter();
            return;
        }
    }

    printf("Venda não encontrada.\n");
    Enter();
}
