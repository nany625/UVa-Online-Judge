#include <stdio.h>

int main() {
	int brick[9][9], N;
	scanf("%d", &N);
	while(N--) {
	    for(int i = 0; i < 9; i += 2) {
	        for(int j = 0; j <= i; j += 2)
	            scanf("%d", &brick[i][j]);
	    }
	    for(int i = 2; i < 9; i += 2) {
	        for(int j = 1; j < i; j += 2)
	            brick[i][j] = brick[i - 2][j - 1] - brick[i][j - 1] - brick[i][j + 1] >> 1;
	    }
	    for(int i = 0; i < 9; ++i) {
	        for(int j = 0; j < i; ++j)
	            printf("%d ", i & 1 ? brick[i + 1][j] + brick[i + 1][j + 1] : brick[i][j]);
	        printf("%d\n", i & 1 ? brick[i + 1][i] + brick[i + 1][i + 1] : brick[i][i]);
	    }
	}
	return 0;
}
