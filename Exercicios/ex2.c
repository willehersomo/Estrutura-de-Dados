#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Na manhã do dia 15 de agosto de 2011 o site de internet “O Globo” publicou a notícia
de que a empresa Google anunciou em seu blog corporativo a compra da Motorola pelo
valor de US$ 12,5 bilhões. Essa notícia pegou de surpresa os funcionários da Motorola
que ficaram animados ao ouvir a declaração do diretor geral da Google: “Estamos
ansiosos para receber os funcionários da Motorola em nossa família de Googlers”.
Diante do compromisso da Motorola com o desenvolvimento Android, os gerentes
fizeram uma reunião com os líderes de projeto, responsáveis pelo setor, para que
algumas atividades fossem concluídas antes da integração das duas companhias. Dentre
os módulos a serem finalizados destacou-se o módulo de contato para celular, que
deverá ser implementado no prazo máximo de dois dias. Este módulo deverá possibilitar
a inserção/listagem/remoção/pesquisa de contatos por nome no celular, respeitando a
ordem alfabética. Na inserção de um novo contato deverá ser possível cadastrar dois
números de telefone e o toque de chamada (ringtone) personalizado para cada usuário.
Como parte dos requisitos foi solicitada a implementação usando a linguagem C
utilizando os conceitos de lista linear dinâmica.*/

typedef struct sContato
{

    char nome[50];
    char numero_telefone[2][14];
    char ringtone[20];

} CONTATO;

typedef struct sLista
{
    CONTATO contato;
    struct sLista *next;
} LISTA;

LISTA *getnode()
{
    return (LISTA *)malloc(sizeof(LISTA));
}

LISTA *inicializar(LISTA *l)
{
    l = NULL;
    return l;
}

int vazio(LISTA *l)
{
    return (l == NULL);
}

void inserir_lista(LISTA **l, CONTATO contato)
{
    LISTA *aux;
    LISTA *q = getnode();
    if (q == NULL)
    {
        printf("Falha ao alocar espaço\n");
    }
    else
    {
        strcpy(q->contato.nome, contato.nome);
        strcpy(q->contato.numero_telefone[0], contato.numero_telefone[0]);
        strcpy(q->contato.numero_telefone[1], contato.numero_telefone[1]);
        strcpy(q->contato.ringtone, contato.ringtone);
        q->next = NULL;

        if (vazio(*l))
        {
            (*l) = q;
        }
        else if (strcmp(q->contato.nome, (*l)->contato.nome) < 0)
        {
            aux = (*l);
            q->next = aux;
            (*l) = (q);
        }
        else
        {
            aux = (*l);

            while (aux != NULL && (strcmp(q->contato.nome, aux->next->contato.nome) > 0))
            {
                aux = aux->next;
            }

            q->next = aux->next;
            aux->next = q;
        }
    }
}

void remover_lista(LISTA **l, char nome[])
{
    if (vazio(*l))
    {
        printf("Lista Vazia\n");
    }
    else
    {

        LISTA *aux = *l;
        LISTA *anterior = NULL;

        if (strcmp(nome, aux->contato.nome) == 0)
        {
            *l = aux->next;
            free(aux);
            printf("Contato deletado\n");
        }
        else
        {

            while (aux != NULL && strcmp(nome, aux->contato.nome) != 0)
            {
                anterior = aux;
                aux = aux->next;
            }

            if (aux == NULL)
            {
                printf("Contato não existe\n");
            }

            else
            {
                anterior->next = aux->next;
                free(aux);
                printf("Contato deletado\n");
            }
        }
    }
}

void pesquisar_contato (LISTA * l, char nome[])
{
    if(vazio(l))
    {
        printf("Lista Vazia\n");        
    }
    else
    {
        LISTA *aux;
        aux = (l);

        if(strcmp(aux->contato.nome, nome)==0)
        {
            printf("Informações do contato: \n");
            printf("%s\n", aux->contato.nome);
            printf("%s/%s\n", aux->contato.numero_telefone[0], aux->contato.numero_telefone[1]);
            printf("Toque de telefone: %s\n\n", aux->contato.ringtone);

        }
        else
        {
            while(aux!=NULL && strcmp (aux->contato.nome, nome)!=0)
            {
                aux=aux->next;
            }

            if(aux==NULL)
            {
                printf("Contato Inexiste\n");
            }
            else
            {
                printf("Informações do contato: \n");
                printf("%s\n", aux->contato.nome);
                printf("%s/%s\n", aux->contato.numero_telefone[0], aux->contato.numero_telefone[1]);
                printf("Toque de telefone: %s\n\n", aux->contato.ringtone);
            }
        }
    }

}

void listar_contatos (LISTA *l)
{
    if(vazio(l))
    {
        printf("Lista Vazia\n");
    }
    else
    {
        LISTA * aux = (l);

        while(aux!=NULL)
        {
            printf("----------------------\n");
            printf("Informações do contato: \n");
            printf("%s\n", aux->contato.nome);
            printf("%s/%s\n", aux->contato.numero_telefone[0], aux->contato.numero_telefone[1]);
            printf("Toque de telefone: %s\n", aux->contato.ringtone);
            printf("----------------------\n");

            aux=aux->next;

        }
        printf ("\n");
    }
}

CONTATO info ()
{
    CONTATO retorno;
    printf("Digite o nome do contato: ");
    scanf(" %[^\n]", retorno.nome);
    printf("Digite o primeiro contato: ");
    scanf(" %[^\n]", retorno.numero_telefone[0]);
    printf("Digite o segundo número: ");
    scanf(" %[^\n]", retorno.numero_telefone[1]);
    printf("Qual o toque de telefone? ");
    scanf (" %[^\n]", retorno.ringtone);
    return retorno;
}

int menu()
{
    int op;
    printf("\nMENU\n");
    printf("1. Inserir Contato\n");
    printf("2. Remover Contato\n");
    printf("3. Pesquisar Contatos\n");
    printf("4. Listar Contatos\n");
    printf("0. Encerrar Programa\n");
    scanf("%d", &op);
    return op;
}

int main()
{
    LISTA *lista = inicializar(&lista);
    CONTATO contato;
    int op;
    char nome[50];

    do
    {
        op = menu();
        switch (op)
        {
            case 1:
            contato = info();
            inserir_lista(&lista, contato);
            break;

            case 2:
            printf("Pesquise o contato que será removido: ");
            scanf(" %[^\n]", nome);
            remover_lista(&lista, nome);
            break;

            case 3:
            printf ("Digite o nome do contato: ");
            scanf(" %[^\n]", nome);
            pesquisar_contato(lista, nome);
            break;

            case 4:
            listar_contatos(lista);
            break;

            case 0:
            printf("Encerrando Programa\n");
            break;

            default:
            printf ("Opção Inválida\n");
            break;
        }


    }while(op!=0);

    return 0;
}