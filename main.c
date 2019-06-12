#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    int codigo;
    char nome[50];
    int semestre;
    int matriculaProfessor;
    int alunosNaDisciplina[ALUNOS_POR_DISCIPLINA];
}Disciplina;

int opcoesMenu();
int menuAlunos(Aluno alunoLista[], Professor professorLista[], int *qtdAlunosPTR, int *qtdProfessoresPTR);
int menuProfessores(Aluno alunoLista[], Professor professorLista[], int *qtdAlunosPTR, int *qtdProfessoresPTR);
int menuDisciplinas(Disciplina disciplinaLista[], Aluno alunoLista[], Professor professorLista[], int *qtdDisciplinasPTR, int *qtdAlunosPTR, int *qtdProfessoresPTR, int *qtdAlunoDisciplinaPTR);
int menuRelatorios(Disciplina disciplinaLista[], Aluno alunoLista[], Professor professorLista[], int *qtdDisciplinasPTR, int *qtdAlunosPTR, int *qtdProfessoresPTR, int *qtdAlunoDisciplinaPTR);
int switchPessoaDisciplina(int tipoItem);

void cadastrarPessoa(Aluno alunoLista[], Professor professorLista[], int *qtdAlunosPTR, int *qtdProfessoresPTR, int tipoCadastro);
void cadastrarDisciplina(Disciplina disciplinaLista[], Professor professorLista[], int *qtdProfessoresPTR, int *qtdDisciplinasPTR);
void atualizarPessoa(Aluno alunoLista[], Professor professorLista[], int *qtdAlunosPTR, int *qtdProfessoresPTR, int tipoCadastro);
void atualizarDisciplina(Disciplina disciplinaLista[], Professor professorLista[], int *qtdProfessoresPTR, int *qtdDisciplinasPTR);
void excluirPessoa(Aluno alunoLista[], Professor professorLista[], int *qtdAlunosPTR, int *qtdProfessoresPTR, int tipoCadastro);
void excluirDisciplina(Disciplina disciplinaLista[], int *qtdDisciplinasPTR);
void incluirAlunoNaDisciplina(Disciplina disciplinaLista[], Aluno alunoLista[], int *qtdDisciplinasPTR, int *qtdAlunosPTR, int *qtdAlunoDisciplinaPTR);
void excluirAlunoDaDisciplina(Disciplina disciplinaLista[], Aluno alunoLista[], int *qtdDisciplinasPTR, int *qtdAlunosPTR, int *qtdAlunoDisciplinaPTR);
void excluirAlunoDaDisciplina(Disciplina disciplinaLista[], Aluno alunoLista[], int *qtdDisciplinasPTR, int *qtdAlunosPTR, int *qtdAlunoDisciplinaPTR);

void exibirAlunos(Aluno alunoLista[], Professor professorLista[], int *qtdAlunosPTR, int *qtdProfessoresPTR);
void exibirProfessor(Aluno alunoLista[], Professor professorLista[], int *qtdAlunosPTR, int *qtdProfessoresPTR);
void exibirDisciplina(Disciplina disciplinaLista[], Professor professorLista[], int *qtdDisciplinasPTR, int *qtdAlunoDisciplinaPTR, int *qtdProfessoresPTR);
void exibirDisciplinaEspecifica(Disciplina disciplinaLista[], Aluno alunoLista[], Professor professorLista[], int *qtdDisciplinasPTR, int *qtdAlunoDisciplinaPTR, int *qtdAlunosPTR, int *qtdProfessoresPTR);
void exibirPorSexo(Aluno alunoLista[], Professor professorLista[], int *qtdAlunosPTR, int *qtdProfessoresPTR, int tipoCadastro);

void exibirPessoaPorOrdemAlfabetica(Aluno alunoLista[], Professor professorLista[], int *qtdAlunosPTR, int *qtdProfessoresPTR, int tipoCadastro);

void textoListagemAlunosOuProfessores(Aluno alunoLista[], Professor professorLista[], int i, int tipoCadastro);

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
    int qtdAlunosDisciplina = 0;

    int *qtdAlunosPTR;
    int *qtdProfessoresPTR;
    int *qtdDisciplinasPTR;
    int *qtdAlunoDisciplinaPTR;


    qtdAlunosPTR = &qtdAlunos;
    qtdProfessoresPTR = &qtdProfessores;
    qtdDisciplinasPTR = &qtdDisciplinas;
    qtdAlunoDisciplinaPTR = &qtdAlunosDisciplina;


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
                menuAlunos(alunoLista, professorLista, qtdAlunosPTR, qtdProfessoresPTR);
                break;

            case 2:
                system("clear");
                menuProfessores(alunoLista, professorLista, qtdAlunosPTR, qtdProfessoresPTR);
                break;

            case 3:
                system("clear");
                menuDisciplinas(disciplinaLista, alunoLista, professorLista, qtdDisciplinasPTR, qtdAlunosPTR, qtdProfessoresPTR, qtdAlunoDisciplinaPTR);
                break;

            case 4:
                system("clear");
                menuRelatorios(disciplinaLista, alunoLista, professorLista, qtdDisciplinasPTR, qtdAlunosPTR, qtdProfessoresPTR, qtdAlunoDisciplinaPTR);
                break;

            default:
                system("clear");
                printf("Opcao invalida!");
        }

    }

    return 0;
}

