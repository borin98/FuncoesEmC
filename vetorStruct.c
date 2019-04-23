#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Pessoa
{

    int idade ;
    float peso ;
    float altura ;
    char *nome ;

} Pessoa ;

typedef struct Pessoa *pNo ;

pNo criaCadastro ( pNo p, int i )
{

    char *nomeAux = malloc ( 50* sizeof ( char ) ) ;
    int idade ;
    float peso ;
    float altura ;
    int c ;

    printf("\n---------- Cadastro %d ----------\n", i ) ;

    printf("\nDigite o nome da pessoa : ") ;
    fgets ( nomeAux, 50, stdin ) ;

    printf("\nDigite a idade da pessoa : ") ;
    scanf ("%d", &idade) ;

    printf("\nDigite o peso da pessoa : ") ;
    scanf("%f", &peso) ;

    printf("\nDigite a altura da pessoa : ") ;
    scanf("%f", &altura) ;

    p -> idade = idade ;
    p -> peso = peso ;
    p -> altura = altura ;
    p -> nome = nomeAux ;

    printf("\n-------------------------------------\n" ) ;

    return p ;

}

pNo inicializaPessoa (  )
{

    pNo p = malloc ( sizeof ( Pessoa ) ) ;

    p -> idade = 0 ;
    p -> peso = 0 ;
    p -> altura = 0 ;
    p -> nome = malloc ( 50* sizeof ( char ) ) ;

    return p ;

}

int main ( void )
{

    int n ;
    int c ;

    printf("Digite quantas pessoas serão inseridas no vetor : ") ;
    scanf("%d",&n) ;
    c = getchar() ;

    pNo vetorPessoas = malloc ( n* sizeof ( Pessoa ) ) ;

    for ( int i = 0; i < n; i++ )
    {

        pNo p = inicializaPessoa (  ) ;

        p = criaCadastro ( p, i ) ;

        vetorPessoas [ i ].nome = p -> nome ;
        vetorPessoas [ i ].idade = p -> idade ;
        vetorPessoas [ i ].altura = p -> altura ;
        vetorPessoas [ i ].peso = p -> peso ;

        c = getchar (  ) ;

    }

    for ( int i = 0; i < n; i++ )
    {

        printf("\n------------- Cadastro %d -------------\n", i ) ;

        printf("Nome : %s\n", vetorPessoas [ i ].nome ) ;
        printf("Idade : %d anos\n", vetorPessoas [ i ].idade ) ;
        printf("peso : %0.2f Kg\n", vetorPessoas [ i ].peso ) ;
        printf("Altura : %0.2f metros\n", vetorPessoas [ i ].altura ) ;

        printf("---------------------------------------\n") ;

    }

    return 0 ;

}
