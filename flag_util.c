#include "lg.h"

/* argvを渡して引数情報を返す */
flag_info arg_parser(char* arg) {
    flag_info temp_flag;
    int flag_type;

    if(arg[0] == '-') {
        flag_type = FLAG_TYPE_1;
    } else {
        flag_type = NOT_FLAG;
    }

    if(flag_type == FLAG_TYPE_1) {
        char c = arg[1];
        switch(c) {
            case 'r':
                temp_flag.flag = FLAG_ROW;
                strcpy(temp_flag.string, &arg[2]);
                break;
            case 'c':
                temp_flag.flag = FLAG_COL;
                strcpy(temp_flag.string, &arg[2]);
                break;
            case 'd':
                temp_flag.flag = FLAG_DELAY;
                strcpy(temp_flag.string, &arg[2]);
                break;
            case 'h':
                temp_flag.flag = FLAG_HELP;
                break;
        }
    }
    return temp_flag;
}

void print_usage(void) {
    printf("\n\
Usage: lg [OPTION]\n\
  -r[INT]\t row number (default=%d)\n\
  -c[INT]\t column number (default=%d)\n\
  -d[INT]\t delay time (msec) (default=%d)\n\
  -h\t\t display this help massage and exit\n\n\
", RN, CN, DELAY / 1000);
}