/* MENUS */

int opcoesMenu(){

    int escolha;

    printf("| ---- Escola do Tio Luiz ---- |\n\n");

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

    escolhaSubMenu = switchPessoaDisciplina(tipoItem);
        switch(escolhaSubMenu){
           case 0:
            system("clear");
            sair = 1;
            break;

        case 1:
            system("clear");

            if(*qtdAlunosPTR == CADASTRO_ALUNO_TAM){
                printf("Acabaram as vagas para esse ano - Não é possível cadastrar nenhum aluno\n");
                break;
            } else {
                cadastrarPessoa(alunoLista, professorLista, qtdAlunosPTR, qtdProfessoresPTR, tipoCadastro);
            }
            break;

        case 2:
            system("clear");
            atualizarPessoa(alunoLista, professorLista, qtdAlunosPTR, qtdProfessoresPTR, tipoCadastro);
            break;

        case 3:
            system("clear");
            excluirPessoa(alunoLista, professorLista, qtdAlunosPTR, qtdProfessoresPTR,  tipoCadastro);
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
            sair = 1;
            break;

        case 1:
            system("clear");

            if(*qtdProfessoresPTR == CADASTRO_PROFESSOR_TAM){
                printf("Acabaram as vagas para professores neste ano - Não é possível cadastrar nenhum prof\n");
                break;
            } else {
                cadastrarPessoa(alunoLista, professorLista, qtdAlunosPTR, qtdProfessoresPTR, tipoCadastro);
            }
            break;

        case 2:
            system("clear");
            atualizarPessoa(alunoLista, professorLista, qtdAlunosPTR, qtdProfessoresPTR, tipoCadastro);
            break;

        case 3:
            system("clear");
            excluirPessoa(alunoLista, professorLista, qtdAlunosPTR, qtdProfessoresPTR,  tipoCadastro);
            break;

        default:
            system("clear");
            printf("Opcao invalida");
            break;
        }
    }
}

int menuDisciplinas(Disciplina disciplinaLista[], Aluno alunoLista[], Professor professorLista[], int *qtdDisciplinasPTR, int *qtdAlunosPTR, int *qtdProfessoresPTR, int *qtdAlunoDisciplinaPTR){

    int escolhaSubMenu, tipoItem = 2, sair = 0;

    while(!sair){
    escolhaSubMenu = switchPessoaDisciplina(tipoItem);

        switch(escolhaSubMenu){
           case 0:
            system("clear");
            sair = 1;
            break;

        case 1:
            system("clear");

            if(*qtdDisciplinasPTR == QUANTIDADE_DISCIPLINAS){
                printf("Todas as disciplinas para esse semestre ja foram cadastradas.\n");
                break;
            } else {
                cadastrarDisciplina(disciplinaLista, professorLista, qtdProfessoresPTR, qtdDisciplinasPTR);
            }

            break;

        case 2:
            system("clear");
            atualizarDisciplina(disciplinaLista, professorLista, qtdProfessoresPTR, qtdDisciplinasPTR);
            break;

        case 3:
            system("clear");
            excluirDisciplina(disciplinaLista, qtdDisciplinasPTR);
            break;

        case 4:
            system("clear");
            incluirAlunoNaDisciplina(disciplinaLista, alunoLista, qtdDisciplinasPTR, qtdAlunosPTR, qtdAlunoDisciplinaPTR);
            break;

        case 5:
            system("clear");
            excluirAlunoDaDisciplina(disciplinaLista, alunoLista, qtdDisciplinasPTR, qtdAlunosPTR, qtdAlunoDisciplinaPTR);
            break;

        default:
            system("clear");
            printf("Opcao invalida");
            break;
        }
    }
}

