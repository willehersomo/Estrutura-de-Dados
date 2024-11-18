/*
Rafinha dos Teclados é um grande admirador de música e tocador nato de teclado.
Desde muito novo seus pais o incentivavam a aprimorar cada vez mais o seu talento.
Chegou a ganhar dinheiro na cidade que mora, mas levar os teclados de um lugar para
outro sempre foi uma coisa que o incomodava. Com isso, ele teve a ideia de começar a
tocar violão por ser um instrumento de fácil manuseio. Ele resolveu comprar uma Pasta
Catálogo (com 100 plásticos) para guardar as letras das músicas que ele imprimia (uma
letra/folha por plástico). Para cada nova música que ele queria aprender ele imprimia a
letra e a colocava na pasta sempre após a última folha inserida. Para selecionar as letras
de músicas em uma apresentação ele adotou a seguinte estratégia: cantar a música que
estava no início (a que estava há mais tempo sem ser cantada) e em seguida retirá-la da
pasta, recolocando-a após a última folha de música da pasta. Caso não houvesse mais
espaço para inclusão de uma folha no final da pasta (a música que Rafinha acabou de
cantar), ele recomeçava e colocava as folhas no início da pasta. Ele repetia este
processo, cantando e remanejando as músicas enquanto alguém pedisse pra ele cantar
uma nova música.
*/

#include <stdio.h>
#include <string.h>
#define TF 100

typedef struct sMusica
{
    char nome [50];
    char genero [50];
}MUSICA;

typedef struct sFila 
{
    MUSICA musica[TF];
    int inicio, fim;
}FILA;

void inicializar (FILA *f)
{
    f->inicio=-1;
    f->fim=-1;
}

int vazio (FILA f)
{
    return f.inicio == f.fim;
}

int cheio(FILA f)
{
    return (f.fim+1) % TF == f.inicio;
}

void enfileirar_fila (FILA *f, MUSICA m)
{
    if(cheio(*f))
    {
        printf ("Fila Cheia\n");
    }
    else
    {
        f->fim = (f->fim+1)%TF;
        strcpy(f->musica[f->fim].nome, m.nome);
        strcpy(f->musica[f->fim].genero, m.genero);
    }
}

MUSICA desenfileirar_fila (FILA *f)
{
    MUSICA retorno = {"", ""};
    if(vazio(*f))
    {
        printf("Fila Vazia\n");
        return retorno;
    }
    else
    {

        f->inicio = (f->inicio+1)%TF;
        retorno = f->musica[f->inicio];
    }

    return retorno;
}

MUSICA preencher_musica ()
{
    MUSICA retorno;
    printf ("Insira o nome da música: ");
    scanf (" %[^\n]", retorno.nome);
    printf ("Insira o genêro da música: ");
    scanf (" %[^\n]", retorno.genero);
    return retorno;
}

void exibir_pasta(FILA f)
{
    MUSICA m;
    int auxiliar;
    if (vazio(f))
    {
        printf ("Fila Vazia\n");
    }
    else
    {
        auxiliar = (f.inicio+1) % TF;
        while (auxiliar != (f.fim+1)%TF)
        {
            m=desenfileirar_fila(&f);
            printf ("%s - %s\n", m.nome, m.genero);
            auxiliar=(auxiliar+1)%TF;
            printf ("\n"); 
        }
        
    }
}


int menu()
{
    int op;
    printf ("Menu\n");
    printf ("1. Engavetar Música\n");
    printf ("2. Tocar música\n");
    printf ("3. Exibir Pasta\n");
    printf ("Insira a opção: ");
    scanf ("%d", &op);
    return op;
}

int main ()
{
    FILA f;
    MUSICA m;
    int op;
    inicializar(&f);


    do
    {
        op=menu();
        switch (op)
        {
            case 1:
            m=preencher_musica();
            enfileirar_fila(&f, m);
            break;

            case 2:
            
            printf ("Música tocada: %s\n", desenfileirar_fila(&f).nome);
            break;

            case 3:
            exibir_pasta(f);
            break;

            case 0:
            printf("Encerrando...");
            break;

            default:
            printf("Opção Inválida\n");
            break;

        }

    }while (op!=0);

    return 0;

}




