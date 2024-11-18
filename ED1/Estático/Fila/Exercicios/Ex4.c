#include <stdio.h>
#include <locale.h>
#include <stdio.h>

#define TF 10

typedef struct FILA{
    int elemento [TF];
    int inicio;
    int fim;

}FILA;

typedef struct PILHA{
    int itens [TF];
    int topo;
}PILHA;

void inicializar_pilha (PILHA *p)
{
    (*p).topo= -1;
}

int pilha_vazia(PILHA p)
{
    int val=0;
    if (p.topo==-1)
    {
        val=1;
    }
    return val;
}

int pilha_cheia(PILHA p)
{
    int val=0;
    if(p.topo==TF-1)
    {
        val=1;
    }
    return val;
}

void push (PILHA *p, int x) //colocar
{
    if (pilha_cheia(*p))
    {
        printf ("Pilha cheia\n");

    }
    else{
        ++(*p).topo;
        (*p).itens[(*p).topo]=x;
    }

}

int pop (PILHA *p)
{
    int retorno = -1;

    if(pilha_vazia(*p))
    {
        printf("Pilha vazia\n");
    }
    else
    {
        retorno = (*p).itens[(*p).topo];
        (*p).topo--;
    }
    return retorno;

}

void inicializar (FILA *f)
{
    (*f).fim=TF-1;
    (*f).inicio=TF-1;
    
}

int vazia (FILA f)
{
    int val =0;

    if (f.inicio==f.fim)
    {
        val=1;
    }

    return val;

}

int cheia(FILA f)
{
    int val=0;
    if((f.fim+1)%TF==f.inicio)
    {
        val=1;
    }

    return val;

}

void enfileirar (FILA *f, int x)
{
    if (cheia(*f))
    {
        printf ("Fila cheia\n");

    }
    else
    {
        (*f).fim=((*f).fim+1)%TF;
        (*f).elemento[(*f).fim]=x;
    }
}

int desenfileirar(FILA *f)
{
    int retorno = -1;
    if(vazia(*f))
    {
        printf ("Fila vazia\n");
    }
    else
    {
        (*f).inicio = ((*f).inicio+1)%TF;
        retorno=(*f).elemento[((*f).inicio)];
    }
    return retorno;
}

void exibir (FILA f)
{
    int auxiliar;
    if(vazia(f))
    {
        printf ("Fila vazia\n");
    }
    else
    {
        printf("Fila: ");
        auxiliar = ((f).inicio+1)%TF;
        while (auxiliar!=(f.fim+1)%TF)
        {
            printf ("%d ", f.elemento[auxiliar]);
            auxiliar = (auxiliar+1)%TF;

        }
        printf ("\n");

    }
}

void inverter_fila(FILA *f, PILHA *p) {
    if (vazia(*f)) 
    {
        printf("Fila vazia\n");
    } 
    else 
    {
        while (!vazia(*f)) 
        {
            push(p, desenfileirar(f));
        }

        while (!pilha_vazia(*p)) 
        {
            enfileirar(f, pop(p));
        }
    }
}




int menu ()
{
    setlocale(LC_ALL, "portuguese");
    int op;

    printf ("1. Enfileirar\n");
    printf ("2. Desenfileirar\n");
    printf ("3. Exibir\n");
    printf ("4. Inverter fila\n");
    printf ("0. Encerrar processo\n");
    printf ("Escolha a opção: ");
    scanf ("%d", &op);
    return op;
}

int main ()
{
    FILA f;
    PILHA p;
    int op, x;

    inicializar(&f);

    do
    {
        op = menu();

        switch (op)
        {
            case 1:
                printf ("Digite o valor a ser inserido: ");
                scanf ("%d", &x);
                enfileirar(&f, x);
                break;
            case 2:
                x = desenfileirar(&f);
                if (x!=-1)
                {
                printf ("Elemento que saiu da fila: %d\n", x);
                }
                break;
            case 3:
                exibir(f);
                break;
            
            case 4:
                inicializar_pilha(&p);
                inverter_fila(&f,&p);
                exibir(f);
                break;

            case 0:
                printf("\nEncerrando\n");
                break;
            default:
                printf("Opção inválida\n");
                break;
        }

    }while (op!=0);

    return 0;

}







 