int menuRelatorios(Disciplina disciplinaLista[], Aluno alunoLista[], Professor professorLista[], int *qtdDisciplinasPTR, int *qtdAlunosPTR, int *qtdProfessoresPTR, int *qtdAlunoDisciplinaPTR){

    int escolhaSubMenu, tipoItem = 3, sair = 0;

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
            exibirAlunos(alunoLista, professorLista, qtdAlunosPTR, qtdProfessoresPTR);
            break;

        case 2:
            system("clear");
            exibirProfessor(alunoLista, professorLista, qtdAlunosPTR, qtdProfessoresPTR);
            break;

        case 3:
            system("clear");
            //Todas as disciplinas
            //exibirDisciplina(disciplinaLista, qtdDisciplinasPTR, qtdAlunoDisciplinaPTR);
            exibirDisciplina(disciplinaLista, professorLista, qtdDisciplinasPTR, qtdAlunoDisciplinaPTR, qtdProfessoresPTR);
            break;

        case 4:
            system("clear");
            //Disciplina com aluno
            exibirDisciplinaEspecifica(disciplinaLista, alunoLista, professorLista, qtdDisciplinasPTR, qtdAlunoDisciplinaPTR, qtdAlunosPTR, qtdProfessoresPTR);
            //exibirDisciplinaEspecifica(disciplinaLista, alunoLista, qtdDisciplinasPTR, qtdAlunoDisciplinaPTR, qtdAlunosPTR);
            break;

        case 5:
            system("clear");
            //Exibir aluno
            exibirPorSexo(alunoLista, professorLista, qtdAlunosPTR, qtdProfessoresPTR, 0);
            break;

        case 6:
            system("clear");
            exibirPessoaPorOrdemAlfabetica(alunoLista, professorLista, qtdAlunosPTR, qtdProfessoresPTR, 0);
            break;

        case 7:
            system("clear");
            break;

        case 8:
            system("clear");
            //Exibir professor
            exibirPorSexo(alunoLista, professorLista, qtdAlunosPTR, qtdProfessoresPTR, 1);
            break;

        case 9:
            system("clear");
            exibirPessoaPorOrdemAlfabetica(alunoLista, professorLista, qtdAlunosPTR, qtdProfessoresPTR, 1);
            break;

        case 10:
            system("clear");
            break;

        case 11:
            system("clear");
            break;

        case 12:
            system("clear");
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
        printf("| ---- Alunos ---- |\n\n");

        printf("Escolha uma opçao:\n");
        printf("1 - Cadastrar Aluno\n");
        printf("2 - Atualizar Aluno\n");
        printf("3 - Excluir Aluno\n");
        printf("0 - Sair\n");

        scanf("%d", &escolhaItemMenu);
        return escolhaItemMenu;
    }
    else if(tipoItem == 1){
        printf("| ---- Professores ---- |\n\n");

        printf("Escolha uma opçao:\n");
        printf("1 - Cadastrar Professor\n");
        printf("2 - Atualizar Professor\n");
        printf("3 - Excluir Professor\n");
        printf("0 - Sair\n");

        scanf("%d", &escolhaItemMenu);
        return escolhaItemMenu;
    }
    else if(tipoItem == 2){
        printf("| ---- DISCIPLINAS ---- |\n\n");

        printf("Escolha uma opçao:\n");
        printf("1 - Cadastrar Disciplina\n");
        printf("2 - Atualizar disciplina\n");
        printf("3 - Excluir disciplina\n");
        printf("4 - Incluir Aluno da disciplina\n");
        printf("5 - Excluir Aluno da disciplina\n");
        printf("0 - Sair\n");

        scanf("%d", &escolhaItemMenu);
        return escolhaItemMenu;

    }
    else if(tipoItem == 3){
        printf("| ---- RELATÓRIOS ---- |\n\n");
        printf("1 - Listar Alunos\n");
        printf("2 - Listar Professores\n");
        printf("3 - Listar Disciplinas\n");
        printf("4 - Listar Disciplinas + Alunos Cadastrados\n");
        printf("5 - Listar Alunos por Sexo\n");
        printf("6 - Listar Alunos Ordenados por Nome\n");
        printf("7 - Listar Alunos Ordenados por Data de Nascimento\n");
        printf("8 - Listar Professores por Sexo\n");
        printf("9 - Listar Professores Ordenados por Nome\n");
        printf("10 - Listar Professores Ordenados por Data de Nascimento\n");
        printf("11 - Listar Aniversariantes do Mes\n");
        printf("12 - Buscar Pessoa (Professor/Aluno)\n");

        scanf("%d", &escolhaItemMenu);
        return escolhaItemMenu;
    }

    return 0;
}

/* CADASTRAR, ATUALIZAR, EXCLUIR */

