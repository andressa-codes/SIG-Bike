#ifndef VALIDATIONS_H
#define VALIDATIONS_H


int validar_nome(const char nome[]); 
int validar_email(const char email[]); 
int validar_cpf(const char cpf[]);
int validar_cargo(const char cargo[]);
int validar_cidade(const char cidade[]);
int validar_marca_modelo(const char txt[]);
int validar_ano(const char *ano);
int validar_preco(const char *preco);
int validar_estoque(const char *estoque);

#endif