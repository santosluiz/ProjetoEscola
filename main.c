#include <stdio.h>
#include <stdlib.h>

int main()
{
    int escolha, escolhaSubMenu, sair = 0;

    while(!sair){

    escolha = opcoesMenu();

        switch(escolha){

            case 0:
                system("clear");
                printf("Você saiu do sistema.");
                sair = 1;
                break;

            case 1:
                system("clear");
                menuAlunos();
                break;

            case 2:
                system("clear");
                printf("Voce entrou em 'Professores'");
                break;

            case 3:
                system("clear");
                printf("Voce entrou em 'Disciplinas'");
                break;

            case 4:
                system("clear");
                printf("Voce entrou em 'Relatorios'");
                break;

            default:
                system("clear");
                printf("Opcao invalida!");
        }

    }

    return 0;
}

int opcoesMenu(){

    int escolha;

    printf("\ ---- Escola do Tio Luiz ---- /\n\n");

    printf("Escolha uma opço:\n");
    printf("1 - Alunos\n");
    printf("2 - Professores\n");
    printf("3 - Disciplinas\n");
    printf("4 - Relatórios\n");
    printf("0 - Sair\n");

    scanf("%d", &escolha);

    return escolha;

}

int switchAlunos(){
    int escolhaAluno;

    printf("\ ---- Alunos ---- /\n\n");

    printf("Escolha uma opçao:\n");
    printf("1 - Cadastrar Aluno\n");
    printf("2 - Atualizar Aluno\n");
    printf("3 - Excluir Aluno\n");
    printf("0 - Sair\n");

    scanf("%d", &escolhaAluno);

    return escolhaAluno;
}

int menuAlunos(){

    int escolhaSubMenu, sair = 0;

    while(!sair){
    escolhaSubMenu = switchAlunos();

        switch(escolhaSubMenu){
           case 0:
            system("clear");
            printf("Você saiu do sistema");
            sair = 1;
            break;

        case 1:
            system("clear");
            printf("Você entrou em cadastro de alunos");
            break;

        case 2:
            system("clear");
            printf("Você entrou em atualizar alunos");
            break;

        case 3:
            system("clear");
            printf("Você entrou em exclurir alunos");
            break;

        default:
            system("clear");
            printf("Opcao invalida");
            break;
        }
    }
}
