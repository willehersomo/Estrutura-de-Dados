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

void inserir_lista_fim(LISTA **l, int elemento)
{
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
            (*l) = q;
            q->next = NULL;
        }
        else
        {
            LISTA *aux = (*l);

            while (aux->next != NULL)
            {
                aux = aux->next;
            }

            aux->next = q;
            q->next = NULL;
        }
    }
}

void exibir_lista(LISTA *l)
{
    LISTA *aux;

    if (!vazio(l))
    {
        aux = l;
       
        while (aux != NULL)
        {

            printf("[%d] ", aux->elemento);
            aux = aux->next;
        }
        printf("\n");
    }
    else
    {
        printf("Vazio\n");
    }
}

void imprimir_reverso_recursão(LISTA *l)
{
    if (!vazio(l))   
    {
    imprimir_reverso_recursão(l->next);
    printf("[%d] ", l->elemento);
    }
}

                       
int menu()
{
    int op;
    printf("\nMENU\n");
    printf("1. Inserir na Lista\n");
    printf("2. Exibir lista\n");
    printf("3. Exibir lista reversa\n");
    printf("0. Sair\n");
    scanf("%d", &op);
    return op;
}


int main()
{
    LISTA *lista = NULL;
    int op, elemento;

    do{
        op=menu();
        switch(op)
        {
            case 1:
            printf("Digite o número que será inserido: ");
            scanf("%d", &elemento);
            inserir_lista_fim(&lista, elemento);
            break;

            case 2: 
            exibir_lista(lista);
            break;
            
            case 3:
            imprimir_reverso_recursão(lista);
            printf("\n\n");
            break;

            case 0:
            printf("Encerrando\n");
            break;

            default:
            printf("Opção Inválida\n");
            break;

        }
    }while(op!=0);

    return 0;
}
