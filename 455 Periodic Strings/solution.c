#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
	int N;
	scanf("%d", &N);
	char s[81];
	bool blankLine = false;
	while(N--) {
		scanf("%s", s);
		if(blankLine)
			puts("");
		int len = strlen(s);
		bool found = false;
		for(int k = 1; k <= len / 2 && !found; ++k) {
			if(len % k == 0) {
				char substring[k + 1];
				strncpy(substring, s, k);
				int i = k;
				while(i < len && strncmp(substring, s + i, k) == 0)
					i += k;
				if(i >= len) {
					printf("%d\n", k);
					found = true;
				}
			}
		}
		if(!found)
		    printf("%d\n", len);
		blankLine = true;
	}
	return 0;
}
