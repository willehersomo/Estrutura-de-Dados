#include <stdio.h>
#include <stdlib.h>

typedef struct sNo {
    int info;
    struct sNo *esquerda;
    struct sNo *direita;
} NO;

NO* getnode() {
    return (NO*) malloc(sizeof(NO));
}

 NO* inserir(NO* raiz, int valor) {
    if (raiz == NULL) {
        NO* novo_no = getnode();
        novo_no->info = valor;
        novo_no->esquerda = NULL;
        novo_no->direita = NULL;
        return novo_no;
    }

    if (valor < raiz->info) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else if (valor > raiz->info) {
        raiz->direita = inserir(raiz->direita, valor);
    }

    return raiz;
}

 NO* pesquisar(NO* raiz, int valor) {
    if (raiz == NULL || raiz->info == valor) {
        return raiz;
    }

    if (valor < raiz->info) {
        return pesquisar(raiz->esquerda, valor);
    } else {
        return pesquisar(raiz->direita, valor);
    }
}

 NO* encontrar_minimo(NO* raiz) {
    while (raiz && raiz->esquerda != NULL) {
        raiz = raiz->esquerda;
    }
    return raiz;
}

 NO* remover(NO* raiz, int valor) {
    if (raiz == NULL) {
        return raiz;
    }

    if (valor < raiz->info) {
        raiz->esquerda = remover(raiz->esquerda, valor);
    } else if (valor > raiz->info) {
        raiz->direita = remover(raiz->direita, valor);
    } else {
        // Caso 1: Nó sem filhos
        if (raiz->esquerda == NULL && raiz->direita == NULL) {
            free(raiz);
            return NULL;
        }
        // Caso 2: Nó com um filho
        else if (raiz->esquerda == NULL) {
            NO* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            NO* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        // Caso 3: Nó com dois filhos
        else {
            NO* temp = encontrar_minimo(raiz->direita); // ou find_maximo(raiz->esquerda)
            raiz->info = temp->info;  // Substitui o valor do nó por seu sucessor in-order
            raiz->direita = remover(raiz->direita, temp->info);  // Remove o sucessor
        }
    }
    return raiz;
}

 void pre_ordem(NO* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->info);
        pre_ordem(raiz->esquerda);
        pre_ordem(raiz->direita);
    }
}

 void em_ordem(NO* raiz) {
    if (raiz != NULL) {
        em_ordem(raiz->esquerda);
        printf("%d ", raiz->info);
        em_ordem(raiz->direita);
    }
}

 void pos_ordem(NO* raiz) {
    if (raiz != NULL) {
        pos_ordem(raiz->esquerda);
        pos_ordem(raiz->direita);
        printf("%d ", raiz->info);
    }
}

 int contar_nos(NO* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    return 1 + contar_nos(raiz->esquerda) + contar_nos(raiz->direita);
}

 int contar_folhas(NO* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    if (raiz->esquerda == NULL && raiz->direita == NULL) {
        return 1;
    }
    return contar_folhas(raiz->esquerda) + contar_folhas(raiz->direita);
}

 int calcular_altura(NO* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    int altura_esquerda = calcular_altura(raiz->esquerda);
    int altura_direita = calcular_altura(raiz->direita);
    return (altura_esquerda > altura_direita ? altura_esquerda : altura_direita) + 1;
}

int menu() {
    int op;
    printf("\nMenu:\n");
    printf("1. Inserir um nó\n");
    printf("2. Exibir árvore em Pré-Ordem\n");
    printf("3. Exibir árvore em Em-Ordem\n");
    printf("4. Exibir árvore em Pós-Ordem\n");
    printf("5. Calcular número de nós\n");
    printf("6. Calcular número de folhas\n");
    printf("7. Calcular altura da árvore\n");
    printf("8. Pesquisar um valor\n");
    printf("9. Remover um nó\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &op);
    return op;
}

int main() {
    NO* raiz = NULL;
    int op, valor;

    do {
        op = menu();

        switch(op) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                raiz = inserir(raiz, valor);
                break;
            case 2:
                printf("Árvore em Pré-Ordem: ");
                pre_ordem(raiz);
                printf("\n");
                break;
            case 3:
                printf("Árvore em Em-Ordem: ");
                em_ordem(raiz);
                printf("\n");
                break;
            case 4:
                printf("Árvore em Pós-Ordem: ");
                pos_ordem(raiz);
                printf("\n");
                break;
            case 5:
                printf("Número de nós: %d\n", contar_nos(raiz));
                break;
            case 6:
                printf("Número de folhas: %d\n", contar_folhas(raiz));
                break;
            case 7:
                printf("Altura da árvore: %d\n", calcular_altura(raiz));
                break;
            case 8:
                printf("Digite o valor a ser pesquisado: ");
                scanf("%d", &valor);
                NO* no_pesquisado = pesquisar(raiz, valor);
                if (no_pesquisado != NULL) {
                    printf("Valor %d encontrado na árvore.\n", valor);
                } else {
                    printf("Valor %d não encontrado.\n", valor);
                }
                break;
            case 9:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &valor);
                raiz = remover(raiz, valor);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (op != 0);

    return 0;
}
