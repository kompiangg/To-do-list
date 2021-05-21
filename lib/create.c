#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "create.h"

To_Do_List_Node *makeNode(To_Do_List_Node temp_input) {
    To_Do_List_Node *head = NULL, *temp_ptr, *temp_head;
    
    temp_ptr = (To_Do_List_Node *) malloc(sizeof(To_Do_List_Node));
    temp_ptr->next = NULL;
    temp_ptr->prev = NULL;
    strcpy(temp_ptr->nama_tugas, temp_input.nama_tugas);
    strcpy(temp_ptr->kelompok_tugas, temp_input.kelompok_tugas);
    temp_ptr->prioritas = temp_input.prioritas;
    temp_ptr->dl_dd = temp_input.dl_dd;
    temp_ptr->dl_mm = temp_input.dl_mm;
    temp_ptr->dl_yyyy = temp_input.dl_yyyy;

    if(head == NULL) head = temp_ptr;
    else {
        temp_head = head;
        while (temp_head->next != NULL) temp_head = temp_head->next;
        temp_head->next = temp_ptr;
        temp_ptr->prev = temp_head;
    }
    return head;
}

void insert(To_Do_List_Node *main_node, To_Do_List_Node temp_input) {
    
}

void helpAddProcess(int menu) {
    if (menu == 1) {
        
    }
    else if (menu == 2) {

    }
    else if (menu == 3) {

    }
    else if (menu == 4) {

    }
}

void addProcess(To_Do_List_Node *main_node) {
    To_Do_List_Node temp_input;
    char temp_text_prioritas[50], temp_text_date[50], *token;
    int back, back_to = 1;

    while (1) {
        back = 0;
        printf("\n  ======= Guide =======  \n");
        printf("Selamat datang di add proses\n");
        printf("apabila Anda bingung tentang\n");
        printf("properti yang akan diisi,\n");
        printf("Anda dapat menginputkan -h\n");
        printf("untuk memanggil menu help\n\n");
        printf("Apabila anda ingin kembali\n");
        printf("ke menu sebelumnya, Anda\n");
        printf("dapat menginputkan -b untuk\n");
        printf("kembali ke menu sebelumnya\n\n");
        
        printf("====================\n");
        printf("| Input to-do list |\n");
        printf("====================\n");

        if (back_to > 0) back_to--;

        while (1) {
            if (back == 0 && back_to == 0) {
                printf(" * Nama Tugas : ");
                scanf("%[^\n]", temp_input.nama_tugas);
                getchar();
            }
            if (strcmp(temp_input.nama_tugas, "-h") == 0) {
                helpAddProcess(1);
                continue;
            }
            else if (strcmp(temp_input.nama_tugas, "-b") == 0) {
                printf("\nIni adalah field pertama, anda tidak dapat menggunakan menu ini");
                break;
            }
            break;
        }

        if (back_to > 0) back_to--;

        while (1) {
            if (back == 0 && back_to == 0) {
                printf(" * Kelompok Tugas : ");
                scanf("%[^\n]", temp_input.kelompok_tugas);
                getchar();
            }
            if (strcmp(temp_input.kelompok_tugas, "-h") == 0) {
                helpAddProcess(2);
                continue;
            }
            else if (strcmp(temp_input.nama_tugas, "-b") == 0) {
                back = 1;
                back_to = 1;
                break;
            }
            break;
        }

        if (back == 1) continue;
        if (back_to > 0) back_to--;
        
        while(1) {
            if (back == 0 && back_to == 0) {
                printf(" * Prioritas : ");
                scanf("%[^\n]", temp_text_prioritas);
                getchar();
                temp_input.prioritas = atoi(temp_text_prioritas);
            }
            if (strcmp(temp_text_prioritas, "-h") == 0) {
                helpAddProcess(3);
                continue;
            }
            else if (strcmp(temp_text_prioritas, "-b") == 0) {
                back = 1;
                back_to = 2;
                break;
            }
            break;
        }

        if (back == 1) continue;
        if (back_to > 0) back_to--;
        
        while (1) {
            if (back == 0 && back_to == 0) {
                printf(" * Deadline (dd/mm/yyyy) : ");
                scanf("%[^%\n]", temp_text_date);
                getchar();

                token = strtok(temp_text_date, "/");
                temp_input.dl_dd = atoi(token);
                token = strtok(NULL, "/");
                temp_input.dl_mm = atoi(token);
                token = strtok(NULL, "/");
                temp_input.dl_yyyy = atoi(token);
            }
            if (strcmp(temp_text_date, "-h") == 0) {
                helpAddProcess(4);
                continue;
            }
            else if (strcmp(temp_text_date, "-b") == 0) {
                back = 1;
                back_to = 3;
                break;
            }
            break;
        }

        if (back == 1) continue;
        break;
    }
}