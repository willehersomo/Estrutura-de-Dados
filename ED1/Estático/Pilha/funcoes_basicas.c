#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define TF 10

typedef struct PILHA{
    int elementos[TF];
    int topo;

}PILHA;

void inicializar (PILHA *p)
{
    (*p).topo=-1;
}

int vazia(PILHA p)
{
    int val = 0;
    if(p.topo==-1)
    {
        val=-1;
    }
    return val;
}

int cheia (PILHA p)
{
    int val=0;
    if (p.topo==TF-1)
    {
        val=1;
    }
    return val;
}

void push (PILHA *p, int x)
{
    if(cheia(*p))
    {
        printf ("Pilha cheia\n");
    }
    else
    {
        ++(*p).topo;
        (*p).elementos[(*p).topo]=x;

    }
}

int pop (PILHA *p)
{
    int retorno = -1;
    
    if(vazia(*p))
    {
        printf ("Pilha vazia\n");
    }
    else
    {
        retorno = (*p).elementos[(*p).topo];
        (*p).topo--;
    }
    return retorno;
}

void exibir(PILHA p)
{
    
    if (vazia(p))
    {
        printf("Pilha Vazia\n");
    }
    else
    {
        PILHA auxiliar = p;  
        int x;
        printf("Pilha - Topo para base:\n");
        while (!vazia(auxiliar))
        {
            x = pop(&auxiliar); 
            printf("%d\n", x);
        }
        printf("\n");
    }
}


int menu ()
{
    int op;
    printf ("1. Empilhar\n");
    printf ("2. Desempilhar\n");
    printf ("3. Exibir\n");
    printf ("0. Encerrar Processo\n");
    scanf ("%d", &op);
    return op;
}

int main ()
{
    PILHA p;
    int op, x;


    inicializar(&p);

    do{
        op = menu();

        switch (op)
        {
            case 1: 
                printf ("Digite o elemento a ser inserido: ");
                scanf ("%d", &x);
                push(&p, x);
                break;
            case 2:
                 x = pop(&p);
                 if(x!=-1)
                 {
                    printf ("Item desempilhado: %d\n", x);
                 }
                break;
            case 3:
                exibir(p);
                break;

            case 0:
                printf ("Encerrando\n");
                break;

            default:
                printf ("Opção inválida\n");
                break;
        }
    }while(op!=0);
    return 0;

}