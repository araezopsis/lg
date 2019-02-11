#include "lg.h"

#define RN 50
#define CN 40
#define SPEED 10000

int main(void){

    int map1[RN][CN];
    int map2[RN][CN];

    srand((unsigned)time(NULL));

    for(int i = 0; i < RN; i++) {
        for(int j = 0; j < CN; j++) {
            map1[i][j] = rand() % 2;
        }
    }

    initscr();
    cbreak();

    erase();
    printw("cycle:1\n");
    print_map(RN, CN, map1);
    refresh();
    usleep(SPEED);

    for(int i = 1; i < 1000; i++) {
        next_map(RN, CN, map1, map2);

        erase();
        printw("cycle:%d\n", i + 1);
        print_map(RN, CN, map2);
        refresh();
        usleep(SPEED);

        memcpy(map1, map2, sizeof(map2));
    }

    getch();
    endwin();

    return 0;
}

