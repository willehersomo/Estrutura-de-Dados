#include <stdio.h>
#include <stdlib.h>

/*2. Desenvolva um programa em Linguagem C que permita ao usuário inserir em ordem
decrescente elementos do tipo char em uma lista linear simplesmente encadeada.
Desenvolva uma função para a operação de inserção.*/


typedef struct sLista {
    char elemento;
    struct sLista *next;
} LISTA;

LISTA *inicializar(LISTA *l) {
    return NULL;
}

LISTA *getnode() {
    return (LISTA *)malloc(sizeof(LISTA));
}

int vazio(LISTA *l) {
    return (l == NULL);
}

void inserir_ordenado(LISTA **l, char elemento) {
    LISTA *aux;
    LISTA *q = getnode();

    if (q == NULL) {
        printf("Falha ao alocar espaço\n");
    } else {
        q->elemento = elemento;
        q->next = NULL;

        if (*l == NULL || (*l)->elemento < elemento) {
            q->next = *l;
            *l = q;
        } else {
            aux = *l;
            while (aux->next != NULL && aux->next->elemento > elemento) {
                aux = aux->next;
            }
            q->next = aux->next;
            aux->next = q;
        }
    }
}

void remover_lista(LISTA **l, char c) {
    if (vazio(*l)) {
        printf("Lista Vazia\n");
    } else {
        LISTA *aux = *l;
        LISTA *anterior = NULL;

        while (aux != NULL && aux->elemento != c) {
            anterior = aux;
            aux = aux->next;
        }

        if (aux == NULL) {
            printf("Elemento %c não encontrado na lista\n", c);
        } else {
            if (anterior == NULL) {
                *l = aux->next;
            } else {
                anterior->next = aux->next;
            }
            free(aux);
        }
    }
}

void exibir_lista(LISTA *l) {
    if (vazio(l)) {
        printf("Lista Vazia\n");
    } else {
        LISTA *aux = l;
        printf("Lista em ordem decrescente: ");
        while (aux != NULL) {
            printf("[%c] ", aux->elemento);
            aux = aux->next;
        }
        printf("\n\n");
    }
}

int menu() {
    int op;
    printf("\nMenu\n");
    printf("1. Inserir elemento\n");
    printf("2. Remover elemento\n");
    printf("3. Exibir Lista\n");
    printf("0. Encerrar programa\n");
    printf("Escolha uma opção: ");
    scanf("%d", &op);
    return op;
}

int main() {
    LISTA *lista = inicializar(lista);
    int op;
    char c;

    do {
        op = menu();
        switch (op) {
            case 1:
                printf("Digite o elemento a ser inserido: ");
                scanf(" %c", &c);
                inserir_ordenado(&lista, c);
                break;

            case 2:
                printf("Digite o elemento que será eliminado (o primeiro a ser encontrado será retirado da lista): ");
                scanf(" %c", &c);
                remover_lista(&lista, c);
                break;

            case 3:
                exibir_lista(lista);
                break;

            case 0:
                printf("Encerrando\n");
                break;

            default:
                printf("Opção Inválida\n");
                break;
        }
    } while (op != 0);

    return 0;
}
