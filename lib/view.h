#ifndef __VIEW_
    #define __VIEW_
    #include "abstract_data_type.h"
    #include "universal_function.h"
    int dayLeft(To_Do_List_Node *temp_main_node);
    void viewAll(To_Do_List_Node *main_node, int menu);
    void viewSpecific(To_Do_List_Node *main_node, int menu);
    void swapValueLinkedList(To_Do_List_Node **node1, To_Do_List_Node **node2);
    void copyLinkedList(To_Do_List_Node **copied_main_node, To_Do_List_Node *temp);
    void selectionSortList(To_Do_List_Node **main_node, int menu);
    void sortKelompok(To_Do_List_Node *main_node);
    void sortPriority(To_Do_List_Node *main_node);
    void sortDeadline(To_Do_List_Node *main_node);
#endif