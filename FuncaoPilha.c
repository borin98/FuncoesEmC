#include <stdio.h>
#include <stdlib.h>

typedef struct Lista
{

    int dado ;
    struct Lista *prox ;

} Lista ;

typedef Lista *pNo ;

typedef struct Pilha
{

    pNo primeiro ;
    pNo ultimo ;

} Pilha ;

typedef Pilha *pPilha ;

//função que adiciona o elemento na pilha
void push ( pPilha* pilha, int x )
{

    pNo novoNo = malloc ( sizeof ( Lista ) ) ;

    novoNo -> dado = x ;
    novoNo -> prox = 0 ;

    if ( *pilha == NULL )
    {

        (*pilha) = malloc ( sizeof ( Pilha ) ) ;

        (*pilha) -> primeiro = novoNo ;
        (*pilha) -> ultimo = novoNo ;

        return ;

    }

    novoNo -> prox = (*pilha) -> primeiro ;

    (*pilha) -> primeiro = novoNo ;

}

// função que retorna o elemento da pilha removido
int pop ( pPilha* pilha )
{

    pNo primeiro = (*pilha) -> primeiro ;
    pNo proxNo ;

    int x ;

    if ( (*pilha) -> primeiro == NULL )
    {

        printf("Pilha vazia\n");

        return -1 ;

    }

    x = primeiro -> dado ;

    proxNo = (*pilha) -> primeiro ;

    (*pilha) -> primeiro = proxNo -> prox ;

    free ( primeiro ) ;

    return x ;

}

void printaPilha ( pPilha pilha )
{

    pNo percorre ;

    for ( percorre = pilha -> primeiro; percorre != NULL; percorre = percorre -> prox )
    {

        printf("%d ", percorre -> dado ) ;

    }

}

void liberaPilha ( pPilha pilha )
{

    pNo percorre ;

    for ( percorre = pilha -> primeiro; percorre != NULL; percorre = percorre -> prox )
    {

        free ( percorre ) ;

    }

    pilha -> primeiro = percorre ;
    pilha -> ultimo = pilha -> primeiro ;

}

int main ( void )
{

    char c = ' ' ;
    int x ;

    pPilha pilha = NULL ;

    while ( c != 'e' )
    {

        scanf ( " %c", &c ) ;

        if ( c == 'i' )
        {

            scanf("%d", &x) ;

            push ( &pilha, x ) ;

        }

        else if ( c == 'p' )
        {

            printf("Printado a Pilha : ") ;
            printaPilha ( pilha ) ;
            printf("\n") ;

        }

        else if ( c == 'r' )
        {

            int remove = pop ( &pilha ) ;

            printf("Elemento removido : %d\n", remove ) ;

        }

    }

    liberaPilha ( pilha ) ;
    return 0 ;

}