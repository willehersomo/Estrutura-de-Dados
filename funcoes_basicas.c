#include <stdio.h>
#include <stdlib.h>

typedef struct sLista
{
    int info;
    struct sLista *next;

} LISTA;

LISTA *get_node()
{
    return (LISTA *)malloc(sizeof(LISTA));
}

LISTA *inicializar(LISTA *l)
{
    l = NULL;
    return l;
}

int vazio(LISTA *l)
{
    return l == NULL;
}

void remover_fim(LISTA **l)
{
    LISTA *aux;
    LISTA *q;

    if (!vazio(*l))
    {
        aux = (*l);
        // l = 1->2->3->4->NULL
        // aux -> l (1)

        if (aux->next == NULL)
        {
            // Se apenas l = 1->NULL
            // Aux apontou para 1
            // Libera a referencia para 1

            free(aux);
            *l = NULL;
        }
        else
        {

            while (aux->next->next != NULL)
            {
                // Primeira iteração
                // aux ->2->3(while)
                // aux -> 2

                // Segunda Iteração
                // aux->3->4(while)
                // aux ->3

                // Terceira Iteração
                // aux->4->NULL
                // Parou a Iteração

                aux = aux->next;
            }

            // aux->3 (->4)
            // q->4 (->NULL)
            // Libera Q
            q = aux->next;
            aux->next = NULL;
            free(q);

            // l= 1->2->3->NULL (Se liberou a referencia de next, então ele vira NULL
        }
    }
    else
    {
        printf("Lista Vazia\n");
    }
}

void remover_inicio(LISTA **l)
{
    LISTA *q;

    if (!vazio(*l))
    {
        // l = 1->2->3->4
        // q->l (1)

        // lista apontava para 1 inicialmente.
        // Agora aponta para 2->3->4
        // q guarda a referencia para 1 (primeiro elemento)
        // Então libera a referencia para 1(free)

        q = (*l);
        (*l) = (*l)->next;
        free(q);
    }
    else
    {
        printf("Lista Vazia\n");
    }
}

void inserir_inicio(LISTA **l, int x)
{
    LISTA *q;

    q = get_node();

    // cria um nó Q que aponta para o endereço de nova alocação

    if (q == NULL)
    {
        printf("Erro ao alocar elemento\n");
    }
    else
    {
        // l = 1 -> 2 -> 3 -> NULL
        // Supondo que eu queira adicionar 4 na lista
        // Minha info de Q recebe 4 e eu faço meu next de q apontar para null
        // q = 4 -> NULL,
        // Se quero inserir no incio, tenho que fazer o restante 4 apontar para o restante da minha lista
        // q= 4-> l
        // q= 4->1->2->3->NULL
        // Agora tenho que fazer l apontar para o começo da lista (referencia em q)
        //  l -> 4 -> resto da lista

        q->info = x;
        q->next = *l;
        *l = q;
    }
}

void inserir_fim(LISTA **l, int x)
{
    LISTA *aux;
    LISTA *q;

    q = get_node();

    // cria um nó e um auxiliar que vai servir para percorrer minha lista sem que eu perca a referência da
    // minha lista

    if (q == NULL)
    {
        printf("Erro ao alocar espaço\n");
    }
    else
    {
        q->info = x;
        q->next = NULL;
        // q.info =5

        if (vazio(*l))
        {
            // Se está vazio, apenas faço minha lista apontar para q
            //  l -> q
            //  l =-> 5 -> NULL (tornou-se inicio da minha lista)

            *l = q;
        }
        else
        {
            // Se há alguma coisa, eu tenho que verificar para que ele percorra até o ultimo elemento e eu
            // adicione faça esse ser o next
            // l= 1->2->3->4->NULL

            // Aux aponta para o começo da minha lista
            //  aux -> l -> 1

            aux = *l;
            while (aux->next != NULL)
            {
                // Percorro até o último elemento da minha lista

                // Primeira Iteração
                // aux->1->2(Next)
                // AUX -> 2

                // Segunda Iteração
                // Aux -> 2 ->3
                // Aux -> 3

                // Terceira Iteração
                // Aux -> 3 ->4
                // Aux -> 4

                // Quarta Iteração
                // Aux -> 4 -> NULL
                // Parou a Iteração

                aux = aux->next;
            }

            // AUX -> 4 -> NULL(Next)
            // Com meu nó Q tendo as informações que quero adcionar (Q -> 5 -> NULL)
            // Faço meu aux( que aponta para meu 5) Next apontar para onde está meu Q
            // Aux -> 4 -> Q
            // Aux -> 4 -> 5 -> NULL

            // Ainda tenho a referência inicial da minha lista
            //  l -> 1(primeiro elemento da lista)
            // l -> 1->2->3->4->5 (Lembra que fiz meu 4 apontar para meu elemento 5?) -> NULL
            aux->next = q;
        }
    }
}

