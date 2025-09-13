#include <stdio.h>
#include <stdlib.h>
#include "../include/tela_inicial.h"
#include "../include/tela_principal.h"

void tela_principal(void) {
    int opcao;

    do {
        system("cls||clear");
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
        printf("///            1. Módulo bicicletas                                         ///\n");
        printf("///            2. Módulo clientes                                           ///\n");
        printf("///            3. Módulo vendas                                             ///\n");
        printf("///            4. Módulo funcionários                                       ///\n");
        printf("///            5. Módulo Relatórios                                         ///\n");
        printf("///            6. Voltar ao menu principal                                  ///\n");
        printf("///                                                                         ///\n");
        printf("///            Escolha a opção desejada:                                    ///\n");
        printf("///                                                                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");

        if (scanf("%d", &opcao) != 1) {
            while (getchar() != '\n'); 
            opcao = 0;
        }
        while (getchar() != '\n');

        switch (opcao) {
            case 1: modulo_bicicletas(); break;
            case 2: modulo_clientes(); break;
            case 3: modulo_vendas(); break;
            case 4: modulo_funcionarios(); break;
            case 6: return;
            default:
                printf("Opção inválida! Tente novamente.\n");
                Enter();
        }
    } while (opcao != 6);
}
