#include <stdio.h>
#include <math.h>

int factorSum(int n) {
    if(n == 1)
        return 1;
    int result = 1 + n, limit = sqrt(n);
    for(int i = 2; i <= limit; ++i) {
        if(n % i == 0)
            result += i + n / i;
    }
    if(sqrt(n) == limit)
        result -= limit;
    return result;
}

int main() {
	int cases = 0, S;
	while(scanf("%d", &S) && S != 0) {
	    int ans = S, limit = ceil(sqrt(1 + 8 * S) - 1) / 2;
	    while(ans >= limit && factorSum(ans) != S)
	        --ans;
	    printf("Case %d: %d\n", ++cases, ans >= limit ? ans : -1);
	}
	return 0;
}
