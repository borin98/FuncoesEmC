#include <stdlib.h>
#include <stdio.h>

typedef struct Lista
{

    int dado ;
    struct Lista *prox ;

} Lista ;

typedef Lista *pNo ;

typedef struct Fila
{

    pNo primeiro ;
    pNo ultimo ;

} Fila ;

typedef Fila *pFila ;

void criaFila ( pFila* f )
{

    *f = NULL ;

}

void apagaFila ( pFila f )
{

    pNo aux ;

    for ( aux = f -> primeiro; aux != NULL; aux = aux -> prox )
    {

        free ( aux ) ;

    }

    f -> primeiro = aux ;
    f -> ultimo = f -> primeiro ;

}

// tira o último elemento da fila
int tiraElementoFila ( pFila *f )
{

    pNo primeiro = (*f) -> primeiro ;

    int x = primeiro -> dado ;

    (*f) -> primeiro = (*f) -> primeiro -> prox ;

    // caso em que a lista está vazia
    if ( (*f) -> primeiro != NULL )
    {

        (*f) -> ultimo = 0 ;

    }

    free ( primeiro ) ;

    return x ;

}

// função que adiciona no fim da fila
void adicionaFila ( pFila* f, int x )
{

    pNo novoNo  = malloc ( sizeof ( Lista ) ) ;

    novoNo -> dado = x ;
    novoNo -> prox = 0 ;

    // caso a fila esteja vazia
    if ( *f == NULL )
    {

        (*f) = malloc ( sizeof ( Fila ) ) ;

        (*f) -> primeiro = novoNo ;
        (*f) -> ultimo = novoNo ;

        return ;

    }

    (*f) -> ultimo -> prox = novoNo ;
    (*f) -> ultimo = novoNo ;

}

void printaLista ( pFila f )
{

    pNo percorre ;

    for ( percorre = f -> primeiro; percorre != NULL; percorre = percorre -> prox )
    {

        printf("%d ", percorre -> dado ) ;

    }

}

int main ( void )
{

    char c = ' ' ;
    int x ;

    pFila f ;

    criaFila( &f ) ;

    while ( c != 'e' )
    {

        scanf ( " %c", &c ) ;

        if ( c == 'i' )
        {

            scanf("%d", &x) ;

            adicionaFila ( &f, x ) ;

        }

        else if ( c == 'p' )
        {

            printf("Printado a Fila : ") ;
            printaLista ( f ) ;
            printf("\n") ;

        }

        else if ( c == 'r' )
        {

            int remove = tiraElementoFila ( &f ) ;

            printf("Elemento removido : %d\n", remove ) ;

        }

    }

    apagaFila ( f ) ;
    return 0 ;

}