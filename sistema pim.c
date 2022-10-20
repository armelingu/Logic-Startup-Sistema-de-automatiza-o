#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#define SIZE 200
#define ALUNO 70

int opcao;
void menu();
void Mcolaborador();
void Login();
void pesqColaborador();
void cadColaborador();
void Mcrianca();
void pesqCrianca();
void cadCrianca();
void delCrianca();

//variaveis para armazenar os cad
char nome[SIZE][50];
char email[SIZE][50];
char cpf[SIZE][50];
char tel[SIZE][50];
float salario[SIZE];
//fim

typedef struct{
    char nomea[70];
    char rg[70];
    float notas[4];
    int ativo;
} crianca;
crianca criancas[ALUNO];

int main(){

    setlocale(LC_ALL, "portuguese");
    //Login();
    menu();

    return 0;
}

void Mcrianca(){

    system("cls");
    printf("\n                     *********** MENU DAS CRIANÇAS ***********\n");
    printf("\nDigite 1 para cadastrar, 2 para consultar, 3 para excluir ou 0 para voltar ao menu principal: ");
    scanf("%d", &opcao);

    if(opcao == 1)
    {
        cadCrianca();
    }

    else if(opcao == 2)
    {
        pesqCrianca();
    }
    else if(opcao == 3)
    {
        delCrianca();
    }
    else if(opcao == 0)
    {
        menu();
        system("cls");
    }

}

void delCrianca(){

    system("cls");
    int matricula;

    printf("\n********** TELA DE EXCLUSÃO DE CRIANÇAS **********\n");

    do
    {

    printf("\nDigite a matricula da criança que deseja remover: ");
    scanf("%d", &matricula);
    --matricula;
    criancas[matricula].ativo = 0;

    printf("\nCriança removida com sucesso! Digite 1 para remover novamente ou 0 para voltar ao menu: ");
    scanf("%d", &opcao);

    switch(opcao)
        {
            case 0: {
            Mcrianca();
            system("pause");
            system("cls");
            break; }
        }

    }while (opcao == 1);

}

void cadCrianca(){

    system("cls");
    char nome[70];
    char rg[70];
    float notas[4];

    printf("\n********** TELA DE CADASTRO DE CRIANÇAS **********\n");

    do{
        fflush(stdin);
        printf("\n       Nome: ");
        fgets(nome, sizeof(nome), stdin);
        fflush(stdin);
        printf("\n       RG: ");
        fgets(rg, sizeof(rg), stdin);
        printf("\n       Nota 1°BIM: ");
        scanf("%f", &notas[0]);
        printf("\n       Nota 2°BIM: ");
        scanf("%f", &notas[1]);
        printf("\n       Nota 2°BIM: ");
        scanf("%f", &notas[2]);
        printf("\n       Nota 4°BIM: ");
        scanf("%f", &notas[3]);

        for(int i = 0; i < ALUNO; i++)
        {
            if(criancas[i].ativo == 0)
            {
                criancas[i].notas[0] = notas[0];
                criancas[i].notas[1] = notas[1];
                criancas[i].notas[2] = notas[2];
                criancas[i].notas[3] = notas[3];
                strcpy(criancas[i].nomea, nome);
                strcpy(criancas[i].rg, rg);
                criancas[i].ativo = 1;
                break;
            }
        }

        printf("\n\n     Digite 1 para cadastrar denovo ou 0 para voltar ao menu: ");
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 0: {
            Mcrianca();
            system("pause");
            system("cls");
            break; }
        }
    }while(opcao == 1);
}

void pesqCrianca(){

    system("cls");
    char pesqRg[70];
    int i;


    do
    {
        system("cls");
        printf("\n ********** TELA DE CONSULTA DE CRIANÇAS **********\n");
        printf("\nDigite 1 para pesquisa por RG ou 2 para listar todos: ");
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
            {
                fflush(stdin);
                printf("Digite o RG: ");
                fgets(pesqRg,sizeof(pesqRg), stdin);
                for(i = 0; i < ALUNO; i++)
                {
                    if(strcmp(criancas[i].rg, pesqRg) == 0)
                    {
                        printf("\n---------------");
                        printf("\nNOME: %s\nRG: %s\nNota 1°BIM:: %.1f\nNota 2°BIM:: %.1f\nNota 3°BIM:: %.1f\nNota 4°BIM: %.1f",
                        criancas[i].nomea, criancas[i].rg, criancas[i].notas[0], criancas[i].notas[1], criancas[i].notas[2], criancas[i].notas[3]);
                        printf("\n---------------");
                    }
                }
                break;
            }

            case 2:
            {
                system("pause");
                system("cls");
                for(i = 0; i < ALUNO; i++)
                {
                    if(criancas[i].ativo == 1)
                    {
                        printf("\nMATRICULA: %d\nNOME: %s\nRG: %s\nNota 1°BIM:: %.1f\nNota 2°BIM:: %.1f\nNota 3°BIM:: %.1f\nNota 4°BIM: %.1f",
                        i +1, criancas[i].nomea, criancas[i].rg, criancas[i].notas[0], criancas[i].notas[1], criancas[i].notas[2], criancas[i].notas[3]);
                        printf("\n-------------------");
                    }
                }
                break;
            }
            default:
                printf("Opção Inválida!\n");
                break;
        }

        printf("\nDigite 1 para continuar pesquisando ou 0 para voltar ao menu: ");
        scanf("%d", &opcao);
        switch(opcao)
        {
            case 0: {
            Mcrianca();
            system("pause");
            system("cls");
            break; }
        }
    } while(opcao == 1);
}

