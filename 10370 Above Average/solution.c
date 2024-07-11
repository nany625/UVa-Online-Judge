#include <stdio.h>

int main() {
    int C;
    scanf("%d", &C);
    while(C--) {
        int N;
        scanf("%d", &N);
        int grades[N], sum = 0;
        for(int i = 0; i < N; ++i) {
            scanf("%d", &grades[i]);
            sum += grades[i];
        }
        int count = 0;
        for(int i = 0; i < N; ++i)
            count += grades[i] * N > sum;
        printf("%.3f%%\n", 100.0 * count / N);
    }
    return 0;
}
