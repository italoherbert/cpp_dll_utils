
#include "arrayutil.h"
#include "comp/Comparador.h"
#include "comp/MenorComparador.h"
#include "comp/MaiorComparador.h"

namespace arrayutil {

    ARRAY_UTIL_API bool verificaSeArraysIguais( int* a1, int* a2, int tam ) {
        return verificaSeArraysIguais2( a1, a2, tam );
    }

    ARRAY_UTIL_API int* copiaVetor( int* vetor, int tam ) {
        return copiaVetor2( vetor, tam );
    }


    ARRAY_UTIL_API void selectionSort( int* vetor, int tam ) {
        selectionSort2( vetor, tam );
    }

    ARRAY_UTIL_API void inversoSelectionSort( int* vetor, int tam ) {
        inversoSelectionSort2( vetor, tam );
    }



    template <typename T>
    bool verificaSeArraysIguais2( T* a1, T* a2, int tam ) {
        for( int i = 0; i < tam; i++ )
            if ( a1[ i ] != a2[ i ] )
                return false;
        return true;
    }

    template <typename T>
    T* copiaVetor2( T* vetor, int tam ) {
        T* vetor2 = new T[ tam ];
        for( int i = 0; i < tam; i++ )
            vetor2[ i ] = vetor[ i ];
        return vetor2;
    }


    template <typename T>
    void selectionSort2( T* vetor, int tam ) {
        selectionSort2( vetor, tam, new MenorComparador<T>() );
    }

    template <typename T>
    void inversoSelectionSort2( T* vetor, int tam ) {
        selectionSort2( vetor, tam, new MaiorComparador<T>() );
    }

    template <typename T>
    void selectionSort2( T* vetor, int tam, Comparador<T>* comp ) {
        for( int i = 0; i < tam-1; i++ ) {
            int menor_j = i;
            for( int j = i+1; j < tam; j++ )
                if ( comp->compara( vetor[ j ], vetor[ i ] ) )
                    menor_j = j;

            if ( menor_j != i ) {
                int aux = vetor[ i ];
                vetor[ i ] = vetor[ menor_j ];
                vetor[ menor_j ] = aux;
            }
        }
    }

}
