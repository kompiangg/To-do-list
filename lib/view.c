#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "our_module.h"

int isLeapYear(int year) {
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        return 1;
    else
        return 0;
}

int dateInMonth(int month, int year) {
    int date_month[12] = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month != 2) return date_month[month-1];
    else {
        if (isLeapYear(year) == 1) return 29;
        else return 28;
    }
}

int dayLeft(To_Do_List_Node *temp_main_node) {
    int day_left;
    int day_from_month = 0;
    date date_now;
    getTheDate(&date_now);

    for (int i = date_now.mm ; i < temp_main_node->dl_mm; i++) {
        day_from_month += dateInMonth(i, temp_main_node->dl_yyyy);
    }
    
    day_left = (temp_main_node->dl_dd - date_now.dd) + day_from_month + \
                365 * (temp_main_node->dl_yyyy - date_now.yyyy);
    return day_left;
}

void viewAll(To_Do_List_Node *main_node, int menu) {
    To_Do_List_Node *temp = main_node;
    int nomor = 1, day_left, prioritas = 0, print = 1;

    while (temp != NULL) {
        // Menu 3 (Sort menurut kelompok)
        if (menu == 3 && print == 1) {
            puts("\n=========================");
            printf("Kelompok %s\n", temp->kelompok_tugas);
            puts("=========================\n");
            nomor = 1;
            print = 0;
        }
        if (menu == 3 && temp->next != NULL && strcmp(temp->kelompok_tugas, temp->next->kelompok_tugas)) {
            print = 1;
        }
        // Menu 4 (Sort menurut prioritas)
        while(menu == 4 && temp->prioritas != prioritas) {
            prioritas++;
            nomor = 1;
            print = 1;
        }
        if (menu == 4 && print == 1) {
            puts("\n================");
            printf("Prioritas %d\n", prioritas);
            puts("================\n");
            print = 0;
        }

        day_left = dayLeft(temp);
        printf("%d. Nama tugas    : %s\n", nomor, temp->nama_tugas);
        printf("   Nama kelompok : %s\n", temp->kelompok_tugas);
        printf("   Prioritas     : %d\n", temp->prioritas);
        printf("   Deadline      : %02d/%02d/%d\n", temp->dl_dd, temp->dl_mm, temp->dl_yyyy);
        if (day_left >= 0) printf("   Sisa Waktu    : %d hari\n", day_left);
        else printf("   Sisa Waktu    : TERLAMBAT %d hari\n", abs(day_left));
        temp = temp->next;
        nomor++;
    }
}

void copyLinkedList(To_Do_List_Node **copied_main_node, To_Do_List_Node *temp) {
    while (temp != NULL) {
        *copied_main_node == NULL ? *copied_main_node = makeNode(*temp) : insert(copied_main_node, *temp);
        temp = temp->next;
    }
}

void viewSpecific(To_Do_List_Node *main_node, int menu) {
    To_Do_List_Node *temp = main_node;
    To_Do_List_Node *copied_main_node = NULL;
    copyLinkedList(&copied_main_node, temp);
    int day_left, nomor = 1;
    char will_find[50];
    
    if (menu == 1) {   
        printf("Masukkan nama tugas : ");
        scanf("%[^\n]", will_find);
        getchar();
        while (temp != NULL) {
            if (strcmp(lowerTheSentence(copied_main_node->nama_tugas), lowerTheSentence(will_find)) == 0) {  
                day_left = dayLeft(temp);
                puts("\n==============================");
                printf("%d. Nama tugas    : %s\n", nomor, temp->nama_tugas);
                printf("   Nama kelompok : %s\n", temp->kelompok_tugas);
                printf("   Prioritas     : %d\n", temp->prioritas);
                printf("   Deadline      : %d/%d/%d\n", temp->dl_dd, temp->dl_mm, temp->dl_yyyy);
                if (day_left >= 0) printf("   Sisa Waktu    : %d hari\n", day_left);
                else printf("   Sisa Waktu    : TERLAMBAT %d hari\n", abs(day_left));
                puts("==============================\n");
                nomor++;
            }
            copied_main_node = copied_main_node->next;
            temp = temp->next;
        }   
    }
    else if (menu == 2) {
        printf("Masukkan nama kelompok tugas : ");
        scanf("%[^\n]", will_find);
        getchar();
        while (temp != NULL) {
            if (strcmp(lowerTheSentence(copied_main_node->kelompok_tugas), lowerTheSentence(will_find)) == 0) {  
                day_left = dayLeft(temp);             
                printf("\n%d. Nama tugas    : %s\n", nomor, temp->nama_tugas);
                printf("   Nama kelompok : %s\n", temp->kelompok_tugas);
                printf("   Prioritas     : %d\n", temp->prioritas);
                printf("   Deadline      : %d/%d/%d\n", temp->dl_dd, temp->dl_mm, temp->dl_yyyy);
                if (day_left >= 0) printf("   Sisa Waktu    : %d hari\n", day_left);
                else printf("   Sisa Waktu    : TERLAMBAT %d hari\n", abs(day_left));
                nomor++;
            }
            copied_main_node = copied_main_node->next;
            temp = temp->next;
        }
    }
    if (temp == NULL && nomor == 1) puts("\nTo-do list yang anda cari tidak ada");
}

