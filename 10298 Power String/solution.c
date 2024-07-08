#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
	char *s = NULL;
	while(scanf("%ms", &s) && strcmp(s, ".") != 0) {
		int len = strlen(s);
		bool found = false;
		for(int i = 1; i <= len / 2 && !found; ++i) {
			if(len % i == 0) {
				char *substring = strndup(s, i);
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
		free(s);
		s = NULL;
	}
	return 0;
}
