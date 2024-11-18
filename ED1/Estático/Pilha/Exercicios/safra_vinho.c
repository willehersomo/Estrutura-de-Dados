#include <stdio.h>
#include <string.h>
#define TF 15

/*
C1. Imagine um colecionador de vinhos que compra
vinhos recentes e guarda-os em uma adega para
envelhecerem, e que a cada ocasião especial abre sempre
sua última aquisição (para poupar os mais antigos).
Construa um programa que:
a) Permita incluir novos vinhos na adega
b) Informe qual vinho deve ser aberto em uma ocasião
especial
c) Relacione as cinco aquisições mais antigas
As informações básicas que o registro do vinho deve
conter são: nome do produto e safra.
*/

typedef struct sVinho
{
    char nome_produto[50];
    int safra;
} VINHO;

typedef struct Spilha
{
    VINHO elementos[TF];
    int topo;
} PILHA;

void inicializar(PILHA *p)
{
    p->topo = -1;
}

int cheia(PILHA p)
{
    if (p.topo == TF - 1)
        return 1;
    return 0;
}

int vazia(PILHA p)
{
    if (p.topo == -1)
        return 1;

    return 0;
}

void empilhar(PILHA *p, char nome_produto[], int safra)
{
    if (cheia(*p))
    {
        printf("Safra cheia\n");
    }
    else
    {
        p->topo++;
        strcpy(p->elementos[p->topo].nome_produto, nome_produto);
        p->elementos[p->topo].safra = safra;
    }
}

VINHO desempilhar(PILHA *p)
{
    if (vazia(*p))
    {
        printf("Adega Vazia\n");
    }
    else
    {
        return p->elementos[(p->topo)--];
    }
}

VINHO ocasiao(PILHA p)
{
    return desempilhar(&p);
}

void aquisicoes_antigas(PILHA p)
{
    PILHA auxiliar;
    VINHO info_vinho;
    int i = 0;

    if (vazia(p))
    {
        printf("Safra Vazia\n");
    }
    else
    {
        auxiliar.topo = -1;
        while (!vazia(p))
        {
            info_vinho = desempilhar(&p);
            empilhar(&auxiliar, info_vinho.nome_produto, info_vinho.safra);
        }

        while (!vazia(auxiliar) && i < 5)
        {
            printf("\n");
            info_vinho = desempilhar(&auxiliar);
            printf("Nome %s\n", info_vinho.nome_produto);
            printf("Safra: %d\n", info_vinho.safra);
            printf("\n");
            i++;
        }
    }
}

int menu()
{
    int op;
    printf("Menu: \n");
    printf("1. Incluir vinho na adega\n");
    printf("2. Vinho a ser usado em ocasiãoe especial\n");
    printf("3. Apresentar aquisições mais antigas\n");
    printf("0. Sair\n");
    printf("Escolha: ");
    scanf("%d", &op);
    return op;
}

int main()
{
    PILHA pilha;
    VINHO vinho_info;
    char nome[50];
    int safra;
    int op;

    inicializar(&pilha);
    do
    {

        op = menu();
        switch (op)
        {
        case 1:
            printf("Digite o nome do produto: ");
            scanf(" %[^\n]", nome);
            printf("Digite o ano da safra: ");
            scanf("%d", &safra);
            empilhar(&pilha, nome, safra);
            break;

        case 2:
            vinho_info = ocasiao(pilha);
            printf("\n");
            printf("Vinho: %s\n", vinho_info.nome_produto);
            printf("Safra: %d\n", vinho_info.safra);
            printf("\n");
            break;

        case 3:
            aquisicoes_antigas(pilha);
            break;

        case 0:
            printf("Encerrando programa\n");
            break;

        default:
            printf("Opção inválida\n");
            break;
        }

    } while (op != 0);

    return 0;
}
