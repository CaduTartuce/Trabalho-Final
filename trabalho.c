#include  <stdio.h>
#include  <string.h>
#include  <ctype.h>
#include  <stdbool.h>
#include  <stdlib.h>

struct  info_veiculos
{
    char  proprietário [ 100 ];
    int  combustivel;
    char modelo [ 40 ];
    char  cor [ 15 ];
    int chassi;
    int  anoDoCarro;
    char  placa [ 11 ];
    int  tipoCombustivel;
};

void  limparBuffer ()
{
    enquanto (( c  =  getchar ()) !=  '\n'  &&  c  !=  EOF );
}

void  cadastrarVeiculo ( struct  info_veiculos  * * veículos , int  * totalVeiculos );
{
    * veículos  =  realloc ( * veículos , ( * totalVeiculos  +  1 ) *  sizeof ( struct  info_veiculos ));

    if ( * veículos  ==  NULL )
    {
        printf ( "Erro ao alocar memória para o veículo.\n" );
        retornar ;
    };
    limparBuffer ();
    printf ( "Informações do proprietário: " );
    fgets (( * veículos )[ * totalVeiculos ]. proprietário , sizeof (( * veículos )[ * totalVeiculos ]. proprietário ), stdin );
    flush ( stdin );

    printf ( "Informe o combustível em litros: " );
    scanf ( "%d" , & ( * veículos )[ * totalVeiculos ]. combustivel );
    flush ( stdin );

    printf ( "Qual tipo de combustível? 1- Álcool / 2- Diesel / 3- Gasolina: " );
    scanf ( "%d" , & ( * veiculos )[ * totalVeiculos ]. tipoCombustivel );
    flush ( stdin );

    printf ( "Informe o modelo: " );
    fgets (( * veículos )[ * totalVeiculos ]. modelo , sizeof (( * veículos )[ * totalVeiculos ]. modelo ), stdin );

    printf ( "Informe o cor: " );
    fgets (( * veículos )[ * totalVeiculos ]. cor , sizeof (( * veículos )[ * totalVeiculos ]. cor ), stdin );

    int  chassisExistente ;

    fazer {
        chassisExistente  =  0 ;  

        printf ( "Informa o número do chassi: " );
        flush ( stdin );
        scanf ( "%d" , & ( * veiculos )[ * totalVeiculos ]. chassis );
        flush ( stdin );

        for ( int  i  =  0 ; i  <  * totalVeiculos ; i ++ ) {
            if (( * veículos )[ i ]. chassi  == ( * veículos )[ * totalVeiculos ]. chassi ) {
                printf ( "Erro: Este chassi já foi cadastrado. Por favor, informe um novo número de chassi.\n" );
                chassisExistente  =  1 ;
                quebrar ;
            }
        }

    } while ( chassiExistente );

    printf ( "Informe o ano do carro: " );
    flush ( stdin );
    scanf ( "%d" , & ( * veiculos )[ * totalVeiculos ].anoDoCarro ) ;
    flush ( stdin );

    int  placaValida  =  0 ;
    fazer {
        printf ( "Informe a Placa do carro: " );
        fgets (( * veículos )[ * totalVeiculos ]. placa , sizeof (( * veículos )[ * totalVeiculos ]. placa ), stdin );

        int  eu ;
        para ( eu  =  0 ; eu  <  3 ; eu ++ ) {
            if (! isalpha (( * veículos )[ * totalVeiculos ]. placa [ i ])) {
                printf ( "Erro: Os primeiros 3 caracteres da placa devem ser letras.\n" );
                quebrar ;
            }
        }
        se ( eu  ==  3 ) {
            para (; eu  <  7 ; eu ++ ) {
                if (! isdigit (( * veículos )[ * totalVeiculos ]. placa [ i ])) {
                    printf ( "Erro: Os últimos 4 caracteres da placa devem ser números.\n" );
                    quebrar ;
                }
            }
        }
        se ( eu  ==  7 ) {
            placaValida  =  1 ;
        }
    } while (! placaValida );

    printf ( "Veículo cadastrado com sucesso!\n" );
    ( * totalVeiculos ) ++ ;
    printf ( "-----------------------------------------------------------\n " );
    printf ( "Total de veículos cadastrados até o momento: %d\n" , * totalVeiculos );
}

