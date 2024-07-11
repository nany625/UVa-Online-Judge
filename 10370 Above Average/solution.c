#include <stdio.h>

int main() {
    int C;
    scanf("%d", &C);
    while(C--) {
        int N;
        scanf("%d", &N);
        int grade[N], sum = 0;
        for(int i = 0; i < N; ++i) {
            scanf("%d", &grade[i]);
            sum += grade[i];
        }
        int count = 0;
        for(int i = 0; i < N; ++i)
            count += grade[i] * N > sum;
        printf("%.3f%%\n", 100.0 * count / N);
    }
    return 0;
}
