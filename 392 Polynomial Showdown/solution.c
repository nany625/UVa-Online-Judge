#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
    int coefficients[9];
	char *buffer = NULL;
	size_t bufsize = 0;
	while(getline(&buffer, &bufsize, stdin) != -1) {
		int i = 0;
		char* token = strtok(buffer, " ");
		while(token) {
			coefficients[i++] = atoi(token);
			token = strtok(NULL, " ");
		}
		bool leadingZero = true;
		for(i = 0; i < 9; ++i) {
			if(coefficients[i] != 0) {
				if(!leadingZero) {
					if(coefficients[i] < 0)
						fputs(" - ", stdout);
					else
						fputs(" + ", stdout);
				} else {
					if(coefficients[i] < 0)
						putchar('-');
				}
				if(i == 8)
					printf("%d", abs(coefficients[i]));
				else if(i == 7) {
					if(abs(coefficients[i]) > 1)
						printf("%d", abs(coefficients[i]));
					putchar('x');
				} else {
					if(abs(coefficients[i]) > 1)
						printf("%d", abs(coefficients[i]));
					printf("x^%d", 8 - i);
				}
				leadingZero = false;
			}
		}
		if(leadingZero)
			putchar('0');
		putchar('\n');
	}
    free(buffer);
	return 0;
}
