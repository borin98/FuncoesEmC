#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int** somaLinha ( int linha1, int linha2, int coluna, int** matriz )
{

    for ( int j = 0; j < coluna; j++ )
    {

        matriz [ linha1 ] [ j ] += matriz [ linha2 ] [ j ] ;

    }

    return matriz ;

}

int** multMatriz ( int lin, int coluna, int** matriz )
{

    int multiplicador ;

    printf("\nDigite o valor do multiplicador inteiro : ") ;

    scanf("%d", &multiplicador) ;

    for ( int i = 0; i < lin; i++ )
    {

        for ( int j = 0; j < coluna; j++)
        {

            matriz [ i ] [ j ] *= multiplicador ;

        }

    }

    return matriz ;

}

void printaMatriz ( int lin, int coluna, int** matriz )
{

    printf("\n") ;

    for ( int i = 0; i < lin; i++ )
    {

        for ( int j = 0; j < coluna; j++ )
        {

            printf("Elemento da linha %d e coluna %d da matriz : %d\n", ( i + 1 ), ( j + 1 ), matriz [ i ] [ j ] ) ;

        }

    }

    return ;

}

int** montaMatriz ( int lin, int coluna, int** matriz )
{

    int elemento ;

    for ( int i = 0; i < lin; i++ )
    {

        int *linha = malloc ( coluna * sizeof ( int ) ) ;

        for ( int j = 0; j < coluna; j++ )
        {

            printf("Digite o elemento da linha %d e coluna %d da matriz : ", ( i + 1 ), ( j + 1 ) ) ;
            scanf("%d", &elemento) ;

            linha [ j ] = elemento ;

        }

        matriz [ i ] = linha ;

    }

    return matriz ;

}

int** inicializaMatriz ( int linha, int coluna )
{

    int **matriz = malloc ( linha*sizeof ( int* ) ) ;

    for ( int i = 0; i < linha; i++ )
    {

        matriz [ i ] = malloc ( coluna * sizeof ( int ) ) ;

    }

    return matriz ;

}

int main ( void )
{

    int lin, coluna ;
    int **matriz = NULL ;
    int soma1, soma2 ;


    printf("Digite a quantidade de linhas e colunas de uma matriz : ") ;
    scanf ( "%d %d", &lin, &coluna ) ;

    printf("\n------------------------------------------------\n") ;

    matriz = inicializaMatriz ( lin, coluna ) ;
    matriz = montaMatriz ( lin, coluna, matriz ) ;

    printaMatriz ( lin, coluna, matriz ) ;

    printf("\n------------------------------------------------\n") ;

    matriz = multMatriz ( lin, coluna, matriz ) ;
    printaMatriz ( lin, coluna, matriz ) ;

    printf("\n------------------------------------------------\n") ;

    printf("Digite qual linha da matriz deseja somar : ") ;
    scanf("%d %d", &soma1, &soma2) ;

    matriz = somaLinha ( soma1, soma2, coluna, matriz ) ;
    printaMatriz ( lin, coluna, matriz ) ;
    free ( matriz ) ;

    return 0 ;

}

