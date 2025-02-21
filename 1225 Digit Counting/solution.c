#include <stdio.h>

void solve(int *array, int n) {
    do {
        ++array[n % 10];
        n /= 10;
    } while(n > 0);
}

int main() {
	int cases;
	scanf("%d", &cases);
	while(cases--){
		int N;
		scanf("%d", &N);
		int digitCounts[10] = {};
		do {
			solve(digitCounts, N);
		} while(--N);
		for(int i = 0; i < 9; ++i)
			printf("%d ", digitCounts[i]);
		printf("%d\n", digitCounts[9]);
	}
	return 0;
}