void cadastrarPessoa(Aluno alunoLista[], Professor professorLista[], int *qtdAlunosPTR, int *qtdProfessoresPTR, int tipoCadastro){

    char nome[50];
    int sexo, tamanhoCpf, statusCadastro = 0;
    char dataNascimento[12];
    char cpf[13];

    //Tipo 0 - Aluno | 1 - Professor

    if(tipoCadastro == 0){

        if(*qtdAlunosPTR == 0){
            for(int i=0; i<CADASTRO_ALUNO_TAM; i++){
                alunoLista[i].matricula = -1;
            }
        }

        printf(" | --- Cadastro de Aluno --- |\n\n");

        alunoLista[*qtdAlunosPTR].matricula = *qtdAlunosPTR + 1;
        getchar();

        printf("Insira o nome: ");
        fflush(stdin);
        fgets(nome, 50, stdin);

        printf("Insira o sexo: (1: Mulher | 2: Homem) ");
        scanf("%d", &sexo);
        getchar();

        if(sexo == 0 || sexo == 1){
            statusCadastro = 1;
        } else {
            printf("-> Sexo invalido <-\n");
            return;
        }

        printf("Insira a data de nascimento: (Formato: DD/MM/AAAA) ");
        fflush(stdin);
        fgets(dataNascimento, 12, stdin);

        printf("Insira o cpf: (Formato: XXXXXXXXXXX) ");
        fflush(stdin);
        fgets(cpf, 13, stdin);

        tamanhoCpf = strlen(cpf);

        if(tamanhoCpf == 12){
            statusCadastro = 1;
        } else {
            printf("-> CPF invalido <-\n");
            return;
        }

        if(statusCadastro == 1){
            strcpy(alunoLista[*qtdAlunosPTR].nome, nome);
            alunoLista[*qtdAlunosPTR].sexo = sexo;
            strcpy(alunoLista[*qtdAlunosPTR].dataNascimento, dataNascimento);
            strcpy(alunoLista[*qtdAlunosPTR].cpf, cpf);
            *qtdAlunosPTR += 1;
        }

        system("clear");

    } else {

        if(*qtdProfessoresPTR == 0){
            for(int i=0; i<CADASTRO_PROFESSOR_TAM; i++){
                professorLista[i].matricula = -1;
            }
        }

        printf(" | --- Cadastro de Professor --- |\n\n");

        professorLista[*qtdProfessoresPTR].matricula = *qtdProfessoresPTR + 1;
        getchar();

        printf("Insira o nome do professor(a): ");
        fflush(stdin);
        fgets(nome, 50, stdin);

        printf("Insira o sexo: (1: Mulher | 2: Homem) ");
        scanf("%d", &sexo);
        getchar();

        if(sexo == 0 || sexo == 1){
            statusCadastro = 1;
        } else {
            printf("-> Sexo invalido <-\n");
            return;
        }

        printf("Insira a data de nascimento: (Formato: DD/MM/AAAA) ");
        fflush(stdin);
        fgets(dataNascimento, 12, stdin);

        printf("Insira o cpf: (Formato: XXXXXXXXXXX) ");
        fflush(stdin);
        fgets(cpf, 13, stdin);

        tamanhoCpf = strlen(cpf);

        if(tamanhoCpf == 12){
            statusCadastro = 1;
        } else {
            printf("-> CPF invalido <-\n");
            return;
        }

        if(statusCadastro == 1){
            strcpy(professorLista[*qtdProfessoresPTR].nome, nome);
            professorLista[*qtdProfessoresPTR].sexo = sexo;
            strcpy(professorLista[*qtdProfessoresPTR].dataNascimento, dataNascimento);
            strcpy(professorLista[*qtdProfessoresPTR].cpf, cpf);
            *qtdProfessoresPTR += 1;
        }

        system("clear");

    }
}

void cadastrarDisciplina(Disciplina disciplinaLista[], Professor professorLista[], int *qtdProfessoresPTR, int *qtdDisciplinasPTR){

    int semestre, matriculaProfessor, matriculaStatus = 0;
    int statusCadastro = 0;
    char nomeDisciplina[50];


        if(*qtdDisciplinasPTR == 0){
            for(int i=0; i<QUANTIDADE_DISCIPLINAS; i++){
                disciplinaLista[i].codigo = -1;
            }
        }

        printf(" | --- Cadastro de Disciplina --- |\n\n");

        disciplinaLista[*qtdDisciplinasPTR].codigo = *qtdDisciplinasPTR + 1;
        getchar();

        printf("Insira o nome: ");
        fflush(stdin);
        fgets(nomeDisciplina, 50, stdin);

        printf("Insira o semestre: (1, 2, 3 ou 4) ");
        scanf("%d", &semestre);
        getchar();

        if(semestre >= 1 && semestre <= 4){
            statusCadastro = 1;
        } else {
            printf("-> Semestre invalido <-\n");
            return;
        }

        printf("Insira a matrícula do professor: ");
        scanf("%d", &matriculaProfessor);
        getchar();

        //Verifica se o professor está cadastrado no sistema
        for(int i=0; i<*qtdProfessoresPTR; i++){
            if(matriculaProfessor == professorLista[i].matricula){
                statusCadastro = 1;
                matriculaStatus = 1;
            }
        }

        if(matriculaStatus == 0){
            printf("-> Professor nao cadastrado <-\n");
            return;
        }

        if(statusCadastro == 1){
            strcpy(disciplinaLista[*qtdDisciplinasPTR].nome, nomeDisciplina);
            disciplinaLista[*qtdDisciplinasPTR].semestre = semestre;
            disciplinaLista[*qtdDisciplinasPTR].matriculaProfessor = matriculaProfessor;
            *qtdDisciplinasPTR += 1;
        }


        system("clear");

}

