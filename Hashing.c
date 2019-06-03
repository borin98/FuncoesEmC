/* Programa que utiliza um hashing com encadeamento para resolver os problemas de colisao
 * como função de hashing, foi implementada a função abaixo para manipular os dados em strings
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# define Max 5000

typedef struct No
{

    char chave [ 250 ] ;

    struct No *prox ;

} No ;

typedef No *pNo ;

typedef struct Hash
{

    pNo vetor [ Max ] ;

} Hash ;

typedef Hash *pHash ;

pNo removeLista ( pNo lista, char *chave )
{

    pNo percorre = lista ;
    pNo proxNo ;
    pNo antNo = percorre ;

    if ( lista == NULL )
    {

        return NULL ;

    }

    while ( strcmp ( chave, percorre -> chave ) != 0 )
    {

        antNo = percorre ;
        percorre = percorre -> prox ;

    }

    // no não existe na lista
    if ( percorre == NULL )
    {

        return lista ;

    }

    proxNo = percorre -> prox ;

    free ( percorre ) ;

    antNo -> prox = proxNo ;

    return lista ;

}

pNo inserirLista ( pNo lista, char* chave )
{

    pNo novoNo ;

    if ( lista == NULL )
    {

        lista = malloc ( sizeof ( No ) ) ;

        strcpy ( lista -> chave, chave ) ;

        return lista ;

    }

    novoNo = malloc ( sizeof ( No ) ) ;

    strcpy ( novoNo -> chave, chave ) ;
    novoNo -> prox = lista ;

    return novoNo ;

}

// implementação da função de hash
int hash ( char *chave )
{

    int n = 0 ;

    for ( int i = 0; i < strlen ( chave ); i++ )
    {

        n = ( ( 256 * n ) + chave [ i ] ) % Max ;

    }

    return n ;

}

void inserir ( pHash t, char *chave, int dado )
{

    int n = hash ( chave ) ;

    t -> vetor [ n ] = inserirLista ( t -> vetor [ n ], chave ) ;

}

void remover ( pHash t, char *chave )
{

    int n = hash ( chave ) ;

    t -> vetor [ n ] = removeLista ( t -> vetor [ n ], chave ) ;

}