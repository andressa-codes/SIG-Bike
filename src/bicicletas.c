#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/tela_inicial.h"
#include "../include/bicicletas.h"

#define ARQ_BICICLETAS "dados/bicicletas.dat"

void modulo_bicicletas(void);
void tela_cadastrar_bicicleta(void);
void tela_ver_bicicletas(void);
void tela_pesquisar_bicicleta(void);
void tela_editar_bicicleta(void);
void tela_excluir_bicicleta(void);

void modulo_bicicletas(void) {
    int opcao;

    do {
        system("clear||cls");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                                                                         ///\n");
        printf("///                   ____ ___ ____       ____  _ _                         ///\n");
        printf("///                  / ___|_ _/ ___|     | __ )(_) | _____                  ///\n");
        printf("///                  \\___ \\| | |  _ _____|  _ \\| | |/ / _ \\                 ///\n");
        printf("///                   ___) | | |_| |_____| |_) | |   <  __/                 ///\n");
        printf("///                  |____/___\\____|     |____/|_|_|\\_\\___|                 ///\n");
        printf("///                                                                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                                                                         ///\n");
        printf("///                    = = = = = SIG-Bike = = = = =                         ///\n");
        printf("///                                                                         ///\n");
        printf("///            1. Cadastrar bicicleta                                       ///\n");
        printf("///            2. Ver bicicletas cadastradas                                ///\n");
        printf("///            3. Pesquisar dados de uma bicicleta                          ///\n");
        printf("///            4. Editar dados de uma bicicleta                             ///\n");
        printf("///            5. Excluir bicicleta do sistema                              ///\n");
        printf("///            6. Voltar para o menu principal                              ///\n");
        printf("///                                                                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("Escolha a opção desejada: ");
        if(scanf("%d", &opcao) != 1){
            while(getchar() != '\n');
            opcao = 0;
        }
        while(getchar() != '\n');

        switch(opcao){
            case 1: tela_cadastrar_bicicleta(); break;
            case 2: tela_ver_bicicletas(); break;
            case 3: tela_pesquisar_bicicleta(); break;
            case 4: tela_editar_bicicleta(); break;
            case 5: tela_excluir_bicicleta(); break;
            case 6: return;
            default:
                printf("Opção inválida!\n");
                Enter();
        }
    } while(opcao != 6);
}

// ======================== CADASTRAR ==============================
void tela_cadastrar_bicicleta(void){
    FILE *arq;
    Bicicleta novo, temp;
    int ultimo_id = 0;

    system("cls||clear");

    arq = fopen(ARQ_BICICLETAS, "rb");
    if (arq != NULL) {
        while (fread(&temp, sizeof(Bicicleta), 1, arq) == 1) {
            if (temp.id > ultimo_id)
                ultimo_id = temp.id;
        }
        fclose(arq);
    }

    novo.id = ultimo_id + 1;

    printf("Marca: ");
    fgets(novo.marca, TAM_MARCA, stdin);
    novo.marca[strcspn(novo.marca, "\n")] = 0;

    printf("Modelo: ");
    fgets(novo.modelo, TAM_MODELO, stdin);
    novo.modelo[strcspn(novo.modelo, "\n")] = 0;

    printf("Ano: ");
    scanf("%d", &novo.ano);
    getchar();

    printf("Cor: ");
    fgets(novo.cor, TAM_COR, stdin);
    novo.cor[strcspn(novo.cor, "\n")] = 0;

    printf("Preço: ");
    scanf("%f", &novo.preco);
    getchar();

    printf("Estoque: ");
    scanf("%d", &novo.estoque);
    getchar();

    arq = fopen(ARQ_BICICLETAS, "ab");
    if (arq == NULL) {
        printf("Erro ao abrir arquivo de bicicletas.\n");
        Enter();
        return;
    }

    fwrite(&novo, sizeof(Bicicleta), 1, arq);
    fclose(arq);

    printf("\n===================================\n");
    printf("= Cadastro realizado com sucesso! =\n");
    printf("= ID da bicicleta: %d\n", novo.id);
    printf("===================================\n");
    Enter();
}

// ======================== LISTAR ==============================
void tela_ver_bicicletas(void){
    FILE *arq = fopen(ARQ_BICICLETAS, "rb");
    Bicicleta b;
    int count = 0;

    system("cls||clear");
    printf("\n=== Bicicletas Cadastradas ===\n");

    if (arq == NULL) {
        printf("Nenhuma bicicleta cadastrada.\n");
        Enter();
        return;
    }

    while (fread(&b, sizeof(Bicicleta), 1, arq) == 1) {
        printf("ID: %d | Marca: %s | Modelo: %s | Ano: %d | Cor: %s | Preço: %.2f | Estoque: %d\n",
               b.id, b.marca, b.modelo, b.ano, b.cor, b.preco, b.estoque);
        count++;
    }

    if (count == 0)
        printf("Nenhuma bicicleta cadastrada.\n");

    fclose(arq);
    Enter();
}

// ======================== PESQUISAR ==============================
void tela_pesquisar_bicicleta(void){
    FILE *arq = fopen(ARQ_BICICLETAS, "rb");
    Bicicleta b;
    int idBuscado, encontrado = 0;

    system("cls||clear");

    if (arq == NULL) {
        printf("Nenhuma bicicleta cadastrada.\n");
        Enter();
        return;
    }

    printf("Digite o ID da bicicleta que deseja pesquisar: ");
    scanf("%d", &idBuscado);
    getchar();

    while (fread(&b, sizeof(Bicicleta), 1, arq) == 1) {
        if (b.id == idBuscado) {
            printf("\n--- Bicicleta Encontrada ---\n");
            printf("ID: %d\nMarca: %s\nModelo: %s\nAno: %d\nCor: %s\nPreço: %.2f\nEstoque: %d\n",
                   b.id, b.marca, b.modelo, b.ano, b.cor, b.preco, b.estoque);
            encontrado = 1;
            break;
        }
    }

    fclose(arq);

    if (!encontrado)
        printf("\nNenhuma bicicleta encontrada com esse ID.\n");

    Enter();
}

// ======================== EDITAR ==============================
void tela_editar_bicicleta(void){
    FILE *arq = fopen(ARQ_BICICLETAS, "r+b");
    Bicicleta b;
    int idBuscado, encontrado = 0;

    system("cls||clear");

    if (arq == NULL) {
        printf("Nenhuma bicicleta cadastrada.\n");
        Enter();
        return;
    }

    printf("Digite o ID da bicicleta que deseja editar: ");
    scanf("%d", &idBuscado);
    getchar();

    while (fread(&b, sizeof(Bicicleta), 1, arq) == 1) {
        if (b.id == idBuscado) {
            encontrado = 1;
            printf("\n--- Editando bicicleta ID %d ---\n", b.id);

            printf("Nova Marca: ");
            fgets(b.marca, TAM_MARCA, stdin);
            b.marca[strcspn(b.marca, "\n")] = 0;

            printf("Novo Modelo: ");
            fgets(b.modelo, TAM_MODELO, stdin);
            b.modelo[strcspn(b.modelo, "\n")] = 0;

            printf("Novo Ano: ");
            scanf("%d", &b.ano);
            getchar();

            printf("Nova Cor: ");
            fgets(b.cor, TAM_COR, stdin);
            b.cor[strcspn(b.cor, "\n")] = 0;

            printf("Novo Preço: ");
            scanf("%f", &b.preco);
            getchar();

            printf("Novo Estoque: ");
            scanf("%d", &b.estoque);
            getchar();

            fseek(arq, -sizeof(Bicicleta), SEEK_CUR);
            fwrite(&b, sizeof(Bicicleta), 1, arq);
            printf("\nBicicleta atualizada com sucesso!\n");
            break;
        }
    }

    fclose(arq);

    if (!encontrado)
        printf("Bicicleta com ID não encontrada.\n");

    Enter();
}

// ======================== EXCLUIR ==============================
void tela_excluir_bicicleta(void){
    FILE *arq = fopen(ARQ_BICICLETAS, "rb");
    FILE *temp = fopen("dados/temp.dat", "wb");
    Bicicleta b;
    int id_excluir, encontrado = 0;

    system("cls||clear");
    printf("\n=== Excluir Bicicleta ===\n");

    if (arq == NULL) {
        printf("Nenhuma bicicleta cadastrada.\n");
        Enter();
        return;
    }

    printf("Digite o ID da bicicleta que deseja excluir: ");
    scanf("%d", &id_excluir);
    getchar();

    while (fread(&b, sizeof(Bicicleta), 1, arq) == 1) {
        if (b.id == id_excluir) {
            encontrado = 1;
        } else {
            fwrite(&b, sizeof(Bicicleta), 1, temp);
        }
    }

    fclose(arq);
    fclose(temp);

    remove(ARQ_BICICLETAS);
    rename("dados/temp.dat", ARQ_BICICLETAS);

    if (encontrado)
        printf("Bicicleta excluída com sucesso!\n");
    else
        printf("Nenhuma bicicleta encontrada com esse ID.\n");

    Enter();
}

// Função para obter o preço e o estoque de uma bicicleta com base no ID
int obter_info_bicicleta(int id, float *preco, int *estoque) {
    FILE *arq = fopen(ARQ_BICICLETAS, "rb");
    Bicicleta b;

    if (arq == NULL) {
        return 0; 
    }

    while (fread(&b, sizeof(Bicicleta), 1, arq) == 1) {
        if (b.id == id) {
            if (preco != NULL) *preco = b.preco;
            if (estoque != NULL) *estoque = b.estoque;
            fclose(arq);
            return 1; 
        }
    }

    fclose(arq);
    return 0; 
}

// Função para atualizar o estoque de uma bicicleta com base no ID
void atualizar_estoque_bicicleta(int id, int novo_estoque) {
    FILE *arq = fopen(ARQ_BICICLETAS, "r+b");
    Bicicleta b;

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo para atualizar estoque.\n");
        return;
    }

    while (fread(&b, sizeof(Bicicleta), 1, arq) == 1) {
        if (b.id == id) {
            b.estoque = novo_estoque;
            fseek(arq, -sizeof(Bicicleta), SEEK_CUR);
            fwrite(&b, sizeof(Bicicleta), 1, arq);
            break;
        }
    }

    fclose(arq);
}
