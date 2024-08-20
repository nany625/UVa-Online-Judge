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

int main() {
    for(int i = 2; i <= MAX_NUM; ++i) {
        if(i <= 999 && !isComposite[i]) {
            for(int j = i * i; j <= MAX_NUM; j += i)
                isComposite[j] = true;
        }
        dpCount[i] = dpCount[i - 1] + (!isComposite[i] && !isComposite[sumOfDigits(i)]);
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
