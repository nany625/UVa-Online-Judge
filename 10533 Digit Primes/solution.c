#include <stdio.h>
#include <stdbool.h>
#define MAX_NUM 999999

bool isComposite[MAX_NUM + 1] = {true, true};
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
    for(int n = 2; n <= MAX_NUM; ++n) {
        if(n <= 999 && !isComposite[n]) {
            for(int i = n * n; i <= MAX_NUM; i += n)
                isComposite[i] = true;
        }
        dpCount[n] = dpCount[n - 1] + (!isComposite[n] && !isComposite[sumOfDigits(n)]);
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
