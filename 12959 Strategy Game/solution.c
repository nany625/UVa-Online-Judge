#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int J, R;
    char *buffer = NULL;
	size_t bufsize = 0;
	while(scanf("%d %d ", &J, &R) == 2) {
		int points[J];
		for(int i = 0; i < J; ++i)
			points[i] = 0;
		getline(&buffer, &bufsize, stdin);
		char *token = strtok(buffer, " ");
		int max = 0, winner;
		while(R--) {
			for(int j = 0; j < J; ++j) {
				points[j] += atoi(token);
				if(R == 0) {
					if(max <= points[j]) {
						max = points[j];
						winner = j + 1;
					}
				}
				token = strtok(NULL, " ");
			}
		}
		printf("%d\n", winner);
	}
	free(buffer);
	return 0;
}
