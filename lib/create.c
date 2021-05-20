#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "create.h"
#include "abstract_data_type.h"

to_do_list_node *init_linked_list(to_do_list_node temp) {
    to_do_list_node *head = NULL, *temp_ptr, *temp_head;
    
    temp_ptr = (to_do_list_node *) malloc(sizeof(to_do_list_node));
    temp_ptr->next = NULL;
    temp_ptr->prev = NULL;
    strcpy(temp_ptr->nama_tugas, temp.nama_tugas);
    strcpy(temp_ptr->kelompok_tugas, temp.kelompok_tugas);
    temp_ptr->prioritas = temp.prioritas;
    temp_ptr->dl_dd = temp.dl_dd;
    temp_ptr->dl_mm = temp.dl_mm;
    temp_ptr->dl_yyyy = temp.dl_yyyy;

    if(head == NULL) head = temp_ptr;
    else {
        temp_head = head;
        while (temp_head->next != NULL) temp_head = temp_head->next;
        temp_head->next = temp_ptr;
        temp_ptr->prev = temp_head;
    }
    return head;
}