#include <stdio.h>
#include <stdbool.h>
#define MAX_SUM 50000

typedef struct {
    short a, b, c;
} Answer;

int main() {
    Answer answers[MAX_SUM];
    bool table[MAX_SUM] = {};
    for(short a = 0; a <= 129; ++a) {
        for(short b = a; b <= 158; ++b) {
            for(short c = b; a * a + b * b + c * c <= MAX_SUM; ++c) {
                int sum = a * a + b * b + c * c;
                if(!table[sum - 1]) {
                    table[sum - 1] = true;
                    answers[sum - 1].a = a;
                    answers[sum - 1].b = b;
                    answers[sum - 1].c = c;
                }
            }
        }
    }
    int N;
    scanf("%d", &N);
    while(N--) {
        int K;
        scanf("%d",&K);
        if(table[K - 1])
            printf("%hd %hd %hd\n", answers[K - 1].a, answers[K - 1].b, answers[K - 1].c);
        else
            puts("-1");
    }
    return 0;
}
