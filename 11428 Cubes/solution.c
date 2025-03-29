#include <stdio.h>
#include <stdbool.h>
#define MAXN 10000

typedef struct {
    short x, y;
} Solution;

Solution solutions[MAXN + 1];
bool table[MAXN + 1];

int main() {
    for(short y = 1; y <= 57; ++y) {
        int N;
        for(short x = y + 1; (N = x * x * x - y * y * y) <= MAXN; ++x) {
            if(!table[N]) {
                table[N] = true;
                solutions[N] = (Solution){x, y};
            }
        }
    }
    int N;
    while(scanf("%d", &N) && N != 0) {
        if(table[N])
            printf("%hd %hd\n", solutions[N].x, solutions[N].y);
        else
            puts("No solution");
    }
    return 0;
}
