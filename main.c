#include <stdio.h>

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main() {
    int opcao;

    do {
        printf("======================================\n");
        printf("==== Bem-vindo ao nosso sistema! =====\n");
        printf("======================================\n");
        printf("= Selecione uma das opções:           =\n");
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
