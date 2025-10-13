#include <stdio.h>
#include <stdlib.h>
#include "../include/tela_inicial.h"
#include "../include/modulos_info.h"
#include "../include/tela_principal.h"


void Enter(void){
    printf("\nPressione ENTER para continuar...");
    while(getchar() != '\n');
}

void tela_inicial(void){
    int opcao;
    do{
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
        printf("//////////////////////////// Bem-vindo ao SIG-Bike! ///////////////////////////\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                                                                         ///\n");
        printf("///            1 - Entrar no sistema                                        ///\n");
        printf("///            2 - Sobre o sistema                                          ///\n");
        printf("///            3 - Equipe de desenvolvimento                                ///\n");
        printf("///            4 - Sair                                                     ///\n");
        printf("///                                                                         ///\n");
        printf("///            Escolha a opção desejada:                                    ///\n");
        printf("///                                                                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");

        if(scanf("%d", &opcao) != 1){
            while(getchar() != '\n');
            opcao = 0;
        }
        while(getchar() != '\n');

        switch(opcao) {
    case 1: tela_principal(); break;
    case 2: tela_sobre(); break;     
    case 3: tela_equipe(); break;    
    case 4: tela_sair(); return;    
    default:
        printf("Opção inválida!\n");
        Enter();
}

    } while(opcao != 4);
}
