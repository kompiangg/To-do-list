#include <stdio.h>
#include <string.h>
#include "lib/our_module.h"

To_Do_List_Node *main_node = NULL, *temp;
int edit_no;
char temp_text_prioritas[5], temp_text_date[10], *token;

void view(To_Do_List_Node *main_node){
    int no_tugas = 1;
    printf("\nIsi Data : \n");
    while(main_node != NULL){
        printf("\n%d. nama tugas : %s", no_tugas, main_node->nama_tugas);
        main_node = main_node->next;
        no_tugas++;
    }
    puts(" ");
}

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
            clear();
            // Tampilkan semua to-do list yang ada dengan urutan
            view(main_node);

            // User akan memilih nomor tersebut
            printf("\nTugas mana yang ingin Anda edit? \n>> ");
            scanf("%d", &edit_no);

            for(int i = 1; i<edit_no; ++i){
                temp = temp->next;
            }
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
                            printf(" * Nama Tugas : ");
                            scanf("%[^\n]", temp->nama_tugas);
                            getchar();
                        }
                        else if (menu == 2) {
                            printf(" * Kelompok Tugas : ");
                            scanf("%[^\n]", temp->kelompok_tugas);
                            getchar();
                        }
                        else if (menu == 3) {
                            printf(" * Prioritas (1-4): ");
                            scanf("%[^\n]", temp_text_prioritas);
                            getchar();
                            temp->prioritas = atoi(temp_text_prioritas);
                            if (temp->prioritas < 1 && temp->prioritas > 4) {
                                puts("\nMasukan angka antara 1 hingga 4\n");
                            }
                        }
                        else if (menu == 4) {
                            printf(" * Deadline (dd/mm/yyyy) : ");
                            scanf("%[^%\n]", temp_text_date);
                            getchar();

                            token = strtok(temp_text_date, "/");
                            temp->dl_dd = atoi(token);
                            token = strtok(NULL, "/");
                            temp->dl_mm = atoi(token);
                            token = strtok(NULL, "/");
                            temp->dl_yyyy = atoi(token);
                        }
                        else if (menu == 0) {
                            puts("\nPilih antara angka 0 hingga 2");
                        }
                        else {

                        }
                    }
                }
                else if (menu == 2) {
                    //belum selesai
                    if(strcmp(head->nim, find) == 0){
                    del = head;
                    head = head->next;
                    head->prev = NULL;
                    free(del);
                } else (strcmp(del->nim, find) == 0){
                    del->prev->next = del->next;
                    del->next->prev = del->prev;
                    free(del);
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
