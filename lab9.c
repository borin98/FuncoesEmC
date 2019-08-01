#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct No
{

    char chave ;

    struct No *esq ;
    struct No *dir ;

} No ;

typedef No *pNo ;

void posOrdem ( pNo arvore )
{

    if ( arvore != NULL )
    {

        posOrdem ( arvore -> esq ) ;
        posOrdem ( arvore -> dir ) ;
        printf("%c", arvore -> chave ) ;

    }

}

pNo criaArvore ( pNo arvore, char x, int op )
{

    pNo novoNo = malloc ( sizeof ( No ) ) ;

    if ( arvore == NULL )
    {

        novoNo -> chave = x ;
        novoNo -> esq = 0 ;
        novoNo -> dir = 0 ;

        arvore = novoNo ;

        return arvore ;

    }

    // percorre a esquerda
    if ( op == 0 )
    {

        arvore -> esq = criaArvore ( arvore -> esq, x, op ) ;

    }

    // percorre a direita
    else if ( op == 1 )
    {

        arvore -> dir = criaArvore ( arvore -> dir, x, op ) ;

    }

    return arvore ;

}

int main ( void )
{

    pNo arvore = NULL ;

    pNo percorre = arvore ;

    size_t len = 0 ;

    char *preOrdem = malloc ( len * sizeof ( char ) );
    char *emOrdem = malloc ( len * sizeof ( char ) );
    int* vizita ;

    while ( scanf("%s[^ ]", preOrdem) != EOF && scanf ( "%s", emOrdem ) != EOF )
    {

        int i = 0 ;
        int j = 0 ;
        int per = 0 ;
        int ant ;
        int avanca = 0 ;
        int op = 0 ;
        int sair = 0 ;

        while ( preOrdem [ i ] != '\0' )
        {

           if ( strlen ( emOrdem ) != 1 )
           {

               char c1 = preOrdem [ 0 ] ;
               char c2 = emOrdem [ 0 ] ;

               while ( c1 != c2 )
               {

                   j ++ ;

                   c2 = emOrdem [ j ] ;

               }

               ant = j ;

               int tam = strlen ( emOrdem ) ;

               // caso para adicionar o primeiro nó a esquerda
               if ( per == 0 )
               {

                   per = 1 ;

                   arvore = criaArvore ( arvore, c1, op ) ;

               }


               i++ ;

               vizita = malloc ( tam * sizeof ( int ) ) ;

               for ( int l = 0; l < strlen ( emOrdem ); l++ )
               {

                   vizita [ l ] = 0 ;

               }

               c1 = preOrdem [ i ] ;
               vizita [ j ] = 1 ;

               for ( int k = j - 1; sair != 1 && k != ant ; k-- )
               {

                   c2 = emOrdem [ k ] ;

                   // adicionando a esquerda
                   if ( c2 == c1 && k >= 0 )
                   {

                       op = 0 ;

                       arvore = criaArvore ( arvore, c1 , op ) ;

                       i ++ ;
                       avanca ++ ;

                       vizita [ k ] = 1 ;

                       printf("\nPrintando o vetor suporte : \n") ;

                       for ( int i = 0; i < tam; i++ )
                       {

                           printf("%d ", vizita [ i ] ) ;

                       }

                       printf("\n") ;

                       c1 = preOrdem [ i ] ;

                   }

                   if ( k == 0 && i <= ant )
                   {

                       for ( k = 1; k != ant; k++ )
                       {

                           c2 = emOrdem [ k ] ;

                           percorre = arvore ;

                           if ( c2 == c1 )
                           {

                               for ( int l = 0 ; l < avanca; l++ )
                               {

                                   percorre = percorre -> esq ;

                               }

                               op = 1 ;

                               percorre = criaArvore ( percorre, c1, op ) ;

                               i ++ ;

                               c1 = preOrdem [ i ] ;

                               vizita [ k ] = 1 ;

                           }

                           else
                           {

                               avanca -- ;

                               printf("\nPrintando o vetor suporte : \n") ;

                               for ( int i = 0; i < tam; i++ )
                               {

                                   printf("%d ", vizita [ i ] ) ;

                               }

                               printf("\n") ;

                               while ( c2 != c1 )
                               {

                                   k ++ ;

                                   c2 = emOrdem [ k ] ;

                               }

                               op = 1 ;

                               c2 = emOrdem [ k - 1 ] ;

                               vizita [ k ] = 1 ;

                               for ( int l = 0 ; l < avanca; l++ )
                               {

                                   percorre = percorre -> esq ;

                               }

                               int m = k - 1 ;

                               i++ ;

                               percorre = criaArvore ( percorre, c1, op ) ;
                               percorre = percorre -> dir ;

                               while ( vizita [ m ] != 1 )
                               {

                                   op = 0 ;

                                   i ++ ;

                                   percorre = criaArvore ( percorre, c2, op ) ;

                                   vizita [ m ] = 1 ;

                                   printf("\nPrintando o vetor suporte : \n") ;

                                   for ( int i = 0; i < tam; i++ )
                                   {

                                       printf("%d ", vizita [ i ] ) ;

                                   }

                                   printf("\n") ;

                                   m-- ;

                               }

                               c1 = preOrdem [ i ] ;

                           }

                       }

                       sair = 1 ;

                   }

                   else if ( k < 0 )
                   {

                       sair = 1 ;

                   }

               }

               if ( j + 1 != tam )
               {

                   j++ ;

                   c2 = emOrdem [ j ] ;
                   c1 = preOrdem [ i ] ;

                   while ( c2 != c1 )
                   {

                        j++ ;

                        c2 = emOrdem [ j ] ;

                   }

                   i++ ;
                   c1 = preOrdem [ i ] ;

                   vizita [ j ] = 1 ;
                   op = 1 ;

                   sair = 0 ;

                   arvore = criaArvore ( arvore, c2, op ) ;

                   avanca = 1 ;

                   for ( int k = j + 1; sair == 0 && k != ant; k++ )
                   {

                        c1 = preOrdem [ k ];
                        c2 = emOrdem [ k ];

                        if ( k >= tam )
                        {

                          sair = 1 ;

                        }

                        if ( c1 == c2 && k < tam )
                        {

                            vizita [ k ] = 1;

                            op = 1;

                            avanca ++ ;

                            arvore = criaArvore(arvore, c1, op);

                            printf("\nPrintando o vetor suporte : \n");

                            for (int i = 0; i < tam; i++)
                            {

                              printf("%d ", vizita[i]);

                            }

                            printf("\n");

                        }

                        else if ( k == tam )
                        {

                            for ( int m = k - 1; m > ant ; m-- )
                            {

                                percorre = arvore -> dir ;

                                c1 = preOrdem [ i ] ;
                                c2 = emOrdem [ m ] ;

                                if ( vizita [ m ] == 1 )
                                {

                                    avanca -- ;

                                }

                                else if ( avanca >= 0 )
                                {

                                    while ( c1 != c2 )
                                    {

                                        m -- ;
                                        c2 = emOrdem [ m ] ;

                                    }

                                    for ( int l = 0; l < avanca; l++ )
                                    {

                                        percorre = percorre -> esq ;

                                    }

                                    i++ ;
                                    vizita [ m ] = 1 ;
                                    avanca ++ ;

                                    op = 0 ;

                                    percorre = criaArvore ( percorre, c1, op ) ;

                                    c1 = preOrdem [ i ] ;

                                    int l = m + 1 ;

                                    if ( vizita [ l ] == 0 )
                                    {

                                        for ( int b = 0; b < avanca; b++ )
                                        {

                                            percorre = percorre -> esq ;

                                        }

                                        op = 1 ;

                                        vizita [ l ] = 1 ;

                                        percorre = criaArvore ( percorre, c1, op ) ;

                                        i ++ ;
                                        l ++ ;

                                    }

                                }

                                else
                                {

                                    sair = 1 ;

                                }

                            }

                        }

                   }

               }

           }

           else
           {

               char c1 = preOrdem [ 0 ] ;

               arvore = criaArvore ( arvore, c1 , op ) ;

               i++ ;

           }

        }

        posOrdem ( arvore ) ;
        printf("\n") ;

        arvore = NULL ;

    }

    return 0 ;

}