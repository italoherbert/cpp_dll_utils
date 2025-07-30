
#include "strutil.h"

#include <iostream>

namespace strutil {

    STRUTIL_API std::string toLower( std::string str ) {
        std::string lower = str;
        for( long long unsigned int i = 0; i < lower.length(); i++ )
            lower[ i ] = std::tolower( lower[ i ] );
        return lower;

    }

    STRUTIL_API bool startsWith( std::string str, std::string ini ) {
        return str.compare( 0, ini.size(), ini ) == 0;
    }

}
