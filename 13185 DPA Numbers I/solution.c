// #解法一
#include <stdio.h>
#include <math.h>

int main() {
    char table[1001] = {};
    for(int i = 2; i <= 1000; ++i) {
        if(table[i] == 'a')
            continue;
        int sum = 1, limit = sqrt(i);
        for(int j = 2; j <= limit && sum <= i; ++j) {
            if(i % j == 0)
                sum += j + i / j;
        }
        if(limit == sqrt(i))
            sum -= limit;
        if(sum < i)
            table[i] = 'd';
        else if(sum == i)
            table[i] = 'p';
        else {
            for(int j = i; j <= 1000; j += i)
                table[j] = 'a';
        }
    }
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
