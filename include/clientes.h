#ifndef CLIENTES_H
#define CLIENTES_H

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

extern Cliente clientes[MAX_CLIENTES];
extern int qtd_clientes;

void modulo_clientes(void);
void tela_cadastrar_cliente(void);
void tela_ver_clientes(void);
void tela_pesquisar_cliente(void);
void tela_editar_cliente(void);
void tela_excluir_cliente(void);
int cliente_existe_arquivo(const char *cpf); 
#endif