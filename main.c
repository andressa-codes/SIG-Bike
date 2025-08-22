#include <stdio.h>
#include <stdlib.h>

// ==== Assinaturas das funções ====

void tela_principal(void);
void tela_sobre(void);
void tela_equipe(void);
void tela_sair(void);

void modulo_clientes(void);
void tela_cadastrar_cliente(void);
void tela_ver_clientes(void);
void tela_excluir_cliente(void);


void Enter(void) {
    printf("\n\t\t>>> Tecle <ENTER> para continuar... \n");
    while (getchar() != '\n');
}

void tela_principal(void) {
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
        printf("///            1. Módulo categorias                                         ///\n");
        printf("///            2. Módulo bicicletas                                         ///\n");
        printf("///            3. Módulo clientes                                           ///\n");
        printf("///            4. Módulo vendas                                             ///\n");
        printf("///            5. Módulo funcionários                                       ///\n");
        printf("///            6. Módulo Relatórios                                         ///\n");
        printf("///            7. Voltar ao menu inicial                                    ///\n");
        printf("///                                                                         ///\n");
        printf("///            Escolha a opção desejada:                                    ///\n");
        printf("///                                                                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        scanf("%d", &opcao);
        while (getchar() != '\n');

        switch(opcao) {
            case 1:
                printf(">>> Módulo categorias em construção...\n");
                Enter();
                break;
            case 2:
                printf(">>> Módulo bicicletas em construção...\n");
                Enter();
                break;
            case 3:
                modulo_clientes();
                break;
            case 4:
                printf(">>> Módulo vendas em construção...\n");
                Enter();
                break;
            case 5:
                printf(">>> Módulo funcionários em construção...\n");
                Enter();
                break;
            case 6:
                printf(">>> Módulo relatórios em construção...\n");
                Enter();
                break;
            case 7:
                return;
            default:
                printf("Opção inválida! Tente novamente.\n");
                Enter();
        }
    } while (opcao != 7);
}

void tela_sobre(){
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
    printf("///  O projeto SIG-Bike está sendo desenvolvido na disciplina DCT1106       ///\n");
    printf("///  – Programação, sob orientação do professor Flávius Gorgonio, durante   ///\n");
    printf("///  o semestre 2025.2. Trata-se de um sistema acadêmico criado para fins   ///\n");
    printf("///  de aprendizado, cujo objetivo principal é exercitar os conceitos de    ///\n");
    printf("///  programação em linguagem C por meio do desenvolvimento de um software  ///\n");
    printf("///  de gestão voltado a uma loja de bicicletas.                            ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    Enter();
}

void tela_equipe(){
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
    printf("///                    Este projeto foi desenvolvido pelos alunos:          ///\n");
    printf("///                                                                         ///\n");
    printf("///                    -> Andressa Carla da Silva                           ///\n");
    printf("///                       Email: andressa.silva.141@ufrn.edu.br             ///\n");
    printf("///                       Redes sociais: @andressa-codes                    ///\n");
    printf("///                                                                         ///\n");
    printf("///                    -> Jezreel Asaias da Silva Souza                     ///\n");
    printf("///                       Email: jezreel.asaias.silva.129@ufrn.edu.br       ///\n");
    printf("///                       Redes sociais: @Jezreel-Asaias                    ///\n");
    printf("///                                                                         ///\n");
    printf("///                Git: https://github.com/andressa-codes/SIG-Bike.git      ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    Enter();
}

void tela_sair(){
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
    printf("///   Muito obrigado por utilizar o nosso sistema, esperamos te ver         ///\n");
    printf("///   novamente em breve.                                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    Enter();
}

void modulo_clientes(void) {
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
        printf("///            1. Cadastrar cliente                                         ///\n");
        printf("///            2. Ver clientes cadastrados                                  ///\n");
        printf("///            3. Excluir cliente do sistema                                ///\n");
        printf("///            4. Voltar para o menu principal                              ///\n");
        printf("///                                                                         ///\n");
        printf("///            Escolha a opção desejada:                                    ///\n");
        printf("///                                                                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        scanf("%d", &opcao);
        while (getchar() != '\n');

        switch (opcao) {
            case 1:
                printf(">>> Função cadastrar cliente (em construção)...\n");
                Enter();
                break;
            case 2:
                printf(">>> Função ver clientes (em construção)...\n");
                Enter();
                break;
            case 3:
                printf(">>> Função excluir cliente (em construção)...\n");
                Enter();
                break;
            case 4:
                return;
            default:
                printf("Opção inválida! Tente novamente.\n");
                Enter();
        }
    } while (opcao != 4);
}

int main() {
    int opcao;

    do {
        system("cls||clear");
        printf("======================================\n");
        printf("==== Bem-vindo ao SIG-Bike! ==========\n");
        printf("======================================\n");
        printf("= Selecione uma das opções:          =\n");
        printf("= 1 - Entrar no sistema              =\n");
        printf("= 2 - Equipe de desenvolvimento      =\n");
        printf("= 3 - Sobre o sistema                =\n");
        printf("= 4 - Sair                           =\n");
        printf("======================================\n");

        printf("Digite uma opção para prosseguir: ");
        if (scanf("%d", &opcao) != 1) {
            while (getchar() != '\n');
            printf("Você escolheu uma opção que não existe. Por favor, tente novamente.\n");
            Enter();
            opcao = 0;
            continue;
        }

        while (getchar() != '\n');

        switch(opcao) {
            case 1:
                tela_principal();
                break;
            case 2:
                tela_equipe();
                break;
            case 3:
                tela_sobre();
                break;
            case 4:
                tela_sair();
                break;
            default:
                printf("Você escolheu uma opção que não existe. Por favor, tente novamente.\n");
                Enter();
        }
    } while(opcao != 4);

    return 0;
}
