#include <stdio.h>
#include <locale.h>

#define TF 100

typedef struct sLista
{
    int elemento[TF];
    int tamanho;
} LISTA;

void inicializar(LISTA *l)
{
    (*l).tamanho = -1;
}

int vazio(LISTA l)
{
    if (l.tamanho == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int cheio(LISTA l)
{
    if (l.tamanho == TF - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void tamanho(LISTA l)
{
    if (vazio(l))
    {
        printf("A lista está vazia\n");
    }
    else if (cheio(l))
    {
        printf("A lista está cheia, %d elementos, tamanho %d\n", TF, l.tamanho + 1);
    }
    else
    {
        printf("A lista tem %d elementos, tamanho %d\n", l.tamanho + 1, l.tamanho + 1);
    }
}

void modificar_elemento(LISTA *l, int elem, int pos)
{
    if (vazio(*l))
    {
        printf("Lista vazia!\n");
    }
    else
    {
        if (pos < 0 || pos > (*l).tamanho)
        {
            printf("Posição Inválida\n");
        }
        else
        {
            (*l).elemento[pos] = elem;
        }
    }
}

void acessar_elemento(LISTA l, int pos)
{
    if (vazio(l))
    {
        printf("Lista Vazia!!\n");
    }
    else
    {
        if (pos < 0 || pos > l.tamanho)
        {
            printf("Posição inválida\n");
        }
        else
        {
            printf("Elemento encontrado na posição %d: %d\n", pos, l.elemento[pos]);
        }
    }
}

void buscar_valor(LISTA l, int elem)
{
    int i;
    int encontrou = 0;
    int posicao = -1;

    if (vazio(l))
    {
        printf("Lista vazia!\n");
    }
    else
    {
        for (i = 0; i <= l.tamanho; i++)
        {
            if (l.elemento[i] == elem)
            {
                encontrou = 1;
                posicao = i;
                i = l.elemento+1;
            }
        }

        if (encontrou)
        {
            printf("Valor encontrado na posição %d\n", posicao);
        }
        else
        {
            printf("Valor não encontrado\n");
        }
    }
}

void remover_elemento(LISTA *l, int pos)
{
    int i;
    if (vazio(*l))
    {
        printf("Lista vazia\n");
    }
    else
    {
        if (pos < 0 || pos > (*l).tamanho)
        {
            printf("Posição inválida\n");
        }
        else
        {
            for (i = pos; i < (*l).tamanho; i++)
            {
                (*l).elemento[i] = (*l).elemento[i + 1];
            }
            (*l).tamanho--;
            printf("Elemento removido!\n");
        }
    }
}

void remover_inicio(LISTA *l)
{
    int i;
    if (vazio(*l))
    {
        printf("Lista vazia!\n");
    }
    else
    {
        for (i = 0; i < (*l).tamanho; i++)
        {
            (*l).elemento[i] = (*l).elemento[i + 1];
        }

        (*l).tamanho--;
    }
}

void remover_final(LISTA *l)
{
    if (vazio(*l))
    {
        printf("Lista vazia!\n");
    }
    else
    {
        (*l).tamanho--;
    }
}

void inverter_lista(LISTA *l)
{
    int i, aux;
    if (vazio(*l))
    {
        printf("Lista vazia!\n");
    }
    else
    {
        for (i = 0; i <= (*l).tamanho / 2; i++)
        {
            aux = (*l).elemento[i];
            (*l).elemento[i] = (*l).elemento[(*l).tamanho - i];
            (*l).elemento[(*l).tamanho - i] = aux;
        }
    }
}

void ordenar_lista(LISTA *l)
{
    int i, j, menor, pos, temp;

    if (vazio(*l))
    {
        printf("Lista vazia\n");
    }
    else
    {
        for (i = 0; i <= (*l).tamanho; i++)
        {
            menor = (*l).elemento[i];
            pos = i;

            for (j = i + 1; j <= (*l).tamanho; j++)
            {
                if ((*l).elemento[j] < menor)
                {
                    menor = (*l).elemento[j];
                    pos = j;
                }
            }

            temp = (*l).elemento[i];
            (*l).elemento[i] = (*l).elemento[pos];
            (*l).elemento[pos] = temp;
        }
    }
}

void concatenar_lista(LISTA *l, LISTA l2)
{
    int aux, i;
    if (vazio(*l) || vazio(l2))
    {
        printf("Uma das listas está vazia\n");
    }
    else
    {
        aux = (*l).tamanho;
        (*l).tamanho += l2.tamanho + 1;
        for (i = aux + 1; i <= (*l).tamanho; i++)
        {
            (*l).elemento[i] = l2.elemento[i - aux - 1];
        }
    }
}

void intercalar_lista(LISTA *l, LISTA l2)
{
    int aux, i, j;
    if (vazio(*l) || vazio(l2))
    {
        printf("Uma das listas está vazia\n");
    }
    else
    {
        (*l).tamanho += l2.tamanho + 1;
        aux = 0;
        for (i = 0; i <= (*l).tamanho; i++)
        {
            if (i % 2 == 0 && aux <= l2.tamanho)
            {
                for (j = (*l).tamanho; j > i; j--)
                {
                    (*l).elemento[j] = (*l).elemento[j - 1];
                }
                (*l).elemento[i] = l2.elemento[aux];
                aux++;
            }
        }
    }
}

void inserir_elemento(LISTA *l, int elem, int pos)
{
    int i;
    if (cheio(*l))
    {
        printf("Lista cheia!\n");
    }
    else
    {
        if (pos < 0 || pos > (*l).tamanho + 1)
        {
            printf("Posição Inválida!\n");
        }
        else
        {
            (*l).tamanho += 1;
            for (i = (*l).tamanho; i > pos; i--)
            {
                (*l).elemento[i] = (*l).elemento[i - 1];
            }

            (*l).elemento[pos] = elem;
        }
    }
}

void inserir_inicio(LISTA *l, int elem)
{
    int i;
    if (cheio(*l))
    {
        printf("Lista cheia!\n");
    }
    else
    {
        (*l).tamanho += 1;
        for (i = (*l).tamanho; i > 0; i--)
        {
            (*l).elemento[i] = (*l).elemento[i - 1];
        }
        (*l).elemento[0] = elem;
    }
}

void inserir_fim(LISTA *l, int elem)
{
    if (cheio(*l))
    {
        printf("Lista cheia!\n");
    }
    else
    {
        (*l).tamanho++;
        (*l).elemento[(*l).tamanho] = elem;
    }
}

void exibir_lista(LISTA l)
{
    int i;
    if (vazio(l))
    {
        printf("Lista vazia!\n");
    }
    else
    {
        for (i = 0; i <= l.tamanho; i++)
        {
            printf("[%d] ", l.elemento[i]);
        }
        printf("\n");
    }
}

void preencher_lista_auxiliar(LISTA *auxiliar)
{
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("Digite o elemento da posição %d da lista 2: ", i);
        scanf("%d", &(*auxiliar).elemento[i]);
    }
    (*auxiliar).tamanho = 9;
}

int menu_principal()
{
    int op;
    printf("Escolha a operação: \n");
    printf("1. Inserir elemento em uma posição especifica\n");
    printf("2. Inserir elemento no inicio\n");
    printf("3. Inserir elemento no final\n");
    printf("4. Remover elemento em uma posição especifica \n");
    printf("5. Remover elemento no inicio\n");
    printf("6. Remover elemento no final\n");
    printf("7. Modificar elemento\n");
    printf("8. Acessar elemento\n");
    printf("9. Buscar valor na lista\n");
    printf("10. Identificar tamanho da lista\n");
    printf("11. Inverter lista\n");
    printf("12. Exibir lista\n");
    printf("13. Ordenar lista\n");
    printf("14. Concatenar listas\n");
    printf("15. Intercalar listas\n");
    printf("0. SAIR\n");
    printf("Opção: ");
    scanf("%d", &op);
    return op;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    LISTA lista;
    LISTA auxiliar;
    int pos, elem, op;
    int sair = 1;

    inicializar(&lista);

    while (sair != 0)
    {
        op = menu_principal();

        switch (op)
        {
        case 1:
            printf("Digite a posição: ");
            scanf("%d", &pos);
            printf("Digite o elemento: ");
            scanf("%d", &elem);
            inserir_elemento(&lista, elem, pos);
            break;
        case 2:
            printf("Digite o elemento: ");
            scanf("%d", &elem);
            inserir_inicio(&lista, elem);
            break;
        case 3:
            printf("Digite o elemento: ");
            scanf("%d", &elem);
            inserir_fim(&lista, elem);
            break;
        case 4:
            printf("Digite a posição do elemento que você quer remover: ");
            scanf("%d", &pos);
            remover_elemento(&lista, pos);
            break;
        case 5:
            remover_inicio(&lista);
            break;
        case 6:
            remover_final(&lista);
            break;
        case 7:
            printf("Digite a posição do elemento que você quer modificar: ");
            scanf("%d", &pos);
            printf("Digite o novo valor do elemento: ");
            scanf("%d", &elem);
            modificar_elemento(&lista, elem, pos);
            break;
        case 8:
            printf("Digite a posição do elemento que você quer acessar: ");
            scanf("%d", &pos);
            acessar_elemento(lista, pos);
            break;
        case 9:
            printf("Digite o elemento que você quer buscar: ");
            scanf("%d", &elem);
            buscar_valor(lista, elem);
            break;
        case 10:
            tamanho(lista);
            break;
        case 11:
            inverter_lista(&lista);
            break;
        case 12:
            exibir_lista(lista);
            break;
        case 13:
            ordenar_lista(&lista);
            break;
        case 14:
            preencher_lista_auxiliar(&auxiliar);
            concatenar_lista(&lista, auxiliar);
            break;
        case 15:
            preencher_lista_auxiliar(&auxiliar);
            intercalar_lista(&lista, auxiliar);
            break;
        case 0:
            sair = 0;
            break;
        default:
            printf("Opção inválida\n");
            break;
        }
    }

    return 0;
}