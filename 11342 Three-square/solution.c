#include <stdio.h>
#include <stdbool.h>
#define MAXK 50000

typedef struct {
    short a, b, c;
} Answer;

Answer answers[MAXK + 1];
bool table[MAXK + 1];

int main() {
    for(short a = 0; a <= 129; ++a) {
        for(short b = a; b <= 158; ++b) {
            int k;
            for(short c = b; (k = a * a + b * b + c * c) <= MAXK; ++c) {
                if(!table[k]) {
                    table[k] = true;
                    answers[k] = (Answer){a, b, c};
                }
            }
        }
    }
    int N;
    scanf("%d", &N);
    while(N--) {
        int K;
        scanf("%d", &K);
        if(table[K])
            printf("%hd %hd %hd\n", answers[K].a, answers[K].b, answers[K].c);
        else
            puts("-1");
    }
    return 0;
}
