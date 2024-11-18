/*7. Codifique, compile e execute um programa em Linguagem C que permita fazer as
seguintes operações sobre uma lista linear duplamente encadeada:
a. Inserir um elemento no início da lista;
b. Inserir um elemento no final da lista;
c. Remover um elemento do início da lista;
d. Remover um determinado elemento da lista;
e. Exibir os elementos da lista
OBS: Defina funções para cada operação, incluindo uma função menu.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct sLista
{
    int elemento;
    struct sLista *next;
    struct sLista *back;
} LISTA;

LISTA *getnode()
{
    return (LISTA *)malloc(sizeof(LISTA));
}

int vazio(LISTA *l)
{
    return l==NULL;
}

void inserir_inicio(LISTA **l, int elemento)
{
    LISTA *q = getnode();
    if (q == NULL)
    {
        printf("Falha ao alocar espaço\n");
    }
    else
    {
        q->elemento = elemento;
        q->next = *l;
        q->back = NULL;

        if (*l != NULL)
        {
            (*l)->back = q;
        }

        *l = q;
    }
}

void inserir_fim(LISTA **l, int elemento)
{
    LISTA *q = getnode();
    if (q == NULL)
    {
        printf("Falha ao alocar espaço\n");
    }
    else
    {

        q->elemento = elemento;
        q->next = NULL;
        q->back = NULL;

        if (*l == NULL)
        {
            *l = q;
        }
        else
        {
            LISTA *aux = *l;
            while (aux->next != NULL)
            {
                aux = aux->next;
            }

            aux->next = q;
            q->back = aux;
        }
    }
}

void remover_inicio (LISTA ** l)
{
    if(vazio(*l))
    {
        printf("Lista vazia\n");
    }
    else
    {
        LISTA * aux = (*l);
        if(aux->next == NULL)
        {
            free(aux);
            (*l)= NULL;
        }
        else
        {
            (*l) = aux->next;
            (*l)->back=NULL;
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
    if (aux->next == NULL)
    {
         free(aux);
        *l = NULL;
    }
    else
    {
         LISTA *anterior = NULL;
        while (aux->next != NULL)
        {
            anterior = aux;
            aux = aux->next;
        }

        anterior->next = NULL;
        free(aux);
    }
    }
}

void remover_elemento(LISTA **l, int elemento)
{
    if (vazio(*l))
    {
        printf("Lista Vazia\n");
    }
    else
    {
        LISTA *aux = *l;

         if (aux->elemento == elemento)
        {
            *l = aux->next;
            if (*l != NULL)
            {
                (*l)->back = NULL;
            }
            free(aux);
            printf("Elemento %d removido\n", elemento);
        }
        else
        {
             while (aux != NULL && aux->elemento != elemento)
            {
                aux = aux->next;
            }

            if (aux == NULL)
            {
                printf("Elemento %d não encontrado\n", elemento);
            }
            else
            {
                 if (aux->next != NULL)
                {
                    aux->next->back = aux->back;
                }

                if (aux->back != NULL)
                {
                    aux->back->next = aux->next;
                }

                free(aux);
                printf("Elemento %d removido\n", elemento);
            }
        }
    }
}

void exibir_lista(LISTA *l)
{
    if (l == NULL)
    {
        printf("Lista vazia\n");
    }
    else
    {
        LISTA *aux = l;
        printf("Elementos na lista:\n");
        while (aux != NULL)
        {
            printf("%d ", aux->elemento); 
            aux = aux->next;
        }
        printf("\n");
    }
}

int menu()
{
    int op;
    printf("1. Inserir elemento no início da lista\n");
    printf("2. Inserir elemento no final da lista\n");
    printf("3. Remover elemento do início da lista\n");
    printf("4. Remover elemento do final da lista\n");
    printf("5. Remover um determinado elemento\n");
    printf("6. Exibir os elementos da lista\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &op);
    return op;
}

int main()
{
    LISTA *lista = NULL;
    int op, elemento;

    do
    {
        op = menu(); 

        switch (op)
        {
            case 1:
                printf("Digite o elemento a ser inserido no início: ");
                scanf("%d", &elemento);
                inserir_inicio(&lista, elemento);
                break;

            case 2:
                printf("Digite o elemento a ser inserido no final: ");
                scanf("%d", &elemento);
                inserir_fim(&lista, elemento);
                break;

            case 3:
                remover_inicio(&lista);
                break;

            case 4:
                remover_fim(&lista);
                break;

            case 5:
                printf("Digite o elemento a ser removido: ");
                scanf("%d", &elemento);
                remover_elemento(&lista, elemento);
                break;

            case 6:
                exibir_lista(lista);
                break;

            case 0:
                printf("Encerrando o programa.\n");
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (op != 0);

    return 0;
}

