#include <stdio.h>
#include <stdlib.h>
#define CADASTRO_PROFESSOR_TAM 2
#define CADASTRO_ALUNO_TAM 5
#define QUANTIDADE_DISCIPLINAS 5
#define ALUNOS_POR_DISCIPLINA 3

/* Struct Aluno */
typedef struct alunoDados{
    int matricula;
    char nome[50];
    int sexo; //1 - Mulher | 2 - Homem
    char dataNascimento[12];
    char cpf[13];
}Aluno;

/* Struct Professor */
typedef struct professorDados{
    int matricula;
    char nome[50];
    int sexo; //1 - Mulher | 2 - Homem
    char dataNascimento[12];
    char cpf[13];
}Professor;

/* Struct Disciplina */
typedef struct disciplinaDados{
    char nome[50];
    int codigo;
    int semestre;
    int professor[50];
    int alunosNaDisciplina[ALUNOS_POR_DISCIPLINA];
}Disciplina;

int opcoesMenu();
int menuAlunos(Aluno alunoLista[], Professor professorLista[], int qtdAlunos, int qtdProfessores);
int menuProfessores(Aluno alunoLista[], Professor professorLista[], int qtdAlunos, int qtdProfessores);
int menuDisciplinas(Disciplina disciplinaLista[], Aluno alunoLista[], Professor professorLista[], int qtdDisciplinas, int qtdAlunos, int qtdProfessores);
int switchPessoaDisciplina(int tipoItem);
void cadastrarPessoa(Aluno alunoLista[], Professor professorLista[], int qtdAlunos, int qtdProfessores, int tipoCadastro);
void cadastrarDisciplina(Disciplina disciplinaLista[], Professor professorLista[], int qtdProfessores, int qtdDisciplinas);

