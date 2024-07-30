#include <stdio.h>
#include <string.h>

int main() {
	char str[100001];
	while(scanf("%s", str) == 1) {
	    int len = strlen(str), LPS[len], i = 1, length = 0;
	    LPS[0] = 0;
	    while(i < len) {
	        if(str[i] == str[len - 1 - length])
	            LPS[i++] = ++length;
	        else {
	            if(length != 0)
	                length = LPS[length - 1];
	            else
	                LPS[i++] = 0;
	        }
	    }
	    fputs(str, stdout);
	    for(int j = len - LPS[len - 1] - 1; j >= 0; --j)
	        putchar(str[j]);
	    putchar('\n');
	}
	return 0;
}
