#include <stdio.h>

char primes[] = {
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 
    31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 
    73, 79, 83, 89, 97
};
short table[101][25];
int size[101];

void initTable(int n) {
    int temp = n;
    for(int i = 0; i < size[n - 1]; ++i)
        table[n][i] = table[n - 1][i];
    size[n] = size[n - 1];
    for(int i = 0; i < size[temp - 1] && n > 1; ++i) {
        while(n % primes[i] == 0) {
            ++table[temp][i];
            n /= primes[i];
        }
    }
    if(n > 1)
        table[temp][size[temp]++] = 1;
}

int main() {
    for(int n = 2; n <= 100; ++n)
        initTable(n);
    int N;
	while(scanf("%d", &N) && N != 0) {
	    printf("%3d! =", N);
		for(int i = 0; i < size[N]; ++i) {
    		if(i == 15)
    		    fputs("\n      ", stdout);
    		printf("%3hd", table[N][i]);
		}
		putchar('\n');
	}
    return 0;
}
