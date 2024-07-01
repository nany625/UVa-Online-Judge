#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
	char s[1000001];
	while(scanf("%s", s) && strcmp(s, ".") != 0) {
		int len = strlen(s);
		bool found = false;
		for(int i = 1; i <= len / 2 && !found; ++i) {
			if(len % i == 0) {
				char substring[i + 1];
				strncpy(substring, s, i);
				int j = i;
				while(j < len && strncmp(substring, s + j, i) == 0)
					j += i;
				if(j >= len) {
					printf("%d\n", len / i);
					found = true;
				}
			}
		}
		if(!found)
		    puts("1");
	}
	return 0;
}
