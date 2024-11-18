#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define TF 10

typedef struct FILA{
    int elementos[TF];
    int inicio;
    int fim;
}FILA;

void inicializar (FILA *f)
{
    (*f).fim = TF-1;
    (*f).inicio = TF-1;
}

int vazia (FILA f)
{
    int val =0;
    if (f.fim==f.inicio)
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
    if (cheia(*f))
    {
        printf ("Fila cheia\n");
    }
    else
    {
        (*f).fim=((*f).fim+1)%TF;
        (*f).elementos[(*f).fim]=x;
    }

}

int desenfileirar (FILA *f)
{
    int retorno = -1;
    if(vazia(*f))
    {
        printf("Fila vazia\n");
    }
    else
    {
        (*f).inicio = ((*f).inicio+1)%TF;
        retorno = (*f).elementos[(*f).inicio];
    }
    return retorno;
}

void exibir(FILA f)
{
    int auxiliar;
    if(vazia(f))
    {
        printf ("Fila vazia\n");
    }
    else
    {
        printf ("Fila: ");
        auxiliar = (f.inicio+1)%TF;
        while (auxiliar!=(f.fim+1)%TF)
        {
            printf ("%d ", f.elementos[auxiliar]);
            auxiliar = (auxiliar+1)%TF;

        }
        printf ("\n");
    }
}

float calcular_media(FILA f)
{
    int contador=0;
    int auxiliar;
    int soma=0;
    float media=0.0;
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
            soma+=f.elementos[auxiliar];
            auxiliar=(auxiliar+1)%TF;

        }

        media=(float)soma/contador;

    }
    return media;

}

int maior_fila(FILA f)
{
    int maior=-1;
    int auxiliar;
   
    if (vazia(f))
    {
        printf ("Fila vazia\n");

    }
    else
    {
        auxiliar = (f.inicio+1)%TF;
        maior = f.elementos[auxiliar];
        while (auxiliar!= (f.fim+1)%TF)
        {
           
            if (f.elementos[auxiliar]>maior)
            {
                maior=f.elementos[auxiliar];
            }

            auxiliar=(auxiliar+1)%TF;

        }


    }
    return maior;

}

int menor_fila(FILA f)
{
    int menor=-1;
    int auxiliar;
   
    if (vazia(f))
    {
        printf ("Fila vazia\n");

    }
    else
    {
        auxiliar = (f.inicio+1)%TF;
        menor = f.elementos[auxiliar];
        while (auxiliar!= (f.fim+1)%TF)
        {
           
            if (f.elementos[auxiliar]<menor)
            {
                menor=f.elementos[auxiliar];
            }

            auxiliar=(auxiliar+1)%TF;

        }


    }
    return menor;

}





int menu ()
{
    setlocale(LC_ALL, "portuguese");
    int op;

    printf ("1. Enfileirar\n");
    printf ("2. Desenfileirar\n");
    printf ("3. Exibir\n");
    printf ("4. Exibir maior\n");
    printf ("5. Exibir menor\n");
    printf ("6. Exibir média\n");
    printf ("0. Encerrar processo\n");
    printf ("Escolha a opção: ");
    scanf ("%d", &op);
    return op;
}

int main ()
{
    FILA f;
    int op, x;
    float y;

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
                x= maior_fila(f);
                if(x!=-1)
                {
                printf ("Maior elemento da fila: %d\n", x);
                }
                break;


            case 5:
                x= menor_fila(f);
                if(x!=-1)
                {
                printf ("Menor elemento da fila: %d\n", x);
                }
                break;

            case 6:
                y= calcular_media(f);
                printf ("Média aritmética dos elementos da fila: %.2f\n", y);
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







 