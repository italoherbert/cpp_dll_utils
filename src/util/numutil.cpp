
#include "numutil.h"

#include <ctime>
#include <cstdlib>

using namespace std;

namespace numutil {

    NUMUTIL_API int sorteiaNumero() {
        srand( time( 0 ) );

        return rand() % 100;
    }

}
