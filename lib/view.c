#include <stdio.h>
#include <string.h>
#include "our_module.h"

int dayLeft(To_Do_List_Node *temp_main_node) {
    int day_left = 0;
    date date_now;
    day_left = (temp_main_node->dl_dd - date_now.dd) +\
                30 * (temp_main_node->dl_mm - date_now.mm) + \
                365 * (temp_main_node->dl_yyyy - date_now.yyyy);
    return day_left;
}

void viewAll(To_Do_List_Node *main_node) {
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

void viewSpecific(To_Do_List_Node *main_node, int menu) {
    To_Do_List_Node *temp = main_node;
    char will_find[50];
    
    if (menu == 1) {   
        printf("Masukkan nama tugas : ");
        scanf("%[^\n]", will_find);
        while (temp != NULL) {
            if (strcmp(lowerTheSentence(temp->nama_tugas), lowerTheSentence(will_find)) == 0) {               
                printf("\nNama tugas    : %s\n", temp->nama_tugas);
                printf("Nama kelompok : %s\n", temp->kelompok_tugas);
                printf("Prioritas     : %s\n", temp->prioritas);
                printf("Prioritas     : %s\n", temp->prioritas);
                printf("Deadline      : %d/%d/%d\n", temp->dl_dd, temp->dl_mm, temp->dl_yyyy);
                printf("Sisa Waktu    : %d\n\n", dayLeft(temp));
            }
            temp = temp->next;
        }
    }
    else if (menu == 2) {
        printf("Masukkan nama tugas : ");
        scanf("%[^\n]", will_find);
        while (temp != NULL) {
            if (strcmp(lowerTheSentence(temp->kelompok_tugas), lowerTheSentence(will_find)) == 0) {               
                printf("\nNama tugas    : %s\n", temp->nama_tugas);
                printf("Nama kelompok : %s\n", temp->kelompok_tugas);
                printf("Prioritas     : %s\n", temp->prioritas);
                printf("Prioritas     : %s\n", temp->prioritas);
                printf("Deadline      : %d/%d/%d\n", temp->dl_dd, temp->dl_mm, temp->dl_yyyy);
                printf("Sisa Waktu    : %d\n\n", dayLeft(temp));
            }
            temp = temp->next;
        }
    }
    
}

void swapValueLinkedList(To_Do_List_Node *node1, To_Do_List_Node *node2) {
    To_Do_List_Node temp;
    
    strcpy(temp.nama_tugas, node1->nama_tugas);
    strcpy(temp.kelompok_tugas, node1->kelompok_tugas);
    temp.prioritas = node1->prioritas;
    temp.dl_dd = node1->dl_dd;
    temp.dl_mm = node1->dl_mm;
    temp.dl_yyyy = node1->dl_yyyy;

    strcpy(node1->nama_tugas, node2->nama_tugas);
    strcpy(node1->kelompok_tugas, node2->kelompok_tugas);
    node1->prioritas = node2->prioritas;
    node1->dl_dd = node2->dl_dd;
    node1->dl_mm = node2->dl_mm;
    node1->dl_yyyy = node2->dl_yyyy;
    
    strcpy(node1->nama_tugas, temp.nama_tugas);
    strcpy(node1->kelompok_tugas, temp.kelompok_tugas);
    node1->prioritas = temp.prioritas;
    node1->dl_dd = temp.dl_dd;
    node1->dl_mm = temp.dl_mm;
    node1->dl_yyyy = temp.dl_yyyy;   
}

void copyLinkedList(To_Do_List_Node *copied_main_node, To_Do_List_Node *temp) {
    while (temp != NULL) {
        copied_main_node == NULL ? copied_main_node = makeNode(*temp) : insert(copied_main_node, *temp);
    }
}

void selectionSortList(To_Do_List_Node *main_node, int menu) {
    To_Do_List_Node *min;
    for (To_Do_List_Node *current = main_node ; current != NULL ; current = current->next) {
        *min = *current;
        for (To_Do_List_Node *index = current->next ; index != NULL ; index = index->next) {
            if (menu == 1 && min->prioritas < index->prioritas) min = index;
            else if (menu == 2 && dayLeft(min) < dayLeft(index)) min = index;
        }
        swapValueLinkedList(min, current);
    }
}

// Masih mikir
void sortKelompok() {
    int banyak_kelompok = 0;

}

void sortPriority(To_Do_List_Node *main_node) {
    To_Do_List_Node *copied_main_node = NULL;
    To_Do_List_Node *temp = main_node;

    copyLinkedList(copied_main_node, temp);
    selectionSortList(copied_main_node, 1);

    viewAll(copied_main_node);
}

void sortDeadline(To_Do_List_Node *main_node) {
    To_Do_List_Node *copied_main_node = NULL;
    To_Do_List_Node *temp = main_node;

    copyLinkedList(copied_main_node, temp);
    selectionSortList(copied_main_node, 2);

    viewAll(copied_main_node);
}