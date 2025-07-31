
#include "vectutil.h"

#include <algorithm>

namespace vectutil {

    VECTOR_UTIL_API bool verificaSeIguais( vector<int> v1, vector<int> v2 ) {
        int tam = v1.size();
        for( int i = 0; i < tam; i++ )
            if ( v1[ i ] != v2[ i ] )
                return false;
        return true;
    }

    VECTOR_UTIL_API int indice( vector<int> vet, int num ) {
        int tam = vet.size();
        for( int i = 0; i < tam; i++ )
            if ( vet[ i ] == num )
                return i;
        return -1;
    }

    VECTOR_UTIL_API void exibe( string msg, vector<int> vetor ) {
        int tam = vetor.size();

        cout << msg;
        for( int i = 0; i < tam; i++ )
            cout << vetor[ i ] << " ";
        cout << endl;
    }

}
