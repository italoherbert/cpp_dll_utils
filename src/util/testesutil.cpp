
#include "testesutil.h"

Testes::Testes( string nome ) {
    this->nome = nome;
}

void Testes::add( string nome, function<bool()> f ) {
    Func func;
    func.nome = nome;
    func.f = f;
    funcs.push_back( func );
}

bool Testes::executa() {
    bool sucesso = true;
    int tam = funcs.size();
    bool results[ tam ];
    for( int i = 0; i < tam; i++ ) {
        results[ i ] = funcs[i].f();
        if ( !results[ i ] )
            sucesso = false;
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
    }
    cout << endl;

    return sucesso;
}

namespace testesutil {

    TESTES_UTIL_API bool verificaSucesso( bool sucesso, string metodoNome ) {
        if ( sucesso )
            cout << metodoNome << " - Ok" << endl;
        else cout << metodoNome << " - Falha" << endl;

        return sucesso;
    }

}
