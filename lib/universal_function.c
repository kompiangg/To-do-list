#include <stdio.h>
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

int isEmpty(To_Do_List_Node *main_node) {
    if (main_node == NULL) {
        puts("To-do list masih kosong");
        return 1;
    }
    return 0;
}

void clearTheScreen() {
    clear();
    puts("Program To-do list\n");
}

void tahan() {
    puts("\nTekan enter untuk melanjutkan...");
    getchar();
}

void overwriteFile(To_Do_List_Node **main_node){
    To_Do_List_Node *temp = *main_node;
    FILE *read_and_write = fopen("file\\to_do_list.txt", "w+");
    while(temp != NULL) {
        fprintf(read_and_write, "%s|%s|%d|%d/%d/%d\n",temp->nama_tugas, temp->kelompok_tugas,\
                                                    temp->prioritas, temp->dl_dd,\
                                                    temp->dl_mm, temp->dl_yyyy);
        temp = temp->next;
    }
    fclose(read_and_write);
}