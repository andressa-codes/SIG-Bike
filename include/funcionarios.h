#ifndef FUNCIONARIOS_H
#define FUNCIONARIOS_H

#define MAX_FUNCIONARIOS 100
#define TAM_NOME_FUNC 50
#define TAM_EMAIL_FUNC 50
#define TAM_CARGO 30
#define TAM_CPF_FUNC 15

typedef struct {
    char nome[TAM_NOME_FUNC];
    char email[TAM_EMAIL_FUNC];
    char cargo[TAM_CARGO];
    char cpf[TAM_CPF_FUNC];
} Funcionario;

extern Funcionario funcionarios[MAX_FUNCIONARIOS];
extern int qtd_funcionarios;

void modulo_funcionarios(void);
void tela_cadastrar_funcionario(void);
void tela_ver_funcionarios(void);
void tela_pesquisar_funcionario(void);
void tela_editar_funcionario(void);
void tela_excluir_funcionario(void);

#endif