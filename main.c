#include <stdio.h>
#include <stdlib.h>
#define CADASTRO_ALUNO_TAM 5

/* Struct Aluno */
typedef struct alunoDados{
    int matricula;
    char nome[50];
    int sexo; //1 - Mulher | 2 - Homem
    char dataNascimento[10];
    char cpf[11];
}Aluno;

int main()
{
    //Variáveis do menu
    int escolha, escolhaSubMenu, sair = 0;

    //Variáveis do cadastro de Aluno
    Aluno alunoLista[CADASTRO_ALUNO_TAM];
    int qtdAlunos = 0;


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
                menuAlunos(alunoLista, qtdAlunos);
                qtdAlunos++;
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

int menuAlunos(Aluno alunoLista[], int qtdAlunos){

    int escolhaSubMenu, tipoCadastro = 0, sair = 0;

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
            cadastrarPessoa(alunoLista, qtdAlunos, tipoCadastro);
            break;

        case 2:
            system("clear");
            printf("Você entrou em atualizar alunos");
            //atualizarPessoa();
            break;

        case 3:
            system("clear");
            printf("Você entrou em exclurir alunos");
            //excluirPessoa();
            break;

        default:
            system("clear");
            printf("Opcao invalida");
            break;
        }
    }
}

void cadastrarPessoa(Aluno alunoLista[], int qtdAlunos, int tipoCadastro){

    //Tipo 0 - Aluno | 1 - Professor

    if(tipoCadastro == 0){
        printf("\ --- Cadastro de Aluno --- /\n\n");

        printf("Insira a matrícula: ");
        scanf("%d", &alunoLista[qtdAlunos].matricula);
        getchar();

        printf("Insira o nome: ");
        fflush(stdin);
        fgets(alunoLista[qtdAlunos].nome, 50, stdin);

        printf("Insira o sexo: (1: Mulher | 2: Homem) ");
        scanf("%d", &alunoLista[qtdAlunos].sexo);
        getchar();

        printf("Insira a data de nascimento: (Formato: DD/MM/AAAA) ");
        fflush(stdin);
        fgets(alunoLista[qtdAlunos].dataNascimento, 10, stdin);

        printf("Insira o cpf: (Formato: XXXXXXXXXXX) ");
        fflush(stdin);
        fgets(alunoLista[qtdAlunos].cpf, 11, stdin);

        system("clear");
    }
}




}
