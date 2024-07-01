#include <stdio.h>
#include <stdlib.h>

int main() {
	int sets;
	scanf("%d", &sets);
	while(sets--) {
		int N;
		scanf("%d", &N);
		if(N == 0) {
			puts("0");
			continue;
		}
		int *digits = NULL, size = 0, curr = 9;
		while(curr > 1) {
			if(N % curr == 0) {
				digits = (int*)realloc(digits, (size + 1) * sizeof(int));
				digits[size++] = curr;
				N /= curr;
			} else
				--curr;
		}
		if(N == 1) {
			if(size == 0)
				puts("1");
			else {
				do {
				    printf("%d", digits[--size]);
				} while(size > 0);
				puts("");
			}
		} else
			puts("-1");
        free(digits);
	}
	return 0;
}
