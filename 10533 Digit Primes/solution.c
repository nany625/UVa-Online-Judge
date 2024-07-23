#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define MAX_SIZE 1000000

bool isComposite[MAX_SIZE] = {true, true};
short dpCount[MAX_SIZE] = {};

int sumOfDigits(int n) {
    int result = 0;
    while(n > 0) {
        result += n % 10;
        n /= 10;
    }
    return result;
}

int main() {
    int limit = sqrt(MAX_SIZE);
    for(int i = 2; i < MAX_SIZE; ++i) {
        dpCount[i] = dpCount[i - 1];
        if(i < limit && !isComposite[i]) {
            for(int j = i * i; j < MAX_SIZE; j += i)
                isComposite[j] = true;
        }
        dpCount[i] += !isComposite[i] && !isComposite[sumOfDigits(i)];
    }
	int N;
	scanf("%d", &N);
	while(N--) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		printf("%d\n", dpCount[t2] - dpCount[t1 - 1]);
	}
	return 0;
}
