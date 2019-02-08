#include "lg.h"

int calc_next(int me, int others[]){
    int sum = 0;
    for(int i = 0; i < 8; i++) {
        sum += others[i];
    }

    if(me == 0 && sum == 3) return 1;
    if(me == 1 && ((sum == 2) || (sum == 3))) return 1;

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
