#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
	int games = 0, N;
	while(scanf("%d", &N) && N != 0) {
		printf("Game %d:\n", ++games);
		getchar();
		char *secretCode = (char*)malloc(((N << 1) + 2) * sizeof(char)), *guess = (char*)malloc(((N << 1) + 2) * sizeof(char));
		fgets(secretCode, (N << 1) + 2, stdin);
		bool lastGuess;
		do {
		    lastGuess = true;
		    fgets(guess, (N << 1) + 2, stdin);
			for(int i = 0; i < N << 1 && lastGuess; i += 2)
				lastGuess = guess[i] == '0';
			if(!lastGuess) {
			    bool check[N];
				int a = 0, b = 0;
				for(int i = 0; i < N << 1; i += 2) {
					if(secretCode[i] == guess[i]) {
						++a;
						check[i >> 1] = true;
						guess[i] = '0';
					} else
					    check[i >> 1] = false;
				}
				for(int i = 0; i < N << 1; i += 2) {
					for(int j = 0; j < N << 1; j += 2) {
						if(secretCode[i] == guess[j] && !check[i >> 1] && guess[j] != '0') {
							++b;
							check[i >> 1] = true;
							guess[j] = '0';
							break;
						}
					}
				}
				printf("    (%d,%d)\n", a, b);
			}
		} while(!lastGuess);
		free(secretCode);
		free(guess);
	}
	return 0;
}
