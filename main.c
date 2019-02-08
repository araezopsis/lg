#include "lg.h"

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

