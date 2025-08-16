#include <stdio.h>
#include <stdlib.h>

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void tela_sobre(){
    system("clear||cls");
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
    printf("///  O projeto SIG-Bike está sendo desenvolvido na disciplina DCT1106       ///\n");
    printf("///  – Programação, sob orientação do professor Flávius Gorgonio, durante   ///\n");
    printf("///  o semestre 2025.2. Trata-se de um sistema acadêmico criado para fins   ///\n");
    printf("///  de aprendizado, cujo objetivo principal é exercitar os conceitos de    ///\n");
    printf("///  programação em linguagem C por meio do desenvolvimento de um software  ///\n");
    printf("///  de gestão voltado a uma loja de bicicletas.                            ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

int main() {
    int opcao;

    do {
        printf("======================================\n");
        printf("==== Bem-vindo ao nosso sistema! =====\n");
        printf("======================================\n");
        printf("= Selecione uma das opções:          =\n");
        printf("= 1 - tela principal                 =\n");
        printf("= 2 - equipe de desenvolvimento      =\n");
        printf("= 3 - sobre o sistema                =\n");
        printf("= 4 - sair                           =\n");
        printf("======================================\n");

        printf("Digite uma opção para prosseguir: ");
        if (scanf("%d", &opcao) != 1) {
            printf("Você escolheu uma opção que não existe. Por favor, tente novamente.\n");
            limparBuffer();
            opcao = 0;
            continue;
        }

        limparBuffer();

        switch(opcao) {
            case 1:
                printf("Bem-vindo à tela principal.\n");
                break;
            case 2:
                printf("Bem-vindo à equipe de desenvolvimento.\n");
                break;
            case 3:
                printf("Bem-vindo à tela sobre o sistema.\n");
                tela_sobre();
                break;
            case 4:
                printf("Saindo do programa. Te vejo em breve!\n");
                break;
            default:
                printf("Você escolheu uma opção que não existe. Por favor, tente novamente.\n");
        }
    } while(opcao != 4);

    return 0;
}
