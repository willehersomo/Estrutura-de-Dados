#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define TF 50

typedef struct Slocatario
{
    char nome[50];
    char CPF[15];

} LOCATARIO;

typedef struct Sbarraca
{
    LOCATARIO locatario;
    int ID;
    int situacao;
    int tipo_prod;

} BARRACA;

typedef struct SLista
{
    BARRACA barraca[TF];
    int n;
} LISTA;

void inicializar(LISTA *l)
{
    l->n = -1;
}

int cheia(LISTA l)
{
    if (l.n == TF - 1)
        return 1;

    return 0;
}

int vazio (LISTA l)
{
    if (l.n==-1)
    return 1;

    return 0;
    
}

void ler_string(char string[])
{
    scanf(" %[^\n]", string);
}

int validar_CPF(char string[])
{
    int i;

    if (string[3] != '.' || string[7] != '.' || string[11] != '-')
    {
        return 0;
    }

    for (i = 0; i < 14; i++)
    {
        if (i != 3 &&i != 7 && i!= 11)
        {
            if (string[i] < '0' || string[i] > '9')
            {
                return 0;
            }
        }
    }

    return 1;
}

LOCATARIO dados_locatario()
{
    LOCATARIO retorno;
    int val;
    printf("Insira nome do locatáro: ");
    ler_string(retorno.nome);
    printf("Insira CPF do locatário: ");
    do
    {
        ler_string(retorno.CPF);
        val = validar_CPF(retorno.CPF);
        if (val == 0)
        {
            printf("CPF inválido, atente-se ao formato XXX.XXX.XXX-XX\n");
            printf("Insira novamente: ");
        }
    } while (val == 0);

    return retorno;
}

BARRACA dados_barraca(LISTA l)
{

    BARRACA retorno;
    retorno.locatario = dados_locatario();
    retorno.ID = l.n+1;

    printf("O locatário pagou a reserva (1. SIM/ 2. NÃO): ");
    do
    {
        scanf("%d", &retorno.situacao);

        if (retorno.situacao < 1 || retorno.situacao > 2)
        {
            printf("Insira um valor válido: ");
        }

    } while (retorno.situacao < 1 || retorno.situacao > 2);

    printf("Qual tipo de produto o comerciante vende:\n 1. Bebida\n 2. Lanche\n 3. Artigo em geral\n");

    do
    {
        scanf("%d", &retorno.tipo_prod);
        if (retorno.tipo_prod < 1 || retorno.tipo_prod > 3)
        {
            printf("Insira um valor válido: ");
        }

    } while (retorno.tipo_prod < 1 || retorno.tipo_prod > 3);

    return retorno;
}

void inserir_lista(LISTA *l)
{
    if (cheia(*l))
    {
        printf("Lista cheia!\n");
    }
    else
    {
        (*l).n++;
        l->barraca[(*l).n] = dados_barraca(*l);
    }
}

void exibir_lista(LISTA l)
{
    int i;
    if(vazio(l))
    {
        printf("A lista está vazia\n");
    }
    else
    {
        for (i=0;i<=l.n;i++)
        {
            printf("-------------------------------------\n");
            printf ("Barraca ID: %d\n", l.barraca[i].ID);
            printf ("Nome do locatário: %s\n", l.barraca[i].locatario.nome);
            printf ("CPF do locatário: %s\n", l.barraca[i].locatario.CPF);
            printf ("Tipo de produto vendido: ");
            if(l.barraca[i].tipo_prod==1)
            {
                printf ("bebida\n");
            }
            else if(l.barraca[i].tipo_prod==2)
            {
                printf ("alimento\n");
            }
            else
            {
                printf ("Artigos em geral\n");

            }
            printf ("Aluguel: ");
            if(l.barraca[i].situacao==1)
            {
                printf ("pago\n");
            }
            else
            {
                printf ("pagamento pendente\n");
            }


            printf("-------------------------------------\n");


        } 
    }
}

void relatorio_inadimplente(LISTA l)
{
    int i;
    if (vazio(l))
    {


        printf ("Lista vazia\n");
    }
    else
    {
        printf ("Relatórios de barracas inadimplentes: \n");

        for (i=0;i<=l.n;i++)
        {
            if(l.barraca[i].situacao==2)
            {
                printf ("----------------------\n");
                printf("Barraca ID: %d\n", l.barraca[i].ID);
                printf("Nome do locatário: %s\n", l.barraca[i].locatario.nome);
                printf("CPF do locatário: %s\n", l.barraca[i].locatario.CPF);
                printf ("----------------------\n");

            }
        }
    }
}

void relatorio_geral (LISTA l)
{
    int i;
    int cheio=0;
    int vaz=0;
    if(vazio(l))
    {
        printf ("Lista vazia\n");

    }
    else
    {
       printf("Barracas ocupadas: \n");
       for(i=1;i<=l.n+1;i++)
       {
            printf("Barraca %d\n", i);
            cheio++;
       }
       printf("\nTotal = %d\n", cheio);

       printf ("----------------------\n");
        printf("Barracas livres: \n");
       for(i=l.n+2;i<=TF;i++)
       {
            printf("Barraca %d\n", i);
            vaz++;
       }
        printf("\nTotal = %d\n", vaz);


    }
}

int menu()
{
    int op;
    printf("Menu: \n");
    printf("1. Alugar Barraca.\n");
    printf("2. Exibir informações de barracas alugadas\n");
    printf("3. Relatório de barracas inadimplentes\n");
    printf("4. Relatorio geral (livres e ocupadas)\n");
    printf("0. Encerrar programa\n");
    printf("Digite a opção: ");
    scanf("%d", &op);
    return op;
}

int main()
{
    LISTA l;
    int op;

    inicializar(&l);

    do
    {
        op = menu();

        switch (op)
        {
        case 1:

            inserir_lista(&l);
            break;

        case 2:
            exibir_lista(l);
            break;
        case 3:
            relatorio_inadimplente(l);
            break;
        case 4:
            relatorio_geral(l);
            break;
        case 0:
            printf ("Encerrando programa\n");
            break;
        default:
            printf("Opção inválida\n");
            break;

        }
    } while (op != 0);

    return 0;
}