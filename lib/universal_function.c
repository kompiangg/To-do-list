#include <stdlib.h>
#include "universal_function.h"

void clear() {
    #ifdef _WIN32
        system("cls");
    #elif __linux__
        system("clear");
    #endif
}