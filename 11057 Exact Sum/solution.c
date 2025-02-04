#include <stdio.h>
#include <string.h>
#define MAX_NUM 1000000

int count[MAX_NUM + 1];

int main() {
    int N;
    while(scanf("%d", &N) == 1) {
        memset(count, 0, sizeof(count));
        int price;
        for(int i = 0; i < N; ++i) {
            scanf("%d", &price);
            ++count[price];
        }
        int M;
        scanf("%d", &M);
        int temp = M >> 1;
        if(!(M & 1) && count[temp] >= 2)
            printf("Peter should buy books whose prices are %d and %d.\n\n", temp, temp);
        else {
            while(!(count[temp] && count[M - temp]))
                --temp;
            printf("Peter should buy books whose prices are %d and %d.\n\n", temp, M - temp);
        }
    }
	return 0;
}
