#include <stdio.h>
#include <stdbool.h>
#define MAX_NUM 10000

typedef struct {
    short x, y;
} Solution;

int main() {
    Solution solutions[MAX_NUM];
    bool table[MAX_NUM] = {};
    for(short y = 1; y <= 57; ++y) {
        for(short x = y + 1; x * x * x - y * y * y <= MAX_NUM; ++x) {
            int N = x * x * x - y * y * y;
            if(!table[N - 1]) {
                table[N - 1] = true;
                solutions[N - 1].x = x;
                solutions[N - 1].y = y;
            }
        }
    }
    int N;
    while(scanf("%d", &N) && N != 0) {
        if(table[N - 1])
            printf("%hd %hd\n", solutions[N - 1].x, solutions[N - 1].y);
        else
            puts("No solution");
    }
    return 0;
}
