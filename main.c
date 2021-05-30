#include <stdio.h>
#include <string.h>
#include "lib/our_module.h"

int main() {
    int menu;
    To_Do_List_Node *main_node = NULL;
    date date_now;

    initToDoListFromFile(&main_node);
    while(1) {
        clearTheScreen();
        puts("==============");
        puts("| MENU UTAMA |");
        puts("==============");
        puts(" 1. Add");
        puts(" 2. Edit");
        puts(" 3. View");
        puts(" 0. Exit");
        puts("==============");
        printf("Input : ");
        scanf("%d", &menu);
        getchar();

        if (menu == 1) {
            clearTheScreen();
            addProcess(&main_node);
            tahan();
        }
        else if (menu == 2) {
            while (1) {
                clearTheScreen();
                puts("===============");
                puts("|  MENU EDIT  |");
                puts("===============");
                puts(" 1. Update");
                puts(" 2. Remove");
                puts(" 0. Back");
                puts("===============");
                printf("Input : ");
                scanf("%d", &menu);
                getchar();

                if (menu == 1) {
                    while (1) {
                        clearTheScreen();
                        puts("=====================");
                        puts("|    MENU UPDATE    |");
                        puts("=====================");
                        puts(" 1. Nama tugas");
                        puts(" 2. Kelompok tugas");
                        puts(" 3. Prioritas");
                        puts(" 4. Deadline");
                        puts(" 0. Back");
                        puts("=====================");
                        printf("Input : ");
                        scanf("%d", &menu);
                        getchar();
                        if (menu == 1) {
                            if (isEmpty(main_node)) {
                                tahan();
                                continue;
                            }
                            editNamaTugas(&main_node);
                            tahan();
                        }
                        else if (menu == 2) {
                            if (isEmpty(main_node)) {
                                tahan();
                                continue;
                            }
                            editKelompokTugas(&main_node);
                            tahan();
                        }
                        else if (menu == 3) {
                            if (isEmpty(main_node)) {
                                tahan();
                                continue;
                            }
                            editPrioritas(&main_node);
                            tahan();
                        }
                        else if (menu == 4) {
                            if (isEmpty(main_node)) {
                                tahan();
                                continue;
                            }
                            editDeadline(&main_node);
                            tahan();
                        }
                        else if (menu == 0) {
                            break;
                        }
                        else {
                            puts("\nPilih antara angka 0 hingga 4");
                                getchar();
                                continue;
                        }
                    }
                }
                else if (menu == 2) {
                    if (isEmpty(main_node)) {
                        tahan();
                        continue;
                    }
                    removeToDoList(&main_node);
                    tahan();
                }
                else if (menu == 0) {
                    break;
                }
                else {
                    puts("\nPilih antara angka 0 hingga 2");
                    getchar();
                    continue;
                }
                overwriteFile(&main_node);
            }
        }
        else if (menu == 3) {
            while (1) {
                clearTheScreen();
                puts("===========================");
                puts("|        MENU VIEW        |");
                puts("===========================");
                puts(" 1. Lihat semua to-do list");
                puts(" 2. Cari spesifik");
                puts(" 3. Sort menurut kelompok");
                puts(" 4. Sort menurut prioritas");
                puts(" 5. Sort menurut deadline");
                puts(" 0. Back");
                puts("===========================");
                printf("Input : ");
                scanf("%d", &menu);
                getchar();

                if (menu == 1) {
                    clearTheScreen();
                    if (isEmpty(main_node)) {
                        tahan();
                        continue;
                    }
                    viewAll(main_node, 0);
                    tahan();
                }
                else if (menu == 2) {
                    clearTheScreen();
                    if (isEmpty(main_node)) {
                        tahan();
                        continue;
                    }
                    while(1) {
                        clearTheScreen();
                        puts("=========================");
                        puts("|     Cari Spesifik     |");
                        puts("=========================");
                        puts(" 1. Nama tugas");
                        puts(" 2. Kelompok tugas");
                        puts(" 0. Back");
                        puts("=========================");
                        printf("Input : ");
                        scanf("%d", &menu);
                        getchar();
                    
                        if (menu > 0 && menu < 3) {
                            clearTheScreen();
                            viewSpecific(main_node, menu);
                            tahan();
                        }
                        else if (menu == 0) {
                            break;
                        }
                        else {
                            puts("\nPilih antara angka 0 hingga 2");
                            tahan();
                            continue;
                        }
                    }
                }
                else if (menu == 3) {
                    clearTheScreen();
                    if (isEmpty(main_node)) {
                        tahan();
                        continue;
                    }
                    sortKelompok(main_node);
                    tahan();
                }
                else if (menu == 4) {
                    clearTheScreen();
                    if (isEmpty(main_node)) {
                        tahan();
                        continue;
                    }
                    sortPriority(main_node);
                    tahan();
                }
                else if (menu == 5) {
                    clearTheScreen();
                    if (isEmpty(main_node)) {
                        tahan();
                        continue;
                    }
                    sortDeadline(main_node);
                    tahan();
                }
                else if (menu == 0) break;
                else {
                    puts("\nPilih antara angka 0 hingga 5");
                    tahan();
                    continue;
                }
            }
        }
        else if (menu == 0) break;
        else {
            puts("\nPilih antara angka 0 hingga 3");
            tahan();
            continue;
        }
    }
    return 0;
}