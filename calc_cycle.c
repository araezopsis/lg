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

void next_map(int row_n, int col_n, int mapA[], int mapB[]) {
    for(int i = 0; i < row_n; i++) {
        for(int j = 0; j < col_n; j++) {
            int it, ib, jl, jr;

            switch(i) {
                case 0: it = row_n - 1; break;
                default: it = i - 1; break;
            }

            if(i == (row_n - 1)) {
                ib = 0;
            } else {
                ib = i + 1;
            }

            switch(j) {
                case 0: jl = col_n - 1; break;
                default: jl = j - 1; break;
            }

            if(j == (col_n - 1)) {
                jr = 0;
            } else {
                jr = j + 1;
            }

            int temp_others[] = {
                mapA[it * col_n + jl],
                mapA[it * col_n + j],
                mapA[it * col_n + jr],

                mapA[i * col_n + jl],
                mapA[i * col_n + jr],

                mapA[ib * col_n + jl],
                mapA[ib * col_n + j],
                mapA[ib * col_n + jr]
            };

            mapB[i * col_n + j] = calc_next(mapA[i * col_n + j], temp_others);
        }
    }
}
