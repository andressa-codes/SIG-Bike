#ifndef VALIDATIONS_H
#define VALIDATIONS_H


int validar_nome(const char nome[]); 
int validar_email(const char email[]); 
int validar_cpf(const char cpf[]);
int validar_cargo(const char cargo[]);
int validar_cidade(const char cidade[]);
int validar_marca_modelo(const char txt[]);
int validar_ano(int ano);
int validar_preco(float preco);
int validar_estoque(int estoque);

#endif