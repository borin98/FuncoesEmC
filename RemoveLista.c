#include <stdio.h>
#include <stdlib.h>

typedef struct No
{

    int dado ;
    struct No *prox ;

} No ;

typedef No *pNo ;

pNo insereHead ( pNo L, int x )
{

    if ( L == NULL )
    {

        L = malloc ( sizeof ( No ) ) ;
        L -> dado = x ;
        L -> prox = 0 ;

        return L ;

    }

    pNo aux = malloc ( sizeof ( No ) ) ;
    aux -> dado = x ;
    aux -> prox = L ;

    return aux ;

}

void removeNo ( pNo *L, int x )
{

    if ( *L == NULL )
    {

        return ;

    }

    else if ( (*L) -> dado == x )
    {

        pNo aux = (*L) -> prox ;
        free ( *L ) ;
        *L = aux ;

        return ;

    }

    pNo ant = *L ;

    for ( pNo percorre = (*L) -> prox; percorre != NULL; percorre = percorre -> prox )
    {

        if ( percorre -> dado == x )
        {

            pNo prox = percorre -> prox ;
            free ( percorre ) ;
            ant -> prox = prox ;

            return ;

        }

        ant = ant -> prox ;

    }

}

void C ( pNo *L1, pNo *L2 )
{

    if ( *L2 == NULL || *L1 == NULL )
    {

        return ;

    }

    pNo copiaDeleta = NULL ;

    for ( pNo aux2 = *L2; aux2 != NULL; aux2 = aux2 -> prox )
    {

        int i = 1 ;
        int remove = 1 ;

        for ( pNo aux1 = *L1; aux1 != NULL && remove == 1; aux1 = aux1 -> prox )
        {

            if ( aux2 -> dado == i )
            {

                copiaDeleta = insereHead ( copiaDeleta, aux1 -> dado ) ;
                remove = 0 ;

            }

            i ++ ;

        }

    }

    while ( copiaDeleta != NULL )
    {

        removeNo ( L1, copiaDeleta -> dado ) ;
        copiaDeleta = copiaDeleta -> prox ;

    }

}

int main ( void )
{

    pNo L = NULL ;
    pNo L2 = NULL ;

    L = insereHead ( L, 5 ) ;
    L = insereHead ( L, 4 ) ;
    L = insereHead ( L, 3 ) ;
    L = insereHead ( L, 2 ) ;
    L = insereHead ( L, 1 ) ;

    L2 = insereHead ( L2, 8 ) ;
    L2 = insereHead ( L2, 4 ) ;
    L2 = insereHead ( L2, 2 ) ;

    C ( &L, &L2 ) ;

    return 0;

}