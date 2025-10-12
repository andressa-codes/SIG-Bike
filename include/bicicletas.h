#ifndef BICICLETA_H
#define BICICLETA_H

#define MAX_BICICLETAS 200
#define TAM_MARCA 50
#define TAM_MODELO 50
#define TAM_COR 30

typedef struct {
    char marca[TAM_MARCA];
    char modelo[TAM_MODELO];
    int ano;
    char cor[TAM_COR];
    float preco;
    int estoque;
    int id;
} Bicicleta;

extern Bicicleta bicicletas[MAX_BICICLETAS];
extern int qtd_bicicletas;

void modulo_bicicletas(void);
void tela_cadastrar_bicicleta(void);
void tela_ver_bicicletas(void);
void tela_pesquisar_bicicleta(void);
void tela_editar_bicicleta(void);
void tela_excluir_bicicleta(void);

#endif