#include <stdio.h>
#define MAX_NUM 999999
#define GET(n) (mark[(n) >> 5] & (1u << ((n) & 31)))
#define SET(n) (mark[(n) >> 5] |= (1u << ((n) & 31)))

unsigned int mark[(MAX_NUM >> 5) + 1];
short dpCount[MAX_NUM + 1];

int sumOfDigits(int n) {
    int result = 0;
    while(n > 0) {
        result += n % 10;
        n /= 10;
    }
    return result;
}

void eratosthenesSieve() {
    SET(0);
    SET(1);
    for(int n = 2; n <= MAX_NUM; ++n) {
        if(n <= 999 && !GET(n)) {
            for(int i = n * n; i <= MAX_NUM; i += n)
                SET(i);
        }
        dpCount[n] = dpCount[n - 1] + (!GET(n) && !GET(sumOfDigits(n)));
    }
}

int main() {
    eratosthenesSieve();
	int N;
	scanf("%d", &N);
	while(N--) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		printf("%d\n", dpCount[t2] - dpCount[t1 - 1]);
	}
	return 0;
}
