#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_map(int row_n, int col_n, int map[row_n][col_n]);
int calc_next(int me, int others[]);
void next_map(int row_n, int col_n, int mapA[row_n][col_n], int mapB[row_n][col_n]);


int main(void){

    int map1[10][10];
    int map2[10][10];

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            map1[i][j] = rand() % 2;
        }
    }

    printf("cycle:1\n");
    print_map(10, 10, map1);
    printf("\n");

    for(int i = 1; i < 5; i++) {
        next_map(10, 10, map1, map2);

        printf("cycle:%d\n", i + 1);
        print_map(10, 10, map2);
        printf("\n");

        memcpy(map1, map2, sizeof(map2));
    }

    return 0;
}

void print_map(int row_n, int col_n, int map[row_n][col_n]) {
    for(int i = 0; i < row_n; i++) {
        for(int j = 0; j < col_n; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}

int calc_next(int me, int others[]){
    int sum = 0;
    for(int i = 0; i < 8; i++) {
        sum += others[i];
    }

    if(me == 0 && sum == 3) return 1;
    if(me == 1 && (sum == 2) || (sum == 3)) return 1;

    return 0;
}

void next_map(int row_n, int col_n, int mapA[row_n][col_n], int mapB[row_n][col_n]){
    for(int i = 0; i < row_n; i++) {
        for(int j = 0; j < col_n; j++) {
            int tit, tib, tjl, tjr;

            switch(i) {
                case 0: tit = row_n-1; break;
                default: tit = i - 1; break;
            }

            if(i == (row_n - 1)) {
                tib = 0;
            } else {
                tib = i + 1;
            }

            switch(j) {
                case 0: tjl = col_n-1; break;
                default: tjl = j - 1; break;
            }

            if(j == (col_n - 1)) {
                tjr = 0;
            } else {
                tjr = j + 1;
            }

            int temp_others[] = {
                mapA[tit][tjl],
                mapA[tit][j],
                mapA[tit][tjr],

                mapA[i][tjl],
                mapA[i][tjr],

                mapA[tib][tjl],
                mapA[tib][j],
                mapA[tib][tjr]
            };

            mapB[i][j] = calc_next(mapA[i][j], temp_others);
        }
    }
}
