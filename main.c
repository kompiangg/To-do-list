#include <stdio.h>
#include <string.h>
#include "lib/our_module.h"

To_Do_List_Node *main_node = NULL;

int main() {
    int menu;
    // date date_now;

    // getTheDate(&date_now);
    initToDoListFromFile(main_node);
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
            addProcess(main_node);
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
                    To_Do_List_Node *temp = main_node;
                    int nomor = 1;
                    while (temp != NULL) {
                        printf("\n%d. Nama tugas    : %s\n", nomor, temp->nama_tugas);
                        printf("   Nama kelompok : %s\n", temp->kelompok_tugas);
                        printf("   Prioritas     : %s\n", temp->prioritas);
                        printf("   Deadline      : %d/%d/%d\n", temp->dl_dd, temp->dl_mm, temp->dl_yyyy);
                        printf("   Sisa Waktu    : %d\n\n", dayLeft(temp));
                        temp = temp->next;
                        nomor++;
                    }
                }
                // viewAll(main_node);
                else if (menu == 2) {
                    while(1) {
                        puts("=========================");
                        puts("|     Cari Spesifik     |");
                        puts("=========================");
                        puts(" 1. Nama tugas");
                        puts(" 2. Kelompok tugas");
                        puts(" 0. Exit");
                        puts("=========================");
                        printf("Input : ");
                        scanf("%d", &menu);
                        getchar();
                    
                        if (menu > 0 && menu < 3) {
                            viewSpecific(main_node, menu);
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

                }
                else if (menu == 4) {
                    sortPriority(main_node);
                }
                else if (menu == 5) {
                    sortDeadline(main_node);
                }
                else if (menu == 0) break;
                else {
                    puts("\nPilih antara angka 0 hingga 5");
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