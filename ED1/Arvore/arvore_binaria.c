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
    } else if (valor >= raiz->info) {
        raiz->direita = inserir(raiz->direita, valor);
    }

    return raiz;
}

 void pre_ordem(NO* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->info);  // Visita a raiz
        pre_ordem(raiz->esquerda);   // Percorre a subárvore esquerda
        pre_ordem(raiz->direita);    // Percorre a subárvore direita
    }
}

 void em_ordem(NO* raiz) {
    if (raiz != NULL) {
        em_ordem(raiz->esquerda);    // Percorre a subárvore esquerda
        printf("%d ", raiz->info);  // Visita a raiz
        em_ordem(raiz->direita);     // Percorre a subárvore direita
    }
}

 void pos_ordem(NO* raiz) {
    if (raiz != NULL) {
        pos_ordem(raiz->esquerda);   // Percorre a subárvore esquerda
        pos_ordem(raiz->direita);    // Percorre a subárvore direita
        printf("%d ", raiz->info);  // Visita a raiz
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
    int altura_esquerda;
    int altura_direita;
    if (raiz == NULL) {
        return 0;
    }
    altura_esquerda = calcular_altura(raiz->esquerda);
    altura_direita = calcular_altura(raiz->direita);
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
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (op != 0);

    return 0;
}
/*
int percorrer_Caracter(int num){
    if (num<10){
        return num;
    }
    else
    {
        return num%10 OP percorrer_caracter(num);
    }
}
*/