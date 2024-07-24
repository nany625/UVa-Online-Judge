#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
	int N;
	scanf("%d", &N);
	char s[81];
	bool firstCase = true;
	while(N--) {
		if(!firstCase)
			putchar('\n');
		scanf("%s", s);
		int len = strlen(s);
		bool found = false;
		for(int k = 1; k <= len / 2 && !found; ++k) {
			if(len % k == 0) {
				char *substring = strndup(s, k);
				int i = k;
				while(i < len && strncmp(substring, s + i, k) == 0)
					i += k;
				if(i >= len) {
					printf("%d\n", k);
					found = true;
				}
				free(substring);
			}
		}
		if(!found)
		    printf("%d\n", len);
		firstCase = false;
	}
	return 0;
}
