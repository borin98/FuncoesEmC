#ifndef UNTITLED_LISTAADJ_H
#define UNTITLED_LISTAADJ_H 1

#include <stdio.h>
#include <stdlib.h>

typedef struct Vertice
{

    int dado ;
    struct Vertice *prox ;

} Vertice ;

typedef Vertice *pNo ;

typedef struct Grafo
{

    pNo *adjacentes ;
    int tam ;

} Grafo ;

typedef Grafo *pGrafo ;

pGrafo criaGrafo ( int n )
{

    pGrafo grafo = malloc ( sizeof ( Grafo ) ) ;
    grafo -> tam = n ;
    grafo -> adjacentes = malloc ( grafo -> tam * sizeof ( Vertice ) ) ;

    for ( int i = 0; i < grafo -> tam; i++ )
    {

        grafo -> adjacentes [ i ] = NULL ;

    }

    return grafo ;

}

void liberaLista ( pNo lista )
{

   if ( lista != NULL )
   {

       pNo post ;
       pNo percorre = lista ;

       while ( percorre != NULL )
       {

           post = percorre -> prox ;

           free ( percorre ) ;

           percorre = post ;

       }

       lista = percorre ;

   }

}

pNo insereLista ( pNo lista, int dado )
{

    pNo novoNo = malloc ( sizeof ( Vertice ) ) ;

    novoNo -> dado = dado ;
    novoNo -> prox = lista ;

    return novoNo ;

}

void insereAresta ( pGrafo grafo, int u, int v )
{

    grafo -> adjacentes [ u ] = insereLista ( grafo -> adjacentes [ v ], u ) ;
    grafo -> adjacentes [ v ] = insereLista ( grafo -> adjacentes [ u ], v ) ;

}

pNo removeLista ( pNo lista, int v )
{

    if ( lista != NULL )
    {

        if ( lista -> dado == v )
        {

            free ( lista ) ;

            return NULL ;

        }

        pNo percorre = lista ;
        int remove = 0 ;

        while ( percorre != NULL && remove != 1 )
        {

            if ( percorre -> dado == v )
            {

                pNo prox = percorre -> prox ;

                free ( percorre ) ;

                percorre = prox ;

                remove = 1 ;

            }

            percorre = percorre -> prox ;

        }

    }

    return lista ;

}

void removeAresta ( pGrafo grafo, int u, int v )
{

    grafo -> adjacentes [ u ] = removeLista ( grafo -> adjacentes [ u ], v ) ;
    grafo -> adjacentes [ v ] = removeLista ( grafo -> adjacentes [ v ], u ) ;

}

int verificaAresta ( pGrafo grafo, int u, int v )
{

    for ( pNo percorre = grafo -> adjacentes [ u ]; percorre != NULL; percorre = percorre -> prox )
    {

        if ( percorre -> dado == v )
        {

            return 1 ;

        }

    }

    return 0 ;

}

void imprimeAresta ( pGrafo grafo )
{

    for ( int i = 0; i < grafo -> tam; i++ )
    {

        for ( pNo percorre = grafo -> adjacentes [ i ]; percorre != NULL; percorre = percorre -> prox )
        {

            printf ("Aresta : {%d, %d}", i, percorre -> dado ) ;

        }

    }

}

#endif //UNTITLED_LISTAADJ_H
