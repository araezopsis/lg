#include "lg.h"

int main(void){

    int map1[10][10];
    int map2[10][10];

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            map1[i][j] = rand() % 2;
        }
    }

    initscr();
    cbreak();

    erase();
    printw("cycle:1\n");
    print_map(10, 10, map1);
    refresh();
    usleep(100000);

    for(int i = 1; i < 1000; i++) {
        next_map(10, 10, map1, map2);

        erase();
        printw("cycle:%d\n", i + 1);
        print_map(10, 10, map2);
        refresh();
        usleep(100000);

        memcpy(map1, map2, sizeof(map2));
    }

    getch();
    endwin();

    return 0;
}

