#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int main() {
    int N, R;
	while(scanf("%d %d", &N, &R) == 2) {
        if(N == R) {
            puts("*");
            while(R--)
                scanf("%d", &N);
            continue;
        }
        if(2 * R >= N) {
            int returned[R];
            for(int i = 0; i < R; ++i)
                scanf("%d", &returned[i]);
            qsort(returned, R, sizeof(int), compare);
            for(int i = 1; i < returned[0]; ++i)
                printf("%d ", i);
            for(int i = 0; i < R - 1; ++i) {
                for(int j = returned[i] + 1; j < returned[i + 1]; ++j)
                    printf("%d ", j);
            }
            for(int i = returned[R - 1] + 1; i <= N; ++i)
                printf("%d ", i);
        } else {
            bool returned[N];
            for(int i = 0; i < N; ++i)
                returned[i] = false;
            int num;
            while(R--) {
                scanf("%d", &num);
                returned[num - 1] = true;
            }
            for(int i = 0; i < N; ++i) {
                if(!returned[i])
                    printf("%d ", i + 1);
            }
	    }
	    putchar('\n');
    }
    return 0;
}
