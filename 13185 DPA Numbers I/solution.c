// #解法一
#include <stdio.h>
#include <math.h>

char table[998];

void sumOfDivisors(int n) {
    if(table[n] == 'a')
        return;
    int sum = 1, i, num = n + 2;
    float limit = sqrt(num);
    for(i = 2; i < limit && sum <= num; ++i) {
        if(num % i == 0)
            sum += i + num / i;
    }
    if(i == limit)
        sum += i;
    if(sum < num)
        table[n] = 'd';
    else if(sum == num)
        table[n] = 'p';
    else {
        for(i = num; i <= 999; i += num)
            table[i - 2] = 'a';
    }
}

int main() {
    for(int i = 0; i < 998; ++i)
        sumOfDivisors(i);
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		if(table[n - 2] == 'd')
			puts("deficient");
		else if(table[n - 2] == 'p')
			puts("perfect");
		else
			puts("abundant");
	}
	return 0;
}

// #解法二
#include <stdio.h>

int sum[1001] = {};

int main() {
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
