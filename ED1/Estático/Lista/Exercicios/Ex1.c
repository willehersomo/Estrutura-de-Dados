#include <stdio.h>
#include <stdlib.h>
#define TF 10

typedef struct sLista{
int elementos [TF];
int n;
}LISTA;


void inicializar (LISTA *l)
{
    (*l).n = -1;
}

int cheia (LISTA l)
{
    if(l.n==TF-1)
    {
        return 1;
    }

        return 0;
}

int vazia (LISTA l)
{
    if(l.n==-1)
    {
        return 1;
    }
    return 0;
}

void inserir_posicao(LISTA *l, int pos, int elem)
{
    int i;
    if (cheia(*l))
    {
        printf ("Lista cheia\n");
    }
    else
    {
        if (pos>l->n+1||pos<0)
        {
            printf ("Posição inválida\n");
        }
        else
        {
            l->n++;
            for(i=l->n; i >= pos; i--)
            {
                l->elementos[i]=l->elementos[i-1];
            }
            l->elementos[pos]=elem;
        }
    }
}

void remover_posicao(LISTA *l, int pos)
{
    int i;
    if(vazia(*l))
    {
        printf ("Lista vazia\n");
    }
    else
    {
        if(pos>l->n+1 || pos<0)
        {
            printf("Posição Inválida\n");
        }
        else
        {
          for(i=pos;i<l->n;i++)
          {
            l->elementos[i]=l->elementos[i+1];
          }  
          l->n--;
        }
    }
    

}

void acessar_elemento(LISTA l, int pos)
{
    if (vazia(l))
    {
        printf("Lista Vazia!!\n");
    }
    else
    {
        if (pos < 0 || pos > l.n)
        {
            printf("Posição inválida\n");
        }
        else
        {
            printf("Elemento encontrado na posição %d: %d\n", pos, l.elementos[pos]);
        }
    }
}

void buscar_valor(LISTA l, int elem)
{
    int i;
    int encontrou = 0;
    int posicao = -1;

    if (vazia(l))
    {
        printf("Lista vazia!\n");
    }
    else
    {
        for (i = 0; i <= l.n; i++)
        {
            if (l.elementos[i] == elem)
            {
                encontrou = 1;
                posicao = i;
                i = l.n+1;
            }
        }

        if (encontrou)
        {
            printf("Valor encontrado na posição %d\n", posicao);
        }
        else
        {
            printf("Valor não encontrado\n");
        }
    }
}

void exibir_vetor(LISTA l)
{
    int i;
    if(vazia(l))
    {
        printf ("Lista vazia\n");
    }
    else
    {
        for(i=0;i<=l.n;i++)
        {
            printf ("[%d] ", l.elementos[i]);
        }
        printf ("\n");
    }
}

int menu ()
{
    int op;
    printf("Menu: \n");
    printf("1. Inserir elemento em uma posição especifica\n");
    printf("2. Remover elemento de uma posição especifica\n");
    printf("3. Acessar elemento\n");
    printf("4. Buscar valor\n");
    printf("5. Exibir vetor\n");
    printf("0. Encerrar programa\n");
    printf("Selecione a opção: ");
    scanf ("%d", &op);
    return op;
}

int main()
{
    LISTA l;
    inicializar(&l);
    int op, elem, pos;

    do
    {
        op = menu();
        switch (op)
        {
            case 1:
            printf ("Insira a posição desejada: ");
            scanf ("%d", &pos);
            printf ("Insira o valor desejado: ");
            scanf ("%d", &elem);
            inserir_posicao(&l, pos, elem);
            break;

            case 2:
            printf ("Insira a posição: ");
            scanf ("%d", &pos);
            remover_posicao(&l, pos);
            break;

            case 3:
            printf ("Insira a posição: ");
            scanf ("%d", &pos);
            acessar_elemento(l, pos);    
            break;

            case 4:
            printf ("Digite o elemento a ser procurado: ");
            scanf ("%d", &elem);
            buscar_valor(l, elem);
            break;

            case 5:
            exibir_vetor(l);
            break;

            case 0:
            printf ("Encerrado programa\n");
            break;

            default:
            printf ("Opção inválida\n");
            break;
        }

    }while(op!=0);

    return 0;
}