#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/tela_inicial.h"
#include "../include/bicicletas.h"

Bicicleta bicicletas[MAX_BICICLETAS];
int qtd_bicicletas = 0;

void modulo_bicicletas(void) {
    int opcao;

    do {
        system("cls||clear");
        printf("\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                                                                         ///\n");
        printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
        printf("///                 Centro de Ensino Superior do Seridó                     ///\n");
        printf("///               Departamento de Computação e Tecnologia                   ///\n");
        printf("///                  Disciplina DCT1106 -- Programação                      ///\n");
        printf("///          Projeto Sistema de Gestão de uma loja de bicicletas            ///\n");
        printf("///   Developed by @andressa-codes and @Jezreel-Asaias -- since Aug, 2025   ///\n");
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
        printf("///            Escolha a opção desejada:                                    ///\n");
        printf("///                                                                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        if(scanf("%d", &opcao) != 1){
            while(getchar() != '\n');
            opcao = 0;
        }
        while(getchar() != '\n');

        switch(opcao){
            case 1:
                tela_cadastrar_bicicleta();
                break;
            case 2:
                tela_ver_bicicletas();
                break;
            case 3:
                tela_pesquisar_bicicleta();
                break;
            case 4:
                tela_editar_bicicleta();
                break;
            case 5:
                tela_excluir_bicicleta();
                break;
            case 6:
                return;
            default:
                printf("Opção inválida!\n");
                Enter();
        }
    } while(opcao != 6);
}

void tela_cadastrar_bicicleta(void){
    FILE *arq_bicicletas;
    system("cls||clear");
    if(qtd_bicicletas >= MAX_BICICLETAS){
        printf("Limite de bicicletas atingido!\n");
        Enter();
        return;
    }

    Bicicleta novo;
    char entrada[50]; 
    int ultimo_id = 0;

    
    arq_bicicletas = fopen("dados/bicicletas.csv", "rt");
    if (arq_bicicletas != NULL) {
        int id, ano, estoque;
        char marca[TAM_MARCA], modelo[TAM_MODELO], cor[TAM_COR];
        float preco;

        while (fscanf(arq_bicicletas, "%d;%[^;];%[^;];%d;%[^;];%f;%d\n",
                      &id, marca, modelo, &ano, cor, &preco, &estoque) == 7) {
            if (id > ultimo_id) {
                ultimo_id = id;
            }
        }
        fclose(arq_bicicletas);
    }


    novo.id = ultimo_id + 1;

    printf("Marca: ");
    fgets(novo.marca, TAM_MARCA, stdin);
    novo.marca[strcspn(novo.marca, "\n")] = 0;

    printf("Modelo: ");
    fgets(novo.modelo, TAM_MODELO, stdin);
    novo.modelo[strcspn(novo.modelo, "\n")] = 0;

    printf("Ano: ");
    fgets(entrada, sizeof(entrada), stdin);
    novo.ano = atoi(entrada);   

    printf("Cor: ");
    fgets(novo.cor, TAM_COR, stdin);
    novo.cor[strcspn(novo.cor, "\n")] = 0;

    printf("Preço: ");
    fgets(entrada, sizeof(entrada), stdin);
    novo.preco = atof(entrada); 

    printf("Quantidade em estoque: ");
    fgets(entrada, sizeof(entrada), stdin);
    novo.estoque = atoi(entrada);

    bicicletas[qtd_bicicletas++] = novo;

    
    arq_bicicletas = fopen("dados/bicicletas.csv", "a");
    if(arq_bicicletas == NULL){
        printf("Erro ao abrir o arquivo de bicicletas.\n");
        return;
    }
    fprintf(arq_bicicletas, "%d;", novo.id); 
    fprintf(arq_bicicletas, "%s;", novo.marca);
    fprintf(arq_bicicletas, "%s;", novo.modelo);
    fprintf(arq_bicicletas, "%i;", novo.ano);
    fprintf(arq_bicicletas, "%s;", novo.cor);
    fprintf(arq_bicicletas, "%f;", novo.preco);
    fprintf(arq_bicicletas, "%i\n", novo.estoque);
    fclose(arq_bicicletas);

    printf("\n===================================\n");
    printf("= Cadastro realizado com sucesso! =\n");
    printf("= ID da bicicleta: %d\n", novo.id);
    printf("===================================\n");
    Enter();
}




void tela_ver_bicicletas(void){
    system("cls||clear");
    printf("\n=== Bicicletas Cadastradas ===\n");

    FILE *arq_ver_bicicletas = fopen("dados/bicicletas.csv", "rt");
    if (arq_ver_bicicletas == NULL) {
        printf("Nenhuma bicicleta cadastrada (arquivo vazio ou não encontrado).\n");
        Enter();
        return;
    }
   


int id;
char marca[TAM_MARCA], modelo[TAM_MODELO], cor[TAM_COR];
int ano, estoque;
float preco;
int count = 0;




while (fscanf(arq_ver_bicicletas, "%d;%[^;];%[^;];%d;%[^;];%f;%d\n",
              &id, marca, modelo, &ano, cor, &preco, &estoque) == 7) {
    printf("ID: %d | Marca: %s | Modelo: %s | Ano: %d | Cor: %s | Preço: %.2f | Estoque: %d\n",
           id, marca, modelo, ano, cor, preco, estoque);
    count++;
}

    if (count == 0) {
        printf("Nenhuma Bicicleta cadastrado.\n");
    }

    fclose(arq_ver_bicicletas);
    Enter();
}


 

