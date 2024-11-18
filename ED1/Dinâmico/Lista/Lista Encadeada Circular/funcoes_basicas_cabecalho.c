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

int vazio(LISTA *l)
{
    return l == NULL;
}

void inserir_inicio(LISTA **cabeca, int elemento)
{
    LISTA *q = getnode();
    if (q == NULL)
    {
        printf("Falha ao alocar espaço\n");
    }
    else
    {
        q->elemento = elemento;
        if (vazio(*cabeca))
        {
            *cabeca = q;
            q->next = *cabeca;
        }
        else
        {
            LISTA *aux = *cabeca;
            while (aux->next != *cabeca)
            {
                aux = aux->next;
            }

            aux->next = q;
            q->next = *cabeca;
            *cabeca = q;
        }
    }
}

void inserir_fim(LISTA **cabeca, int elemento)
{
    LISTA *q = getnode();

    if (q == NULL)
    {
        printf("Falha ao alocar espaço\n");
    }
    else
    {
        q->elemento = elemento;
        if (vazio(*cabeca))
        {
            *cabeca = q;
            q->next = *cabeca;
        }
        else
        {
            LISTA *aux = *cabeca;
            while (aux->next != *cabeca)
            {
                aux = aux->next;
            }
            aux->next = q;
            q->next = *cabeca;
        }
    }
}

void remover_inicio(LISTA **cabeca)
{
    if (vazio(*cabeca))
    {
        printf("Lista Vazia\n");
    }
    else
    {
        LISTA *primeiro = *cabeca;

        if ((*cabeca)->next == *cabeca)
        {
            *cabeca = NULL;
            free(primeiro);
        }
        else
        {
            LISTA *aux = *cabeca;
            while (aux->next != *cabeca)
            {
                aux = aux->next;
            }

            aux->next = (*cabeca)->next;
            *cabeca = (*cabeca)->next;

            free(primeiro);
        }
    }
}

void remover_fim(LISTA **cabeca)
{
    if (vazio(*cabeca))
    {
        printf("Lista Vazia\n");
    }
    else
    {
        LISTA *aux = *cabeca;

        if (aux->next == *cabeca)
        {
            free(aux);
            *cabeca = NULL;
        }
        else
        {
            LISTA *ultimo = NULL;
            while (aux->next != *cabeca)
            {
                ultimo = aux;
                aux = aux->next;
            }

            ultimo->next = *cabeca;
            free(aux);
        }
    }
}

void exibir_lista(LISTA *cabeca)
{
    if (vazio(cabeca))
    {
        printf("Lista Vazia\n");
    }
    else
    {
        LISTA *aux = cabeca;
        do
        {
            printf("[%d] ", aux->elemento);
            aux = aux->next;
        } while (aux != cabeca);

        printf("\n\n");
    }
}

int menu()
{
    int op;
    printf("1. Inserir no início\n");
    printf("2. Inserir no fim\n");
    printf("3. Remover do início\n");
    printf("4. Remover do fim\n");
    printf("5. Exibir lista\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &op);
    return op;
}

int main()
{
    LISTA *lista = NULL;
    LISTA *cabeca = lista;

    int op, elemento;

    do
    {
        op = menu();

        switch (op)
        {
        case 1:
            printf("Digite um elemento inteiro positivo: ");
            scanf("%d", &elemento);
            if (elemento > 0)
            {
                inserir_inicio(&cabeca, elemento);
            }
            else
            {
                printf("Por favor, insira um número inteiro positivo.\n");
            }
            break;
        case 2:
            printf("Digite um elemento inteiro positivo: ");
            scanf("%d", &elemento);
            if (elemento > 0)
            {
                inserir_fim(&cabeca, elemento);
            }
            else
            {
                printf("Por favor, insira um número inteiro positivo.\n");
            }
            break;
        case 3:
            remover_inicio(&cabeca);
            break;
        case 4:
            remover_fim(&cabeca);
            break;
        case 5:
            exibir_lista(cabeca);
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida\n");
        }
    } while (op != 0);

    return 0;
}
