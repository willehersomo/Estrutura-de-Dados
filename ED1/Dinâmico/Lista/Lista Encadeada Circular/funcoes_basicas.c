#include <stdio.h>
#include <stdlib.h>

typedef struct sLista
{
    int elemento;
    struct sLista *next;
} LISTA;

LISTA *getnode()
{
    return (LISTA *)malloc(sizeof(LISTA));
}

LISTA *inicializar(LISTA *l)
{
    return l = NULL;
}

int vazio(LISTA *l)
{
    return l == NULL;
}

void inserir_inicio(LISTA **l, int elemento)
{
    LISTA *aux;
    LISTA *q = getnode();
    if (q == NULL)
    {
        printf("Falha ao alocar espaço\n");
    }
    else
    {
        q->elemento = elemento;

        if (vazio(*l))
        {
            q->next = q;
            *l = q;
        }
        else
        {
            aux = *l;
            while (aux->next != *l)
            {
                aux = aux->next;
            }

            aux->next = q;
            q->next = *l;
            *l = q;
        }
    }
}

void inserir_fim(LISTA **l, int elemento)
{
    LISTA *aux;
    LISTA *q = getnode();

    if (q == NULL)
    {
        printf("Falha ao alocar espaço\n");
    }
    else
    {
        q->elemento = elemento;

        if (vazio(*l))
        {
            q->next = q;
            (*l) = q;
        }
        else
        {
            aux = (*l);
            while (aux->next != (*l))
            {
                aux = aux->next;
            }

            aux->next = q;
            q->next = (*l);
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

        if (aux->next == *l)
        {
            free(aux);
            *l = NULL;
        }
        else
        {
            LISTA *anterior = NULL;
            while (aux->next != *l)
            {
                anterior = aux;
                aux = aux->next;
            }

            anterior->next = *l;
            free(aux);
        }
    }
}

void remover_inicio(LISTA **l)
{
    if (vazio(*l))
    {
        printf("Lista Vazia\n");
    }
    else
    {
        LISTA *aux = *l;

        if (aux->next == *l)
        {
            free(aux);
            *l = NULL;
        }
        else
        {
            LISTA *ultimo = *l;
            while (ultimo->next != *l)
            {
                ultimo = ultimo->next;
            }

            *l = aux->next;
            ultimo->next = *l;
            free(aux);
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
        printf("[%d] ", aux->elemento);

        while (aux->next != l)
        {
            aux = aux->next;
            printf("[%d] ", aux->elemento);
        }

        printf("\n\n");
    }
}

int menu()
{
    int op;
    printf("Menu: \n");
    printf("1. Exibir Lista\n");
    printf("2. Inserir no Inicio\n");
    printf("3. Inserir no final\n");
    printf("4. Remover no inicio\n");
    printf("5. Remover no final\n");
    printf("0. Encerrar Programa\n");
    printf("Escolha uma opção: ");
    scanf("%d", &op);
    return op;
}

int main()
{
    LISTA *lista = inicializar(lista);
    int op;
    int x;

    do
    {
        op = menu();
        switch (op)
        {
        case 1:
            exibir_lista(lista);
            break;

        case 2:
            printf("Digite o número a inserir: ");
            scanf("%d", &x);
            inserir_inicio(&lista, x);
            break;

        case 3:
            printf("Digite o número a inserir: ");
            scanf("%d", &x);
            inserir_fim(&lista, x);
            break;

        case 4:
            remover_inicio(&lista);
            break;

        case 5:
            remover_fim(&lista);
            break;

        case 0:
            printf("Encerrando\n");
            break;

        default:
            printf("Opção Inválida\n");
            break;
        }
    } while (op != 0);
    return 0;
}
