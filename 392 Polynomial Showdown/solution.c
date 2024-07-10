#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
    int coefficients[9];
	char *buffer = NULL;
	size_t bufsize = 0;
	while(getline(&buffer, &bufsize, stdin) != -1) {
		int i = 8;
		char* token = strtok(buffer, " ");
		while(token) {
			coefficients[i--] = atoi(token);
			token = strtok(NULL, " ");
		}
		bool leadingZero = true;
		for(i = 8; i >= 0; --i) {
			if(coefficients[i] != 0) {
				if(!leadingZero) {
					if(coefficients[i] < 0)
						printf(" - ");
					else
						printf(" + ");
				} else {
					if(coefficients[i] < 0)
						putchar('-');
				}
				if(i == 0)
					printf("%d", abs(coefficients[i]));
				else if(i == 1) {
					if(abs(coefficients[i]) > 1)
						printf("%d", abs(coefficients[i]));
					putchar('x');
				} else {
					if(abs(coefficients[i]) > 1)
						printf("%d", abs(coefficients[i]));
					printf("x^%d", i);
				}
				leadingZero = false;
			}
		}
		if(leadingZero)
			putchar('0');
		puts("");
	}
	return 0;
}
