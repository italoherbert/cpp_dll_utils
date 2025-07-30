
#include "MaiorComparador.h"

template <typename T>
int MaiorComparador<T>::compara( T n1, T n2 ) {
    return n1 > n2;
}

template class MaiorComparador<int>;
template class MaiorComparador<double>;
template class MaiorComparador<float>;
