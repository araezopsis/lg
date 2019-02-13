#include "lg.h"

void print_map(int row_n, int col_n, int map[row_n][col_n]) {
    char row_string[col_n + 1];
    row_string[col_n] = '\0';
    for(int i = 0; i < row_n; i++) {
        for(int j = 0; j < col_n; j++) {
            if(map[i][j] == 0) {
                row_string[j] = ' ';
            } else {
                row_string[j] = '+';
            }
        }
        printw("%s \n", row_string);
    }
}

