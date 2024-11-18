#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*É tradição em algumas Universidades oferecer o Baile Anual de Ex-Alunos no início do
mês de dezembro de todos os anos. Com o objetivo de reencontrar os antigos colegas
de curso e retornar aos lugares do tempo da graduação as turmas se reúnem de 5 em 5
anos para festejar. Visando trazer essa tradição para o campus do IFSP de Presidente
Epitácio foi solicitado ao CTI-PEP o desenvolvimento de uma aplicação simples para
cadastramento dos dados de cada formando do IFSP-PEP (prontuário, nome completo,
nome do curso, ano de ingresso, ano de formatura, endereço e dois telefones de
contato). Além disso, foi solicitado que a aplicação fosse capaz de gerar dois tipos de
relatórios, o primeiro contendo as informações de todos os ex-alunos separados por
curso, e o segundo contendo as informações dos alunos separados pelo ano de
formatura. Utilize os conceitos de lista linear dinâmica para desenvolver a aplicação e,
desta forma, atender plenamente o pedido solicitado.*/

typedef struct sFormando {
    int prontuario;
    char nome_completo[50];
    char curso_nome[20];
    int ano_ingresso;
    int ano_formatura;
    char endereco[100];
    char telefone[2][13];
} FORMANDO;

typedef struct sLista {
    FORMANDO formando;
    struct sLista *next;
} LISTA;

LISTA *getnode() {
    return (LISTA *) malloc(sizeof(LISTA));
}

LISTA *inicializar(LISTA *l) {
    l = NULL;
    return l;
}

int vazio(LISTA *l) {
    return (l == NULL);
}

void inserir_inicio(LISTA **l, FORMANDO info) {
    LISTA *q = getnode();
    if (q == NULL) {
        printf("Falha ao alocar espaço\n");
    } else {
        q->formando = info;
        q->next = *l;
        *l = q;
    }
}

void inserir_fim(LISTA **l, FORMANDO info) {
    LISTA *q = getnode();
    if (q == NULL) {
        printf("Falha ao alocar espaço\n");
    } else {
        q->formando = info;
        q->next = NULL;
        if (vazio(*l)) {
            *l = q;
        } else {
            LISTA *aux = *l;
            while (aux->next != NULL) {
                aux = aux->next;
            }
            aux->next = q;
        }
    }
}

void remover_inicio(LISTA **l) {
    if (vazio(*l)) {
        printf("Lista Vazia\n");
    } else {
        LISTA *q = *l;
        *l = (*l)->next;
        free(q);
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
            free(aux->next);
            aux->next = NULL;
        }
    }
}

void exibir_lista(LISTA *l) {
    if (vazio(l)) {
        printf("Lista Vazia\n");
    } else {
        LISTA *aux = l;
        while (aux != NULL) {
            printf("-----------------------------\n");
            printf("%d\n", aux->formando.prontuario);
            printf("%s\n", aux->formando.nome_completo);
            printf("%s\n", aux->formando.curso_nome);
            printf("%d - %d\n", aux->formando.ano_ingresso, aux->formando.ano_formatura);
            printf("%s\n", aux->formando.endereco);
            printf("%s/%s\n", aux->formando.telefone[0], aux->formando.telefone[1]);
            printf("-----------------------------\n");
            aux = aux->next;
        }
    }
}

void gerar_relatorio_curso(LISTA *l) {
    if (vazio(l)) {
        printf("Lista Vazia\n");
    } else {
        LISTA *aux = l;
        LISTA *atual;
        LISTA *pos;
        while (aux != NULL) {
            atual = aux;
            while (atual->next != NULL) {
                if (strcmp(atual->next->formando.curso_nome, aux->formando.curso_nome) == 0) {
                    pos = atual->next;
                    atual->next = atual->next->next;
                    pos->next = aux->next;
                    aux->next = pos;
                    aux = aux->next;
                    atual = aux;
                } else {
                    atual = atual->next;
                }
            }
            aux = aux->next;
        }
        exibir_lista(l);
    }
}

void gerar_relatorio_formatura(LISTA *l)
{
    if (vazio(l)) {
        printf("Lista Vazia\n");
    } else {
        LISTA *aux = l;
        LISTA *atual;
        LISTA *pos;
        while (aux != NULL) {
            atual = aux;
            while (atual->next != NULL) {
                if (atual->next->formando.ano_formatura == aux->formando.ano_formatura) {
                    pos = atual->next;
                    atual->next = atual->next->next;
                    pos->next = aux->next;
                    aux->next = pos;
                    aux = aux->next;
                    atual = aux;
                } else {
                    atual = atual->next;
                }
            }
            aux = aux->next;
        }
        exibir_lista(l);
    }
}

FORMANDO coletar() {
    FORMANDO retorno;
    printf("Insira prontuário: ");
    scanf("%d", &retorno.prontuario);
    printf("Insira nome do aluno: ");
    scanf(" %[^\n]", retorno.nome_completo);
    printf("Insira curso do aluno: ");
    scanf(" %[^\n]", retorno.curso_nome);
    printf("Insira ano de ingresso do aluno: ");
    scanf("%d", &retorno.ano_ingresso);
    printf("Insira ano de formação: ");
    scanf("%d", &retorno.ano_formatura);
    printf("Insira endereço do aluno: ");
    scanf(" %[^\n]", retorno.endereco);
    printf("Insira primeiro contato do aluno: ");
    scanf(" %[^\n]", retorno.telefone[0]);
    printf("Insira segundo contato do aluno: ");
    scanf(" %[^\n]", retorno.telefone[1]);
    printf("\n");
    return retorno;
}

int menu() {
    int op;
    printf("\nMENU\n");
    printf("1. Inserir dado no inicio\n");
    printf("2. Inserir dado no final\n");
    printf("3. Remover dado no inicio\n");
    printf("4. Remover dado no final\n");
    printf("5. Gerar relatório de alunos por curso\n");
    printf("6. Gerar relatório de alunos pelo ano da formatura\n");
    printf("7. Exibir Lista\n");
    printf("0. Encerrar Programa\n");
    scanf("%d", &op);
    return op;
}

int main() {
    LISTA *lista = inicializar(lista);
    FORMANDO info;
    int op;
    do {
        op = menu();
        switch (op) {
            case 1:
                info = coletar();
                inserir_inicio(&lista, info);
                break;
            case 2:
                info = coletar();
                inserir_fim(&lista, info);
                break;
            case 3:
                remover_inicio(&lista);
                break;
            case 4:
                remover_fim(&lista);
                break;
            case 5:
                gerar_relatorio_curso(lista);
                break;

            case 6:
                gerar_relatorio_formatura(lista);
                break;

            case 7:
                exibir_lista(lista);
                break;

            case 0:
                printf("Encerrando.\n");
                break;
            default:
                printf("Opção Inválida!\n");
                break;
        }
    } while (op != 0);
}
