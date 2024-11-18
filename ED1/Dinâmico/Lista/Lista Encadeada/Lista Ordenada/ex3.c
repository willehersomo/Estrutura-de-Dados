#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*3. Para organizar o chá de cozinha de Maria Eduarda, sua irmã mais nova, Gabriela, enviou
um e-mail para todas as suas amigas convidando-as para se reunirem no salão de festa
de sua casa. Ela solicitou que cada convidada levasse junto com o presente uma receita
culinária de sua preferência para enriquecer o livro de receitas virtual que será dado
para Maria Eduarda antes do dia do casamento. Para facilitar a organização das receitas,
Gabriela pediu a um(a) amigo(a) do curso de Sistemas de Informação (você!!!) que
fizesse um programa em que fosse possível cadastrar (ordenando pelo título) e exibir as
receitas na tela do computador a qualquer momento que ela quisesse. Foi solicitado
também que este sistema ficasse pronto até o dia da festa, para que fosse possível cada
convidada cadastrar sua receita previamente. As informações solicitadas no momento
do cadastro deverão ser: título da receita, descrição dos ingredientes, tipo (doce ou
salgado) e o nome da pessoa que presenteou Maria Eduarda com a receita. Utilize os
conceitos de lista simplesmente encadeada para implementar uma solução para o
problema acima.*/

typedef struct sLivro {
    char titulo[50];
    char descricao[100];
    int tipo;
    char nome[20];
} LIVRO;

typedef struct sLista {
    LIVRO livro;
    struct sLista *next;
} LISTA;

LISTA *getnode() {
    return (LISTA *)malloc(sizeof(LISTA));
}

LISTA *inicializar(LISTA *l) {
    return NULL;
}

int vazio(LISTA *l) {
    return (l == NULL);
}

void inserir_ordenado(LISTA **l, LIVRO livro) {
    LISTA *q = getnode();

    if (q == NULL) {
        printf("Falha ao alocar espaço\n");
    } else {
        strcpy(q->livro.descricao, livro.descricao);
        strcpy(q->livro.nome, livro.nome);
        strcpy(q->livro.titulo, livro.titulo);
        q->livro.tipo = livro.tipo;
        q->next = NULL;

        if (vazio(*l) || strcmp((*l)->livro.titulo, livro.titulo) > 0) {
            q->next = *l;
            *l = q;
        } else {
            LISTA *aux = *l;
            LISTA *anterior = NULL;

            while (aux != NULL && strcmp(aux->livro.titulo, livro.titulo) < 0) {
                anterior = aux;
                aux = aux->next;
            }

            anterior->next = q;
            q->next = aux;
        }
    }
}

void remover_fim(LISTA **l) {
    if (vazio(*l)) {
        printf("Lista Vazia\n");
    } else {
        LISTA *aux = *l;

        if (aux->next == NULL) {
             free(aux);
            *l = NULL;
        } else {
             while (aux->next->next != NULL) {
                aux = aux->next;
            }

            LISTA *q = aux->next;
            aux->next = NULL;
            free(q);
        }
    }
}

void remover_inicio(LISTA **l) {
    if (vazio(*l)) {
        printf("Lista Vazia\n");
    } else {
        LISTA *aux = *l;
        *l = aux->next;
        free(aux);
    }
}

void remover_livro(LISTA **l, char livro[]) {
    if (vazio(*l)) {
        printf("Lista Vazia\n");
    } else {
        LISTA *aux = *l;
        LISTA *anterior = NULL;

        while (aux != NULL && strcmp(aux->livro.titulo, livro) != 0) {
            anterior = aux;
            aux = aux->next;
        }

        if (aux == NULL) {
            printf("Título inexistente\n");
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
        while (aux != NULL) {
            printf("---------------\n");
            printf("Título: %s\n", aux->livro.titulo);
            printf("Descrição: %s\n", aux->livro.descricao);
            printf("Tipo: %s\n", aux->livro.tipo ? "Doce" : "Salgado");
            printf("Presenteado por: %s\n", aux->livro.nome);
            printf("---------------\n");
            aux = aux->next;
        }
        printf("\n");
    }
}

LIVRO coletar() {
    LIVRO retorno;
    printf("Insira o título da receita: \n");
    scanf(" %[^\n]", retorno.titulo);
    printf("Insira descrição dos ingredientes:\n");
    scanf(" %[^\n]", retorno.descricao);
    do {
        printf("É doce [1] ou salgado [0]?\n");
        scanf("%d", &retorno.tipo);
        if (retorno.tipo < 0 || retorno.tipo > 1) {
            printf("Opção inválida! Leia a pergunta novamente!\n");
        }
    } while (retorno.tipo < 0 || retorno.tipo > 1);
    printf("Quem te presenteou?\n");
    scanf(" %[^\n]", retorno.nome);
    return retorno;
}

int menu() {
    int op;
    printf("\nMenu\n");
    printf("1. Inserir receita\n");
    printf("2. Remover receita específica\n");
    printf("3. Remover última receita\n");
    printf("4. Remover primeira receita\n");
    printf("5. Listar receitas\n");
    printf("0. Encerrar Programa\n");
    printf("Escolha uma opção: ");
    scanf("%d", &op);
    return op;
}

int main() {
    LISTA *lista = inicializar(lista);
    LIVRO livro;
    int op;
    char titulo[50];

    do {
        op = menu();
        switch (op) {
            case 1:
                livro = coletar();
                inserir_ordenado(&lista, livro);
                break;
            case 2:
                printf("Insira o título da receita: \n");
                scanf(" %[^\n]", titulo);
                remover_livro(&lista, titulo);
                break;
            case 3:
                remover_fim(&lista);
                break;
            case 4:
                remover_inicio(&lista);
                break;
            case 5:
                exibir_lista(lista);
                break;
            case 0:
                printf("Encerrando Programa\n");
                break;
            default:
                printf("Opção Inválida\n");
                break;
        }
    } while (op != 0);

    return 0;
}
