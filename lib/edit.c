#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "edit.h"
#include "our_module.h"

void editNamaTugas(To_Do_List_Node **main_node){
    To_Do_List_Node *temp = main_node;
    char new[50], huruf[50];
    printf("Masukkan nama tugas yang ingin dicari: ");
    scanf("%[^\n]", &huruf);
    
    if (temp!=NULL){
        while(1){
            if (strcmp(temp->nama_tugas,huruf)==0){
                printf("Masukkan nama tugas baru: ");
                scanf(" %49[^\n]",&new);
                getchar();
                strcpy(temp->nama_tugas, new);
                puts("Data berhasil disimpan");
            }
            if (temp==NULL){
                temp=temp->next;
            }else {
                puts("DATA yang Anda cari tidak ada!");
                break;
            }
        }
    
    }
}


void editKelompokTugas(To_Do_List_Node **main_node){
    To_Do_List_Node *temp = main_node;
    char new[50], huruf[50];

    printf("Masukkan nama tugas yang ingin dicari: ");
    scanf(" %49[^\n]", &huruf);

    while(temp!=NULL){
        if (strcmp(temp->nama_tugas,huruf)==0){
            printf("Masukkan kelompok tugas baru: ");
            scanf(" %49[^\n]",&new);
            strcpy(temp->kelompok_tugas, new);
            return;

        }
        if (temp==NULL){
            temp=temp->next;
        }else {
            puts("DATA yang Anda cari tidak ada!");
            break;
        }
    }
}

void editPrioritas(To_Do_List_Node **main_node){
    To_Do_List_Node *temp = main_node;
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
        if (temp==NULL){
            temp=temp->next;
        }else {
            puts("DATA yang Anda cari tidak ada!");
            break;
        }
      
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
            temp=temp->next; 
        }else{
            puts("DATA yang Anda cari tidak ada!");
        }
        break;
    }
     
    
}

//MASIH BELUM FIX
void delete(To_Do_List_Node **main_node){
    To_Do_List_Node *temp = *main_node, *prev;

    prev = temp;
    char new[50],huruf[50];
    int baru;


    printf("Masukkan nama tugas yang ingin dihapus : ");
    scanf("%[^\n]", &huruf);

    while (temp!=NULL)
    {
        if (temp == *main_node)
        {
            if (strcmp(temp->nama_tugas, huruf) == 0)
            {
                *main_node = temp->next;
                free(temp);
                printf("Node berhasil dihapus");
                return;
            }
        }
        else
        {
            while (temp != NULL)
            {
                prev = temp;
                    temp = temp->next;
            }

            prev->next = temp->next;
            free(temp);
        }

    }

}

void overwriteFile(To_Do_List_Node **main_node){
    To_Do_List_Node *temp = main_node;
    FILE *read_and_write = fopen("file\\to_do_list.txt", "w+");
    fprintf(read_and_write, "%s|%s|%d|%d/%d/%d\n",temp->nama_tugas, temp->kelompok_tugas,\
                                                  temp->prioritas, temp->dl_dd,\
                                                  temp->dl_mm, temp->dl_yyyy);
    fclose(read_and_write);

}