void Login(){

    char user[15] = "NovasTrilhas";
    char user1[15];
    char senha[15] = "novastrilhas";
    char senha1[15];
    int loginFeito = 0;

    printf("\n---------- TELA DE LOGIN ----------\n");

    while(!loginFeito)
    {
        printf("\nDigite o Usuário: ");
        scanf("%s", user1);

        printf("\nDigite a Senha: ");
        scanf("%s", senha1);

        if (strcmp(user, user1) == 0 && strcmp(senha, senha1) == 0)
        {
            system("cls");
            printf("\n\nLogado com Sucesso - Bem Vindo ao Sistema!\n\n");
            system("pause");
            system("cls");

            loginFeito = 1;
        }
        else
            printf("\n\nUsuário e/ou Senha Inválidos!\n\n");
    }
}

void cadColaborador(){
    system("cls");

    static int linha;

    printf("\n********** TELA DE CADASTRO DE COLABORADORES **********\n");

    do
    {
        fflush(stdin);
        printf("\n       Digite o nome: ");
        gets(nome[linha]);
        fflush(stdin);
        printf("\n       Digite o email: ");
        gets(email[linha]);
        fflush(stdin);
        printf("\n       Digite o cpf: ");
        gets(cpf[linha]);
        fflush(stdin);
        printf("\n       Digite o telefone: ");
        gets(tel[linha]);
        fflush(stdin);
        printf("\n       Digite o salário: ");
        scanf("%f", &salario[linha]);
        printf("\n\n     Digite 1 para cadastrar denovo ou 0 para voltar ao menu: ");
        scanf("%d", &opcao);
        linha ++;

        switch(opcao)
        {
            case 0: {
            Mcolaborador();
            system("pause");
            system("cls");
            break; }
        }
    } while(opcao == 1);

}

void pesqColaborador(){
    system("cls");

    int i;
    char pesqCpf[50], pesqEmail[50];

    printf("\n********** TELA DE CONSULTA DE COLABORADORES **********\n");

    do
    {
        printf("\nDigite 1 para pesquisa por CPF, 2 para pesquisar por EMAIL ou 3 para listar todos: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
            {
                printf("Digite o CPF: ");
                scanf("%s", &pesqCpf);
                for(i = 0; i < SIZE; i++)
                {
                    if(strcmp(cpf[i], pesqCpf) == 0)
                    {
                        printf("\nNOME: %s\nEMAIL: %s\nCPF: %s\nTELEFONE: %s\nSALÁRIO: %.2f\n\n", nome[i], email[i], cpf[i], tel[i], salario[i]);
                    }
                }
                break;
            }

            case 2:
            {
                printf("Digite o EMAIL: ");
                scanf("%s", &pesqEmail);
                for(i = 0; i < SIZE; i++)
                {
                    if(strcmp(email[i], pesqEmail) == 0)
                    {
                        printf("\nNOME: %s\nEMAIL: %s\nCPF: %s\nTELEFONE: %s\nSALÁRIO: %.2f\n\n", nome[i], email[i], cpf[i], tel[i], salario[i]);
                    }
                }
                break;
            }

	        case 3:
            {
                system("pause");
                system("cls");
                for(i = 0; i < SIZE; i++)
                {
			        if(salario[i] > 0)
			        {
                	printf("\nNOME: %s\nEMAIL: %s\nCPF: %s\nTELEFONE: %s\nSALÁRIO: %.2f\n", nome[i], email[i], cpf[i], tel[i], salario[i]);
			        printf("--------------------------------------------------------------");
			        }
			        else
			        {
			        break;
			        }
                }
                break;
            }
            default:
                printf("Opção Inválida!\n");
                break;
        }
        printf("\nDigite 1 para continuar pesquisando ou 0 para voltar ao menu: ");
        scanf("%d", &opcao);
        switch(opcao)
        {
            case 0: {
            Mcolaborador();
            system("pause");
            system("cls");
            break; }
        }
    } while(opcao == 1);
}

void Mcolaborador(){
    system("cls");
    printf("\n             *********** MENU DE COLABORADOR ***********\n");
    printf("\nDigite 1 para cadastrar, 2 para consultar ou 0 para voltar ao menu principal: ");
    scanf("%d", &opcao);

    if(opcao == 1)
    {
        cadColaborador();
    }

    else if(opcao == 2)
    {
        pesqColaborador();
    }
    else if(opcao == 0)
    {
        menu();
        system("cls");
    }
}

void menu(){
    system("cls");
    do
    {
        printf("\n---------- TELA DE MENU ----------\n");
        printf("    1) Menu de Colaboradores\n");
        printf("    2) Menu de Diretores\n");
        printf("    3) Menu de Educadores\n");
        printf("    4) Menu de Crianças\n\n");
        printf("    0) SAIR\n\n");
        printf("Digite sua opção: ");
        scanf("%d", &opcao);

	    switch(opcao)
        {
            case 1:
	        {
                Mcolaborador();
                system("pause");
                system("cls");
                break;
            }
            case 4:
	        {
                Mcrianca();
                system("pause");
                system("cls");
                break;
            }
            case 0:
            {
                exit("Até mais!");
                system("pause");
                system("cls");
            }
        }
    }while(opcao);
}
