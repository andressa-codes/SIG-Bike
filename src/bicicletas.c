#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/tela_inicial.h"
#include "../include/bicicletas.h"

#define ARQ_BICICLETAS "dados/bicicletas.dat"
#define TEMP_BICICLETA  "dados/temp_bicicletas.dat"

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
        printf("///                    = = = = = SIG-Bike = = = = =                         ///\n");
        printf("///                                                                         ///\n");
        printf("///            1. Cadastrar bicicleta                                       ///\n");
        printf("///            2. Ver bicicletas cadastradas                                ///\n");
        printf("///            3. Pesquisar dados de uma bicicleta                          ///\n");
        printf("///            4. Editar dados de uma bicicleta                             ///\n");
        printf("///            5. Excluir bicicleta do sistema                              ///\n");
        printf("///            6. Voltar para o menu principal                              ///\n");
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
    novo.status = 'A';
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
        if (b.status == 'I') continue; // pula inativas

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
    if (b.status == 'I') continue; 
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
void tela_editar_bicicleta(void) {
    FILE *arq = fopen(ARQ_BICICLETAS, "r+b");
    if (!arq) {
        printf("Erro ao abrir arquivo.\n");
        Enter();
        return;
    }

    int idBuscado, encontrado = 0;
    Bicicleta b;

    system("cls||clear");
    printf("===== Editar Bicicleta =====\n");
    printf("Digite o ID da bicicleta que deseja editar: ");
    scanf("%d", &idBuscado);
    getchar();

    while (fread(&b, sizeof(Bicicleta), 1, arq) == 1) {
        if (b.id == idBuscado) {
            encontrado = 1;

            // 🧠 Aqui entra o trecho que te mostrei
            if (b.status == 'I') {
                printf("Essa bicicleta está inativa e não pode ser editada.\n");
                fclose(arq);
                Enter();
                return; // sai da função sem permitir edição
            }

            printf("\n=== Bicicleta Encontrada ===\n");
            printf("Marca atual: %s\n", b.marca);
            printf("Novo valor (ou Enter para manter): ");
            fgets(b.marca, TAM_MARCA, stdin);
            b.marca[strcspn(b.marca, "\n")] = 0;

            // Exemplo editando outro campo:
            printf("Novo preço (ou 0 para manter): ");
            float novoPreco;
            scanf("%f", &novoPreco);
            getchar();
            if (novoPreco > 0) b.preco = novoPreco;

            // Volta o ponteiro 1 registro atrás e regrava
            fseek(arq, -sizeof(Bicicleta), SEEK_CUR);
            fwrite(&b, sizeof(Bicicleta), 1, arq);

            printf("\nBicicleta atualizada com sucesso!\n");
            break;
        }
    }

    if (!encontrado)
        printf("Bicicleta não encontrada.\n");

    fclose(arq);
    Enter();
}

// ======================== EXCLUIR ==============================
void tela_excluir_bicicleta(void) {
    FILE *fp = fopen(ARQ_BICICLETAS, "rb");
    if (!fp) { 
        printf("Erro ao abrir arquivo.\n"); 
        Enter(); 
        return; 
    }

    FILE *temp = fopen(TEMP_BICICLETA, "wb");
    if (!temp) { 
        fclose(fp); 
        printf("Erro ao criar arquivo temporário.\n"); 
        Enter(); 
        return; 
    }

    Bicicleta b;
    int id_excluir;
    int encontrado = 0;
    int tipo_exclusao;

    system("cls||clear");
    printf("Digite o ID da bicicleta a excluir: ");
    scanf("%d", &id_excluir);
    getchar();

    printf("============== Tipo de exclusão =============\n");
    printf("= 1. Exclusão lógica (inativar bicicleta)  =\n");
    printf("= 2. Exclusão física (remover do sistema)  =\n");
    printf("============================================\n");
    printf("Escolha uma opção: ");
    scanf("%d", &tipo_exclusao);
    getchar();

    while (fread(&b, sizeof(Bicicleta), 1, fp) == 1) {
        if (b.id == id_excluir) {
            encontrado = 1;
            if (tipo_exclusao == 1) {
                b.status = 'I'; // Exclusão lógica
                printf("Bicicleta inativada com sucesso.\n");
                fwrite(&b, sizeof(Bicicleta), 1, temp);
            }
            // Exclusão física: não escreve o registro no temp
        } else {
            fwrite(&b, sizeof(Bicicleta), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove(ARQ_BICICLETAS);
    rename(TEMP_BICICLETA, ARQ_BICICLETAS);

    if (encontrado && tipo_exclusao == 2) {
        printf("===================================\n");
        printf("= Bicicleta excluída com sucesso! =\n");
        printf("===================================\n");
    } else if (!encontrado) {
        printf("===================================\n");
        printf("= Bicicleta não encontrada!       =\n");
        printf("===================================\n");
    }

    Enter();
}
// ======================== FUNÇÕES AUXILIARES ==============================
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

// Função de atualizar o estoque
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

