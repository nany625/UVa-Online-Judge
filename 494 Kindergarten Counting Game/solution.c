#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
	char *buffer = NULL;
	size_t bufsize = 0;
	while(getline(&buffer, &bufsize, stdin) != -1) {
	    int count = 0, i = 0, len = strlen(buffer);
	    while(i < len) {
	        if(isalpha(buffer[i])) {
	            int j = i + 1;
	            while(j < len && isalpha(buffer[j]))
	                ++j;
	            ++count;
	            i = j;
	        }
	        ++i;
	    }
	    printf("%d\n", count);
	}
	free(buffer);
	return 0;
}
