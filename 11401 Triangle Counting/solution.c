#include <stdio.h>
#define MAX_NUM 1000000

long ans[MAX_NUM + 1];

int main() {
    for(int i = 4; i <= MAX_NUM; ++i) {
        long temp = (i >> 1) - 1;
        ans[i] = ans[i - 1] + (1 + temp) * temp - temp * ((i + 1) & 1);
    }
    int n;
    while(scanf("%d", &n) && n >= 3)
        printf("%ld\n", ans[n]);
	return 0;
}
