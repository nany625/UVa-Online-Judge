#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    while(N--) {
        int L;
        scanf("%d", &L);
        int a[L], swap = 0;
        for(int i = 0; i < L; ++i) {
            scanf("%d", &a[i]);
            for(int j = 0; j < i; ++j) {
                if(a[j] > a[i])
                    ++swap;
            }
        }
        printf("Optimal train swapping takes %d swaps.\n", swap);
    }
    return 0;
}
