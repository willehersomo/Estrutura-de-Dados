/*
Dada uma lista sequencial estática L1, referente aos alunos matriculados em uma determinada disciplina, 
elabore em C a função abaixo. 
Cada “célula” da lista deve conter as seguintes informações: 
número de matrícula do aluno (inteiro), 
nome do aluno (char) e 
média das notas obtidas pelo aluno (float). 
Assuma que o número máximo de alunos matriculados na disciplina é 50.

a) Fazer uma cópia da lista L1 em L2, 
verificando e eliminando possíveis repetições de células com o mesmo número de matrícula. 
As células com números de matrícula repetidos devem ser armazenadas em uma terceira lista L3 
(obs.: a lista L2 não deve possuir nenhuma cópia dos elementos repetidos).

Obs: Deve-se implementar todas as funções adicionais utilizadas na função desenvolvida em a).
*/


#include <stdio.h>
#include <string.h>
#define TF 50

typedef struct sAluno
{
    int prontuario;
    char nome[50];
    float media;
}ALUNO;

typedef struct sLista
{
    ALUNO aluno[TF];
    int n;
}LISTA;

void inicializar (LISTA *l)
{
    l->n=-1;
}

int vazio(LISTA l)
{
    return l.n==-1;
}

int cheio (LISTA l)
{
    return l.n==TF-1;
}

void inserir_fim (LISTA *l, ALUNO a)
{
    if (cheio(*l))
    {
        printf ("Fila cheia\n");
    }
    else
    {
        l->n++;
        l->aluno[l->n].prontuario = a.prontuario;
        strcpy(l->aluno[l->n].nome, a.nome);
        l->aluno[l->n].media=a.media;
    }
}


/*a) Fazer uma cópia da lista L1 em L2, 
verificando e eliminando possíveis repetições de células com o mesmo número de matrícula. 
As células com números de matrícula repetidos devem ser armazenadas em uma terceira lista L3 
(obs.: a lista L2 não deve possuir nenhuma cópia dos elementos repetidos).
*/

int verificar_duplicada (LISTA l2, int prontuario)
{
    int i;
    if(vazio(l2))
    {
        return 0;
    }
    else
    {
        for(i=0;i<=l2.n;i++)
        {
            if(l2.aluno[i].prontuario==prontuario)
            {
                return 1;
            }
        }
    }

    return 0;
}

void organizar_lista(LISTA l, LISTA *l2, LISTA *l3)
{
    int i;
    for(i=0;i<=l.n;i++)
    {
        if(verificar_duplicada(*l2, l.aluno[i].prontuario))
        {
                                                           
           inserir_fim(l3, l.aluno[i]);                        
           
        }
        else
        {  
           inserir_fim(l2, l.aluno[i]);
        }
    }
}

ALUNO preencher_aluno()
{
    ALUNO a;
    printf("Digite nome do aluno: ");
    scanf (" %s[^\n]", a.nome);
    printf ("Digite o prontuário do aluno: ");
    scanf ("%d", &a.prontuario);
    printf ("Digite média do aluno: ");
    scanf("%f", &a.media);
    return a;
}

void exibir_lista (LISTA l)
{
    int i;
    if(vazio(l))
    {
        printf("Lista Vazia\n");

    }
    else
    {
        for(i=0;i<=l.n;i++)
        {
            
            printf ("Matricula: %d - ", l.aluno[i].prontuario);
            printf("%s - ", l.aluno[i].nome);
            printf("Média: %.2f", l.aluno[i].media);
            printf("\n");
        }
    }
}

int menu()
{
    int op;

    printf("\nMENU\n");
    printf("1. Inserir aluno.\n");
    printf("2. Organizar aluno\n");
    printf("3. Exibir listas de alunos\n");
    printf("0. Sair\n");
    printf("Insira a opção: ");
    scanf("%d", &op);
    printf("\n");
    return op;
}

int main()
{
    int op;
    ALUNO a;
    LISTA l1, l2, l3;

    inicializar(&l1);
    inicializar(&l2);
    inicializar(&l3);

    do
    {
        op=menu();
        switch(op)
        {
            case 1:
            a=preencher_aluno();
            inserir_fim(&l1, a);
            break;

            case 2:
            organizar_lista(l1, &l2, &l3);
            break;

            case 3:
            printf("Lista 1: \n");
            exibir_lista(l1);
            
            printf("Lista 2: \n");
            exibir_lista(l2);
            
            printf("Lista 3: \n");
            exibir_lista(l3);

            break;

            case 0:
            printf("Encerrando...\n");
            break;

            default:
            printf("Opção inválida\n");
            break;
        }

    }while (op!=0);
    

return 0;

}