void  listarProprietarios ( struct  info_veiculos  * veiculos , int  totalVeiculos )
{

    int  retornar ;
    printf ( "Proprietários dos veículos do ano de 2010 ou posterior e movidos a diesel:\n \n" );
    for ( int  i  =  0 ; i  <  totalVeiculos ; i ++ )
    {
        if ( veículos [ i ]. anoDoCarro >= 2010  &&  veículos [ i ]. tipoCombustivel  ==  2 )
        {
            printf ( "Proprietário: %s\n Veículo: %s\n Placa: %s" , veículos [ i ]. proprietário , veículos [ i ]. modelo , veículos [ i ]. placa );
            printf ( "-----------------------------------------------------------\n " );
        }
    }
    printf ( "Deseja retornar ao menu de operações? (1) = Sim / (0) = Fechar o programa\n Digite: " );
    scanf ( "%d" , & retornar );

    mudar ( retornar )
    {
    caso  1 :
        retornar ;
        quebrar ;

    caso  0 :
        sair ( retornar );
        quebrar ;

    padrão :
        retornar ;
        quebrar ;
    }
}

void  listarPlacasJ ( struct  info_veiculos  * veiculos , int  totalVeiculos )
{
    int  retornar ;

    printf ( "Placas que começam com a letra J e terminam com 0, 2, 4 ou 7 e seus respectivos proprietários:\n" );
    for ( int  i  =  0 ; i  <  totalVeiculos ; i ++ )
    {
        if ( veículos [ i ]. placa [ 0 ] ==  'J'  &&
            ( veículos [ i ]. placa [ 6 ] ==  '0'  ||  veículos [ i ]. placa [ 6 ] ==  '2'  ||  veículos [ i ]. placa [ 6 ] ==  '4'  ||  veículos [ i ]. placa [ 6 ] ==  '7' ))
        {

            size_t  len  ​​=  strlen ( veículos [ i ]. proprietário );
            if ( len  >  0  &&  veículos [ i ]. proprietário [ len  -  1 ] ==  '\n' )
            {
                veículos [ i ]. proprietário [ len  -  1 ] =  '\0' ;
            }

            printf ( "Placa: %s \nProprietário: %s\n" , veículos [ i ]. placa , veículos [ i ]. proprietário );
            printf ( "-----------------------------------------------------------\n " );
        }
    }

    printf ( "-----------------------------------------------------------\n " );
    printf ( "Deseja retornar ao menu de operações? (1) = Sim / (0) = Fechar o programa\nDigite: " );
    scanf ( "%d" , & retornar );

    mudar ( retornar )
    {
    caso  1 :
        retornar ;
        quebrar ;

    caso  0 :
        sair ( retornar );
        quebrar ;

    padrão :
        retornar ;
        quebrar ;
    }
}

