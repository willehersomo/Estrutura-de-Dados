#include <stdio.h>
#include <string.h>
#define TF 40

typedef struct sPassageiro
{
    char nome[50];
    int idade;

} PASSAGEIRO;

typedef struct sDeque
{
    PASSAGEIRO passageiro[TF];
    int fim, inicio;

} DEQUE;

void inicializar(DEQUE *d)
{
    d->fim = -1;
    d->inicio = -1;
}

int vazia(DEQUE d)
{
    return d.fim == -1 && d.inicio == -1;
}

int cheia(DEQUE d)
{
    return (d.fim + 1) % TF == d.inicio;
}

void enfileirar_inicio(DEQUE *d, PASSAGEIRO p)
{
    if (cheia(*d))
    {
        printf("Ônibus lotado\n");
    }
    else
    {
        if (vazia(*d))  
        {
            d->inicio = d->fim = 0;
        }
        else
        {
            d->inicio = (d->inicio - 1 + TF) % TF;
        }

        d->passageiro[d->inicio] = p;
    }
}

void enfileirar_fim(DEQUE *d, PASSAGEIRO p)
{
    if (cheia(*d))
    {
        printf("Ônibus Lotado\n");
    }
    else
    {
        if (vazia(*d))  
        {
            d->inicio = d->fim = 0;
        }
        else
        {
            d->fim = (d->fim + 1) % TF;
        }

        d->passageiro[d->fim] = p;
    }
}

PASSAGEIRO desenfileirar_inicio(DEQUE *d)
{
    PASSAGEIRO retorno = {"", 0};

    if (vazia(*d))
    {
        printf("Ônibus vazio\n");
        return retorno;
    }
    else
    {
        retorno = d->passageiro[d->inicio];
        if (d->inicio == d->fim)  
        {
            d->inicio = d->fim = -1;
        }
        else
        {
            d->inicio = (d->inicio + 1) % TF;
        }
        return retorno;
    }
}

PASSAGEIRO informar_passageiro()
{
    PASSAGEIRO retorno;
    printf("Insira o nome do passageiro: ");
    scanf(" %[^\n]", retorno.nome);
    printf("Insira idade do passageiro: ");
    scanf("%d", &retorno.idade);
    return retorno;
}

void inserir_passageiro(DEQUE *d, PASSAGEIRO p)
{
    if (p.idade >= 60)
    {
        enfileirar_inicio(d, p);
    }
    else
    {
        enfileirar_fim(d, p);
    }
}

void exibir_n_classica(DEQUE d)
{
    int auxiliar;
    if (vazia(d))
    {
        printf("Ônibus vazio\n");
    }
    else
    {
        printf("Passageiros: \n");
        auxiliar = d.inicio;
        while (auxiliar != (d.fim + 1) % TF)
        {
            printf("%s - ", d.passageiro[auxiliar].nome);
            printf("%d\n", d.passageiro[auxiliar].idade);
            auxiliar = (auxiliar + 1) % TF;
        }
        printf("\n");
    }
}

int menu()
{
    int op;
    printf("Menu\n");
    printf("1. Embarcar Passageiro\n");
    printf("2. Desembarcar Passageiro\n");
    printf("3. Exibir Passageiros (no ônibus)\n");
    printf("0. Encerrar\n");
    scanf("%d", &op);
    return op;
}

int main()
{
    PASSAGEIRO p;
    DEQUE d;
    int op;

    inicializar(&d); 

    do
    {
        op = menu();
        switch (op)
        {
        case 1:
            p = informar_passageiro();
            inserir_passageiro(&d, p);
            break;

        case 2:
            p = desenfileirar_inicio(&d);
            printf("Passageiro desembarcado: \n");
            printf("%s - ", p.nome);
            printf("%d\n", p.idade);
            break;

        case 3:
            exibir_n_classica(d);
            break;

        case 0:
            printf("Encerrando...\n");
            break;

        default:
            printf("Opção Inválida\n");
            break;
        }

    } while (op != 0);

    return 0;
}
