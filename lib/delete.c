#include <stdio.h>
#include <string.h>
#include "delete.h"
#include "view.h"
#include "universal_function.h"
#include "abstract_data_type.h"

void removeToDoList(To_Do_List_Node **main_node) {
    To_Do_List_Node *prev = NULL, *temp = *main_node;
    char will_delete[50];
    
    viewAll(temp, 0);

    printf("Masukan nama tugas yang ingin dihapus : ");
    scanf("%[^\n]", will_delete);
    getchar();

    while(temp != NULL && strcmp(temp->nama_tugas, will_delete)) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL) {
        puts("\n Nama tugas yang anda masukkan tidak ada");
        return;
    }
    

    if (prev == NULL) *main_node = (*main_node)->next;
    else prev->next = temp->next;
}
