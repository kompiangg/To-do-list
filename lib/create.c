#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "create.h"
#include "universal_function.h"

To_Do_List_Node *makeNode(To_Do_List_Node temp_input) {
    To_Do_List_Node *head;
    
    head = (To_Do_List_Node *) malloc(sizeof(To_Do_List_Node));
    head->next = NULL;
    strcpy(head->nama_tugas, temp_input.nama_tugas);
    strcpy(head->kelompok_tugas, temp_input.kelompok_tugas);
    head->prioritas = temp_input.prioritas;
    head->dl_dd = temp_input.dl_dd;
    head->dl_mm = temp_input.dl_mm;
    head->dl_yyyy = temp_input.dl_yyyy;
    return head;
}

void initToDoListFromFile(To_Do_List_Node **main_node) {
    FILE *init_node_from_file = fopen("file\\to_do_list.txt", "r");
    if (init_node_from_file != NULL) {
        To_Do_List_Node temp_node;
        char temp[200];
        char *token;
        while(fgets(temp, 200, init_node_from_file) != NULL) {
            token = strtok(temp, "|");
            strcpy(temp_node.nama_tugas, token);
            token = strtok(NULL, "|");
            strcpy(temp_node.kelompok_tugas, token);
            token = strtok(NULL, "|");
            temp_node.prioritas = atoi(token);
            token = strtok(NULL, "|");
            token = strtok(token, "/");
            temp_node.dl_dd = atoi(token);
            token = strtok(NULL, "/");
            temp_node.dl_mm = atoi(token);
            token = strtok(NULL, "/");
            temp_node.dl_yyyy = atoi(token);
            *main_node == NULL ? *main_node = makeNode(temp_node) : insert(main_node, temp_node);
        }
    }
    fclose(init_node_from_file);
}

void insert(To_Do_List_Node **main_node, To_Do_List_Node temp_input) {
    To_Do_List_Node *tail_input_node, *temp_main_node = *main_node;
    tail_input_node = makeNode(temp_input);
    while(temp_main_node->next != NULL) temp_main_node = temp_main_node->next;
    temp_main_node->next = tail_input_node;
}

void helpAddProcess(int menu) {
    if (menu == 1) {
        puts("\n\n== Nama Tugas ==");
        puts("Field ini hendaknya diisikan");
        puts("nama tugas yang akan dikerjakan");
        puts("Contoh : Membuatkan pacar kejutan\n\n");
    }
    else if (menu == 2) {
        puts("\n\n== Kelompok Tugas ==");
        puts("Field ini dibuat ntuk memudahkan Anda dalam");
        puts("mengelompokkan tugas yang memiliki");
        puts("kesamaan menurut Anda dalam segi");
        puts("asal tugas, nama, dll");
        puts("Contoh : Alpro");
        puts("\n== CATATAN ==");
        puts("Pengelompokan ini tidak sensitive case");
        puts("Alpro dan alpro akan dianggap sama");
        puts("\n");
    }
    else if (menu == 3) {
        puts("\n\n== Prioritas ==");
        puts("Untuk membantu Anda dalam mengatur jadwal");
        puts("prioritas ini dapat menyimpan tingkat");
        puts("prioritas agar dapat ditampilkan nantinya");
        puts("== Tingkat-tingkat prioritas dari 1 - 4");
        puts("1. Penting & mendesak");
        puts("2. Tidak penting & mendesak");
        puts("3. Penting & tidak mendesak");
        puts("4. Tidak penting & tidak mendesak\n\n");
    }
    else if (menu == 4) {
        puts("\n\n== Deadline ==");
        puts("Deadline membantu anda untuk menyimpan");
        puts("batas akhir dari pengumpulan atau batas selesai");
        puts("tugas Anda");
        puts("Format yang dapat diterima program ini adalah");
        puts("dd/mm/yy");
        puts("Contoh : 22/05/2021\n\n");
    }
}

void saveToFile(To_Do_List_Node *temp_input) {
    FILE *write_to_file = fopen("file\\to_do_list.txt", "a");
    fprintf(write_to_file, "%s|%s|%d|%d/%d/%d\n", temp_input->nama_tugas, temp_input->kelompok_tugas,\
                                                  temp_input->prioritas, temp_input->dl_dd,\
                                                  temp_input->dl_mm, temp_input->dl_yyyy);
    fclose(write_to_file);
}

