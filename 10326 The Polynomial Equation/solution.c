#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int N;
	char *buffer = NULL;
	size_t bufsize = 0;
	while(scanf("%d", &N) == 1) {
	    getchar();
	    getline(&buffer, &bufsize, stdin);
		int factors[N - 1][2];
		long C[N][N + 1];
		char *token = strtok(buffer, " ");
		C[0][0] = atol(token) * (-1);
		C[0][1] = 1;
		for(int i = 0; i < N - 1; ++i) {
		    token = strtok(NULL, " ");
			factors[i][0] = atoi(token) * (-1);
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
					fputs(" + ", stdout);
				else
					fputs(" - ", stdout);
				if(i > 1) {
					if(abs(C[N - 1][i]) > 1)
						printf("%ldx^%d", abs(C[N - 1][i]), i);
					else
						printf("x^%d", i);
				} else if(i == 1) {
					if(abs(C[N - 1][i]) > 1)
						printf("%ldx", abs(C[N - 1][i]));
					else
						putchar('x');
				} else
					printf("%ld", abs(C[N - 1][i]));
			}
		}
		if(C[N - 1][0] == 0)
			fputs(" + 0", stdout);
		puts(" = 0");
	}
    free(buffer);
	return 0;
}
