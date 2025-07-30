
#include "readutil.h"

#include <iostream>
#include <limits>
#include <ctime>
#include <cstdlib>

using namespace std;

namespace readutil {

    READUTIL_API string readLine( string msg ) {
        string nome;
        cin.ignore();
        cout << msg;
        getline( cin, nome );
        return nome;
    }

    READUTIL_API int readInt( string msg, string errorMsg ) {
        int num;

        cout << msg;
        while( !(cin >> num) ) {
            cout << errorMsg << endl;
            cin.clear();
            cin.ignore( numeric_limits<streamsize>::max(), '\n' );
            cout << msg;
        }
        return num;
    }

    READUTIL_API int readDouble( string msg, string errorMsg ) {
        double num;

        cout << msg;
        while( !(cin >> num) ) {
            cout << errorMsg << endl;
            cin.clear();
            cin.ignore( numeric_limits<streamsize>::max(), '\n' );
            cout << msg;
        }
        return num;
    }

}
