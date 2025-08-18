#include <stdio.h>
#include <stdlib.h>

void esperarEnter(void) {
    printf("\n\t\t>>> Tecle <ENTER> para continuar... \n");
    while (getchar() != '\n');
}

void tela_principal(void) {
    system("clear");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                 Centro de Ensino Superior do Seridó                     ///\n");
    printf("///               Departamento de Computação e Tecnologia                   ///\n");
    printf("///                  Disciplina DCT1106 -- Programação                      ///\n");
    printf("///                  Projeto Sistema de Gestão Escolar                      ///\n");
    printf("///             Developed by @flgorgonio -- since Mar, 2020                 ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = Sistema de Gestão Escolar = = = = =                ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Módulo categorias                                         ///\n");
    printf("///            2. Módulo bicicletas                                         ///\n");
    printf("///            3. Módulo clientes                                           ///\n");
    printf("///            4. Módulo vendas                                             ///\n");
    printf("///            5. Módulo funcionários                                       ///\n");
    printf("///            6. Módulo Relatórios                                         ///\n");
    printf("///            7. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///            Escolha a opção desejada:                                    ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    esperarEnter();
}

void tela_sobre(){
    system("clear");
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
    esperarEnter();
}

void tela_equipe(){
    system("clear");
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
    esperarEnter();
}

int main() {
    int opcao;

    do {
        system("clear");
        printf("======================================\n");
        printf("==== Bem-vindo ao SIG-Bike! ===========\n");
        printf("======================================\n");
        printf("= Selecione uma das opções:          =\n");
        printf("= 1 - Entrar no sistema              =\n");
        printf("= 2 - Equipe de desenvolvimento      =\n");
        printf("= 3 - Sobre o sistema                =\n");
        printf("= 4 - Sair                           =\n");
        printf("======================================\n");

        printf("Digite uma opção para prosseguir: ");
        if (scanf("%d", &opcao) != 1) {
            while (getchar() != '\n'); // limpa buffer
            printf("Você escolheu uma opção que não existe. Por favor, tente novamente.\n");
            esperarEnter();
            opcao = 0;
            continue;
        }

        while (getchar() != '\n'); // limpa buffer

        if (opcao < 1 || opcao > 4) {
            printf("Você escolheu uma opção que não existe. Por favor, tente novamente.\n");
            esperarEnter();
            opcao = 0;
            continue;
        }

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
                printf("Saindo do programa. Te vejo em breve!\n");
                break;
        }
    } while(opcao != 4);

    return 0;
}
