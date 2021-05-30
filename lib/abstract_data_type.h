#ifndef __DATA_TYPE_
    #define __DATA_TYPE_
    typedef struct To_Do_List_Node {
        struct To_Do_List_Node *next;
        char nama_tugas[50], kelompok_tugas[50];
        int prioritas;
        int dl_dd, dl_mm, dl_yyyy;
        
    } To_Do_List_Node;
    
    typedef struct date {
        int dd, mm, yyyy;
    } date;
#endif