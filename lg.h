#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <ncurses.h>

void print_map(int row_n, int col_n, int map[row_n][col_n]);
int calc_next(int me, int others[]);
void next_map(int row_n, int col_n, int mapA[row_n][col_n], int mapB[row_n][col_n]);
