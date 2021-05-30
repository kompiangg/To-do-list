#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "edit.h"
#include "universal_function.h"
#include "our_module.h"

void editNamaTugas(To_Do_List_Node **main_node){
    To_Do_List_Node *temp = *main_node;
    char new[50], huruf[50];
    printf("Masukkan nama tugas yang ingin dicari: ");
    scanf("%[^\n]", &huruf);
    
    while(temp!=NULL){
        if (strcmp(temp->nama_tugas,huruf)==0){
            printf("Masukkan nama tugas baru: ");
            scanf(" %49[^\n]",&new);
            getchar();
            strcpy(temp->nama_tugas, new);
            puts("Data berhasil disimpan");
            return ;
        }
        temp=temp->next;
    }

    if (temp == NULL) {
        puts("DATA yang Anda cari tidak ada!");
    }
}


void editKelompokTugas(To_Do_List_Node **main_node){
    To_Do_List_Node *temp = *main_node;
    char new[50], huruf[50];

    printf("Masukkan nama tugas yang ingin dicari: ");
    scanf(" %49[^\n]", &huruf);

    while(temp!=NULL){
        if (strcmp(temp->nama_tugas,huruf)==0){
            printf("Masukkan kelompok tugas baru: ");
            scanf(" %49[^\n]",&new);
            strcpy(temp->kelompok_tugas, new);
            puts("Data berhasil disimpan");
            return;
        }
        temp=temp->next;

    }

    if (temp == NULL) {
        puts("DATA yang Anda cari tidak ada!");
    }

    
}

void editPrioritas(To_Do_List_Node **main_node){
    To_Do_List_Node *temp = *main_node;
    int new;
    char huruf[50];

    printf("Masukkan nama tugas yang ingin dicari: ");
    scanf(" %49[^\n]", &huruf);

    while (temp!=NULL){
        if (strcmp(temp->nama_tugas,huruf)==0){
            printf("Masukkan prioritas tugas baru (1-4): ");
            scanf("%d",&new);
            getchar();
            
            temp->prioritas = new;
            puts("Data berhasil disimpan!");
            return;
        }
        temp=temp->next;
    }
    
    if (temp == NULL) {
        puts("DATA yang Anda cari tidak ada!");
    }
}

void editDeadline(To_Do_List_Node **main_node){
    To_Do_List_Node *temp = *main_node, temp_input, *token;
    int new;
    char huruf[50];
    date date_now;
    getTheDate(&date_now);

    printf("Masukkan nama tugas yang ingin dicari: ");
    scanf(" %49[^\n]", &huruf);


    while (temp!=NULL){
        if (strcmp(temp->nama_tugas,huruf)==0){
            
            while(1){
                printf("Masukkan deadline tugas baru (dd/mm/yyyy): ");
                scanf("%d/%d/%d", &temp_input.dl_dd, &temp_input.dl_mm, &temp_input.dl_yyyy);
                getchar();
                if (temp_input.dl_dd < date_now.dd && temp_input.dl_mm < date_now.mm \
                    && temp_input.dl_yyyy < date_now.yyyy) {
                        puts("\n=== TIDAK BOLEH MEMASUKAN TANGGAL ===");
                        puts("  === SEBELUM TANGGAL HARI INI ===\n");
                        continue;
                    }else {
                        temp->dl_dd=temp_input.dl_dd;
                        temp->dl_mm=temp_input.dl_mm;
                        temp->dl_yyyy=temp_input.dl_yyyy;
                        puts("Data berhasil disimpan!");
                        break;
                    }
            }
            return;
             
        }
        temp=temp->next;
        
    }
    
    if (temp == NULL) {
        puts("DATA yang Anda cari tidak ada!");
    }
}