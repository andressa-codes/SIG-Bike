#ifndef FUNCIONARIOS_H
#define FUNCIONARIOS_H

#define TAM_NOME_FUNC 50
#define TAM_EMAIL_FUNC 50
#define TAM_CARGO_FUNC 30
#define TAM_CPF_FUNC 15

#define ARQ_FUNCIONARIOS "dados/funcionarios.dat"  // Corrigido o caminho do arquivo




typedef struct {
    char nome[TAM_NOME_FUNC];
    char email[TAM_EMAIL_FUNC];
    char cargo[TAM_CARGO_FUNC];
    char cpf[TAM_CPF_FUNC];
    char status; // 'A' para ativo, 'I' para inativo
} Funcionario;

// Módulos principais
void modulo_funcionarios(void);


// Declarações das funções (sem o corpo {})

// Telas de interação
void tela_cadastrar_funcionario(void);
void tela_ver_funcionarios(void);
void tela_pesquisar_funcionario(void);
void tela_editar_funcionario(void);
void tela_excluir_funcionario(void);

// Função utilitária para verificação de existência
int funcionario_existe_arquivo(const char *cpf);


#endif