void exibir_lista(LISTA *l)
{
    LISTA *aux;

    // A mesma ideia, não posso perder a referência do inicio da minha lista
    // Então crio um ponteiro auxiliar que irá apontar para o inicio da lista e com ele eu percorro

    if (!vazio(l))
    {
        aux = l;
        // l->1->2->3->4->5->Null
        // aux -> l
        while (aux != NULL)
        {
            // Apresento até o final real da minha lista

            // Primeira Iteração
            // aux -> 1 (apresenta)
            // aux= aux->next (vou para o próximo elemento)
            // aux->1->2
            // aux = 2->3 (aux atual é 2)

            // Segunda Iteração
            // aux -> 2(apresenta)
            // aux -> 3 (próximo)

            // Terceira Iteração
            // Aux -> 3 (apresenta)
            // Aux ->4(próximo)

            // Quarta Iteração
            // Aux -> 4 (Apresenta)
            // Aux -> 5 (Próximo)

            // Quinta Iteração
            // Aux -> 5 (Apresenta )
            // Aux -> NULL(Próximo)
            // Para Iteração

            printf("[%d] ", aux->info);
            aux = aux->next;
        }
        printf("\n");
    }
    else
    {
        printf("Vazio\n");
    }
}

void mover_pra_frente(LISTA **l, int valor)
{
    if (vazio(*l))
    {
        printf("Lista Vazia\n");
    }
    else
    {
        LISTA *aux;
        LISTA *aux2;
        aux = (*l);
        if (aux->next == NULL)
        {
            if (aux->info != valor)
            {
                printf("Elemento não está na lista\n");
            }
        }
        else
        {
            while (aux->next != NULL && aux->next->info != valor)
            {
                aux = aux->next;
            }

            if (aux->next->info == valor)
            {
                aux2 = aux->next;
                aux->next = aux->next->next;
                aux2->next = (*l);
                (*l) = aux2;
            }
            else
            {
                printf("Elemento não está na lista");
            }
        }
    }
}

void transposicao(LISTA **l, int valor)
{
    if (vazio(*l))
    {
        printf("Lista Vazia\n");
    }
    else
    {
        LISTA *aux = *l;
        LISTA *antes = NULL;
        LISTA *antes_antes = NULL;
        int encontrou = 0;

        while (aux != NULL && encontrou == 0)
        {
            if (aux->info == valor)
            {
                encontrou = 1;
            }
            else
            {
                antes_antes = antes;
                antes = aux;
                aux = aux->next;
            }
        }

        if (encontrou == 0)
        {
            printf("Valor inexistente na lista\n");
        }
        else
        {

            antes->next = aux->next;
            aux->next = antes;

            if (antes_antes != NULL)
            {
                antes_antes->next = aux;
            }
            else
            {
                *l = aux;
            }
        }
    }
}

void inserir_ordenado(LISTA **l, int valor)
{
    if (vazio(*l))
    {
        printf("Lista Vazia\n");
    }
    else
    {
        LISTA *aux;

        aux = (*l);

        if (aux->next == NULL)
        {
            inserir_inicio(l, valor);
        }
        else
        {
            while (aux->next != NULL && aux->next->info < valor)
            {
                aux = aux->next;
            }

            if (aux->next == NULL)
            {
                inserir_fim(l, valor);
            }
            else
            {
                LISTA *q = get_node();

                if (q == NULL)
                {
                    printf("Falha ao alocar espaço\n");
                }
                else
                {
                    q->info = valor;
                    q->next = aux->next;
                    aux->next = q;
                }
            }
        }
    }
}


int menu()
{
    int op;
    printf("Menu: \n");
    printf("1. Exibir Lista\n");
    printf("2. Inserir no Inicio\n");
    printf("3. Inserir no final\n");
    printf("4. Remover no inicio\n");
    printf("5. Remover no final\n");
    printf("6. Mover pra frente\n");
    printf("7. Transpor Elemento\n");
    printf("8. Inserir Ordenado\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &op);
    return op;
}

int main()
{
    LISTA *lista = inicializar(lista);
    int op;
    int x;

    do
    {
        op = menu();
        switch (op)
        {
        case 1:
            exibir_lista(lista);
            break;

        case 2:
            printf("Digite o número a inserir: ");
            scanf("%d", &x);
            inserir_inicio(&lista, x);
            break;

        case 3:
            printf("Digite o número a inserir: ");
            scanf("%d", &x);
            inserir_fim(&lista, x);
            break;

        case 4:
            remover_inicio(&lista);
            break;

        case 5:
            remover_fim(&lista);
            break;

        case 6:
            printf("Insira o elemento que deseja mover pra frente: ");
            scanf("%d", &x);
            mover_pra_frente(&lista, x);
            break;

        case 7:
            printf("Insira o elemento que deseja transpor: ");
            scanf("%d", &x);
            transposicao(&lista, x);
            break;

        case 8:
            printf("Insira o elemento a ser inserido: ");
            scanf("%d", &x);
            inserir_ordenado(&lista, x);
            break;

        case 0:
            printf("Saindo...\n");
            break;

        default:
            printf("Opção Inválida\n");
            break;
        }
    } while (op != 0);
    return 0;
}
