g++.exe -Wall -g -DBUILDING_DLL  -c C:\Users\italo\workspace-cpp\dlls\Utils\src\util\arrayutil.cpp -o obj\Debug\src\util\arrayutil.o
g++.exe -Wall -g -DBUILDING_DLL  -c C:\Users\italo\workspace-cpp\dlls\Utils\src\util\comp\MaiorComparador.cpp -o obj\Debug\src\util\comp\MaiorComparador.o
g++.exe -Wall -g -DBUILDING_DLL  -c C:\Users\italo\workspace-cpp\dlls\Utils\src\util\comp\MenorComparador.cpp -o obj\Debug\src\util\comp\MenorComparador.o
g++.exe -Wall -g -DBUILDING_DLL  -c C:\Users\italo\workspace-cpp\dlls\Utils\src\util\numutil.cpp -o obj\Debug\src\util\numutil.o
g++.exe -Wall -g -DBUILDING_DLL  -c C:\Users\italo\workspace-cpp\dlls\Utils\src\util\readutil.cpp -o obj\Debug\src\util\readutil.o
g++.exe -Wall -g -DBUILDING_DLL  -c C:\Users\italo\workspace-cpp\dlls\Utils\src\util\strutil.cpp -o obj\Debug\src\util\strutil.o
g++.exe -Wall -g -DBUILDING_DLL  -c C:\Users\italo\workspace-cpp\dlls\Utils\src\util\vectutil.cpp -o obj\Debug\src\util\vectutil.o
g++.exe -shared -Wl,--output-def=bin\Debug\libUtils.def -Wl,--out-implib=bin\Debug\libUtils.a -Wl,--dll  obj\Debug\src\util\arrayutil.o obj\Debug\src\util\comp\MaiorComparador.o obj\Debug\src\util\comp\MenorComparador.o obj\Debug\src\util\numutil.o obj\Debug\src\util\readutil.o obj\Debug\src\util\strutil.o obj\Debug\src\util\vectutil.o  -o bin\Debug\Utils.dll  -luser32
