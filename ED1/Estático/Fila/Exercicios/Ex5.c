#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TF 10

typedef struct FILA{
    int elementos [TF];
    int fim;
    int inicio;
}FILA;

void inicializar(FILA *f)
{
    (*f).inicio=TF-1;
    (*f).fim=TF-1;

}

int vazia (FILA f)
{
    int val=0;

    if(f.inicio==f.fim)
    {
        val=1;
    }

    return val;
}

int cheia (FILA f)
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
    if(cheia(*f))
    {
        printf("Filha cheia\n");

    }
    else
    {
        (*f).fim=((*f).fim+1)%TF;
        (*f).elementos[(*f).fim]=x;
    }

}

int desenfileirar (FILA *f)
{
    int retorno=-1;
    if(vazia(*f))
    {
        printf("Fila Vazia\n");

    }
    else
    {   
        (*f).inicio=((*f).inicio+1)%TF;
        retorno=(*f).elementos[(*f).inicio];

    }
    return retorno;
}

void exibir (FILA f)
{   int auxiliar;
    if (cheia(f))
    {
        printf ("Fila vazia\n");
    }
    else
    {
        printf("Fila: ");
        auxiliar = ((f).inicio+1)%TF;
        while (auxiliar!=(f.fim+1)%TF)
        {
            printf ("%d ", f.elementos[auxiliar]);
            auxiliar = (auxiliar+1)%TF;
        }
        printf ("\n");

    }
}

int contar_elementos (FILA f)
{
    int contador=0;
    int auxiliar;
    if (vazia(f))
    {
        printf ("Fila vazia\n");

    }
    else
    {
        auxiliar = (f.inicio+1)%TF;
        while (auxiliar!= (f.fim+1)%TF)
        {
            contador++;
            auxiliar=(auxiliar+1)%TF;

        }

    }
    return contador;

}

void fila_maior (FILA f, FILA f2)
{
    int contador_um, contador_dois;
    if (vazia(f)&&vazia(f2))
    {
       printf ("Filas vazias\n");
    }
    else
    {
        contador_um = contar_elementos(f);
        contador_dois = contar_elementos(f2);

        if(contador_um>contador_dois)
        {
            printf ("Fila 1 é maior\n"); 
        }
        else if(contador_dois>contador_um)
        {
            printf ("Fila 2 é maior\n");
        }
        else
        {
            printf ("Ambas as filas tem o mesmo tamanho\n");

        }
    }
}

int menu ()
{
    setlocale(LC_ALL, "portuguese");
    int op;

    printf ("1. Enfileirar fila 1\n");
    printf ("2. Enfileirar fila 2\n");
    printf ("3. Desenfileirar fila 1\n");
    printf ("4. Desenfileirar fila 2\n");
    printf ("5. Exibir fila 1\n");
    printf ("6. Exibir fila 2\n");
    printf ("7. Encontrar maior fila\n");
    printf ("0. Encerrar processo\n");
    printf ("Escolha a opção: ");
    scanf ("%d", &op);
    return op;
}

int main ()
{
    FILA f, f2;
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
                printf ("Digite o valor a ser inserido: ");
                scanf ("%d", &x);
                enfileirar(&f2, x);
                break;

            case 3:
                x = desenfileirar(&f);
                if (x!=-1)
                {
                printf ("Elemento que saiu da fila: %d\n", x);
                }
                break;

            case 4:
                x = desenfileirar(&f2);
                if (x!=-1)
                {
                printf ("Elemento que saiu da fila: %d\n", x);
                }
                break;

            case 5:
                exibir(f);
                break;

            case 6:
                exibir(f2);
                break;
            
            case 7:
                fila_maior(f,f2);
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







 