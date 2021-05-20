#ifndef __DATA_TYPE_
    #define __DATA_TYPE_
    typedef struct to_do_list_node {
        struct to_do_list_node *next, *prev;
        char nama_tugas[50], kelompok_tugas[50];
        int prioritas;
        int dl_dd, dl_mm, dl_yyyy;
    } to_do_list_node;
 
    // Tambahkan ADT yang kalian perlukan
#endif