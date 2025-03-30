#include <stdio.h>

int main() {
    int N, M;
    while(scanf("%d %d", &N, &M) && N != 0) {
        int Jack[N], Jill[M];
        for(int i = 0; i < N; ++i)
            scanf("%d", &Jack[i]);
        for(int i = 0; i < M; ++i)
            scanf("%d", &Jill[i]);
        int i = 0, j = 0, count = 0;
        while(i < N && j < M) {
            if(Jack[i] == Jill[j]) {
                ++count;
                ++i;
                ++j;
            } else if(Jack[i] > Jill[j])
                ++j;
            else
                ++i;
        }
        printf("%d\n", count);
    }
	return 0;
}
