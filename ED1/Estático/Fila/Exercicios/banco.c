#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TF 101

typedef struct SBilhete
{
    char nome[20];
    int hora_entrada;
    int minuto_entrada;
    int hora_atendimento;
    int minuto_atendimento;
} BILHETE;

typedef struct SFila
{
    BILHETE bilhete[TF];
    int inicio;
    int fim;
} FILA;

void inicializar(FILA *f)
{
    f->inicio = 0;
    f->fim = 0;
}

int vazia(FILA f)
{
    return (f.inicio == f.fim);
}

int cheia(FILA f)
{
    return ((f.fim + 1) % TF == f.inicio);
}

void enfileirar(FILA *f, int h, int m, char nome[])
{
    if (cheia(*f))
    {
        printf("Fila cheia\n");
    }
    else
    {
        f->bilhete[f->fim].hora_entrada = h;
        f->bilhete[f->fim].minuto_entrada = m;
        strcpy(f->bilhete[f->fim].nome, nome);
        f->fim = (f->fim + 1) % TF;
    }
}

BILHETE desenfileirar(FILA *f, int h, int m)
{
    if (vazia(*f))
    {
        printf("Fila Vazia\n");
        BILHETE vazio = {"", 0, 0, 0, 0};
        return vazio;
    }
    else
    {
        BILHETE bilhete = f->bilhete[f->inicio];
        bilhete.hora_atendimento = h;
        bilhete.minuto_atendimento = m;
        f->inicio = (f->inicio + 1) % TF;
        return bilhete;
    }
}

float calcular_tempo_total(BILHETE b)
{
    int total_minutos_entrada = b.hora_entrada * 60 + b.minuto_entrada;
    int total_minutos_atendimento = b.hora_atendimento * 60 + b.minuto_atendimento;
    return total_minutos_atendimento - total_minutos_entrada;
}

void ler_vetor(char vetor[])
{
    scanf(" %[^\n]", vetor);
}

int main()
{
    FILA f;
    inicializar(&f);

    int h_entrada, m_entrada, h_atendimento, m_atendimento, i = 1;
    char nome[20];
    float tempo_medio = 0;
    
    printf("Inserir clientes na fila:\n");
    while (!cheia(f))
    {
        printf("\nEntrada do Cliente %d na fila:\n", i);
        i++;
        printf("Insira nome do cliente: ");
        ler_vetor(nome);
        printf("Insira hora de entrada (formato 24h): ");
        scanf("%d", &h_entrada);
        printf("Insira minuto de entrada: ");
        scanf("%d", &m_entrada);
        enfileirar(&f, h_entrada, m_entrada, nome);
    }

    i = 1;
    printf("Registrar atendimento dos clientes:\n");
    while (!vazia(f))
    {
        printf("\nHora que o Cliente %d foi atendido: \n", i);
        i++;
        printf("Insira hora de atendimento (formato 24h): ");
        scanf("%d", &h_atendimento);
        printf("Insira minuto de atendimento: ");
        scanf("%d", &m_atendimento);
        BILHETE bilhete = desenfileirar(&f, h_atendimento, m_atendimento);
        tempo_medio += calcular_tempo_total(bilhete);
    }

    tempo_medio /= TF;
    printf("\nTempo médio de espera: %.2f minutos\n", tempo_medio);

    return 0;
}
