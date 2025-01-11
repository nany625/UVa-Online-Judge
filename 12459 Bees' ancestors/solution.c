#include <stdio.h>

long ans[81] = {0, 1, 2};

int main() {
    for(int n = 3; n < 81; ++n)
        ans[n] = ans[n - 2] + ans[n - 1];
    int generation;
    while(scanf("%d", &generation) && generation != 0)
        printf("%ld\n", ans[generation]);
	return 0;
}
