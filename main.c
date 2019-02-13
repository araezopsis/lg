#include "lg.h"

/*  DEFAULT PARAMETER  */
int RN = 50;            // 50 character
int CN = 80;            // 80 character
int DELAY = 50 * 1000;  // 50 msec

int main(int argc, char** argv) {

    /* PARSE ARGUMENTS */
    if(argc >= 2) {
        flag_info temp_arg;
        for(int i = 0; i < argc; i++) {
            temp_arg = arg_parser(argv[i]);
            switch(temp_arg.flag) {
                case FLAG_ROW:
                    RN = atoi(temp_arg.string);
                    break;
                case FLAG_COL:
                    CN = atoi(temp_arg.string);
                    break;
                case FLAG_DELAY:
                    DELAY = atoi(temp_arg.string) * 1000;
                    break;
                case FLAG_HELP:
                    print_usage();
                    return 0;
                    break;
            }
        }
    }

    int map1[RN][CN];
    int map2[RN][CN];

    /* SET SEED VALUE OF RANDOM NUMBER */
    srand((unsigned)time(NULL));

    for(int i = 0; i < RN; i++) {
        for(int j = 0; j < CN; j++) {
            map1[i][j] = rand() % 2;
        }
    }

    initscr();
    cbreak();

    printw("cycle:1\n");
    print_map(RN, CN, map1);
    refresh();
    usleep(DELAY);

    int i = 1;
    while(1) {
        next_map(RN, CN, map1, map2);
        erase();
        printw("cycle:%d\n", i + 1);
        print_map(RN, CN, map2);
        refresh();
        usleep(DELAY);
        memcpy(map1, map2, sizeof(map2));
        i++;
    }

    getch();
    endwin();

    return 0;
}