void  listarModelosCores ( struct  info_veiculos  * veiculos , int  totalVeiculos )
{
    printf ( "Modelos e núcleos dos veículos (placas com segunda letra vogal e soma dos valores numéricos e par):\n" );

    for ( int  i  =  0 ; i  <  totalVeiculos ; i ++ )
    {
        if ( strchr ( "AEIOUaeiou" , veículos [ i ]. placa [ 1 ]) !=  NULL )
        {
            int  somaNúmeros  =  0 ;
            for ( int  j  =  0 ; j  <  strlen ( veículos [ i ]. placa ); j ​​++ )
            {
                if ( isdigit ( veículos [ i ]. placa [ j ]))
                {
                    somaNumeros  =  somaNumeros  *  10  + ( veículos [ i ]. placa [ j ] -  '0' );
                }
            }

            if ( somaNúmeros % 2  ==  0 )
            {
                size_t  lenModelo  =  strlen ( veículos [ i ]. modelo );
                if ( lenModelo  >  0  &&  veículos [ i ]. modelo [ lenModelo  -  1 ] ==  '\n' )
                {
                    veículos [ i ]. modelo [ lenModelo  -  1 ] =  '\0' ;
                }

                size_t  lenCor  =  strlen ( veículos [ i ]. cor );
                if ( lenCor  >  0  &&  veículos [ i ]. cor [ lenCor  -  1 ] ==  '\n' )
                {
                    veículos [ i ]. cor [ lenCor  -  1 ] =  '\0' ;
                }

                printf ( "Modelo: %s, Cor: %s\n" , veículos [ i ]. modelo , veículos [ i ]. cor );
                printf ( "-----------------------------------------------------------\n " );
            }
        }
    }
}

void  trocarProprietario ( struct  info_veiculos  * veiculos , int  totalVeiculos ) {
    int  numeroChassi ;

    printf ( "Informe o número do chassi para troca de proprietário: " );
    scanf ( "%d" , & numeroChassi );
    limparBuffer ();

    int  índiceVeiculo  =  -1 ;
    for ( int  i  =  0 ; i  <  totalVeiculos ; i ++ ) {
        if ( veículos [ i ]. chassi  ==  numeroChassi  && ! strchr ( veículos [ i ]. placa , '0' )) {
            índiceVeiculo  =  i ;
            quebrar ;
        }
    }

    if ( índiceVeiculo  ==  -1 ) {
        printf ( "Nenhum veículo encontrado com o número do chassi informado ou a placa possui dígito zero.\n" );
    } outro {
        printf ( "Informe o novo proprietário: " );
        fgets ( veículos [ índiceVeiculo ]. proprietário , sizeof ( veículos [ índiceVeiculo ]. proprietário ), stdin );
        flush ( stdin );

        printf ( "Proprietário trocado com sucesso!\n" );
    }

    printf ( "---------------------------------------------------------- ----------------\n" );
}

int  principal ()
{
    struct  info_veiculos  * veiculos  =  NULL ;
    int  totalVeiculos  =  0 ;
    int  switchOptions ;

    fazer
    {
        printf ( "-----------------------------------------------------------\n " );
        printf ( "Selecione uma opção:\n 1- Cadastrar um novo veículo\n 2- Listar proprietários (cujos carros são do ano de 2010 ou posterior e que sejam movidos a diesel.)\n 3- Listar Placas que começam com a letra J e terminem com 0, 2, 4 ou 7 e seus respectivos proprietários.\n 4- Listar modelos e núcleos dos veículos (cujas placas possuem como segunda letra uma vogal e cujo soma dos valores numéricos fornece um número par.)\n 5 - Trocar proprietário do veículo (apenas para carros com placas que não possuam nenhum dígito igual a zero.)\n 0- Sair\n Digite: " );
        scanf ( "%d" e switchOptions ) ;
        printf ( "-----------------------------------------------------------\n " );

        switch ( switchOptions )
        {
        caso  1 :
            cadastrarVeiculo ( &veículos , &totalVeiculos );

            quebrar ;
        caso  2 :
            listarProprietarios (  veículos , &totalVeiculos );

            quebrar ;
        caso  3 :
            listarPlacasJ ( &veículos , &totalVeiculos );

            quebrar ;
        caso  4 :
            listarModelosCores ( &veículos , &totalVeiculos );
            quebrar ;
        caso  5 :
            trocarProprietário ( &veículos , &totalVeiculos );
            quebrar ;
        caso  0 :
            printf ( "Saindo do programa.\n" );
            quebrar ;
        padrão :
            printf ( "Opção invalida. Tente novamente.\n" );
        }
    } while ( switchOptions  ! =  0 );

    grátis ( veículos );

    retornar  0 ;
}