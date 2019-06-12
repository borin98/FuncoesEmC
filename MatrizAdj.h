
#ifndef UNTITLED_MATRIZADJ_H
#define UNTITLED_MATRIZADJ_H 1

#include <stdio.h>
#include <stdlib.h>

typedef struct Grafo
{

    int ** matrizAdj ;
    int tam ;

} Grafo ;

typedef Grafo *pGrafo ;

pGrafo criaGrafo ( int n )
{

    pGrafo grafo = malloc ( sizeof ( Grafo ) ) ;

    grafo -> tam = n ;

    grafo -> matrizAdj = malloc ( n * sizeof ( int * ) ) ;

    for ( int i = 0; i < n; i++ )
    {

        grafo -> matrizAdj [ i ] = malloc ( n * sizeof ( int ) ) ;

    }

    for ( int i = 0; i < n; i++ )
    {

        for ( int j = 0; j < n; j++ )
        {

            grafo -> matrizAdj [ i ] [ j ] = 0 ;

        }

    }

    return grafo ;

}

void destroiGrafo ( pGrafo grafo )
{

   for ( int i = 0; i < grafo -> tam; i++ )
   {

       free ( grafo -> matrizAdj [ i ] ) ;

   }

   free ( grafo -> matrizAdj ) ;
   free ( grafo ) ;

}

void insereAresta ( pGrafo grafo, int u, int v )
{

    if ( u != v )
    {

        grafo -> matrizAdj [ u ] [ v ] = 1 ;
        grafo -> matrizAdj [ v ] [ u ] = 1 ;

    }

}

void removeAresta ( pGrafo grafo, int u, int v )
{

    grafo -> matrizAdj [ u ] [ v ] = 0 ;
    grafo -> matrizAdj [ v ] [ u ] = 0 ;

}

int verificaAresta ( pGrafo grafo, int u, int v )
{

    return grafo -> matrizAdj [ u ] [ v ] ;

}

void imprimeAresta ( pGrafo grafo )
{

    for ( int i = 0; i < grafo -> tam; i++ )
    {

        for ( int j = 0; j < grafo -> tam; j++ )
        {

            if ( grafo -> matrizAdj [ i ] [ j ] == 1 )
            {

                printf("Aresta : {%d, %d} ", i, j ) ;

            }

        }

        printf("\n") ;

    }

}

int quantVizinhos ( pGrafo grafo, int u )
{

    int vizinhos = 0 ;

    for ( int j = 0; j < grafo -> tam; j++ )
    {

        if ( grafo -> matrizAdj [ u ] [ j ] == 1 )
        {

            vizinhos ++ ;

        }

    }

    return vizinhos ;

}

// retorna o vértice com o maior quantidade de vizinhos
int maisVizinhos ( pGrafo grafo )
{

    int max = quantVizinhos ( grafo, 0 ) ;
    int aux ;
    int vertice = 0 ;

    for ( int i = 1; i < grafo -> tam; i++ )
    {

        aux = quantVizinhos ( grafo, i ) ;

        if ( aux > max )
        {

            max = aux ;
            vertice = i ;

        }

    }

    return vertice ;

}

int quantAresta ( pGrafo grafo )
{

    return ( grafo-> tam * ( grafo -> tam - 1 )/2 ) ;

}

void imprimeRecomendacao ( pGrafo grafo, int u )
{

    for ( int j = 0; j < grafo -> tam; j++ )
    {

        if ( grafo -> matrizAdj [ u ] [ j ] == 1 )
        {

            for ( int k = 0; k < grafo -> tam; k++ )
            {

                if ( grafo -> matrizAdj [ j ] [ k ] == 1 && k != u && grafo -> matrizAdj [ u ] [ k ] == 0 )
                {

                    printf("Recomendacao : %d\n", k ) ;

                }

            }

        }

    }

}

#endif //UNTITLED_MATRIZADJ_H
