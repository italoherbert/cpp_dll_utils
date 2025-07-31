
#include "testesutil.h"

#include <sstream>

teste_error::teste_error( string msg ) : runtime_error( msg ) {

}

Testes::Testes( string nome ) {
    this->nome = nome;
}

void Testes::add( string nome, function<void()> f ) {
    Func func;
    func.nome = nome;
    func.f = f;
    funcs.push_back( func );
}

bool Testes::executa() {
    int tam = funcs.size();

    bool sucesso = true;
    bool results[ tam ];
    string error = "";
    int errorI = -1;

    for( int i = 0; i < tam; i++ ) {
        try {
            funcs[ i ].f();
            results[ i ] = true;
        } catch ( const teste_error& e ) {
            error = e.what();
            errorI = i;

            results[ i ] = false;
            sucesso = false;
        } catch ( const exception& e ) {
            error = e.what();
            errorI = i;

            results[ i ] = false;
            sucesso = false;
        }
    }

    cout << "Executando ( " << nome << " testes ) - ";
    if ( sucesso )
        cout << "Ok" << endl;
    else cout << "Falha" << endl;

    for( int i = 0; i < tam; i++ ) {
        cout << "\t" << funcs[i].nome << " - ";

        if ( results[ i ] )
            cout << "Ok" << endl;
        else cout << "Falha" << endl;

        if ( i == errorI )
            cout << "\nErro: " << error << "\n" << endl;
    }
    cout << endl;

    return sucesso;
}

namespace testesutil {

    template <typename T>
    void verificaSeIguais2( T, T );

    template <typename T>
    void verificaSeIguais2( T*, T*, int );

    template <typename T>
    void verificaSeIguais2( vector<T>, vector<T> );


    template <typename T>
    void verificaSeDiferentes2( T, T );

    template <typename T>
    void verificaSeDiferentes2( T*, T*, int );

    template <typename T>
    void verificaSeDiferentes2( vector<T>, vector<T> );


    template <typename T>
    string stringValores( string, T, T );

    template <typename T>
    string stringVetores( string, T*, T*, int );

    template <typename T>
    string stringVetores( string, vector<T>, vector<T> );



    TESTES_UTIL_API void verificaSeNulo( void* ptr ) {
        if(  ptr != NULL )
            throw teste_error( "Ponteiro não nulo." );
    }

    TESTES_UTIL_API void verificaSeNaoNulo( void* ptr ) {
        if(  ptr == NULL )
            throw teste_error( "Ponteiro nulo." );
    }


    TESTES_UTIL_API void verificaSeIguais( void* p1, void* p2 ) {
        if ( p1 != p2 )
            throw teste_error( "Ponteiros diferentes." );
    }

    TESTES_UTIL_API void verificaSeIguais( int n1, int n2 ) {
        verificaSeIguais2( n1, n2 );
    }

    TESTES_UTIL_API void verificaSeIguais( double n1, double n2 ) {
        verificaSeIguais2( n1, n2 );
    }

    TESTES_UTIL_API void verificaSeIguais( float n1, float n2 ) {
        verificaSeIguais2( n1, n2 );
    }

    TESTES_UTIL_API void verificaSeIguais( string s1, string s2 ) {
        verificaSeIguais2( s1, s2 );
    }

    TESTES_UTIL_API void verificaSeIguais( int* v1, int* v2, int tam ) {
        verificaSeIguais2( v1, v2, tam );
    }

    TESTES_UTIL_API void verificaSeIguais( vector<int> v1, vector<int> v2 ) {
        verificaSeIguais2( v1, v2 );
    }


    TESTES_UTIL_API void verificaSeDiferentes( void* p1, void* p2 ) {
        if ( p1 == p2 )
            throw teste_error( "Ponteiros iguais." );
    }

    TESTES_UTIL_API void verificaSeDiferentes( int n1, int n2 ) {
        verificaSeDiferentes2( n1, n2 );
    }

