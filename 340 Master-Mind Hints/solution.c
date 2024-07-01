#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
	int games = 0, N;
	while(scanf("%d", &N) && N != 0) {
		printf("Game %d:\n", ++games);
		char *secretCode = (char*)malloc(N * sizeof(char));
		for(int i = 0; i < N; ++i)
			scanf(" %c", &secretCode[i]);
		char *guess = (char*)malloc(N * sizeof(char));
		bool lastGuess;
		do {
		    lastGuess = true;
			for(int i = 0; i < N; ++i) {
				scanf(" %c", &guess[i]);
				if(guess[i] != '0')
					lastGuess = false;
			}
			if(!lastGuess) {
			    bool check[N];
				int a = 0, b = 0;
				for(int i = 0; i < N; ++i) {
					if(secretCode[i] == guess[i]) {
						++a;
						check[i] = true;
						guess[i] = '0';
					} else
					check[i] = false;
				}
				for(int i = 0; i < N; ++i) {
					for(int j = 0; j < N; ++j) {
						if(secretCode[i] == guess[j] && !check[i] && guess[j] != '0') {
							++b;
							check[i] = true;
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
