#ifndef __CREATE_
    #define __CREATE_
    #include "abstract_data_type.h"
    To_Do_List_Node *makeNode(To_Do_List_Node temp_input);
    void initToDoListFromFile(To_Do_List_Node **main_node);
    void insert(To_Do_List_Node ***main_node, To_Do_List_Node temp_input);
    void helpAddProcess(int menu);
    void saveToFile(To_Do_List_Node *temp_input);
    void addProcess(To_Do_List_Node **main_node);
#endif