#include <stdlib.h>
#include <stdio.h>

typedef struct No
{

    int dado ;
    struct No *prox ;

}No;

typedef struct No *pNo ;

void adicionaTail ( pNo* lista, int dado )
{

    pNo percorre ;
    pNo novoNo = malloc ( sizeof ( No ) ) ;

    if ( *lista == NULL )
    {

        (*lista) = malloc ( sizeof ( No ) ) ;
        (*lista) -> dado = dado ;
        (*lista) -> prox = 0 ;

        return ;

    }

    for ( percorre = *lista; percorre -> prox != NULL; percorre = percorre -> prox ) ;

    novoNo -> dado = dado ;
    percorre -> prox = novoNo ;

}

void printaLista ( pNo lista )
{

    pNo percorre ;

    for ( percorre = lista; percorre != NULL; percorre = percorre -> prox )
    {

        printf("%d ", percorre -> dado ) ;

    }

}

void removeNo ( pNo *lista, pNo percorre )
{

    pNo ant ;

    pNo temp = *lista ;

    if ( temp -> dado == percorre -> dado ) // caso em que ele é o primeiro da lista
    {

        temp = percorre -> prox ;
        free ( percorre ) ;

    }

    // armazena os nós futuros
    while ( temp != NULL && temp -> dado != percorre -> dado )
    {

        ant = temp ;
        temp = temp -> prox ;

    }

    ant -> prox = temp -> prox ;

    free ( temp ) ;

}

int removeNos ( pNo *listaA, pNo *listaB )
{

    int remove = 0 ;

    pNo percorreA = *listaA ;
    pNo copiaA = *listaA ;
    pNo auxA ;

    pNo percorreB = *listaB ;
    pNo copiaB = *listaB ;
    pNo auxB ;

    while ( percorreB != NULL )
    {

        //copiaA = *listaA ;
        percorreA = copiaA ;

        //copiaB = *listaB ;

        while ( percorreA != NULL )
        {

            pNo salvaA = copiaA ;
            pNo prevA = copiaA ;

            pNo salvaB = copiaB ;
            pNo prevB = copiaB ;

            if ( percorreA -> dado == percorreB -> dado )
            {

                remove ++ ;

                // caso o nó seja a cabeça para remoção
                if ( percorreA -> dado == salvaA -> dado )
                {

                    copiaA = salvaA -> prox ;
                    free ( salvaA ) ;

                }

                else
                {

                    while ( salvaA != NULL && salvaA -> dado != percorreA -> dado )
                    {

                        prevA = salvaA ;

                        salvaA = salvaA -> prox ;

                    }

                    if ( salvaA != NULL )
                    {

                        prevA -> prox = salvaA -> prox ;

                    }

                    free ( salvaA ) ;

                }

                // caso o nó seja a cabeça para remoção
                if ( percorreB -> dado == salvaB -> dado )
                {

                    copiaB = salvaB -> prox ;
                    free ( salvaB ) ;

                }

                else
                {

                    while ( salvaB != NULL && salvaB -> dado != percorreB -> dado )
                    {

                        prevB = salvaB ;
                        salvaB = salvaB -> prox ;

                    }

                    if ( salvaB != NULL )
                    {

                        prevB -> prox = salvaB -> prox ;

                    }

                    free ( salvaB ) ;

                }

            }

            percorreA = percorreA -> prox ;

        }

        percorreB = percorreB -> prox ;

    }

    (*listaA) = copiaA ;
    (*listaB) = copiaB ;

    return remove ;

}

void liberaMemoria ( pNo* p )
{

   pNo aux ;

   for ( aux = *p; aux != NULL; aux = aux -> prox )
   {

       free ( aux ) ;

   }

   *p = aux ;

}


int main ( void )
{

    pNo listaA = NULL ;
    pNo listaB = NULL ;

    int n ;
    int dado ;
    int remove ;

    scanf("%d", &n) ;

    for ( int i = 0; i < n; i++ )
    {

        scanf ( "%d", &dado ) ;

        adicionaTail ( &listaA, dado ) ;

    }

    for ( int i = 0; i < n; i ++ )
    {

        scanf ( "%d", &dado ) ;

        adicionaTail ( &listaB ,dado ) ;

    }

    printf("\n") ;

    printf("Antes da remoção\n\n") ;

    printf("Lista A : ");
    printaLista ( listaA ) ;
    printf("\n") ;

    printf("Lista B : ");
    printaLista ( listaB ) ;
    printf("\n") ;

    printf("\nDepois da remoção \n") ;

    remove = removeNos ( &listaA, &listaB ) ;

    printf( "Quantidade de nós removidos : %d\n", remove ) ;

    printf("Lista A : ");
    printaLista ( listaA ) ;
    printf("\n") ;

    printf("Lista B : ");
    printaLista ( listaB ) ;
    printf("\n") ;

    liberaMemoria ( &listaA ) ;
    liberaMemoria ( &listaB ) ;


    return 0 ;

}