void tela_pesquisar_bicicleta(void) {
    system("cls||clear");

    FILE *arq_pesquisar_bicicletas = fopen("dados/bicicletas.csv", "rt");
    if (arq_pesquisar_bicicletas == NULL) {
        printf("Nenhuma bicicleta cadastrada (arquivo vazio ou não encontrado).\n");
        Enter();
        return;
    }

    int id, ano, estoque, idBuscado;
    char marca[TAM_MARCA], modelo[TAM_MODELO], cor[TAM_COR];
    float preco;
    int encontrado = 0;

    printf("Digite o ID da bicicleta que deseja ver: ");
    scanf("%d", &idBuscado);
    getchar();

    while (fscanf(arq_pesquisar_bicicletas, "%d;%[^;];%[^;];%d;%[^;];%f;%d\n",
                  &id, marca, modelo, &ano, cor, &preco, &estoque) == 7) {

        if (id == idBuscado) {
            printf("\n--- Bicicleta Encontrada ---\n");
            printf("ID: %d\n", id);
            printf("Marca: %s\n", marca);
            printf("Modelo: %s\n", modelo);
            printf("Ano: %d\n", ano);
            printf("Cor: %s\n", cor);
            printf("Preço: %.2f\n", preco);
            printf("Estoque: %d\n", estoque);
            encontrado = 1;
            break;
        }
    }

    fclose(arq_pesquisar_bicicletas);

    if (!encontrado) {
        printf("\nNenhuma bicicleta encontrada com esse ID.\n");
    }

    Enter();
}

 

void tela_editar_bicicleta(void){
    system("cls||clear");

    FILE *arq = fopen("dados/bicicletas.csv", "rt");
    if (!arq) {
        printf("Nenhuma bicicleta cadastrada.\n");
        Enter();
        return;
    }

    FILE *temp = fopen("dados/temp.csv", "wt");
    if (!temp) {
        fclose(arq);
        printf("Erro ao criar arquivo temporário.\n");
        Enter();
        return;
    }

    int id, ano, estoque, idBuscado;
    char marca[TAM_MARCA], modelo[TAM_MODELO], cor[TAM_COR];
    float preco;
    int encontrado = 0;

    printf("Digite o ID da bicicleta que deseja editar: ");
    scanf("%d", &idBuscado);
    getchar();

    while (fscanf(arq, "%d;%[^;];%[^;];%d;%[^;];%f;%d\n",
                  &id, marca, modelo, &ano, cor, &preco, &estoque) == 7) {

        if (id == idBuscado) {
            encontrado = 1;
            printf("\n--- Editando bicicleta ID %d ---\n", id);

            printf("Nova Marca: ");
            fgets(marca, TAM_MARCA, stdin);
            marca[strcspn(marca, "\n")] = 0;

            printf("Novo Modelo: ");
            fgets(modelo, TAM_MODELO, stdin);
            modelo[strcspn(modelo, "\n")] = 0;

            printf("Novo Ano: ");
            scanf("%d", &ano);
            getchar();

            printf("Nova Cor: ");
            fgets(cor, TAM_COR, stdin);
            cor[strcspn(cor, "\n")] = 0;

            printf("Novo Preço: ");
            scanf("%f", &preco);
            getchar();

            printf("Novo Estoque: ");
            scanf("%d", &estoque);
            getchar();
        }

        fprintf(temp, "%d;%s;%s;%d;%s;%.2f;%d\n",
                id, marca, modelo, ano, cor, preco, estoque);
    }

    fclose(arq);
    fclose(temp);
    remove("dados/bicicletas.csv");
    rename("dados/temp.csv", "dados/bicicletas.csv");

    if (encontrado)
        printf("Bicicleta cadastrada com sucesso\n");
    else
        printf("Bicicleta com ID não encontrada.\n");

    Enter();
}

void tela_excluir_bicicleta(void){
    system("cls||clear");
    printf("\n=== Excluir Bicicleta ===\n");

    int id_excluir;
    printf("Digite o ID da bicicleta que deseja excluir: ");
    scanf("%d", &id_excluir);

    FILE *arq = fopen("dados/bicicletas.csv", "rt");
    if (arq == NULL) {
        printf("Nenhuma bicicleta cadastrada.\n");
        Enter();
        return;
    }

    FILE *temp = fopen("dados/temp.csv", "wt");
    if (temp == NULL) {
        printf("Erro ao criar arquivo temporário.\n");
        fclose(arq);
        Enter();
        return;
    }

    char linha[256];
    int id, ano, estoque;
    char marca[TAM_MARCA], modelo[TAM_MODELO], cor[TAM_COR];
    float preco;
    int encontrado = 0;

    while (fgets(linha, sizeof(linha), arq)) {
        if (sscanf(linha, "%d;%[^;];%[^;];%d;%[^;];%f;%d",
                   &id, marca, modelo, &ano, cor, &preco, &estoque) == 7) {
            if (id == id_excluir) {
                encontrado = 1;
            } else {
                fprintf(temp, "%d;%s;%s;%d;%s;%.2f;%d\n",
                        id, marca, modelo, ano, cor, preco, estoque);
            }
        }
    }

    fclose(arq);
    fclose(temp);

    remove("dados/bicicletas.csv");
    rename("dados/temp.csv", "dados/bicicletas.csv");

    if (encontrado) {
        printf(" Bicicleta de ID  excluída com sucesso!\n");
    } else {
        printf(" Nenhuma bicicleta encontrada com o ID .\n");
    }

    Enter();
}