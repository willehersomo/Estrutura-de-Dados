/*Marcos Paulo, como todo amante de filmes, sempre sonhou com uma televisão grande
para suas sessões de cinema no final de semana. A televisão que tinha em casa, 14 polegadas,
foi adquirida na época da faculdade e o acompanhou em várias etapas de
sua vida profissional: graduação, mestrado, primeiro emprego. Sem falar que, graças a
ela, ele se tornou fluente em inglês, pois as legendas pequenas eram difíceis de
acompanhar durante os filmes. Após passar em um concurso federal, ele recebeu de
presente dos pais uma televisão de 50 polegadas que o deixou bastante feliz e satisfeito.
Uma de suas manias ao assistir televisão é pegar o controle remoto e ficar pulando de
canal em canal sem, na verdade, assistir nenhum programa (mania esta que causava
bastante irritação na esposa). Desenvolva uma aplicação usando o conceito de lista
simplesmente encadeada circular que permita cadastrar os canais da operadora CTBC
de TV a cabo (ex: Fox, Megapix, Universal, GNT, SBT, etc) e ilustre a mania de Marcos
Paulo. Lembrando que o controle de Marcos Paulo veio com problemas e só permitia
que ele passasse os canais para frente, nunca para trás.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sTV
{
    char nome[50];
    int numero;
} TV;

typedef struct sLista
{
    TV tv;
    struct sLista *next;

} LISTA;

LISTA *getnode()
{
    return (LISTA *)malloc(sizeof(LISTA));
}

int vazio(LISTA * l)
{
    return l == NULL;
}

void inserir_inicio(LISTA **l, TV tv)
{
    LISTA *q = getnode();
    LISTA *aux;

    if (q == NULL)
    {
        printf("Falha ao alocar espaço\n");
    }
    else
    {
        strcpy(q->tv.nome, tv.nome);
        q->tv.numero = tv.numero;
        q->next = NULL;
        if (vazio(*l))
        {
            q->next = q;
            (*l) = q;
        }
        else
        {
            aux = *l;
            while (aux->next != *l)
            {
                aux = aux->next;
            }

            aux->next = q;
            q->next = *l;
            *l = q;
        }
    }
}

void inserir_fim(LISTA **l, TV tv)
{
    LISTA *q = getnode();
    LISTA *aux;

    if (q == NULL)
    {
        printf("Falha ao Alocar Espaço\n");
    }
    else
    {
        strcpy(q->tv.nome, tv.nome);
        if (vazio(*l))
        {
            (q)->next = (*l);
            (*l) = (q);
        }
        else
        {
            aux = (*l);
            while (aux->next != (*l))
            {
                aux = aux->next;
            }

            aux->next = q;
            q->next = (*l);
        }
    }
}

void remover_inicio(LISTA **l)
{
    if (vazio(*l))
    {
        printf("Lista vazia\n");
    }
    else
    {
        LISTA *aux = (*l);

        if ((aux)->next == (*l))
        {
            free(aux);
            *l = NULL;
        }
        else
        {
            LISTA *ultimo = aux;
            while (ultimo->next != *l)
            {
                ultimo = ultimo->next;
            }

            *l = aux->next;
            ultimo->next = *l;
            free(aux);
        }
    }
}

void remover_fim(LISTA **l)
{
    if (vazio(*l))
    {
        printf("Lista Vazia\n");
    }
    else
    {
        LISTA *anterior;
        LISTA *aux = (*l);

        if (aux->next == *l)
        {
            free(aux);
            *l = NULL;
        }
        while (aux->next != (*l))
        {
            anterior = aux;
            aux = aux->next;
        }

        anterior->next = (*l);
        free(aux);
    }
}

void exibir_lista(LISTA *l)
{
    if (vazio(l))
    {
        printf("Lista Vazia\n");
    }
    else
    {
        LISTA *aux = l;
        do
        {
            printf("Canal %d - %s\n", aux->tv.numero, aux->tv.nome);
            aux = aux->next;
        } while (aux != l);
        printf("\n\n");
    }
}

void passar_canal (LISTA ** controle, LISTA * l)
{
    if(vazio(l))
    {
        printf("Seu plano não tem canais\n");
    }
    else
    {
       (*controle) = (*controle)->next;
        printf("Canal %d - %s\n", (*controle)->tv.numero, (*controle)->tv.nome);

    }

}

TV informacao ()
{
    TV retorno;
    printf("Insira número do canal: ");
    scanf("%d", &retorno.numero);
    printf("Insira nome do canal: ");
    scanf(" %[^\n]", retorno.nome);
    return retorno;
} 

int menu()
{
    int op;
    printf("1. Cadastrar canal no começo da lista\n");
    printf("2. Cadastrar canal no final da lista\n");
    printf("3. Remover canal do inicio\n");
    printf("4. Remover canal do final\n");
    printf("5. Exibir lista de canais\n");
    printf("6. Passar canal\n");
    printf("0. Desligar TV\n");
    scanf("%d", &op);
    return op;
}

int main()
{
    LISTA *l = NULL;
    LISTA *controle = NULL; 
    TV tv;
    int op;

    do
    {
        op = menu();

        switch (op)
        {
            case 1:
                tv = informacao();
                inserir_inicio(&l, tv);
                if (controle == NULL) 
                {
                    controle = l;
                }
                break;

            case 2:
                tv = informacao();
                inserir_fim(&l, tv);
                if (controle == NULL) 
                {
                    controle = l;
                }
                break;

            case 3:
                remover_inicio(&l);
                if (vazio(l))
                {
                    controle = NULL; 
                }
                break;

            case 4:
                remover_fim(&l);
                if (vazio(l))
                {
                    controle = NULL;
                }
                break;

            case 5:
                exibir_lista(l);
                break;

            case 6:
                passar_canal(&controle, l);
                break;

            case 0:
                printf("Desligando TV\n");
                break;

            default:
                printf("Opção Inválida\n");
                break;
        }

    } while (op != 0);

    return 0;
}
