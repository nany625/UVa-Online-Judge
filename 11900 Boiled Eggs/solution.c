#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int*)a > *(int*)b;
}

int main() {
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; ++i) {
        int n, P, Q;
        scanf("%d %d %d", &n, &P, &Q);
        int weights[n];
        for(int j = 0; j < n; ++j)
            scanf("%d", &weights[j]);
        qsort(weights, n, sizeof(int), compare);
        int total = 0, count = 0;
        n = n < P ? n : P;
        while(count < n) {
            if(total + weights[count] > Q)
                break;
            total += weights[count++];
        }
        printf("Case %d: %d\n", i, count);
    }
	return 0;
}
