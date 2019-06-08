#include <stdio.h>
#include <stdlib.h>
#define CADASTRO_PROFESSOR_TAM 2
#define CADASTRO_ALUNO_TAM 3
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
    int matriculaProfessor;
    int alunosNaDisciplina[ALUNOS_POR_DISCIPLINA];
}Disciplina;

int opcoesMenu();
int menuAlunos(Aluno alunoLista[], Professor professorLista[], int *qtdAlunosPTR, int *qtdProfessoresPTR);
int menuProfessores(Aluno alunoLista[], Professor professorLista[], int *qtdAlunosPTR, int *qtdProfessoresPTR);
int menuDisciplinas(Disciplina disciplinaLista[], Aluno alunoLista[], Professor professorLista[], int *qtdDisciplinasPTR, int *qtdAlunosPTR, int *qtdProfessoresPTR);
int switchPessoaDisciplina(int tipoItem);
void cadastrarPessoa(Aluno alunoLista[], Professor professorLista[], int *qtdAlunosPTR, int *qtdProfessoresPTR, int tipoCadastro);
void cadastrarDisciplina(Disciplina disciplinaLista[], Professor professorLista[], int *qtdProfessoresPTR, int *qtdDisciplinasPTR);
void exibirAlunos(Aluno alunoLista[], int *qtdAlunosPTR);
void exibirProfessor(Professor professorLista[], int *qtdProfessoresPTR);


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

    int *qtdAlunosPTR;
    int *qtdProfessoresPTR;
    int *qtdDisciplinasPTR;


    qtdAlunosPTR = &qtdAlunos;
    qtdProfessoresPTR = &qtdProfessores;
    qtdDisciplinasPTR = &qtdDisciplinas;


    while(!sair){

    printf("qtdALunos ---> %d\n\n", *qtdAlunosPTR);

    escolha = opcoesMenu();

        switch(escolha){

            case 0:
                system("clear");
                printf("Você saiu do sistema.");
                sair = 1;
                break;

            case 1:
                system("clear");
                menuAlunos(alunoLista, professorLista, qtdAlunosPTR, qtdProfessoresPTR);
                break;

            case 2:
                system("clear");
                menuProfessores(alunoLista, professorLista, qtdAlunosPTR, qtdProfessoresPTR);
                qtdProfessores++;
                break;

            case 3:
                system("clear");
                menuDisciplinas(disciplinaLista, alunoLista, professorLista, qtdDisciplinasPTR, qtdAlunosPTR, qtdProfessoresPTR);
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

int menuAlunos(Aluno alunoLista[], Professor professorLista[], int *qtdAlunosPTR, int *qtdProfessoresPTR){

    int escolhaSubMenu, tipoItem = 0, tipoCadastro = 0, sair = 0;

    while(!sair){

    printf("qtdALunos MenuAlunos---> %d\n\n", *qtdAlunosPTR);

    escolhaSubMenu = switchPessoaDisciplina(tipoItem);

        switch(escolhaSubMenu){
           case 0:
            system("clear");
            printf("Você saiu do sistema");
            sair = 1;
            break;

        case 1:
            system("clear");

            if(*qtdAlunosPTR == CADASTRO_ALUNO_TAM){
                printf("Acabaram as vagas para esse ano - Não é possível cadastrar nenhum aluno\n");
                break;
            } else {
                printf("Você entrou em cadastro de alunos");
                cadastrarPessoa(alunoLista, professorLista, qtdAlunosPTR, qtdProfessoresPTR, tipoCadastro);
                *qtdAlunosPTR += 1;
            }
            break;

        case 2:
            system("clear");
            printf("Você entrou em exibir -atualizar- alunos");
            exibirAlunos(alunoLista, qtdAlunosPTR);
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

int menuProfessores(Aluno alunoLista[], Professor professorLista[], int *qtdAlunosPTR, int *qtdProfessoresPTR){

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

            if(*qtdProfessoresPTR == CADASTRO_PROFESSOR_TAM){
                printf("Acabaram as vagas para professores neste ano - Não é possível cadastrar nenhum prof\n");
                break;
            } else {
                printf("Você entrou em cadastro de professores");
                cadastrarPessoa(alunoLista, professorLista, qtdAlunosPTR, qtdProfessoresPTR, tipoCadastro);
                *qtdProfessoresPTR += 1;
            }


            break;

        case 2:
            system("clear");
            printf("Você entrou em exibir professor");
            //atualizarPessoa();
            exibirProfessor(professorLista, qtdProfessoresPTR);
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

int menuDisciplinas(Disciplina disciplinaLista[], Aluno alunoLista[], Professor professorLista[], int *qtdDisciplinasPTR, int *qtdAlunosPTR, int *qtdProfessoresPTR){

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
            cadastrarDisciplina(disciplinaLista, professorLista, qtdProfessoresPTR, qtdDisciplinasPTR);
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

void cadastrarPessoa(Aluno alunoLista[], Professor professorLista[], int *qtdAlunosPTR, int *qtdProfessoresPTR, int tipoCadastro){

    //Tipo 0 - Aluno | 1 - Professor

    if(tipoCadastro == 0){

        if(*qtdAlunosPTR == 0){
            for(int i=0; i<CADASTRO_ALUNO_TAM; i++){
                alunoLista[i].matricula = -1;
            }
        }

        printf(" \ --- Cadastro de Aluno --- /\n\n");

        alunoLista[*qtdAlunosPTR].matricula = *qtdAlunosPTR + 1;
        getchar();

        printf("Insira o nome: ");
        fflush(stdin);
        fgets(alunoLista[*qtdAlunosPTR].nome, 50, stdin);

        printf("Insira o sexo: (1: Mulher | 2: Homem) ");
        scanf("%d", &alunoLista[*qtdAlunosPTR].sexo);
        getchar();

        printf("Insira a data de nascimento: (Formato: DD/MM/AAAA) ");
        fflush(stdin);
        fgets(alunoLista[*qtdAlunosPTR].dataNascimento, 12, stdin);

        printf("Insira o cpf: (Formato: XXXXXXXXXXX) ");
        fflush(stdin);
        fgets(alunoLista[*qtdAlunosPTR].cpf, 13, stdin);

        system("clear");

    } else {

        if(*qtdProfessoresPTR == 0){
            for(int i=0; i<CADASTRO_PROFESSOR_TAM; i++){
                professorLista[i].matricula = -1;
            }
        }

        printf(" \ --- Cadastro de Professor --- /\n\n");

        professorLista[*qtdProfessoresPTR].matricula = *qtdProfessoresPTR + 1;
        getchar();

        printf("Insira o nome do professor(a): ");
        fflush(stdin);
        fgets(professorLista[*qtdProfessoresPTR].nome, 50, stdin);

        printf("Insira o sexo: (1: Mulher | 2: Homem) ");
        scanf("%d", &professorLista[*qtdProfessoresPTR].sexo);
        getchar();

        printf("Insira a data de nascimento: (Formato: DD/MM/AAAA) ");
        fflush(stdin);
        fgets(professorLista[*qtdProfessoresPTR].dataNascimento, 12, stdin);

        printf("Insira o cpf: (Formato: XXXXXXXXXXX) ");
        fflush(stdin);
        fgets(professorLista[*qtdProfessoresPTR].cpf, 13, stdin);

        system("clear");

    }
}

void cadastrarDisciplina(Disciplina disciplinaLista[], Professor professorLista[], int *qtdProfessoresPTR, int *qtdDisciplinasPTR){

    int matriculaProfessor, matriculaStatus = 0;

        if(*qtdDisciplinasPTR == 0){
            for(int i=0; i<QUANTIDADE_DISCIPLINAS; i++){
                disciplinaLista[i].codigo = -1;
            }
        }

        printf(" \ --- Cadastro de Disciplina --- /\n\n");

        disciplinaLista[*qtdDisciplinasPTR].codigo = *qtdDisciplinasPTR + 1;
        getchar();

        printf("Insira o nome: ");
        fflush(stdin);
        fgets(disciplinaLista[*qtdDisciplinasPTR].nome, 50, stdin);

        printf("Insira o semestre ");
        scanf("%d", &disciplinaLista[*qtdDisciplinasPTR].semestre);
        getchar();

        printf("Insira a matrícula do professor: ");
        scanf("%d", &matriculaProfessor);
        getchar();

        for(int i=0; i<*qtdProfessoresPTR; i++){
            if(matriculaProfessor == professorLista[i].matricula){
                matriculaStatus = 1;
            }
        }

        if(matriculaStatus == 1){
            disciplinaLista[*qtdDisciplinasPTR].matriculaProfessor = matriculaProfessor;
            getchar();
        } else {
            printf("Professor nao cadastrado");
            return;
        }


        system("clear");

}

void exibirAlunos(Aluno alunoLista[], int *qtdAlunosPTR){

    printf("qtd alunos: %d\n\n", *qtdAlunosPTR);

    for(int i=0; i<CADASTRO_ALUNO_TAM; i++){
        printf("matricula: %d", alunoLista[i].matricula);
        printf("Nome: %s", alunoLista[i].nome);
        printf("Sexo: %d", alunoLista[i].sexo);
        printf("Data: $s", alunoLista[i].dataNascimento);
        printf("CPF: %s", alunoLista[i].cpf);
        printf("\n\n");
    }
}

void exibirProfessor(Professor professorLista[], int *qtdProfessoresPTR){

    printf("qtd alunos: %d\n\n", *qtdProfessoresPTR);

    for(int i=0; i<CADASTRO_PROFESSOR_TAM; i++){
        printf("matricula: %d", professorLista[i].matricula);
        printf("Nome: %s", professorLista[i].nome);
        printf("Sexo: %d", professorLista[i].sexo);
        printf("Data: $s", professorLista[i].dataNascimento);
        printf("CPF: %s", professorLista[i].cpf);
        printf("\n\n");
    }
}
