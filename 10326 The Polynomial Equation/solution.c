#include <stdio.h>
#include <stdlib.h>

int main() {
	int N;
	while(scanf("%d", &N) == 1) {
		int factors[N - 1][2];
		long long int C[N][N + 1];
		scanf("%lld", &C[0][0]);
		C[0][0] *= -1;
		C[0][1] = 1;
		for(int i = 0; i < N - 1; ++i) {
			scanf("%d", &factors[i][0]);
			factors[i][0] *= -1;
			factors[i][1] = 1;
			for(int j = 0; j < i + 3; ++j)
				C[i + 1][j] = 0;
			for(int j = 0; j < i + 2; ++j) {
				for(int k = 0; k < 2; ++k)
					C[i + 1][j + k] += C[i][j] * factors[i][k];
			}
		}
		if(N > 1)
			printf("x^%d", N);
		else
			putchar('x');
		for(int i = N - 1; i >= 0; --i) {
			if(C[N - 1][i] != 0) {
				if(C[N - 1][i] > 0)
					printf(" + ");
				else
					printf(" - ");
				if(i > 1) {
					if(abs(C[N - 1][i]) > 1)
						printf("%lldx^%d", abs(C[N - 1][i]), i);
					else
						printf("x^%d", i);
				} else if(i == 1) {
					if(abs(C[N - 1][i]) > 1)
						printf("%lldx", abs(C[N - 1][i]));
					else
						putchar('x');
				} else
					printf("%lld", abs(C[N - 1][i]));
			}
		}
		if(C[N - 1][0] == 0)
			printf(" + 0");
		puts(" = 0");
	}
	return 0;
}
