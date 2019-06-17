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

/*
 * Função auxiliar para buscar os n
 */
int buscaReq ( pGrafo grafo, int *visitados, int v, int t )
{

    if ( v == t )
    {

        return 1 ; // caso base da recursão

    }

    visitados [ v ] = 1 ;

    // fazendo a busca nos elementos adjacentes dos vértices
    for ( int i = 0; i < grafo -> tam; i++)
    {

        if ( grafo -> matrizAdj [ v ] [ i ] == 1 && visitados [ i ] == 0 )
        {

            if ( buscaReq ( grafo, visitados, i, t ) == 1 )
            {

                return 1 ;

            }

        }

    }

    return 0 ;

}

int buscaCiclo ( pGrafo g, int vi )
{

    int j = 0 ;
    int i = vi ;
    int sair = 0 ;

    do
    {

        while ( j < g -> tam && sair == 0 )
        {

            // encontrou o ciclo
            if ( g -> matrizAdj [ i ] [ j ] == 1 && j == vi )
            {

                return 1 ;

            }

            else if ( g -> matrizAdj [ i ] [ j ] == 1 )
            {

                sair = 1 ;
                i ++ ;

            }

            else
            {

                j ++ ;

            }

        }

        j = 0 ;
        sair = 0 ;

        if ( i == g -> tam )
        {

            i = 0 ;

        }

    } while ( i != vi ) ;

    return 0 ; // caso não encontre nenhum ciclo

}

/* Busca por profundidade
 * Função que verifica se tem caminho em dois vértices
 * Neste caso, "s" e "t" são os vértices dos vértices
 * e retorna 0 se não encontrar caminho
 * e retorna 1 caso contrário
 */
int veriCaminho ( pGrafo grafo, int s, int t )
{

    int encontrou ;
    int *vizitados = malloc ( grafo -> tam * sizeof ( int ) ) ; // vetor que contém os vértices processados ao longo do caminho

    for ( int i = 0; i < grafo -> tam; i++ )
    {

        vizitados [ i ] = 0 ;

    }

    encontrou = buscaReq ( grafo, vizitados, s, t ) ;
    free ( vizitados ) ;

    return encontrou ;

}

#endif //UNTITLED_MATRIZADJ_H
