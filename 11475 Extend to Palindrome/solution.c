#include <stdio.h>
#include <string.h>

int main() {
	char str[100001];
	while(scanf("%s", str) == 1) {
	    int len = strlen(str);
	    char revStr[len + 1];
	    for(int i = 0; i < len; ++i)
	        revStr[i] = str[len - 1 - i];
	    revStr[len] = '\0';
	    char concat[2 * len + 2];
	    sprintf(concat, "%s#%s", revStr, str);
	    int LPS[2 * len + 1], i = 1, length = 0;
	    LPS[0] = 0;
	    while(i < 2 * len + 1) {
	        if(concat[i] == concat[length])
	            LPS[i++] = ++length;
	        else {
	            if(length != 0)
	                length = LPS[length - 1];
	            else
	                LPS[i++] = 0;
	        }
	    }
	    fputs(str, stdout);
	    for(int j = len - LPS[2 * len] - 1; j >= 0; --j)
	        putchar(str[j]);
	    putchar('\n');
	}
	return 0;
}
