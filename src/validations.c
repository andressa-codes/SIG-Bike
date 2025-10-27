
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/validations.h"



int validar_nome(const char *nome) {
    for (int i = 0; nome[i] != '\0'; i++) {
        unsigned char c = nome[i];

        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
            continue;

        if (c == ' ')
            continue;

        
        if (c >= 192) {
            if (nome[i + 1] != '\0') {
                i++; 
                continue;
            }
        }

        
        return 0;
    }
    return 1;
}



int validar_email(const char *email) {
    int tem_arroba = 0, tem_ponto = 0;
    int len = strlen(email);

    if (len < 5) return 0;
    if (email[0] == '@' || email[0] == '.' || email[len-1] == '@' || email[len-1] == '.')
        return 0;

    for (int i = 0; i < len; i++) {
        unsigned char c = (unsigned char)email[i];

        if (c == '@') {
            if (tem_arroba) return 0;
            tem_arroba = 1;
            if (i + 1 < len && email[i+1] == '.') return 0;
        }
        else if (c == '.' && tem_arroba) {
            tem_ponto = 1;
        }
        else if (c == ' ') {
            return 0;
        }
        else if ((c >= 'A' && c <= 'Z')) {
            return 0;
        }
        else if (c >= 0xC0) { 

            return 0;
        }
    }

    return (tem_arroba && tem_ponto) ? 1 : 0;
}




int validar_cpf(const char *cpf) {
    int i;

    if (strlen(cpf) != 11)
        return 0;

    for (i = 0; cpf[i] != '\0'; i++) {
        if (!isdigit((unsigned char)cpf[i]))
            return 0;
    }

    return 1;
}



int validar_cargo(const char *cargo) {
    for (int i = 0; cargo[i] != '\0'; i++) {
        unsigned char c = cargo[i];

        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
            continue;
        if (c >= '0' && c <= '9')
            continue;
        if (c == ' ')
            continue;
        if (c >= 192) {
            if (cargo[i + 1] != '\0') { 
                continue;
            }
        }

        return 0;
    }
    return 1;
}



int validar_cidade(const char *cidade) {
    for (int i = 0; cidade[i] != '\0'; i++) {
        unsigned char c = cidade[i];

        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
            continue;
        if (c == ' ')
            continue;
        if (c >= 192) {
            if (cidade[i + 1] != '\0') {
                continue;
            }
        }
        return 0;
    }
    return 1;
}



int validar_marca_modelo(const char *txt) {
    for (int i = 0; txt[i] != '\0'; i++) {
        unsigned char c = txt[i];
        if (isalnum(c) || c == ' ' || c == '-' || c == '_')
            continue;
        return 0;
    }
    return strlen(txt) > 0;
}



int validar_ano(const char *ano) {
    int len = 0;

    for (int i = 0; ano[i] != '\0'; i++) {
        unsigned char c = ano[i];
        if (!isdigit(c))
            return 0;
        len++;
    }

    if (len != 4)
        return 0;

    int valor = atoi(ano);
    if (valor < 1900 || valor > 2025)
        return 0;

    return 1;
}



int validar_estoque(const char *estoque) {
    for (int i = 0; estoque[i] != '\0'; i++) {
        unsigned char c = estoque[i];

        if (c >= '0' && c <= '9')
            continue;

        return 0; 
    }

    return 1; 
}


int validar_preco(const char *preco) {
    int separador = 0; 

    for (int i = 0; preco[i] != '\0'; i++) {
        unsigned char c = preco[i];

        if (c >= '0' && c <= '9')
            continue;

        if ((c == '.' || c == ',') && separador == 0) {
            separador = 1; // permite apenas um separador decimal
            continue;
        }

        return 0; 
    }

    return 1; 
}