    TESTES_UTIL_API void verificaSeDiferentes( double n1, double n2 ) {
        verificaSeDiferentes2( n1, n2 );
    }

    TESTES_UTIL_API void verificaSeDiferentes( float n1, float n2 ) {
        verificaSeDiferentes2( n1, n2 );
    }

    TESTES_UTIL_API void verificaSeDiferentes( string s1, string s2 ) {
        verificaSeDiferentes2( s1, s2 );
    }

    TESTES_UTIL_API void verificaSeDiferentes( int* v1, int* v2, int tam ) {
        verificaSeDiferentes2( v1, v2, tam );
    }

    TESTES_UTIL_API void verificaSeDiferentes( vector<int> v1, vector<int> v2 ) {
        verificaSeDiferentes2( v1, v2 );
    }


    template <typename T>
    void verificaSeIguais2( T v1, T v2 ) {
        if ( v1 != v2 )
            throw teste_error( stringValores( "Valores diferentes -> ", v1, v2 ) );
    }

    template <typename T>
    void verificaSeIguais2( T* v1, T* v2, int tam ) {
        bool iguais = true;
        for( int i = 0; iguais && i < tam; i++ )
            if ( v1[ i ] != v2[ i ] )
                iguais = false;

        if ( !iguais )
            throw teste_error( stringVetores( "diferentes", v1, v2, tam ) );
    }

    template <typename T>
    void verificaSeIguais2( vector<T> v1, vector<T> v2 ) {
        int tam = v1.size();

        bool iguais = v1.size() == v2.size();
        for( int i = 0; iguais && i < tam; i++ )
            if ( v1[ i ] != v2[ i ] )
                iguais = false;

        if ( !iguais )
            throw teste_error( stringVetores( "diferentes", v1, v2 ) );
    }


    template <typename T>
    void verificaSeDiferentes2( T v1, T v2 ) {
        if ( v1 == v2 )
            throw teste_error( stringValores( "Valores iguais -> ", v1, v2 ) );
    }

    template <typename T>
    void verificaSeDiferentes2( T* v1, T* v2, int tam ) {
        bool diferentes = true;
        for( int i = 0; diferentes && i < tam; i++ )
            if ( v1[ i ] == v2[ i ] )
                diferentes = false;

        if ( !diferentes )
            throw teste_error( stringVetores( "iguais", v1, v2, tam ) );
    }

    template <typename T>
    void verificaSeDiferentes2( vector<T> v1, vector<T> v2 ) {
        int tam = v1.size();

        bool diferentes = true;
        if ( v1.size() == v2.size() ) {
            for( int i = 0; diferentes && i < tam; i++ )
                if ( v1[ i ] == v2[ i ] )
                    diferentes = false;
        }

        if ( !diferentes )
            throw teste_error( stringVetores( "iguais", v1, v2 ) );
    }


    template <typename T>
    string stringValores( string msg, T v1, T v2 ) {
        stringstream v1ss;
        v1ss << v1;
        stringstream v2ss;
        v2ss << v2;

        return msg + v1ss.str() + " e " + v2ss.str();
    }

    template <typename T>
    string stringVetores( string message, T* v1, T* v2, int tam ) {
        string msg = " " + message;

        msg += "\nVetor(1)= ";
        for( int i = 0; i < tam; i++ )
            msg += v1[ i ] + " ";
        msg += "\nVetor(2)= ";
        for( int i = 0; i < tam; i++ )
            msg += v2[ i ] + " ";

        return msg;
    }

    template <typename T>
    string stringVetores( string message, vector<T> v1, vector<T> v2 ) {
        string msg = " " + message;

        msg += "\nVetor(1)= ";
        for( int i = 0; i < (int)v1.size(); i++ ) {
            stringstream ss;
            ss << v1[ i ];
            msg += ss.str() + " ";
        }
        msg += "\nVetor(2)= ";
        for( int i = 0; i < (int)v2.size(); i++ ) {
            stringstream ss;
            ss << v2[ i ];
            msg += ss.str() + " ";
        }

        return msg;
    }

}