void atualizarPessoa(Aluno alunoLista[], Professor professorLista[], int *qtdAlunosPTR, int *qtdProfessoresPTR, int tipoCadastro){

    int matricula, statusMatricula = 0;

    //Tipo 0 - Aluno | 1 - Professor

    if(tipoCadastro == 0){
        printf(" | --- Atualizar Aluno --- |\n\n");

        printf("Lista de alunos:\n");
        for(int i=0; i<*qtdAlunosPTR; i++){
            printf("Nome: %s", alunoLista[i].nome);
            printf("Matricula: %d\n\n", alunoLista[i].matricula);
        }

        printf("Insira a matricula do aluno a ser atualizado: ");
        scanf("%d", &matricula);
        getchar();

        for(int i=0; i<*qtdAlunosPTR; i++){
            if(matricula == alunoLista[i].matricula){
                statusMatricula = 1;

                printf("Insira o nome: ");
                fflush(stdin);
                fgets(alunoLista[i].nome, 50, stdin);

                printf("Insira o sexo: (1: Mulher | 2: Homem) ");
                scanf("%d", &alunoLista[i].sexo);
                getchar();

                printf("Insira a data de nascimento: (Formato: DD/MM/AAAA) ");
                fflush(stdin);
                fgets(alunoLista[i].dataNascimento, 12, stdin);

                printf("Insira o cpf: (Formato: XXXXXXXXXXX) ");
                fflush(stdin);
                fgets(alunoLista[i].cpf, 13, stdin);
            }
        }

        if(statusMatricula == 0){
            printf("-> Aluno nao encontrado <-\n");
            return;
        }
    } else {
        printf(" | --- Atualizar Professor --- |\n\n");

        printf("Lista de professores:\n");
        for(int i=0; i<*qtdProfessoresPTR; i++){
            printf("Nome: %s", professorLista[i].nome);
            printf("Matricula: %d\n\n", professorLista[i].matricula);
        }

        printf("Insira a matricula do professor a ser atualizado: ");
        scanf("%d", &matricula);
        getchar();

        for(int i=0; i<*qtdProfessoresPTR; i++){
            if(matricula == professorLista[i].matricula){
                statusMatricula = 1;

                printf("Insira o nome: ");
                fflush(stdin);
                fgets(professorLista[i].nome, 50, stdin);

                printf("Insira o sexo: (1: Mulher | 2: Homem) ");
                scanf("%d", &professorLista[i].sexo);
                getchar();

                printf("Insira a data de nascimento: (Formato: DD/MM/AAAA) ");
                fflush(stdin);
                fgets(professorLista[i].dataNascimento, 12, stdin);

                printf("Insira o cpf: (Formato: XXXXXXXXXXX) ");
                fflush(stdin);
                fgets(professorLista[i].cpf, 13, stdin);
            }
        }

        if(statusMatricula == 0){
            printf("-> Professor nao encontrado <-\n");
            return;
        }

    }
}

void atualizarDisciplina(Disciplina disciplinaLista[], Professor professorLista[], int *qtdProfessoresPTR, int *qtdDisciplinasPTR){

    int codigoDisciplina, matriculaProfessor, matriculaProfessorStatus = 0, statusCodigoDisciplina = 0;

        printf(" | --- Atualizar Disciplina --- |\n\n");

        printf("Lista de disciplinas:\n");
        for(int i=0; i<*qtdDisciplinasPTR; i++){
            printf("Disciplina: %s\n", disciplinaLista[i].nome);
            printf("Codigo: %d\n\n", disciplinaLista[i].codigo);
        }

        printf("Insira a disciplina a ser atualizada: ");
        scanf("%d", &codigoDisciplina);
        getchar();

        for(int i=0; i<*qtdDisciplinasPTR; i++){
            if(codigoDisciplina == disciplinaLista[i].codigo){
                statusCodigoDisciplina = 1;

                printf("Insira o nome: ");
                fflush(stdin);
                fgets(disciplinaLista[i].nome, 50, stdin);

                printf("Insira o semestre ");
                scanf("%d", &disciplinaLista[i].semestre);
                getchar();

                printf("Insira a matrícula do professor: ");
                scanf("%d", &matriculaProfessor);
                getchar();

                for(int j=0; j<*qtdProfessoresPTR; j++){
                    if(matriculaProfessor == professorLista[j].matricula){
                        disciplinaLista[j].matriculaProfessor = matriculaProfessor;
                        matriculaProfessorStatus = 1;
                    }
                }

                if(matriculaProfessorStatus == 0){
                    printf("-> Professor nao cadastrado <-\n");
                    return;
                }
            }
        }

        if(statusCodigoDisciplina == 0){
            printf("-> Disciplina nao encontrada <-\n");
            return;
        }
}

void excluirPessoa(Aluno alunoLista[], Professor professorLista[], int *qtdAlunosPTR, int *qtdProfessoresPTR, int tipoCadastro){

    int matriculaPessoa, statusMatriculaPessoa = 0;

    if(tipoCadastro == 0){
        printf(" | --- Excluir Aluno --- |\n\n");

        printf("Lista de alunos:\n");
        for(int i=0; i<*qtdAlunosPTR; i++){
            printf("Nome: %s\n", alunoLista[i].nome);
            printf("Matricula: %d\n\n", alunoLista[i].matricula);
        }

        printf("Insira a matricula do aluno a ser excluido: ");
        scanf("%d", &matriculaPessoa);
        getchar();

        for(int i=0; i<*qtdAlunosPTR; i++){
            if(matriculaPessoa == alunoLista[i].matricula){
                //Zera a matricula do aluno
                alunoLista[i].matricula = -1;
                statusMatriculaPessoa = 1;
            }
        }

        if(statusMatriculaPessoa == 1){
            //Coloca aluno excluido para o final da lista
            for(int i=matriculaPessoa - 1; i<*qtdAlunosPTR - 1; i++){
                alunoLista[i] = alunoLista[i + 1];
            }
            *qtdAlunosPTR -= 1;
        } else {
            printf("-> Aluno nao encontrado <-\n");
            return;
        }
    }
    else {
        printf(" | --- Excluir Professor --- |\n\n");

        printf("Lista de professores:\n");
        for(int i=0; i<*qtdProfessoresPTR; i++){
            printf("Nome: %s\n", professorLista[i].nome);
            printf("Matricula: %d", professorLista[i].matricula);
            printf("\n\n");
        }

        printf("Insira a matricula do professor a ser excluido: ");
        scanf("%d", &matriculaPessoa);
        getchar();

        for(int i=0; i<*qtdProfessoresPTR; i++){
            if(matriculaPessoa == professorLista[i].matricula){
                //Limpa a matricula do professor
                professorLista[i].matricula = -1;
                statusMatriculaPessoa = 1;
            }
        }

        if(statusMatriculaPessoa == 1){
            //Coloca professor excluido para o final da lista
            for(int i=matriculaPessoa - 1; i<*qtdProfessoresPTR - 1; i++){
                professorLista[i] = professorLista[i + 1];
            }
            *qtdProfessoresPTR -= 1;
        } else {
            printf("-> Professor nao encontrado <-\n");
            return;
        }
    }
}

