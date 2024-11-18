/*Marcos Paulo irritado com o controle remoto de sua televisão que só passava os canais
em uma direção, resolveu ligar na garantia do produto solicitando um novo controle
remoto que funcionasse corretamente (capaz de percorrer em duas direções,
‘aumentar’ e ‘diminuir’ os canais). Utilizando como base a implementação do exercício
6), codifique, compile e execute uma nova aplicação que seja capaz de percorrer os
canais com o novo controle remoto. Para isso, utilize o conceito de lista linear
duplamente encadeada circular.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sTV
{
    char nome[50];
    int numero;
} TV;

typedef struct sLista
{
    TV tv;
    struct sLista *next;
    struct sLista *back;
} LISTA;

LISTA *getnode()
{
    return (LISTA *)malloc(sizeof(LISTA));
}

int vazio(LISTA *l)
{
    return l == NULL;
}

void inserir_inicio(LISTA **l, TV tv)
{
    LISTA *q = getnode();
    if (q == NULL)
    {
        printf("Falha ao alocar espaço\n");
    }
    else
    {
        strcpy(q->tv.nome, tv.nome);
        q->tv.numero = tv.numero;

        if (vazio(*l))
        {
            q->next = q;
            q->back = q;
            *l = q;
        }
        else
        {
            LISTA *ultimo = (*l)->back;

            q->next = *l;
            q->back = ultimo;
            ultimo->next = q;
            (*l)->back = q;
            *l = q;
        }
    }
}

void inserir_fim(LISTA **l, TV tv)
{
    LISTA *q = getnode();
    if (q == NULL)
    {
        printf("Falha ao alocar espaço\n");
    }
    else
    {
        strcpy(q->tv.nome, tv.nome);
        q->tv.numero = tv.numero;

        if (vazio(*l))
        {
            q->next = q;
            q->back = q;
            *l = q;
        }
        else
        {
            LISTA *ultimo = (*l)->back;

            q->next = *l;
            q->back = ultimo;
            ultimo->next = q;
            (*l)->back = q;
        }
    }
}

void remover_inicio(LISTA **l)
{
    if (vazio(*l))
    {
        printf("Lista vazia\n");
    }
    else
    {
        LISTA *aux = *l;

        if (aux->next == aux)
        {
            free(aux);
            *l = NULL;
        }
        else
        {
            LISTA *ultimo = aux->back;

            *l = aux->next;
            (*l)->back = ultimo;
            ultimo->next = *l;
            free(aux);
        }
    }
}

void remover_fim(LISTA **l)
{
    if (vazio(*l))
    {
        printf("Lista Vazia\n");
    }
    else
    {
        LISTA *aux = *l;

        if (aux->next == aux)
        {
            free(aux);
            *l = NULL;
        }
        else
        {
            LISTA *ultimo = (*l)->back;
            LISTA *penultimo = ultimo->back;

            penultimo->next = *l;
            (*l)->back = penultimo;
            free(ultimo);
        }
    }
}

void exibir_lista(LISTA *l)
{
    if (vazio(l))
    {
        printf("Lista Vazia\n");
    }
    else
    {
        LISTA *aux = l;
        do
        {
            printf("Canal %d - %s\n", aux->tv.numero, aux->tv.nome);
            aux = aux->next;
        } while (aux != l);
        printf("\n");
    }
}

void passar_canal(LISTA **controle)
{
    if (*controle == NULL)
    {
        printf("Não há canais cadastrados\n");
    }
    else
    {
        *controle = (*controle)->next;
        printf("Canal %d - %s\n", (*controle)->tv.numero, (*controle)->tv.nome);
    }
}

void voltar_canal(LISTA **controle)
{
    if (*controle == NULL)
    {
        printf("Não há canais cadastrados\n");
    }
    else
    {
        *controle = (*controle)->back;
        printf("Canal %d - %s\n", (*controle)->tv.numero, (*controle)->tv.nome);
    }
}

TV informacao()
{
    TV retorno;
    printf("Insira número do canal: ");
    scanf("%d", &retorno.numero);
    printf("Insira nome do canal: ");
    scanf(" %[^\n]", retorno.nome);
    return retorno;
}

int menu()
{
    int op;
    printf("\n----- Menu de Operações -----\n");
    printf("1. Cadastrar canal no começo da lista\n");
    printf("2. Cadastrar canal no final da lista\n");
    printf("3. Remover canal do início\n");
    printf("4. Remover canal do final\n");
    printf("5. Exibir lista de canais\n");
    printf("6. Passar para o próximo canal\n");
    printf("7. Voltar para o canal anterior\n");
    printf("0. Desligar TV\n");
    printf("Escolha uma opção: ");
    scanf("%d", &op);
    return op;
}

int main()
{
    LISTA *l = NULL;
    LISTA *controle = NULL;
    TV tv;
    int op;

    do
    {
        op = menu();

        switch (op)
        {
            case 1:
                tv = informacao();
                inserir_inicio(&l, tv);
                if (controle == NULL)
                {
                    controle = l;
                }
                break;

            case 2:
                tv = informacao();
                inserir_fim(&l, tv);
                if (controle == NULL)
                {
                    controle = l;
                }
                break;

            case 3:
                remover_inicio(&l);
                if (vazio(l))
                {
                    controle = NULL;
                }
                break;

            case 4:
                remover_fim(&l);
                if (vazio(l))
                {
                    controle = NULL;
                }
                break;

            case 5:
                exibir_lista(l);
                break;

            case 6:
                passar_canal(&controle);
                break;

            case 7:
                voltar_canal(&controle);
                break;

            case 0:
                printf("Desligando TV\n");
                break;

            default:
                printf("Opção Inválida\n");
                break;
        }

    } while (op != 0);

    return 0;
}
