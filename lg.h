#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <ncurses.h>

/* 引数タイプ */
enum {
    NOT_FLAG = 0,
    FLAG_TYPE_1,

    FLAG_ROW,
    FLAG_COL,
    FLAG_DELAY,
    FLAG_HELP,
};

/* 引数情報の構造体 */
typedef struct {
    int flag;
    char string[100];
} flag_info;

/* PARAMETER  */
extern int RN;
extern int CN;
extern int DELAY;

void print_usage(void);
flag_info arg_parser(char* arg);

void print_map(int row_n, int col_n, int map[]);

int calc_next(int me, int others[]);
void next_map(int row_n, int col_n, int mapA[], int mapB[]);
