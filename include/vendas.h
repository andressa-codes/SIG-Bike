#ifndef VENDAS_H
#define VENDAS_H

#define MAX_VENDAS 500

typedef struct {                 
    char cpf_cliente[TAM_CPF];   
    char cpf_funcionario[TAM_CPF_FUNC]; 
    int id_bicicleta;         
    int quantidade;           
    float valor_total;   
    int id;      
} Venda;

extern Venda vendas[MAX_VENDAS];
extern int qtd_vendas;

void modulo_vendas(void);
void tela_cadastrar_venda(void);
void tela_ver_vendas(void);
void tela_pesquisar_venda(void);
void tela_editar_venda(void);
void tela_excluir_venda(void);

#endif