void excluirDisciplina(Disciplina disciplinaLista[], int *qtdDisciplinasPTR){

    int codigoDisciplina, statusCodigoDisciplina = 0;

    printf(" | --- Excluir Disciplina --- |\n\n");

    printf("Lista de disciplinas:\n");
    for(int i=0; i<*qtdDisciplinasPTR; i++){
        printf("Disciplina: %s", disciplinaLista[i].nome);
        printf("Codigo: %d", disciplinaLista[i].codigo);
        printf("\n\n");
    }

    printf("Insira o codigo da disciplina a ser excluida: ");
    scanf("%d", &codigoDisciplina);
    getchar();

    for(int i=0; i<*qtdDisciplinasPTR; i++){
        if(codigoDisciplina == disciplinaLista[i].codigo){
            //Limpa o codigo da disciplina
            disciplinaLista[i].codigo = -1;
            statusCodigoDisciplina = 1;
        }
    }

    if(statusCodigoDisciplina == 1){
        //Coloca a matricula excluida para o final da lista
        for(int i=codigoDisciplina-1; i<*qtdDisciplinasPTR - 1; i++){
            disciplinaLista[i] = disciplinaLista[i + 1];
        }
        *qtdDisciplinasPTR -= 1;

    } else {
        printf("-> Disciplina nao encontrada <-\n");
        return;
    }

}

void incluirAlunoNaDisciplina(Disciplina disciplinaLista[], Aluno alunoLista[], int *qtdDisciplinasPTR, int *qtdAlunosPTR, int *qtdAlunoDisciplinaPTR){

    int codigoDisciplina, matriculaAluno, statusCodigoDisciplina = 0, statusMatriculaAluno = 0;

    printf(" | --- Incluir Aluno da Disciplina --- |\n\n");

    printf("Lista de disciplinas:\n");
    for(int i=0; i<*qtdDisciplinasPTR; i++){
        printf("Disciplina: %s", disciplinaLista[i].nome);
        printf("Codigo: %d\n\n", disciplinaLista[i].codigo);
    }

    printf("Insira o codigo da disciplina: ");
    scanf("%d", &codigoDisciplina);

    for(int i=0; i<*qtdDisciplinasPTR; i++){
        if(codigoDisciplina == disciplinaLista[i].codigo){
            statusCodigoDisciplina = 1;
            system("clear");

            printf("Lista de alunos:\n");
            for(int i=0; i<*qtdAlunosPTR; i++){
                printf("Nome: %s", alunoLista[i].nome);
                printf("Matricula: %d", alunoLista[i].matricula);
                printf("\n\n");
            }

            printf("Insira a matricula do aluno: ");
            scanf("%d", &matriculaAluno);


            for(int k=0; k<*qtdAlunoDisciplinaPTR; k++){
                if(disciplinaLista[i].alunosNaDisciplina[k] == matriculaAluno){
                    statusMatriculaAluno = 2;
                }
            }

            if(statusMatriculaAluno == 0){
                for(int j=0; j<*qtdAlunosPTR; j++){
                    if(matriculaAluno == alunoLista[j].matricula){
                        statusMatriculaAluno = 1;
                        disciplinaLista[i].alunosNaDisciplina[*qtdAlunoDisciplinaPTR] = matriculaAluno;
                        *qtdAlunoDisciplinaPTR += 1;
                    }
                }
            }

        }
    }

    if(statusCodigoDisciplina == 0){
        printf("-> Disciplina nao encontrada <-\n");
        return;
    }

    if(statusMatriculaAluno == 0){
        printf("-> Aluno nao encontrado <-\n");
        return;
    } else if(statusMatriculaAluno == 2){
        printf("-> Aluno ja cadastrado <-\n");
        return;
    }
}

