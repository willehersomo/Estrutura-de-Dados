#include <stdio.h>
#define TF 10

typedef struct sPilha
{
    char elementos[TF];
    int topo;
}PILHA;

void inicializar (PILHA *p)
{
    p->topo=-1;
}

int vazio(PILHA p)
{
    return p.topo==-1;
}

int cheio (PILHA p)
{
    return p.topo==TF-1;
}

void empilhar (PILHA *p, char c)
{
    if(cheio(*p))
    {
        printf ("Pilha Cheia\n");
    }
    else
    {
        p->elementos[++p->topo]=c;
    }
}

char desempilhar (PILHA *p)
{
    if(vazio(*p))
    {
        printf ("Pilha Vazia\n");
    }
    else
    {
        return p->elementos[p->topo--];
    }
}

void exibir_pilha(PILHA p)
{

    if(vazio(p))
    {
        printf ("Pilha Cheia\n");
    }
    else
    {
        printf ("Pilha (topo pra base): \n");
        while(!vazio(p))
        {
            printf("[%c]\n", desempilhar(&p));
        }
        printf ("\n");
    }
}

void trocar_base_topo (PILHA *p)
{
    PILHA auxiliar;
    inicializar(&auxiliar);
    char base, topo;
    if(vazio(*p))
    {
        printf("Pilha Vazia\n");
    }
    else
    {
       topo=desempilhar(p);
       while(!vazio(*p))
       {
        empilhar(&auxiliar, desempilhar(p));
       }
       base = desempilhar (&auxiliar);
       empilhar(p, topo);
       while(!vazio(auxiliar))
       {
        empilhar (p, desempilhar(&auxiliar));
       }
       empilhar(p, base);
    }
}

int menu()
{
    int op;
    printf ("Menu:\n");
    printf ("1. Empilhar\n");
    printf ("2. Desempilhar\n");
    printf ("3. Exibir pilhar\n");
    printf ("4. Troca topo pra base\n");
    printf ("0. Encerrar\n");
    scanf ("%d", &op);
    return op;
}

int main ()
{
    PILHA p;
    int op;
    char c;
    inicializar(&p);

    do{
        op=menu();
        
        switch (op)
        {
            case 1:
            printf ("Insira o caractere: \n");
            scanf (" %c", &c);
            empilhar(&p, c);
            break;

            case 2:
            printf ("Caractere desempilhado: %c\n\n", desempilhar(&p));
            break;

            case 3:
            exibir_pilha(p);
            break;

            case 4:
            trocar_base_topo(&p);
            break;
            
            case 0:
            printf ("Encerrando...\n");
            break;

            default:
            printf("Opção Inválida\n");
            break;

        }



    }while(op!=0);


    return 0;
}