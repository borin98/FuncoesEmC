#include <stdlib.h>
#include <stdio.h>

typedef struct No
{

    int dado ;
    struct No *prox ;

}No;

typedef struct No *pNo ;

pNo criaLista (  )
{

    return NULL ;

}


void imprimeListaRecursivamente ( pNo p )
{

    if ( p != NULL )
    {

        printf("%d ", p -> dado ) ; // declaração que imprime do head ao tail
        imprimeListaRecursivamente ( p -> prox ) ;
        //printf("%d ", p -> dado ) ; // declaração que imprime do tail ao head

    }


}

// funcao que imprime a lista do head ao tail
void imprimeListaIterativa ( pNo p )
{

    pNo aux ;

    for ( aux = p; aux != NULL; aux = aux -> prox )
    {

        printf("%d ", aux -> dado ) ;

    }

}

void destroiListaIterativa ( pNo p )
{

    while ( p != NULL )
    {

        free ( p ) ;
        p = p -> prox ;

    }

}

// adiciona no head da lista
pNo adicionaElemento ( pNo p, int e )
{

    pNo aux = malloc ( sizeof ( No ) ) ;

    aux -> dado = e ;
    aux -> prox = p ;

    return aux ;

}


void destroiListaRecursiva ( pNo p )
{

    if ( p != NULL )
    {

        destroiListaRecursiva ( p -> prox ) ;

        free ( p ) ;

    }

}

pNo copiaListaIterativamente ( pNo l1 )
{

    pNo l2 = 0 ;
    pNo preElem = 0 ;
    pNo copia ;

    for ( copia = l1; copia != NULL; copia = copia -> prox )
    {

        pNo elem = malloc ( sizeof ( No ) ) ;

        elem -> dado = copia -> dado ;
        elem-> prox = 0 ;

        if ( l2 == 0 ) // a lista chegou no elemento Null
        {

            l2 = elem ;
            preElem = elem ;

        }

        else
        {

            preElem -> prox = elem ;
            preElem = elem ;

        }

    }

    return l2 ;

}

pNo copiaListaRecursivamente ( pNo l1 )
{

    pNo aux = malloc ( sizeof ( No ) ) ;

    if ( l1 == NULL )
    {

        return NULL ;

    }

    aux -> dado = l1 -> dado ;
    aux -> prox = copiaListaRecursivamente ( l1 -> prox ) ;

    return aux ;

}

// função que adiciona um elemento no Tail de uma lista recursivamente
pNo adicionaElementoTail  ( pNo p, int x )
{

    if ( p == NULL )
    {

        p = adicionaElemento ( p, x ) ;

        return p ;

    }

    p -> prox = adicionaElementoTail ( p -> prox, x ) ;

    return p ;

}

pNo adicionaElementoTailIterativo ( pNo p, int x )
{

  pNo aux = malloc ( sizeof ( No ) ) ;
  pNo percorre ;

  if ( p == NULL )
  {

    return adicionaElemento ( p, x ) ;

  }

  for ( percorre = p; percorre -> prox != NULL; percorre = percorre -> prox ) ; // percorre até o fim da lista

  aux -> dado = x ;
  aux -> prox = 0 ;

  percorre -> prox = aux ;

  return p ;
}

// funçao principal de exemplo do programa
int main ( void )
{

    pNo p = criaLista (  ) ;
    pNo p2 = criaLista (  ) ;

    p = adicionaElemento ( p, 3 ) ;
    p = adicionaElemento ( p, 2 ) ;
    p = adicionaElemento ( p, 1 ) ;

    p2 = copiaListaIterativamente ( p ) ;

    imprimeListaIterativa ( p ) ;

    printf("\n") ;
    imprimeListaRecursivamente ( p2 ) ;

    destroiListaIterativa ( p ) ;

    return 0 ;

}