void excluirAlunoDaDisciplina(Disciplina disciplinaLista[], Aluno alunoLista[], int *qtdDisciplinasPTR, int *qtdAlunosPTR, int *qtdAlunoDisciplinaPTR){

    int codigoDisciplina, matriculaAluno, statusCodigoDisciplina = 0, statusMatriculaAluno = 0;

    printf(" | --- Excluir Aluno da Disciplina --- |\n\n");

    printf("Lista de disciplinas:\n");
    for(int i=0; i<*qtdDisciplinasPTR; i++){
        printf("Disciplina: %s", disciplinaLista[i].nome);
        printf("Codigo: %d\n\n", disciplinaLista[i].codigo);
    }

    printf("Insira o codigo da disciplina: ");
    scanf("%d", &codigoDisciplina);

    for(int i=0; i<*qtdDisciplinasPTR; i++){
        if(codigoDisciplina == disciplinaLista[i].codigo){
            statusCodigoDisciplina = 1;
            system("clear");

            printf("Lista de alunos:\n");
            for(int i=0; i<*qtdDisciplinasPTR; i++){
                printf("Nome: %s", alunoLista[i].nome);
                printf("Matricula: %d", alunoLista[i].matricula);
                printf("\n\n");
            }

            printf("Insira a matricula do aluno: ");
            scanf("%d", &matriculaAluno);

            if(statusMatriculaAluno == 0){
                for(int j=0; j<*qtdAlunosPTR; j++){
                    if(matriculaAluno == alunoLista[j].matricula){
                        statusMatriculaAluno = 1;

                        for(int k=matriculaAluno-1; k<*qtdAlunoDisciplinaPTR - 1; k++){
                            disciplinaLista[j].alunosNaDisciplina[k] = disciplinaLista[j].alunosNaDisciplina[k + 1];
                        }

                        *qtdAlunoDisciplinaPTR -= 1;
                    }
                }
            }
        }
    }

    if(statusCodigoDisciplina == 0){
        printf("-> Disciplina nao encontrada <-\n");
        return;
    }

    if(statusMatriculaAluno == 0){
        printf("-> Aluno nao encontrado <-\n");
        return;
    }

}

/* RELATÓRIOS */

void exibirAlunos(Aluno alunoLista[], Professor professorLista[], int *qtdAlunosPTR, int *qtdProfessoresPTR){

    int tipoCadastro = 0, statusAlunoCadastrado;

    printf(" | --- ALUNOS CADASTRADOS --- |\n\n");

    if(*qtdAlunosPTR == 0){
        printf("-> Nenhum aluno cadastrado <-\n");
    } else {
        for(int i=0; i<*qtdAlunosPTR; i++){
            textoListagemAlunosOuProfessores(alunoLista, professorLista, i, tipoCadastro);
        }
    }
}

void exibirProfessor(Aluno alunoLista[], Professor professorLista[], int *qtdAlunosPTR, int *qtdProfessoresPTR){

    int tipoCadastro = 1;

    printf(" | --- PROFESSORES CADASTRADOS --- |\n\n");

    if(*qtdProfessoresPTR == 0){
        printf("-> Nenhum professor cadastrado <-\n");
    } else {
        for(int i=0; i<*qtdProfessoresPTR; i++){
            textoListagemAlunosOuProfessores(alunoLista, professorLista, i, tipoCadastro);
        }
    }
}

void exibirDisciplina(Disciplina disciplinaLista[], Professor professorLista[], int *qtdDisciplinasPTR, int *qtdAlunoDisciplinaPTR, int *qtdProfessoresPTR){

    printf(" | --- DISCIPLINAS CADASTRADAS --- |\n\n");

    if(*qtdDisciplinasPTR == 0){
        printf("-> Nenhuma disciplina cadastrada <-\n");
    } else {
        for(int i=0; i<*qtdDisciplinasPTR; i++){
            printf("Disciplina: %s", disciplinaLista[i].nome);
            printf("Codigo: %d\n", disciplinaLista[i].codigo);
            printf("Semestre: %d\n", disciplinaLista[i].semestre);

            for(int j=0; j<*qtdProfessoresPTR; j++){
                if(disciplinaLista[i].matriculaProfessor == professorLista[j].matricula){
                    printf("Professor: %s", professorLista[j].nome);
                }
            }
            printf("\n\n");
        }
    }
}

void exibirDisciplinaEspecifica(Disciplina disciplinaLista[], Aluno alunoLista[], Professor professorLista[], int *qtdDisciplinasPTR, int *qtdAlunoDisciplinaPTR, int *qtdAlunosPTR, int *qtdProfessoresPTR){

    int codigoDisciplina, matriculaAluno, statusCodigoDisciplina = 0;

    printf(" | --- DISCIPLINA ESPECÍFICA --- |\n\n");

    if(*qtdDisciplinasPTR == 0){
        printf("-> Nenhuma disciplina cadastrada <-\n");
    } else {

        exibirDisciplina(disciplinaLista, professorLista, qtdDisciplinasPTR, qtdAlunoDisciplinaPTR, qtdProfessoresPTR);

        printf("Digite o código da disciplina: ");
        scanf("%d", &codigoDisciplina);
        getchar();
        system("clear");

        for(int i=0; i<*qtdDisciplinasPTR; i++){
            if(codigoDisciplina == disciplinaLista[i].codigo){
                statusCodigoDisciplina = 1;
                printf("Disciplina: %s", disciplinaLista[i].nome);
                printf("Codigo: %d\n", disciplinaLista[i].codigo);
                printf("Semestre: %d\n", disciplinaLista[i].semestre);

                for(int j=0; j<*qtdProfessoresPTR; j++){
                    if(disciplinaLista[i].matriculaProfessor == professorLista[j].matricula){
                        printf("Professor: %s", professorLista[j].nome);
                    }
                }

                for(int j=0; j<*qtdAlunoDisciplinaPTR; j++){
                    matriculaAluno = disciplinaLista[i].alunosNaDisciplina[j];

                    for(int k=0; k<*qtdAlunosPTR; k++){
                        if(matriculaAluno == alunoLista[k].matricula){
                            printf("-- aluno: %s", alunoLista[k].nome);
                        }
                    }
                }
            }
        }

        if(statusCodigoDisciplina == 0){
            printf("-> Disciplina nao encontrada <-\n");
            return;
        }
    }
}

