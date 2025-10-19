#ifndef VENDAS_H
#define VENDAS_H

#include "../include/funcionarios.h"
#include "../include/clientes.h"
#include "../include/bicicletas.h"

#define VENDAS_FILE "dados/vendas.dat"
#define MAX_VENDAS 500

typedef struct {
    int id;
    char cpf_cliente[TAM_CPF];
    char cpf_funcionario[TAM_CPF_FUNC];
    int id_bicicleta;
    int quantidade;
    float valor_total;
    char status; // 'A' = ativo, 'I' = inativo
} Venda;

void modulo_vendas(void);
void tela_cadastrar_venda(void);
void tela_ver_vendas(void);
void tela_pesquisar_venda(void);
void tela_editar_venda(void);
void tela_excluir_venda(void);

#endif
