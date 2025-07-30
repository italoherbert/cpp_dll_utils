
#include "numutil.h"

#include <ctime>
#include <cstdlib>

using namespace std;

NUMUTIL_API int sorteiaNumero() {
	srand( time( 0 ) );

	return rand() % 100;
}
