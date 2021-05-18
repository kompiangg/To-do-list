#include <stdio.h>

int main() {
    int menu;
    while(1) {
        puts("============");
        puts(" MENU UTAMA");
        puts("============");
        puts(" 1. Add");
        puts(" 2. Edit");
        puts(" 3. View");
        puts(" 0. Exit");
        puts("============");
    }
    printf("Input : ");
    scanf("%d", &menu);
    getchar();
    return 0;
}