void exibirPorSexo(Aluno alunoLista[], Professor professorLista[], int *qtdAlunosPTR, int *qtdProfessoresPTR, int tipoCadastro){

    int tipoSexo;

    if(tipoCadastro == 0){
        printf(" | --- LISTAGEM DE ALUNOS POR SEXO --- |\n\n");

        if(*qtdAlunosPTR == 0){
            printf("-> Nenhum aluno cadastrado <-\n");
        } else {
            printf("Insira 1 - Mulher ou 2 - Homem: ");
            scanf("%d", &tipoSexo);
            getchar();

            for(int i=0; i<*qtdAlunosPTR; i++){
                if(tipoSexo == alunoLista[i].sexo){
                    textoListagemAlunosOuProfessores(alunoLista, professorLista, i, tipoCadastro);
                }
            }
        }

    } else {
        printf(" | --- LISTAGEM DE PROFESSORES POR SEXO --- |\n\n");

        if(*qtdProfessoresPTR == 0){
            printf("-> Nenhum professor cadastrado <-\n");
        } else {
            printf("Insira 1 - Mulher ou 2 - Homem: ");
            scanf("%d", &tipoSexo);
            getchar();

            for(int i=0; i<*qtdProfessoresPTR; i++){
                if(tipoSexo == professorLista[i].sexo){
                    textoListagemAlunosOuProfessores(alunoLista, professorLista, i, tipoCadastro);
                }

            }
        }
    }
}

void exibirPessoaPorOrdemAlfabetica(Aluno alunoLista[], Professor professorLista[], int *qtdAlunosPTR, int *qtdProfessoresPTR, int tipoCadastro){

int j, i;
  char aux[300];

    if(tipoCadastro == 0){

        if(*qtdAlunosPTR == 0){
            printf("-> Nenhum aluno cadastrado <-\n");
        } else {

            Aluno alunoListaCopia[CADASTRO_ALUNO_TAM];

            for(int l=0; l<*qtdAlunosPTR; l++){
                alunoListaCopia[l] = alunoLista[l];
            }

            for(j=0; j<*qtdAlunosPTR; j++){
                strcpy(aux,alunoListaCopia[j].nome);
                i = j-1;

                while(i >= 0 && strcmp(alunoListaCopia[i].nome, aux) > 0){
                    strcpy(alunoListaCopia[i+1].nome,alunoListaCopia[i].nome);
                    i--;
                }

                strcpy(alunoListaCopia[i+1].nome,aux);
            }

            for(int z=0; z<*qtdAlunosPTR; z++){
                printf("Nome do Aluno: %s", alunoListaCopia[z].nome);
            }
        }
    } else {

        if(*qtdProfessoresPTR== 0){
            printf("-> Nenhum professor cadastrado <-\n");
        } else {

            Professor professorListaCopia[CADASTRO_PROFESSOR_TAM];

            for(int l=0; l<*qtdProfessoresPTR; l++){
                professorListaCopia[l] = professorLista[l];
            }

            for(j=0; j<*qtdProfessoresPTR; j++){
                strcpy(aux,professorListaCopia[j].nome);
                i = j-1;

                while(i >= 0 && strcmp(professorListaCopia[i].nome, aux) > 0){
                    strcpy(professorListaCopia[i+1].nome,professorListaCopia[i].nome);
                    i--;
                }

                strcpy(professorListaCopia[i+1].nome,aux);
            }

            for(int z=0; z<*qtdProfessoresPTR; z++){
                printf("Nome do Professor: %s", professorListaCopia[z].nome);
            }
        }
    }

}

void textoListagemAlunosOuProfessores(Aluno alunoLista[], Professor professorLista[], int i, int tipoCadastro){

    if(tipoCadastro == 0){
        printf("Matricula: %d\n", alunoLista[i].matricula);
        printf("Nome: %s", alunoLista[i].nome);
        printf("Sexo: %d\n", alunoLista[i].sexo);
        printf("Data: %s", alunoLista[i].dataNascimento);
        printf("CPF: %s", alunoLista[i].cpf);
    } else {
        printf("Matricula: %d \n", professorLista[i].matricula);
        printf("Nome: %s", professorLista[i].nome);
        printf("Sexo: %d \n", professorLista[i].sexo);
        printf("Data: %s", professorLista[i].dataNascimento);
        printf("CPF: %s", professorLista[i].cpf);
    }
    printf("\n\n");
}

