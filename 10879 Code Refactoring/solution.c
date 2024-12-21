#include <stdio.h>

int main() {
    int N, temp[2];
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i) {
        int K;
        scanf("%d", &K);
        int count = 0;
        for(int j = 2; count < 2; ++j) {
            if(K % j == 0)
                temp[count++] = j;
        }
        printf("Case #%d: %d = %d * %d = %d * %d\n", i, K, temp[0], K / temp[0], temp[1], K / temp[1]);
    }
	return 0;
}
