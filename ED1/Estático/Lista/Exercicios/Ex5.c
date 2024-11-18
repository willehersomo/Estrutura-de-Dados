#include <stdio.h>
#include <locale.h>
#define TF 10

typedef struct sLista
{
    int elementos[TF];
    int n;
}LISTA;

void inicializar (LISTA *l)
{
    l->n=-1;
}

int cheia (LISTA l)
{
    if(l.n==TF-1)
    {
        return 1;
    }
    return 0;
}

int vazia(LISTA l)
{
    if(l.n==-1)
    {
        return 1;
    }
    return 0;
}

void inserir_inicio(LISTA *l, int num)
{
    int i;
    if(cheia(*l))
    {
        printf("Lista cheia\n");
    }
    else
    {  
        l->n++;
        for(i=l->n;i>0;i--)
        {
            l->elementos[i]=l->elementos[i-1];
        }
        l->elementos[0] = num;
    }
}

void inserir_fim(LISTA *l, int num)
{  
    int i;
    if(cheia(*l))
    {
        printf ("Lista Cheia\n");
    }
    else
    {
        l->n++;
        l->elementos[l->n]=num;
    }

}

void inserir_posicao(LISTA *l, int num, int pos)
{
    int i;
    if(cheia(*l))
    {
        printf ("Lista Cheia\n");
    }
    else
    {
        if(pos<0||pos>l->n)
        {
            printf ("Posição inválida\n");
        }
        else
        {
        l->n++;
        for (i=l->n;i>pos;i++)
        {
            l->elementos[i]=l->elementos[i-1];
        }

        l->elementos[pos]=num;

        }
    }
}

void intercalar_lista (LISTA l, LISTA l2, LISTA *l3)
{
    int i;
    int total;
    int cont1 = 0, cont2 = 0;

    if (vazia(l) || vazia(l2))
    {
        printf("Uma ou ambas listas estão vazias\n");
    }
    else
    {
        total = l.n + l2.n + 2;  

        if (total >= TF)
        {
            printf("Os elementos de Lista 1 e Lista 2 combinados não cabem em uma única lista\n");  
        }
        else
        {
            inicializar(l3);

            for (i = 0; i < total - 2; i++)  
            {
                if (i % 2 == 0 && cont1 <= l.n)
                {
                    l3->elementos[i] = l.elementos[cont1];
                    cont1++;
                }
                else if (cont2 <= l2.n)
                {
                    l3->elementos[i] = l2.elementos[cont2];
                    cont2++;
                }
            }
            l3->n = total - 2;  
        }
    }
}

void exibir_lista(LISTA l)
{
    int i;
    if (vazia(l))
    {
        printf ("Lista vazia\n");
    }
    else
    {
        printf ("\n");
        for (i=0;i<=l.n;i++)
        {
            printf ("[%d] ", l.elementos[i]);
        }
        printf ("\n");
    }
}

int menu ()
{
    int op;
    printf ("Menu: \n");
    printf ("1. Inserir lista 1 inicio\n");
    printf ("2. Inserir lista 2 inicio");
    printf ("3. Inserir lista 1 fim\n");
    printf ("4. Inserir 2 fim\n");
    printf ("5. Inserir lista 1 pos\n");
    printf ("6. Inserir lista 2 pos\n");
    printf ("7. Intercalar Listas em Lista 3\n");
    printf ("8. Exibir lista 1\n");
    printf ("9. Exibir lista 2\n");
    printf ("10. Exibir lista 3\n");
    printf ("0. Encerrar Programa\n");
    scanf ("%d", &op);
    return op;
}

int main()
{
    LISTA lista1, lista2, lista3;
    int op, num, pos;

    inicializar(&lista1);
    inicializar (&lista2);

    do
    {
        op=menu();

        switch (op)
        {
            case 1:
            printf ("Insira número: ");
            scanf ("%d", &num);
            inserir_inicio(&lista1, num);
            break;

            case 2:

            printf ("Insira número: ");
            scanf ("%d", &num);
            inserir_inicio(&lista2, num);
            break;

            case 3:

            printf ("Insira número: ");
            scanf ("%d", &num);
            inserir_fim(&lista1, num);
            break;

            case 4:


            printf ("Insira número: ");
            scanf ("%d", &num);
            inserir_fim(&lista2, num);
            break;

            case 5:


            printf ("Insira número: ");
            scanf ("%d", &num);
            inserir_posicao(&lista1, num, pos);
            break;
            
            



        }




    }while(op!=0);
}




