// #解法一
#include <stdio.h>
#include <math.h>

char table[1001];

void sumOfDivisors(int n) {
    if(table[n] == 'a')
        return;
    int sum = 1, i;
    float limit = sqrt(n);
    for(i = 2; i < limit && sum <= n; ++i) {
        if(n % i == 0)
            sum += i + n / i;
    }
    if(i == limit)
        sum += i;
    if(sum < n)
        table[n] = 'd';
    else if(sum == n)
        table[n] = 'p';
    else {
        for(i = n; i <= 1000; i += n)
            table[i] = 'a';
    }
}

int main() {
    for(int i = 2; i <= 1000; ++i)
        sumOfDivisors(i);
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		if(table[n] == 'd')
			puts("deficient");
		else if(table[n] == 'p')
			puts("perfect");
		else
			puts("abundant");
	}
	return 0;
}

// #解法二
#include <stdio.h>

int main() {
    int sum[1001] = {};
    for(int i = 1; i <= 1000; ++i) {
        for(int j = 2 * i; j <= 1000; j += i)
            sum[j] += i;
    }
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		if(sum[n] < n)
			puts("deficient");
		else if(sum[n] == n)
			puts("perfect");
		else
			puts("abundant");
	}
	return 0;
}
