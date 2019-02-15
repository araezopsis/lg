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

    int RCN = RN * CN;
    int map[RN * CN * 3];

    /* SET SEED VALUE OF RANDOM NUMBER */
    srand((unsigned)time(NULL));

    for (int i = 0; i < (sizeof(map) / sizeof(map[0])); i++) {
        map[i] = rand() % 2;
    }

    initscr();
    cbreak();

    int i = 1;
    int loop = 1;
    do {
        erase();
        printw("cycle:%d\n", i);
        print_map(RN, CN, &map[0]);

        for (int j = 3-1; j > 0; j--) {
            memcpy(&map[RCN*j], &map[RCN*(j-1)], sizeof(int)*RCN);
        }

        next_map(RN, CN, &map[RCN], &map[0]);

        refresh();
        usleep(DELAY);

        if(i > 1) {
            if(memcmp(&map[0], &map[RCN*2], sizeof(int)*RCN) == 0) {
                loop = 0;
            }
        }

        i++;
    } while(loop);

    getch();
    endwin();

    return 0;
}
