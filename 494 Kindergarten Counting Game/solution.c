#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	char buffer[106];
	while(fgets(buffer, sizeof(buffer), stdin)) {
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
	return 0;
}
