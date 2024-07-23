#include <stdio.h>
#include <stdbool.h>
#define MAX_SUM 50000

typedef struct {
    short a, b, c;
} Answer;

int main() {
    Answer answers[MAX_SUM + 1];
    bool table[MAX_SUM + 1] = {};
    for(short a = 0; a <= 129; ++a) {
        for(short b = a; b <= 158; ++b) {
            for(short c = b; a * a + b * b + c * c <= MAX_SUM; ++c) {
                int sum = a * a + b * b + c * c;
                if(!table[sum]) {
                    table[sum] = true;
                    answers[sum].a = a;
                    answers[sum].b = b;
                    answers[sum].c = c;
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
