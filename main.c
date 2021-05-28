#include <stdio.h>
#include <string.h>
#include "lib/our_module.h"

    To_Do_List_Node *main_node = NULL;
    

int main() {
    int menu;
    date date_now;

    getTheDate(&date_now);
    initToDoListFromFile(&main_node, date_now);
    while(1) {
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
            addProcess(&main_node, date_now);
        }
        else if (menu == 2) {
            // Tampilkan semua to-do list yang ada dengan urutan
            // User akan memilih nomor tersebut
            while (1) {
                puts("===============");
                puts("|  MENU EDIT  |");
                puts("===============");
                puts(" 1. Update");
                puts(" 2. Remove");
                puts(" 0. Exit");
                puts("===============");
                printf("Input : ");
                scanf("%d", &menu);
                getchar();

                if (menu == 1) {
                    while (1) {
                        puts("=====================");
                        puts("|    MENU UPDATE    |");
                        puts("=====================");
                        puts(" 1. Nama tugas");
                        puts(" 2. Kelompok tugas");
                        puts(" 3. Prioritas");
                        puts(" 4. Deadline");
                        puts(" 0. Exit");
                        puts("=====================");
                        printf("Input : ");
                        scanf("%d", &menu);
                        getchar();
                        if (menu == 1) {
                            
                        }
                        else if (menu == 2) {

                        }
                        else if (menu == 3) {

                        }
                        else if (menu == 4) {

                        }
                        else if (menu == 0) {
                            puts("\nPilih antara angka 0 hingga 2");
                        }
                        else {

                        }
                    }
                }
                else if (menu == 2) {
                    	while(1){
                        puts("=====================");
                        puts("|    MENU REMOVE    |");
                        puts("=====================");
   						puts(" 1. Remove Nama tugas");
                        puts(" 2. Remove Kelompok tugas");
                        puts(" 3. Remove Prioritas");
                        puts(" 4. Remove Deadline");
                        puts(" 0. Exit");
                        puts("=====================");
                        printf("Input : ");
                        scanf("%d", &menu);
                        getchar();
                        if (menu == 1) {
                            
                        }
                        else if (menu == 2) {
                          
                        }
                        else if (menu == 3) {

                        }
                        else if (menu == 4) {

                        }
                        else if (menu == 0) {
                            puts("\nPilih antara angka 0 hingga 2");
                        }
                        else {

                        }
                    }                       

                }
                else if (menu == 0) {
                    break;
                }
                else {
                    puts("\nPilih antara angka 0 hingga 2");
                    getchar();
                    continue;
                }
            }
        }
        else if (menu == 3) {
            while (1) {
                puts("===========================");
                puts("|        MENU VIEW        |");
                puts("===========================");
                puts(" 1. Lihat semua to-do list");
                puts(" 2. Cari spesifik");
                puts(" 3. Sort menurut kelompok");
                puts(" 4. Sort menurut prioritas");
                puts(" 5. Sort menurut deadline");
                puts(" 0. Exit");
                puts("===========================");
                printf("Input : ");
                scanf("%d", &menu);
                getchar();

                if (menu == 1) {
                      
                }
                else if (menu == 2) {

                }
                else if (menu == 3) {

                }
                else if (menu == 4) {

                }
                else if (menu == 0) break;
                else {
                    puts("\nPilih antara angka 0 hingga 4");
                    getchar();
                    continue;
                }
            }
        }
        else if (menu == 0) break;
        else {
            puts("\nPilih antara angka 0 hingga 3");
            getchar();
            continue;
        }
    }
    return 0;
}