void swapValueLinkedList(To_Do_List_Node **node1, To_Do_List_Node **node2) {
    To_Do_List_Node temp;
    
    strcpy(temp.nama_tugas, (*node1)->nama_tugas);
    strcpy(temp.kelompok_tugas, (*node1)->kelompok_tugas);
    temp.prioritas = (*node1)->prioritas;
    temp.dl_dd = (*node1)->dl_dd;
    temp.dl_mm = (*node1)->dl_mm;
    temp.dl_yyyy = (*node1)->dl_yyyy;

    strcpy((*node1)->nama_tugas, (*node2)->nama_tugas);
    strcpy((*node1)->kelompok_tugas, (*node2)->kelompok_tugas);
    (*node1)->prioritas = (*node2)->prioritas;
    (*node1)->dl_dd = (*node2)->dl_dd;
    (*node1)->dl_mm = (*node2)->dl_mm;
    (*node1)->dl_yyyy = (*node2)->dl_yyyy;
    
    strcpy((*node2)->nama_tugas, temp.nama_tugas);
    strcpy((*node2)->kelompok_tugas, temp.kelompok_tugas);
    (*node2)->prioritas = temp.prioritas;
    (*node2)->dl_dd = temp.dl_dd;
    (*node2)->dl_mm = temp.dl_mm;
    (*node2)->dl_yyyy = temp.dl_yyyy;   
}


void selectionSortList(To_Do_List_Node **main_node, int menu) {
    To_Do_List_Node *min;
    for (To_Do_List_Node *current = *main_node ; current != NULL ; current = current->next) {
        min = current;
        for (To_Do_List_Node *index = current->next ; index != NULL ; index = index->next) {
            if (menu == 1 && min->prioritas > index->prioritas) min = index;
            else if (menu == 2 && dayLeft(min) > dayLeft(index)) min = index;
        }
        swapValueLinkedList(&min, &current);
    }
}

void sortKelompok(To_Do_List_Node *main_node) {
    int banyak_kelompok = 0;
    To_Do_List_Node *temp = main_node;
    To_Do_List_Node *copied_main_node = NULL;
    copyLinkedList(&copied_main_node, temp);

    for (To_Do_List_Node *current = copied_main_node ; current != NULL ; current = current->next) {
        for (To_Do_List_Node *index = current->next ; index != NULL ; index = index->next) {
            if(!strcmp(current->kelompok_tugas, index->kelompok_tugas) && current->next != NULL) {
                swapValueLinkedList(&index, &(current->next));
                break;
            }
        }
    }

    viewAll(copied_main_node, 3);
}

void sortPriority(To_Do_List_Node *main_node) {
    To_Do_List_Node *temp = main_node;
    To_Do_List_Node *copied_main_node = NULL;


    copyLinkedList(&copied_main_node, temp);
    selectionSortList(&copied_main_node, 1);

    viewAll(copied_main_node, 4);
}

void sortDeadline(To_Do_List_Node *main_node) {
    To_Do_List_Node *copied_main_node = NULL;
    To_Do_List_Node *temp = main_node;

    copyLinkedList(&copied_main_node, temp);
    selectionSortList(&copied_main_node, 2);

    viewAll(copied_main_node, 0);
}