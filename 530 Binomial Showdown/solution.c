#include <stdio.h>

int main() {
	int n, k;
	while(scanf("%d %d", &n, &k) && n != 0) {
	    if(k > n - k)
	        k = n - k;
	    double ans = 1;
	    for(int i = n, j = 1; j <= k; j++, i--) {
            ans *= i;
            ans /= j;
        }
	    printf("%.f\n", ans);
	}
	return 0;
}
