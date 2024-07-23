// #解法一
#include <stdio.h>
#include <math.h>

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

int main() {
    char table[1001] = {};
    for(int num = 2; num <= 1000; ++num) {
        if(num % 2 == 1) {
            table[num] = 'd';
            continue;
        }
        if(table[num] == 'a')
            continue;
        int sum = 1, limit = sqrt(num);
        for(int i = 0; primes[i] <= limit && sum <= num; ++i) {
            if(num % primes[i] == 0) {
                sum += primes[i] + num / primes[i];
                for(int j = 0; primes[j] <= primes[i] && sum <= num; ++j) {
                    for(int factor = primes[i] * primes[j]; num % factor == 0 && factor <= limit && sum <= num; factor *= primes[j])
                        sum += factor + num / factor;
                }
            }
        }
        if(limit == sqrt(num))
            sum -= limit;
        if(sum < num)
            table[num] = 'd';
        else if(sum == num)
            table[num] = 'p';
        else {
            for(int i = num; i <= 1000; i += num)
                table[i] = 'a';
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
    for(int num = 1; num <= 1000; ++num) {
        for(int j = 2 * num; j <= 1000; j += num)
            sum[j] += num;
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
