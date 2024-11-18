#include <stdio.h>
#include <string.h>
#define TF 10

typedef struct sPilha
{
    char elementos[TF];
    int topo;

} PILHA;

void inicializar(PILHA *p)
{
    p->topo = -1;
}

int cheio(PILHA p)
{
    return p.topo == TF - 1;
}

int vazio(PILHA p)
{
    return p.topo == -1;
}

void empilhar(PILHA *p, char c)
{
    if (cheio(*p))
    {
        printf("Pilha Cheia\n");
    }
    else
    {
        p->elementos[++p->topo] = c;
    }
}

char desempilhar(PILHA *p)
{
    if (vazio(*p))
    {
        printf("Pilha Vazia\n");
    }
    else
    {
        return p->elementos[p->topo--];
    }
}

void exibir_pilha(PILHA p)
{
    if (vazio(p))
    {
        printf("Pilha Vazia\n");
    }
    else
    {
        printf("Pilha do topo pra base\n");
        while (!vazio(p))
        {
            printf("[%c]\n", desempilhar(&p));
        }
        printf("\n");
    }
}

void ler_vetor(char vetor[])
{
    scanf(" %[^\n]", vetor);
}

void inserir_palavra_pilha(PILHA *p, char vetor[])
{
    int i;
    int cont = -1;
    int tamanho = strlen(vetor);
    printf("%d", tamanho);
    for (i = 0; i < tamanho; i++)
    {
        empilhar(p, vetor[i]);
        cont++;
    }

    p->topo = cont;
}

int identificar_palindro(PILHA p)
{
    PILHA auxiliar;
    PILHA auxiliar2;
    inicializar(&auxiliar);
    inicializar(&auxiliar2);
    char a;
    int inicio = p.topo;
    int cont = -1;

    if (vazio(p))
    {
        return 0;
    }
    else
    {
        while (!(vazio(p)))
        {
            a = desempilhar(&p);
            empilhar(&auxiliar, a);
            empilhar(&auxiliar2, a);
        }

        while (!(vazio(auxiliar2)))
        {
            empilhar(&p, desempilhar(&auxiliar2));
        }

        while (!(vazio(p)) && !(vazio(auxiliar)))
        {
            if (desempilhar(&p) == desempilhar(&auxiliar))
            {
                cont++;
            }
        }

        if (cont == inicio)
        {
            return 1;
        }

        return 0;
    }
}

int menu()
{
    int op;
    printf("Menu \n");
    printf("1. Ler vetor e introduzir na pilha\n");
    printf("2. Exibir Pilha\n");
    printf("3. Identifica Palindromo\n");
    scanf("%d", &op);
    return op;
}

int main()
{
    PILHA p;
    int op;
    char vet[10];
    inicializar(&p);

    do
    {
        op = menu();
        switch (op)
        {
        case 1:
            printf("Insira palavra: ");
            ler_vetor(vet);
            inserir_palavra_pilha(&p, vet);
            break;

        case 2:
            exibir_pilha(p);
            break;

        case 3:
            if (!identificar_palindro(p))
            {
                printf("Não é Palíndromo\n");
            }
            else
            {
                printf("É Palindromo\n");
            }
            break;
        }

    } while (op != 0);
}