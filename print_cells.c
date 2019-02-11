#include "lg.h"

void print_map(int row_n, int col_n, int map[row_n][col_n]) {
    for(int i = 0; i < row_n; i++) {
        for(int j = 0; j < col_n; j++) {
            if(map[i][j] == 0) {
                printw("%s ", "+");
            } else {
                printw("%s ", " ");
            }

        }
        printw("\n");
    }
}
