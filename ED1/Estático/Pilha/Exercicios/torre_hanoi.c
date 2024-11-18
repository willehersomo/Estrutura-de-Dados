#include <stdio.h>
#include <math.h>

/*
2. O problema das Torres de Hanói é bastante estudado em computação.
O problema consiste em n discos de diferentes diâmetros e três estacas: A, B e C.
Inicialmente os discos estão encaixados na estaca A onde o menor está sempre encima do maior disco.
O objetivo é deslocar os discos para uma estaca C, usando a estaca B como p2iliar.
Somente o primeiro disco de toda estaca pode ser deslocado. Isso para nós dá a idéia de pilhas.
Portanto construa a resolução desse exercício usando pilhas e para n = 4, ou seja, para 04 discos.
*/

typedef struct sPilha
{
    int elemento[4];
    int topo;
} PILHA;

void inicializar_e1(PILHA *p)
{
    p->elemento[0] = 4;
    p->elemento[1] = 3;
    p->elemento[2] = 2;
    p->elemento[3] = 1;
    p->topo = 3;
}

void inicializar(PILHA *p)
{
    p->topo = -1;
}

int cheia(PILHA p)
{
    if (p.topo == 3)
        return 1;

    return 0;
}

int vazia(PILHA p)
{
    if (p.topo == -1)
        return 1;

    return 0;
}

void empilhar(PILHA *p, int x)
{
    if (cheia(*p))
    {
        printf("Cheio");
    }
    else
    {
        p->topo++;
        p->elemento[p->topo] = x;
    }
}

int desempilhar(PILHA *p)
{
    if (vazia(*p))
    {
        printf("Vazia\n");
    }
    else
    {
        return p->elemento[p->topo--];
    }

    return -1;
}

void mover_disco(PILHA *p, PILHA *p3, char p_nome, char p3_nome)
{
    int topo_p = desempilhar(p);
    int topo_p3 = desempilhar(p3);

    if (topo_p == -1)
    {
        empilhar(p, topo_p3);
        printf("Mover disco %d de %c para %c\n", topo_p3, p3_nome, p_nome);
    }
    else if (topo_p3 == -1)
    {
        empilhar(p3, topo_p);
        printf("Mover disco %d de %c para %c\n", topo_p, p_nome, p3_nome);
    }
    else if (topo_p > topo_p3)
    {
        empilhar(p, topo_p);
        empilhar(p, topo_p3);
        printf("Mover disco %d de %c para %c\n", topo_p3, p3_nome, p_nome);
    }
    else
    {
        empilhar(p3, topo_p3);
        empilhar(p3, topo_p);
        printf("Mover disco %d de %c para %c\n", topo_p, p_nome, p3_nome);
    }
}

int calcular_potencia(int n)
{
    int resultado = 1;
    int i;
    for (i = 0; i < n; i++)
    {
        resultado *= 2;
    }
    return resultado - 1;
}

void processo(int n, PILHA *p, PILHA *p2, PILHA *p3)
{
    int i;
    int total_movimentos = calcular_potencia(n);
    char nomes[] = {'A', 'B', 'C'};

    for (i = 1; i <= total_movimentos; i++)
    {
        if (n % 2 != 0)
        {
            if (i % 3 == 1)
            {
                mover_disco(p, p3, nomes[0], nomes[2]); // Mover entre A e C
            }
            else if (i % 3 == 2)
            {
                mover_disco(p, p2, nomes[0], nomes[1]); // Mover entre A e B
            }
            else
            {
                mover_disco(p2, p3, nomes[1], nomes[2]); // Mover entre B e C
            }
        }
        else
        {
            if (i % 3 == 1)
            {
                mover_disco(p, p2, nomes[0], nomes[1]); // Mover entre A e B
            }
            else if (i % 3 == 2)
            {
                mover_disco(p, p3, nomes[0], nomes[2]); // Mover entre A e C
            }
            else
            {
                mover_disco(p2, p3, nomes[1], nomes[2]); // Mover entre B e C
            }
        }
    }
}

void mostrar_pilha(PILHA p)
{
    PILHA p2;
    inicializar(&p2);
    while (!vazia(p))
    {
        printf("[%d]\n", p.elemento[p.topo]);
        empilhar(&p2, desempilhar(&p));
    }
    while (!vazia(p2))
    {

        empilhar(&p, desempilhar(&p2));
    }
}

int main()
{
    PILHA e1;
    PILHA e2;
    PILHA e3;

    inicializar_e1(&e1);
    inicializar(&e2);
    inicializar(&e3);

    processo(4, &e1, &e2, &e3);
    mostrar_pilha(e3);

    return 0;
}
