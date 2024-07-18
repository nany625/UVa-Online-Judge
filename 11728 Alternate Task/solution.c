// #解法一
#include <stdio.h>
#include <math.h>
#define MAX_NUM 1000

int factorSum(int n) {
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
    int table[MAX_NUM] = {1};
    for(int i = 2; i <= MAX_NUM; ++i) {
        int temp = factorSum(i);
        if(temp <= MAX_NUM)
            table[temp - 1] = i;
    }
	int cases = 0, S;
	while(scanf("%d", &S) && S != 0)
	    printf("Case %d: %d\n", ++cases, table[S - 1] != 0 ? table[S - 1] : -1);
	return 0;
}

// #解法二
#include <stdio.h>
#include <math.h>

int factorSum(int n) {
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
	    if(S == 1) {
	        printf("Case %d: 1\n", ++cases);
	        continue;
	    }
	    int ans = S - 1, limit = ceil(sqrt(1 + 8 * S) - 1) / 2;
	    while(ans >= limit && factorSum(ans) != S)
	        --ans;
	    printf("Case %d: %d\n", ++cases, ans >= limit ? ans : -1);
	}
	return 0;
}
