#include <stdio.h>
#include <stdlib.h>
#include "../include/tela_inicial.h"
#include "../include/tela_principal.h"

void tela_principal(void) {
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
        printf("///                                                                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                                                                         ///\n");
        printf("///                    = = = = = SIG-Bike = = = = =                         ///\n");
        printf("///                                                                         ///\n");
        printf("///            Escolha o módulo que deseja acessar:                         ///\n");
        printf("///            1. Módulo clientes                                           ///\n");
        printf("///            2. Módulo funcionários                                       ///\n");
        printf("///            3. Módulo bicicletas                                         ///\n"); 
        printf("///            4. Módulo vendas                                             ///\n"); 
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
            case 1: modulo_clientes(); break;
            case 2: modulo_funcionarios(); break;
            case 3: modulo_bicicletas(); break;
            case 4: modulo_vendas(); break;
            case 6: return;
            default:
                printf("Opção inválida! Tente novamente.\n");
                Enter();
        }
    } while (opcao != 6);
}
