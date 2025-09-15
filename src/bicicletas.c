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
    system("cls||clear");
    if(qtd_bicicletas >= MAX_BICICLETAS){
        printf("Limite de bicicletas atingido!\n");
        Enter();
        return;
    }

    Bicicleta novo;
    char entrada[50]; 
    novo.id = qtd_bicicletas + 1;

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

    printf("\n===================================\n");
    printf("= Cadastro realizado com sucesso!   =\n");
    printf("= ID da bicicleta: %d\n", novo.id);
    printf("===================================\n");
    Enter();
}

void tela_ver_bicicletas(void){
    system("cls||clear");
    printf("\n=== Bicicletas Cadastradas ===\n");
    if(qtd_bicicletas == 0){
        printf("Nenhuma bicicleta cadastrada.\n");
    } else {
        for(int i = 0; i < qtd_bicicletas; i++){
            printf("%d. Marca: %s | Modelo: %s | Ano: %d | Cor: %s | Preço: R$ %.2f | Estoque: %d\n",
                i+1, bicicletas[i].marca, bicicletas[i].modelo, bicicletas[i].ano, bicicletas[i].cor, bicicletas[i].preco, bicicletas[i].estoque
            );
        }
    }
    Enter();
}

void tela_pesquisar_bicicleta(void){
    system("cls||clear");
    
    if(qtd_bicicletas == 0){
        printf("Nenhuma bicicleta cadastrada.\n");
        Enter();
        return;
    }

    int id;
    char entrada[50];

    printf("Digite o ID da bicicleta que deseja visualizar: ");
    fgets(entrada, sizeof(entrada), stdin);
    id = atoi(entrada);

    int encontrado = -1;
    for(int i = 0; i < qtd_bicicletas; i++){
        if(bicicletas[i].id == id){
            encontrado = i;
            break;
        }
    }

    if(encontrado == -1){
        printf("\nBicicleta com ID %d não encontrada.\n", id);
    } else {
        int i = encontrado;
        printf("%d. Marca: %s | Modelo: %s | Ano: %d | Cor: %s | Preço: R$ %.2f | Estoque: %d\n",
            bicicletas[i].id, bicicletas[i].marca, bicicletas[i].modelo, bicicletas[i].ano, 
            bicicletas[i].cor, bicicletas[i].preco, bicicletas[i].estoque
        );
    }
    Enter();
}

void tela_editar_bicicleta(void){
    system("cls||clear");
    if(qtd_bicicletas == 0){
        printf("Nenhuma bicicleta cadastrada.\n");
        Enter();
        return;
    }

    char entrada[50];
    int id;
    printf("Digite o ID da bicicleta que deseja editar: ");
    fgets(entrada, sizeof(entrada), stdin);
    id = atoi(entrada);

    int encontrado = -1;
    for(int i = 0; i < qtd_bicicletas; i++){
        if(bicicletas[i].id == id){
            encontrado = i;
            break;
        }
    }

    if(encontrado == -1){
        printf("\nBicicleta com ID %d não encontrada.\n", id);
        Enter();
        return;
    }

    Bicicleta *b = &bicicletas[encontrado];

    printf("Marca: ");
    fgets(b->marca, TAM_MARCA, stdin);
    b->marca[strcspn(b->marca, "\n")] = 0;

    printf("Modelo: ");
    fgets(b->modelo, TAM_MODELO, stdin);
    b->modelo[strcspn(b->modelo, "\n")] = 0;

    printf("Ano: ");
    fgets(entrada, sizeof(entrada), stdin);
    b->ano = atoi(entrada);   

    printf("Cor: ");
    fgets(b->cor, TAM_COR, stdin);
    b->cor[strcspn(b->cor, "\n")] = 0;

    printf("Preço: ");
    fgets(entrada, sizeof(entrada), stdin);
    b->preco = atof(entrada); 

    printf("Quantidade em estoque: ");
    fgets(entrada, sizeof(entrada), stdin);
    b->estoque = atoi(entrada);

    printf("=======================================\n");
    printf("=    Edição realizada com sucesso!    =\n");
    printf("=======================================\n");
    Enter();
}

void tela_excluir_bicicleta(void){
    system("cls||clear");

    if(qtd_bicicletas == 0){
        printf("Nenhuma bicicleta cadastrada para excluir.\n");
        Enter();
        return;
    }

    char entrada[50];
    int id;
    printf("Digite o ID da bicicleta para excluir: ");
    fgets(entrada, sizeof(entrada), stdin);
    id = atoi(entrada);

    int encontrado = -1;
    for(int i = 0; i < qtd_bicicletas; i++){
        if(bicicletas[i].id == id){
            encontrado = i;
            break;
        }
    }

    system("cls||clear");
    if(encontrado == -1){
        printf("=============================\n");
        printf("= Bicicleta não encontrada! =\n");
        printf("=============================\n");
    } else {

        for(int i = encontrado; i < qtd_bicicletas - 1; i++){
            bicicletas[i] = bicicletas[i+1];
        }
        qtd_bicicletas--; 

        printf("===================================\n");
        printf("= Exclusão realizada com sucesso! =\n");
        printf("===================================\n");
    }
    Enter();
}