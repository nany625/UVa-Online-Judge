#include <stdio.h>
#define MAXN 999999

short collatz[MAXN + 1] = {0, 1};

void init(int n) {
    collatz[n] = 1;
    long temp = n;
    while(temp != 1) {
        if(temp < n) {
            collatz[n] += collatz[temp] - 1;
            return;
        }
        temp = temp & 1 ? 3 * temp + 1 : temp >> 1;
        ++collatz[n];
    }
}

int main() {
	for(int n = 2; n <= MAXN; ++n)
        init(n);
    int min, max;
    while(scanf("%d %d", &min, &max) == 2) {
        printf("%d %d ", min, max);
        if(min > max) {
            int temp = min;
            min = max;
            max = temp;
        }
        short maxLen = collatz[min];
        for(int i = min + 1; i <= max; ++i)
            maxLen = maxLen > collatz[i] ? maxLen : collatz[i];
        printf("%hd\n", maxLen);
    }
	return 0;
}