void addProcess(To_Do_List_Node **main_node) {
    To_Do_List_Node temp_input, *temp_travel;
    date date_now;
    char temp_text_prioritas[50], temp_text_date[50], *token;
    int back, back_to = 1;
    getTheDate(&date_now);

    printf("  ======= Guide =======  \n");
    printf("Selamat datang di add proses\n");
    printf("apabila Anda bingung tentang\n");
    printf("properti yang akan diisi,\n");
    printf("Anda dapat menginputkan -h\n");
    printf("untuk memanggil menu help\n\n");
    printf("Apabila anda ingin kembali\n");
    printf("ke menu sebelumnya, Anda\n");
    printf("dapat menginputkan -b untuk\n");
    printf("kembali ke menu sebelumnya\n\n");
    
    printf("====================\n");
    printf("| Input to-do list |\n");
    printf("====================\n");

    while (1) {
        temp_travel = *main_node;
        back = 0;

        if (back_to > 0) back_to--;

        while (1) {
            if (back == 0 && back_to == 0) {
                printf(" * Nama Tugas : ");
                scanf("%[^\n]", temp_input.nama_tugas);
                getchar();
                while (temp_travel != NULL) {
                    if (!strcmp(lowerTheSentence(temp_travel->nama_tugas), lowerTheSentence(temp_input.nama_tugas))) {
                        puts("\n========================================");
                        puts("=== MASUKKAN NAMA TUGAS YANG BERBEDA ===");
                        puts("===  NAMA TUGAS INI SUDAH DIGUNAKAN  ===");
                        puts("========================================\n");
                        back = 1;
                        break;
                    }
                    temp_travel = temp_travel->next;
                }
                if (back == 1) {
                    back = 0;
                    continue;
                }
            }
            if (strcmp(temp_input.nama_tugas, "-h") == 0) {
                helpAddProcess(1);
                continue;
            }
            else if (strcmp(temp_input.nama_tugas, "-b") == 0) {
                back = 1;
                break;
            }
            break;
        }

        if (back == 1) break;
        if (back_to > 0) back_to--;

        while (1) {
            if (back == 0 && back_to == 0) {
                printf(" * Kelompok Tugas : ");
                scanf("%[^\n]", temp_input.kelompok_tugas);
                getchar();
            }
            if (strcmp(temp_input.kelompok_tugas, "-h") == 0) {
                helpAddProcess(2);
                continue;
            }
            else if (strcmp(temp_input.nama_tugas, "-b") == 0) {
                back = 1;
                back_to = 1;
                break;
            }
            break;
        }

        if (back == 1) continue;
        if (back_to > 0) back_to--;
        
        while(1) {
            if (back == 0 && back_to == 0) {
                printf(" * Prioritas (1-4): ");
                scanf("%[^\n]", temp_text_prioritas);
                getchar();
                temp_input.prioritas = atoi(temp_text_prioritas);
                if (!(temp_input.prioritas >= 1 && temp_input.prioritas <= 4)) {
                    puts("\nMasukan angka antara 1 hingga 4\n");
                    continue;
                }
            }
            if (strcmp(temp_text_prioritas, "-h") == 0) {
                helpAddProcess(3);
                continue;
            }
            else if (strcmp(temp_text_prioritas, "-b") == 0) {
                back = 1;
                back_to = 2;
                break;
            }
            break;
        }

        if (back == 1) continue;
        if (back_to > 0) back_to--;
        
        while (1) {
            if (back == 0 && back_to == 0) {
                printf(" * Deadline (dd/mm/yyyy) : ");
                scanf("%[^%\n]", temp_text_date);
                getchar();

                token = strtok(temp_text_date, "/");
                temp_input.dl_dd = atoi(token);
                token = strtok(NULL, "/");
                temp_input.dl_mm = atoi(token);
                token = strtok(NULL, "/");
                temp_input.dl_yyyy = atoi(token);

                if (temp_input.dl_dd < date_now.dd || temp_input.dl_mm < date_now.mm || temp_input.dl_yyyy < date_now.yyyy) {
                        puts("\n=====================================");
                        puts("=== TIDAK BOLEH MEMASUKAN TANGGAL ===");
                        puts("=== SEBELUM TANGGAL HARI INI ===");
                        puts("=====================================\n");
                        continue;
                }
            }
            if (strcmp(temp_text_date, "-h") == 0) {
                helpAddProcess(4);
                continue;
            }
            else if (strcmp(temp_text_date, "-b") == 0) {
                back = 1;
                back_to = 3;
                break;
            }
            break;
        }

        if (back == 1) continue;
        break;
    }
    if (back == 0) {
        saveToFile(&temp_input);
        *main_node == NULL ? *main_node = makeNode(temp_input) : insert(main_node, temp_input);
    }
}