#include "lg.h"

void print_map(int row_n, int col_n, int map[row_n][col_n]) {
    for(int i = 0; i < row_n; i++) {
        for(int j = 0; j < col_n; j++) {
            printw("%d ", map[i][j]);
        }
        printw("\n");
    }
}