int main()
{
    //Variáveis do menu
    int escolha, escolhaSubMenu, sair = 0;

    //Listas aluno, professor, disciplina
    Aluno alunoLista[CADASTRO_ALUNO_TAM];
    Professor professorLista[CADASTRO_PROFESSOR_TAM];
    Disciplina disciplinaLista[QUANTIDADE_DISCIPLINAS];

    //Variáveis de controle das listas
    int qtdAlunos = 0;
    int qtdProfessores = 0;
    int qtdDisciplinas = 0;


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
                menuAlunos(alunoLista, professorLista, qtdAlunos, qtdProfessores);
                qtdAlunos++;
                break;

            case 2:
                system("clear");
                menuProfessores(alunoLista, professorLista, qtdAlunos, qtdProfessores);
                qtdProfessores++;
                break;

            case 3:
                system("clear");
                menuDisciplinas(disciplinaLista, alunoLista, professorLista, qtdDisciplinas, qtdAlunos, qtdProfessores);
                printf("Voce entrou em 'Disciplinas'");
                break;

            case 4:
                system("clear");
                //menuRelatorios(alunoLista, professorLista, qtdAlunos, qtdProfessores);
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

int menuAlunos(Aluno alunoLista[], Professor professorLista[], int qtdAlunos, int qtdProfessores){

    int escolhaSubMenu, tipoItem = 0, tipoCadastro = 0, sair = 0;

    while(!sair){
    escolhaSubMenu = switchPessoaDisciplina(tipoItem);

        switch(escolhaSubMenu){
           case 0:
            system("clear");
            printf("Você saiu do sistema");
            sair = 1;
            break;

        case 1:
            system("clear");
            printf("Você entrou em cadastro de alunos");
            cadastrarPessoa(alunoLista, professorLista, qtdAlunos, qtdProfessores, tipoCadastro);
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

int menuProfessores(Aluno alunoLista[], Professor professorLista[], int qtdAlunos, int qtdProfessores){

    int escolhaSubMenu, tipoItem = 1, tipoCadastro = 1, sair = 0;

    while(!sair){
    escolhaSubMenu = switchPessoaDisciplina(tipoItem);

        switch(escolhaSubMenu){
           case 0:
            system("clear");
            printf("Você saiu do sistema");
            sair = 1;
            break;

        case 1:
            system("clear");
            cadastrarPessoa(alunoLista, professorLista, qtdAlunos, qtdProfessores, tipoCadastro);
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

int menuDisciplinas(Disciplina disciplinaLista[], Aluno alunoLista[], Professor professorLista[], int qtdDisciplinas, int qtdAlunos, int qtdProfessores){

    int escolhaSubMenu, tipoItem = 2, sair = 0;

    while(!sair){
    escolhaSubMenu = switchPessoaDisciplina(tipoItem);

        switch(escolhaSubMenu){
           case 0:
            system("clear");
            printf("Você saiu do sistema");
            sair = 1;
            break;

        case 1:
            system("clear");
            printf("Você entrou em cadastro de disciplina");
            cadastrarDisciplina(disciplinaLista, professorLista, qtdProfessores, qtdDisciplinas);
            break;

        case 2:
            system("clear");
            printf("Você entrou em atualizar disciplina");
            //atualizarPessoa();
            break;

        case 3:
            system("clear");
            printf("Você entrou em excluir disciplina");
            //excluirPessoa();
            break;

        default:
            system("clear");
            printf("Opcao invalida");
            break;
        }
    }
}

int switchPessoaDisciplina(int tipoItem){
    int escolhaItemMenu;

    if(tipoItem == 0){
        printf("\ ---- Alunos ---- /\n\n");

        printf("Escolha uma opçao:\n");
        printf("1 - Cadastrar Aluno\n");
        printf("2 - Atualizar Aluno\n");
        printf("3 - Excluir Aluno\n");
        printf("0 - Sair\n");

        scanf("%d", &escolhaItemMenu);

        return escolhaItemMenu;
    }
    else if(tipoItem == 1){
        printf("\ ---- Professores ---- /\n\n");

        printf("Escolha uma opçao:\n");
        printf("1 - Cadastrar Professor\n");
        printf("2 - Atualizar Professor\n");
        printf("3 - Excluir Professor\n");
        printf("0 - Sair\n");

        scanf("%d", &escolhaItemMenu);

        return escolhaItemMenu;
    }
    else if(tipoItem == 2){
        printf("\ ---- DISCIPLINAS ---- /\n\n");

        printf("Escolha uma opçao:\n");
        printf("1 - Cadastrar Disciplina\n");
        printf("2 - Incluir Aluno da disciplina\n");
        printf("3 - Excluir Aluno da disciplina\n");
        printf("0 - Sair\n");

        scanf("%d", &escolhaItemMenu);

        return escolhaItemMenu;
    }

    return 0;
}

void cadastrarPessoa(Aluno alunoLista[], Professor professorLista[], int qtdAlunos, int qtdProfessores, int tipoCadastro){

    //Tipo 0 - Aluno | 1 - Professor

    if(tipoCadastro == 0){

        if(qtdAlunos == 0){
            for(int i=0; i<CADASTRO_ALUNO_TAM; i++){
                alunoLista[i].matricula = -1;
            }
        }

        printf(" \ --- Cadastro de Aluno --- /\n\n");

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
        fgets(alunoLista[qtdAlunos].dataNascimento, 12, stdin);

        printf("Insira o cpf: (Formato: XXXXXXXXXXX) ");
        fflush(stdin);
        fgets(alunoLista[qtdAlunos].cpf, 13, stdin);

        system("clear");

        //INSERIR VALIDAÇÃO DOS DADOS!
    } else {

        if(qtdProfessores == 0){
            for(int i=0; i<CADASTRO_PROFESSOR_TAM; i++){
                professorLista[i].matricula = -1;
            }
        }

        printf(" \ --- Cadastro de Professor --- /\n\n");

        printf("Insira a matrícula: ");
        scanf("%d", &professorLista[qtdProfessores].matricula);
        getchar();

        printf("Insira o nome: ");
        fflush(stdin);
        fgets(professorLista[qtdProfessores].nome, 50, stdin);

        printf("Insira o sexo: (1: Mulher | 2: Homem) ");
        scanf("%d", &professorLista[qtdProfessores].sexo);
        getchar();

        printf("Insira a data de nascimento: (Formato: DD/MM/AAAA) ");
        fflush(stdin);
        fgets(professorLista[qtdProfessores].dataNascimento, 12, stdin);

        printf("Insira o cpf: (Formato: XXXXXXXXXXX) ");
        fflush(stdin);
        fgets(professorLista[qtdProfessores].cpf, 13, stdin);

        system("clear");

    }
}

void cadastrarDisciplina(Disciplina disciplinaLista[], Professor professorLista[], int qtdProfessores, int qtdDisciplinas){

        if(qtdDisciplinas == 0){
            for(int i=0; i<QUANTIDADE_DISCIPLINAS; i++){
                disciplinaLista[i].codigo = -1;
            }
        }

        printf(" \ --- Cadastro de Disciplina --- /\n\n");


        printf("Insira o nome: ");
        fflush(stdin);
        fgets(disciplinaLista[qtdDisciplinas].nome, 50, stdin);

        printf("Insira o semestre ");
        scanf("%d", &disciplinaLista[qtdDisciplinas].semestre);
        getchar();

        /*printf("Insira a matrícula do professor: ");
        fflush(stdin);
        fgets(disciplinaLista[qtdDisciplinas].professor, 12, stdin);*/


        system("clear");

}
