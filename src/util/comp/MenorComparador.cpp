
#include "MenorComparador.h"

template <typename T>
int MenorComparador<T>::compara( T n1, T n2 ) {
    return n1 < n2;
}

template class MenorComparador<int>;
template class MenorComparador<double>;
template class MenorComparador<float>;
