#include <stdio.h>
#include <stdlib.h>

typedef struct Lista
{

    double dado ;
    struct Lista *a ;
    struct Lista *b ;

} Lista ;

typedef Lista *pNo ;

void imprimeLista ( pNo lista )
{

    pNo percorre ;

    for ( percorre = lista; percorre != NULL; percorre = percorre -> b )
    {

        printf("%0.4lf ", percorre -> dado ) ;

    }

    printf("\n") ;

}

// função que retorna o tamanho da lista, além de adicionar um novo nó na mesma
int adicionaElemento ( pNo *lista, double x, int i, int tam )
{

    pNo novoNo =  malloc ( sizeof ( Lista ) ) ;
    pNo percorre ;
    pNo post ;

    int k = 0 ;

    // caso da lista estar vazia
    if ( *lista == NULL )
    {

        (*lista) = malloc ( sizeof ( Lista ) ) ;

        (*lista) -> dado = x ;
        (*lista) -> a = 0 ;
        (*lista) -> b = 0 ;

        return 1 ;

    }

    // caso queira adicionar o elemento da lista no começo dela
    if ( i == 0 )
    {

        novoNo -> dado = x ;
        novoNo -> b = *lista ;
        novoNo -> a = 0 ;

        (*lista) -> a = novoNo ;

        (*lista) = novoNo ;

        tam += 1 ;

        return tam ;

    }

    // caso queira adicionar um elemento no rabo da lista
    if ( i >= ( tam - 1 ) )
    {

        novoNo -> dado = x ;
        novoNo -> a = 0 ;
        novoNo -> b = 0 ;

        for ( percorre = *lista; percorre -> b != NULL; percorre = percorre -> b ) ;

        percorre -> b = novoNo ;
        novoNo -> a = percorre ;

        tam += 1 ;

        return tam ;

    }

    for ( percorre = *lista; percorre != NULL; percorre = percorre -> b )
    {

        if ( k + 1 == i )
        {

            pNo salva = percorre ;

            novoNo -> dado = x ;
            novoNo -> a = salva ;

            post = salva -> b ;
            post -> a = novoNo ;

            novoNo -> b = post ;

            novoNo -> a = percorre ;
            percorre -> b = novoNo ;

            tam += 1 ;

            return tam ;

        }

        k++ ;

    }

}

void reverse ( pNo *head_ref )
{

    pNo temp = NULL;
    pNo current = *head_ref;

    /* swap next and prev for all nodes of
      doubly linked list */
    while (current !=  NULL)
    {
        temp = current-> a ;
        current-> a = current-> b ;
        current-> b = temp ;
        current = current-> a ;
    }

    /* Before changing head, check for the cases like empty
       list and list with only one node */
    if(temp != NULL )
        *head_ref = temp->a ;

}

void reverteLista ( pNo* lista, int tam )
{

    pNo atual = *lista ;

    pNo targetN1 ;
    pNo targetN2 ;
    pNo post ;
    pNo aux ;
    pNo salva ;
    pNo ant ;
    pNo percorreAux ;

    pNo percorre = atual;

    int n1 ;
    int n2 ;

    int i ;
    int k ;

    scanf(" %d %d", &n1, &n2 ) ;

    if ( n1 == 0 && n2 == ( tam - 1 ) )
    {

        reverse ( &(*lista) ) ;

        return ;

    }

    if ( n1 != n2  && (*lista) != NULL )
    {

        if ( n2 == ( tam - 1 ) )
        {

            for ( i = 0; ( i + 1 ) != n1; i++ )
            {

                percorre = percorre -> b ;

            }

            ant = percorre ;

            targetN1 = percorre -> b ;

            aux = targetN1 ;

            salva = aux ;

            salva -> a = 0 ;

            for ( k = i; ( k + 1 ) != n2; k++ )
            {

                percorre = percorre -> b ;


            }

            targetN2 = percorre -> b ;

            reverse ( &salva ) ;

            ant -> b = salva ;
            salva -> a = ant ;

            return ;

        }

        else if ( n1 != 0 )
        {

            for ( i = 0; ( i + 1 ) != n1; i++ )
            {

                percorre = percorre -> b ;

            }

            ant = percorre ;

            targetN1 = percorre -> b ;

            aux = targetN1 ;

            salva = aux ;

            for ( k = i; ( k + 1 ) != n2; k++ )
            {

                percorre = percorre -> b ;

                if ( aux != NULL )
                {

                    aux = aux -> b ;

                }


            }

            targetN2 = percorre -> b ;

            post = targetN2 -> b ;

            if ( aux != NULL )
            {

                aux -> b = 0 ;

            }

            reverse ( &salva ) ;

            percorreAux = salva ;

            for ( int j = n2; j >= ( n1 - 1 ) ; j-- )
            {

                percorreAux = percorreAux -> b ;

            }

            percorreAux -> b = post ;

            post -> a = percorreAux ;

            ant -> b = salva ;

            salva -> a = ant ;

            return ;

        }

        else
        {

            pNo percorreAux = percorre ;

            pNo percorreSalva ;

            salva = percorre ;

            for ( i = 0; ( i + 1 ) != n2; i++ )
            {

                percorre = percorre -> b ;
                percorreAux = percorreAux -> b ;

            }

            targetN1 = percorre -> b ;

            post = targetN1 -> b ;

            percorreAux -> b -> b = 0 ;

            reverse ( &salva ) ;

            for ( percorreSalva = salva; percorreSalva -> b != NULL; percorreSalva = percorreSalva -> b ) ;

            percorreSalva -> b = post ;
            post -> a = percorreSalva ;

            (*lista) = salva ;

            return ;

        }

    }

}

int main ( void )
{

    pNo lista = NULL ;

    char op = ' ' ;

    int tam = 0 ;

    while ( op != 't' )
    {

        scanf ( " %c", &op ) ;

        if ( op == 'i' )
        {

            int i ;
            double x ;

            scanf("%d %lf", &i, &x ) ;

            tam = adicionaElemento ( &lista, x, i, tam ) ;

        }

        else if ( op == 'p' )
        {

            imprimeLista ( lista ) ;

        }

        else if ( op == 'v' )
        {

            reverteLista ( &lista, tam ) ;

        }

    }

    return 0 ;

}
