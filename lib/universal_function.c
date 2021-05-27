#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "universal_function.h"

void clear() {
    #ifdef _WIN32
        system("cls");
    #elif __linux__
        system("clear");
    #endif
}

void getTheDate(date *date_now) {
    time_t time_now;
    time(&time_now);
    struct tm *time_now_converted = localtime(&time_now);
    date_now->dd = time_now_converted->tm_mday;
    date_now->mm = time_now_converted->tm_mon + 1;
    date_now->yyyy = time_now_converted->tm_year + 1900;
}

char *lowerTheSentence(char *sentence) {
    for (int i = 0 ; sentence[i] ; i++) sentence[i] = tolower(sentence[i]);
    return sentence;
}